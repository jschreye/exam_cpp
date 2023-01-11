#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <iostream>
#include <string>
class ASpell;
#include "ATarget.hpp"

class ASpell {

	protected:
		std::string _name;
		std::string _effects;

		ASpell();

	public:
		ASpell ( std::string name, std::string effects ): _name(name), _effects(effects) {}
		ASpell ( ASpell const &copy ): _name(copy._name), _effects(copy._effects) {}
		virtual ~ASpell(){}

		ASpell &operator=(ASpell const &right)
		{
			if (&right != this)
			{
				this->_name = right._name;
				this->_effects = right._effects;
			}
			return (*this);
		}

		const std::string &getName() const {return this->_name;}
		const std::string &getEffects() const {return this->_effects;}

		virtual ASpell *clone () const = 0;

		void launch (ATarget const &target);
};

#endif
