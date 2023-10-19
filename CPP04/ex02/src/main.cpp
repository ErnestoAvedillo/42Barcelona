/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/main.h"
void print_title(std::string msg, std::string clr_text, std::string clr_border)
{
	int fill;
	int odd;
	int size;

	size = msg.length() >= FILL ? msg.length() + 10 : FILL;
	fill = (size - msg.length()) / 2;
	odd = msg.length() < FILL ? msg.length() % 2 : 0;
	std::cout << clr_border;
	std::cout << "\n " << std::setfill('_') << std::setw(size) << "" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(size + 1) << "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(size + 1) << "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(fill + odd) << "" << clr_text << msg << clr_border << std::setw(fill + 1) << "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(size + 1) << "|" << std::endl;
	std::cout << "|" << std::setfill('_') << std::setw(size + 2) << "|\n"
			  << std::endl;
	std::cout << RESET;
}

std::string long_to_string(long num)
{
	std::string str;
	std::stringstream ss;

	ss << num;
	str = ss.str();
	return (str);
}

void test_WrongAnimal(void)
{
	print_title("Constructors", GREEN, YELLOW);
	std::cout << GREEN "const WrongAnimal* wrongAAnimal" RESET << std::endl;
	const WrongAnimal *wrongAAnimal = new WrongAnimal();
	std::cout << std::endl;
	std::cout << GREEN "const WrongAnimal* wrongAAnimalCat" RESET << std::endl;
	const WrongAnimal *wrongAAnimalCat = new WrongCat();
	std::cout << std::endl;
	std::cout << GREEN "const WrongCat* wrongCat" RESET << std::endl;
	const WrongCat *wrongCat = new WrongCat();

	print_title("Methods: getType", PURPLE, YELLOW);
	std::cout << "wrongAAnimal -> " << wrongAAnimal->getType() << " " << std::endl;
	std::cout << "wrongAAnimalCat -> " << wrongAAnimalCat->getType() << " " << std::endl;
	std::cout << "wrongCat -> " << wrongCat->getType() << " " << std::endl;

	print_title("Methods: makeSound", PURPLE, YELLOW);
	std::cout << "wrongAAnimal -> ";
	wrongAAnimal->makeSound();
	std::cout << "wrongAAnimalCat -> ";
	wrongAAnimalCat->makeSound();
	std::cout << "wrongCat -> ";
	wrongCat->makeSound();

	print_title("Destructors", RED, YELLOW);
	std::cout << RED "wrongAAnimal" RESET << std::endl;
	delete wrongAAnimal;
	std::cout << std::endl;
	std::cout << RED "wrongAAnimalCat" RESET << std::endl;
	delete wrongAAnimalCat;
	std::cout << std::endl;
	std::cout << RED "wrongCat" RESET << std::endl;
	delete wrongCat;
}

void test_Animal_v1(void)
{
	print_title("Constructors", GREEN, YELLOW);
	// std::cout << GREEN"const AAnimal* animal"RESET << std::endl;
	// const AAnimal* animal = new AAnimal();
	// std::cout << std::endl;
	std::cout << GREEN "const AAnimal* animalDog" RESET << std::endl;
	const AAnimal *animalDog = new Dog();
	std::cout << std::endl;
	std::cout << GREEN "const AAnimal* animalCat" RESET << std::endl;
	const AAnimal *animalCat = new Cat();
	std::cout << std::endl;
	std::cout << GREEN "const Dog* dog" RESET << std::endl;
	const Dog *dog = new Dog();
	std::cout << std::endl;
	std::cout << GREEN "const Cat* cat" RESET << std::endl;
	const Cat *cat = new Cat();

	print_title("Methods: getType", PURPLE, YELLOW);
	// std::cout << "animal -> " << animal->getType() << " " << std::endl;
	std::cout << "animalDog -> " << animalDog->getType() << " " << std::endl;
	std::cout << "animalCat -> " << animalCat->getType() << " " << std::endl;
	std::cout << "dog -> " << dog->getType() << " " << std::endl;
	std::cout << "cat -> " << cat->getType() << " " << std::endl;

	print_title("Methods: makeSound", PURPLE, YELLOW);
	// std::cout << "animal -> ";
	// animal->makeSound();
	std::cout << "animalDog -> ";
	animalDog->makeSound();
	std::cout << "animalCat -> ";
	animalCat->makeSound();
	std::cout << "dog -> ";
	dog->makeSound();
	std::cout << "cat -> ";
	cat->makeSound();

	print_title("Destructors", RED, YELLOW);
	// std::cout << RED"animal"RESET << std::endl;
	// delete animal;
	std::cout << std::endl;
	std::cout << RED "animalDog" RESET << std::endl;
	delete animalDog;
	std::cout << std::endl;
	std::cout << RED "animalCat" RESET << std::endl;
	delete animalCat;
	std::cout << std::endl;
	std::cout << RED "dog" RESET << std::endl;
	delete dog;
	std::cout << std::endl;
	std::cout << RED "cat" RESET << std::endl;
	delete cat;
}

