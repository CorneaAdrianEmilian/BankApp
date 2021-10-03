#include "LogIn.h"

std::shared_ptr<LogIn>LogIn::instanta = nullptr;
LogIn::LogIn()
{
}


LogIn::~LogIn()
{
	conturiAdmin.clear();
}

std::shared_ptr<LogIn> LogIn::getInstanta()
{
	if(instanta != nullptr) {
		return instanta;
	}
	else
	{
		std::unique_ptr<LogIn> temp(new LogIn);
		instanta = std::move(temp);
		return instanta;
	}
}

std::shared_ptr<ContAdmin> LogIn::getConturi(int index)
{
	return conturiAdmin.at(index);
}


void LogIn::writeFile(std::shared_ptr<ContAdmin> cont)
{
	std::ofstream myfile("ConturiAdministratori",std::ios::app);
	myfile << cont->getUserName() << ' ' << cont->getPassword() << std::endl;
	myfile.close();
}

void LogIn::overwriteFile(std::vector<std::shared_ptr<ContAdmin>> conturi)
{
	std::vector <std::shared_ptr<ContAdmin>>::iterator it;
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
		std::shared_ptr<ContAdmin> cont = std::make_shared <ContAdmin>(nume, parola);
		conturiAdmin.push_back(cont);
	}
}
