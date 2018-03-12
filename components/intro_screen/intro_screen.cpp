#include "intro_screen.h"
#include "../draw/draw.h"

IntroScreen::IntroScreen() {
    height = 768;
    width = 1366;
    title = "Trap Adventure";
    devansh = "Devansh Sharma (1PE15CS048)";
    divyaksh = "Divyaksh Shukla (1PE15CS051)";
}

void IntroScreen::drawScreen() {
    // glPushMatrix();
    // glTranslatef(330, height/2+100,0.0);
    // glScalef(0.75,0.75,0.0);
    // glLineWidth(3.0);
    // for (int i = 0; i < title.length(); i++) {
    //     glutStrokeCharacter(GLUT_STROKE_ROMAN, title[i]);
    // }
    
    // glPopMatrix();
    Draw draw = Draw();
    draw.drawString(330, 484, 0, 0.75, 0.75, 0.0, 3.0, title);
    draw.drawString(1000, 100, 0, 0.15, 0.15, 0.0, 1.5, devansh);
    draw.drawString(1000, 75, 0, 0.15, 0.15, 0.0, 1.5, divyaksh);
}