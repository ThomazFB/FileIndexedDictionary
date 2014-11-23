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
    fseek(indexedDictionary, (sizeof(char)), SEEK_CUR);
    fseek(indexedDictionary, (sizeof(int)), SEEK_CUR);
    fseek(indexedDictionary, (sizeof(int)), SEEK_CUR);
    fread(&numberOfChilds, sizeof(int), 1, indexedDictionary);
    for(int i = 0; i < numberOfChilds; i++)
    {
        fseek(indexedDictionary, (sizeof(char)), SEEK_CUR);
        fseek(indexedDictionary, (sizeof(int)), SEEK_CUR);
    }
}

void jumpStructAmount(int amount, FILE * indexedDictionary)
{
    WordIndex aux;
    setFileRegisterToStartPoint(indexedDictionary);
    for(int i = 0; i < amount; i++)
    {
        doJump(indexedDictionary);
    }
}

WordIndex readNode(FILE * indexedDictionary)
{
    WordIndex auxiliarNode;
    fread(&auxiliarNode.letter, sizeof(char), 1, indexedDictionary);
    fread(&auxiliarNode.nodePosition, sizeof(int), 1, indexedDictionary);
    fread(&auxiliarNode.verbatePosition, sizeof(int), 1, indexedDictionary);
    fread(&auxiliarNode.numberOfChilds, sizeof(int), 1, indexedDictionary);
    for(int i = 0; i < auxiliarNode.numberOfChilds; i++)
    {
        ChildInfo auxiliarChild;
        fread(&auxiliarChild.childLetter, sizeof(char), 1, indexedDictionary);
        fread(&auxiliarChild.fileReference, sizeof(int), 1, indexedDictionary);
        auxiliarNode.childs[i] = auxiliarChild;
    }
    return auxiliarNode;
}

void getVerbates(FILE * dictionary, int verbatePosition, char verbatesToLoad[10][1300])
{
    char * word;
    for(int i = 0; i < 10; i++)
    {
        word = findWordByPosition(dictionary, verbatePosition);
        puts(word);
        verbatePosition++;
    }
}

int findChild(char keyLetter, WordIndex node)
{
    for(int i = 0; i < node.numberOfChilds; i++)
    {
        if(node.childs[i].childLetter == keyLetter)
        {
            return node.childs[i].fileReference;
        }
    }
    return -1;
}

int getWordPosition(char * buffer, int layer, FILE * indexedDictionary)
{
    int nextPosition;
    WordIndex node;
    setFileRegisterToStartPoint(indexedDictionary);
    for(int i = 0; i < layer; i++)
    {
        node = readNode(indexedDictionary);
        nextPosition = findChild(buffer[i], node);
        if(nextPosition == -1)
        {
            return -1;
        }
        jumpStructAmount(nextPosition, indexedDictionary);
    }
    node = readNode(indexedDictionary);
    return node.verbatePosition;
}