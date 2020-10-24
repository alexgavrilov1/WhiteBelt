#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<string> Buses(map<string, vector<string>>& stops_to_buses, const string& stop){

	vector<string> result;

	if(stops_to_buses.count(stop) != 0){
		for(const auto& w: stops_to_buses[stop]){
			result.push_back(w);
		}
	}

	return result;
}

int main() {

	int q;
	map<string, vector<string>> buses_to_stops, stops_to_buses;

	cin >> q;
	for(int i = 0; i < q; i++){
		string s;
		cin >> s;

		if(s == "NEW_BUS"){
			string bus;
			int stop_count;
			cin >> bus >> stop_count;
			buses_to_stops[bus].resize(stop_count);
			for(auto& stop: buses_to_stops[bus]){
				cin >> stop;
				stops_to_buses[stop].push_back(bus);
			}

		}

		else if(s == "BUSES_FOR_STOP"){
			string stop;
			cin >> stop;
			vector<string> result;
			result = Buses(stops_to_buses, stop);
			if(result.size() == 0){
				cout << "No stop";
			}else{
				for(const auto& w: result){
					cout << w << " ";
				}
			}
			cout << endl;
		}
		else if(s == "STOPS_FOR_BUS"){
			string bus;
			cin >> bus;
			vector<string> result;

			if(buses_to_stops.count(bus) == 0){
				cout << "No bus" << endl;
			}
			else{
				for(auto& w: buses_to_stops[bus]){
					cout << "Stop " << w << ": ";
					result = Buses(stops_to_buses, w);
					if(result.size() == 1){
						cout << "no interchange";
					}
					else{
						for(const auto& item: result){
							if(item != bus){
								cout << item << " ";
							}
						}
					}
					cout << endl;
				}
			}

		}
		else if(s == "ALL_BUSES"){
			if(buses_to_stops.size() == 0){
				cout << "No buses" << endl;
			}
			else{
				for(const auto& item: buses_to_stops){
					cout << "Bus" << " " << item.first <<": ";
					for(const auto& item2: item.second){
						cout << item2 << " ";
					}
					cout << endl;
				}
			}
		}

	}

	return 0;
}
