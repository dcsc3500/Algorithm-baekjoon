#include <iostream>
#include <string>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	int len[30], i;
	string word;

	cin >> word;

	for (i = 0; i < 27; i++) {
		len[i] = -1;
	}


	for (i = 0; i < word.length(); i++) {
		if (len[word[i] - 'a'] == -1) {
			len[word[i] - 'a'] = i;
		}
	}

	for (i = 0; i < 26; i++) {
		cout<<len[i]<<' ';
	}


	return 0;
}