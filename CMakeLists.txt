cmake_minimum_required(VERSION 3.6)
project(TP3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_INCLUDE_PATH /usr/local/boost_1_63_0/)
set(CMAKE_LIBRARY_PATH /usr/local/boost_1_63_0/lib)

set(BOOST_ROOT "/usr/local/boost_1_63_0")
find_package(Boost 1.63.0)

include_directories(/usr/local/boost_1_63_0/)
set(SOURCE_FILES main.cpp Application.cpp Catalogue.cpp Catalogue.h Trajet.cpp Trajet.h TrajetSimple.cpp TrajetSimple.h TrajetCompose.cpp TrajetCompose.h ListeT.cpp ListeT.h)
add_executable(TP3 ${SOURCE_FILES})