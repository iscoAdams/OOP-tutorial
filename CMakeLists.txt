cmake_minimum_required(VERSION 3.0.0)

include(CTest)
enable_testing()

add_executable(
                OOP-tutorial 
                
                # final stuff
                src/final/main.cpp
                
                src/final/guitar-shop/v0.1/guitar.h
                src/final/guitar-shop/v0.1/inventory.h
                src/final/guitar-shop/v0.1/test-drive.h
                
                src/final/preface/airplane.h
                src/final/preface/box.h
                src/final/preface/city.h
                src/final/preface/mall.h
                src/final/preface/matrix.h
                src/final/preface/rabbit.h
                src/final/preface/youtubeChannel.h
                
                # utils stuff
                src/utils/io.h
                src/utils/out.h
                src/utils/timercpp.h

                # setup stuff
                src/setup/main.cpp

            )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# added comiler configuration (using linux-gnu)
set(CMAKE_C_COMPILER "C:\\MinGW\\bin\\gcc")
set(CMAKE_CXX_COMPILER "C:\\MinGW\\bin\\g++")
add_compile_options(-fconcepts)
add_compile_options(-std=c++2a)
add_compile_options(-pthread)
include(CPack)
