#include <iostream>
#include <algorithm>

using namespace std;

int dir[4][2] = {
	{-1,0},{0,1},{1,0},{0,-1}
};
int N, M;
int map[501][501];
int visit[501][501];
int max1;
int sum;

void tCheck() {
	int i, j;
	for (i = 0; i < N; i++) {
		
		for (j = 0; j < M; j++) {
			sum = 0;
			if (j + 2 > M - 1)
				continue;
			sum += map[i][j];
			sum += map[i][j + 1];
			sum += map[i][j + 2];
			if (i - 1 >= 0) {
				sum += map[i - 1][j + 1];
				max1 = max(sum, max1);
				sum -= map[i - 1][j + 1];
			}
			if (i + 1 < N) {
				sum += map[i + 1][j + 1];
				max1 = max(sum, max1);
			}
		}
	}



	for (j = 0; j < M; j++) {
		for (i = 0; i < N; i++) {
			sum = 0;
			if (i + 2 > N - 1)
				continue;
			sum += map[i][j];
			sum += map[i + 1][j];
			sum += map[i + 2][j];
			if (j - 1 >= 0) {
				sum += map[i + 1][j - 1];
				max1 = max(sum, max1);
				sum -= map[i + 1][j - 1];
			}
			if (j + 1 < M) {
				sum += map[i + 1][j + 1];
				max1 = max(sum, max1);
			}
		}
	}

}


void dfs(int cnt, int y, int x) {

	int i, j, k;

	if (cnt > 3) {
		if (sum > max1)
			max1 = sum;
		return;
	}

	for (i = 0; i < 4; i++) {
		if (y + dir[i][0] <0 || y + dir[i][0] > N - 1 || x + dir[i][1] > M-1 || x + dir[i][1] < 0)
			continue;
		if (visit[y + dir[i][0]][x + dir[i][1]] == 1)
			continue;
		visit[y][x] = 1;
		sum += map[y][x];
		dfs(cnt + 1, y + dir[i][0], x + dir[i][1]);
		sum -= map[y][x];
		visit[y][x] = 0;
	}



}


int main() {
	int i, j;


	cin >> N;
	cin >> M;


	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			dfs(0, i, j);
		}
	}
	tCheck();

	cout << max1;


	return 0;
}