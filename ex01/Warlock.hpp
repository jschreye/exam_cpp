#ifndef WARLOCK_HPP
# define WARLOCK_HPP
#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
    private:
            std::string _name;
            std::string _title;
            std::vector<ASpell*> spells;
            
            Warlock(){}
            Warlock(const Warlock& warlock){*this = warlock;}
            Warlock &operator=(const Warlock &rhs)
            {
                _name = rhs._name;
                _title = rhs._title;

                for(std::vector<ASpell*>::iterator it(this->spells.begin()); it != this->spells.end(); it++)
                    delete (*it);
                spells.clear();
                for(std::vector<ASpell*>::const_iterator it(rhs.spells.begin()); it != rhs.spells.end(); it++)
                    spells.push_back((*it)->clone());
                return *this;
            }
    public:
            Warlock(const std::string &name, const std::string &title): _name(name) , _title(title)
            {
                std::cout << _name << ": This looks like another boring day." << std::endl;
            }
            virtual ~Warlock()
            {
                std::cout << _name << ": My job here is done!" << std::endl;
            }

            const std::string   &getName() const {return this->_name;}
            const std::string   &getTitle() const {return this->_title;}

            void setTitle(const std::string &title){this->_title = title;}

            void	introduce() const 
            {
                std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
            }

            void	learnSpell(ASpell *s)
            {
                if (!s)
                    return ;
                std::vector<ASpell*>::const_iterator it(this->spells.begin());
                for(;it != this->spells.end(); it++)
                {
                    if(s->getName() == (*it)->getName())
                    {
                        return;
                    }
                }
                this->spells.push_back(s);
            }

            void	forgetSpell(const std::string &s)
            {
                std::vector<ASpell*>::iterator it(this->spells.begin());
                for(;it != this->spells.end();)
                {
                    if(s == (*it)->getName())
                    {
                        delete (*it);
                        it = spells.erase(it);
                    }
                    else
                        it++;
                }
            }

            void	launchSpell(const std::string &s, const ATarget &target) const
            {
                std::vector<ASpell*>::const_iterator it(this->spells.begin());
                for(;it != this->spells.end(); it++)
                {
                    if(s == (*it)->getName())
                    {
                        (*it)->launch(target);
                    }
                }
            }
            
};

#endif