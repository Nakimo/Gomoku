#include "FiveNeck.h"


int Game::Chk_Win() {
	int color,cnt;
	int lastest_x, lastest_y;
	int x, y;

	lastest_x = this->LOAD[this->Load_cnt - 1][0];
	lastest_y = this->LOAD[this->Load_cnt - 1][1];
	color = this->Map[lastest_x][lastest_y];

	// ㅡ 직선 체크

	cnt = 1;
	x = lastest_x;
	y = lastest_y;
	while (1) {
		if (Map[x - 1][y] == color) {
			x--;
			cnt++;
		}
		else break;
	}
	x = lastest_x;
	y = lastest_y;
	while (1) {
		if (Map[x + 1][y] == color) {
			x++;
			cnt++;
		}
		else break;
	}
	if (cnt >= 5) return 1;

	// \ 대각선 체크

	cnt = 1;
	x = lastest_x;
	y = lastest_y;
	while (1) {
		if (Map[x - 1][y - 1] == color) {
			x--;
			y--;
			cnt++;
		}
		else break;
	}
	x = lastest_x;
	y = lastest_y;
	while (1) {
		if (Map[x + 1][y + 1] == color) {
			x++;
			y++;
			cnt++;
		}
		else break;
	}
	if (cnt >= 5) return 1;

	// | 직선 체크
	
	cnt = 1;
	x = lastest_x;
	y = lastest_y;
	while (1) {
		if (Map[x][y - 1] == color) {
			y--;
			cnt++;
		}
		else break;
	}
	x = lastest_x;
	y = lastest_y;
	while (1) {
		if (Map[x][y + 1] == color) {
			y++;
			cnt++;
		}
		else break;
	}
	if (cnt >= 5) return 1;

	// / 대각선 체크

	cnt = 1;
	x = lastest_x;
	y = lastest_y;
	while (1) {
		if (Map[x + 1][y - 1] == color) {
			x++;
			y--;
			cnt++;
		}
		else break;
	}
	x = lastest_x;
	y = lastest_y;
	while (1) {
		if (Map[x - 1][y + 1] == color) {
			x--;
			y++;
			cnt++;
		}
		else break;
	}
	if (cnt >= 5) return 1;

	return 0;
}