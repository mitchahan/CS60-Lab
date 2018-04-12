#include <iostream>
using namespace std;

class Rational {
	public:
		int getNum() {
			return num;
		}
		
		int getDenom() {
			return denom;
		}
		
		Rational() {
			num = 0;
			denom = 0;
		}
		
		Rational(int n, int d) {
			num = n;
			denom = d;
		}
		
		void operator +=(Rational rhs) {
			num = (num * rhs.getDenom()) + (rhs.getNum() * denom);
			denom = denom * rhs.getDenom();
		}
		
		void reduce();
	private:
		int num, denom;	
};

Rational operator *(Rational lhs, Rational rhs);
Rational operator +(Rational lhs, Rational rhs);
Rational operator -(Rational lhs, Rational rhs);
bool operator ==(Rational lhs, Rational rhs);
bool operator <(Rational lhs, Rational rhs);
bool operator >(Rational lhs, Rational rhs);

int main() {
	Rational r1(4, 3);
	Rational r2(1, 2);
	
	Rational r3;
	r3 = r1 * r2;
	Rational r4;
	r4 = r1 + r2;
	bool tf = r1 == r2;
	cout << tf << endl;
	
	//equals
	Rational r5(2, 6);
	Rational r6(1, 3);
	bool tf2 = r5 == r6;
	cout << tf2 << endl;
	
	r5 = r5 + r6;
	cout << r5.getNum() << "/" << r5.getDenom() << endl;
	r1 = r1 - r2;
	cout << r1.getNum() << "/" << r1.getDenom() << endl;
	
	bool tf3 = r1 > r2;
	cout << tf3 << endl;
	bool tf4 = r6 < r1;
	cout << tf4 << endl;
}

Rational operator *(Rational lhs, Rational rhs) {
	Rational r(lhs.getNum() * rhs.getNum(), lhs.getDenom() * rhs.getDenom());
	r.reduce();
	return r;
}

Rational operator +(Rational lhs, Rational rhs) {
	Rational r((lhs.getNum() * rhs.getDenom()) + (rhs.getNum() * lhs.getDenom()), lhs.getDenom() * rhs.getDenom());
	r.reduce();
	return r;
}

Rational operator -(Rational lhs, Rational rhs) {
	Rational r((lhs.getNum() * rhs.getDenom()) - (rhs.getNum() * lhs.getDenom()), lhs.getDenom() * rhs.getDenom());
	r.reduce();
	return r;
}


bool operator ==(Rational lhs, Rational rhs) {
	int one, two;
	one = lhs.getNum() * rhs.getDenom();
	two = rhs.getNum() * lhs.getDenom();
	return one == two;
}

bool operator <(Rational lhs, Rational rhs) {
	int one, two;
	one = lhs.getNum() * rhs.getDenom();
	two = rhs.getNum() * lhs.getDenom();
	return one < two;
}

bool operator >(Rational lhs, Rational rhs) {
	int one, two;
	one = lhs.getNum() * rhs.getDenom();
	two = rhs.getNum() * lhs.getDenom();
	return one > two;
}

void Rational::reduce() {
	for (int i = num * denom; i > 1; i--) {
		if ((num % i == 0) && (denom % i == 0)) {
			denom /= i;
			num /= i;
		}
	}
}