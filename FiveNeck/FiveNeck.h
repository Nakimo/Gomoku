#pragma once

class Game {
public:
	Game() {}
	~Game() {}

	void init() {// Game √ ±‚»≠
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) Map[i][j] = 0;
		}
		Load_cnt = 0;
		Turn = 1;
	}

	int Chk_Win();


public:
	int Map[19][19]; // ∫Û∞˜ 0 »Ê 1 πÈ -1
	int LOAD[362][2], Load_cnt; // ±‚∑œ
	int Turn; // ≈œ(»ÊorπÈ)
};