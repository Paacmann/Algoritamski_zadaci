#include <functional>
#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

priority_queue<int , vector<int> , greater<int>> veci_od_sredine;
priority_queue<int , vector<int> , less<int>> manji_od_sredine;


double medijana() {
	
	if (manji_od_sredine.size() == veci_od_sredine.size())
		return (manji_od_sredine.top() + veci_od_sredine.top()) / 2.0;
	else {
		return veci_od_sredine.top();	
	}
}

void dodaj_el(int x) {
	if (veci_od_sredine.empty())
		veci_od_sredine.push(x);
	else {
		if (x <= veci_od_sredine.top())
			manji_od_sredine.push(x);
		else 
			veci_od_sredine.push(x);

		if (manji_od_sredine.size() > veci_od_sredine.size()) {
			veci_od_sredine.push(manji_od_sredine.top());
			manji_od_sredine.pop();
		} else if (veci_od_sredine.size() > manji_od_sredine.size() + 1) {
			manji_od_sredine.push(veci_od_sredine.top());
			veci_od_sredine.pop();
		}
	}
}

int main () {
	
	while (true) {
		string s;
		if (!(cin >> s))
			break;
		if (s == "m")
			cout << fixed << showpoint << setprecision(1) << medijana() << '\n';
		else if (s == "d") {
			int x;
			cin >> x;
			dodaj_el(x);
		}
	}

	return 0;
}
