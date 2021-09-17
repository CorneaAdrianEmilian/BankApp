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
	inline std::string getNume() { return nume; }
	inline std::string getPrenume() { return prenume; }
	inline int getSold() { return sold; }
	inline std::string getIban() { return IBAN; }
	inline void setSoldValue(int value) { sold = value; } 
	inline void setNume(std::string nou) { nume = nou; }
	inline void setPrenume(std::string nou) { prenume = nou; }


	~ContBancar();
};

