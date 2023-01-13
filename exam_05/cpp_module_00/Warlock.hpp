#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock
{
private:
	std::string _name;
	std::string _title;

	Warlock();
	Warlock &operator=(const Warlock &rhs);

public:
	Warlock(const std::string &name, const std::string &title) : _name(name), _title(title)
	{
		std::cout << this->_name << ": This looks like another boring day." << std::endl;
	}
	const std::string &getName() const { return this->_name; }
	const std::string &getTitle() const { return this->_title; }
	void setTitle(const std::string &title) { this->_title = title; }
	void introduce() const
	{
		std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
	}
	virtual ~Warlock()
	{
		std::cout << this->_name  << ": My job here is done!" << std::endl;
	}

};

#endif
