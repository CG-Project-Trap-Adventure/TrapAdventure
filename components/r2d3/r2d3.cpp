#include "r2d3.h"
#include "../draw/draw.h"
#include "../../states.h"

R2D3::R2D3() {
	radius = 20;
	cap_radius = 18;
	rangle = 19.4712;
	arm_l = 24;
	lastKey = GLUT_KEY_RIGHT;
}

void R2D3::setKey(int key) {
	lastKey = key;
}

void R2D3::draw(float x, float y, float z) {
	Draw draw = Draw();
	glColor3f(0.78, 0.03, 0.0);     //Bounce Red (CP)
	draw.drawCircle(x, y, z, radius, true);
	// draw.drawCircle(x, y, z, radius, false);	// Makes circle more smooth // But also makes the cap weird so...

	glColor3f(0.91, 0.62, 0.11);    //Orangish yellow (CP)
	draw.drawSemiCircle(x, y - radius, z, arm_l, true);

	if(lastKey == GLUT_KEY_LEFT) {
		glPushMatrix();
		glTranslatef(x - radius * sin(rangle * draw.PI / 180.0), y + radius * cos(rangle * draw.PI / 180.0), 5);
		glRotatef(rangle, 0, 0, 1);
		glTranslatef(-x, -y - radius, 5);
		draw.drawSemiCircle(x, y + radius, z, cap_radius, true);
		glPopMatrix();

		draw.drawBox(x, y, z + 0.1, -arm_l, 5);
	} else if(lastKey == GLUT_KEY_RIGHT) {
		glPushMatrix();
		glTranslatef(x + radius * sin(rangle * draw.PI / 180.0), y + radius * cos(rangle * draw.PI / 180.0), 5);
		glRotatef(rangle, 0, 0, -1);
		glTranslatef(-x, -y - radius, 5);
		draw.drawSemiCircle(x, y + radius, z, cap_radius, true);
		glPopMatrix();

		draw.drawBox(x, y, z + 0.1, arm_l, 5);
	}
}
