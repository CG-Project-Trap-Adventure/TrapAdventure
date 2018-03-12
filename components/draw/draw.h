#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Draw {
    public:
        void drawString(float, float, float, float, float, float, float, string);
        void drawBox(float, float, float, float, float);
};