#pragma once
#include "ContBancar.h"
#include <fstream>
#include<string>
#include <vector>
class FileManager
{
	std::string nume;
	std::string prenume;
	std::string iban;
	std::vector <ContBancar*> conturiData;

public:
	FileManager();
	FileManager(ContBancar* contCurent);
	~FileManager();
	void writeData();
	void readData();
	ContBancar* getConturi(int index);
	inline int dimensiuneData() { return conturiData.size(); };
};

