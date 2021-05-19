// glBegin(GL_QUADS);
// glTexCoord2f(0,0); BOTTOM LEFT
// glVertex3f(0,0,0);
// glTexCoord2f(A,C); BOTTOM RIGHT
// glVertex3f(6,0,0);
// glTexCoord2f(A,B); TOP RIGHT
// glVertex3f(6,4,0);
// glTexCoord2f(0,B); TOP LEFT
// glVertex3f(0,4,0);
// glEnd();

// question 7
glBegin(GL_QUADS);
glTexCoord2f(0,0); // BOTTOM LEFT
glVertex3f(0,0,0);
glTexCoord2f(5,0); // BOTTOM RIGHT
glVertex3f(6,0,0);
glTexCoord2f(5,3); // TOP RIGHT
glVertex3f(6,4,0);
glTexCoord2f(0,3); // TOP LEFT
glVertex3f(0,4,0);
glEnd();

A=5;
B=3;
C=0;

// glBegin(GL_QUADS);
// glTexCoord2f(0,1.5); TOP RIGHT
// glVertex3f(0,0,0);
// glTexCoord2f(A,C); TOP LEFT
// glVertex3f(6,0,0);
// glTexCoord2f(A,B); BOTTOM LEFT
// glVertex3f(6,4,0);
// glTexCoord2f(0,B); BOTTOM RIGHT
// glVertex3f(0,4,0);
// glEnd();

A=3;
B=0;
C=1.5;

// glBegin(GL_QUADS);
// glTexCoord2f(0,0.5);
// glVertex3f(0,0,0);
// glTexCoord2f(A,B);
// glVertex3f(4,0,0);
// glTexCoord2f(C,D);
// glVertex3f(4,4,0);
// glTexCoord2f(E,F);
// glVertex3f(0,4,0);
// glEnd();

A= ;
B= ;
C= ;
D= ;
E= ;
F= ;