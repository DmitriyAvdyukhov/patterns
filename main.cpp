#include <iostream>

#include "generative/singleton.h"
#include "generative/factory_method.h"
#include "generative/object_pool.h"
#include "generative/prototype.h"
#include "generative/abstract_factory.h"

#include "structural/adapter_wrapper.h"
#include "structural/decorator.h"
#include "structural/builder.h"
#include "structural/fasade.h"

int main()
{
	TestAbstractFactory();
	/*TestSingleton();
	TestFactoryMethod();
	TestBuilder();
	TestObjectPool();
	TestAdapter();
	TestPrototype();*/
	//TestDecorator();
	//TestFasade();
	return 0;
}