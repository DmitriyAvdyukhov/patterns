#include <iostream>

#include "singleton.h"
#include "factory_method.h"
#include "builder.h"
#include "object_pool.h"

int main()
{
	TestSingleton();
	TestFactoryMethod();
	TestBuilder();
	TestObjectPool();
	return 0;
}