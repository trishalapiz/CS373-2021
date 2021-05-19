/*
Write a function phongSingleColour() which implements the ACHROMATIC version of the Phong Illumination equation.
If the function is implemented correctly you should get the following result (Note: this image is rendered using only your implementation and does not use OpenGL lights or materials)


double phongSingleColour(double ambientIntensity, double diffuseIntensity, double specularIntensity,double ambientReflecCoef, 
       double diffuseReflecCoef, double specularReflecCoef,double shininess,double kc, double kl, double kq, Vector3 pointOnSurface, 
       Vector3 surfaceNormal, Vector3 lightPosition, Vector3 viewPoint)



The Vector3 class from previous exercises is available to you, with the following member functions:

Vector3 Vector3.normalized() //returns a vector pointing in the same direction with length 1

double Vector3.magnitude() //returns the length of the vector

void Vector3.normalize() //normalises the vector (destructive)

In addition, you can assume the + and - operators are available for the Vector3 class.


You can assume that the following functions are also defined:

double dot(Vector3 a, Vector3 b) //returns the dot product of a and b

Vector3 cross (Vector3 a, Vector3 b) //returns the cross product of a and b

double pow(double a, double b) //returns a to the power of b

double Vector3.magnitude() usage example: double mag = myVector.magnitude();

*/


double phongSingleColour(double ambientIntensity, double diffuseIntensity, double specularIntensity,double ambientReflecCoef, double diffuseReflecCoef, double specularReflecCoef,double shininess,
            double kc, double kl, double kq, Vector3 pointOnSurface, Vector3 surfaceNormal, Vector3 lightPosition, Vector3 viewPoint) {
    // double ambient = ambientIntensity * ambientReflecCoef;
    // double diffuse = (diffuseIntensity * diffuseReflecCoef) * ( (dot(surfaceNormal, lightPosition)) / (surfaceNormal.magnitude() * lightPosition.magnitude()) );

    // Vector3 h = Vector3.normalised(surfaceNormal.normalize() + viewPoint.normalize() );


    // double specular = (specularIntensity * specularReflecCoef) * pow((dot(h, lightPosition) / h.magnitude() * lightPosition.magnitude()), shininess);

    // // Vector3 h = Vector3.normalize(surfaceNormal.normalised() + viewPoint.normalize() );
    // // dot(h, m);
    // // h.magnitude() * lightPosition.magnitude()

    // return ambient + (diffuse + specular) / (kc + );

    // m = surface normal

/*---------------------*/
    // to substitute
    Vector3 s = lightPosition - pointOnSurface;
    Vector3 v = viewPoint - pointOnSurface;
    Vector h = Vector3();
    // h.normalized(s.normalized() + v.normalized())

    double ambient = ambientIntensity * ambientReflecCoef;
    // Vector3 s = lightPosition - pointOnSurface;
    
    double diffuse = (diffuseIntensity * diffuseReflecCoef) * ( dot(s,surfaceNormal) / (s.magnitude() * surfaceNormal.magnitude()) );

    double base = dot((h.normalized(s.normalized() + v.normalized())), surfaceNormal) / ( (h.normalized(s.normalized() + v.normalized())) * surfaceNormal.magnitude() );
    double specular = (specularIntensity * specularReflecCoef) * pow(base,shininess);

    double denominator = kc + (kl * s.magnitude()) + (kq * pow(s.magnitude(), 2));

    // bracket = dot((h.normalized(s.normalized() + v.normalized())), surfaceNormal) / ( (h.normalized(s.normalized() + v.normalized())) * surfaceNormal.magnitude() )
    // (h.normalized(s.normalized() + v.normalized()))

    


    
    // Vector3 s = lightPosition - viewPoint;
    // Vector3 a = Vector3();
    // Vector3 d = a.magnitude(s);
    
    // double diffuse = (diffuseIntensity * diffuseReflecCoef) * ( (dot(s, surfaceNormal)) / (a.magnitude(s) * a.magnitude(surfaceNormal)) );
    
    // Vector3 b = Vector3();
    // Vector3 h = b.normalize(b.normalize(s) + b.normalize(v));

    // double specular = (specularIntensity * specularReflecCoef) * pow((dot(h, surfaceNormal) / (b.normalize(h) * b.normalize(surfaceNormal))), shininess); 
    
    
    // return ambient + ( (diffuse + specular) / (kc + (kl * d) + (kq + pow(d,2))) );



}


// FINAL
double phongSingleColour(double ambientIntensity, double diffuseIntensity, double specularIntensity,double ambientReflecCoef, double diffuseReflecCoef, double specularReflecCoef,double shininess,double kc, double kl, double kq, Vector3 pointOnSurface, Vector3 surfaceNormal, Vector3 lightPosition, Vector3 viewPoint) {
    Vector3 s = lightPosition - pointOnSurface;
    Vector3 v = viewPoint - pointOnSurface;
    Vector3 h = (s.normalized() + v.normalized()).normalized();
    
    double ambient = ambientIntensity * ambientReflecCoef;
    
    double diffuse = (diffuseIntensity * diffuseReflecCoef) * ( dot(s,surfaceNormal) / (s.magnitude() * surfaceNormal.magnitude()) );
    
    double base = dot(h, surfaceNormal) / ( h.magnitude() * surfaceNormal.magnitude() );
    double specular = (specularIntensity * specularReflecCoef) * pow(base,shininess);

    double denominator = kc + (kl * s.magnitude()) + (kq * pow(s.magnitude(), 2));
    
    return ambient + ((diffuse + specular) / denominator);

}