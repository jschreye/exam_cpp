#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include "ASpell.hpp"
#include "ATarget.hpp"
#include <string>
#include <iostream>

class SpellBook
{
    private:

        std::vector<ASpell*> _spells;
        SpellBook(const SpellBook &rhs);
        SpellBook &operator=(const SpellBook &rhs);

    public:

        SpellBook(){}
        virtual ~SpellBook()
        {
            std::vector<ASpell*>::iterator ite = _spells.end();
            for(std::vector<ASpell*>::iterator it = _spells.begin(); it != ite; ++it)
            {
                delete (*it);
            }
            _spells.clear();   
        }

        void learnSpell(const ASpell *spell)
        {
            if (spell)
            {
                std::vector<ASpell*>::iterator ite = _spells.end();
                for(std::vector<ASpell*>::iterator it = _spells.begin(); it != ite; ++it)
                {
                    if ((*it)->getName() == spell->getName())
                    {
                        return ;
                    }
                }               
                this->_spells.push_back(spell->clone()); 
            }
        }
        void forgetSpell(const std::string &sort)
        {
            std::vector<ASpell*>::iterator ite = _spells.end();
            for(std::vector<ASpell*>::iterator it = _spells.begin(); it != ite; ++it)
            {
                if ((*it)->getName() == sort)
                {
                    delete(*it);
                    it = this->_spells.erase(it);
                }
            } 
            return ;            
        }
        ASpell* createSpell(const std::string &sort)
        {
            std::vector<ASpell*>::iterator ite = _spells.end();
            for(std::vector<ASpell*>::iterator it = _spells.begin(); it != ite; ++it)
            {
                if ((*it)->getName() == sort)
                {
                    return (*it);
                }
            }
            return NULL;
        }
};

#endif