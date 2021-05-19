// In this exercise you need to complete the functions below defining a Ray-Sphere Intersection for a transformed sphere. 
// The sphere is first scaled and then translated. NOTE: please complete both the intersection calculation and the normal calculation:
double Sphere::Intersect(Vector source, Vector d)
{
	// Compute the intersection of a ray with a TRANSFORMED sphere
	// You can assume that for a transformed object the vectors 'scaling' and 'translation" are defined.
	// where (scaling.x,scaling.y,scaling.z) are the scale factors in x,y, and z direction 
	// and (translation.x,translation.y,translation.z) is the translation vector

	// STEP 1: Transform the ray, compute the transformed ray start point and direction
	// transformed ray = inverse matrix of eye + inverse matrix of d
    source = 
	// d = d.Scale(-scaling.x * source.x,-scaling.y * source.y,-scaling.z * source.z); // 1/scaling.x * d.x,
	d = d.Scale(1/scaling.x, 1/scaling.y, 1/scaling.z);

    // ray direction 'd' = pixelPos - eye (slide 11)

	// STEP 2: Compute intersection of the transformed ray with the sphere
	// A, B, and C are the parameters of the quadratic equation for finding the 
	// ray intersection parameter t (see "Ray Tracing" lecture notes)
	float A = d.Dot(d);
	float B = 2 * (eye.Dot(d));
	float C = source.Dot(source)-1;

    float discriminant = (B*B) - (4*A*C);

    if (discriminant <= 0) return -1.0; // misses sphere

    // if discriminant <= 0 then the ray misses the sphere
    // else then the ray intersects with the sphere
    // intersection when (eye + t*d) • (eye + t*d) - 1 = 0
        // p = (eye + t*d)
        // 'eye' from slides is 'source' in Coderunner

	float t1; // the parameter t for the closest intersection point or ray with the sphere. If no intersection t=-1.0
    

	// BEGIN SOLUTION RAY-SPHERE INTERSECTION
	// ================================================================
	// == Delete the line "t=-1.0;" and insert your solution instead ==
	// == NOTE 1: If there is no ray-shere intersection set t=-1.0   == 
	// == NOTE 2: Use C notation so that the code runs in Coderunner ==
	// == NOTE 3: You might want to use the sqrt() function          == 
	// ================================================================
    if (B > 0) {
        t1 = ( (-B - sqrt(discriminant)) / (2*A) );
    } else {
        t1 = ( (-B + sqrt(discriminant)) / (2*A) );
    }

	float t2 = C/(A*t1);

	if (t1<t2) return t1;
	else return t2;
	
	// END SOLUTION RAY-SPHERE INTERSECTION
}

Vector Sphere::Normal(Vector p)
{
	// STEP 3: Calculate the correct normal for the transformed sphere
	// replace the existing code below and use the values 'scaling' and 'translation" to compute the normal of the transformed sphere
	return p.Normalize();
}
// Note: If the ray has two intersection points, return the closer positive value. You can ignore cases where t<0.

// Note: The following variables and functions are already defined for you to use:

// Vector: v1+v2 - adds the vectors v1 and v2 and returns resulting vector

// Vector: v1-v2 - subtracts v2 from v1 and returns resulting vector

// Vector: v1/v2 - returns the component-wise division of the vectors (v1.x/v2.x, v1.y/v2.y, v1.z/v2.z)

// Vector: v1 * t - scales the vector v1 by t and returns resulting vector

// Vector v.Scale(float a, float b, float c) - scales each component of the vector v

// float v1.Dot(Vector v2) - returns the dot product of vector v1 and v2