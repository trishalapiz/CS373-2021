/*
Given are the vertices

const int numVertices=6;

const float vertices[numVertices][2] = {{200,150},{300,200},{300,300},{200,350},{100,300},{100,200}};

=====>  Which calling sequence of these vertices (using glVertex2fv) results in the shape below if we use the OpenGL commands glBegin(GL_TRIANGLES) and glEnd()?  <=====

(Shape consisting of 6 triangles with different shades of blue)

Write your answer in the form:

****** int index[numIndices]={<input the vertex indices separated by comma>}; ******

IMPORTANT:

1) You can assume that numIndices=18

2) The shape consists of 6 triangles, the first one has the lightest shade of blue (triangle 0) and the last one the darkest shade of blue (triangle 5). 
The first vertex index of triangle k should be k, e.g. triangle 0 starts with the vertex 0.

3) The vertices must be defined in anticlockwise order.

4) Do NOT define colours - the code provided by me will colour the triangles correctly.

If you get the correct image but an error in the test case then this might indicate that you used clockwise order or started the triangles with the wrong vertex index.


-------------
DISCORD
you just need to list the index of the vertices in the right order
*/
int numIndices = 18;

int index[18]={0,1,2, 1,2,3, 2,3,4, 3,4,5, 4,5,0, 5,0,1}; // 0,1,2,3,4,5
