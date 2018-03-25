#include <GL/glut.h>
#include <iostream>

using namespace std;

class InstScreen {
    private:
        int height;
        int width;
        string inst1;
        string inst2;
        string inst3;
        string inst4;
		string inst5;
    public:
        InstScreen();
        void drawScreen();
};