void test_Cat(Cat *cat, unsigned int first_getIdea_idx, unsigned int second_getIdea_idx, std::ostream &out, std::string stream)
{
	out << "getType(): " << cat->getType();
	out << " | getIdea( 0 ): " << cat->getIdea(first_getIdea_idx);
	out << " | getIdea( 1 ): " << cat->getIdea(second_getIdea_idx);
	out << " | getIndex(): " << cat->getIndex();
	out << " | getCurrentIdea(): " << cat->getCurrentIdea() << std::endl;
	out << " | printBrain( " << stream << " ): ";
	cat->printBrain(out);
	out << std::endl;
}

void test_Dog(Dog *dog, unsigned int first_getIdea_idx, unsigned int second_getIdea_idx, std::ostream &out, std::string stream)
{
	out << "getType(): " << dog->getType();
	out << " | getIdea( 0 ): " << dog->getIdea(first_getIdea_idx);
	out << " | getIdea( 1 ): " << dog->getIdea(second_getIdea_idx);
	out << " | getIndex(): " << dog->getIndex();
	out << " | getCurrentIdea(): " << dog->getCurrentIdea() << std::endl;
	out << " | printBrain( " << stream << " ): ";
	dog->printBrain(out);
	out << std::endl;
}

void test_Animal_basic_v2(AAnimal *animals[], unsigned short int size, unsigned int c_size, unsigned short int (*cmp)(unsigned int, unsigned int))
{
	unsigned short int lower;

	print_title("Methods: getType() && getIdea( 0 ) && getIdea( 1 ) && getIndex() && getCurrentIdea() && printBrain( std::cout )", PURPLE, YELLOW);
	for (unsigned int i = 0; i < c_size; i++)
	{
		lower = cmp(i, size);
		std::cout << PURPLE "AAnimal* animals[ " WHITE << i << PURPLE " ]" WHITE << std::endl;
		switch (lower)
		{
		case 1:
			test_Cat(dynamic_cast<Cat *>(animals[i]), 0, 1, std::cout, "std::cout");
			break;
		default:
			test_Dog(dynamic_cast<Dog *>(animals[i]), 0, 1, std::cout, "std::cout");
			break;
		}
		std::cout << std::endl;
	}
}

