#include "FileManager.h"

FileManager* FileManager::instanta = nullptr;
FileManager::FileManager() 
{

};

void FileManager::setAttributes(ContBancar* contCurent)
{
	nume = contCurent->getNume();
	prenume = contCurent->getPrenume();
	iban = contCurent->getIban();
}

FileManager::~FileManager()
{
	conturiData.clear();
}

void FileManager::writeData(ContBancar* contCurent)
{
	std::ofstream myFile("ConturiBancare.csv", std::ios::app);
	//myFile << "Nume " << "Prenume " << "IBAN\n";
	myFile <<contCurent->getNume()<<' ' << contCurent->getPrenume()<<' ' << contCurent->getIban() << std::endl;
	myFile.close();
}
void FileManager::overwriteFile(std::vector<ContBancar*> conturi)
{
	std::vector <ContBancar*>::iterator it;
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
		ContBancar* cont = new ContBancar(nume, prenume,iban);
		conturiData.push_back(cont);
	}

}

ContBancar* FileManager::getConturi(int index)
{
	return conturiData.at(index);
}

std::shared_ptr<FileManager> FileManager::getInstanta()
{
	if (instanta != nullptr) {
		return instanta;
	}
	else {
		instanta = new FileManager();
		return instanta;
	}
}


