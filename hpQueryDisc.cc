#include<iostream>
#include"pointing.h"
#include"vec3.h"
#include"healpix_base.h"
#include"wstp.h"

extern "C"{
void hpAng2Pix(double theta,double phi, int order){
	
    pointing pos(theta,phi);
    
    long pixel;
    
    Healpix_Ordering_Scheme scheme=NEST;
    
    T_Healpix_Base<long> base(order,scheme);
    
    pixel=base.ang2pix(pos);
    
    WSPutInteger64(stdlink, pixel);
    
    return;
}
}

extern "C"{
void hpPix2Ang(long pixel, int order){
	
    pointing pos;
    
    Healpix_Ordering_Scheme scheme=NEST;
    
    T_Healpix_Base<long> base(order,scheme);
    
    pos=base.pix2ang(pixel);
    
    std::vector<double> poslist={pos.theta,pos.phi};
    
    WSPutReal64List(stdlink, poslist.data(),(int) poslist.size());
    
    return;
}
}

extern "C"{
void hpPix2AngRing(long pixel, int order){
	
    pointing pos;
    
    Healpix_Ordering_Scheme scheme=RING;
    
    T_Healpix_Base<long> base(order,scheme);
    
    pos=base.pix2ang(pixel);
    
    std::vector<double> poslist={pos.theta,pos.phi};
    
    WSPutReal64List(stdlink, poslist.data(),(int) poslist.size());
    
    return;
}
}

extern "C"{
void hpQueryDisc(double theta,double phi,double radius, int order){
	
    pointing pos(theta,phi);
    
    Healpix_Ordering_Scheme scheme=RING;
    rangeset<long> poslist;
    
    T_Healpix_Base<long> base(order,scheme);
    
    base.query_disc(pos,radius,poslist);
    
    std::vector<long> pixlist;
    
    poslist.toVector(pixlist);
    
    WSPutInteger64List(stdlink, pixlist.data(), (int) pixlist.size());
    
    return;
}
}

extern "C"{
    void hpQueryPolygon(double * vertices, long verticeslen, int order){
        
        
        
        std::vector<pointing> vertex;
        vertex.reserve(verticeslen/2);
        
        for (int ii=0; ii<verticeslen; ii=ii+2) {
            pointing vertexPointing(vertices[ii],vertices[ii+1]);
            vertex.push_back(vertexPointing);
        }
        
        //Healpix_Ordering_Scheme scheme=RING;
        rangeset<long> poslist;
        
        T_Healpix_Base<long> base(order,RING);
        
        base.query_polygon(vertex, poslist);
        
        std::vector<long> pixlist;
        
        poslist.toVector(pixlist);
        
        WSPutInteger64List(stdlink, pixlist.data(), (int) pixlist.size());
        
        return;
    }
}

#if WINDOWS_WSTP

#if __BORLANDC__
#pragma argsused
#endif

int PASCAL WinMain(HINSTANCE hinstCurrent, HINSTANCE hinstPrevious, LPSTR lpszCmdLine, int nCmdShow)
{
	char  buff[512];
	char FAR * buff_start = buff;
	char FAR * argv[32];
	char FAR * FAR * argv_end = argv + 32;

	hinstPrevious = hinstPrevious; /* suppress warning */

	if (!WSInitializeIcon(hinstCurrent, nCmdShow)) return 1;
	WSScanString(argv, &argv_end, &lpszCmdLine, &buff_start);
	return WSMain((int)(argv_end - argv), argv);
}

#else

int main(int argc, char* argv[])
{
	return WSMain(argc, argv);
}

#endif
