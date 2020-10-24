#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

class Date{
public:
	Date(){
		year = 0;
		month = 0;
		day = 0;
	}
	Date(const int &new_year, const int &new_month, const int &new_day){
		year = new_year;
		if(new_month < 1 || new_month > 12){
			throw invalid_argument("Month value is invalid: " + to_string(new_month));
		}
		month = new_month;
		if(new_day < 1 || new_day > 31){
			throw invalid_argument("Day value is invalid: " + to_string(new_day));
		}
		day = new_day;
	}
	int GetYear() const{
		return year;
	}
    int GetMonth() const{
    	return month;
    }
	int GetDay() const{
		return day;
	}
private:
	int year;
	int month;
	int day;
};

ostream& operator<<(ostream& stream, const Date& date){

	stream << setfill('0');
	stream << setw(4) << date.GetYear() << "-" << setw(2) <<
			date.GetMonth() << "-" <<setw(2) << date.GetDay();
	return stream;
}

istream& operator>>(istream& stream, Date& date){
	int year = 0;
	int month = 0;
	int day = 0;
	string str;
	stream >> str;
	stringstream ss(str);
	runtime_error excep("Wrong date format: " + str);
	set<char> allowed_symbols = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-'};
	int minus_sum_near = 0;
	for(const char& symbol : str){
		if(allowed_symbols.count(symbol) == 0){
			throw excep;
		}
		if(symbol == '-'){
			minus_sum_near++;
		}
		else{
			minus_sum_near = 0;
		}
		if(minus_sum_near > 2){
			throw excep;
		}
	}
	if(count(begin(str),end(str), '-') < 2){
		throw excep;
	}
	if(str[str.size() - 1] == '-'){
		throw excep;
	}

	ss >> year;
	ss.ignore(1);
	ss >> month;
	ss.ignore(1);
    ss >> day;

	date = Date{year, month, day};
	return stream;
}

bool operator<(const Date& left,const Date& right){
	if(left.GetYear() == right.GetYear()){
		if(left.GetMonth() == right.GetMonth()){
			return left.GetDay() < right.GetDay();
		}
		return left.GetMonth() < right.GetMonth();
	}
	return left.GetYear() < right.GetYear();
}

bool operator==(const Date& left,const Date& right){
	return (left.GetYear() == right.GetYear()) && (left.GetMonth() == right.GetMonth())
			&& (left.GetDay() == right.GetDay());
}

class Database {
public:
  void AddEvent(const Date& date, const string& event){
	  date_events[date].insert(event);
  }
  bool DeleteEvent(const Date& date, const string& event){
	  if(date_events.count(date) == 0){
		  return false;
	  }
	  bool flag = date_events[date].count(event) != 0;
	  date_events[date].erase(event);
	  return flag;
  }
  int  DeleteDate(const Date& date){
	  int size = date_events[date].size();
	  date_events.erase(date);
	  return size;
  }

  void Find(const Date& date)const{

	  if(date_events.count(date) == 0){
		  return;
	  }
	  for(const auto& word: date_events.at(date)){
	  	  cout << word << endl;
	  }
  }
  void Print()const{

	  for(const auto& item: date_events){
		  for(const string& w: item.second){
			  cout << item.first << " " << w << endl;
		  }
	  }
  }
private:
  map <Date, set<string>> date_events;
};
void Add(stringstream& ss, Database& db){
	Date date;
	string event;
	ss >> date >> event;
	db.AddEvent(date, event);
}
void Del(stringstream& ss, Database& db){
	Date date;
	string event;
	ss >> date >> event;
	if(event.empty()){		// Delete date with events
		cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
	}
	else{ //Delete event
		if(db.DeleteEvent(date, event)){
			cout << "Deleted successfully" << endl;
		}
		else{
			cout << "Event not found" << endl;
		}
	}
}
void Find(stringstream& ss, Database& db){
	Date date;
	ss >> date;
	db.Find(date);
}
int main() {
	Database db;
	string commandline;
	while(getline(cin, commandline)){
		stringstream ss(commandline);
		string command;
		ss >> command;
		try{
			if(command == "Add"){
				Add(ss, db);
			}
			else if(command == "Del"){
				Del(ss, db);
			}
			else if(command == "Find"){
				Find(ss, db);
			}
			else if(command == "Print"){
				db.Print();
			}
			else if(command == ""){

			}
			else{
				cout << "Unknown command: " << command << endl;
			}
		}
		catch(runtime_error & e){
			cout << e.what() << endl;
			return 0;
		}
		catch(invalid_argument& e){
			cout << e.what() << endl;
			return 0;
		}
	}
	return 0;
}
