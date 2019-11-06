#include <iostream>
#include <vector>
#include <queue>
#include <string>


using namespace std;

struct pos {
	int rX, rY, bX, bY;
	int cnt;
};

int dirY[4] = {
   -1,0,1,0
};
int dirX[4] = {
   0,1,0,-1
};

int ans, fail;
int map[11][11];
int visited[11][11][11][11];
int N, M;
queue<pos> q;
pos nowRB;
int hole[2]; // 0 번은 y좌표 1번은 x좌표
int cnt;


void bfs() {
	int i, j;

	int trX, trY, tbX, tbY, tCnt;
	visited[nowRB.rY][nowRB.rX][nowRB.bY][nowRB.bX] = 1;
	nowRB.cnt++;
	q.push(nowRB);
	while (!q.empty()) {
		nowRB = q.front();
		if (nowRB.cnt > 10) {
			q.pop();
			continue;
		}
		trY = nowRB.rY;
		trX = nowRB.rX;
		tbY = nowRB.bY;
		tbX = nowRB.bX;
		tCnt = nowRB.cnt;
		for (i = 0; i < 4; i++) { // 방향기울이기
			while (1) { // 기울인방향으로 쭉가기
				if (map[nowRB.rY][nowRB.rX] == -1 && map[nowRB.bY][nowRB.bX] == -1)
					break;
				if (map[nowRB.rY][nowRB.rX] != -1) {
					nowRB.rY += dirY[i];
					nowRB.rX += dirX[i];
					if (nowRB.rY == hole[0] && nowRB.rX == hole[1]) {
						ans = 1;

					}
				}

				if (map[nowRB.bY][nowRB.bX] != -1) {
					nowRB.bY += dirY[i];
					nowRB.bX += dirX[i];
					if (nowRB.bY == hole[0] && nowRB.bX == hole[1]) {
						fail = 1;
					}
				}
			}

			nowRB.rY -= dirY[i];
			nowRB.rX -= dirX[i];
			nowRB.bY -= dirY[i];
			nowRB.bX -= dirX[i];

			if (fail == 1) {
				ans = 0;
				fail = 0;
				nowRB.rY = trY;
				nowRB.rX = trX;
				nowRB.bY = tbY;
				nowRB.bX = tbX;
				continue;
			}
			else if (ans == 1 && fail == 0) {
				cnt = nowRB.cnt;
				return;
			}



			if (nowRB.rX == nowRB.bX && nowRB.rY == nowRB.bY) {
				if (i == 0)
					trY < tbY ? nowRB.bY++ : nowRB.rY++;
				else if (i == 1)
					trX < tbX ? nowRB.rX-- : nowRB.bX--;
				else if (i == 2)
					trY < tbY ? nowRB.rY-- : nowRB.bY--;
				else if (i == 3)
					trX < tbX ? nowRB.bX++ : nowRB.rX++;
			}

			if (!visited[nowRB.rY][nowRB.rX][nowRB.bY][nowRB.bX]) {
				visited[nowRB.rY][nowRB.rX][nowRB.bY][nowRB.bX] = 1;
				nowRB.cnt++;
				q.push(nowRB);
				//cout << nowRB.rY << "/" << nowRB.rX << "        ";
				//cout << nowRB.bY << "/" << nowRB.bX << endl;

			}
			nowRB.rY = trY;
			nowRB.rX = trX;
			nowRB.bY = tbY;
			nowRB.bX = tbX;
			nowRB.cnt = tCnt;

		}
		q.pop();
	}
	if (cnt < 11 && ans == 0)
		cnt = -1;
}


int main() {
	int i, j;
	string temp;
	scanf_s("%d %d", &N, &M);

	for (i = 0; i < N; i++) {
		cin >> temp;
		for (j = 0; j < M; j++) {
			if (temp[j] == '#') {
				map[i][j] = -1;
			}
			else if (temp[j] == '.')
				map[i][j] = 0;
			else if (temp[j] == 'R') {
				nowRB.rX = j;
				nowRB.rY = i;
				map[i][j] = 0;
			}
			else if (temp[j] == 'B') {
				nowRB.bX = j;
				nowRB.bY = i;
				map[i][j] = 0;
			}

			else if (temp[j] == 'O') {
				map[i][j] = 0;
				hole[0] = i;
				hole[1] = j;
			}

		}
	}

	nowRB.cnt = 0;
	bfs();

	cout << cnt;

	return 0;
}