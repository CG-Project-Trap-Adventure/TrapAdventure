#include "draw.h"

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