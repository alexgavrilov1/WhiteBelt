#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <exception>

using namespace std;

int NOD(int a, int b){
	while(a > 0 && b > 0){
		if(a > b){
			a %= b;
		}
		else{
			b %= a;
		}
	}
	return a + b;
}


class Rational {
public:
    Rational() {
        p = 0;
        q = 1;// Реализуйте конструктор по умолчанию
    }

    Rational(int numerator, int denominator) {

    	if(denominator == 0){
    		throw invalid_argument("");
    	}

    	if(numerator == 0){
    		p = 0;
    		q = 1;
    	}
    	else{

			int nod = NOD(abs(numerator), abs(denominator));
			if(denominator < 0){
				p = -numerator / nod;
				q = abs(denominator) / nod;
			}
			else{
				p = numerator / nod;
				q = denominator / nod;
			}
    	}
        // Реализуйте конструктор
    }

    int Numerator() const {
        return p;// Реализуйте этот метод
    }

    int Denominator() const {
        return q;// Реализуйте этот метод
    }

private:
    int p;
    int q;// Добавьте поля
};

bool operator==(const Rational& left, const Rational& right){
	return (left.Numerator() == right.Numerator()) &&
			(left.Denominator() == right.Denominator());


}

Rational operator+(const Rational& left, const Rational& right){
	return Rational{left.Numerator() * right.Denominator() + right.Numerator() *
		left.Denominator(), left.Denominator() * right.Denominator()};
}

Rational operator-(const Rational& left, const Rational& right){
	return Rational{left.Numerator() * right.Denominator() - right.Numerator() *
		left.Denominator(), left.Denominator() * right.Denominator()};
}

Rational operator*(const Rational& left, const Rational& right){
	return Rational{left.Numerator() * right.Numerator(), left.Denominator() * right.Denominator()};
}

Rational operator/(const Rational& left, const Rational& right){
	if(right.Numerator() == 0){
		throw domain_error("");
	}
	return Rational{left.Numerator() * right.Denominator(), left.Denominator() * right.Numerator()};
}

ostream& operator<<(ostream& stream, const Rational& r){
	stream << r.Numerator() << "/" << r.Denominator();
	return stream;
}

istream& operator>>(istream& stream, Rational& r){

	char sign;
	int p, q;
	stream >> p;
	stream >> sign;
	if(sign != '/'){
		return stream;
	}
	stream >> q;
	if(stream){
		r = Rational{p, q};
	}
	return stream;
}

bool operator<(const Rational& left, const Rational& right){
	return (left - right).Numerator() < 0;
}


int main() {

	Rational drob1, drob2;
	char operation;
	try{
		cin >> drob1 >> operation >> drob2;
	}
	catch(invalid_argument&){
		cout << "Invalid argument";
		return 0;
	}

	if(operation == '+'){
		cout << drob1 + drob2;
	}
	else if(operation == '-'){
		cout << drob1 - drob2;
	}
	else if(operation == '*'){
		cout << drob1 * drob2;
	}
	else{
		try{
			cout << drob1 / drob2;
		}
		catch(domain_error&){
			cout << "Division by zero";
			return 0;
		}
	}

    return 0;
}
