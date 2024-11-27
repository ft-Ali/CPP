#include "test.hpp"

void Character::sayHello(std::string const &target) {
	std::cout << "Hello " << target << "!" << std::endl;
}

void Warrior::sayHello(std::string const &target) {
	std::cout << "Fuck off " << target << ", I don't need you!" << std::endl;
}


int main() {
	Warrior* me = new Warrior();
	Character* me2 = new Warrior();

	me->sayHello("students");
	me2->sayHello("students");
	delete me;
	delete me2;
	return 0;
}

/*** 
 *  Virtual :
 * fonction virtual ne peuvent etre static
 * fonction virutal peut etre une fonction friend d'une autre class
 * les fonctions virtual doivent etre accedee a l'aide d'un pointeur ou ref type class
 * prototype virtual doit etre le meme dans la class de base ainsi que dans la class derivee 
*/
