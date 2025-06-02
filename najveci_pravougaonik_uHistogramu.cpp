#include <iostream>
#include <vector>
#include <stack>


using namespace std;

int main () {
	
	int n;
	cin >> n;
	vector<int> visine(n);
	for (int i = 0; i < n; i++)
		cin >> visine[i];

	int povrsina = 0;
	stack<int> s;

	for (int i = 0; i <= n; i++) {
		int trenutna = (i < n ? visine[i] : 0);

		while (!s.empty() && trenutna < visine[s.top()]) {
			int visina = visine[s.top()];
			s.pop();
			int sirina = s.empty() ? i : i - s.top() - 1;
			povrsina = max(povrsina,visina*sirina);	
		}

		s.push(i);
	}

	cout << povrsina << endl;

	return 0;
}
