#pragma once
#include "ContBancar.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <windows.h>
class Bank
{
	std::vector <ContBancar*> m_ConturiBancare;
	std::string createIban();
public:
	Bank();
	~Bank();
	void adaugareCont();
	void vizualizareConturi();
	void modificareCont();

};

