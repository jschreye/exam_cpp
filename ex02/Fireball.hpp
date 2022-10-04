#ifndef FIREBALL_HPP
#define FIREBALL_HPP
#include "ASpell.hpp"

class Fireball : public ASpell 
{
    public:
        Fireball() : ASpell("Fireball", "burnt to a crisp"){}
		Fireball(const Fireball &rhs) : ASpell(rhs){*this = rhs;}
		Fireball &operator=(const Fireball &rhs){ASpell::operator=(rhs); return *this;}
		virtual ~Fireball(){}

		ASpell *clone() const { return new Fireball(*this); }
    private:
};

#endif