#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>
class ATarget;
#include "ASpell.hpp"

class ATarget
{
    protected:
        std::string _type;

        ATarget();
    public :

        ATarget(const std::string type): _type(type){}
        const std::string &getType() const { return this->_type; }
        ATarget &operator=(const ATarget &rhs)
        {
            if (&rhs != this)
                this->_type = rhs._type;
            return (*this);            
        }

        void getHitBySpell(const ASpell &rhs) const;
        virtual ATarget *clone() const = 0;
        virtual ~ATarget(){}
};

#endif