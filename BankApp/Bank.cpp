#include "Bank.h"

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
}

Bank::~Bank()
{
	m_ConturiBancare.clear();
}

void Bank::adaugareCont()
{
	system("CLS");
	std::cout << "Introduceti numele utilizatorului: " << std::endl;
	std::string nume;
	std::cin >> nume;
	std::cout << "Introduceti prenumele utilizatorului: " << std::endl;
	std::string prenume;
	std::cin >> prenume;
	std::string iban = createIban();
	ContBancar* cont = new ContBancar(nume, prenume, iban);
	m_ConturiBancare.push_back(cont);
	std::cout << "1 -> Crearea a unui cont\n";
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
	std::cout << "Numarul de conturi in banca este: " <<m_ConturiBancare.size()<< std::endl;
	for(int i=0; i<m_ConturiBancare.size();i++)
	{
		std::cout << "Contul " << i + 1 << " " << m_ConturiBancare[i]->getNume() << std::endl;

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
	ContBancar* temp=nullptr ;
	int foundIndex = 0;
	/*for (int i=0;i< m_ConturiBancare.size();i++)
	{
		if (nume == m_ConturiBancare[i]->getNume() && prenume == m_ConturiBancare[i]->getPrenume())
		{
			foundIndex = i;
			temp = m_ConturiBancare[i];
			break;
		}

	}*/
	std::vector <ContBancar*>::iterator it;
	for (it= m_ConturiBancare.begin(); it != m_ConturiBancare.end(); it++)
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

		switch(optiune)
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
		std::cout << "Ce modificari doriti sa faceti?";
		m_ConturiBancare.erase(it);
	}
}

