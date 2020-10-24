#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;


int main() {

	map<string, set<string>> sinonims;
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		string s;
		cin >> s;
		if(s == "ADD"){
			string word1, word2;
			cin >> word1 >> word2;
				sinonims[word1].insert(word2);
				sinonims[word2].insert(word1);

		}
		else if(s == "COUNT"){
			string word;
			cin >> word;

			if(sinonims.count(word) == 0){
				cout << 0;
			}
			else{
				cout << sinonims[word].size();
			}

			cout << endl;

		}
		else if(s == "CHECK"){
			string word1;
			string word2;
			cin >> word1 >> word2;

			if(sinonims.count(word1) == 0){
				cout << "NO";
			}
			else{

				if(sinonims[word1].count(word2) == 0){
					cout << "NO";
				}
				else{
					cout << "YES";
				}

			}

			cout << endl;
		}
	}
	return 0;
}

