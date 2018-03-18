#include <GL/glut.h>
#include <stdio.h>

class Spike{
    private:
        int length;
        int height;
        GLfloat color[3];
    
    public:
        Spike();
        Spike(int l, int h);
        void drawSpike(int x, int y);
};