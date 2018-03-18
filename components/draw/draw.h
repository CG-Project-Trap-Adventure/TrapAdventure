#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Draw {
    public:
        void drawString(float tx, float ty, float tz, float sx, float sy, float sz, float lw, string text);
        void drawBox(float xx, float yy, float zz, float w, float h);
};