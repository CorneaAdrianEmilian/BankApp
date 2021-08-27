#pragma once
#include <iostream>
#include <string>
class ContAdmin
{
	std::string userName;
	std::string password;
public:
	ContAdmin(std::string nume,std::string parola);
	~ContAdmin();
	inline std::string getUserName() { return userName; };
	inline std::string getPassword() { return password; };
	inline void setUserName(std::string name) { userName = name; };
	inline void setPassword(std::string pass) { password = pass; };
	
};

