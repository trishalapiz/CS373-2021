Vector2 coordinates(CIEColour c) {
    double x = c.X / (c.X + c.Y + c.Z);
    double y = c.Y / (c.X + c.Y + c.Z);
    
    return Vector2(x,y);
    
}