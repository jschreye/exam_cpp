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

    public:

        ATarget(const std::string type): _type(type){}
        ATarget(const ATarget &rhs): _type(rhs._type){}
        ATarget &operator=(const ATarget &rhs)
        {
            if (&rhs != this)
            {
                _type = rhs._type;
            }
            return (*this);
        }
        virtual ~ATarget(){}
        const std::string &getType() const
        {
            return (this->_type);
        }
        virtual ATarget *clone() const = 0;

        void getHitBySpell(const ASpell &spell) const;
};

#endif