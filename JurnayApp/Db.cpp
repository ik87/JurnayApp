#include "Db.h"


void Db::saveToFile(string filename, List list) {
	std::ofstream outfile;

	outfile.open(filename,std::ios::app);

	outfile << list.getCountry() << '\t' << list.getDays() << '\t' << list.getDate()
		<< '\t' << list.getTrasnport() << '\t' << list.getCost() << std::endl;

	outfile.close();
}

std::vector<List> Db::loadFromFile(string filename) {
	std::vector<List> list;
	std::ifstream infile;
	infile.open(filename, std::ios::in);
	List *tmpList = new List();
	char ch;
	int tabs = 0;
	string tmp = "";
	while (!infile.eof())
	{
		infile.get(ch);

		if (ch != '\t' && ch != '\n') {
			tmp.push_back(ch);
		}

		else {
			if (ch == '\n') {
				list.push_back(*tmpList);
				tabs = 0;
			} 
			switch (tabs)
			{
				case 0: tmpList->setCountry(tmp); break;
				case 1: tmpList->setDays(tmp); break;
				case 2: tmpList->setDate(tmp);break;
				case 3: tmpList->setTransport(tmp);break;
				case 4: tmpList->setCost(tmp);break;
			}
			tmp = "";
			tabs++;
		}

	}
	
	infile.close();

	return list;
}