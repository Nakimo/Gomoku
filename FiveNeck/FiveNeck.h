#pragma once

class Game {
public:
	Game() {}
	~Game() {}

	void init() {// Game �ʱ�ȭ
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) Map[i][j] = 0;
		}
		Load_cnt = 0;
		Turn = 1;
	}

	int Chk_Win();


public:
	int Map[19][19]; // ��� 0 �� 1 �� -1
	int LOAD[362][2], Load_cnt; // ���
	int Turn; // ��(��or��)
};