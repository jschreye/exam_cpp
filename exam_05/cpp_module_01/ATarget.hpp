#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <iostream>
#include <string>
class ATarget;
#include "ASpell.hpp"

class ATarget {

	protected:
		std::string _type;

		ATarget();

	public:
		ATarget (std::string type): _type(type) {}
		ATarget (ATarget const &copy): _type(copy._type) {}
		virtual ~ATarget(){}

		ATarget &operator=(ATarget const &right)
		{
			if (&right != this)
				this->_type = right._type;
			return (*this);
		}

		const std::string &getType() const {return this->_type;}

		void getHitBySpell(ASpell const &spell) const;

		virtual ATarget *clone () const = 0;
};

#endif
