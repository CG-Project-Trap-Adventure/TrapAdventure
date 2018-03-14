#include <GL/glut.h>
#include <iostream>

using namespace std;

class GameScreen {
	private:
		int height;
		int width;
		string score;
	public:
		GameScreen();
		void drawScreen();
};
