#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

vector<string> FindName(const map<int, string>& names, const int& year){
	vector<string> name_to_print;
	for(const auto& w: names){
	 if(year >= w.first){
		  name_to_print.push_back(w.second);
	 }
	 else{
		  break;
	 }
	}
	return name_to_print;
}

string BuildString(const vector<string>& string_to_print){

	uint sizename = string_to_print.size();
	string result = string_to_print[sizename - 1];
	bool flag = 0;
	for(int i = sizename - 2; i >= 0; i--){
	  if(string_to_print[i] != string_to_print[i + 1]){
		  if(flag == 0){
			  result +=" (";
			  flag = 1;
		  }
		  else{
			  result += ", ";
		  }
		  result += string_to_print[i];
	  }
	}
	if(flag == 1){
	  result += ")";
	}
	return result;
}


class Person {
public:
  Person(string new_name, string new_surname, int new_birth){

	  birth = new_birth;
	  year_to_name[birth] = new_name;
	  year_to_surname[birth] = new_surname;

  }

  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
	  if(year >= birth){
		  year_to_name[year] = first_name;
	  }
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
	  if(year >= birth){
		  year_to_surname[year] = last_name;
	  }
  }
  string GetFullName(const int& year)const{

	  vector<string> name_to_print;
	  vector<string> surname_to_print;

	  name_to_print = FindName(year_to_name, year);
	  surname_to_print = FindName(year_to_surname, year);

	  uint sizename = name_to_print.size();
	  uint sizesurname = surname_to_print.size();

	  if(year < birth){
		  return "No person";
	  }
	  if((name_to_print.empty()) && (surname_to_print.empty())){
		  return "Incognito";
	  }
	  else if(name_to_print.empty()){
		  return surname_to_print[sizesurname - 1] + " with unknown first name";
	  }
	  else if(surname_to_print.empty()){
		  return name_to_print[sizename - 1] + " with unknown last name";
	  }
	  else{
		  return name_to_print[sizename - 1] + " " +surname_to_print[sizesurname - 1];
	  }


  }

  string GetFullNameWithHistory(const int& year)const{
      vector<string> name_to_print;
	  vector<string> surname_to_print;

	  name_to_print = FindName(year_to_name, year);
	  surname_to_print = FindName(year_to_surname, year);

	  if(year < birth){
		  return "No person";
	  }
	  if(name_to_print.empty() && surname_to_print.empty()){
		  return "Incognito";
	  }
	  else if(name_to_print.empty()){
		  return (BuildString(surname_to_print) + " with unknown first name");
	  }
	  else if(surname_to_print.empty()){
		  return (BuildString(name_to_print) + " with unknown last name");
	  }
	  else{
		  return (BuildString(name_to_print) + " " + BuildString(surname_to_print));
	  }
  }

private:
  // приватные поля
  map<int, string> year_to_name;
  map<int, string> year_to_surname;
  int birth;
};


int main() {


	Person person("Polina", "Sergeeva", 1960);
	for (int year : {1959, 1960}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}
	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	for (int year : {1965, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	 return 0;
}

