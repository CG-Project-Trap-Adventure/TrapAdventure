#include "r2d3.h"
#include "../draw/draw.h"

R2D3::R2D3() {
    radius = 25;
    cap_radius = 20;
}

void R2D3::draw(float x, float y, float z) {
    Draw draw = Draw();
    glColor3f(0.78, 0.03, 0.0);     //Bounce Red (CP)
    draw.drawCircle(x,y,z,radius, true);
    glColor3f(0.91, 0.62, 0.11);
    draw.drawSemiCircle(x, y+radius, z, cap_radius, true);
}
