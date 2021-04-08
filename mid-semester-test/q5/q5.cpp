/*
Write a function pixelInMesh(), which determines if a given pixel coordinate is covered by the triangles of a mesh during the rasterization step.

This function takes as parameters an array of Vector3s which represent the screen coordinates of the vertices of a shape drawn using a series of triangles, 
an integer vertexCount representing the NUMBER OF VERTICES in the mesh, and a Vector3 point representing the coordinates of the pixel to be tested. 
Your function should return true if the pixel is covered by the mesh, or false otherwise.

Your function should have the following signature:

bool pixelInMesh(Vector3 vertices[], int vertexCount, Vector3 point)

You can assume that the order of vertices in the array is the same as the order in which they are drawn, and that the vertices were drawn using GL_TRIANGLES.

You can assume vertexCount will always be equal to or greater than 3.

You can assume that the z-component of all Vector3s provided to the function will be 0 (the x-y coordinates given the screen location of the vertex).

You should treat any pixel that falls on the border of a triangle as being inside it. 
    ==> IF ON THE LINE then it's INSIDE THE MESH

You should assume that test cases may contain degenerate triangles and/or triangles that overlap.

You can assume that Vector3 is a class that represents a 3D vector, and exposes fields named x, y, and z, and that the following functions are available to you:

double dot(Vector3 u, Vector3 v) //dot product

Vector3 cross(Vector3 u, Vector3 v) //cross product

You can assume that the Vector3 class has the following member functions available to you:

Vector3 Vector3.normalized() //returns a vector pointing in the same direction with length 1

double Vector3.magnitude() //returns the length of the vector

You can assume that the Vector3 class supports the following operators:

Vector3 + Vector3

Vector3 - Vector3

Hint: You may find it useful to make yourself a diagram of some of the test cases.

Hint: Any excess vertices that do not make a triangle will be discarded.
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

};

// Vector3 vertices[] = {Vector3(20.0, 0.0, 0.0), Vector3(40.0, 30.0, 0.0), Vector3(20.0, 40.0, 0.0), Vector3(20.0, 40.0, 0.0),
//     Vector3(0.0, 30.0, 0.0), Vector3(20.0, 0.0, 0.0)};

// FROM CODERUNNER!
bool pixelInMesh(Vector3 vertices[], int vertexCount, Vector3 point) {
    int count = 0;

    if (vertexCount % 3 == 0) { // to check if there are the right number of vertices to make a triangle
        count = vertexCount;
    } else {
        count = vertexCount - (vertexCount % 3);
    }
    
    bool check[count];

    for (int i = 0; i < count; i++) { 
        double edgeFunction;

        if (i == count-1) { // if last number
            edgeFunction = ( (vertices[i].x - vertices[0].x) * (point.y - vertices[i].y) ) - ( (vertices[i].y - vertices[0].y) * (point.x - vertices[i].x) );
        } else {
            edgeFunction = ( (vertices[i].x - vertices[i+1].x) * (point.y - vertices[i].y) ) - ( (vertices[i].y - vertices[i+1].y) * (point.x - vertices[i].x) );
        }
        
        
        // GOING ANTI-CLOCKWISE
        // so inside = left
        // outside = right
        if (edgeFunction <= 0) {
            check[i] = true;
        } else { // right
            check[i] = false;
        }
    }
    
    // check if all values in the array are the same
    const int a0 = check[0];
    for (int i = 1; i < count; i++) {         
        if (check[i] != a0) {
            return false;
        }
    }
    
    return true;

}

// // if vertexCount is not a multiple of 3, make the loop count verte
//         double edgeFunction = ((point.x - vertices[i].x) * (vertices[i+1].y - vertices[i].y)) - ((point.y - vertices[i].y) * (vertices[i+1].x - vertices[i].x));
//         // if > 0 = right side
//         // if == 0 = on the line
//         // if < 0 = left side

bool pixelInMesh(Vector3 vertices[], int vertexCount, Vector3 point) {

    // pixel is a point, therefore Vector3 point = pixel to check
    // test to see which side of each vector the pixel is situated
    // if it is on the same side of every vector, it is INSIDE THE TRIANGLE
        // if there is VARIATION, then it is OUTSIDE of the triangle
    // 'vertexCount' = number of vertices in mesh
        // always >= 3


    // DO A LOOP
    // IN THAT LOOP USE THIS EQUATION: E(P) = ( (point.x - v0.x) * (v1.y - v0.y) ) - ( (point.y - v0.y) * (v1.x - v0.x) ) ==> ((x1 * y2) - (y1 * x2))

    int count = 0;

    if (vertexCount % 3 == 0) { // to check if there are the right number of vertices to make a triangle
        count = vertexCount;
    } else {
        count = vertexCount - (vertexCount % 3);
    }

    bool check[count];


    for (int i = 0; i < count; i+=3) {
        // double edgeFunction = ((point.x - vertices[i].x) * (vertices[i+1].y - vertices[i].y)) - ((point.y - vertices[i].y) * (vertices[i+1].x - vertices[i].x));

        double firstEdgeFunction;
        double secondEdgeFunction;
        double thirdEdgeFunction;

        // if (i == count-1) { // if last number
        //     edgeFunction = ( (vertices[i].x - vertices[0].x) * (point.y - vertices[i].y) ) - ( (vertices[i].y - vertices[0].y) * (point.x - vertices[i].x) );
        // } else {
        //     edgeFunction = ( (vertices[i].x - vertices[i+1].x) * (point.y - vertices[i].y) ) - ( (vertices[i].y - vertices[i+1].y) * (point.x - vertices[i].x) );
        // }
        
        firstEdgeFunction = ( (vertices[i].x - vertices[i+1].x) * (point.y - vertices[i].y) ) - ( (vertices[i].y - vertices[i+1].y) * (point.x - vertices[i].x) );
        secondEdgeFunction = ( (vertices[i+1].x - vertices[i+2].x) * (point.y - vertices[i+1].y) ) - ( (vertices[i+1].y - vertices[i+2].y) * (point.x - vertices[i+1].x) );
        thirdEdgeFunction = ( (vertices[i+2].x - vertices[i].x) * (point.y - vertices[i+2].y) ) - ( (vertices[i+2].y - vertices[i].y) * (point.x - vertices[i+2].x) );

        cout << i << "\n";
        cout << edgeFunction << "\n";

        // GOING ANTI-CLOCKWISE
        // so inside = left
        // outside = right
        if (firstEdgeFunction <= 0 && secondEdgeFunction <= 0 && thirdEdgeFunction <= 0) { // if inside
            check[i] = true;
            check[i+1] = true;
            check[i+2] = true;
        } else { // outside
            check[i] = false;
            check[i+1] = false;
            check[i+2] = false;
        }
    }

    for (int j = 0; j < count; j+=3) {
        if (check[i] == check[i+1] && check[i+1] == check[i+2] && check[i] == 1) {
            return true;
        } else {
            return false;
        }
    }


    // for (int k = 0; k < count; k++) {
    //     cout << check[k] << "\n";
    // }

    // // check if all values in the array are the same
    // const int a0 = check[0];
    // for (int i = 1; i < count; i++) {         
    //     if (check[i] != a0)
    //         return true;
    // }
    
    // return false;
 
} 

// firstEdgeFunction = ( (vertices[i].x - vertices[i+1].x) * (point.y - vertices[i].y) ) - ( (vertices[i].y - vertices[i+1].y) * (point.x - vertices[i].x) );
// secondEdgeFunction = ( (vertices[i+1].x - vertices[i+2].x) * (point.y - vertices[i+1].y) ) - ( (vertices[i+1].y - vertices[i+2].y) * (point.x - vertices[i+1].x) );
// thirdEdgeFunction = ( (vertices[i+2].x - vertices[i].x) * (point.y - vertices[i+2].y) ) - ( (vertices[i]+2.y - vertices[i].y) * (point.x - vertices[i+2].x) );

bool edgeFunction(const Vec2f &a, const Vec3f &b, const Vec2f &c) 
{ 
    // However, if we were to declare the vertices in counter-clockwise order, points to the right of an edged defined by vertices A and B would still be positive, 
    // but then they would be outside the triangle. In other words points overlapping the triangle would not be positive but negative.(figure 10). 
    // You can potentially still get the code working with positive numbers with a small change to the edge function:
    // (A.x−B.x)∗(P.y−A.y)−(A.y−B.y)∗(P.x−A.x) ==> anticlockwise

    return ((c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x) >= 0); // clockwise
} 
 
bool inside = true; 
inside &= edgeFunction(V0, V1, p); 
inside &= edgeFunction(V1, V2, p); 
inside &= edgeFunction(V2, V0, p); 
 
if (inside == true) { 
    // point p is inside triangles defined by vertices v0, v1, v2
    ... 
} 

/* TEST CASE */

