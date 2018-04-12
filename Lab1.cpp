#include <iostream>
#include <string>
using namespace std;

struct Time{//military time, no am/pm
	int hour;
	int minute;
};

struct Carpool {
	string names[5];
	int num;
	Time t;
};

Time earlier(Time t1, Time t2);
Carpool combineCarpool(Carpool car1, Carpool car2);

int main() {
	Carpool car1 = {{"J", "M", "A"}, 3, {5, 30}};
	Carpool car2 = {{"B"}, 1, {6, 30}};
	Carpool combine = combineCarpool(car1, car2);
	
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


Carpool combineCarpool(Carpool car1, Carpool car2) {
	Carpool car;
	if (car1.num + car2.num <= 5) {
		car.num = car1.num + car2.num;
		for (int x = 0; x < car1.num; x++) {
			car.names[x] = car1.names[x];
		}
		int i = 0;
		for (int y = car1.num; y < car2.num + car1.num; y++) {
			car.names[y] = car2.names[i];
			i++;
		}
		car.t = earlier(car1.t, car2.t);
	} else {
		car.num = 0;
	}
	return car;
}
