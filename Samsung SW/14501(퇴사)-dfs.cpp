#include <iostream>

using namespace std;

int N;
int t[20], p[20];
int max1;

void dfs(int day, int temp) {
	if (day + t[day] -1 > N) {
		return;
	}
	temp = temp + p[day];
	if (max1 < temp) {
		max1 = temp;
	}
	
	for (int i = t[day] + day; i <= N; i++) {
		dfs(i, temp);
	}
	

}


int main() {
	int i, j;


	cin >> N;
	for (i = 1; i <= N; i++) {
		cin >> t[i];
		cin >> p[i];
	}
	for (i = 1; i <= N; i++) {
		dfs(i, 0);
	}
	
	cout << max1;


	return 0;
}