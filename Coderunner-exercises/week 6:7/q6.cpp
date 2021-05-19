// Given is a function drawCube() which draws a unit cube centered at the origin with coloured dots on its top (see image below). 
// The top front corner has a yellow dot, the top-back corner has a cyan dot and the top-left and top-right corners have grey and magenta dots, respectively.

// Please write OpenGL code to render a robot as illustrated in the image below. 
// The robot has three arms with lengths armLength. 
// The bottom arm is centered at the origin and aligned with the y-axis. 
// The centre of the bottom face of the middle arm is equal to the centre of the top face of the bottom arm, 
//     and the centre of the bottom face of the top arm is equal to the centre of the top face of the middle arm. 
// The bottom arm has the width bottomArmWidth, the middle and top arm have the width topArmWidth.

// The whole robot is rotated by an angle φ (phi) around its centre axis. 
// The second arm is rotated by the angle θ (theta) with respect to the bottom arm and 
//     the third arm is rotated by 2θ with respect to the second arm as illustrated in the figure below.

// The values for bottomArmWidth and topArmWidth are specified in the code hidden from you. The values for armLength, φ (phi) and θ (theta) are specified in the test cases.

// In order for the automarker to work correctly you:

// (1) must use the function drawCube() to draw each robot arm

// (2) must draw the bottom arm (red) first, then the middle arm (green) and then the top arm (blue)

// (3) must use the variables armLength, phi, and theta, which have different values in the test cases, and the variables bottomArmWidth and topArmWidth.

// (4) must make sure that the dots at the top of each cube are in the correct positions. If you rotate the arms around their axes the robot looks the same, 
    // but the transformation matrices are different and the automarker will mark it as wrong.



// Tip: Start by drawing the bottom arm and compare visually with the correct outputs shown in this question text. 
// The position of the middle arm should be defined with respect to the bottom arm, and the position of the top arm with respect to the middle arm. 
// Hence the rotation for the bottom arm will rotate the whole robot, and the rotation for the middle arm, will rotate the top arm as well. 
// In addition to glRotatef, glTranslatef, and glScalef, you might also want to use glPushMatrix() and glPopMatrix().

// armLength = 2;
// phi = 180.0;
// theta = 160.0;

// armLength = 3;
// phi = 90.0;
// theta = 45.0;

// armLength = 4;
// phi = 150.0;
// theta = 140.0;

// RED
glPushMatrix();
glRotatef(phi,1,0,0); // should rotate the entire robot
glTranslatef(0,armLength/2,0);
glScalef(bottomArmWidth,armLength,0);
drawCube();
glPopMatrix();

// GREEN
glRotatef(theta,1,0,0);
glTranslatef(0,armLength+(armLength/2),0); // glScalef(topArmWidth,armLength/2,0);
glScalef(topArmWidth,armLength,0);
drawCube();

// BLUE
glRotatef(2*theta,1,0,0);
glTranslatef(0,armLength+(armLength/2),0);
glScalef(topArmWidth,armLength,0);
drawCube();

// scale to 1, move, scale back up ==> scale to 1 meaning NORMALISE?
// Scale, translate, rotate, translate ===> with push() and pop() matrices

// THEY FINALLY CONNECT

// red
glPushMatrix();
glTranslatef(0,armLength/2,0);
glScalef(bottomArmWidth,armLength,0);
drawCube();
glPopMatrix();

// green
glPushMatrix();
glTranslatef(0,armLength+(armLength/2),0); 
glScalef(topArmWidth,armLength,0);
drawCube();
glPopMatrix();

// blue
glPushMatrix();
glTranslatef(0,(2*armLength)+1,0); 
glScalef(topArmWidth,armLength,0);
drawCube();
glPopMatrix();

//  UPDATED VERSION

// red
glRotatef(phi,0,1,0);
glPushMatrix();
glTranslatef(0,armLength/2,0);
glScalef(bottomArmWidth,armLength,0);
drawCube();
glPopMatrix();

