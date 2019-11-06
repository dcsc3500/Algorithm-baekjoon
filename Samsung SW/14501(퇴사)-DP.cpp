#include <iostream>
#include <algorithm>

using namespace std;

int N;
int t[20], p[20];
int dp[20];
int max1;



int main() {
	int i, j;


	cin >> N;
	for (i = 1; i <= N; i++) {
		cin >> t[i];
		cin >> p[i];
		dp[i] = p[i];
	}


	for (i = 2; i <= N; i++) {
		for (j = 1; j < i; j++) {
			if (j + t[j] <= i && i + t[i] <= N +1) {//day가 가능하다면	
				dp[i] = max(dp[j] + p[i], dp[i]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (i + t[i] <= N + 1) {
			if (max1 < dp[i]) {
				max1 = dp[i];
			}
		}
	}
	
	cout << max1;


	


	return 0;
}