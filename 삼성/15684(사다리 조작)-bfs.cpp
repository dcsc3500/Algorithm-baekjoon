#include <iostream>
#include <cstdio>

using namespace std;
int N, M, H;
int map[11][31];
int ansmap[11][31];
int ans = -1;

int check() {
	int i, j, k;
	int myNum,temp;
	for (myNum = 1; myNum <= N;) {
		temp = myNum;
		for (i = 1; i <= H; i++) {
			if (map[i][myNum] == 1)
				myNum++;
			else if (map[i][myNum] == -1)
				myNum--;
		}
		if (myNum != temp)
			return -1;
		myNum = temp + 1;
	}
	return 1;

}

void print() {
	int i, j;
	cout << endl;
	for (i = 1; i <= H; i++) {
		for (j = 1; j <= N; j++) {
			printf("%2d", map[i][j]);
		}
		cout << endl;
	}
}


void dfs(int cnt, int now) {
	int i, j, k;
	//cout << cnt << ' ' << now << endl;
	if (cnt > 3)
		return;

	if (ans > 0)
		return;

	
	for (i = 1; i <= H; i++) {
		for (j = 1; j <= N - 1; j++) {
			if (map[i][j] != 1 && map[i][j] != -1 && map[i][j + 1] != -1 && map[i][j + 1] != 1) {
				map[i][j] = 1;
				map[i][j + 1] = -1;
				
				int ck = check();
				if (ck == 1) {

					for (int q = 1; q <= H; q++) {
						for (int k = 1; k <= N; k++) {
							ansmap[q][k] = map[q][k];
						}
					}

					ans = cnt;
					//cout << ans << endl;
					return;
				}
				if (now < cnt)
					dfs(cnt, now + 1);
				//cout << cnt << ' ' << now << endl;
				if (ans > 0)
					return;

				map[i][j] = 0;
				map[i][j + 1] = 0;


			}
		}
	}

	dfs(cnt+1,1);

}




int main() {
	int i, j, k;
	int a, b;
	scanf_s("%d %d %d", &N, &M, &H);

	for (i = 0; i < M; i++) {
		scanf_s("%d %d", &a, &b);
		map[a][b] = 1;
		map[a][b + 1] = -1;
	}
	print();
	int ck = check();
	if (ck == 1) {
		ans = 0;
	}
	else
		dfs(1, 1);

	cout << endl;
	for (i = 1; i <= H; i++) {
		for (j = 1; j <= N; j++) {
			printf("%2d", ansmap[i][j]);
		}
		cout << endl;
	}



	cout << ans;

	return 0;
}