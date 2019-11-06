#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;


struct namecard {
	string name;
	int kor;
	int eng;
	int math;
};

bool compare(const namecard &t1, const namecard &t2) {
	if (t1.kor > t2.kor)
		return true;
	else if (t1.kor == t2.kor) {
		if (t1.eng < t2.eng)
			return true;
		else if (t1.eng == t2.eng) {
			if (t1.math > t2.math)
				return true;
			else if (t1.math == t2.math)
				return t1.name < t2.name;
		}
			
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	vector<namecard> v;
	int i, j;
	namecard tName;
	
	cin >> N;
	
	for (i = 0; i < N; i++) {
		cin >> tName.name;
		cin >> tName.kor;
		cin >> tName.eng;
		cin >> tName.math;
		v.push_back(tName);		
	}
	sort(v.begin(), v.end(), compare);
	for (i = 0; i < v.size(); i++) {
		cout << v[i].name << '\n';
	}

	return 0;
}