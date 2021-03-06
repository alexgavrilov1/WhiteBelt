#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
#include <set>
#include <map>
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
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
