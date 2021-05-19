// In this exercise you need to complete the code fragment below defining primary rays:

// for(int r=0; r<windowHeight; r++) {
//   for(int c=0; c<windowWidth; c++) {

//     // construct ray through (c, r) using u,v,n and H,W

//     //  Please ONLY MODIFY the values for dx, dy, dz

//     dx = -n.x*N;

//     dy = -n.y*N;

//     dz = -n.z*N;

//     Vector d = Vector(dx, dy, dz);

//     // intersect ray with scene objects

//     Hit hit = intersect(eye, d);

//     // shade pixel accordingly

//     Color color = shade(hit);

//     glColor3f(color.r, color.g, color.b);

//     glVertex2f((GLfloat)c, (GLfloat)r);

//   }

// }


// Please compute the ray direction (dx, dy, dz) by modifying the equations for these values appropriately

// Please use the following parameters:

// W and H - window width and height (in units)

// N - view plane distance from eye

// windowWidth and windowHeight - size of display window in pixels (in lecture notes called nCols and nRows)

// c and r - index of current pixel

// u.x,u.y,u.z, v.x,v.y,v.z, n.x, n.y, n.z - uvn view coordinate system

for (int r=0; r<windowHeight; r++) {
  for (int c=0; c<windowWidth; c++) {

    // construct ray through (c, r) using u,v,n and H,W

    //  Please ONLY MODIFY the values for dx, dy, dz

    dx = (W * ((2*c / (float) (windowWidth-1)) - 1) * u.x);

    dy = (H * ((2*r / (float) (windowHeight-1)) - 1) * v.y);

    dz = -n.z*N;

    Vector d = Vector(dx, dy, dz);

    // intersect ray with scene objects

    Hit hit = intersect(eye, d);

    // shade pixel accordingly

    Color color = shade(hit);

    glColor3f(color.r, color.g, color.b);

    glVertex2f((GLfloat)c, (GLfloat)r);

  }

}