// Vector3 vertices[] = {
//     Vector3(20.0, 0.0, 0.0),
//     Vector3(40.0, 30.0, 0.0),
//     Vector3(20.0, 40.0, 0.0),
//     Vector3(20.0, 40.0, 0.0),
//     Vector3(0.0, 30.0, 0.0),
//     Vector3(20.0, 0.0, 0.0)
// };
// bool res = pixelInMesh(vertices, 6, Vector3(40.0, 40.0, 0.0));
// printf(res ? "true" : "false");

bool check(const int array[], int n) // checking if elements in an array are ALL the same

{   
    const int a0 = array[0];

    for (int i = 1; i < n; i++)      
    {         
        if (array[i] != a0)
            return true;
    }
    return false;
}
// FINAL CODE!
bool pixelInMesh(Vector3 vertices[], int vertexCount, Vector3 point) {
    int count = 0; // determine the loop count, which is dependent on the number of vertices

    if (vertexCount % 3 == 0) { // to check if there are the right number of vertices to make a triangle
        count = vertexCount;
    } else {
        count = vertexCount - (vertexCount % 3); // can only make as much triangles as able
    }
    
    bool check[count]; // check if the point is to the left of each vector

    for (int i = 0; i < count; i+=3) { // increment is 3 because i'm iterating through each triangle in the mesh
        double firstEdgeFunction;
        double secondEdgeFunction;
        double thirdEdgeFunction;

        // calculate edge function for each side of each triangle
        firstEdgeFunction = ( (vertices[i].x - vertices[i+1].x) * (point.y - vertices[i].y) ) - ( (vertices[i].y - vertices[i+1].y) * (point.x - vertices[i].x) );
        secondEdgeFunction = ( (vertices[i+1].x - vertices[i+2].x) * (point.y - vertices[i+1].y) ) - ( (vertices[i+1].y - vertices[i+2].y) * (point.x - vertices[i+1].x) );
        thirdEdgeFunction = ( (vertices[i+2].x - vertices[i].x) * (point.y - vertices[i+2].y) ) - ( (vertices[i+2].y - vertices[i].y) * (point.x - vertices[i+2].x) );

        // GOING ANTI-CLOCKWISE
        // so inside = left
        // outside = right
        if (firstEdgeFunction <= 0 && secondEdgeFunction <= 0 && thirdEdgeFunction <= 0) { // if inside
            check[i] = true;
            check[i+1] = true;
            check[i+2] = true;
        } else { // outside
            check[i] = false;
            check[i+1] = false;
            check[i+2] = false;
        }
    }

    // check if the point is in each triangle
    for (int j = 0; j < count; j+=3) {
        if (check[j] == check[j+1] && check[j+1] == check[j+2] && check[j] == 1) {
            return true; // if point is in triangle
        }
    }
    return false; // point not in triangle
}




