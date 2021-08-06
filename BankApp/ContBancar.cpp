#include "ContBancar.h"

ContBancar::ContBancar(std::string nume, std::string prenume, std::string iban)
{
	this->nume = nume;
	this->prenume = prenume;
	IBAN = iban;
	sold = 0;
	eTipCont = Tip_Cont::CONT_Ron;

}

ContBancar::~ContBancar()
{
}
