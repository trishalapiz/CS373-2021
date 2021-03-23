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

/*                                                                         DRAW ANTI-CLOCKWISE
GIVEN THESE VERTICES
const static int numVertices = 5;
static Vector3 verticesTriangles[numVertices] = { 
	0 = Vector3(0.0, 0.0f, 0.0), top left vertex
	1 = Vector3(0.0, 0.0f, 5.0), bottom left vertex
	2 = Vector3(2.5, 0.0f, 2.5), middle vertex
	3 = Vector3(5.0, 0.0f, 5.0), bottom right vertex
	4 = Vector3(5.0, 0.0, 0.0)   top right vertex
};

This shape must be constructed from FOUR TRIANGLES, and drawn using GL_TRIANGLES. 
Each triangle must have its vertices specified in anticlockwise order, starting with the vertex at the CENTRE OF THE SHAPE.

The triangles must be drawn in anticlockwise order, starting from the ORANGE triangle.

The rgb values for the orange triangle are: 1.0, 0.5, 0.0

The rgb values for the blue triangles are: 0.0, 0.0, 1.0

Your code should use the minimum number of colour and vertex declarations.

Important note:

Coderunner requires certain OpenGL functions to use special versions in order to recognise the answer as correct:

Instead of glVertex3d(), use CRVertex3d()

Instead of glColor3d(), use CRColor3d()


--------------------------
HELPFUL TIPS!
Also, make sure you start with the middle point for each of the triangles.
For the blue triangles, you only need to declare its colour once, that fixed my problem.
Check that you're drawing each triangle anti-clockwise too. That's what is most likely causing your issue, one triangle having one line of code in the wrong spot.


  	first triangle = (2.5, 0.0f, 2.5), (0.0, 0.0f, 0.0), (0.0, 0.0f, 5.0) // index 2, 0, 1
    second triangle = (2.5, 0.0f, 2.5), (0.0, 0.0f, 5.0), (5.0, 0.0f, 5.0) // index 2, 1, 3
    third triangle = (2.5, 0.0f, 2.5), (5.0, 0.0f, 5.0), (5.0, 0.0f, 0.0) // index 2, 3, 4
    last triangle = (2.5, 0.0f, 2.5), (5.0, 0.0f, 0.0), (0.0, 0.0f, 0.0) // index 2, 4, 0
	

*/

void drawTriangleTile(Vector3 verticesTriangles[]) { // 'verticesTriangles' size has already been defined, the array itself is just being passed as an argument

    glBegin(GL_TRIANGLES);
	/*
    for (int i = 0; i < numVertices; i++) {
        // use 3x of glVertex2v()
        // use some if statement for orange/blue triangles 
            // if 0 (because starting triangle), use orange
            // else, use blue
        if (i == 0) {
            CRColor3d(1.0, 0.5, 0.0);
        } else {
            CRColor3d(0.0, 0.0, 1.0);
        }

		CRVertex3d(verticesTriangles[i].x, verticesTriangles[i].y, verticesTriangles[i].z);
        CRVertex3d(verticesTriangles[i+1].x, verticesTriangles[i+1].y, verticesTriangles[i+1].z);
		CRVertex3d(verticesTriangles[i+2].x, verticesTriangles[i+2].y, verticesTriangles[i+2].z);
		*/
	Vector3 startingVertex = verticesTriangles[2];
	int indices[4]={1,3,4,0}; // 0,1,2,3,4,5

	// orange triangle
	CRColor3d(1.0, 0.5, 0.0);
	CRVertex3d(verticesTriangles[2].x, verticesTriangles[2].y, verticesTriangles[2].z); // origin
    CRVertex3d(verticesTriangles[0].x, verticesTriangles[0].y, verticesTriangles[0].z);
	CRVertex3d(verticesTriangles[1].x, verticesTriangles[1].y, verticesTriangles[1].z);

	// blue triangle
	int arrSize = sizeof(indices)/sizeof(indices[0]); // 5
	CRColor3d(1.0, 0.5, 0.0);
	for (int i = 0; i < arrSize-1; i++) {
		CRVertex3d(verticesTriangles[2].x, verticesTriangles[2].y, verticesTriangles[2].z); // origin
		CRVertex3d(verticesTriangles[indices[i]].x, verticesTriangles[indices[i]].y, verticesTriangles[indices[i]].z);
		CRVertex3d(verticesTriangles[indices[i+1]].x, verticesTriangles[indices[i+1]].y, verticesTriangles[indices[i+1]].z);
	}
    glEnd();
    
}