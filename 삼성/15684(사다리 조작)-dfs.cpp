#include <iostream>
#include <cstdio>

using namespace std;

int N, M, H;
int ans = 4;
int map[31][11];


bool check() {
	int i, j;
	int temp;
	for (i = 1; i <= N; i++) {
		temp = i;
		for (j = 1; j <= H; j++) {
			if (map[j][temp] == 1)
				temp++;
			else if(map[j][temp] == -1)
				temp--;
		}
		if (temp == i)
			continue;
		else
			return false;
	}


	return true;
}

void dfs(int cnt, int x, int y) {
	int i, j;

	if (cnt >= ans)//현재 최솟값보다 cnt값이 크면 종료
		return;
	cout << endl;
	for (i = 1; i <= H; i++) {
		for (j = 1; j <= N; j++) {
			printf("%2d", map[i][j]);
		}
		cout << endl;
	}

	for (i = x; i <= H; i++) {
		for (j = 1; j <= N-1; j++) {
	
			if (map[i][j] != 1 && map[i][j] != -1 && map[i][j+1] != -1 && map[i][j+1] != 1) {
				map[i][j] = 1;
				map[i][j + 1] = -1;
				if (check()) {
					ans = cnt;
				}
				dfs(cnt + 1, i, j);
				map[i][j] = 0;
				map[i][j + 1] = 0;
				
			}
		}
	}


}



int main() {
	int a, b;
	int i, j;
	scanf_s("%d %d %d", &N, &M, &H);
	for (i = 0; i < M; i++) {
		scanf_s("%d %d", &a, &b);
		map[a][b] = 1;
		map[a][b + 1] = -1;
	}
	
	cout << endl;
	for (i = 1; i <= H; i++) {
		for (j = 1; j <= N; j++) {
			printf("%2d", map[i][j]);
		}
		cout << endl;
	}
	


	if(check()) {
		ans = 0;
	}
	else{
		dfs(1, 1,1);
	}
	
	if (ans == 4)
		ans = -1;
	
	cout << ans;

	return 0;
}