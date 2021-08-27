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
	static FileManager* instanta;
	FileManager();
public:
	void setAttributes(ContBancar* contCurent);
	~FileManager();
	void writeData(ContBancar* contCurent);
	void readData();
	ContBancar* getConturi(int index);
	inline int dimensiuneData() { return conturiData.size(); };
	static FileManager* getInstanta();
	

};

