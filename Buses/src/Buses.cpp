#include <iostream>
using namespace std;
#include <map>
#include <vector>
#include <set>

int main() {
	map<set<string>, int> m;
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int n;
		int value;
		set<string> ost;
		cin >> n;
		for(int j = 0; j < n; j++){
			string s;
			cin >> s;
			ost.insert(s);
		}
		value = m.size();
		if(m.count(ost) == 1){
			cout << "Already exists for " << m[ost];
		}
		else{
			m[ost] = value + 1;
			cout << "New bus " << m[ost];
		}
		cout << endl;
	}

	return 0;
}
