//creating a program to determine the charges by weight of a package for 500 miles shipped

#include <iostream>
using namespace std;


double calculatecharges(double weight, int distance) {
	double rate;
	//first we determine the weight of the package 
	//the <= allows for any outcome between the previous maximum and the new maximum to be 
	if (weight <= 2) {
		rate = 1.10;
	}
	else if (weight <= 6) {
		rate = 2.20;
	}
	else if (weight <= 10) {
		rate = 3.70;
	}
	else if(weight <= 20) {
		rate = 4.80;
	}
	else {
		return -1;//for invalid weight which could mean 0 weight or more then 20
	}
	int distance_traveled = (distance + 499) / 500;
	return rate * distance_traveled;
}

//now we create the input area

int main() {
	double weight;
	int distance;

	cout << " Weight of package in kilograms : ";
	cin >> weight;
	if (weight <= 0 || weight > 20) {
	cout << " invalid input---try again chose a weight between 0.01-20 ";
	return 1;
	}
	cout << " Enter how far the package will travel in miles : ";
	cin >> distance;
	if (distance < 10 || distance > 3000) {
		cout << " invlaid distance---please try again and choose a distance between 10 miles and 3000 miles.";
		return 1;
	}
	//now we show the charges and error outcome
	double charges = calculatecharges(weight, distance);
	if (charges == -1) {
		cout << "Error" << endl;
	}
	else {
		cout << "the shipping charges are: $"<<charges<<endl;

	}
	return 0;
}