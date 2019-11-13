#include <string>
#include <vector>
#include <iostream>

using namespace std;
string answer = "";

string func(string p) {
	if (p.size() == 0)
		return answer;

	int cnt = 0;

	if (p.front() == '(')
		cnt++;
	else
		cnt--;

	bool flag = (cnt < 0) ? false : true;  // flag flase¸é ±ÕÇüÀâÈù true¸é ¿Ã¹Ù¸¥
	int i = 1;

	for (i; i < p.size(); i++) {

		if (p.at(i) == '(')
			cnt++;
		else {
			cnt--;
		}
		if (cnt == 0) {
			break;
		}		
	}

	string s1 = p.substr(0, i + 1);
	string s2 = p.substr(i + 1);
	
	if (flag) { //¿Ã¹Ù¸¥ÀÌ¸é
		string temp = func(s2);
		s1.append(temp);
		return s1;
	}
	else if (!flag) { //±ÕÇüÀâÈùÀÌ¸é
		
		string s3 = func(s2);
		string temp = "(";
		temp.append(s3);
		temp.append(")");
		string rever1 = s1.substr(1, s1.size() - 2);
		string rever2 = "";
		for (int j = 0; j < rever1.size(); j++) {
			char a = rever1.at(j);
			if (a == '(')
				rever2.append(")");
			else
				rever2.append("(");
		}
		temp.append(rever2);
		return temp;
	}

}


string solution(string p) {


	answer = func(p);
	return answer;
}

int main() {
	string s = "()))((()";

	cout << solution(s) << endl;

	return 0;
}

