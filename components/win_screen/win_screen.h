#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class WinScreen {
    private:
        int height;
        int width;
        string text;
    public:
        WinScreen();
        void drawScreen();
};
