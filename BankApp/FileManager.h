#pragma once
#include "ContBancar.h"
#include <fstream>
#include<string>
#include <vector>
#include <memory>
class FileManager
{
	std::string nume;
	std::string prenume;
	std::string iban;
	std::vector<std::shared_ptr<ContBancar>> conturiData;
	FileManager();
	static std::shared_ptr<FileManager> instanta;
public:
	friend std::unique_ptr<FileManager> std::make_unique<FileManager>();
	static std::shared_ptr<FileManager> getInstanta();
	void setAttributes(std::shared_ptr<ContBancar> contCurent);
	~FileManager();
	void writeData(std::shared_ptr<ContBancar> contCurent);
	void readData();
	std::shared_ptr<ContBancar> getConturi(int index);
	inline int dimensiuneData() { return conturiData.size(); };
	void overwriteFile(std::vector <std::shared_ptr<ContBancar>> conturi);


};
