#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main () {
	
	int n;
	cin >> n;
	vector<int> niz(n);
	for (int i = 0; i < n; i++)
		cin >> niz[i];

	vector<int> vecihLevo(n) , vecihDesno(n);
	stack<int> s;

	for (int i = 0; i < n; i++) {
		while (!s.empty() && niz[s.top()] > niz[i])
			s.pop();
		
		vecihLevo[i] = s.empty() ? i+1 : i - s.top();
		s.push(i);
	}

	while (!s.empty())
		s.pop();

	for (int i = n-1; i >= 0; i--) {
		while (!s.empty() && niz[s.top()] >= niz[i])
			s.pop();
		
		vecihDesno[i] = s.empty() ? n-i : s.top() - i;
		s.push(i);
	}

	int rezultat = 0;
	for (int i = 0; i < n; i++) {
		
		rezultat += niz[i]*vecihLevo[i]*vecihDesno[i];
	}

	cout << rezultat << endl;

	return 0;
}
