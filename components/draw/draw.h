#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

class Draw {
    public:
		GLfloat PI;
		Draw();
        void drawString(float tx, float ty, float tz, float sx, float sy, float sz, float lw, string text);
        void drawBox(float xx, float yy, float zz, float w, float h);
        void drawCircle(float xx, float yy, float zz, float r, bool fill);
        void drawSemiCircle(float xx, float yy, float zz, float r, bool fill);
};
