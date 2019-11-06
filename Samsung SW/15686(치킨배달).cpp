#include <iostream>
#include<cstdio>

using namespace std;

int N, M;
int map[51][51];
int info_chic[13][2];
int info_home[100][2];
int num_chic, num_home;
int mymin = 9999999;
int ans_chic[13];


int distance() {
	int x, y;
	int min_home;
	int sum = 0;
	int i, j, k; 
	for (j = 0; j < num_home; j++) {
		min_home = 999999;
		for (i = 0; i < M; i++) {
			if (info_chic[ans_chic[i]][0] > info_home[j][0])
				x = info_chic[ans_chic[i]][0] - info_home[j][0];
			else
				x = info_home[j][0] - info_chic[ans_chic[i]][0];
			
			if (info_chic[ans_chic[i]][1] > info_home[j][1])
				y = info_chic[ans_chic[i]][1] - info_home[j][1];
			else
				y = info_home[j][1] - info_chic[ans_chic[i]][1];
			if (min_home > x + y)
				min_home = x + y;
		}
		sum += min_home;
	}
	return sum;
}

void dfs(int cnt,int now) {
	int i, j, temp;
	int dis;
	if (cnt == M) {
		dis = distance();
		if (mymin > dis)
			mymin = dis;
		return;
	}
	else {
		for (i = now; i < num_chic; i++) {
			ans_chic[cnt] = i;
			dfs(cnt + 1, i + 1);
		}				
	}

}



int main() {
	int i, j, k;
	int temp;
	
	scanf_s("%d", &N);
	scanf_s("%d", &M);
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf_s("%d", &temp);
			if (temp == 1) {
				info_home[num_home][0] = i;
				info_home[num_home][1] = j;
				num_home++;
						
			}
			else if (temp == 2) {
				info_chic[num_chic][0] = i;
				info_chic[num_chic][1] = j;
				num_chic++;
			}
		}
	}

	dfs(0,0);

	cout << mymin;

	return 0;
}