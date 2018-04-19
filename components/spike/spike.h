#include <GL/glut.h>
#include <stdio.h>

class Spike{
    private:
        int length;
        int height;
        int xx;
        int yy;
        int zz;
        GLfloat color[3];

    public:
        Spike();
        Spike(int x, int y, int z, int l, int h);
        Spike(int x, int y, int z);
        void drawSpike();
        void spikeCollision();
};
