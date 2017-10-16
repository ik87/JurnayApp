#pragma once
#include "List.h"
#include <fstream>
#include <iostream>
#include <vector>

class Db {
	public: 
		static void saveToFile(string filename, List list);
		static std::vector<List> loadFromFile(string filename);
};