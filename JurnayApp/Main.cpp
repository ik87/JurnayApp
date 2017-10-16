#include <iostream>
#include "Db.h"
#include "List.h"
#include <iomanip>
/* http://www.cyberforum.ru/cpp-beginners/thread2082549.html */

using namespace std;
void writeToFile(string filename);
void readFromFile(string filename);
int main() {
	string filename = "name.txt";
	string tmp;
	while (true) {
		cout << "What would you like to do? (R)ead or (W)rite file. Q - exit?: ";
		cin >> tmp;
		cin.get();
		if (tmp.length() == 1) {
			if (tmp.at(0) == 'R' || tmp.at(0) == 'r')
				readFromFile(filename);
			else if (tmp.at(0) == 'W' || tmp.at(0) == 'w')
				writeToFile(filename);
			else if (tmp.at(0) == 'Q' || tmp.at(0) == 'q')
				exit(0);
		}
	}

	return 0;
}

void writeToFile(string filename) {
	bool flag1 = true;
	do {
		List list;
		string tmp;
		cout << "Enter country: " << endl;
		cin >> tmp;
		list.setCountry(tmp);
		cout << "Enter num days" << endl;
		cin >> tmp;
		list.setDays(tmp);
		cout << "Enter date(ddmmyyyy): " << endl;
		cin >> tmp;
		list.setDate(tmp);
		cout << "Enter transport: " << endl;
		cin >> tmp;
		list.setTransport(tmp);
		cout << "Enter cost: " << endl;
		cin >> tmp;
		list.setCost(tmp);
		while (true) {
			cout << "Enter else ? (Y/N)" << endl;
			cin >> tmp;
			cin.get();
			if (tmp.length() == 1) {
				if (tmp.at(0) == 'y' || tmp.at(0) == 'Y') {
					break;
				}
				else if (tmp.at(0) == 'n' || tmp.at(0) == 'N')
				{
					flag1 = false;
					break;
				}
			}
			system("cls");
		}
		Db::saveToFile(filename, list);
	} while (flag1);
}

void readFromFile(string filename) {
	vector<List> list = Db::loadFromFile(filename);
	vector<List>::iterator v = list.begin();
		cout << "Country:" 
		<< setw(20) << std::right << "Days:"
		<< setw(20) << std::right << "Date:"
		<< setw(20) << std::right << "Transport:"
		<< setw(20) << std::right << "Cost:" << endl;
	while (v != list.end())	{
		cout << v->getCountry() 
		<< setw(20) << std::right << v->getDays()
		<< setw(20) << std::right << v->getDate()
		<< setw(20) << std::right << v->getTrasnport()
		<< setw(20) << std::right << v->getCost() << endl;
		v++;
	}
}