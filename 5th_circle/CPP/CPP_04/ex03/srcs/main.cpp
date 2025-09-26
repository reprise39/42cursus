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

// ============================ OFFICIAL (NO LEAK)==============================
// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
	
// 	AMateria* ap1 = new Ice();
// 	src->learnMateria(ap1);

// 	AMateria* ap2 = new Cure();
// 	src->learnMateria(ap2);

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

// 	delete ap1;
// 	delete ap2;
// 	return 0;
// }

// ============================ OFFICIAL (NO LEAK)==============================
int main()
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

	return 0;
}

