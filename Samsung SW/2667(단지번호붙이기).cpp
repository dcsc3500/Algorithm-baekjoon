#include <iostream>
#include <queue>
#include <utility>
#include <list>

using namespace std;
int map[26][26];
int w, h;
int ansNum = 0;
int temp = 0;
queue<pair<int,int>> q;
list<int> l;


void change(int a,int b) {
	if (map[a][b] == -1)
		return;
	if (map[a][b] == 1) {
		temp++;
	}
	map[a][b] = -1;
	
	
	if (a != 0)
		if (map[a - 1][b] == 1)			
			q.push(pair<int,int>(a-1,b));
	if (b != w - 1)
		if (map[a][b + 1] == 1)
			q.push(pair<int,int>(a,b+1));
	if (a != h - 1)
		if (map[a + 1][b] == 1)
			q.push(pair<int,int>(a+1,b));
	if (b != 0)
		if (map[a][b - 1] == 1)
			q.push(pair<int,int>(a,b-1));		
}


int main() {
	ios_base::sync_with_stdio(false);

	int i, j;
	int a, b;
	int line;

	cin >> w;
	h = w;
	for (i = 0; i < w; i++) {
		for (j = h-1; j >= 0; j--) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (i = 0; i < w; i++) {
		for (j = 0; j < h; j++) {
			if (map[i][j] == 1) {
				ansNum++;
				q.push(pair<int,int>(i, j));
				while (1) {
					if (q.empty())
						break;
					a = q.front().first;
					b = q.front().second;
					change(a, b);
					q.pop();
					
				}
				l.push_back(temp);
				temp = 0;
			}
			
		}
	}
	l.sort();

	cout << ansNum << '\n';

	auto it = l.begin();
	while (1)
	{
		cout << *it;
		it++;
			cout << '\n';
	}



	return 0;

}