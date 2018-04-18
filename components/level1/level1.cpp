#include "level1.h"
#include "../draw/draw.h"
#include "../platform/platform.h"
#include "../spike/spike.h"

void drawLevel() {
    Draw draw = Draw();
    // Spike spike = Spike();
    Platform platform = Platform(0.0, 0.0, 0.0, 10000.0, 200.0);
    glColor3f(0.545, 0.271, 0.075);     //SaddleBrown
    // draw.drawBox(0.0, 0.0, 0.0, 10000.0, 200.0);
    platform.drawPlatform();
    glColor3f(0.863, 0.863, 0.863);     //Gainsboro
    for (int i = 30; i < 10000; i+=100)
    {
        // spike.drawSpike(i, 200, -1.0);
    }
    // cout<<"Drawing the level"<<endl;
}
