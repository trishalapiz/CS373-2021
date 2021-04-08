/*
Your function should have the following signature:

void drawMesh(Vector3 vertices[], int indices[], int numIndices)

The vertices and indices parameters together represent a 3D mesh drawn using triangles. numIndices gives the number of elements in the indices array.

The colour of each vertex should depend on the vertex's initial position (i.e. ignoring transformations). The colour intensity linearly scales with the absolute value of the vertex's distance from the origin in each axis. The red component of the colour is associated with distance in the x-axis, green is associated with the y axis, and blue is associated with the z-axis. Colour intensities scale from 0.0 at the origin, to 1.0 at 5 units or more away from the origin.

You can assume that the standard floating point maths functions (e.g. fabs(), fmin(), fmax()) are available to you.

Important note:

Coderunner requires certain OpenGL functions to use special versions:

Instead of glVertex3d(), use CRVertex3d()

Instead of glColor3d(), use CRColor3d()
*/

// FROM WEEK 3 LAB

// void drawMesh(Vector3 vertices[], Vector3 colors[], int indices[], int numIndices) {
//     glBegin(GL_TRIANGLES);
//     // indices[] indicates the sequence for drawing the mesh
//     for (int i = 0; i < numIndices; i++) {
//         CRColor3d(colors[indices[i]].x, colors[indices[i]].y, colors[indices[i]].z);
//         CRVertex3d(vertices[indices[i]].x, vertices[indices[i]].y, vertices[indices[i]].z);
//     }
//     glEnd();
    
// }

void drawMesh(Vector3 vertices[], int indices[], int numIndices) {
    glBegin(GL_TRIANGLES);

    for (int i = 0; i < numIndices; i++) {
        
        double r = 1.0;
        double g = 1.0;
        double b = 1.0;
    
        double x = vertices[indices[i]].x;
        double y = vertices[indices[i]].y;
        double z = vertices[indices[i]].z;
        
        if (x < 5) r = fabs(x / 5);
        if (y < 5) g = fabs(y / 5);
        if (z < 5) b = fabs(z / 5);
        
        CRColor3d(r,g,b);
        CRVertex3d(x, y, z);
    }
   
    glEnd();
}
