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
// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
	
// 	Ice tmpice;
// 	Ice* tmpiceptr = &tmpice;
// 	src->learnMateria(tmpiceptr);

// 	Cure tmpcure;
// 	Cure* tmpcureptr = &tmpcure;
// 	src->learnMateria(tmpcureptr);

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
    std::cout << "\n=== EX03 Test 2: Character equip/use ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
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

    std::cout << "\n=== EX03 Test 3: Inventory overflow ===" << std::endl;
    {
        Character c("tester");
        for (int i = 0; i < 5; i++) {
            c.equip(new Ice()); // 5回目は無視される
        }
    }

    std::cout << "\n=== EX03 Test 4: Unequip behavior ===" << std::endl;
    {
        Character c("tester");
        AMateria* tmp = new Ice();
        c.equip(tmp);
        c.unequip(0); // deleteしない仕様
    }

    std::cout << "\n=== EX03 Test 5: Invalid use ===" << std::endl;
    {
        Character c("tester");
        Character t("target");
        c.use(0, t); // 空スロットで呼んでも何も起きない
    }

    std::cout << "\n=== EX03 Test 6: Canonical Character ===" << std::endl;
    {
        Character c1("Alice");
        Character c2(c1);
        Character c3("Bob");
        c3 = c1;
    }

    std::cout << "\n=== EX03 Test 7: Canonical MateriaSource ===" << std::endl;
    {
        MateriaSource ms1;
        MateriaSource ms2(ms1);
        MateriaSource ms3;
        ms3 = ms1;
    }

    std::cout << "\n=== EX03 Test 8: Deep copy equip ===" << std::endl;
    {
        Character c1("Alice");
        c1.equip(new Ice());
        Character c2(c1); // deep copy
        Character c3("Bob");
        c3 = c1;
    }

    std::cout << "\n=== EX03 Test 9: Clone check ===" << std::endl;
    {
        Ice ice;
        AMateria* clone = ice.clone();
        delete clone;
    }

    std::cout << "\n=== EX03 Test 10: Stress test ===" << std::endl;
    {
        MateriaSource src;
        for (int i = 0; i < 10; i++)
            src.learnMateria(new Ice()); // 5回目以降は無視される
    }
}