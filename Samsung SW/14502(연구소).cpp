#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int map[12][12];
int temp[12][12];
int dir[4][2] = { {-1,0}, {0,1}, {1,0} , {0, -1} };
int max1;


queue <pair<int,int>> q;
vector<pair<int, int>> v;


void print() {
	int i, j;
	for (i = 0; i < N + 2; i++) {
		for (j = 0; j < M + 2; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void dfs(int cnt) {
	
	int i, j;
	int y, x;
	int ans;
	
	if (cnt > 2) {
		//퍼트리기
		for (i = 0; i < v.size(); i++) {
			q.push(v[i]);
		}
		while (!q.empty()) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			for (i = 0; i < 4; i++) {
				if (map[y + dir[i][0]][x + dir[i][1]] == 0) {
					map[y + dir[i][0]][x + dir[i][1]] = 2;
					q.push(make_pair(y + dir[i][0], x + dir[i][1]));
				}
			}
			
		}
	//	print();
		ans = 0;
		for (i = 1; i < N + 1; i++) {
			for (j = 1; j < M + 1; j++) {
				if (map[i][j] == 0)
					ans++;
			}
		}
		if (max1 < ans)
			max1 = ans;


		for (i = 0; i < N + 2; i++) {
			for (j = 0; j < M + 2; j++) {
				map[i][j] = temp[i][j];
			}
		}
		return;
	}


	for (i = 1; i < N + 1; i++) {
		for (j = 1; j < M + 1; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				temp[i][j] = 1;
			}
			else continue;
			dfs(cnt + 1);
			map[i][j] = 0;
			temp[i][j] = 0;
		}
	}
	

}


int main() {
	int i, j;
	cin >> N;
	cin >> M;

	for (i = 0; i < N + 2; i++) {
		map[i][0] = 1;
		map[i][M + 1] = 1;
	}
	for (i = 0; i < M + 2; i++) {
		map[0][i] = 1;
		map[N + 1][i] = 1;
	}


	for (i = 1; i < N+1; i++) {
		for (j = 1; j < M + 1; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				v.push_back(make_pair(i, j));
			}
		}
	}

	for (i = 0; i < N + 2; i++) {
		for (j = 0; j < M + 2; j++) {
			temp[i][j] = map[i][j];
		}
	}

	dfs(0);
	

	cout << max1;



	return 0;
}