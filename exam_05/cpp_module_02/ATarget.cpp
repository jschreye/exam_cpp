#include "ASpell.hpp"
#include "ATarget.hpp"

void ATarget::getHitBySpell(const ASpell &rhs) const
{
    std::cout << this->_type << " has been " << rhs.getEffects() << "!" << std::endl;
}