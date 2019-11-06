#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> v;
string dir;
char map[6][3][3]; //0윗면-w,3아랫면-y  // 1이앞면-r 4 뒷면-o // 2오른쪽-b 5 왼쪽면-g
int rotate1[6][4] =  {
	{4,2,1,5},
	{0,2,3,5},
	{0,4,3,1},
	{1,2,4,5},
	{3,2,0,5},
	{0,1,3,4}
};
int N1, N2;

void cube0(char dir) {
	if (dir == '+') { //시계방향	
		j = 2;
		for (i = 0; i < 2; i++) {//돌리는면 시계방향으로 회전시키기
			temp = map[color][i][0];
			map[color][i][0] = map[color][2][i];
			map[color][2][i] = map[color][j][2];
			map[color][j][2] = map[color][0][j];
			map[color][0][j] = temp;
		}
		j = 2;
		for (i = 0; i < 3; i++) {
			temp = map[rotate1[color][3]][i][2];
			map[rotate1[color][3]][i][2] = map[rotate1[color][2]][0][i];
			map[rotate1[color][2]][0][i] = map[rotate1[color][1]][j][0];
			map[rotate1[color][1]][j][0] = map[rotate1[color][0]][2][j];
			map[rotate1[color][0]][2][j] = temp;
			j--;
		}
	}
	else if (dir == '-') {// 반시계방향
		j = 2;
		for (i = 0; i < 2; i++) {//돌리는면 반시계방향으로 회전시키기
			temp = map[color][0][i];
			map[color][0][i] = map[color][i][2];
			map[color][i][2] = map[color][2][j];
			map[color][2][j] = map[color][j][0];
			map[color][j][0] = temp;
			j--;
		}
		j = 2;
		for (i = 0; i < 3; i++) {
			cout << rotate1[color][0] << endl;
			temp = map[rotate1[color][0]][2][i];
			map[rotate1[color][0]][2][i] = map[rotate1[color][1]][i][0];
			map[rotate1[color][1]][i][0] = map[rotate1[color][2]][0][j];
			map[rotate1[color][2]][0][j] = map[rotate1[color][3]][j][2];
			map[rotate1[color][3]][j][2] = temp;
			j--;
		}
	}
}




void move(char col,char dir) {

	int i, j;
	char temp;
	int color;

	if (col == 'U')
		color = 0;
	else if (col == 'D')
		color = 3;
	else if (col == 'F')
		color = 1;
	else if (col == 'B')
		color = 4;
	else if (col == 'L')
		color = 5;
	else if (col == 'R')
		color = 2;
}

void print() {
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cout << map[0][i][j];
		}
		cout << endl;
	}
}

void go() {
	int i, j;
	string s;
	for (i = 0; i < N1; i++) {
		N2 = v[i].size();
		for (j = 0; j < N2; j++) {
			s = v[i][j];
			move(s[0], s[1]);
		}
		print();
	}

}



int main() {	
	int i, j, k;
	for (k = 0; k < 6; k++) {
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (k == 0)
					map[k][i][j] = 'w';
				if (k == 1)
					map[k][i][j] = 'r';
				if (k == 2)
					map[k][i][j] = 'b';
				if (k == 3)
					map[k][i][j] = 'y';
				if (k == 4)
					map[k][i][j] = 'o';
				if (k == 5)
					map[k][i][j] = 'g';
			}			
		}
	}


	cin >> N1;
	for (i = 0; i < N1; i++) {
		vector<string> sv;
		cin >> N2;
		for (j = 0; j < N2; j++) {		
			cin >> dir;
			sv.push_back(dir);
		}
		v.push_back(sv);
	}

	go();
	



	return 0;
}