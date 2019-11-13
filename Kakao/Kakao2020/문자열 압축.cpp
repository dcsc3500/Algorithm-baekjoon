#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
	if (s.length() == 1)
		return 1;

	int answer = 999999;
	string ansString = "";
	for (int i = 1; i <= s.length()/2; i++) {  // 몇개씩 짜를건지
		
		string s1 = s.substr(0, i);
		int cnt = 0;

		for (int j = 0; j < s.length(); j += i) {
			string s2 = s.substr(j, i);
			//같은지 비교	
			//cout << "s1: " + s1 + "// s2 :" + s2 << endl;
			if (s2.compare(s1) == 0) {  //같다면 cnt 증가
				cnt++;
			}
			else {   // 다르면
				string sCnt = (cnt > 1) ? to_string(cnt) : "";
				ansString = ansString + sCnt + s1;

				s1 = s2;
				cnt = 1;
			}
			
		}
		if (cnt > 0) {
			string sCnt = (cnt > 1) ? to_string(cnt) : "";
			ansString = ansString + sCnt + s1;
		}
		//cout << ansString << endl;
		

		if (ansString.length() < answer) {
			answer = ansString.length();		
		}
		ansString.clear();
			
	}

	return answer;


}

int main() {
	string s = "a";
	cout << solution(s) << endl;
	return 0;
}