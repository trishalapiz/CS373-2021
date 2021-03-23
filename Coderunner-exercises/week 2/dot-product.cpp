/*
Write a function dot(), that takes as parameters two 3D vectors, and returns a double representing their dot product. 
Your function should have the following signature:

double dot(Vector3 u, Vector3 v)

You can assume that Vector3 is a class that represents a 3D vector, and exposes fields named x, y, and z.

Vector3 u = {3.0, -1.0, 2.0};
Vector3 v = {2.0, 1.0, 2.0};
double f = dot(u, v);
printf("u.v = %.2lf", f);
*/

double dot(Vector3 u, Vector3 v) {
    return ( (u.x * v.x) + (u.y * v.y) + (u.z * v.z) ); 
}

