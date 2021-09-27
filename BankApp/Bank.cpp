#include "Bank.h"
void Bank::creareContAdmin()
{
	system("CLS");
	bool creare = true;
	std::string nume;
	std::cout << "Creare cont admin\n";
	while (creare)
	{
		std::cout << "Introduceti username-ul:\nIntre 3 si 16 caractere alphanumerice:\n";
		std::cin >> nume;
		int caractere = 0;
		if (nume.size() < 2 && nume.size() > 17) {
			std::cout << "Username-ul nu are numarul necesar de caractere\n";
			Sleep(1000);
			system("CLS");
			continue;
		}
		for (int i = 0; i < nume.size(); i++)
		{
			if (nume.at(i) > 64 && nume.at(i) < 91)
				caractere++;
			if (nume.at(i) > 96 && nume.at(i) < 123)
				caractere++;
			if (nume.at(i) > 47 && nume.at(i) < 58)
				caractere++;
		}
		if (caractere == nume.size())
			creare = false;
		else {
			std::cout << "Creare cont esuata\n";
			Sleep(1000);
			system("CLS");
		}
	}
	creare = true;
	int literaMare = 0;
	int caracterS = 0;
	int literaMica = 0;
	std::string parola;
	while (creare)
	{
		std::cout << "Introduceti parola: intre 3-16 caractere alphanumerice,";
		std::cout << " minim o litera mare si un caracter special\n";
		// 3- 16 caracatere, alphanumerice, o litera mare, 1 caracter special
		std::cin >> parola;
		if (parola.size() < 2 && parola.size() > 17) {
			std::cout << "Parola nu are numarul necesar de caractere\n";
			Sleep(1000);
			system("CLS");
			continue;
		}
		for (int i = 0; i < parola.size(); i++)
		{
			if (parola.at(i) > 64 && parola.at(i) < 91)
				literaMare++;
			if (parola.at(i) > 96 && parola.at(i) < 123)
				literaMica++;
			if (parola.at(i) > 32 && parola.at(i) < 48)
				caracterS++;
			if (parola.at(i) > 57 && parola.at(i) < 65)
				caracterS++;
			if (parola.at(i) > 90 && parola.at(i) < 97)
				caracterS++;

			if (literaMare >= 1 && literaMica >= 1 && caracterS >= 1) {
				std::cout << "Cont creat cu succes\n";
				Sleep(1000);
				creare = false;
				break;
			}
		}
		if (creare) {
			std::cout << "Creare cont esuata\n";
			Sleep(1000);
			system("CLS");
		}
	}
	ContAdmin* cont = new ContAdmin(nume, parola);
	dataAdmin->writeFile(cont);
	m_ConturiAdmin.push_back(cont);

	std::cout << "1 -> Crearea a unui cont\n";
	std::cout << "2 -> Meniu principal\n";
	char optiune;
	std::cin >> optiune;
	switch (optiune)
	{
	case '1':
		system("CLS");
		creareContAdmin();
		break;
	default:
		system("CLS");
		break;
	}
}

bool Bank::autentificare()
{
	std::string nume, parola;
	for (int i = 3; i != 0; i--)
	{
		std::cout << "Autentificare cont\nIncercari ramase:" << i << std::endl;
		std::cout << "Introduceti username-ul:\n";
		std::cin >> nume;
		std::vector <ContAdmin*>::iterator it;
		for (it = m_ConturiAdmin.begin(); it != m_ConturiAdmin.end(); it++)
		{
			if (nume == (*it)->getUserName())
			{
				std::cout << "Introduceti parola:\n";
				std::cin >> parola;
				if (parola == (*it)->getPassword())
				{
					std::cout << "Te-ai autentificat cu succes\n";
					Sleep(1500);
					return true;
				}
				break;
			}
		}
		std::cout << "Introduceti parola:\n";
		std::string temp;
		std::cin >> temp;
		std::cout << "Autentificare esuata\n";
		Sleep(1500);
		system("CLS");
	}

	return false;
}


std::string Bank::createIban()
{
	std::string iban = "RO";
	for (int i = 0; i < 2; i++)
	{
		int temp = 0;
		srand(time(0) + i);
		temp = rand() % 9 + i;
		iban += std::to_string(temp);
	}
	iban += "BANK";
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 5; i++)
		{
			int temp = 0;
			srand(time(0) + i + k);
			temp = rand() % 9;
			iban += std::to_string(temp);
		}
	}
	return iban;
}

