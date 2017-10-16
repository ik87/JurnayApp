#pragma once
#include "JourneyList.h"

class WorkWithFile{
	private:
		JournayList jl;
		string fileName;

	public: 
			WorkWithFile(string fileName, JournayList jl);
			bool saveToFile();
			bool loadFromFile();
};