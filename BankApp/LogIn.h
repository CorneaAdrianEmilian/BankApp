#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "ContAdmin.h"
class LogIn
{
private:
	std::vector <ContAdmin*> conturiAdmin;
	static LogIn* instanta;
	LogIn();
public:
	~LogIn();
	ContAdmin* getConturi(int index);
	inline int dimensiuneData() { return conturiAdmin.size(); };
	void writeFile(ContAdmin* cont);
	void readFile();
	static LogIn* getInstanta();
};


