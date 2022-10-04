#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP
#include "ASpell.hpp"

class Polymorph : public ASpell 
{
    public:
        Polymorph() : ASpell("Polymorph", "turned into a critter"){}
		Polymorph(const Polymorph &rhs) : ASpell(rhs){*this = rhs;}
		Polymorph &operator=(const Polymorph &rhs){ASpell::operator=(rhs); return *this;}
		virtual ~Polymorph(){}

		ASpell *clone() const { return new Polymorph(*this); }
    private:
};

#endif