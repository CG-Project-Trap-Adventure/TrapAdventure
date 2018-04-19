#include "level1.h"
#include "../draw/draw.h"
#include "../platform/platform.h"
#include "../spike/spike.h"

const int nSpike = 10;
const int nPlatform = 1;
static Platform platform[nPlatform];
static Spike spike[nSpike];

void setLevel() {
  for(int i = 0; i < nSpike; i++) {
    spike[i] = Spike(i*200+30, 200, -1.0);
  }
  for(int i = 0; i < nPlatform; i++) {
    platform[i] = Platform(0.0, 0.0, 0.0, 10000.0, 200.0);
  }
}

void drawLevel() {
    //Platform platform = Platform(0.0, 0.0, 0.0, 10000.0, 200.0);
    glColor3f(0.545, 0.271, 0.075);     //SaddleBrown
    // draw.drawBox(0.0, 0.0, 0.0, 10000.0, 200.0);
    for(int i = 0; i < nPlatform; i++) {
      platform[i].drawPlatform();
    }
    glColor3f(0.863, 0.863, 0.863);     //Gainsboro
    for (int i = 0; i < nSpike; i++)
    {
        spike[i].drawSpike();
    }
    // cout<<"Drawing the level"<<endl;
}

void level1CollisionDetection() {
  // Collision detection for all the assets (platform and spike) is called here
  // This function is called by the glutIdleFunc()
  // Because it is called by glutIdleFunc there might be some delay in actual collision and its detection

  for(int i = 0; i < nSpike; i++) {
    spike[i].spikeCollision();
  }
  for(int i = 0; i < nPlatform; i++) {
    platform[i].platformCollision();
  }

}
