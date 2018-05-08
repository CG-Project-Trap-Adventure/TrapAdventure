#include "platform.h"
#include "../draw/draw.h"
#include "../../states.h"

Platform::Platform() {
}

Platform::Platform(int x, int y, int z, int l, int h, int id) {
	length = l;
	height = h;
	xx = x;
	yy = y;
	zz = z;
	pid = id;
}

/*
Shape of you(r platform)
				II
(xx, yy+h)					 (xx+w, yy+h)
	*****************************
I	*****************************	III
	*****************************
(xx, yy)					 (xx+w, yy)

				IV
*/

void Platform::drawPlatform() {
	Draw draw = Draw();

	glPushMatrix();
	draw.drawBox(xx, yy, zz, length, height);
	glPopMatrix();
}

void Platform::platformCollision(){
	float x1, y1, x2, y2;	// Points for platform edge
	int flag;
	// max_y = min_y + 125;	// We're resetting the value so that R2D3 can jump to original height once it is not in sector 4

	if(r2d3_y - 20 <= 0.0) {
		screen = _death_screen;
	}
	// Same conditions as below... But doesnt work...
	// FYR : 38.7415
	if(r2d3_x + 24 == xx && r2d3_y + 40 >= yy && r2d3_y - 20 <= yy + height) {
		// cout << "Right blocked\n";
		block_r = true;
		// safe =true;
	}
	if(r2d3_x - 24 == xx + length && r2d3_y - 20 <= yy + height && r2d3_y + 40 >= yy) {
		block_l = true;
	}

	// Sector 2
	if(r2d3_y - 20 >= yy + height && r2d3_x + 24 >= xx && r2d3_x - 24 <= xx + length) {
		// if(r2d3_x)
		// if(up_key == false) {
		// 	safe = false;
		// }
		// if(pid == 6 && safe == true) {
		// 	return;
		// }
		// if(pid != 6 && safe == false) {
		// 	safe = true;
		// }
		//
		// min_y = yy + height;
		// x1 = xx;
		// y1 = yy + ;
		// x2 = xx + w;
		// y2 = yy + h;
		// cout << "Sector 2\n";
		min_y = (min_y < (yy + height)) ? (yy + height) : min_y;
		max_y = min_y + 124;
		// min_y = yy + height;
		// safe = true;
		// ppid = pid;
		// cout << "Sector 2 " << min_y << "," << max_y << "\t" << r2d3_x << "," << r2d3_y << "\t" << pid << "\n";
	}
	// Sector 4
	else if(r2d3_y + 40 < yy && r2d3_x + 24 > xx && r2d3_x - 24 <= xx + length) {
		// x1 = xx;
		// y1 = yy;
		// x2 = xx + length;
		// y2 = yy;
		// cout << "Sector 4\n";
		max_y = (max_y >= yy - 40) ? yy - 40 : min_y + 124;
		// if(pid == 2) {
		// 	cout<<"Sector 4 "<<max_y<< "\t" << r2d3_x << "," << r2d3_y << endl;
		// }
		// cout << "Sector 4 " << min_y << "," << max_y << "\t" << r2d3_x << "," << r2d3_y << "\t" << pid << "\n";
	}
	// Sector 1
	// else if(r2d3_x + 25 < xx && r2d3_y + 38.7415 >= yy && r2d3_y - 21 <= yy + height) {
		// x1 = xx;
		// y1 = yy;
		// x2 = xx;
		// y2 = yy + height;
		// if(pid == 1) {
		// 	cout << "Sector 1 " << r2d3_x << "\t" << r2d3_y << "\t" << xx << "\t" << yy << "\n";
		// }
		// if(r2d3_x + 25 == xx) {
		// 	block_r = true;
		// }
		// cout << "Sector 1 " << safe << "\t" << r2d3_x << "\n";
		// if(safe == false) {
			// min_y = 0;
		// }
		// cout << "Sector 1 " << min_y << "," << max_y << "\t" << r2d3_x << "," << r2d3_y << "\t" << pid << "\n";
		// printf("SECTOR 1 %f,%f\n", r2d3_x, r2d3_y);
	// }

	//Sector 3
	// else if(r2d3_x - 25 > xx + length && r2d3_y - 21 <= yy + height && r2d3_y + 38.7415 >= yy) {
		// x1 = xx + length;
		// y1 = yy;
		// x2 = xx + length;
		// y2 = yy + height;
		// cout << "Sector 3\n";
		// if(r2d3_x - 25 == xx + length) {
		// 	block_l = true;
		// }
		// if(safe == false) {
			// min_y = 0;
		// }
		// cout << "Sector 3 " << min_y << "," << max_y << "\t" << r2d3_x << "," << r2d3_y << "\t" << pid << "\n";
	// }
	// else {
	// 	// printf("Mai hoon else!!! %d\n", min_y);
	// 	// min_y = 0;
	// 	safe = false;
	// }
}
