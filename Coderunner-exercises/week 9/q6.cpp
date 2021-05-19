double HermiteBasis1 (double t) { 
    return 1; 
}
double HermiteBasis2 (double t) { // TANGENT?
    return t; 
}
double HermiteBasis3 (double t) { 
    return (t*t) + t + 1; 
}


double Basis1(double t){ return -(t*t) + 1;} // B1(t) 
double Basis2(double t){ return -(t*t) + t;} // B2(t) 
double Basis3(double t){ return (t*t);} // B3(t) 

CVec3df c(float t, CVec3df p0, CVec3df r0, CVec3df p1)
{
	CVec3df p=Basis1(t)*p0+Basis2(t)*r0+Basis3(t)*p1;
	return p;
}

double HermiteBasis1 (double t) { 
    return -(t*t) + 1; 
}
double HermiteBasis2 (double t) { // TANGENT?
    return -(t*t) + t; 
}
double HermiteBasis3 (double t) { 
    return (t*t); 
}
