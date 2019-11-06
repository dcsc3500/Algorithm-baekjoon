#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;


struct POS {
	int cctvNum;
	int x, y;
};

int map[10][10];
vector<POS> cctv;
int N, M;
int myMin = 999999;

int count_no() {
	int i, j;
	int temp = 0;
	for (i = 1; i < N + 1; i++) {
		for (j = 1; j < M + 1; j++) {
			if (map[i][j] == 0)
				temp++;
		}
	}
	return temp;
}

int check(int l) {
	if (l == 2)
		return 2;
	else if (l == 5)
		return 1;
	else
		return 4;
}

void oneWay(int dir, int cnt, int whatNum) {
	int i, j, k;

	if (dir == 0) {
		for (i = cctv[cnt].x; map[cctv[cnt].y][i] != -1; i++) {
			if (whatNum == -1)
				map[cctv[cnt].y][i]--;
			else
				map[cctv[cnt].y][i]++;
		}
	}

	else if (dir == 1) {
		for (i = cctv[cnt].y; map[i][cctv[cnt].x] != -1; i++) {
			if (whatNum == -1)
				map[i][cctv[cnt].x]--;
			else
				map[i][cctv[cnt].x]++;
		}
	}

	else if (dir == 2) {
		for (i = cctv[cnt].x; map[cctv[cnt].y][i] != -1; i--) {
			if (whatNum == -1)
				map[cctv[cnt].y][i]--;
			else
				map[cctv[cnt].y][i]++;
		}
	}

	else if (dir == 3) {
		for (i = cctv[cnt].y; map[i][cctv[cnt].x] != -1; i--) {
			if (whatNum == -1)
				map[i][cctv[cnt].x]--;
			else
				map[i][cctv[cnt].x]++;
		}
	}

}


void changeMap(int cctvNum, int cnt, int dir) {
	if (cctvNum == 1) {
		oneWay(dir % 4, cnt, cctvNum);
	}
	else if (cctvNum == 2) {
		oneWay(dir % 4, cnt, cctvNum);
		oneWay((dir + 2) % 4, cnt, cctvNum);
	}
	else if (cctvNum == 3) {
		oneWay(dir % 4, cnt, cctvNum);
		oneWay((dir + 1) % 4, cnt, cctvNum);
	}
	else if (cctvNum == 4) {
		oneWay(dir % 4, cnt, cctvNum);
		oneWay((dir + 1) % 4, cnt, cctvNum);
		oneWay((dir + 2) % 4, cnt, cctvNum);

	}
	else if (cctvNum == 5) {
		oneWay(dir % 4, cnt, cctvNum);
		oneWay((dir + 1) % 4, cnt, cctvNum);
		oneWay((dir + 2) % 4, cnt, cctvNum);
		oneWay((dir + 3) % 4, cnt, cctvNum);
	}
}


void backMap(int cctvNum, int cnt, int dir) {
	if (cctvNum == 1) {
		oneWay(dir % 4, cnt, -1);
		map[cctv[cnt].y][cctv[cnt].x] = cctvNum;
	}
	else if (cctvNum == 2) {
		oneWay(dir % 4, cnt, -1);
		oneWay((dir + 2) % 4, cnt, -1);
		map[cctv[cnt].y][cctv[cnt].x] = cctvNum;
	}
	else if (cctvNum == 3) {
		oneWay(dir % 4, cnt, -1);
		oneWay((dir + 1) % 4, cnt, -1);
		map[cctv[cnt].y][cctv[cnt].x] = cctvNum;
	}
	else if (cctvNum == 4) {
		oneWay(dir % 4, cnt, -1);
		oneWay((dir + 1) % 4, cnt, -1);
		oneWay((dir + 2) % 4, cnt, -1);
		map[cctv[cnt].y][cctv[cnt].x] = cctvNum;

	}
	else if (cctvNum == 5) {
		oneWay(dir % 4, cnt, -1);
		oneWay((dir + 1) % 4, cnt, -1);
		oneWay((dir + 2) % 4, cnt, -1);
		oneWay((dir + 3) % 4, cnt, -1);
		map[cctv[cnt].y][cctv[cnt].x] = cctvNum;
	}

}


void dfs(int cnt) {
	int i, j, k;
	int l;
	int temp, dir;
	if (cnt == cctv.size()) {
		temp = count_no();
		if (myMin > temp) {
			myMin = temp;

		}
		return;
	}

	l = cctv[cnt].cctvNum;
	dir = check(l);
	for (i = 0; i < dir; i++) {
		//cout << i << endl;

		changeMap(l, cnt, i);
		dfs(cnt + 1);
		backMap(l, cnt, i);
	}
}




int main() {
	int i, j, k;
	int temp;
	POS pos;

	scanf_s("%d %d", &N, &M);

	for (i = 0; i < N + 2; i++) {
		map[i][0] = -1;
		map[i][M + 1] = -1;
	}
	for (i = 0; i < M + 2; i++) {
		map[0][i] = -1;
		map[N + 1][i] = -1;
	}

	for (i = 1; i < N + 1; i++) {
		for (j = 1; j < M + 1; j++) {
			scanf_s("%d", &temp);
			if (0 < temp && temp < 6) {
				pos.x = j;
				pos.y = i;
				pos.cctvNum = temp;
				cctv.push_back(pos);
			}
			if (temp == 6)
				map[i][j] = -1;
			else
				map[i][j] = temp;
		}
	}

	dfs(0);

	cout << myMin;

	return 0;
}