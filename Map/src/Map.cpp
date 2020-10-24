#include <map>
#include <iostream>
#include <string>
using namespace std;


int main() {

	map<string, string> countries;
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		string s;
		cin >> s;

		if(s == "CHANGE_CAPITAL"){
			string country, new_capital;
			cin >> country >> new_capital;

			if(countries.count(country) == 0){
				countries[country] = new_capital;
				cout << "Introduce new country "<< country <<" with capital "<< new_capital << endl;
			}
			else if(countries[country] == new_capital){
				cout << "Country " << country << " hasn't changed its capital" << endl;
			}
			else if(countries[country] != new_capital){
				const string& old_capital = countries[country];
				cout << "Country " << country << " has changed its capital from " << old_capital <<
						" to " << new_capital << endl;
				countries[country] = new_capital;
			}
		}

		else if(s == "RENAME"){
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;


			if((countries.count(new_country_name) == 1) || (countries.count(old_country_name) == 0)){
				cout << "Incorrect rename, skip" << endl;
			}
			else{
				const string& capital = countries[old_country_name];
				cout << "Country " << old_country_name << " with capital " << capital <<
						" has been renamed to " << new_country_name << endl;
				countries[new_country_name] = capital;
				countries.erase(old_country_name);
			}
		}

		else if(s == "ABOUT"){
			string country;
			cin >> country;
			if(countries.count(country) == 0){
				cout << "Country " << country << " doesn't exist" << endl;
			}
			else{
				const string& capital = countries[country];
				cout << "Country " << country << " has capital " << capital << endl;
			}
		}

		else if(s == "DUMP"){

			if(countries.size() == 0){
				cout << "There are no countries in the world" << endl;
			}
			else{
				for(const auto& item: countries){
					cout << item.first << "/" << item.second << " ";
				}
			}
		}
	}
	return 0;
}