// green
glRotatef(theta,0,0,1);
glPushMatrix();
glTranslatef(0,armLength+(armLength/2),0); 
glScalef(topArmWidth,armLength,0);
drawCube();
glPopMatrix();

// glPushMatrix();
// glRotatef(theta,0,0,1);
// glPopMatrix();
// glPushMatrix();
// glRotatef(theta,0,0,1);
// glTranslatef(0,armLength+(armLength/2),0); 
// glScalef(topArmWidth,armLength,0);
// drawCube();
// glPopMatrix();


// blue
glRotatef(2*theta,0,0,1);
glPushMatrix();
glTranslatef(0,(2*armLength)+1,0); 
glScalef(topArmWidth,armLength,0);
drawCube();
glPopMatrix();


int armLength = 2;
int theta = 160;
glRotatef(theta,1,1,1);
glTranslatef(0,2*armLength,0); 
glScalef(0.25,armLength,0);
drawCube();


// 4 lines for 1st cube

// 6 lines each for 2nd and 3rd cubes

// red
glRotatef(phi,0,1,0);
glPushMatrix();
glTranslatef(0,armLength/2,0);
glScalef(bottomArmWidth,armLength,0);
drawCube();
glPopMatrix();

// green
glTranslatef(0,armLength+(armLength/2),0);
glScalef(topArmWidth,armLength,0);
glRotatef(theta,0,1,0);

// DRAW ONE
drawOne();
glTranslatef(2,2,0);
glRotatef(-20,0,0,1);
glTranslatef(-2,0,0);
drawOne();
glTranslatef(2,2,0);
glRotatef(-20,0,0,1);
glTranslatef(-2,0,0);
drawOne();



// glRotatef(phi,0,1,0);
// glPushMatrix();
// glTranslatef(0,armLength/2,0);
// glScalef(bottomArmWidth,armLength,0);
// drawCube();
// glPopMatrix();

// glPushMatrix();
// glTranslatef(0,armLength/2,0);
// glRotatef(theta,0,0,1);
// glTranslatef(armLength/2,0,0);
// glPopMatrix();
// drawCube();


// red
//glRotatef(phi,0,1,0);
glPushMatrix();
glTranslatef(0,armLength/2,0);
glScalef(bottomArmWidth,armLength,0);
drawCube();
glPopMatrix();

// green
glPushMatrix();
//glTranslatef(-armLength,-armLength,0);
glRotatef(theta,0,0,1);
glTranslatef(0,armLength,0);
drawCube();
glPopMatrix();

// blue
//glTranslatef(armLength,armLength,0);
glRotatef(theta,0,0,1);
glTranslatef(armLength,armLength,0);
drawCube();




// glRotatef(phi,0,1,0);
// glPushMatrix();
// glTranslatef(0,armLength/2,0);
// glScalef(bottomArmWidth,armLength,bottomArmWidth);
// drawCube();
// glPopMatrix();
// glPopMatrix();

// glPushMatrix();
// //glTranslatef(0,0,armLength);
// glTranslatef(0,armLength,0);
// glRotatef(theta,0,0,1);
// drawCube();

// getting 110 for the code below, so blue not working? but blue is in the right angle but green for length = 2 in wrong position

// RED
glRotatef(phi,0,1,0);
glPushMatrix();
glTranslatef(0,armLength/2,0);
glScalef(bottomArmWidth,armLength,bottomArmWidth);
drawCube();
glPopMatrix();

// GREEN
glTranslatef(0,armLength,0);
glPushMatrix();
glRotatef(theta,0,0,1);
glPushMatrix();
glTranslatef(0,armLength/2,0);
glPushMatrix();
glScalef(topArmWidth,armLength,topArmWidth);
drawCube();
glPopMatrix();
glPopMatrix();

// BLUE
//glTranslatef(0,armLength,0);
glPushMatrix();
glRotatef(2*theta,0,0,1);
glTranslatef(0,armLength,0);
glPushMatrix();
glScalef(topArmWidth,armLength,topArmWidth);
drawCube();