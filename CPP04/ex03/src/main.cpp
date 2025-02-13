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

void print_title(std::string msg, std::string color_text, std::string color_border)
{
	std::cout << color_border << "|" ;
	std::cout << std::setfill('*') << std::setw(5) << "";
	std::cout << color_text << msg << color_border << std::setw(5) << "|";
	std::cout << RESET << std::endl;
}
int main()
{
	{
		print_title("1. Creating MateriaSource", GREEN, YELLOW);
		IMateriaSource *src=  new MateriaSource();
		std::cout << std::endl;
		std::cout << std::endl;

		// ------------------------------------------------------------------------------------ //

		print_title("2. \"src\" learning 5 materias", GREEN, YELLOW);
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		std::cout << std::endl;
		Ice *mater = new Ice();
		src->learnMateria(mater);
		std::cout << std::endl;
		dynamic_cast<MateriaSource*>(src)->printMaterias();

		// ------------------------------------------------------------------------------------ //

		print_title("3. Creating Character \"vilma\" and \"oktorok\"", GREEN, YELLOW);
		Character *vilma = new Character("vilma");
		vilma->printMaterias();
		std::cout << std::endl;

		Character *oktorok = new Character("oktorok");
		oktorok->printMaterias();
		std::cout << std::endl;

		// ------------------------------------------------------------------------------------ //

		print_title("4. \"vilma\" trying to equip 5 materias and \"oktorok\" one materia", GREEN, YELLOW);
		vilma->equip(NULL);

		AMateria *tmp;
		tmp = src->createMateria("ice");
		vilma->equip(tmp);
		tmp = src->createMateria("ice");
		vilma->equip(tmp);
		tmp = src->createMateria("cure");
		vilma->equip(tmp);
		tmp = src->createMateria("cure");
		vilma->equip(tmp);
		tmp = src->createMateria("ice");
		vilma->equip(tmp);

		std::cout << std::endl;
		vilma->printMaterias();
		vilma->printHandler();

		std::cout << std::endl;
		tmp = src->createMateria("ice");
		oktorok->equip(tmp);
		std::cout << std::endl;
		oktorok->printMaterias();
		oktorok->printHandler();

		// ------------------------------------------------------------------------------------ //

		print_title("5. Testing Character Assignation overload \"vilma = oktorok\" for deep copy and changed vilma afterwards", 
	GREEN, YELLOW);
		*oktorok = *vilma;

		vilma->unequip(0);
		std::cout << "VILMA" << std::endl;
		vilma->printMaterias();
		vilma->printHandler();
		std::cout << std::endl;

		std::cout << "OKTOROK" << std::endl;
		oktorok->printMaterias();
		oktorok->printHandler();
		std::cout << std::endl;

		// ------------------------------------------------------------------------------------ //

		print_title("6. Testing character copy constructor for deep copy \"stardust = Character(vilma)\" and changed vilma afterwards", 
	GREEN, YELLOW);

		vilma->printMaterias();
		vilma->printHandler();

		Character *stardust = new Character(*vilma);
		stardust->setName("stardust");
		stardust->printMaterias();
		stardust->printHandler();

		tmp = src->createMateria("ice");
		vilma->equip(tmp);
		std::cout << "VILMA" << std::endl;
		vilma->printMaterias();
		vilma->printHandler();
		std::cout << std::endl;

		std::cout << "STARDUST" << std::endl;
		stardust->printMaterias();
		stardust->printHandler();
		std::cout << std::endl;

		// ------------------------------------------------------------------------------------ //

		print_title("7. \"vilma\" using all equiped materias on \"oktorok\" ", 
	GREEN, YELLOW);
		vilma->use(0, *oktorok);
		vilma->use(1, *oktorok);
		vilma->use(2, *oktorok);
		vilma->use(3, *oktorok);
		vilma->use(10, *oktorok);
		vilma->use(-1, *oktorok);
		std::cout << std::endl;

		// ------------------------------------------------------------------------------------ //

		print_title("8. \"vilma\" trying to use unequiped materias on \"oktorok\" ", 
	GREEN, YELLOW);
		vilma->unequip(0);
		vilma->use(0, *oktorok);

		std::cout << std::endl;

		// ------------------------------------------------------------------------------------ //

		print_title("9. New character \"lucifer\" equipping and unequipping materias", 
	GREEN, YELLOW);
		ICharacter *lucifer = new Character("lucifer");
		lucifer->printMaterias();
		lucifer->printHandler();
		AMateria *cure = new Cure;
		AMateria *ice = new Ice;

		lucifer->equip(cure);
		lucifer->equip(ice);
		lucifer->equip(cure);
		lucifer->equip(ice);
		lucifer->unequip(0);
		lucifer->unequip(1);
		lucifer->unequip(2);
		lucifer->unequip(3);
		lucifer->equip(cure);
		lucifer->equip(ice);

		lucifer->printMaterias();
		lucifer->printHandler();

		std::cout << std::endl;

		// ------------------------------------------------------------------------------------ //

		print_title("10. Testing if unequiped materia is freed", 
	GREEN, YELLOW);

		ICharacter *test = new Character("test");

		tmp = src->createMateria("ice");
		test->equip(tmp);
		test->unequip(0);
		std::cout << "Material " << tmp->getType() << " is stll in memory " << tmp << std::endl;
		delete tmp;
		std::cout << std::endl;

		// ------------------------------------------------------------------------------------ //

		print_title("11. Deleting \"vilma\", \"oktorok\", \"stardust\" and \"lucifer\"", RED, YELLOW);

		print_title("11 -> TEST", RED, YELLOW);
		test->printMaterias();
		test->printHandler();
		delete test;
		std::cout << std::endl;

		print_title("11 -> LUCIFER", RED, YELLOW);
		lucifer->printMaterias();
		lucifer->printHandler();
		delete lucifer;
		std::cout << std::endl;

		print_title("11 -> STARDUST", RED, YELLOW);
		stardust->printMaterias();
		stardust->printHandler();
		delete stardust;
		std::cout << std::endl;

		print_title("11 -> OKTOROK", RED, YELLOW);
		oktorok->printMaterias();
		oktorok->printHandler();
		delete oktorok;
		std::cout << std::endl;

		print_title("12 -> VILMA", RED, YELLOW);
		vilma->printMaterias();
		vilma->printHandler();
		delete vilma;
		std::cout << std::endl;

		print_title("13 -> SRC", RED, YELLOW);
		delete src;

		return (0);
	}
}
