// BankApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "FileManager.h"
#include <iostream>
#include "Bank.h"
int main()
{
	
	std::unique_ptr<Bank> itSchoolBank = std::make_unique <Bank>();
	if(itSchoolBank->autentificare())
	{

		bool isRunnning = true;
		do
		{
			system("CLS");
			std::cout << "Meniu Principal\n";
			std::cout << "1 -> Adaugare Cont\n";
			std::cout << "2 -> Vizualizare Conturi\n";
			std::cout << "3 -> Modificare Conturi\n";
			std::cout << "4 -> Creare cont admin\n";
			std::cout << "9 ->Exit\n";
			std::cout << "Introduceti optiunea dorita: \n";
			char optiune;
			std::cin >> optiune;
			switch (optiune)
			{
			case'1':
				system("CLS");
				itSchoolBank->adaugareCont();
				break;
			case'2':
				system("CLS");
				itSchoolBank->vizualizareConturi();
				break;
			case'3':
				system("CLS");
				itSchoolBank->modificareCont();
				break;
			case'4':
				system("CLS");
				itSchoolBank->creareContAdmin();
				break;
			case'9':
				system("CLS");
				std::cout << "Thank you\n";
				isRunnning = false;
				break;
			default:
				std::cout << "Optiunea nu este valida\n";

				break;
			}
		} while (isRunnning);

	}


	

}

