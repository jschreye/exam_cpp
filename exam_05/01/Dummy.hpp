#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "ATarget.hpp"

class Dummy: public ATarget
{
    public:

        Dummy(): ATarget("Target Practice Dummy"){}
        virtual ~Dummy(){}
        virtual ATarget *clone() const
        {
            return (new Dummy());
        }
};

#endif