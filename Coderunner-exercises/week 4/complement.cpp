/* complement() takes a RGB colour as a parameter with each component in the range 0.0-1.0 and RETURNS an RGB colour representing its complement */

Colour complement(Colour c) {
    // 'Colour' is a class that represents an RGB vector (exposes fields r, g, b)
    // A new instance of the Colour class can be instantiated as Colour c = Colour(red, green, blue)
    return Colour(1-c.r, 1-c.g, 1-c.b);

}