#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <vector>
#include "ASpell.hpp"
class Warlock
{
private:
	std::string _name;
	std::string _title;
	std::vector<ASpell*> _spells;

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
		std::vector<ASpell*>::iterator ite = _spells.end();
		for(std::vector<ASpell*>::iterator it = _spells.begin(); it != ite; ++it)
		{
			delete (*it);
		}
		_spells.clear();
		std::cout << this->_name  << ": My job here is done!" << std::endl;
	}
	void learnSpell(const ASpell *spell)
	{
		if (spell)
		{
			std::vector<ASpell*>::iterator ite = _spells.end();
			for(std::vector<ASpell*>::iterator it = _spells.begin(); it != ite; ++it)
			{
				if ((*it)->getName() == spell->getName())
					return ;
			}
			_spells.push_back(spell->clone());
		}
	}
	void forgetSpell(const std::string sort)
	{
		std::vector<ASpell*>::iterator ite = _spells.end();
		for(std::vector<ASpell*>::iterator it = _spells.begin(); it != ite; ++it)
		{
			if ((*it)->getName() == sort)
			{
				delete(*it);
				it = this->_spells.erase(it);
			}
		}
	}
	void launchSpell(const std::string sort, const ATarget &target)
	{
		std::vector<ASpell*>::iterator ite = _spells.end();
		for(std::vector<ASpell*>::iterator it = _spells.begin(); it != ite; ++it)
		{
			if ((*it)->getName() == sort)
			{
				(*it)->launch(target);
				return ;
			}
		}
	}
};

#endif
