//
//  wordTreeIterator.c
//  HashDictionary
//
//  Created by Thomaz Freitas Barbosa Cortez on 11/15/14.
//  Copyright (c) 2014 Thomaz F B. All rights reserved.
//

#include "wordTreeIterator.h"
#include "file.h"


void doJump(FILE * indexedDictionary)
{
    int numberOfChilds;
    fseek(indexedDictionary, (sizeof(char) + sizeof(int)), SEEK_CUR);
    fread(&numberOfChilds, sizeof(int), 1, indexedDictionary);
    for(int i = 0; i < numberOfChilds; i++)
    {
        fseek(indexedDictionary, (sizeof(char) + sizeof(int)), SEEK_CUR);
    }
}

void jumpStructAmount(int amount, FILE * indexedDictionary)
{
    setFileRegisterToStartPoint(indexedDictionary);
    for(int i = amount; i < amount; i++)
    {
        doJump(indexedDictionary);
    }
}

void getWordPosition(char * buffer, int layer, FILE * indexedDictionary)
{
    int arraySize = layer - 1;
    
    for(int i = 0; i < layer; i++)
    {
        
    }
}