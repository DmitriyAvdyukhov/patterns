#pragma once
#include "factory_method.h"


class Army
{
public:
	void Info() const
	{
		std::cout << "Infantrymans: " << infantrymen_.size() << " count "
			<< "Archers: " << archers_.size() << " count "
			<< "Horsemen: " << horsemen_.size() << " count "
			<< "Catapults: " << catapults_.size() << " count "
			<< "Elephants: " << elephants_.size() << " count" << std::endl;
	}

	std::vector<Infantryman>& GetInfantrymans()
	{
		return infantrymen_;
	}

	std::vector<Archer>& GetArchers()
	{
		return archers_;
	}

	std::vector<Horseman>& GetHosemen()
	{
		return horsemen_;
	}

	std::vector<Catapult>& GetCatapults()
	{
		return catapults_;
	}

	std::vector<Elephant>& GetElephants()
	{
		return elephants_;
	}
private:
	std::vector<Infantryman> infantrymen_;
	std::vector<Archer> archers_;
	std::vector<Horseman> horsemen_;
	std::vector<Catapult> catapults_;
	std::vector<Elephant> elephants_;
};

class ArmyBuilder
{
protected:
	std::shared_ptr<Army> army_ptr_ = nullptr;
public:
	ArmyBuilder() = default;
	virtual ~ArmyBuilder() {}
	virtual void CreateArmy() {}
	virtual void CreateInfantryman() {}
	virtual void CreateArcher() {}
	virtual void CreateHorseman() {}
	virtual void CreateCatapult() {}
	virtual void CreateElephant() {}
	virtual std::shared_ptr<Army> GetArmy() 
	{
		return army_ptr_;
	}
};

class RomanArmyBuilder : public ArmyBuilder
{
public:
	void CreateArmy() override
	{
		army_ptr_ = std::make_shared<Army>();
	}

	void CreateInfantryman() override
	{
		army_ptr_->GetInfantrymans().push_back(Infantryman());
	}

	void CreateArcher() override
	{
		army_ptr_->GetArchers().push_back(Archer());
	}

	void CreateHorseman() override
	{
		army_ptr_->GetHosemen().push_back(Horseman());
	}

	void CreateCatapult() override
	{
		army_ptr_->GetCatapults().push_back(Catapult());
	}	
};

class CarthagenArmyBuilder : public ArmyBuilder
{
public:
	void CreateArmy() override
	{
		army_ptr_ = std::make_shared<Army>();
	}
	void CreateInfantryman() override
	{
		army_ptr_->GetInfantrymans().push_back(Infantryman());
	}

	void CreateArcher() override
	{
		army_ptr_->GetArchers().push_back(Archer());
	}

	void CreateHorseman() override
	{
		army_ptr_->GetHosemen().push_back(Horseman());
	}

	void CreateElephant() override
	{
		army_ptr_->GetElephants().push_back(Elephant());
	}
};

class Director
{
public:
	Director()	{}
	std::shared_ptr<Army> CreateArmy(ArmyBuilder& builder)
	{
		builder.CreateArmy();
		builder.CreateInfantryman();
		builder.CreateArcher();
		builder.CreateHorseman();
		builder.CreateCatapult();
		builder.CreateElephant();
		return builder.GetArmy();
	}
};

void TestBuilder()
{
	Director dir;
	RomanArmyBuilder roman;
	CarthagenArmyBuilder carthagen;
	std::shared_ptr<Army> roman_army = dir.CreateArmy(roman);
	std::shared_ptr<Army> carthagen_army = dir.CreateArmy(carthagen);
	std::cout << "Roman army: ";
	roman_army->Info();
	std::cout << "Carthagen army: ";
	carthagen_army->Info();
	std::cout << std::endl;		
}