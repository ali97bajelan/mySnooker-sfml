## SFML sample ping pong

This is sample SFML code for students of advanced programming in University of Tehran, Computer Science faculty - Spring 2018

To run this project you must install SFML library on your system (which is ubuntu for student)
so use this your package manager to install it

`$ apt install libsfml-dev`

and then you must configure your editor (Clion is recommended)

use this CMakeLists.txt:
```
cmake_minimum_required(VERSION 3.2)
project(SFMLPong)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(SFMLPong ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SFMLPong ${SFML_LIBRARIES})
endif()

```

remember to replace `SFMLPong` with your project name!

and paste FindSFML.cmake in cmake_modules folder (you can find it in this repository).

now your environment is ready and you can code ;)

good luck