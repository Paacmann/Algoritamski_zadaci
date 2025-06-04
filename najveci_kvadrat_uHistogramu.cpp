#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main () {
	
	int n;
	cin >> n;
	vector<int> visine(n);
	for (int i = 0; i < n; i++)
		cin >> visine[i];

	stack<int> s;
	int max_povrsina = 0;

	for (int i = 0; i <= n; i++) {
		
		int trenutna = (i < n ? visine[i] : 0);
		
		while (!s.empty() && trenutna < visine[s.top()]) {
			int visina = visine[s.top()];
			s.pop();
			int sirina = s.empty() ? i : i - s.top() - 1;
			int stranica = min(visina,sirina);
			max_povrsina = max(max_povrsina , stranica*stranica);
		}

		s.push(i);
	}

	cout << max_povrsina << endl;

	return 0;
}
