#include <iostream>
#include <exception>
#include <string>
#include <sstream>
using namespace std;
/*
string AskTimeServer(){

	//throw invalid_argument("SOS");
	//return "18:49:35";
}
*/
class TimeServer {
public:
  string GetCurrentTime(){
	  try{
		  last_fetched_time = AskTimeServer();
		  return last_fetched_time;
	  }catch(system_error& ){
		  return last_fetched_time;
	  }


  }
private:
  string last_fetched_time = "00:00:00";
};
/*
int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
*/
