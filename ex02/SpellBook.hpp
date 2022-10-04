#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <vector>

#include "ASpell.hpp"
#include "ATarget.hpp"

class SpellBook
{
    private:
        std::vector<ASpell*> spells;

        SpellBook(const SpellBook &rhs){*this = rhs;}
        SpellBook &operator=(const SpellBook &rhs)
        {
            for(std::vector<ASpell*>::iterator it(this->spells.begin()); it != this->spells.end(); it++)
                delete (*it);
            spells.clear();
            for(std::vector<ASpell*>::const_iterator it(rhs.spells.begin()); it != rhs.spells.end(); it++)
                spells.push_back((*it)->clone());
            return (*this);
        }
    public:
        SpellBook(){}
        ~SpellBook()
        {
            std::vector<ASpell*>::iterator it (this->spells.begin());
            for(; it != this->spells.end(); it++)
            {
                delete (*it);
            }
            spells.clear();
        }

        void learnSpell(ASpell *s)
        {
            if (!s)
                return ;
            std::vector<ASpell*>::iterator it(this->spells.begin());
            for(; it != this->spells.end(); it++)
            {
                if (s->getName() == (*it)->getName())
                    return ;
            }
            this->spells.push_back(s->clone());
        }

        void forgetSpell(const std::string &s)
        {
            std::vector<ASpell*>::iterator it(this->spells.begin());
            for(; it != this->spells.end();)
            {
                if (s == (*it)->getName())
                {
                    delete (*it);
                    it = spells.erase(it);
                    continue;
                }
                it++;
            }
        }

        ASpell *createSpell(const std::string &s)
        {
            std::vector<ASpell*>::iterator it(this->spells.begin());
            for (; it != this->spells.end(); it++)
            {
                if (s == (*it)->getName())
                    return (*it);
            }
            return (NULL);
        }
};

#endif