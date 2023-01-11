#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <string>
#include <vector>
class Warlock;
#include "ATarget.hpp"
#include "ASpell.hpp"

class Warlock {

	private:
		std::string _name;
		std::string _title;
		std::vector<ASpell*> _spells;

		Warlock();
		Warlock(Warlock const &copy);
		Warlock &operator=(Warlock const &right);

	public:
		Warlock(std::string name, std::string title): _name(name), _title(title)
		{
			std::cout << this->_name << ": This looks like another boring day." << std::endl;
		}
		virtual ~Warlock ()
		{
			std::cout << this->_name << ": My job here is done!" << std::endl;
			std::vector<ASpell*>::iterator ite = this->_spells.end();
			for (std::vector<ASpell*>::iterator it = this->_spells.begin(); it != ite; ++it ) 
			{
				delete (*it);
			}
			this->_spells.clear();
		}

		const std::string &getName() const {return this->_name;}
		const std::string &getTitle() const {return this->_title;}

		void setTitle (std::string const &title) 
		{
			this->_title = title;
		}

		void introduce () const 
		{
			std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
		}

	void learnSpell (ASpell *spell) 
	{
		if (spell) 
		{
			std::vector<ASpell*>::iterator ite = this->_spells.end();
			for (std::vector<ASpell*>::iterator it = this->_spells.begin(); it != ite; ++it) {
				if ((*it)->getName() == spell->getName())
					return ;
			}
			this->_spells.push_back(spell->clone());
		}
	}

	void forgetSpell (std::string name) 
	{
		std::vector<ASpell*>::iterator ite = this->_spells.end();
		for (std::vector<ASpell*>::iterator it = this->_spells.begin(); it != ite; ++it) 
		{
			if ((*it)->getName() == name)
			{
				delete (*it);
				it = this->_spells.erase(it);
			}
		}

	}

	void launchSpell (std::string name, ATarget &target)
	{
		std::vector<ASpell*>::iterator ite = this->_spells.end();
		for (std::vector<ASpell*>::iterator it = this->_spells.begin(); it != ite; ++it)
		{
			if ((*it)->getName() == name)
			{
				(*it)->launch(target);
				return ;
			}
		}
	}

};

#endif