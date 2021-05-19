// In this exercise you need to complete the function below defining Ray-Plane Intersection:


// double Plane::Intersect(Vector source, Vector d)
// {
//     /*====================================================*/
//     /* == Enter ray/plane intersection calculations here ==*/
//     /* == Delete the line "t = -1.0;" and insert your solution instead ==*/
//     /* == NOTE 1: If there is no ray-plane intersection set t = -1.0; ==*/
//     /*====================================================*/
// 	float t = -1.0;
//         return t;
// }
// Note: The following variables are already defined for you to use:

// float a -> distance from origin to the plane

// Vector n -> plane normal

// Vector: v1+v2 -> adds the vectors v1 and v2 and returns resulting vector

// Vector: v1-v2 -> subtracts v2 from v1 and returns resulting vector

// Vector: v1 * t -> scales the vector v1 by t and returns resulting vector

// Vector v.Scale(float a, float b, float c) -> scales each component of the vector v

// float v1.Dot(Vector v2) -> returns the dot product of vector v1 and v2

// Vector v1.Cross(Vector v2) -> returns the cross product of vector v1 and v2

double Plane::Intersect(Vector source, Vector d)
{
    /*====================================================*/
    /* == Enter ray/plane intersection calculations here ==*/
    /* == Delete the line "t = -1.0;" and insert your solution instead ==*/
    /* == NOTE 1: If there is no ray-plane intersection set t = -1.0; ==*/
    /*====================================================*/
	
    // if t is negative, set t = -1.0 and return this
    // source == eye == startPoint ??

    // FIRST SOLUTION
    // double t = ((a - source.Dot(n)) / d.Dot(n)) ; 
    // if (t > 0) {
    //     return t;
    // } else {
    //     t = -1.0;
    //     return t;
    // }

    // SECOND SOLUTION
    double t = -1.0;

    if ( ((a - source.Dot(n)) / d.Dot(n)) > 0 ) t = ((a - source.Dot(n)) / d.Dot(n));

    return t;

}

// STARTPOINT == eye

// Ray-Plane Intersection 
// • Implicit function for plane (normal n, distance a 
// from origin): 
// • Intersection when (eye + t d).n — a = 0 
// i.e. t = (a—eye•n) / d•n
// • If d.n=0 then ray parallel to plane (ignore plane) 
// • If t negative then ray directed away from plane 
// (no intersection that can be seen) 

// for (int i = 0; i < numIndices; i++) {
        
//         double r = 1.0;
//         double g = 1.0;
//         double b = 1.0;
    
//         double x = vertices[indices[i]].x;
//         double y = vertices[indices[i]].y;
//         double z = vertices[indices[i]].z;
        
//         if (x < 5) r = fabs(x / 5);
//         if (y < 5) g = fabs(y / 5);
//         if (z < 5) b = fabs(z / 5);
        
//         CRColor3d(r,g,b);
//         CRVertex3d(x, y, z);
//     }