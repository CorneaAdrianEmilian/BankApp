#pragma once
#include "ContBancar.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "FileManager.h"
#include "LogIn.h"
#include "ContAdmin.h"
class Bank
{
	std::vector <ContAdmin*> m_ConturiAdmin;
	std::vector <std::shared_ptr<ContBancar>> m_ConturiBancare;
	std::string createIban();
	std::shared_ptr<FileManager> data = data->getInstanta();
	LogIn* dataAdmin = dataAdmin->getInstanta();
public:
	Bank();
	~Bank();
	void adaugareCont();
	void vizualizareConturi();
	void modificareCont();
	void creareContAdmin();
	bool autentificare();
	void modificareNume(std::vector <std::shared_ptr<ContBancar>>::iterator iterator);
	void modificarePrenume(std::vector <std::shared_ptr<ContBancar>>::iterator iterator);
	void modificareSold(std::vector <std::shared_ptr<ContBancar>>::iterator iterator);
};

