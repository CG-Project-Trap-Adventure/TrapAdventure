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
    glColor3f(1.000, 0.871, 0.678);     //NavajoWhite
    draw.drawBox(0, 0, -2.0, 1366.0, 768.0);
    glColor3f(1.0, 0.0, 0.0);
    draw.drawString(330, 484, 0, 0.75, 0.75, 0.0, 6.0, title);
    // glColor3f(0.722, 0.525, 0.043);     //DarkGoldenRod
    // draw.drawBox(320, 474, -1.0, 1000.0,100.0);
    glColor3f(0.5, 0.0, 1.0);
    draw.drawString(1000, 100, 0, 0.15, 0.15, 0.0, 1.5, devansh);
    draw.drawString(1000, 75, 0, 0.15, 0.15, 0.0, 1.5, divyaksh);
	glColor3f(0.118, 0.565, 1.000);		//DodgerBlue
	draw.drawBox(300, 75, 0, 200, 35);
	glColor3f(1.0, 1.0, 1.0);
	draw.drawString(310, 82, 2, 0.2, 0.2, 0.0, 1.5, "Instructions >>");
    // printf("Drawing the intro screen...\n");
}
