#include "level1.h"
#include "../draw/draw.h"
#include "../spike/spike.h"

void drawLevel() {
    Draw draw = Draw();
    Spike spike = Spike();
    glColor3f(0.545, 0.271, 0.075);     //SaddleBrown
    draw.drawBox(0.0, 0.0, 0.0, 3000.0, 200.0);
    glColor3f(0.412, 0.412, 0.412);     //DimGray
    for (int i = 30; i < 3000; i+=60)
    {
        spike.drawSpike(i, 200);
    }
    // cout<<"Drawing the level"<<endl;
}