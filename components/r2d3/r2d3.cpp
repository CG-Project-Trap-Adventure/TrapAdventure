#include "r2d3.h"
#include "../draw/draw.h"
#include "../../states.h"

R2D3::R2D3() {
    radius = 25;
    cap_radius = 20;
}

void R2D3::draw(float x, float y, float z) {
    Draw draw = Draw();
    glColor3f(0.78, 0.03, 0.0);     //Bounce Red (CP)
    draw.drawCircle(x,y,z,radius, true);
    glColor3f(0.91, 0.62, 0.11);    //Orangish yello (CP)
    draw.drawSemiCircle(x, y+radius, z, cap_radius, true);
    if(lastKey == GLUT_KEY_LEFT)
      draw.drawBox(x, y, z+ 0.1, -40, 2);
    else if(lastKey == GLUT_KEY_RIGHT)
      draw.drawBox(x, y, z+ 0.1, 40, 2);
}
