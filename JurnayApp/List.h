#pragma once
#include <string>
using std::string;

class List{
	private:
		string country;
		string days;
		string date;
		string transport;
		string cost;

	public:
		List(string country, string date, string transport, string cost, string days);
		List();
		string getCountry();
		string getDays();
		string getDate();
		string getTrasnport();
		string getCost();
		void setDate(string date);
		void setTransport(string transport);
		void setCost(string cost);
		void setCountry(string country);
		void setDays(string days);

};