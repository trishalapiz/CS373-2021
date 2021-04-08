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

bool pixelInMesh(Vector3 vertices[], int vertexCount, Vector3 point) {
    int count = 0;

    if (vertexCount % 3 == 0) { // to check if there are the right number of vertices to make a triangle
        count = vertexCount;
    } else {
        count = vertexCount - (vertexCount % 3);
    }
    
    bool check[count]; // for the number of edges to be checked

    for (int i = 0; i < count; i+=3) { 
        double firstEdgeFunction;
        double secondEdgeFunction;
        double thirdEdgeFunction;
	
	// check each edge of the triangle
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
