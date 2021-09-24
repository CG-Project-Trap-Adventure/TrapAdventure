#include <GL/glut.h>
#include <iostream>

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
	const int RIGHT = 2, LEFT = 1, TOP = 8, BOTTOM = 4;
// public:
	Platform();
	Platform(int x, int y, int z, int l, int h, int id);
	void drawPlatform();
	void platformCollision();
};
