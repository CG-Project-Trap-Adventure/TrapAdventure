#include "score.h"
#include "../draw/draw.h"
#include "../../states.h"

using namespace std;

void Score::drawScore() {
    Draw draw = Draw();
    glColor3f(0.0, 0.0, 0.0);
    draw.drawString((win_x + win_w - 200), (win_h - 40), 0.0, 0.3, 0.3, 0.0, 1.0,"Score:" + to_string(score));
}