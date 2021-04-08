/*

Consider a set of vectors, u, v, and uv, where uv represents the orthogonal projection of u on to v.

Write a function getOriginalVector() that takes as parameters the normalized form of u and the projection uv, and returns the original vector u.

Your function should have the following signature:

Vector3 getOriginalVector(Vector3 uNormalized, Vector3 uv)

You can assume that Vector3 is a class that represents a 3D vector, and exposes fields named x, y, and z.

You can assume that no inputs to the function will be vectors with a magnitude of 0, and that u and v will not point in the same direction.

You can assume the following functions related to vectors are available to you.

double Vector3.magnitude() usage example: double mag = myVector.magnitude();

double dot(Vector3 a, Vector3 b)

Vector3 cross(Vector3 a, Vector3 b)

You can assume that the following C++ mathematical functions are available to you, and that the trigonometric functions represent angles using radians by default.

double sin(double angle)

double cos(double angle)

double tan(double angle)

double asin(double angle)

double acos(double angle)

double atan(double angle)

double sqrt(double angle)

For example:

Test	                                             Result
Vector3 un = Vector3(0.8, 0.6, 0.0);                 u = {4.00, 3.00, 0.00}
Vector3 uv = Vector3(4.0, 0.0, 0.0);
Vector3 u = getOriginalVector(un, uv);
printf("u = {%.2lf, %.2lf, %.2lf}", u.x, u.y, u.z);


*/
// FINAL CODE

Vector3 getOriginalVector(Vector3 uNormalized, Vector3 uv) {
    // double uvMag = uv.magnitude();
    // Vector3 scaledUN = Vector3(uvMag * uNormalized.x, uvMag * uNormalized.y, uvMag * uNormalized.z); // scale uNormalized so that it's the same length as Uv

    // Vector3 newVec = scaledUN + uNormalized;
    // double newMag = newVec.magnitude();


    // return Vector3(newMag * uNormalized.x, newMag * uNormalized.y, newMag * uNormalized.z);

    double uvMag = uv.magnitude(); 

    Vector3 uvNorm = Vector3(uv.x / uvMag, uv.y / uvMag, uv.z / uvMag);

    double dp = dot(uvNorm, uNormalized);

    double scalar = uvMag / dp;

    return Vector3(scalar * uNormalized.x, scalar * uNormalized.y, scalar * uNormalized.z);
}