Bank::Bank()
{
	dataAdmin->readFile();
	if (dataAdmin->dimensiuneData() > 0)
	{
		for (int i = 0; i < dataAdmin->dimensiuneData(); i++)
		{
			m_ConturiAdmin.push_back(dataAdmin->getConturi(i));
		}

	}
	else
		creareContAdmin();

	data->readData();
	if (data->dimensiuneData() > 0)
	{
		for (int i = 0; i < data->dimensiuneData(); i++)
		{
			m_ConturiBancare.push_back(data->getConturi(i));
		}
	}

}
Bank::~Bank()
{
	m_ConturiBancare.clear();
	//delete data;
	delete dataAdmin;
}

void Bank::modificareSold(std::vector <std::shared_ptr<ContBancar>>::iterator iterator)
{
	int new_sold;
	std::cout << "Introduceti noul sold:\n";
	std::cin >> new_sold;
	(*iterator)->setSoldValue(new_sold);
}

void Bank::modificareNume(std::vector <std::shared_ptr<ContBancar>>::iterator iterator)
{
	system("CLS");
	bool creare = true;
	std::string nume;

	std::cout << "Modificare nume:\n";
	while (creare)
	{
		std::cout << "Introduceti numele\nIntre 3 si 16 caractere alfabetice:\n";
		std::cin >> nume;
		int caractere = 0;
		if (nume.size() < 2 && nume.size() > 17) {
			std::cout << "Numele nu are numarul necesar de caractere\n";
			Sleep(1000);
			system("CLS");
			continue;
		}
		for (int i = 0; i < nume.size(); i++)
		{
			if (nume.at(i) > 64 && nume.at(i) < 91)
				caractere++;
			if (nume.at(i) > 96 && nume.at(i) < 123)
				caractere++;
		}
		if (caractere == nume.size())
			creare = false;
		else {
			std::cout << "Modificare nume esuata\n";
			Sleep(1000);
			system("CLS");
		}
	}
	std::cout << "Modificare reusita\n" << std::endl;
	Sleep(1000);
	(*iterator)->setNume(nume);
}
void Bank::modificarePrenume(std::vector <std::shared_ptr<ContBancar>>::iterator iterator)
{
	system("CLS");
	bool creare = true;
	std::string prenume;
	while (creare)
	{
		std::cout << "Introduceti prenumele\nIntre 3 si 16 caractere alfabetice:\n";
		std::cin >> prenume;
		int caractere = 0;
		if (prenume.size() < 2 && prenume.size() > 17) {
			std::cout << "Prenumele nu are numarul necesar de caractere\n";
			Sleep(1000);
			system("CLS");
			continue;
		}
		for (int i = 0; i < prenume.size(); i++)
		{
			if (prenume.at(i) > 64 && prenume.at(i) < 91)
				caractere++;
			if (prenume.at(i) > 96 && prenume.at(i) < 123)
				caractere++;
		}
		if (caractere == prenume.size())
			creare = false;
		else {
			std::cout << "Modificare esuata\n";
			Sleep(1000);
			system("CLS");
		}
	}
	std::cout << "Modificare prenume reusita\n";
	Sleep(1000);
	(*iterator)->setPrenume(prenume);
}

