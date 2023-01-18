#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
    private:

        std::string _name;
        std::string _title;
        SpellBook _spells;

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
            this->_spells.learnSpell(spell);
        }
        void forgetSpell(const std::string sort)
        {
            this->_spells.forgetSpell(sort);
        }
        void launchSpell(const std::string sort, ATarget &target)
        {
            const ATarget *test = 0;
            if (test == &target)
                return ;
            ASpell *tmp = _spells.createSpell(sort);
            if (tmp)
                tmp->launch(target);
        }
};
#endif