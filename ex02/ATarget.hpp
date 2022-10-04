class ATarget;
#ifndef ATARGET_HPP
#define ATARGET_HPP
#include <iostream>
#include "ASpell.hpp"

class ATarget
{
    public:
        ATarget() : _type(""){}
        ATarget(const std::string &type): _type(type){}
        ATarget(const ATarget & target)
        {
            *this = target;
        }
        ATarget &operator=(const ATarget &rhs)
        {
            this->_type = rhs._type;
            return (*this);
        }
        virtual ~ATarget(){}

        virtual ATarget *clone() const = 0;

        const std::string &getType() const {return this->_type;}

        void getHitBySpell(const ASpell &aspell) const;

    private:
        std::string _type;
};

#endif