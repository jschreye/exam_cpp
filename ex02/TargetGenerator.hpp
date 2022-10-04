#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include <vector>

class TargetGenerator
{
    private:
		TargetGenerator(const TargetGenerator &rhs){*this = rhs;}
		TargetGenerator &operator=(const TargetGenerator &rhs){(void)rhs; return *this;}
        std::vector<ATarget*> _targets;

    public:
    	TargetGenerator(){}
		~TargetGenerator(){}

		void learnTargetType(ATarget *target)
		{
			for (std::vector<ATarget*>::iterator it = _targets.begin(); it != _targets.end(); ++it)
			{
				if ((*it)->getType() == target->getType())
					return ;
			}
			_targets.push_back(target->clone());
		}

		ATarget *createTarget(const std::string &type)
		{
			for(std::vector<ATarget*>::const_iterator it(_targets.begin()); it != _targets.end(); it++)
			{
				if ((*it)->getType() == type)
					return ((*it)->clone());
			}
			return NULL;
		}
};

#endif