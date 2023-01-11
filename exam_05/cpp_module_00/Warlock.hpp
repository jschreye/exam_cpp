#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock {

	private:
		std::string _name;
		std::string _title;

		Warlock();
		Warlock(Warlock const &copy);
		Warlock &operator=(Warlock const &right);

	public:
		Warlock(std::string name, std::string title): _name(name), _title(title)
		{
			std::cout << this->_name << ": This looks like another boring day." << std::endl;
		}
		virtual ~Warlock ()
		{
			std::cout << this->_name << ": My job here is done!" << std::endl;
		}

		const std::string &getName() const {return this->_name;}
		const std::string &getTitle() const {return this->_title;}

		void setTitle (std::string const &title) 
		{
			this->_title = title;
		}

		void introduce () const 
		{
			std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
		}
};

#endif
