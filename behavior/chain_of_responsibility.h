#pragma once
#include <iostream>
#include <memory>

enum class FromTo
{
	B2B,
	B2P,
	P2B,
	P2P
};

class MoneyTransfer
{
public:
	MoneyTransfer() = delete;
	MoneyTransfer(double money, std::string from, std::string to, std::string currency, FromTo from_to)
		: currency_(currency), money_(money), from_account_(from), to_account_(to), from_to_(from_to)
	{}

	FromTo GetFromTo() const
	{
		return from_to_;
	}
private:
	std::string currency_{};
	double money_ = 0;
	std::string from_account_{};
	std::string to_account_{};
	FromTo from_to_;
};

class TransferMiddleware
{
public:
	virtual ~TransferMiddleware(){}
	TransferMiddleware() = default;
	TransferMiddleware(TransferMiddleware* next)
		: next_(next)
	{}

	void Process(MoneyTransfer* transfer)
	{
		if (CanDo(transfer))
		{
			bool next = Do(transfer);
			if (next)
			{
				return;
			}
		}
		if (!next_)
		{
			return;
		}
		next_->Process(transfer);
	}

	TransferMiddleware& Add(TransferMiddleware* next)
	{
		if (next_)
		{
			next_->Add(next);
		}
		else
		{
			next_ = next;
		}
		return *this;
	}
	virtual bool CanDo(MoneyTransfer*) = 0;
	virtual bool Do(MoneyTransfer*) = 0;

private:
	TransferMiddleware* next_ = nullptr;
};

class B2BTransferMiddelware : public TransferMiddleware
{
public:
	B2BTransferMiddelware() : TransferMiddleware(nullptr){}

	B2BTransferMiddelware(TransferMiddleware* next) : TransferMiddleware(next) {}

	bool CanDo(MoneyTransfer* transfer) override
	{
		if (!transfer)
		{
			return false;
		}
		if (transfer->GetFromTo() == FromTo::B2B)
		{
			return true;
		}
		return false;
	}

	bool Do(MoneyTransfer* transfer) override
	{
		if (transfer)
		{
			std::cout << "B2B logic" << std::endl;
			return true;
		}
		return false;
	}
};


class B2PTransferMiddelware : public TransferMiddleware
{
public:
	B2PTransferMiddelware() : TransferMiddleware(nullptr) {}

	B2PTransferMiddelware(TransferMiddleware* next) : TransferMiddleware(next) {}

	bool CanDo(MoneyTransfer* transfer) override
	{
		if (!transfer)
		{
			return false;
		}
		if (transfer->GetFromTo() == FromTo::B2P)
		{
			return true;
		}
		return false;
	}

	bool Do(MoneyTransfer* transfer) override
	{
		if (transfer)
		{
			std::cout << "B2P logic" << std::endl;
			return true;
		}
		return false;
	}
};

class P2BTransferMiddelware : public TransferMiddleware
{
public:
	P2BTransferMiddelware() : TransferMiddleware(nullptr) {}

	P2BTransferMiddelware(TransferMiddleware* next) : TransferMiddleware(next) {}

	bool CanDo(MoneyTransfer* transfer) override
	{
		if (!transfer)
		{
			return false;
		}
		if (transfer->GetFromTo() == FromTo::P2B)
		{
			return true;
		}
		return false;
	}

	bool Do(MoneyTransfer* transfer) override
	{
		if (transfer)
		{
			std::cout << "P2B logic" << std::endl;
			return true;
		}
		return false;
	}
};

class P2PTransferMiddelware : public TransferMiddleware
{
public:
	P2PTransferMiddelware() : TransferMiddleware(nullptr) {}

	P2PTransferMiddelware(TransferMiddleware* next) : TransferMiddleware(next) {}

	bool CanDo(MoneyTransfer* transfer) override
	{
		if (!transfer)
		{
			return false;
		}
		if (transfer->GetFromTo() == FromTo::P2P)
		{
			return true;
		}
		return false;
	}

	bool Do(MoneyTransfer* transfer) override
	{
		if (transfer)
		{
			std::cout << "P2P logic" << std::endl;
			return true;
		}
		return false;
	}
};


void TestChainOfResponsibility()
{
	MoneyTransfer transfer(20., "SPB 0123245646544", "ALF 456456432131", "RUB", FromTo::B2P);
	
	B2BTransferMiddelware b2b;
	P2PTransferMiddelware p2p;
	P2BTransferMiddelware p2b;
	B2PTransferMiddelware b2p;
	b2b.Add(&p2p).Add(&p2b).Add(&b2p).Process(&transfer);
	
}