// ======
// Vector3 vertices[] = {Vector3(20.0, 0.0, 0.0), Vector3(40.0, 30.0, 0.0), Vector3(20.0, 40.0, 0.0), Vector3(20.0, 40.0, 0.0),
//     Vector3(0.0, 30.0, 0.0), Vector3(20.0, 0.0, 0.0)};

bool pixelInMesh(Vector3 vertices[], int vertexCount, Vector3 point) {
    int count = 0;

    if (vertexCount % 3 == 0) { // to check if there are the right number of vertices to make a triangle
        count = vertexCount;
    } else {
        count = vertexCount - (vertexCount % 3);
    }
    
    bool check[count];

    for (int i = 0; i < count; i+=3) { 
        double firstEdgeFunction;
        double secondEdgeFunction;
        double thirdEdgeFunction;

        firstEdgeFunction = ( (vertices[i].x - vertices[i+1].x) * (point.y - vertices[i].y) ) - ( (vertices[i].y - vertices[i+1].y) * (point.x - vertices[i].x) );
        secondEdgeFunction = ( (vertices[i+1].x - vertices[i+2].x) * (point.y - vertices[i+1].y) ) - ( (vertices[i+1].y - vertices[i+2].y) * (point.x - vertices[i+1].x) );
        thirdEdgeFunction = ( (vertices[i+2].x - vertices[i].x) * (point.y - vertices[i+2].y) ) - ( (vertices[i+2].y - vertices[i].y) * (point.x - vertices[i+2].x) );

        // GOING ANTI-CLOCKWISE
        // so inside = left
        // outside = right
        if (firstEdgeFunction <= 0 && secondEdgeFunction <= 0 && thirdEdgeFunction <= 0) { // if inside
            check[i] = true;
            check[i+1] = true;
            check[i+2] = true;
        } else { // outside
            check[i] = false;
            check[i+1] = false;
            check[i+2] = false;
        }
    }
    
    for (int j = 0; j < count; j+=3) {
        if (check[j] == check[j+1] && check[j+1] == check[j+2] && check[j] == 1) {
            return true;
        }
    }
    
    return false;

}