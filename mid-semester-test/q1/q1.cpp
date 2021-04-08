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
#include<stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

class Vector3	//The vector3 class is used in several Coderunner questions, in these questions it is already defined for you.
{
	public:
	double x;
	double y;
	double z;
	Vector3()	//default constructor
	{
		x = 0.0;
		y = 0.0;
		z = 0.0;
	}
	Vector3(double xVal, double yVal, double zVal)	//non-default constructor
	{
		x = xVal;
		y = yVal;
		z = zVal;
	}

    double dot(Vector3 u, Vector3 v) {
		return ( (u.x * v.x) + (u.y * v.y) + (u.z * v.z) ); 

	}

    Vector3 cross(Vector3 a, Vector3 b) {
        return Vector3((a.y * b.z) - (a.z * b.y), ((a.z * b.x) - (a.x * b.z)), ((a.x * b.y) - (a.y * b.x)));
    }

    // double magnitude(Vector3 v) {
    //     return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
    // }

    
    
};


    
    
Vector3 getOriginalVector(Vector3 uNormalized, Vector3 uv) {
    // angle between 2 vectors
    // Vector3 cp = cross(uNormalized, uv);

    // double uvMag = uv.magnitude();
    // double uNMag = uNormalized.magnitude(); // should return 1

    // double uMag = uvMag + uNMag;

    // double angleBetweenUVAndUN = dot(uNormalized, uv) / (uNMag * uvMag); // this is cos Θ
    // double uvUNAngle = acos(angleBetweenUVAndUN) * (180/M_PI); // returns 0.64 rads if not converted

    // // return Vector3(uMag * uNormalized.x, uMag * uNormalized.y, uMag * uNormalized.z);

    // // scale both vectors so that they form a right triangle
    // Vector3 scaledUN = Vector3(uvMag * uNormalized.x, uvMag * uNormalized.y, uvMag * uNormalized.z); // scale uNormalized so that it's the same length as Uv
    // Vector3 scaledUV = Vector3(angleBetweenUVAndUN * uv.x, angleBetweenUVAndUN * uv.y, angleBetweenUVAndUN * uv.z);

    // Vector3 scaledUNToScaledUV = 



    // double findAngle = (dot(scaledUN, uv) / (scaledUN.magnitude() * uvMag));
    
    // double angle = acos(findAngle); // returns the angle between uNormalised and Uv
    
    // return cp;
}

// int main() {
//     Vector3 un = Vector3(0.8, 0.6, 0.0);                 
//     Vector3 uv = Vector3(4.0, 0.0, 0.0);
//     Vector3 h = Vector3();
//     Vector3 u = h.getOriginalVector(un, uv);

//     cout << u;

//     return 0;
// }

// main();


// double uvMag = uv.magnitude();
//     double uNMag = uNormalized.magnitude(); // should return 1

//     Vector3 scaledUN = Vector3(uvMag * uNormalized.x, uvMag * uNormalized.y, uvMag * uNormalized.z); // scale uNormalized so that it's the same length as Uv
//     Vector3 resultantOne = scaledUN - uv;
//     double resOneMag = resultantOne.magnitude(); // 2.529822128


//     // double angleBetweenUVAndUN = dot(uNormalized, uv) / (uNMag * uvMag); // this is cos Θ
//     // double uvUNAngle = acos(angleBetweenUVAndUN) * (180/M_PI); // returns 0.64 rads if not converted

//     double cosTheta = dot(resultantOne, scaledUN) / (resOneMag * uvMag);
//     double x = acos(cosTheta) * (180/M_PI);




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