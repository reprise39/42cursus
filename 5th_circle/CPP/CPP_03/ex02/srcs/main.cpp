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

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

std::ostream& red(std::ostream& os)
{
	return (os << "\033[31m");
}

std::ostream& blue(std::ostream& os)
{
	return (os << "\033[34m");
}

std::ostream& reset(std::ostream& os)
{
	return (os << "\033[0m");
}

// int main() {
// 	FragTrap st("FT-Beta");

// 	st.takeDamage(10000);
// 	st.attack("evil-bot");
// 	st.takeDamage(20);
// 	st.beRepaired(15);

// 	return 0;
// }

int main() {
	// 1. コンストラクタ・デストラクタの呼び出し確認
	std::cout << "=== Test 1: Constructor / Destructor ===" << std::endl;
	{
		FragTrap ft1("Alpha");
	}
	std::cout << std::endl;

	// 2. attack() の基本挙動（FragTrap独自メッセージ）
	std::cout << "=== Test 2: Basic attack ===" << std::endl;
	{
		FragTrap ft2("Bravo");
		ft2.attack("TargetDummy");
	}
	std::cout << std::endl;

	// 3. takeDamage() の基本挙動
	std::cout << "=== Test 3: Take damage ===" << std::endl;
	{
		FragTrap ft3("Charlie");
		ft3.takeDamage(30);
		ft3.takeDamage(50);
		ft3.takeDamage(30); // HPを0に
	}
	std::cout << std::endl;

	// 4. beRepaired() の基本挙動（HP上限なし）
	std::cout << "=== Test 4: Repair ===" << std::endl;
	{
		FragTrap ft4("Delta");
		ft4.takeDamage(70);
		ft4.beRepaired(40);
		ft4.beRepaired(200);
	}
	std::cout << std::endl;

	// 5. Energyが尽きた時の挙動
	std::cout << "=== Test 5: Energy depletion ===" << std::endl;
	{
		FragTrap ft5("Echo");
		for (int i = 0; i < 101; i++) {
			ft5.attack("Target"); // 100回でEnergyが尽きる
		}
		ft5.beRepaired(5); // Energyが0なので修理できない
	}
	std::cout << std::endl;

	// 6. HPが尽きた時の挙動
	std::cout << "=== Test 6: No HP left ===" << std::endl;
	{
		FragTrap ft6("Foxtrot");
		ft6.takeDamage(150);  // HPをゼロに
		ft6.attack("Target"); // HPゼロなので攻撃不可
		ft6.beRepaired(50);   // HPゼロなので修理不可
	}
	std::cout << std::endl;

	// 7. 特殊能力 highFivesGuys()
	std::cout << "=== Test 7: highFivesGuys ability ===" << std::endl;
	{
		FragTrap ft7("Golf");
		ft7.highFivesGuys();
	}
	std::cout << std::endl;

	// 8. 複数インスタンスの独立性確認
	std::cout << "=== Test 8: Multiple instances ===" << std::endl;
	{
		FragTrap ft8a("Hotel");
		FragTrap ft8b("India");

		ft8a.attack("India");
		ft8b.takeDamage(40);

		ft8b.attack("Hotel");
		ft8a.takeDamage(30);

		ft8a.beRepaired(20);
		ft8b.highFivesGuys();
	}
	std::cout << std::endl;

	// 9. コピーコンストラクタと代入演算子
	std::cout << "=== Test 9: Copy constructor and assignment ===" << std::endl;
	{
		FragTrap ft9a("Juliet");
		ft9a.attack("Target");

		FragTrap ft9b(ft9a); // コピーコンストラクタ
		ft9b.attack("AnotherTarget");

		FragTrap ft9c("Kilo");
		ft9c = ft9a; // 代入演算子（名前もコピー → Juliet）
		ft9c.attack("ThirdTarget");
	}
	std::cout << std::endl;

	return 0;
}