void test_assignation_operator(AAnimal *animals[], unsigned short int size)
{
	print_title("animals[ First Cat ] = animals[ First dog ]", PINK, YELLOW);
	std::cout << WHITE;
	*(static_cast<Cat *>(animals[0])) = *(static_cast<Cat *>(animals[size]));
	std::cout << "animal[ 0 ] -> getIdea( 0 ): " << static_cast<Dog *>(animals[0])->getIdea(0) << std::endl;
	std::cout << "  		  |" << std::endl;
	std::cout << "  		  |" << std::endl;
	std::cout << "animal[ " << size << " ] -> getIdea( 0 ): " << static_cast<Dog *>(animals[size])->getIdea(0) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "animal[ 0 ] -> makeSound(): ";
	static_cast<Dog *>(animals[0])->makeSound();
	std::cout << "  		  |" << std::endl;
	std::cout << "  		  |" << std::endl;
	std::cout << "animal[ " << size << " ] -> makeSound(): ";
	static_cast<Dog *>(animals[size])->makeSound();
	std::cout << std::endl;
	print_title("animals[ 0 ] = animals[ 0 ]", PINK, YELLOW);
	std::cout << WHITE;
	*(static_cast<Cat *>(animals[0])) = *(static_cast<Cat *>(animals[0]));
	std::cout << "animal[ 0 ] -> getIdea( 0 ): " << static_cast<Cat *>(animals[0])->getIdea(0);
	std::cout << " |---| getType(): " << static_cast<Cat *>(animals[0])->getType();
	std::cout << " |---| makeSound(): ";
	static_cast<Dog *>(animals[0])->makeSound();
	std::cout << std::endl;
}

void test_addIdea_getIndex_getCurrentIdea(AAnimal *animals[], unsigned short int size, bool dog_edition)
{
	unsigned int idx;
	std::string title;
	std::string idea;

	idx = dog_edition == true ? size : 0;
	print_title("getIndex() && getCurrentIdea()", PINK, YELLOW);
	std::cout << WHITE;
	std::cout << "animals[ " << idx << " ]->getIndex(): " << static_cast<Cat *>(animals[idx])->getIndex() << std::endl;
	std::cout << "animals[ " << idx << " ]->getCurrentIdea(): " << static_cast<Cat *>(animals[idx])->getCurrentIdea() << std::endl;
	title = "Adding 99 ideas to animals[ " + long_to_string(idx) + " ]: animals[ " + long_to_string(idx) + " ]->addIdea( \"Test Idea i\" )";
	print_title(title, PINK, YELLOW);
	std::cout << WHITE;
	for (unsigned int i = 1; i < MAX_IDEAS; i++)
	{
		idea = "Test Idea " + long_to_string(i);
		static_cast<Cat *>(animals[idx])->addIdea(idea);
	}
	std::cout << "animals[ " << idx << " ]->printBrain( std::cout ) = " << std::endl;
	static_cast<Cat *>(animals[idx])->printBrain(std::cout);
	print_title("getIndex()", PINK, YELLOW);
	std::cout << WHITE;
	std::cout << "animals[ " << idx << " ]->getIndex(): " << static_cast<Cat *>(animals[idx])->getIndex() << std::endl;
	std::cout << "animals[ " << idx << " ]->getCurrentIdea(): " << static_cast<Cat *>(animals[idx])->getCurrentIdea() << std::endl;
	title = "Adding 1 idea to animals[ " + long_to_string(idx) + " ]: animals[ " + long_to_string(idx) + " ]->addIdea( \"Overflow test idea\" )";
	print_title(title, PINK, YELLOW);
	std::cout << WHITE;
	static_cast<Cat *>(animals[idx])->addIdea("Overflow test idea");
	std::cout << "animals[ " << idx << " ]->printBrain( std::cout ) = " << std::endl;
	static_cast<Cat *>(animals[idx])->printBrain(std::cout);
	print_title("getIndex()", PINK, YELLOW);
	std::cout << WHITE;
	std::cout << "animals[ " << idx << " ]->getIndex(): " << static_cast<Cat *>(animals[idx])->getIndex() << std::endl;
	std::cout << "animals[ " << idx << " ]->getCurrentIdea(): " << static_cast<Cat *>(animals[idx])->getCurrentIdea() << std::endl;
	(void)size;
}

void test_getIdea_idx(AAnimal *animals[], unsigned int idx, long int idea_idx)
{
	std::string title;

	title = "animals[ " + long_to_string(idx) + " ]: animals[ " + long_to_string(idx) + " ]->getIdea( " + long_to_string(idea_idx) + " )";
	print_title(title, PINK, YELLOW);
	std::cout << WHITE;
	std::cout << "animals[ " << idx << " ]->getIdea( " << idea_idx << " ): " << static_cast<Cat *>(animals[idx])->getIdea(idea_idx) << std::endl;
}

