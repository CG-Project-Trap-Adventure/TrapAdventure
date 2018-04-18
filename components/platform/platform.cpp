#include "platform.h"
#include "../draw/draw.h"
#include "../../states.h"

Platform::Platform(int xx, int yy, int zz, int l, int h) {
  length = l;
  height = h;
  x = xx;
  y = yy;
  z = zz;
}

void Platform::drawPlatform() {
  Draw draw = Draw();

  glPushMatrix();
    draw.drawBox(x, y, z, length, height);
  glPopMatrix();
}

void Platform::platformCollision(){
  // Collision detection logic
}
