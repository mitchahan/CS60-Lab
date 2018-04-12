#include <iostream>
#include <string>
#include <ifstream>
#include <cstdl>
using namespace std;

struct Time{//military time, no am/pm
	int hour;
	int minute;
};

Time earlier(Time t1, Time t2);

class Carpool {
public:
	string names[5];
	int num;
	Time t;
	
	Carpool() {
		for (int i = 0; i < 5; i++) {
			names[i] = "";
		}
		num = 0;
		Time time = {-1, -1};
		t = time;
	}
	Carpool(string n[], int nu, Time time) {
		for (int i = 0; i < nu; i++) {
			names[i] = n[i];
		}
		num = nu;
		t = time;
	}
	Carpool combineCarpool(Carpool car2);
};

int main() {
	Carpool cars[];
	int c = 0;
	
	ifstream in;
	ofstream out;
	
	in.open();
	
	if (!in.exist()) {
		cout << "File DNE" << endl;
		exit(1);
	}
	
	while (in >> cars[c].num) {
		for () {
			
		}
		in >> 
	}

	Carpool combine = car1.combineCarpool(car2);
	
	for (int x = 0; x < 4; x++) {
		cout << combine.names[x] << " ";
	}
	cout << " " << combine.num << " " << combine.t.hour << ":" << combine.t.minute << endl;
	return 0;
}


Time earlier(Time t1, Time t2){
    Time ret;
    if(t1.hour == t2.hour){
        if(t1.minute<t2.minute)
            ret = t1;
        else
            ret = t2;
    }
    else if(t1.hour<t2.hour){
        ret = t1;
    }
    else{
        ret = t2;
    }
    return ret;
}

Carpool Carpool::combineCarpool(Carpool car2) {
		Carpool car;
		if (num + car2.num <= 5) {
			car.num = num + car2.num;
			for (int x = 0; x < num; x++) {
				car.names[x] = names[x];
			}
			int i = 0;
			for (int y = num; y < car2.num + num; y++) {
				car.names[y] = car2.names[i];
				i++;
			}
			car.t = earlier(t, car2.t);
		} else {
			car.num = 0;
		}
		return car;
	}