cmake_minimum_required(VERSION 3.8)
project(Translator_Java_CS)

set(SOURCES 
    main.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/Lexer/Lexer.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Lexer/Lexer.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/Lexer/Token/Token.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Utils/Help.hpp)

add_executable(main ${SOURCES})