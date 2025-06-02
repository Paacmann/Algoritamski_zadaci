#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int main () {
	
	int n;
	cin >> n;
	vector<int> niz(n);
	vector<int> rez;
	for (int i = 0; i < n; i++)
		cin >> niz[i];

	stack<int> s;
	for (int i = n-1; i >= 0; i--) {
		while (!s.empty() && niz[i] >= niz[s.top()])
			s.pop();

		if (s.empty())
			rez[i] = - 1;
		else {
			rez[i] = s.top();	
		}
		s.push(i);
	}
		
	for (int i = 0; i < n; i++) {
		if (rez[i] == -1)
			cout << "-" << " ";
		else {
			cout << rez[i] << " ";	
		}
	}


	return 0;
}
