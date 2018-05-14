#include <GL/glut.h>
#include <iostream>
#include <time.h>

using namespace std;

class Platform {
// private:
public:
	int length;
	int height;
	int xx;  // The bottom-left corner
	int yy;
	int zz;
	int pid;
	bool visible;
	int show_time;
	time_t prev_time;
// public:
	Platform();
	Platform(int x, int y, int z, int l, int h, int id, bool vis = true, time_t t = 0);
	void drawPlatform();
	void platformCollision();
};
