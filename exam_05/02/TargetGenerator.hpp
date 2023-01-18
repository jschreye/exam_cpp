#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include "ASpell.hpp"
#include "ATarget.hpp"
#include <string>
#include <iostream>
#include <vector>

class TargetGenerator
{
    private:

        std::vector<ATarget*> _spells;
        TargetGenerator(const TargetGenerator &rhs);
        TargetGenerator &operator=(const TargetGenerator &rhs);

    public:

        TargetGenerator(){}
        virtual ~TargetGenerator()
        {
            std::vector<ATarget*>::iterator ite = _spells.end();
            for(std::vector<ATarget*>::iterator it = _spells.begin(); it != ite; ++it)
            {
                delete (*it);
            }
            _spells.clear();   
        }

        void learnTargetType(const ATarget *spell)
        {
            if (spell)
            {
                std::vector<ATarget*>::iterator ite = _spells.end();
                for(std::vector<ATarget*>::iterator it = _spells.begin(); it != ite; ++it)
                {
                    if ((*it)->getType() == spell->getType())
                    {
                        return ;
                    }
                }               
                this->_spells.push_back(spell->clone()); 
            }
        }
        void forgetTargetType(const std::string &sort)
        {
            std::vector<ATarget*>::iterator ite = _spells.end();
            for(std::vector<ATarget*>::iterator it = _spells.begin(); it != ite; ++it)
            {
                if ((*it)->getType() == sort)
                {
                    delete(*it);
                    it = this->_spells.erase(it);
                }
            } 
            return ;            
        }
        ATarget* createTarget(const std::string &sort)
        {
            std::vector<ATarget*>::iterator ite = _spells.end();
            for(std::vector<ATarget*>::iterator it = _spells.begin(); it != ite; ++it)
            {
                if ((*it)->getType() == sort)
                {
                    return (*it);
                }
            }
            return NULL;
        }
};

#endif