// In this exercise you need to complete the function below defining an intersection between a Ray and a Plane with a triangular hole. 
// The plane normal n is provided and the hole in the plane is defined by three vertices A, B and C.

// In the answer space is given a function for computing the intersection between a ray and a triangle. 
// Modify this function such that it computes instead the intersection between a ray and a plane with a triangular hole. 
// Your answer should have the following format:
    // double PlaneWithTriangleHole::Intersect(Vector source, Vector d)
    // {
    // 	// modify calculation from ray-triangle intersection in the answer box below
    // 	// and return correct value for t. If there is no intersection t should be -1.0
    // }

// Note: The following variables and functions are already defined for you to use:

// Vector A, B, C -> coordinates of 3 vertices of the triangle

// Vector n -> plane normal

// Vector: v1+v2 -> adds the vectors v1 and v2 and returns resulting vector

// Vector: v1-v2 -> subtracts v2 from v1 and returns resulting vector

// Vector: v1 * t -> scales the vector v1 by t and returns resulting vector

// Vector v.Scale(float a, float b, float c) -> scales each component of the vector v

// float v1.Dot(Vector v2) -> returns the dot product of vector v1 and v2

// Vector v1.Cross(Vector v2) -> returns the cross product of vector v1 and v2

// FROM TUTORIAL
// test to see if ray is parallel to the plane or not
    // parallel = no intersection


double PlaneWithTriangleHole::Intersect(Vector source, Vector d)
{
	// modify calculation from ray-triangle intersection in the answer box below
	// and return correct value for t. If there is no intersection t should be -1.0

    // source == eye == startPoint ??

    if (d.Dot(n) == 0) { // ray is parallel to the plane
        return -1.0;
    }

    // compute 'p' by computing 't'
    float t = ((A - source).Dot(n)) / d.Dot(n) ; // if positive, there is an intersection?
    Vector p = source + d.Scale(t,t,t); // Vector 'd' is scaled by 't'

    float scalarOne = ((p-A).Cross(B-A)).Dot(n); // ((B-A) x (p-A))•n
    float scalarTwo = ((p-B).Cross(C-B)).Dot(n);
    float scalarThree = ((p-C).Cross(A-C)).Dot(n);

    if (scalarOne < 0 && scalarTwo < 0 && scalarThree < 0) return -1.0;
	if (scalarOne > 0 && scalarTwo > 0 && scalarThree > 0) return -1.0;
	return t;
    
}

// Ray-Triangle Intersection 
// • Normal n = (B-A) x (C-A) 
// • Implicit function for corresponding plane: (p A) n 
// • Intersection with plane when (eye + t d - A).n = O 
// i.e. t = (—(eye - A)•n) / d•n
// • Is the ray-plane intersection at p=(eye + t d) inside the triangle? 
// Calculate scalars for three cross products (normals for the plane): 
    // ((B-A) x (p-A))•n and ((C-B) x (p-B))•n and ((A-C) x (p-C))•n 
// If they all have the same sign (e.g. all negative) then p is inside the triangle 
// Each tests if p is on the inside or outside of one of the edges 
// If p on the inside of an edge, then normal is directed towards us 

// The code below computes the intersection with a triangle
// you need to change it so that you compute the intersection 
// with a plane with  triangular hole
double PlaneWithTriangleHole::Intersect(Vector source, Vector d)
{
	float t = -1.0;
	float dn = d.Dot(n);
	if (dn == 0)	// plane and ray parallel
		return -1.0;
	t = (A - source).Dot(n) / dn;
	Vector p = source + d.Scale(t,t,t);
	float t1, t2, t3;
	t1 = (p - A).Cross(B - A).Dot(n);
	t2 = (p - B).Cross(C - B).Dot(n);
	t3 = (p - C).Cross(A - C).Dot(n);

	if (t1 < 0 && t2 < 0 && t3 < 0) return t;
	if (t1 > 0 && t2 > 0 && t3 > 0) return t;
	return -1.0;
}