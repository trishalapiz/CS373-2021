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

  	first triangle = (2.5, 0.0f, 2.5), (0.0, 0.0f, 0.0), (0.0, 0.0f, 5.0) // index 2, 0, 1
    second triangle = (2.5, 0.0f, 2.5), (0.0, 0.0f, 5.0), (5.0, 0.0f, 5.0) // index 2, 1, 3
    third triangle = (2.5, 0.0f, 2.5), (5.0, 0.0f, 5.0), (5.0, 0.0f, 0.0) // index 2, 3, 4
    last triangle = (2.5, 0.0f, 2.5), (5.0, 0.0f, 0.0), (0.0, 0.0f, 0.0) // index 2, 4, 0
	

*/

void drawTriangleTile(Vector3 verticesTriangles[]) { // 'verticesTriangles' size has already been defined, the array itself is just being passed as an argument

    glBegin(GL_TRIANGLES);
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
