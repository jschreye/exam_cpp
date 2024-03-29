#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
    private:

        std::string _name;
        std::string _title;
        std::vector<ASpell*> _spells;

        Warlock();
        Warlock(const Warlock &rhs);
        Warlock &operator=(const Warlock &rhs);

    public:

        Warlock(const std::string &name, const std::string &title): _name(name), _title(title)
        {
            std::cout << this->_name << ": This looks like another boring day." << std::endl;
        }
        virtual ~Warlock()
        {
            std::cout << this->_name << ": My job here is done!" << std::endl;
            std::vector<ASpell*>::iterator ite = _spells.end();
            for(std::vector<ASpell*>::iterator it = _spells.begin(); it != ite; ++it)
            {
                delete (*it);
            }
            _spells.clear();
        }
        const std::string &getName() const
        {
            return (this->_name);
        }
        const std::string &getTitle() const
        {
            return (this->_title);
        }
        void setTitle(const std::string &title)
        {
            this->_title = title;
        }
        void introduce() const
        {
            std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
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
        void forgetSpell(const std::string sort)
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
        void launchSpell(const std::string sort, ATarget &target)
        {
            std::vector<ASpell*>::iterator ite = _spells.end();
            for(std::vector<ASpell*>::iterator it = _spells.begin(); it != ite; ++it)
            {
                if ((*it)->getName() == sort)
                {
                    (*it)->launch(target);
                    return ;
                }
            }
            return ;
        }
};
#endif