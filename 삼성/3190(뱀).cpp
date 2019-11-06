#include <iostream>
#include <vector>
#include <deque>
#include <cstdio>

using namespace std;

int N, K ,L;
int map[102][102];
vector <pair<int, char>> v;
deque<pair<int,int>> q;
int nowDir = 1;
int head[2], tail[2];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
bool stop = false;
int ans;

void print() {
	int i, j;
	for (i = 0; i < N + 2; i++) {
		for (j = 0; j < N + 2; j++) {
			printf("%2d", map[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}

void start() {
	int i, j;
	char tdir;
	int cnt = 0;
	pair <int, int> p1;
	p1 = make_pair(1, 1);
	map[1][1] = -1;
	q.push_back(p1);

	

	for (i = 0; i < L; i++) {
		cnt = v[i].first;
		tdir = v[i].second;

		while (1) {
			if (cnt == ans)
				break;
			ans++;
			head[0] = q.front().first + dir[nowDir][0];
			head[1] = q.front().second + dir[nowDir][1];
			if (map[head[0]][head[1]] == -1) {
				stop = true;
				break;
			}
			else if (map[head[0]][head[1]] == 2) {
				map[head[0]][head[1]] = -1;
				p1 = make_pair(head[0], head[1]);
				q.push_front(p1);
			}
			else {
				p1 = make_pair(head[0], head[1]);
				map[head[0]][head[1]] = -1;
				p1 = make_pair(head[0], head[1]);
				q.push_front(p1);
				tail[0] = q.back().first;
				tail[1] = q.back().second;
				map[tail[0]][tail[1]] = 0;
				q.pop_back();
			}
		}
		if (stop)
			break;
		if (tdir == 'D') { //오른쪽회전
			nowDir = (nowDir + 1) % 4;
		}
		else if (tdir == 'L') { //왼쪽회전
			nowDir = (nowDir + 3) % 4;
		}
			
	}
	if (!stop) {
		while (1) {
			ans++;
			head[0] = q.front().first + dir[nowDir][0];
			head[1] = q.front().second + dir[nowDir][1];
			if (map[head[0]][head[1]] == -1) {
				break;
			}
			p1 = make_pair(head[0], head[1]);
			map[head[0]][head[1]] = -1;
			p1 = make_pair(head[0], head[1]);
			q.push_front(p1);
			tail[0] = q.back().first;
			tail[1] = q.back().second;
			map[tail[0]][tail[1]] = 0;
			q.pop_back();
			
			
		}
	}

}




int main() {
	int i, j, k;
	int x, y;
	char t;
	pair<int, char> p;


	cin >> N;
	cin >> K;
	for (i = 0; i < K; i++) {
		cin >> y;
		cin >> x;
		map[y][x] = 2;
	}
	cin >> L;
	for (i = 0; i < L; i++) {
		cin >> x;
		cin >> t;
		p = make_pair(x, t);
		v.push_back(p);
	}


	for (i = 0; i < N + 2; i++) {
		map[i][0] = -1;
		map[i][N + 1] = -1;
		map[0][i] = -1;
		map[N + 1][i] = -1;
	}


	start();

	cout << ans;
	


	return 0;
}