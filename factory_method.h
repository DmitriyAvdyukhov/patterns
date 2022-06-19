#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <cassert>


class Warrior
{
public:
	virtual void Info() = 0;
	virtual ~Warrior() {}	
};

class Infantryman : public Warrior
{
public:
	void Info() override
	{
		std::cout << "Infantryman" << std::endl;
	}
};

class Archer : public Warrior
{
public:
	void Info() override
	{
		std::cout << "Archer" << std::endl;
	}
};

class Horseman : public Warrior
{
public:
	void Info() override
	{
		std::cout << "Horseman" << std::endl;
	}
};

class Catapult : public Warrior
{
public:
	void Info() override
	{
		std::cout << "Catapult" << std::endl;
	}
};

class Elephant : public Warrior
{
public:
	void Info() override
	{
		std::cout << "Elephant" << std::endl;
	}
};

class Factory
{
public:
	virtual std::shared_ptr<Warrior> CreateWarrior() = 0;
	virtual ~Factory(){}
};

class InfantryFactory : public Factory
{
public:
	std::shared_ptr<Warrior> CreateWarrior() override
	{
		return std::make_shared<Infantryman>();
	}
};

class ArcherFactory : public Factory
{
public:
	std::shared_ptr <Warrior> CreateWarrior() override
	{
		return std::make_shared<Archer>();
	}
};

class HorsemanFactory : public Factory
{
public:
	std::shared_ptr<Warrior> CreateWarrior() override
	{
		return std::make_shared<Horseman>();
	}
};

class Arm
{
public:
	using Warrior_ptr = std::shared_ptr<Warrior>;
	Arm()
	{
		InfantryFactory infantry;
		ArcherFactory archer;
		HorsemanFactory horse;
		for (size_t i = 0; i < 20; ++i)
		{
			int x = std::rand() / 10 % 3;
			switch (x)
			{
			case 0:
				warriors_.push_back(infantry.CreateWarrior());
				break;
			case 1:
				warriors_.push_back(archer.CreateWarrior());
				break;
			case 2:
				warriors_.push_back(horse.CreateWarrior());
				break;
			default:
				break;
			}
		}
	}
	
	std::vector<Warrior_ptr> GetWarriors() const
	{
		return warriors_;
	}
private:
	std::vector<Warrior_ptr> warriors_;
};

void TestFactoryMethod()
{
	using Warrior_ptr = std::shared_ptr<Warrior>;

	InfantryFactory infantry;
	ArcherFactory archer;
	HorsemanFactory horse;
	std::vector<Warrior_ptr>war;
	war.push_back(infantry.CreateWarrior());
	war.push_back(archer.CreateWarrior());
	war.push_back(horse.CreateWarrior());
	for (const auto& warrior : war)
	{
		warrior->Info();
	}

	Arm arm;
	for (const auto& warrior : arm.GetWarriors())
	{
		warrior->Info();
	}

	std::cout << "Test FactoryMethod is Ok" << std::endl;
}