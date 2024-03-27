#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock
{
	private:
		std::string name;
		std::string title;
		Warlock();
		Warlock(Warlock const &);
		Warlock &operator=(Warlock const &);
	public: 
		~Warlock();
		Warlock(std::string const &,std::string const &);
		std::string const & getName() const;
		std::string const & getTitle() const;
		void setTitle (std::string const &);
		void introduce() const;
};

#endif
