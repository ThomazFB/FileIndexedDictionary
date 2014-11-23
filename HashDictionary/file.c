//
//  file.c
//  HashDictionary
//
//  Created by Thomaz Freitas Barbosa Cortez on 11/8/14.
//  Copyright (c) 2014 Thomaz F B. All rights reserved.
//

#include "file.h"


FILE * getDictionaryReference()
{
    FILE * newFile = fopen("/Users/ThomazFB/Documents/Library/XCode/HashDictionary/Files/dictionary.txt","r");
    return newFile;
}

FILE * getIndexedDictionaryReference()
{
    FILE * newFile = fopen("/Users/ThomazFB/Documents/Library/XCode/HashDictionary/Files/indexedDictionary", "w+b");
    return newFile;
}

void setFileRegisterToStartPoint(FILE * dictionary)
{
    fseek(dictionary, 0, SEEK_SET);
}

void setFileRegisterToEndPoint(FILE * dictionary)
{
    fseek(dictionary, 0, SEEK_END);
    /*while(!feof(dictionary))
    {
        doJump(dictionary);
    }*/
}