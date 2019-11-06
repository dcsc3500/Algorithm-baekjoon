#include <iostream>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

struct POS {
	int rX;
	int rY;
	int bX;
	int bY;
};

int min = 9999;
int N, M;
int map[10][10];
int hole[2]; // 0에는 y좌표 1에는 x좌표
int holeIn[2];  // 0에는 R가 홀인시 1 1에는 B가 홀인시 1
POS nowPos;// 0에는 R좌표(y,x) 1에는 B좌표 2에는 홀좌표
vector<POS> lastPos; // 0에는 전꺼 1에는 전전꺼

void moving(int dir) {
	holeIn[0] = 0;
	holeIn[1] = 0;

	if (dir == 0) {  // 오른쪽으로 
		if (nowPos.rX < nowPos.bX) {
			map[nowPos.bY][nowPos.bX] = 0;
			while (map[nowPos.bY][nowPos.bX] != -1) {
				nowPos.bX++;
				if (nowPos.bY == hole[0] && nowPos.bX == hole[1])
					holeIn[1] = 1;
			}
			nowPos.bX--;
			map[nowPos.bY][nowPos.bX] = 2;

			map[nowPos.rY][nowPos.rX] = 0;
			while (map[nowPos.rY][nowPos.rX] != -1 && map[nowPos.rY][nowPos.rX] != 2) {
				nowPos.rX++;
				if (nowPos.rY == hole[0] && nowPos.rX == hole[1])
					holeIn[0] = 1;
			}
			nowPos.rX--;
			map[nowPos.rY][nowPos.rX] = 1;
		}
		else {
			map[nowPos.rY][nowPos.rX] = 0;
			while (map[nowPos.rY][nowPos.rX] != -1) {
				nowPos.rX++;
				if (nowPos.rY == hole[0] && nowPos.rX == hole[1])
					holeIn[0] = 1;
			}
			nowPos.rX--;
			map[nowPos.rY][nowPos.rX] = 1;

			map[nowPos.bY][nowPos.bX] = 0;
			while (map[nowPos.bY][nowPos.bX] != -1 && map[nowPos.bY][nowPos.bX] != 1) {		
				nowPos.bX++;
				if (nowPos.bY == hole[0] && nowPos.bX == hole[0])
					holeIn[1] = 1;
			}
			nowPos.bX--;
			map[nowPos.bY][nowPos.bX] = 2;
		}
	}


	else if (dir == 1) {  // 아랫쪽으로 
		if (nowPos.rY < nowPos.bY) {
			map[nowPos.bY][nowPos.bX] = 0;
			while (map[nowPos.bY][nowPos.bX] != -1) {
				nowPos.bY++;
				if (nowPos.bY == hole[0] && nowPos.bX == hole[1])
					holeIn[1] = 1;
			}
			nowPos.bY--;
			map[nowPos.bY][nowPos.bX] = 2;

			map[nowPos.rY][nowPos.rX] = 0;
			while (map[nowPos.rY][nowPos.rX] != -1 && map[nowPos.rY][nowPos.rX] != 2) {
				nowPos.rY++;
				if (nowPos.rY == hole[0] && nowPos.rX == hole[1])
					holeIn[0] = 1;
			}
			nowPos.rY--;
			map[nowPos.rY][nowPos.rX] = 1;
		}
		else {
			map[nowPos.rY][nowPos.rX] = 0;
			while (map[nowPos.rY][nowPos.rX] != -1) {
				nowPos.rY++;
				if (nowPos.rY == hole[0] && nowPos.rX == hole[1])
					holeIn[0] = 1;
			}
			nowPos.rY--;
			map[nowPos.rY][nowPos.rX] = 1;

			map[nowPos.bY][nowPos.bX] = 0;
			while (map[nowPos.bY][nowPos.bX] != -1 && map[nowPos.bY][nowPos.bX] != 1) {
				nowPos.bY++;
				if (nowPos.bY == hole[0] && nowPos.bX == hole[0])
					holeIn[1] = 1;
			}
			nowPos.bY--;
			map[nowPos.bY][nowPos.bX] = 2;
		}
	}


	else if (dir == 2) {  // 왼쪽으로 
		if (nowPos.rX > nowPos.bX) {
			map[nowPos.bY][nowPos.bX] = 0;
			while (map[nowPos.bY][nowPos.bX] != -1) {
				nowPos.bX--;
				if (nowPos.bY == hole[0] && nowPos.bX == hole[1])
					holeIn[1] = 1;
			}
			nowPos.bX++;
			map[nowPos.bY][nowPos.bX] = 2;

			map[nowPos.rY][nowPos.rX] = 0;
			while (map[nowPos.rY][nowPos.rX] != -1 && map[nowPos.rY][nowPos.rX] != 2) {
				nowPos.rX--;
				if (nowPos.rY == hole[0] && nowPos.rX == hole[1])
					holeIn[0] = 1;
			}
			nowPos.rX++;
			map[nowPos.rY][nowPos.rX] = 1;
		}
		else {
			map[nowPos.rY][nowPos.rX] = 0;
			while (map[nowPos.rY][nowPos.rX] != -1) {
				nowPos.rX--;
				if (nowPos.rY == hole[0] && nowPos.rX == hole[1])
					holeIn[0] = 1;
			}
			nowPos.rX++;
			map[nowPos.rY][nowPos.rX] = 1;

			map[nowPos.bY][nowPos.bX] = 0;
			while (map[nowPos.bY][nowPos.bX] != -1 && map[nowPos.bY][nowPos.bX] != 1) {
				nowPos.bX--;
				if (nowPos.bY == hole[0] && nowPos.bX == hole[0])
					holeIn[1] = 1;
			}
			nowPos.bX++;
			map[nowPos.bY][nowPos.bX] = 2;
		}
	}



	else if (dir == 3) {  //윗쪽
		if (nowPos.rY > nowPos.bY) {
			map[nowPos.bY][nowPos.bX] = 0;
			while (map[nowPos.bY][nowPos.bX] != -1) {
				nowPos.bY--;
				if (nowPos.bY == hole[0] && nowPos.bX == hole[1])
					holeIn[1] = 1;
			}
			nowPos.bY++;
			map[nowPos.bY][nowPos.bX] = 2;

			map[nowPos.rY][nowPos.rX] = 0;
			while (map[nowPos.rY][nowPos.rX] != -1 && map[nowPos.rY][nowPos.rX] != 2) {
				nowPos.rY--;
				if (nowPos.rY == hole[0] && nowPos.rX == hole[1])
					holeIn[0] = 1;
			}
			nowPos.rY++;
			map[nowPos.rY][nowPos.rX] = 1;
		}
		else {
			map[nowPos.rY][nowPos.rX] = 0;
			while (map[nowPos.rY][nowPos.rX] != -1) {
				nowPos.rY--;
				if (nowPos.rY == hole[0] && nowPos.rX == hole[1])
					holeIn[0] = 1;
			}
			nowPos.rY++;
			map[nowPos.rY][nowPos.rX] = 1;

			map[nowPos.bY][nowPos.bX] = 0;
			while (map[nowPos.bY][nowPos.bX] != -1 && map[nowPos.bY][nowPos.bX] != 1) {
				nowPos.bY--;
				if (nowPos.bY == hole[0] && nowPos.bX == hole[0])
					holeIn[1] = 1;
			}
			nowPos.bY++;
			map[nowPos.bY][nowPos.bX] = 2;
		}
	}


}


