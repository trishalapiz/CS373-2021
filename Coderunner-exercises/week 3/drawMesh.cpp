/*
Your function should have the following signature:

void drawMesh(Vector3 vertices[], Vector3 colors[], int indices[], int numIndices)

The vertices and indices parameters together represent a 3D mesh drawn using triangles. 

=====> numIndices gives the NUMBER OF ELEMENTS in the INDICES array.

The colors array CORRESPONDS to the vertices array: the vertex stored in vertices[0] should have the colour stored in colors[0].

Note that the colors array is passed as an array of Vector3 instances. The x, y, and z components of the Vector3 represent the red, green, and blue components of the colour.

x = red
y = green
z = blue

Important note:

Coderunner requires certain OpenGL functions to use special versions:

Instead of glVertex3d(), use CRVertex3d()
Instead of glColor3d(), use CRColor3d()
*/

void drawMesh(Vector3 vertices[], Vector3 colors[], int indices[], int numIndices) {
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < numIndices; i++) {
        CRColor3d(colors[indices[i]].x, colors[indices[i]].y, colors[indices[i]].z);
        CRVertex3d(vertices[indices[i]].x, vertices[indices[i]].y, vertices[indices[i]].z);
    }
    glEnd();
    
}