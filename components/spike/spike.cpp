#include "spike.h"
#include "../../states.h"
#include <iostream>
#include <math.h>
using namespace std;

Spike::Spike() {
	length = 20;    //Keep this as a multiple of 2
	height = 20;
	color[0] = 1.0;
	color[1] = 0.0;
	color[2] = 0.0;
}

Spike::Spike(int x, int y, int z, int l, int h){
	xx = x;
	yy = y;
	zz = z;
	length = l;
	height = h;
}

Spike::Spike(int x, int y, int z, int id){
	xx = x;
	yy = y;
	zz = z;
	sid = id;
	length = 20;
	height = 40;
}

/*
Shape of you(r spike)
    (x+(length/2), y+height)
                *
               ***
              *****
             *******
            *********
           ***********
          *************
  (x, y) ***************  (x+length, y)
*/

void Spike::drawSpike() {
	// glColor3fv(color);
	GLfloat vertices[3][3];
	vertices[0][0] = (GLfloat)(xx);
	vertices[0][1] = (GLfloat)(yy);
	vertices[0][2] = zz;
	vertices[1][0] = (GLfloat)(xx+length);
	vertices[1][1] = (GLfloat)(yy);
	vertices[1][2] = zz;
	vertices[2][0] = (GLfloat)(xx+length/2);
	vertices[2][1] = (GLfloat)(yy+height);
	vertices[2][2] = zz;
	glBegin(GL_TRIANGLES);
	glVertex3fv(vertices[0]);
	glVertex3fv(vertices[1]);
	glVertex3fv(vertices[2]);
	glEnd();
}

void Spike::spikeCollision() {
	// cout << "Check for " << sid << "\n";
	// cout << level1_loaded << "\n";
	int h = 40;
	// float r2d3_x = win_x + 1366.0 / 2.0, r2d3_y = win_y;

	// cout << "Spike " << r2d3_x << "," << r2d3_y << "\n";
	// cout << xx << "," << yy << "\n";
	// if(r2d3_x + 40 < xx || xx + length < r2d3_x - 25) {
	// 	flag = 0;
	// }
	// if(r2d3_y - 25 > yy + height || r2d3_y + 25 + 20 < yy) {
	// 	flag = 0;
	// }
	// if(flag) {
	// 	// cout << "Collision at " << sid << "\n";
	// 	screen = _death_screen;
	// }
	float x1, y1, x2, y2;	// Points of spike edge
	if(r2d3_x + 25 <= xx + (20 / 2)) {
		x1 = xx;
	} else {
		x1 = xx + 20;
	}
	y1 = yy;
	x2 = xx + (20 / 2);
	y2 = yy + h;

	if(yy + h > r2d3_y - 21) {
		float a, b, c, m, k;
		m = (x2 - x1) / (y2 - y1);
		k = r2d3_x - x1;
		a = m * m + 1;
		b = -(2 * r2d3_y + 2 * k * m + 2 * m * m * y1);
		c = m * m * y1 * y1 + k * k + 2 * k * m * y1 + r2d3_y * r2d3_y - 625;

		// Delta = b^2 - 4ac
		// Delta < 0 ==> No collision

		float delta = b * b - 4 * a * c;
		// cout << delta << "\n";
		if(delta >= 0) {
			float root1, root2;
			root1 = (-b + sqrt(delta)) / (2 * a);
			root2 = (-b - sqrt(delta)) / (2 * a);
			if((root1 <= yy + h && root1 >= yy) || (root2 <= yy + h && root2 >= yy)) {
				screen = _death_screen;
				// for(auto i = 0; i < 999999999; i++);
			}
		}
	}
}
