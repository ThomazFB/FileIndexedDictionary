cmake_minimum_required(VERSION 2.8.4)
project(HashDictionary)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    HashDictionary/file.c
    HashDictionary/file.h
    HashDictionary/main.c
    HashDictionary/main.h
    HashDictionary/typeDefinition.h
    HashDictionary/wordFinder.c
    HashDictionary/wordFinder.h
    HashDictionary/wordTreeConstruction.c
    HashDictionary/wordTreeConstruction.h
    HashDictionary/wordTreeIterator.c
    HashDictionary/wordTreeIterator.h
    HashDictionary/wordTreeTranslation.c
    HashDictionary/wordTreeTranslation.h)

add_executable(HashDictionary ${SOURCE_FILES})