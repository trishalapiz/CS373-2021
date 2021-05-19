CVec3df c(float t) {

    if (t >= 0.5 && t <= 1) { // quarter circle

        // p(t)=(r* sin(2*Pi*t/2) +cx, r*cos(2*Pi*t/2) + cy) where t in [0.5, 1.0]
        // return CVec3df((2*sin(2*Pi*(t/2)) + 1), (2*cos(2*Pi*(t/2)) + 1), 3-(2*t));

        2*cos(2*Pi*(t/2)) + 2*sin(2*Pi*(t/2)), 0, -2*sin(2*Pi*(t/2)) + 2*cos(2*Pi*(t/2))
        
        
          
    
    } else { // straight line
    
        return CVec3df(t, 0, 2+t);
    
    }

}