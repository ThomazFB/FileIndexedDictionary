//
//  wordTreeIterator.c
//  HashDictionary
//
//  Created by Thomaz Freitas Barbosa Cortez on 11/15/14.
//  Copyright (c) 2014 Thomaz F B. All rights reserved.
//

#include "typeDefinition.h"
#include "wordFinder.h"
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

WordIndex readNode(FILE * indexedDictionary)
{
    WordIndex auxiliarNode;
    fread(&auxiliarNode.letter, sizeof(char), 1, indexedDictionary);
    fread(&auxiliarNode.verbatePosition, sizeof(int), 1, indexedDictionary);
    fread(&auxiliarNode.numberOfChilds, sizeof(int), 1, indexedDictionary);
    for(int i = 0; i < auxiliarNode.numberOfChilds; i++)
    {
        ChildInfo auxiliarChild;
        fread(&auxiliarChild.childLetter, sizeof(int), 1, indexedDictionary);
        fread(&auxiliarChild.fileReference, sizeof(int), 1, indexedDictionary);
        auxiliarNode.childs[i] = auxiliarChild;
    }
    return auxiliarNode;
}

void getVerbates(FILE * dictionary, int verbatePosition, char verbatesToLoad[10][1300])
{
    for(int i = 0; i < 10; i++)
    {
        strcpy(verbatesToLoad[i], findWordByPosition(dictionary, verbatePosition));
        verbatePosition++;
    }
}

void getWordPosition(char * buffer, int layer, FILE * indexedDictionary)
{
    //recebe um buffer e decide quantas iterações precisa para atingir a palavra
    for(int i = 0; i < layer; i++)
    {
        
    }
}