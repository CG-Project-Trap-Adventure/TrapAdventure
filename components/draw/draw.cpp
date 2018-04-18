#include "draw.h"

Draw::Draw() {
	PI = 3.1415926536;
}

void Draw::drawString (float tx, float ty, float tz, float sx, float sy, float sz, float lw, string text) {
	glPushMatrix();
	glTranslatef(tx, ty, tz);
	glScalef(sx, sy, sz);
	glLineWidth(lw);
	for (int i = 0; i < text.length(); i++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i]);
	}
	glPopMatrix();
}

void Draw::drawBox(float xx, float yy, float zz, float w, float h) {
	glBegin(GL_POLYGON);
	glVertex3f(xx, yy, zz);
	glVertex3f(xx+w, yy, zz);
	glVertex3f(xx+w, yy+h, zz);
	glVertex3f(xx, yy+h, zz);
	glEnd();
}

void Draw::drawCircle(float xx, float yy, float zz, float r, bool fill = false) {
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

	GLfloat twicePi = 2.0f * PI;
	if(fill) {
		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(xx, yy, zz);
	}
	else {
		glBegin(GL_LINE_LOOP);
	}
	for(i = 0; i <= lineAmount;i++) {
		glVertex3f(
			xx + (r * cos(i * twicePi / lineAmount)),
			yy + (r * sin(i * twicePi / lineAmount)),
			zz
		);
	}
	glEnd();
}

void Draw::drawSemiCircle(float xx, float yy, float zz, float r, bool fill = false) {
	int i;
	int lineAmount = 100; //# of triangles used to draw circle
	PI = 3.1415926536;

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
	if(fill) {
		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(xx, yy, zz);
	}
	else {
		glBegin(GL_LINE_LOOP);
	}
	for(i = 0; i <= lineAmount/2;i++) {
		glVertex3f(
			xx + (r * cos(i * twicePi / lineAmount)),
			yy + (r * sin(i * twicePi / lineAmount)),
			zz
		);
	}
	glEnd();
}
