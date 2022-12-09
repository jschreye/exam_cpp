#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock {

	private:

		std::string name;
		std::string title;

		Warlock(){}
		Warlock(const Warlock &rhs){*this = rhs;}
		Warlock &operator=(const Warlock &rhs){name = rhs.name; title = rhs.title; return *this;}
	public:

		Warlock(const std::string &name, const std::string title)
			: name(name), title(title) 
		{
			std::cout << name << ": This looks like another boring day." << std::endl;
		}
		virtual ~Warlock(){
			std::cout << name << ": My job here is done!" << std::endl;
		}

		const std::string &getTitle() const{ return this->title;}
		const std::string &getName() const{ return this->name;}
		void	setTitle(const std::string &s){ this->title = s;}

		void	introduce() const {
			std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
		}
};
#endif
