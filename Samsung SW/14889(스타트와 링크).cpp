#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int map[21][21];
int person[21];
int t0, t1;
int min1= 99999;

void sum() {
	int i, j;
	t1 = 0; t0 = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (person[i] == 1 && person[j] == 1) {
				t1 = t1 + map[i][j];
			}
			else if (person[i] == 0 && person[j] == 0) {
				t0 = t0 + map[i][j];
			}
		}
	}
}


void dfs(int cnt, int man) {
	int i, j;

	if (cnt > N / 2) {
		sum();
		min1 = min(abs(t1-t0),min1);
		return;
	}
	

	for (i = man; i < N; i++) {
		person[man] = 1;
		dfs(cnt + 1, i+1);
		person[man] = 0;
	}
}



int main() {
	int i, j;
	
	cin >> N;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	dfs(1, 0);
	
	cout << min1;


	return 0;
}