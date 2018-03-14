#include "game_screen.h"
#include "../draw/draw.h"

GameScreen::GameScreen() {
	width = 1366;
	height = 768;
	score = "SCORE : ";
}

void GameScreen::drawScreen() {
	Draw draw = Draw();
	glColor3f(0.0, 1.0, 1.0);
	draw.drawBox(0.0, 0.0, -2.0, width, height);
	glColor3f(0.5, 0.2, 0.0);
	draw.drawBox(0.0, 0.0, -1.9, width, 250);
}
