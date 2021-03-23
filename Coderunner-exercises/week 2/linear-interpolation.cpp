/*
Write a function lerp(), that takes as parameters two 3D vectors (a & b), and a double t in the range [0..1] representing a fraction of the distance between them. 
This function should return a 3D vector representing the linear interpolation from a to b by a factor of t.

The function should have the following signature:

Vector3 lerp(Vector3 u, Vector3 v, double t)

You can assume that Vector3 is a class that represents a 3D vector, and exposes fields named x, y, and z. 

Hint: You can initialise an instance of the Vector3 class as follows: 

Vector3 example = Vector3(x, y, z);


Vector3 a = Vector3(3.0, -1.0, 2.0);
Vector3 b = Vector3(2.0, 1.0, 2.0);
Vector3 result = lerp(a, b, 0.5);
printf("(%.2lf, %.2lf, %.2lf)", result.x, result.y, result.z); // (2.50, 0.00, 2.00)

Vector3 a = Vector3(3.0, -1.0, 2.0);
Vector3 b = Vector3(2.0, 1.0, 2.0);
Vector3 result = lerp(a, b, 0.0);
printf("(%.2lf, %.2lf, %.2lf)", result.x, result.y, result.z); // (3.00, -1.00, 2.00)

*/
// DO IT BASED OFF 'A'
Vector3 lerp(Vector3 u, Vector3 v, double t) {
    double newX = t * (u.x - v.x);
    double newY = t * (u.y - v.y);
    double newZ = t * (u.z - v.z);

    return Vector3(u.x-newX, u.y-newY, u.z-newZ);
}

/*
LINEAR INTERPOLATION BETWEEN VECTORS:
- get the difference between vectors
- then scale it using the given factor
- the add the starting vector with the scaled up vector to get the linear interpolation
*/