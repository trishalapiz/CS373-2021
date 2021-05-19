/*
Phong Shading interpolates the surface normal of a polygon and computes the perceived colour of each pixel using the Phong Illumination model. 
In modern OpenGL this is usually implemented using fragment shaders. In this exercise you will simulate such a fragment shader.


Write a function drawPixel(), which renders a vertex with the correct surface colour using Phong shading and the ACHROMATIC Phong Illumination model. 
This function takes as parameters two values i and j, which represent the coordinates of the pixel within the quad.

Your code should have the following structure:

void drawPixel(int i, int j) 
{
	pointOnSurface = p(i,j);
	Vector3 surfaceNormal; //YOU DO: compute the interpolated surface normal
	double c; //YOU DO: compute correct surface colour at pixel (i,j) using the Phong Illumination model
	glColor3d(c, c, c);
	glVertex3d(pointOnSurface.x, pointOnSurface.y, pointOnSurface.z);
}


NOTE 1: In order to compute the surface normal at pixel (i,j) you need to BILINEARLY interpolate the normals at the corners of the polygon.

The polygon has 121 pixels (0<=i,j<=120). The normals at the corner of the polygon are: 
==> n0 at pixel (0,0), 
==> n1 at pixel (0, 120), 
==> n2 at pixel (120, 0) and 
==> n3 at pixel (120,120)

NOTE 2: Once you have the surface normal you can compute the colour (intensity) of pixel (i,j) using the function:

phongSingleColour(ambientIntensity, diffuseIntensity, specularIntensity,ambientReflecCoef, diffuseReflecCoef, specularReflecCoef, shininess, kc, kl, kq, pointOnSurface, surfaceNormal, 
    lightPosition, viewPoint)

You do not need to include your code for the previous question - you can assume this function is already implemented for you.

You can assume that all parameters except for surfaceNormal are already defined as global variables.

*/

// FROM PIAZZA

//  Bilinear interpolation is an extension of the linear interpolation that you did in the first geometry programming quiz. 
//  It's the same concept, but interpolating the value (the surface normal vector) in two dimensions instead of one.

// Given two values (which could be scalars, or vectors as in the case of this quiz and the geometry quiz), 
// we may want some value at a location between them. For example, we might want the value halfway between 1 and 3 (which is 2). 
// We DEFINE a value which tells us HOW FAR BETWEEN our two values we are looking. 
	// This is generally referred to as t. 
// If t is equal to 0, we are looking at exactly the first value, if t is equal to 1, we are looking at the second value, 
// and for any t-value between 0 and 1, we are looking for the value that is the corresponding distance between our first and second value. 
// In the example of ranging from 1 to 3, a t-value of 0.5 would mean halfway between 1 and 3 (2). 
// A t-value of 0.25 would mean quarter of the way (1.5), a t-value of 0.75 would give 2.5, etc. 
// If we were interpolating from 3 to 1, it would be the same, but going in the other direction (so a t-value of 0.5 would still be 2, but a t-value of 0.25 would be 2.5).


Now for the quiz question:

n0, n1, n2, & n3 give the surface normal vectors at the corners of the square polygon. 
i and j give the horizontal and vertical coordinates of the pixel being currently drawn. 
Using the width of the polygon and i, you can figure out how far across the polygon the pixel is horizontally (and so get a horizontal t-value). 
Using the height of the polygon and j, you can figure out how far across the polygon the pixel is vertically (and so get a vertical t-value).

Vector3 lerp(Vector3 u, Vector3 v, double t) {
    double newX = t * (u.x - v.x);
    double newY = t * (u.y - v.y);
    double newZ = t * (u.z - v.z);

    return Vector3(u.x-newX, u.y-newY, u.z-newZ);
}

return (1 - tx) * (1 - ty) * c00 + 
        tx * (1 - ty) * c10 + 
        (1 - tx) * ty * c01 + 
        tx * ty * c11; 

		tx = i
		ty = j

The t-value can be worked out based on the range between our two locations (so between 1 and 3 we have a range of 2), 
and what fraction of that range our new point covers (so location 1.5 is 0.5 units into a range of 2. 0.5/2 gives us 0.25).

void drawPixel(int i, int j) 
{
	// // t values consist of both i and j
	// pointOnSurface = p(i,j);
	// // Vector3 horizontal = lerp(n1,n3,i);
	// // Vector3 vertical = lerp(n0,n2,j);

	// // Vector3 bl = ((1-i) * (1-j) * n0 )+ (i * (1-j) * n2) + ((1-i) * j * n1) + (i * j * n3);
	

	// // Vector3 top = lerp(n1,n3, (double) i);
	// // Vector3 bottom = lerp(n0,n2, (double) j);

	// // Vector3 bl = lerp(top,bottom,pointOnSurface);


	// Vector3 surfaceNormal = lerp(top,bottom,j);
	// double c; //YOU DO: compute correct surface colour at pixel (i,j) using the Phong Illumination model
	// glColor3d(c, c, c);
	// glVertex3d(pointOnSurface.x, pointOnSurface.y, pointOnSurface.z);

	pointOnSurface = p(i,j);
	
	Vector3 top = lerp(n1,n3, (double) i);
	Vector3 bottom = lerp(n0,n2, (double) j);

	double range = ((top.y - bottom.y) - j) / (top.y - bottom.y);
	
	Vector3 surfaceNormal = lerp(top,bottom, range);
	double c = phongSingleColour(ambientIntensity, diffuseIntensity, specularIntensity, ambientReflecCoef, diffuseReflecCoef, specularReflecCoef, shininess, kc, kl, kq, pointOnSurface, surfaceNormal, lightPosition, viewPoint);
	glColor3d(c, c, c);
	glVertex3d(pointOnSurface.x, pointOnSurface.y, pointOnSurface.z);
}