#include <iostream>
#include <deque>
#include <vector>

using namespace std;


int main () {
	
	int k , n;
	cin >> k >> n;

	deque<int> segment;
	deque<int> maksimumi;
	
	vector<int> rezultat;

	for (int i = 0; i < n; i++) {
		if (i >= k) {
			int prvi = segment.front();
			segment.pop_front();

			if (prvi == maksimumi.front())
				maksimumi.pop_front();
		}
		
		int ai;
		cin >> ai;
		segment.push_back(ai);
		while (!maksimumi.empty() && maksimumi.back() < ai)
			maksimumi.pop_back();
		maksimumi.push_back(ai);

		if (i >= k-1)
			rezultat.push_back(maksimumi.front());	

			//cout << maksimumi.front() << " ";
	}

	for (int &x : rezultat)
		cout << x << endl;

	return 0;
}
