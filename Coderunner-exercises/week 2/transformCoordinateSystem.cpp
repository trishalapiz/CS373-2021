#include <stdio.h>      /* printf */
#include <math.h> 
#include<iostream>
/*
Write a function transformCoordinateSystem(), which takes a point defined in some coordinate system, and transforms it to a new coordinate system.

The first coordinate system is described by the axis vectors u, v, and n, and has an origin located at uvnOrigin. 
The second coordinate system is described by the axis vectors a, b, and c, and has an origin located at abcOrigin. 
The axis vectors and origins of both coordinate systems are defined with respect to the global xyz coordinate system.

The point to be transformed is given by the parameter point, and describes the location of the point in the uvn coordinate system. 
Your function must return the location of point when described in the ABC coordinate system.

Your function should have the following signature:

--> Vector3 transformCoordinateSystem(Vector3 point, Vector3 u, Vector3 v, Vector3 n, Vector3 uvnOrigin, Vector3 a, Vector3 b, Vector3 c, Vector3 abcOrigin)

You can assume that each of the vectors u, v, n, a, b, and c, are unit vectors. ==> NORMALISED?

You can assume that Vector3 is a class that represents a 3D vector, and exposes fields named x, y, and z, and that the following functions are available to you:

--> double dot(Vector3 u, Vector3 v) // dot product

--> Vector3 cross(Vector3 u, Vector3 v) // cross product

In addition, you can assume the + and - operators are available for the Vector3 class.

You can assume that the Vector3 class has the following member functions available to you:

--> Vector3 Vector3::normalized() //returns a vector pointing in the same direction with length 1

--> double Vector3::magnitude() //returns the length of the vector

Hint: The x, y, and z components of the Vector class represent the location of the point in the corresponding axis of whichever coordinate system it is located within 
        (e.g. the point is initially located within the uvn coordinate system, so point.x represents how far away it is from the uvn origin along the u-axis).

Hint: You may find it useful to make yourself a diagram of some of the test cases.

----------------------
// OLD SYSTEM
Vector3 p = Vector3(0.0, 2.0, 0.0);
Vector3 u = Vector3(0.0, 1.0, 0.0);
Vector3 v = Vector3(-1.0, 0.0, 0.0);
Vector3 n = Vector3(0.0, 0.0, 1.0);
Vector3 uvnOrigin = Vector3(0.0, 2.0, 4.0);
// NEW SYSTEM
Vector3 a = Vector3(1.0, 0.0, 0.0);
Vector3 b = Vector3(0.0, 1.0, 0.0);
Vector3 c = Vector3(0.0, 0.0, 1.0);
Vector3 abcOrigin = Vector3(0.0, 0.0, 0.0);
Vector3 tp = transformCoordinateSystem(p, u, v, n, uvnOrigin, a, b, c, abcOrigin);
printf("(%.2lf, %.2lf, %.2lf)", tp.x, tp.y, tp.z); // (-2.00, 2.00, 4.00)
*/
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

    double magnitude(Vector3 v) {
        return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
    }

	Vector3 transformCoordinateSystem(Vector3 point, Vector3 u, Vector3 v, Vector3 n, Vector3 uvnOrigin, Vector3 a, Vector3 b, Vector3 c, Vector3 abcOrigin) {
		// M * p bit of F(P) = Mp + t //// REFERENCED GEOMETRY 3 SLIDE 14 FOR ROTATION
		double xCo = ((u.x * point.x) + (v.x * point.y) + (n.x * point.z));
		double yCo = ((u.y * point.x) + (v.y * point.y) + (n.y * point.z));
		double zCo = ((u.z * point.x) + (v.z * point.y) + (n.z * point.z));

		Vector3 mp = Vector3(xCo, yCo, zCo);

		// F(P) = Mp + t (where t is uvnOrigin)
		Vector3 P = mp + uvnOrigin; // point in global coordinates

		// project P to abc coordinates 
		Vector3 r = P - abcOrigin;
		// in the form of P' = (r•a, r•b, r•c)
		return Vector3(dot(r,a), dot(r,b), dot(r,c));
	}

};



