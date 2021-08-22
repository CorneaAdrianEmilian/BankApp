#include "FileManager.h"

FileManager::FileManager()
{
}

FileManager::FileManager(ContBancar* contCurent)
{
	nume = contCurent->getNume();
	prenume = contCurent->getPrenume();
	iban = contCurent->getIban();
}

FileManager::~FileManager()
{
	conturiData.clear();
}

void FileManager::writeData()
{
	std::ofstream myFile("ConturiBancare.csv");
	//myFile << "Nume " << "Prenume " << "IBAN\n";
	myFile << nume<<' ' << prenume<<' ' << iban << std::endl;
	myFile.close();
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