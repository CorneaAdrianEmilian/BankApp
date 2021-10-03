#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "ContAdmin.h"
class LogIn
{
private:
	std::vector <std::shared_ptr<ContAdmin>> conturiAdmin;
	static std::shared_ptr<LogIn> instanta;
	LogIn();
public:
	~LogIn();
	std::shared_ptr<ContAdmin> getConturi(int index);
	inline int dimensiuneData() { return conturiAdmin.size(); };
	void writeFile(std::shared_ptr<ContAdmin> cont);
	void overwriteFile(std::vector <std::shared_ptr<ContAdmin>> conturi);
	void readFile();
	static std::shared_ptr<LogIn> getInstanta();
};


