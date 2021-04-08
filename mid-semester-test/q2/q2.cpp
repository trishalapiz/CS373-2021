/*
Write a function coplanar(), that takes as parameters four 3D vectors representing points, and returns a boolean: true if all four points lie on the same plane, false otherwise. Your function should have the following signature:

bool coplanar(Vector3 p, Vector3 q, Vector3 r, Vector3 s)

You can assume that Vector3 is a class that represents a 3D vector, and exposes fields named x, y, and z, and that the following functions are available to you:

double dot(Vector3 u, Vector3 v) //dot product

Vector3 cross(Vector3 u, Vector3 v) //cross product

You can assume that the Vector3 class has the following member functions available to you:

Vector3 Vector3.normalized() //returns a vector pointing in the same direction with length 1

double Vector3.magnitude() //returns the length of the vector

You can assume that the Vector3 class supports the following operators:

Vector3 + Vector3

Vector3 - Vector3
*/

bool coplanar(Vector3 p, Vector3 q, Vector3 r, Vector3 s) {
    Vector3 ps = s - p;
    Vector3 pq = q - p;
    Vector3 pr = r - p;
    double final = dot(ps, cross(pq,pr));
    
    if (final == 0) {
        return true;
    } else {
        return false;
    }
    
}


const int numVertices=6;
const float vertices[numVertices][3] = {{200,0,0},{400,300,0},{200,400,0},{200,400,0},{0,300,0},{200,0,0}};
glBegin(GL_TRIANGLES);
glVertex3fv(vertices[0]);
glVertex3fv(vertices[1]);
glVertex3fv(vertices[2]);
glVertex3fv(vertices[3]);
glVertex3fv(vertices[4]);
glVertex3fv(vertices[5]);
glEnd();

 

Instead of glVertex3d(), use CRVertex3d()

Instead of glColor3d(), use CRColor3d()


glBegin(GL_TRIANGLES);
 
glVertex3d(20.0, 0.0, 0.0);
glVertex3d(40.0, 30.0, 0.0);
glVertex3d(20.0, 40.0, 0.0);
glVertex3d(20.0, 40.0, 0.0);
glVertex3d(0.0, 30.0, 0.0);
glVertex3d(20.0, 0.0, 0.0);

glEnd();