void test_getIdea(AAnimal *animals[], unsigned short int size, bool dog_edition)
{
	unsigned int idx;

	idx = dog_edition == true ? size : 0;
	test_getIdea_idx(animals, idx, -1);
	test_getIdea_idx(animals, idx, 0);
	test_getIdea_idx(animals, idx, 1);
	test_getIdea_idx(animals, idx, 99);
	test_getIdea_idx(animals, idx, 100);
}

void test_Animal_advanced_v2(AAnimal *animals[], unsigned short int size)
{
	print_title("Assignation operator Tests", PURPLE, YELLOW);
	test_assignation_operator(animals, size);
	print_title("addIdea && getIndex && getCurrenIdea Tests: Cat Edition", PURPLE, YELLOW);
	test_addIdea_getIndex_getCurrentIdea(animals, size, false);
	print_title("addIdea && getIndex && getCurrenIdea Tests: Dog Edition", PURPLE, YELLOW);
	test_addIdea_getIndex_getCurrentIdea(animals, size, true);
	print_title("getIdea Tests: Cat Edition", PURPLE, YELLOW);
	test_getIdea(animals, size, false);
	print_title("getIdea Tests: Dog Edition", PURPLE, YELLOW);
	test_getIdea(animals, size, true);
	return;
}

unsigned short int lower_than(unsigned int num1, unsigned int num2)
{
	if (num1 < num2)
		return (1);
	return (0);
}

void test_Animal_v2(unsigned short int size)
{
	unsigned int c_size;
	unsigned short int lower;

	c_size = size * 2;
	print_title("Constructors", GREEN, YELLOW);
	std::cout << GREEN "AAnimal* animals[ " WHITE << c_size << GREEN " ]" RESET << std::endl;
	AAnimal *animals[c_size];
	std::cout << std::endl;

	for (unsigned int i = 0; i < c_size; i++)
	{
		lower = i < size;
		switch (lower)
		{
		case 1:
			std::cout << GREEN "AAnimal* animals[ " WHITE << i << GREEN " ] = new Cat()" RESET << std::endl;
			animals[i] = new Cat();
			dynamic_cast<Cat *>(animals[i])->addIdea("Exploding Kittens");
			break;
		default:
			std::cout << GREEN "AAnimal* animals[ " WHITE << i << GREEN " ] = new Dog()" RESET << std::endl;
			animals[i] = new Dog();
			dynamic_cast<Dog *>(animals[i])->addIdea("Exploding Puppies");
			break;
		}
		std::cout << std::endl;
	}

	print_title("BASIC", BLUE, YELLOW);
	test_Animal_basic_v2(animals, size, c_size, lower_than);
	print_title("ADVANCED", BLUE, YELLOW);
	test_Animal_advanced_v2(animals, size);

	print_title("Destructors", RED, YELLOW);
	for (unsigned int i = 0; i < c_size; i++)
	{
		std::cout << RED "animals[ " WHITE << i << RED " ]" RESET << std::endl;
		delete animals[i];
		std::cout << std::endl;
	}
}

void test_AAnimal(void)
{
	// Uncomment the following lines to check that the AAnimal class could not be instantied
	// AAnimal	abstract_animal;
	// AAnimal	*abstract_pointer_animal = new AAnimal();
}

int main(void)
{
	/*
		print_title( "Test: Animal V.1", BLUE, YELLOW );
		test_Animal_v1();
		print_title( "Test: WrongAnimal", BLUE, YELLOW );
		test_WrongAnimal();
		print_title( "Test: AAnimal", BLUE, YELLOW );
		test_AAnimal();
	*/
	print_title("Test: Animal V.2", BLUE, YELLOW);
	test_Animal_v2(5);
	return (0);
}
