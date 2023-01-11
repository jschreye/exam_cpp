#include "ASpell.hpp"

void ASpell::launch ( ATarget const &target )
{
	target.getHitBySpell(*this);
}
