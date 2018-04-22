#include "death_screen.h"
#include "../draw/draw.h"

DeathScreen::DeathScreen() {
    height = 768;
    width = 1366;
	text = "You Died";
}

void DeathScreen::drawScreen() {
    // glPushMatrix();
    // glTranslatef(330, height/2+100,0.0);
    // glScalef(0.75,0.75,0.0);
    // glLineWidth(3.0);
    // for (int i = 0; i < title.length(); i++) {
    //     glutStrokeCharacter(GLUT_STROKE_ROMAN, title[i]);
    // }

    // glPopMatrix();
    Draw draw = Draw();
    glColor3f(0, 0, 0);     //Black
    draw.drawBox(0, 0, -2.0, 1366.0, 768.0);
    glColor3f(0.545, 0.000, 0.000);		//DarkRed
    draw.drawString(500, 350, 0, 0.75, 0.75, 0.0, 6.0, text);
}