void Bank::adaugareCont()
{
	system("CLS");
	bool creare = true;
	std::string nume;

	std::cout << "Creare cont:\n";
	while (creare)
	{
		std::cout << "Introduceti numele\nIntre 3 si 16 caractere alfabetice:\n";
		std::cin >> nume;
		int caractere = 0;
		if (nume.size() < 2 && nume.size() > 17) {
			std::cout << "Numele nu are numarul necesar de caractere\n";
			Sleep(1000);
			system("CLS");
			continue;
		}
		for (int i = 0; i < nume.size(); i++)
		{
			if (nume.at(i) > 64 && nume.at(i) < 91)
				caractere++;
			if (nume.at(i) > 96 && nume.at(i) < 123)
				caractere++;
		}
		if (caractere == nume.size())
			creare = false;
		else {
			std::cout << "Creare cont esuata\n";
			Sleep(1000);
			system("CLS");
		}
	}
	creare = true;
	std::string prenume;
	while (creare)
	{
		std::cout << "Introduceti prenumele\nIntre 3 si 16 caractere alfabetice:\n";
		std::cin >> prenume;
		int caractere = 0;
		if (prenume.size() < 2 && prenume.size() > 17) {
			std::cout << "Prenumele nu are numarul necesar de caractere\n";
			Sleep(1000);
			system("CLS");
			continue;
		}
		for (int i = 0; i < prenume.size(); i++)
		{
			if (prenume.at(i) > 64 && prenume.at(i) < 91)
				caractere++;
			if (prenume.at(i) > 96 && prenume.at(i) < 123)
				caractere++;
		}
		if (caractere == prenume.size())
			creare = false;
		else {
			std::cout << "Creare cont esuata\n";
			Sleep(1000);
			system("CLS");
		}
	}
	std::cout << "Creare cont reusita\n";
	std::string iban = createIban();
	std::shared_ptr<ContBancar> cont = std::make_shared<ContBancar>(nume, prenume, createIban());
	m_ConturiBancare.push_back(cont);
	data->writeData(cont);
	std::cout << "1 -> Crearea  unui cont\n";
	std::cout << "2 -> Meniu principal\n";
	char optiune;
	std::cin >> optiune;
	switch (optiune)
	{
	case '1':
		system("CLS");
		adaugareCont();
		break;
	default:
		system("CLS");
		break;
	}
}
void Bank::vizualizareConturi()
{
	system("CLS");
	std::cout << "Numarul de conturi in banca este: " << m_ConturiBancare.size() << std::endl;
	for (int i = 0; i < m_ConturiBancare.size(); i++)
	{
		std::cout << "Contul " << i + 1 << " " << m_ConturiBancare[i]->getNume()
			<< ' ' << m_ConturiBancare[i]->getIban() << std::endl;

	}
	std::cout << "1 -> Revenire la meniul principal\n";
	char temp;
	std::cin >> temp;
	switch (temp)
	{
	default:
		system("CLS");
		break;
	}
}

void Bank::modificareCont()
{
	system("CLS");
	std::cout << "Introduceti numele si prenumele contului\n";
	std::cout << "Introduceti numele de familie:\n";
	std::string nume;
	std::cin >> nume;
	std::cout << "Introduceti prenumele:\n";
	std::string prenume;
	std::cin >> prenume;
	std::shared_ptr<ContBancar> temp = nullptr;
	int foundIndex = 0;
	std::vector <std::shared_ptr<ContBancar>>::iterator it;
	for (it = m_ConturiBancare.begin(); it != m_ConturiBancare.end(); it++)
	{
		if (nume == (*it)->getNume() && prenume == (*it)->getPrenume())
		{

			temp = *it;
			break;
		}
	}


	if (temp == nullptr)
	{
		system("CLS");
		std::cout << "Contul nu a fost gasit\n";
		std::cout << "1-> Reveniti la meniul principal\n";
		std::cout << "2-> Creati un cont\n";
		std::cout << "3-> Cautati un alt cont\n";
		char optiune;
		std::cin >> optiune;

		switch (optiune)
		{
		case '1':
			std::cout << "going back\n";
			break;
		case '2':
			adaugareCont();
			break;
		case'3':
			modificareCont();
			break;
		default:
			break;
		}
	}
	else
	{
		std::cout << "Ce modificari doriti sa faceti?\n";
		std::cout << "1-> Modificare nume\n";
		std::cout << "2-> Modificare prenume\n";
		std::cout << "3-> Modificare sold\n";
		std::cout << "4-> Stergere cont\n";
		std::cout << "5-> Revenire la meniul principal\n";
		char optiune;
		std::cin >> optiune;

		switch (optiune)
		{
		case '1':
			modificareNume(it);
			data->overwriteFile(m_ConturiBancare);
			break;
		case '2':
			modificarePrenume(it);
			data->overwriteFile(m_ConturiBancare);
			break;
		case'3':
			modificareSold(it);
			data->overwriteFile(m_ConturiBancare);
			break;
		case'4':
			m_ConturiBancare.erase(it);
			data->overwriteFile(m_ConturiBancare);
			break;
		default:
			break;
		}
	}
}