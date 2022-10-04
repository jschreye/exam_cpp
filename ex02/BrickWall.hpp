#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP
#include "ATarget.hpp"

class BrickWall : public ATarget 
{
    public:
        BrickWall():ATarget("Inconspicuous Red-brick Wall"){}
		BrickWall(const BrickWall &rhs) : ATarget(rhs){*this = rhs;}
		BrickWall &operator=(const BrickWall &rhs){ATarget::operator=(rhs); return *this;}
		virtual ~BrickWall(){}

		ATarget *clone() const { return new BrickWall(*this); }
        
};

#endif