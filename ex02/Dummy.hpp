#ifndef DUMMY_HPP
#define DUMMY_HPP
#include "ATarget.hpp"

class Dummy : public ATarget 
{
    public:
        Dummy():ATarget("Target Practice Dummy"){}
		Dummy(const Dummy &rhs) : ATarget(rhs){*this = rhs;}
		Dummy &operator=(const Dummy &rhs){ATarget::operator=(rhs); return *this;}
		virtual ~Dummy(){}

		ATarget *clone() const { return new Dummy(*this); }
        
};

#endif