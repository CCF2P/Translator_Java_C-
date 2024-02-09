cmake_minimum_required(VERSION 3.8)
project(Translator_Java_CS)

set(SOURCES 
    main.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/Lexer/Lexer.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/Lexer/Lexer.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/Lexer/Token/Token.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/Utils/Help.h)

add_executable(main ${SOURCES})