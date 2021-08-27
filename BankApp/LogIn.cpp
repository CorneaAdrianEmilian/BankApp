#include "LogIn.h"

LogIn::LogIn()
{
}


LogIn::~LogIn()
{
	conturiAdmin.clear();
}

ContAdmin* LogIn::getConturi(int index)
{
	return conturiAdmin.at(index);
}


void LogIn::writeFile(ContAdmin* cont)
{
	std::ofstream myfile("ConturiAdministratori",std::ios::app);
	myfile << cont->getUserName() << ' ' << cont->getPassword() << std::endl;
	myfile.close();
}

void LogIn::readFile()
{
	std::ifstream myFile;
	std::string nume;
	std::string parola;
	while(myFile >>nume >>parola)
	{
		ContAdmin* cont = new ContAdmin(nume, parola);
		conturiAdmin.push_back(cont);
	}
}
