#include "ASpell.hpp"
#include "ATarget.hpp"

void ATarget::getHitBySpell(const ASpell &spell) const
{
    std::cout << this->_type << " has been " << spell.getEffects() << "!" << std::endl;
}