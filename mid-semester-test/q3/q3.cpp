/*

Your function should have the following signature:

void drawPyramid(Vector3 pyramidVertices[])

The parameter pyramidVertices[] contains the vertices used to draw the shape and is defined as:

const static int numVertices = 5;
static Vector3 pyramidVertices[numVertices] = {
	Vector3(2.5, 5.0, 2.5),
	Vector3(5.0, 0.0, 5.0),
	Vector3(0.0, 0.0, 5.0),
	Vector3(0.0, 0.0, 0.0),
	Vector3(5.0, 0.0, 0.0)
};
The viewpoint for this scene is positioned at (2.5, 1, 15), and is looking along the vector (0, -1, -2). You do not need to apply transformations to account for this, but you must use this to determine which of the above vertices are used by each face.

The pyramid has three total faces: there is no base, nor is there a face on the side not visible to the camera. 

This pyramid must be drawn using GL_TRIANGLES. Each triangle must have its vertices specified in anticlockwise order, starting with the vertex at the top of the pyramid.

The sides of the pyramid must be drawn starting with the blue face, then the red face on the right of the image above, and finally the red face on the left of the image above.

The rgb values for the blue face are: 0.0, 0.0, 1.0

The rgb values for the red faces are: 1.0, 0.0, 0.0

Your code should use the minimum number of colour and vertex declarations.

You can assume that Vector3 is a class that represents a 3D vector, and exposes fields named x, y, and z.

Important note:

Coderunner requires certain OpenGL functions to use special versions:

Instead of glVertex3d(), use CRVertex3d()

Instead of glColor3d(), use CRColor3d()

*/

void drawPyramid(Vector3 pyramidVertices[]) {
    glBegin(GL_TRIANGLES);
    
    // blue triangle
    CRColor3d(0.0, 0.0, 1.0);
    CRVertex3d(pyramidVertices[0].x, pyramidVertices[0].y, pyramidVertices[0].z);
    CRVertex3d(pyramidVertices[2].x, pyramidVertices[2].y, pyramidVertices[2].z);
    CRVertex3d(pyramidVertices[1].x, pyramidVertices[1].y, pyramidVertices[1].z);
    
    // red triangle
    CRColor3d(1.0, 0.0, 0.0);

    // right triangle
    CRVertex3d(pyramidVertices[0].x, pyramidVertices[0].y, pyramidVertices[0].z);
    CRVertex3d(pyramidVertices[4].x, pyramidVertices[4].y, pyramidVertices[4].z);
    CRVertex3d(pyramidVertices[1].x, pyramidVertices[1].y, pyramidVertices[1].z);

    // left triangle
    CRVertex3d(pyramidVertices[0].x, pyramidVertices[0].y, pyramidVertices[0].z);
    CRVertex3d(pyramidVertices[3].x, pyramidVertices[3].y, pyramidVertices[3].z);
    CRVertex3d(pyramidVertices[2].x, pyramidVertices[2].y, pyramidVertices[2].z);

    glEnd();
}