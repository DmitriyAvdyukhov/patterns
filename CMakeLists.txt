cmake_minimum_required(VERSION 3.0)

project(Patterns)
set(CMAKE_CXX_STANDARD 17)

set(FILES_PROJECT main.cpp 
                  adapter_wrapper.h 
				  builder.h
				  factory_method.h
				  object_pool.h
				  prototype.h
				  singleton.h singleton.cpp)
				  
add_executable(main ${FILES_PROJECT})