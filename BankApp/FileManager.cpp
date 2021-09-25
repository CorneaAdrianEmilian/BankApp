#include "FileManager.h"
std::shared_ptr<FileManager> FileManager::instanta = nullptr;
FileManager::FileManager() 
{
};

void FileManager::setAttributes(std::shared_ptr<ContBancar> contCurent)
{
	nume = contCurent->getNume();
	prenume = contCurent->getPrenume();
	iban = contCurent->getIban();
}

FileManager::~FileManager()
{
	conturiData.clear();
}

void FileManager::writeData(std::shared_ptr<ContBancar> contCurent)
{
	std::ofstream myFile("ConturiBancare.csv", std::ios::app);
	//myFile << "Nume " << "Prenume " << "IBAN\n";
	myFile <<contCurent->getNume()<<' ' << contCurent->getPrenume()<<' ' << contCurent->getIban() << std::endl;
	myFile.close();
}
void FileManager::overwriteFile(std::vector<std::shared_ptr<ContBancar>> conturi)
{
	std::vector <std::shared_ptr<ContBancar>>::iterator it;
	std::ofstream myfile("ConturiBancare.csv");
	for (it = conturi.begin(); it != conturi.end(); it++)
	{
		myfile << (*it)->getNume() << ' ' << (*it)->getPrenume() << ' ' << (*it)->getIban() << std::endl;

	}
	myfile.close();
}

void FileManager::readData()
{
	std::ifstream myFile("ConturiBancare.csv");
	while( myFile >>nume >>prenume >>iban)
	{
		std::shared_ptr<ContBancar> cont = std::make_shared <ContBancar>(nume, prenume,iban);
		conturiData.push_back(cont);
	}

}

std::shared_ptr<ContBancar> FileManager::getConturi(int index)
{
	return conturiData.at(index);
}

std::shared_ptr<FileManager> FileManager::getInstanta()
{
	if (instanta != nullptr) {
		return instanta;
	}
	else {
		instanta = std::make_unique<FileManager>();
		return instanta;
	}
}


