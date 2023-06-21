## linux ou windows + wsl ubuntu apenas
## usuarios do replit a primeira compilação da versão extra pode demorar *um pouco*
## por favor não tentem com mingw ou msvc (compiladores do windows)

cmake_minimum_required(VERSION 3.2)
project(Autocomplete)

#include(./ncurses.cmake)

#com ncurses
#add_executable(words_complete_correct_extra
#               src/main_ncurses.cpp)
#target_include_directories(words_complete_correct_extra PUBLIC
#                           ./include
#                           ${NCURSES_INCLUDES}/ncurses)
#target_link_libraries(words_complete_correct_extra ncurses)


#sem ncurses
add_executable(words_complete_correct
               src/Autocomplete.cpp
               src/Autocorrect.cpp
               src/Interface.cpp
               src/leveshtein.cpp
               src/main.cpp
               src/StringUtil.cpp
               src/Database.cpp
              )
              
target_include_directories(words_complete_correct PUBLIC
                           include
                           )

## Testes Interface
set(TESTS "tests_interface")

add_executable(${TESTS} 
                tests/interface.cpp
                tests/test_manager/src/test_manager.cpp
                src/Interface.cpp
                src/Database.cpp
                src/Autocomplete.cpp
                src/Autocorrect.cpp
                src/leveshtein.cpp
                src/StringUtil.cpp
                )

target_include_directories(${TESTS} PUBLIC tests/test_manager/include include)

set_property(TARGET ${TESTS} PROPERTY CXX_STANDARD 14)

add_custom_target(
    run_tests_interface
    COMMAND ${TESTS}
    DEPENDS ${TESTS}
)

## Testes Database
set(TESTS "tests_database")

add_executable(${TESTS} tests/database.cpp tests/test_manager/src/test_manager.cpp src/Database.cpp src/StringUtil.cpp)

target_include_directories(${TESTS} PUBLIC tests/test_manager/include include)

set_property(TARGET ${TESTS} PROPERTY CXX_STANDARD 14)

add_custom_target(
    run_tests_database
    COMMAND ${TESTS}
    DEPENDS ${TESTS}
)

## Testes Autocomplete
set(TESTS "tests_autocomplete")

add_executable(${TESTS} 
                tests/autocomplete.cpp 
                tests/test_manager/src/test_manager.cpp 
                src/Autocomplete.cpp 
                src/Database.cpp
                src/StringUtil.cpp
            )

target_include_directories(${TESTS} PUBLIC tests/test_manager/include include)

set_property(TARGET ${TESTS} PROPERTY CXX_STANDARD 14)

add_custom_target(
    run_tests_autocomplete
    COMMAND ${TESTS}
    DEPENDS ${TESTS}
)

## Testes Autocorrect
set(TESTS_AUTOCORRECT "tests_autocorrect")

add_executable(${TESTS_AUTOCORRECT} tests/autocorrect.cpp tests/test_manager/src/test_manager.cpp src/Autocorrect.cpp src/Database.cpp src/leveshtein.cpp src/StringUtil.cpp)

target_include_directories(${TESTS_AUTOCORRECT} PUBLIC tests/test_manager/include include)

set_property(TARGET ${TESTS_AUTOCORRECT} PROPERTY CXX_STANDARD 14)

add_custom_target(
    run_tests_autocorrect
    COMMAND ${TESTS_AUTOCORRECT}
    DEPENDS ${TESTS_AUTOCORRECT}
)

## Testes
set(TESTS "tests")

add_executable(${TESTS} tests/main.cpp tests/test_manager/src/test_manager.cpp src/leveshtein.cpp)

target_include_directories(${TESTS} PUBLIC tests/test_manager/include include)

set_property(TARGET ${TESTS} PROPERTY CXX_STANDARD 14)

add_custom_target(
    run_tests
    COMMAND ${TESTS}
    DEPENDS ${TESTS}
)