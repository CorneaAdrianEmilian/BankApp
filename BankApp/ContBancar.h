#pragma once
#include <string>
enum class Tip_Cont
{
	CONT_Ron,
	CONT_Euro,
	CONT_Dolar
};

class ContBancar
{
	std::string nume;
	std::string prenume;
	int sold;
	Tip_Cont eTipCont;
	std::string IBAN;
public:
	ContBancar(std::string nume, std::string prenume, std::string iban);
	~ContBancar();
};

