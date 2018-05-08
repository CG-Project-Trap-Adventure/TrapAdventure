#include "level1.h"
#include "../draw/draw.h"
#include "../platform/platform.h"
#include "../spike/spike.h"
#include "../../states.h"

const int nSpike = 100;
const int nPlatform = 6;
static Platform platform[nPlatform];
static Spike spike[nSpike];

unordered_map <int, vector <int>> spike_pos;

void setLevel() {
	for(int i = 0; i < nSpike; i++) {
		int sx = i * 40 * 5;
		spike[i] = Spike(sx, 200, -1.0, i);
		spike_pos[sx / 1000].push_back(i);
	}
	// for(int i = 0; i < nPlatform; i++) {
	// int start_x, end_x;
	// for(int j = start_x / 1000; j < end_x / 1000; i++) {
	// 	plat_pos[j].push_back(i);
	// }
	platform[0] = Platform(0.0, 150.0, 0.0, 1000.0, 50.0, 0);	// Main Platform
	platform[4] = Platform(1200.0, 150.0, 0.0, 350.0, 50.0, 4);
	platform[3] = Platform(1400.0, 252.0, 0.0, 100.0, 8.0, 3);
	platform[2] = Platform(1800.0, 280.0, 0.0, 50.0, 8.0, 2);		// Till the time I didn't put this it was working
	platform[1] = Platform(1550.0, 320.0, 0.0, 100.0, 8.0, 1);
	platform[5] = Platform(2100.0, 150.0, 0.0, 1000.0, 50.0, 5);
	// platform[6] = Platform(0.0, -1.0, 0.0, 10000.0, 3.0, 6);
	// platform[3] = Platform(0.0, 1400.0, 0.0, 10000.0, 50.0, 3);

	// }
}

void drawLevel() {
	//Platform platform = Platform(0.0, 0.0, 0.0, 10000.0, 200.0);
	glColor3f(0.545, 0.271, 0.075);     //SaddleBrown
	// draw.drawBox(0.0, 0.0, 0.0, 10000.0, 200.0);
	for(int i = 0; i < nPlatform; i++) {
		// if(insane == true)
		// {
		// 	if(i == 2){;}
		// 	else
		// 		platform[i].drawPlatform();
		// }
		// else{
			platform[i].drawPlatform();
		// }
	}
	glColor3f(0.663, 0.663, 0.663);     //DarkGray
	for(int i = 0; i < nSpike; i++) {
		// spike[i].drawSpike();
	}
	// cout<<"Drawing the level"<<endl;
}

void level1CollisionDetection() {
	// Collision detection for all the assets (platform and spike) is called here
	// This function is called by the glutIdleFunc()
	// Because it is called by glutIdleFunc there might be some delay in actual collision and its detection

	// for(int i = 0; i < nSpike; i++) {
	// 	spike[i].spikeCollision();
	// }
	// cout << "Level 1 " << r2d3_x << ", " << r2d3_y << "\n";
	// spike[0].spikeCollision();

	int r2d3_pos = r2d3_x / 1000;
	// cout << r2d3_x << "\t" << r2d3_pos << "\t";
	for(auto vit : spike_pos[r2d3_pos]) {
		// cout << vit << " ";
		// spike[vit].spikeCollision();
	}
	// cout << "\n";
	// platform[ppid].platformCollision();
	for(int i = 0; i < nPlatform; i++) {
		// if(i == ppid) {
			// continue;
		// }
		// cout << "Platform " << i << "\n";
		cout << r2d3_x << "\t" << platform[i].xx << ", " << platform[i].xx + platform[i].length << "\t" << right_dir << "\n";
		// if(right_dir == true && r2d3_x + 207 == platform[i].xx) {
		//
		// }
		// if((right_dir == true && r2d3_x >= platform[i].xx && r2d3_x - 207 ) || (right_dir == false && r2d3_x - 207 <= platform[i].xx + platform[i].length)) {
		// float range;
		// if(right_dir == true) {
		// 	range = r2d3_x + 207;
		// } else{
		// 	range = r2d3_x - 207;
		// }
		float pxx, pxxl;
		pxx = platform[i].xx;
		pxxl = platform[i].xx + platform[i].length;
		if(right_dir == true) {
			// if((r2d3_x + 25 >= pxx - 207 && r2d3_x - 25 <= pxxl + 207) ) {
			if((r2d3_x + 25 == platform[i].xx) || (r2d3_x + 25 >= platform[i].xx && r2d3_x - 25 <= platform[i].xx + platform[i].length)) {
				platform[i].platformCollision();
				cout << i << "\n";
			}
		} else {
			if((r2d3_x + 25 >= pxx - 207 && r2d3_x - 25 <= pxxl + 207)) {
				platform[i].platformCollision();
				cout << i << "\n";
			}
		}
		// platform[i].platformCollision();
		// cout << i << "\n";
	}
}
