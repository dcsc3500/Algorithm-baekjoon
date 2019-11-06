#include <iostream>
#include <algorithm>

using namespace std;

int N, L;
int map[101][101];
int last[2] = { -1,-1 };  // y,x
int ans;


bool checkGaro(int dir, int y, int x) {
	int i, j;
	int temp;
	if (dir == 1) { // �ϰ���
		temp = map[y][x+1];
		for (i = 1; i <= L; i++) {
			if (temp != map[y][x + i] || x + i > N-1) {
				return false;
			}
		}
		last[0] = y;
		last[1] = x + L;
	}
	else if (dir == -1) { // ��½�
		temp = map[y][x];
		for (i = -1; i >= -L; i--) {
			if (temp != map[y][x + i +1] || x + i +1 < 0 || (y == last[0] && x + i + 1 <= last[1])) {
				return false;
			}
		}	
	}
	return true;
}

bool checkSero(int dir, int y, int x) {
	int i, j;
	int temp;
	if (dir == 1) { // �ϰ���
		temp = map[y + 1][x];
		for (i = 1; i <= L; i++) { //
			if (temp != map[y + i][x] || y + i > N - 1) {
				//cout << temp << "   " << map[y + i][x] << endl;
				//cout << "y: " << y << "    x:  " << x << endl;
				return false;
			}
		}
		last[0] = y + L;
		last[1] = x;
	}
	else if (dir == -1) { // ��½�
		temp = map[y][x];
		for (i = -1; i >= -L; i--) {
			if (temp != map[y + i +1][x] || y + i +1 < 0 || (y + i + 1 <= last[0] && x == last[1])) {
				//cout << temp << "   " << map[y + i][x] << endl;
				//cout << "y: " << y << "    x:  " << x << endl;
				return false;
			}
		}
	}
	return true;
}


void way() {
	int i, j;
	int temp;


	for (i = 0; i < N; i++) {    //���ι��� check
		for (j = 0; j < N - 1; j++) {
			temp = map[i][j] - map[i][j + 1];
			if (abs(temp) > 1) { //�������� 1�̻�
				//cout << "break" << endl;
				break;
			}
			if (temp == 0) {
			//	cout << "continue" << endl;
				continue;
			}
			if (!checkGaro(temp, i, j)) { // ���� ����� �н�
			//	cout << "check break" << endl; 
				break;
			}
		}
		//cout << "j: " << j << "    N:" << N << endl;
		if (j+1 == N)
			ans++;
	}

	last[0] = -1;
	last[1] = -1;

	for (j = 0; j < N; j++) {
		for (i = 0; i < N-1; i++) {
			temp = map[i][j] - map[i + 1][j];
			if (abs(temp) > 1) //�������� 1�̻�
				break;
			if (temp == 0)
				continue;
			if (!checkSero(temp,i,j)) // ���� ����� �н�
				break;

		}
		//cout << "i: " << i << "    N:" << N << endl;
		if (i+1 == N)
			ans++;
	}


}



int main() {

	int i, j;

	cin >> N;
	cin >> L;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	way();

	cout << ans;

	return 0;
}