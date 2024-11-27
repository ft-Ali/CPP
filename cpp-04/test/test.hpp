#ifndef	TEST_HPP
# define TEST_HPP

# include <fstream>
# include <iostream>
# include <string>


class Character {
	public:
		virtual void  sayHello(std::string const &target);
};

class Warrior : public Character {
	public:
		virtual void  sayHello(std::string const &target);
};


#endif 