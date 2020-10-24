#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

/*
struct Image{
	double quality;
	double freshness;
	double rating;
};

struct Params{
	double a;
	double b;
	double c;
};
*/
class FunctionsPart{
public:

	FunctionsPart(char new_operation, double new_value){
		operation = new_operation;
		value = new_value;
	}
	double Apply(double source_value)const{
		if(operation == '+'){
			return source_value + value;
		}
		else if(operation == '-'){
			return source_value - value;
		}
		else if(operation == '*'){
			return source_value * value;
		}
		else{
			return source_value / value;
		}
	}
	void Invert(){
		if(operation == '+'){
			operation = '-';
		}
		else if(operation == '-'){
			operation = '+';
		}
		else if(operation == '*'){
			operation = '/';
		}
		else{
			operation = '*';
		}
	}
private:
	char operation;
	double value;
};

class Function{
public:
	void AddPart(char operation, double value){
		parts.push_back({operation, value});
	}
	double Apply(double value) const{
		for(const FunctionsPart& part: parts){
			value = part.Apply(value);
		}
		return value;
	}
	void Invert(){
		for(FunctionsPart& part: parts){
			part.Invert();
		}
		reverse(begin(parts), end(parts));
	}
private:
	vector<FunctionsPart> parts;
};

/*
Function MakeWeightFucntion(const Params& params, const Image& image){
	Function my_function;
	my_function.AddPart('*', params.a);
	my_function.AddPart('-', image.freshness * params.b);
	my_function.AddPart('+', image.rating * params.c);
	return my_function;

}

double ComputeImageWeight(const Params& params, const Image& image){
	Function my_function = MakeWeightFucntion(params, image);
	return my_function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
		const Image& image, double weight){
	Function my_function = MakeWeightFucntion(params, image);
	my_function.Invert();
	return my_function.Apply(weight);
}


int main() {
	Image image = {10, 2, 6};
	Params params = {4, 2, 6};
	cout << ComputeImageWeight(params, image) << endl;
	cout << ComputeQualityByWeight(params, image, 52) << endl;
	return 0;
}
*/


