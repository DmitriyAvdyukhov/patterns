#include "generative/singleton.h"
#include "generative/factory_method.h"
#include "generative/object_pool.h"
#include "generative/prototype.h"
#include "generative/abstract_factory.h"
#include "generative/builder.h"

#include "structural/adapter_wrapper.h"
#include "structural/decorator.h"
#include "structural/fasade.h"

#include "behavior/visitor.h"
#include "behavior/obsever.h"

int main()
{
	////-------generative-----------
	//TestAbstractFactory();
	//TestSingleton();
	//TestFactoryMethod();
	//TestPrototype();
	//TestObjectPool();

	////----------structurial----------
	//TestAdapter();	
	//TestBuilder();	
	//TestDecorator();
	//TestFasade();

	//-----------behavior------------
	//TestVisitor();
	TestObserver();

	return 0;
}