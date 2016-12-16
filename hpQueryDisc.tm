:Begin:
:Function:       hpAng2Pix
:Pattern:        hpAng2Pix[theta_Real,phi_Real,order_Integer]
:Arguments:      {theta,phi,order}
:ArgumentTypes:  {Real,Real,Integer}
:ReturnType:     Manual
:End:

:Begin:
:Function:       hpPix2Ang
:Pattern:        hpPix2Ang[pixel_Integer,order_Integer]
:Arguments:      {pixel,order}
:ArgumentTypes:  {Integer,Integer}
:ReturnType:     Manual
:End:

:Begin:
:Function:       hpPix2AngRing
:Pattern:        hpPix2AngRing[pixel_Integer,order_Integer]
:Arguments:      {pixel,order}
:ArgumentTypes:  {Integer,Integer}
:ReturnType:     Manual
:End:

:Begin:
:Function:       hpQueryDisc
:Pattern:        hpQueryDisc[theta_Real,phi_Real,radius_Real,order_Integer]
:Arguments:      {theta,phi,radius,order}
:ArgumentTypes:  {Real,Real,Real,Integer}
:ReturnType:     Manual
:End:

:Begin:
:Function:       hpQueryPolygon
:Pattern:        hpQueryPolygon[vertices_List,order_Integer]
:Arguments:      {vertices,order}
:ArgumentTypes:  {RealList,Integer}
:ReturnType:     Manual
:End:
