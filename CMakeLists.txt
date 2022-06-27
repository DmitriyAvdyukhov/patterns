cmake_minimum_required(VERSION 3.0)

project(Patterns)
set(CMAKE_CXX_STANDARD 17)

set(FILES_PROJECT main.cpp 
                  structural/adapter_wrapper.h 
				  structural/builder.h
				  structural/fasade.h
				  structural/decorator.h

				  generative/factory_method.h
				  generative/object_pool.h
				  generative/prototype.h
				  generative/singleton.h generative/singleton.cpp
				  generative/abstract_factory.h

				  behavior/visitor.h)
				  
add_executable(main ${FILES_PROJECT})