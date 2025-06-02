#include <iostream>
#include <stack>

using namespace std;


int main () {

	int n;
	cin >> n;
	stack<int> s;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.push(x);

		while (!s.empty() && s.top() <= x) {
			s.pop();
		}

		if (s.empty()) {
			cout << '-' << endl;
		} else {
			cout << s.top() << " ";
		}
		s.push(x);
	}
	
	cout << endl;
	return 0;
}
