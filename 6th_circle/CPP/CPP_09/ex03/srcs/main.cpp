/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:40:44 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/09 17:40:44 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"


// ============================OFFICIAL==============================
// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
	
// 	src->learnMateria(new Ice()); //cp and learn
// 	src->learnMateria(new Cure());

// 	ICharacter* me = new Character("me");

// 	AMateria* tmp;

// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);

// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);

// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }

int main()
{
	std::cout << "\n=== Official test ===\n" << std::endl;
	{
	IMateriaSource* src = new MateriaSource();
	
	Ice tmpice;
	Ice* tmpiceptr = &tmpice;
	src->learnMateria(tmpiceptr);

	Cure tmpcure;
	Cure* tmpcureptr = &tmpcure;
	src->learnMateria(tmpcureptr);

	ICharacter* me = new Character("me");

	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	}

	std::cout << "\n=== Test 1: Character equip/use ===" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();

		AMateria* m1 = new Ice();
		AMateria* m2 = new Cure();
		src->learnMateria(m1);
		src->learnMateria(m2);
		delete m1;
		delete m2;

		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);


		//error
		tmp = src->createMateria("hory magic");
		me->equip(tmp);

		delete bob;
		delete me;
		delete src;
	}

	std::cout << "\n=== Test 2: Inventory overflow ===" << std::endl;
	{
		Character c("tester");
		for (int i = 0; i < 6; i++) // can equip limit 4
		{
			AMateria* m = new Ice();
			c.equip(m);
			if (i >= 4) // for no leak
				delete m;
		}
	}

	std::cout << "\n=== Test 3: Unequip behavior ===" << std::endl;
	{
		Character c("tester");
		AMateria* tmp = new Ice();
		c.equip(tmp);
		c.unequip(0); // unequip no delete
		c.unequip(100); // 
		c.unequip(0); // 
		delete tmp;
	}

	std::cout << "\n=== Test 4: Invalid use ===" << std::endl;
	{
		Character c("tester");
		Character t("target");
		c.use(0, t); // fail
		c.use(4242424, t); // fail
	}

	std::cout << "\n=== Test 5: Canonical Character (deep copy equip) ===" << std::endl;
	{
		Character c1("Alice");
		AMateria* ice = new Ice();
		c1.equip(ice); // equip to c1
		Character c2(c1); // copy constructor
		Character c3("Bob");
		c3 = c1; // copy assignment

		std::cout << "c1 name is " << c1.getName() << std::endl;
		std::cout << "c2 name is " << c2.getName() << std::endl;
		std::cout << "c3 name is " << c3.getName() << std::endl;

		Character target("target");
		std::cout << "c1 uses slot 0: "; c1.use(0, target);
		std::cout << "c2 uses slot 0: "; c2.use(0, target); //can
		std::cout << "c3 uses slot 0: "; c3.use(0, target); //can
	}

	std::cout << "\n=== Test 6: Canonical MateriaSource (deep copy learned materia) ===" << std::endl;
	{
		MateriaSource ms1;
		AMateria* cure = new Cure();
		ms1.learnMateria(cure); // learn  clone 
		delete cure;

		MateriaSource ms2(ms1); // copy constructor
		MateriaSource ms3;
		ms3 = ms1; // copy assignment

		AMateria* m1 = ms1.createMateria("cure");
		AMateria* m2 = ms2.createMateria("cure");
		AMateria* m3 = ms3.createMateria("cure");

		delete m1;
		delete m2;
		delete m3;
	}

	std::cout << "\n=== Test 8: deliverd delete ===" << std::endl;
	{
		Ice ice;
		AMateria* clone = ice.clone();
		delete clone;
	}

	std::cout << "\n=== Test 9: learn materia ===" << std::endl;
	{
		MateriaSource src;
		for (int i = 0; i < 10; i++)
		{
			AMateria* m = new Ice();
			src.learnMateria(m); // learn cloned materia
			delete m;
		}
	}
	return 0;
}
