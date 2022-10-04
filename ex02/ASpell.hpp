class ASpell;
#ifndef ASPELL_HPP
#define ASPELL_HPP
#include <iostream>
#include "ATarget.hpp"
#include <string>


class ASpell
{
    public:
        ASpell(){}
        ASpell(const std::string &name, const std::string &effects): _name(name), _effects(effects){}
        ASpell(const ASpell& aspell){*this = aspell;}
        ASpell &operator=(const ASpell &rhs)
        {
            this->_name = rhs._name;
            this->_effects = rhs._effects;
            return (*this);
        }
        virtual ~ASpell(){}

        virtual ASpell *clone() const = 0;

        const std::string &getName()const {return this->_name;}
        const std::string &getEffects() const {return this->_effects;}

        void launch(const ATarget &atarget) const;

    private:
            std::string _name;
            std::string _effects;
};

#endif