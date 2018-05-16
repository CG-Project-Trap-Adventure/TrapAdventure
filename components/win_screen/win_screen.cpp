#include "win_screen.h"
#include "../draw/draw.h"
#include "../../states.h"

WinScreen::WinScreen() {
    height = win_h;
    width = win_w;
	text = "You Died";
}

void WinScreen::drawScreen() {
    // glPushMatrix();
    // glTranslatef(330, height/2+100,0.0);
    // glScalef(0.75,0.75,0.0);
    // glLineWidth(3.0);
    // for (int i = 0; i < title.length(); i++) {
    //     glutStrokeCharacter(GLUT_STROKE_ROMAN, title[i]);
    // }

    // glPopMatrix();
    Draw draw = Draw();
    glColor3f(0, 0.678, 0);     //DarkGreen
    draw.drawBox(0, 0, -2.0, width+10, height);
    glColor3f(0.0, 0.000, 0.000);		//Black
    draw.drawString(500, 350, 0, 0.75, 0.75, 0.0, 6.0, "YOU WON");
    glColor3f(1.0, 1.0, 1.0);       //White
    draw.drawString(500, 200, 0, 0.3, 0.3, 0.0, 1.0, "press \'r\' to replay");
}
