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