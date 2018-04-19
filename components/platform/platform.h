#include <GL/glut.h>
#include <iostream>

using namespace std;

class Platform {
private:
  int length;
  int height;
  int x;  // The bottom-left corner
  int y;
  int z;
public:
  Platform();
  Platform(int xx, int yy, int zz, int l, int h);
  void drawPlatform();
  void platformCollision();
};
