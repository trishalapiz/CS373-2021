/*
Write a function coordinates(), that takes as a parameter a colour in the 3D CIE colour space with each component in the range [0...1], and 
returns its coordinates in the CIE 2D chromacity space.

It must have a signature of 
===> Vector2 coordinates(CIEColour c)

You can assume that CIEColour is a class that represents a colour in the 3D CIE space and exposes fields named X, Y, and Z.

You can assume that Vector2 is a class that represents a 2D vector, and exposes fields named x and y.
*/

/*
SpectralFunction resultantSDF(SpectralFunction light, SpectralFunction surface) {
    // light = SDF
    // surface = SRF
    (r, g, b) === (x, y, z)

    // TO DO VECTOR MULTIPLICATION, USE CROSS PRODUCT!!!!
    double x = (light.Y * surface.Z) - (light.Z - surface.Y);
    double y = (light.Z * surface.X) - (light.X - surface.Z);
    double z = (light.X * surface.Y) - (light.Y - surface.X);

    return SpectralFunction(x,y,z);   
}
*/

SpectralFunction resultantSDF(SpectralFunction light, SpectralFunction surface) {
    // light = SDF
    // surface = SRF
    //(r, g, b) 
    //(x, y, z)
    
    // turns out you just need to multiply each of the corresponding components of SDF and SRF
    return SpectralFunction(light.r * surface.r, light.g * surface.g, light.b * surface.b);
}
