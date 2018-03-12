#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class IntroScreen {
    private:
        int height;
        int width;
        string title;
        string devansh;
        string divyaksh;
    public:
        IntroScreen();
        void drawScreen();
};