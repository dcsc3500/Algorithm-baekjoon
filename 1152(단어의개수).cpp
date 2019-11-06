#include <iostream>
#include <string>



using namespace std;


int main() {
	ios_base::sync_with_stdio(false);


	int i, j;
	int state = 0;
	string word;
	int cnt = 0;
	string temp = "a";

	getline(cin, word);


	for (i = 0; i < word.length(); i++) {
		if (state == 0 && (('A' <= word[i] && word[i] <= 'Z') || ('a' <= word[i] && word[i] <= 'z'))) {
			cnt++;
			state = 1;
		}
		if (word[i] == ' ') {
			state = 0;
		}
	}
	cout << cnt;


	return 0;

}