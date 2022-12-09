#ifndef FWOOSH_HPP
#define FWOOSH_HPP
#include "ASpell.hpp"

class Fwoosh : public ASpell 
{
    public:
        Fwoosh() : ASpell("Fwoosh", "fwooshed"){}
		Fwoosh(const Fwoosh &rhs) : ASpell(rhs){*this = rhs;}
		Fwoosh &operator=(const Fwoosh &rhs){ASpell::operator=(rhs); return *this;}
		virtual ~Fwoosh(){}

		ASpell *clone() const { return new Fwoosh(*this); }
};

#endif