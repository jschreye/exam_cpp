#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include "ASpell.hpp"
#include <vector>
#include <iostream>
class SpellBook
{
	private:
		std::vector<ASpell*> _book;

		SpellBook(SpellBook const &copy);
		SpellBook &operator=(SpellBook const &rhs);

    public:

        SpellBook(){}
        virtual ~SpellBook()
        {
           	std::vector<ASpell*>::iterator ite = _book.end();
            for(std::vector<ASpell*>::iterator it = _book.begin(); it != ite; ++it)
            {
                delete (*it);
            }
            _book.clear(); 
        }
        void learnSpell(ASpell * spell)
        {
            if (spell)
            {
                std::vector<ASpell*>::iterator ite = _book.end();
                for(std::vector<ASpell*>::iterator it = _book.begin(); it != ite; ++it)
                {
                    if ((*it)->getName() == spell->getName())
                        return ;
                }
                _book.push_back(spell->clone());
            }
        }
        void forgetSpell(std::string const &sort)
        {
            std::vector<ASpell*>::iterator ite = _book.end();
            for(std::vector<ASpell*>::iterator it = _book.begin(); it != ite; ++it)
            {
                if ((*it)->getName() == sort)
                {
                    delete(*it);
                    it = this->_book.erase(it);
                }
            }
        }
        ASpell* createSpell(std::string const &sort)
        {
            std::vector<ASpell*>::iterator ite = _book.end();
            for(std::vector<ASpell*>::iterator it = _book.begin(); it != ite; ++it)
            {
                if ((*it)->getName() == sort)
                {
                    return ((*it));
                }
            }
            return (NULL);
        }
};

#endif