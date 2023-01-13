#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include "ASpell.hpp"
#include <vector>
#include <iostream>
class TargetGenerator
{
	private:
		std::vector<ATarget*> _target;

		TargetGenerator(TargetGenerator const &copy);
		TargetGenerator &operator=(TargetGenerator const &rhs);

    public:

        TargetGenerator(){}
        virtual ~TargetGenerator()
        {
            std::vector<ATarget*>::iterator ite = this->_target.end();
            for (std::vector<ATarget*>::iterator it = this->_target.begin(); it != ite; ++it) {
                delete (*it);
            }
            this->_target.clear();
        }
        void learnTargetType(ATarget *target)
        {
            if (target)
            {
                std::vector<ATarget*>::iterator ite = _target.end();
                for(std::vector<ATarget*>::iterator it = _target.begin(); it != ite; ++it)
                {
                    if ((*it)->getType() == target->getType())
                        return ;
                }
                _target.push_back(target->clone());
            }
        }
        void forgetTargetType(std::string const &name)
        {
            std::vector<ATarget*>::iterator ite = _target.end();
            for(std::vector<ATarget*>::iterator it = _target.begin(); it != ite; ++it)
            {
                if ((*it)->getType() == name)
                {
                    delete(*it);
                    it = this->_target.erase(it);
                }
            }
        }
        ATarget* createTarget(std::string const &name)
        {
            std::vector<ATarget*>::iterator ite = _target.end();
            for(std::vector<ATarget*>::iterator it = _target.begin(); it != ite; ++it)
            {
                if ((*it)->getType() == name)
                {
                    return ((*it));
                }
            }
            return NULL;
        }
};

#endif