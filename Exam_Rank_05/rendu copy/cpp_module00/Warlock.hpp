
#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock
{
	private:
		std::string _name;
		std::string _title;
		Warlock();
		Warlock( Warlock &);
		Warlock &operator= (Warlock const &);
	public:
		Warlock(std::string const &, std::string const &);
		~Warlock();
		std::string const &getName() const;
		std::string const &getTitle() const;
		void setTitle(std::string const &);
		void introduce() const ;
};

#endif