void print() {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			printf("%2d", map[i][j]);
		}
		cout << endl;
	}
}


void dfs(int cnt, vector<POS> yx) {
	int i, j;
	if (cnt > min)
		return;
	if (cnt > 10)
		return;
	if (yx[0].rX == nowPos.rX && yx[0].rY == nowPos.rY && yx[0].rY == nowPos.rY && yx[0].rX == nowPos.rX)//그전과 구슬 좌표가같다면
		return;
	if (yx[1].rX == nowPos.rX && yx[1].rY == nowPos.rY && yx[1].rY == nowPos.rY && yx[1].rX == nowPos.rX) // 그전전과 구슬좌표가 같다면
		return;
	if (min > cnt && (holeIn[0] == 1 && holeIn[1] != 1)) {
		min = cnt;
		return;
	}

	for (i = 0; i < 4; i++) {
		POS temp; // 전전좌표 저장해놓고 백트레킹시 다시 써야됨
		temp.rX = yx[1].rX;
		temp.rY = yx[1].rY;
		temp.bX = yx[1].bX;
		temp.bY = yx[1].bY;
		yx[1].rX = yx[0].rX;
		yx[1].rY = yx[0].rY;
		yx[1].bX = yx[0].bX;
		yx[1].bY = yx[0].bY;
		yx[0].rX = nowPos.rX;
		yx[0].rY = nowPos.rY;
		yx[0].bX = nowPos.bX;
		yx[0].bY = nowPos.bY;
		moving(i);
		cout << i << endl;
		print();
		dfs(cnt + 1,yx);
		yx[0].rX = yx[1].rX;
		yx[0].rY = yx[1].rY;
		yx[0].bX = yx[1].bX;
		yx[0].bY = yx[1].bY;
		yx[1].rX = temp.rX;
		yx[1].rY = temp.rY;
		yx[1].bX = temp.bX;
		yx[1].bY = temp.bY;
		moving(((i + 2) % 4));
	}
}



int main() {
	int i, j;

	
	scanf_s("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (j = 0; j < M; j++) {
			map[i][j] == temp[j];
			if (temp[j] == '#')
				map[i][j] = -1;
			else if (temp[j] == '.')
				map[i][j] = 0;
			else if (temp[j] == 'R') {
				map[i][j] = 1;
				nowPos.rX = j;
				nowPos.rY = i;
			}
			else if (temp[j] == 'B') {
				map[i][j] = 2;
				nowPos.bX = j;
				nowPos.bY = i;
			}
			else if (temp[j] == 'O') {
				map[i][j] = 3;
				hole[0] = i;
				hole[1] = j;
			}
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			printf("%2d", map[i][j]);
		}
		cout << endl;
	}
	vector<POS> yx;
	POS temp1;
		temp1.rX = 0;
		temp1.rY = 1;
		temp1.bX = 0;
		temp1.bY = 1;
		yx.push_back(temp1);
		temp1.rX = 1;
		temp1.rY = 0;
		temp1.bX = 1;
		temp1.bY = 0;
		yx.push_back(temp1);
	dfs(0, yx);
	
	cout << min;

	return 0;
}