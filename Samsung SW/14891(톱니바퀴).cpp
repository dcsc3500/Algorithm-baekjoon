#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct moving {
	int time;//�ð�
	int dir;
};

int top[4][8]; 
int topNow[4]; // ���� 12���ξֵ� ��ȣ
vector<moving> how;
queue<int> q;




void check(int time) {
	int i, j;

	for (i = time; i > 0; i--) {  // ȸ���ؾ��� ���� ���ʾֵ� check
		int temp = topNow[i] - 2;
		if (temp < 0)
			temp = temp + 8;
		if (top[i-1][(topNow[i-1] + 2) % 8] != top[i][temp]) {
			q.push(i - 1);
		}
		else break;

	}

	for (i = time; i < 3; i++) {   //ȸ���ؾ��ҹ��� �����ʾֵ� check
		int temp = topNow[i + 1] - 2;
		if (temp < 0)
			temp = temp + 8;
		if (top[i][(topNow[i] + 2) % 8] != top[i + 1][temp]) {
			q.push(i + 1);
		}
		else break;

	}

}


void bfs(int time, int dir) {
	int rDir = -dir;
	int i, j;
	int tTime = time - 1;

	q.push(tTime);  // ��ó�� �ϴ� ������ ��ϴ� q�� �ٷ� �ھ���
	check(tTime);  //�¿쿡 ���̴ٸ���ã�������� �Լ�
	while (!q.empty()) {
		if (q.front() % 2 == tTime % 2) {  //��ó�� ���³��̶� ���� �ڸ� �� 1,3 2,4,���� �������� ȸ���ϴ°� üũ
			topNow[q.front()] = (topNow[q.front()] - dir) % 8;
			if (topNow[q.front()] < 0)
				topNow[q.front()] = topNow[q.front()] + 8;
		}
		else {
			topNow[q.front()] = (topNow[q.front()] - rDir) % 8; 
			if (topNow[q.front()] < 0)
				topNow[q.front()] = topNow[q.front()] + 8;
		}
		//cout << q.front()<< "/ ";

		q.pop();

	}

	//cout << endl;
	//cout << "���� ž: " << topNow[0] << "/" << topNow[1] << "/" << topNow[2] << "/" << topNow[3] << "/" << endl;
}



int main() {
	int i, j;
	int temp;
	int sum;
	moving tem;
	for (j = 0; j < 4; j++) {
		for (i = 0; i < 8; i++) {
			scanf_s("%1d", &top[j][i]);
		}
	}


	scanf_s("%d", &temp);
	for (i = 0; i < temp; i++) {
		scanf_s("%d %d", &tem.time, &tem.dir);
		how.push_back(tem);
	}

	for (i = 0; i < temp; i++) {
		bfs(how[i].time, how[i].dir);
	}
	sum = 0;

	int two = 1;

	for (i = 0; i < 4; i++) {
		sum += (top[i][topNow[i]] * two);
		two = two * 2;
	}

	cout << sum;


	return 0;
}