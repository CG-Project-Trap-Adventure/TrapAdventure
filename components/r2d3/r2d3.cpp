#include "r2d3.h"
#include "../draw/draw.h"

R2D3::R2D3() {
	radius = 25;
	cap_radius = 20;
	lastKey = GLUT_KEY_RIGHT;
}

void R2D3::setKey(int key) {
	lastKey = key;
}

void R2D3::draw(float x, float y, float z) {
	Draw draw = Draw();
	glColor3f(0.78, 0.03, 0.0);     //Bounce Red (CP)
	draw.drawCircle(x, y, z, radius, true);
	draw.drawCircle(x, y, z, radius, false);	// Makes circle more smooth

	glColor3f(0.91, 0.62, 0.11);    //Orangish yello (CP)
	if(lastKey == GLUT_KEY_LEFT) {
		glPushMatrix();
		glTranslatef(x - radius * sin(30.0 * draw.PI / 180.0), y + radius * cos(30.0 * draw.PI / 180.0), 5);
		glRotatef(30, 0, 0, 1);
		glTranslatef(-x, -y - radius, 5);
		draw.drawSemiCircle(x, y + radius, z, cap_radius, true);
		glPopMatrix();

		draw.drawBox(x, y, z + 0.1, -40, 5);
	} else if(lastKey == GLUT_KEY_RIGHT) {
		glPushMatrix();
		glTranslatef(x + radius * sin(30.0 * draw.PI / 180.0), y + radius * cos(30.0 * draw.PI / 180.0), 5);
		glRotatef(30, 0, 0, -1);
		glTranslatef(-x, -y - radius, 5);
		draw.drawSemiCircle(x, y + radius, z, cap_radius, true);
		glPopMatrix();

		draw.drawBox(x, y, z + 0.1, 40, 5);
	}
}
