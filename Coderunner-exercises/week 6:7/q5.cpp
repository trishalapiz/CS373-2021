// https://coderunner.auckland.ac.nz/moodle/mod/quiz/attempt.php?attempt=30768&cmid=3674&page=4&scrollpos=1258.6666259765625

// Please write OpenGL code to rotate this cube such that it stands on its corner, i.e. the black vertex is the origin and the white vertex lies on the y-axis.

// Please only use OpenGL transformations, e.g. glTranslatef, glRotatef

// Please do NOT draw the cube itself - this is done automatically by the uploaded code

// TIP:

// This is easiest done using only two rotations, first around z-axis and then around x-axis. The hard part is to find out the correct rotation angles. It is a good idea to make yourself a drawing of the situation and from this compute the angles.

// You can make use of the following constants and functions: atan(), sqrt(), Pi

// Note that glRotatef uses an angle in degree whereas atan() returns an angle in radian.

// BY RANDOMLY GUESSING
glRotatef(-35,1,0,0); // angle, x, y, z
glRotatef(45,0,0,1)
// atan() returns angle after calculating number from 'TOA'

// BY ACTUALLY CALCULATING THE ANGLES

// z-axis:
double zAngle = atan(1.5/1.5)