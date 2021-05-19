double HermiteBasis1 (double t) { 
    return ((2*t*t*t) - (3*t*t))+1; 
}
double HermiteBasis2 (double t) { 
    return (-(2*t*t*t) + (3*t*t)); 
}
double HermiteBasis3 (double t) { 
    return ((t*t*t) - (2*t*t)) + t; 
}
double HermiteBasis4 (double t) { 
    return (t*t*t) - (t*t); 
}

CVec3df c(float t, CVec3df p1, CVec3df p4, CVec3df r1, CVec3df r4)
{ 
    CVec3df p= HermiteBasis1(t) * p1 + HermiteBasis2(t) * p4 + HermiteBasis3(t) * r1 + HermiteBasis4(t) * r4;  
 
    return p; 
}




// double HermiteBasis1 (double t) { 
//         return (2*t*t*t)+1; 
//     }
//     double HermiteBasis2 (double t) { 
//         return (4*t)+1; 
//     }
//     double HermiteBasis3 (double t) { 
//         return (6*t*t*t); 
//     }
//     double HermiteBasis4 (double t) { 
//         return (6*t); 
//     }


