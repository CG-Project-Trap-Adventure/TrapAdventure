#include <GL/glut.h>

#include <map>
using namespace std;

size_t win_w = 0;
size_t win_h = 0;

void Box( int xoff, int yoff, int size = 10 )
{
    glBegin(GL_QUADS);
        glVertex2f( xoff + -1*size, yoff + -1*size);
        glVertex2f( xoff +  1*size, yoff + -1*size);
        glVertex2f( xoff +  1*size, yoff +  1*size);
        glVertex2f( xoff + -1*size, yoff +  1*size);
    glEnd();
}

map< int, bool > key_map;

void keyboard( int key, int x, int y )
{
    key_map[key] = true;
}

void keyboard_up( int key, int x, int y )
{
    key_map[key] = false;
}


void display(void)
{
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    static int center_x = 0;
    static int center_y = 0;
    if( key_map[GLUT_KEY_LEFT]  ) center_x--;
    if( key_map[GLUT_KEY_RIGHT] ) center_x++;
    if( key_map[GLUT_KEY_DOWN]  ) center_y--;
    if( key_map[GLUT_KEY_UP]    ) center_y++;

    double left   = center_x - win_w/2.0;
    double right  = center_x + win_w/2.0;
    double bottom = center_y - win_h/2.0;
    double top    = center_y + win_h/2.0;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(left, right, bottom, top, -10, 10);

    glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();

    glColor3ub(255,0,0);
    Box( 10, 10 );

    glColor3ub(0,255,0);
    Box( 100, 100 );

    glColor3ub(0,0,255);
    Box(150, 150);

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    win_w = w;
    win_h = h;
    glViewport(0, 0, w, h);
}

void idle()
{
    glutPostRedisplay();
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(200,200);
    glutCreateWindow("Scroll");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc( keyboard );
    glutSpecialUpFunc( keyboard_up );

    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
