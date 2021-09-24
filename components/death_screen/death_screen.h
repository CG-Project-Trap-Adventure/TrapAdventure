#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class DeathScreen {
    private:
        int height;
        int width;
        string text;
    public:
        DeathScreen();
        void drawScreen();
};
