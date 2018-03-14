#include "components/trapadv.h"

using namespace std;

IntroScreen introScreen = IntroScreen();
InstScreen instScreen = InstScreen();
GameScreen gameScreen = GameScreen();

enum ScreenStates {
	_intro_screen = 0,
	_inst_screen,
	_game_screen
};

ScreenStates screen = _intro_screen;

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	switch(screen) {
		case _intro_screen:
		introScreen.drawScreen();
		break;
		case _inst_screen:
		instScreen.drawScreen();
		break;
		case _game_screen:
		gameScreen.drawScreen();
		break;
	}
	glFlush();
}

void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glOrtho(0.0, 1366.0, 0.0, 768.0, -10.0 , 10.0);
}

void mouse(int btn, int state, int xx, int yy) {
	switch(screen) {
		case _intro_screen:
		switch(btn) {
			case GLUT_LEFT_BUTTON:
			if(xx >= 300 && xx <= 500 && yy >= 658 && yy <= 693 && state == GLUT_DOWN) {
				screen = _inst_screen;
			}
			else {
				cout << "Outside button\n";
			}
			break;
		}
		break;
		case _inst_screen:
		switch(btn) {
			case GLUT_LEFT_BUTTON:
			if(xx >= 300 && xx <= 500 && yy >= 658 && yy <= 693 && state == GLUT_DOWN) {
				screen = _game_screen;
			}
			else {
				cout << "Outside button\n";
			}
			break;
		}
		break;
	}
	display();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Trap Adventure");
	glutFullScreen();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	myinit();
	glutMainLoop();
}
