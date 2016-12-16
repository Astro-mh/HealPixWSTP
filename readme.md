# Mathematica HEALPix WSTP link

This is the initial version of a system to allow calls from Mathematica to the NASA JPL [HEALPix](http://healpix.jpl.nasa.gov) library.

At this stage it doesn't contain much, only allowing calls to ang2pix, pix2ang, query_disc and query_polygon. It lacks error checking, a build system and the difference between `NEST` and `RING` schemes of pixel layout is somewhat hidden.