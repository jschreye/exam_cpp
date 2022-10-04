#include "ATarget.hpp"

void ATarget::getHitBySpell(const ASpell &aspell) const
{
    std::cout << this->_type << " has been " << aspell.getEffects() << "!" << std::endl;
}