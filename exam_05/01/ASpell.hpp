#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>
class ASpell;
#include "ATarget.hpp"

class ASpell
{
    protected:

        std::string _name;
        std::string _effects;

        ASpell();

    public:

        ASpell(const std::string name, const std::string effects): _name(name), _effects(effects){}
        ASpell(const ASpell &rhs): _name(rhs._name), _effects(rhs._effects){}
        ASpell &operator=(const ASpell &rhs)
        {
            if (&rhs != this)
            {
                _name = rhs._name;
                _effects = rhs._effects;
            }
            return (*this);
        }
        virtual ~ASpell(){}
        const std::string &getName() const
        {
            return (this->_name);
        }
        const std::string &getEffects() const
        {
            return (this->_effects);
        }
        virtual ASpell *clone() const = 0;

        void launch(const ATarget &target) const;
}; 

#endif