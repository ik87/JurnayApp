#include "List.h"

List::List(string country, string date, string transport, string cost, string days) {
	this->country = country;
	this->days = days;
	this->date = date;
	this->transport = transport;
	this->cost = cost;
}
List::List() {}
string List::getCountry() {
	return this->country;
}
string List::getDate() {
	return this->date;
}
string List::getTrasnport() {
	return this->transport;
}
string List::getCost() {
	return this->cost;
}
string List::getDays() {
	return this->days;
}
void List::setCountry(string country) {
	this->country = country;
}
void List::setDate(string date) {
	this->date = date;
}
void List::setTransport(string transport) {
	this->transport = transport;
}
void List::setCost(string cost) {
	this->cost = cost;
}
void List::setDays(string days) {
	this->days = days;
}