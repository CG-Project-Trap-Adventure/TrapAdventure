#include <GL/glut.h>
#include <stdio.h>

class Spike{
    public:
        int length;
        int height;
        int xx;
        int yy;
        int zz;
		int sid;
        GLfloat color[3];
        bool visible;
        time_t show_time;
        time_t prev_time;

    // public:
        Spike();
        Spike(int x, int y, int z, int l, int h);
        Spike(int x, int y, int z, int id, bool vis = true, time_t t = 0);
        void drawSpike();
        void spikeCollision();
};