/*
https://piazza.com/class/kkzypt8ny6h7ja?cid=45
None of those are needed, you just need to remember 3 equations (2, kinda) from Geometry 2.

F(P) = Mp + t
r = P-E
P`=(r•u, r•v, r•n)

M is the matrix of the current local vectors, p is the point in localspace and t is the local origin in worldspace.

You can see in this example how it works - remember how you multiply matrixes? Dot products, so multiplying row to column. The top row is the X, the middle the Y and the bottom is Z - each row can only have one value that isn't zero which is the axis value for the corresponding row. Dot products are just a combination of multiplication and addition so the zeroes are effectively ignored during the dot product operation, which is good when we don't know which axis each of uvn represents. Another way of putting it is multiplying the X of point by all possible values that could be X in uvn, the Y of point by all possible Y values in uvn, and the Z of point by all possible Z values in uvn.

This is then added to the local origin to get the location (relative to the worldspace's origin of 0,0,0) giving you a point in worldspace with the correct location and vectors. This result is P, which you can plug into the second equation where E is the origin of the new localspace. The third and final equation is where uvn are the new xyz axis' in the new localspace, with a nice (relatively) easy dot product to work out the local transform which is the final result you're aiming for.

Of course, you've got to code it all but if you're familiar with C++ it shouldn't be too hard :)

--------------------------------------------------------------------

uvnOrigin [P] - abcOrigin [E] = (0,2,4) - (0,0,0) = (0,2,4) /// the 'r' example in class in regards to P-E
P' = (r.u, r.v, r.n)
   = (2,-1,4) == WRONG, HAVEN'T DONE THE PROJECTION 

r.u = (0 * 0) + (2 * 1) + (4 * 0) = 2
r.v = (0 * -1) + (2 * 0) + (4 * 0) = 0
r.n = (0 * 0) + (2 * 0) + (4 * 1) = 4

r.u = (0 * 0) + (2 * 1) + (4 * 0) = 2
r.v = (0 * -1) + (2 * 0) + (4 * 0) = 0
r.n = (0 * 0) + (2 * 0) + (4 * 1) = 4

CORRECT WAY?
point [P] - abcOrigin [E] = (0,2,0) - (0,0,0) = (0,2,0)
r.a = (0 * 0) + (2 * 1) + (0 * 0) = 2
r.b = (0 * -1) + (2 * 0) + (0 * 0) = 0
r.c = (0 * 0) + (2 * 0) + (0 * 1) = 0

Vector3 a = Vector3(1.0, 0.0, 0.0);
Vector3 b = Vector3(0.0, 1.0, 0.0);
Vector3 c = Vector3(0.0, 0.0, 1.0);
r.a = (0 * 1) + (2 * 0) + (0 * 0) = 2
r.b = (0 * 0) + (2 * 1) + (0 * 0) = 0
r.c = (0 * 0) + (2 * 0) + (0 * 1) = 4

https://piazza.com/class/kkzypt8ny6h7ja?cid=25
What i mean is the following:

On slide 5 you compute the coordinates of a point in world coordinates with respect to a new UVN coordinate system.

In this question the first step is the reverse, i.e. you are given a point in an UVN coordinate system and you need to convert it to world coordinates. 
You need to think about how this can  be done - the solution is not in the slides, but can be achieved using the concepts you learned in the lecture 
(i.e. vector between points, projections onto coordinate axis). As mentioned above it helps to draw an example in 2D.

https://piazza.com/class/kkzypt8ny6h7ja?cid=24
In slide 5 we want to express the point P with respect to a new coordinate system (in this case a camera coordinate system - also called view coordinate system).

The  new coordinate system has the origin E (in this case the so-called "view point") and the coordinate axis (u,v,n).

(in your formula above you treated (x',y',z') as a point, but if x', y',z' are the axes of the new coordinate system, then they are vectors)

In order to express the point P in the new coordinate system we first compute the vector P-E. 
This is the vector from the origin of the new coordinate system to the origin of the old coordinate system.

If we now project this vector onto the coordinate axis of the new coordinate system (u,v,n) then we get the position of P (i.e. its coordinates) with respect to the new coordinate system.

If the vectors u,v,n are normalised then these coordinates are (r.u, r.v, r.n)

Note that this formula is only correct if the coordinate axes are unit vectors.

Hope that helps :-) Burkhard
*/