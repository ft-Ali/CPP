#ifndef	TEST_HPP
# define TEST_HPP

# include <fstream>
# include <iostream>
# include <string>


class Character {
	public:
		void  sayHello(std::string const &target);
};

class Warrior : public Character {
	public:
		void  sayHello(std::string const &target);
};


#endif 