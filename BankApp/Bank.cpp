#include "Bank.h"

std::string Bank::createIban()
{
	std::string iban = "123";
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

