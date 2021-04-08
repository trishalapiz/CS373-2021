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

    fabs()
    
    CRColor3d(vertices[indices[0]].x, vertices[indices[0]].y, vertices[indices[0]].z);
    CRVertex3d(vertices[indices[0]].x, vertices[indices[0]].y, vertices[indices[0]].z);
    
    CRColor3d(vertices[indices[1]].x, vertices[indices[1]].y, vertices[indices[1]].z);
    CRVertex3d(vertices[indices[1]].x, vertices[indices[1]].y, vertices[indices[1]].z);
    
    CRColor3d(vertices[indices[2]].x, vertices[indices[2]].y, vertices[indices[2]].z);
    CRVertex3d(vertices[indices[2]].x, vertices[indices[2]].y, vertices[indices[2]].z);
    
    CRColor3d(vertices[indices[3]].x, vertices[indices[3]].y, vertices[indices[3]].z);
    CRVertex3d(vertices[indices[3]].x, vertices[indices[3]].y, vertices[indices[3]].z);
    
    CRColor3d(vertices[indices[4]].x, vertices[indices[4]].y, vertices[indices[4]].z);
    CRVertex3d(vertices[indices[4]].x, vertices[indices[4]].y, vertices[indices[4]].z);
    
    CRColor3d(vertices[indices[5]].x, vertices[indices[5]].y, vertices[indices[5]].z);
    CRVertex3d(vertices[indices[5]].x, vertices[indices[5]].y, vertices[indices[5]].z);
    
    CRColor3d(vertices[indices[6]].x, vertices[indices[6]].y, vertices[indices[6]].z);
    CRVertex3d(vertices[indices[6]].x, vertices[indices[6]].y, vertices[indices[6]].z);
    
    CRColor3d(vertices[indices[7]].x, vertices[indices[7]].y, vertices[indices[7]].z);
    CRVertex3d(vertices[indices[7]].x, vertices[indices[7]].y, vertices[indices[7]].z);
    
    CRColor3d(vertices[indices[8]].x, vertices[indices[8]].y, vertices[indices[8]].z);
    CRVertex3d(vertices[indices[8]].x, vertices[indices[8]].y, vertices[indices[8]].z);
    
    CRColor3d(vertices[indices[9]].x, vertices[indices[9]].y, vertices[indices[9]].z);
    CRVertex3d(vertices[indices[9]].x, vertices[indices[9]].y, vertices[indices[9]].z);
    
    CRColor3d(vertices[indices[10]].x, vertices[indices[10]].y, vertices[indices[10]].z);
    CRVertex3d(vertices[indices[10]].x, vertices[indices[10]].y, vertices[indices[10]].z);
    
    CRColor3d(vertices[indices[11]].x, vertices[indices[11]].y, vertices[indices[11]].z);
    CRVertex3d(vertices[indices[11]].x, vertices[indices[11]].y, vertices[indices[11]].z);
    
    CRColor3d(vertices[indices[12]].x, vertices[indices[12]].y, vertices[indices[12]].z);
    CRVertex3d(vertices[indices[12]].x, vertices[indices[12]].y, vertices[indices[12]].z);
    
    CRColor3d(vertices[indices[13]].x, vertices[indices[13]].y, vertices[indices[13]].z);
    CRVertex3d(vertices[indices[13]].x, vertices[indices[13]].y, vertices[indices[13]].z);
    
    CRColor3d(vertices[indices[14]].x, vertices[indices[14]].y, vertices[indices[14]].z);
    CRVertex3d(vertices[indices[14]].x, vertices[indices[14]].y, vertices[indices[14]].z);
    
    
    
    glEnd();
    
}

// for (int i = 0; i < numIndices; i++) {
//         CRColor3d(vertices[indices[i]].x, vertices[indices[i]].y, vertices[indices[i]].z);
//         CRVertex3d(vertices[indices[i]].x, vertices[indices[i]].y, vertices[indices[i]].z);
//     }

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


    // double resultantRed = fabs(r-rr); # r-rr ==> 0.0 - 6.0 = -6.0 but if abs then 6.0
    //     double resultantGreen = fabs(g-gg);
    //     double resultantBlue = fabs(b-bb);



    //     double r = 1.0;
    // double g = 1.0;
    // double b = 1.0;
    
    
    
    // for (int i = 0; i < numIndices; i++) {
    //     double x = vertices[indices[i]].x;
    //     double y = vertices[indices[i]].y;
    //     double z = vertices[indices[i]].z;
        
    //     double finalRed = (x < 5) ? 1.0 : (rr / 5);
    //     double finalGreen = (y >= 5) ? 1.0 : (gg / 5);
    //     double finalBlue = (z >= 5) ? 1.0 : (bb / 5);
        
    //     CRColor3d(finalRed, finalGreen, finalBlue);
    //     CRVertex3d(vertices[indices[i]].x, vertices[indices[i]].y, vertices[indices[i]].z);
    // }
    

    // for (int i = 0; i < numIndices; i++) {
    //     double x = vertices[indices[i]].x;
    //     double y = vertices[indices[i]].y;
    //     double z = vertices[indices[i]].z;
        
    //     if (x >= 5.0) {r = 1.0 ;} else { r = fabs(x / 5.0);}
    //     if (y >= 5.0) {g = 1.0 ;} else { g = fabs(y / 5.0);}
    //     if (z >= 5.0) {b = 1.0 ;} else { b = fabs(z / 5.0);}
        
    //     CRColor3d(r,g,b);
    //     CRVertex3d(x, y, z);
    // }

