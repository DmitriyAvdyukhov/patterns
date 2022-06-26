#pragma once
#include <memory>
#include <iostream>
#include "./structural/builder.h"

namespace abstract_factory
{
	class RomanInfantryman : public factory::Infantryman
	{
	public:
		void Info() override
		{
			std::cout << "RomanInfantryman" << std::endl;
		}
	};

	class RomanArcher : public factory::Archer
	{
	public:

		void Info() override
		{
			std::cout << "RomanArcher" << std::endl;
		}
	};

	class  RomanHorseman : public factory::Horseman
	{
	public:

		void Info() override
		{
			std::cout << "RomanHorseman" << std::endl;
		}
	};


	class CarthaginianInfantryman : public factory::Infantryman
	{
	public:
		void Info() override
		{
			std::cout << "CarthaginianInfantryman" << std::endl;
		}
	};

	class CarthaginianArcher : public factory::Archer
	{
	public:

		void Info() override
		{
			std::cout << "CarthaginianArcher" << std::endl;
		}
	};

	class  CarthaginianHorseman : public factory::Horseman
	{
	public:

		void Info() override
		{
			std::cout << "CarthaginianHorseman" << std::endl;
		}
	};


	class ArmyFactory
	{
	public:
		virtual  std::shared_ptr<factory::Infantryman> CreateInfantryman() = 0;
		virtual  std::shared_ptr<factory::Archer> CreateArcher() = 0;
		virtual  std::shared_ptr<factory::Horseman> CreateHorseman() = 0;
		virtual ~ArmyFactory() {}
	};

	class RomanArmyFactory : public ArmyFactory
	{
		std::shared_ptr<factory::Infantryman> CreateInfantryman() override
		{
			return std::make_shared<RomanInfantryman>(RomanInfantryman());
		}

		std::shared_ptr<factory::Archer> CreateArcher() override
		{
			return std::make_shared<RomanArcher>(RomanArcher());
		}

		std::shared_ptr<factory::Horseman> CreateHorseman() override
		{
			return std::make_shared<RomanHorseman>(RomanHorseman());
		}

	};


	class CarthaginianArmyFactory : public ArmyFactory
	{
		std::shared_ptr<factory::Infantryman> CreateInfantryman() override
		{
			return std::make_shared<CarthaginianInfantryman>(CarthaginianInfantryman());
		}

		std::shared_ptr<factory::Archer> CreateArcher() override
		{
			return std::make_shared<CarthaginianArcher>(CarthaginianArcher());
		}

		std::shared_ptr<factory::Horseman> CreateHorseman() override
		{
			return std::make_shared<CarthaginianHorseman>(CarthaginianHorseman());
		}

	};

	class builder::Army;

	class Game
	{
	public:
		std::shared_ptr<builder::Army> CreateArmy(ArmyFactory& factory)
		{
			std::shared_ptr<builder::Army> p = std::make_shared<builder::Army>();
			p->GetInfantrymans().push_back(factory.CreateInfantryman());
			p->GetArchers().push_back(factory.CreateArcher());
			p->GetHorsemen().push_back(factory.CreateHorseman());
			return p;
		}
	};
}

void TestAbstractFactory()
{
	using namespace abstract_factory;
	Game game;
	RomanArmyFactory roman;
	CarthaginianArmyFactory carthaginian;
	std::shared_ptr<builder::Army> r_army = game.CreateArmy(roman);
	std::shared_ptr<builder::Army> car_army = game.CreateArmy(carthaginian);
	std::cout << "Roman army:" << std::endl;
	r_army->Info();
	std::cout << "\nCarthaginian army:" << std::endl;
	car_army->Info();
	
}