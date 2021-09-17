#include "LogIn.h"

LogIn* LogIn::instanta = nullptr;
LogIn::LogIn()
{
}


LogIn::~LogIn()
{
	conturiAdmin.clear();
}

LogIn* LogIn::getInstanta()
{
	if(instanta != nullptr) {
		return instanta;
	}
	else
	{
		instanta = new LogIn();
		return instanta;
	}
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

void LogIn::overwriteFile(std::vector<ContAdmin*> conturi)
{
	std::vector <ContAdmin*>::iterator it;
	std::ofstream myfile("ConturiAdministratori");
	for (it = conturi.begin(); it != conturi.end(); it++)
	{
		myfile << (*it)->getUserName() << ' ' << (*it)->getPassword() << std::endl;

	}
	myfile.close();
}

void LogIn::readFile()
{
	std::ifstream myFile("ConturiAdministratori");
	std::string nume;
	std::string parola;
	while(myFile >>nume >>parola)
	{
		ContAdmin* cont = new ContAdmin(nume, parola);
		conturiAdmin.push_back(cont);
	}
}
