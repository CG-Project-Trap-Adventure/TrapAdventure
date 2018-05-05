#include <GL/glut.h>
#include <iostream>

using namespace std;

class Platform {
private:
	int length;
	int height;
	int xx;  // The bottom-left corner
	int yy;
	int zz;
public:
	Platform();
	Platform(int x, int y, int z, int l, int h);
	void drawPlatform();
	void platformCollision();
};
