//
//  wordTreeConstruction.c
//  HashDictionary
//
//  Created by Thomaz Freitas Barbosa Cortez on 11/8/14.
//  Copyright (c) 2014 Thomaz F B. All rights reserved.
//

#include "wordTreeConstruction.h"

//ChaosKeeper Tree implementation

void refreshTree(Dictionary * dictionary)
{
    dictionary->currentPosition = dictionary->tree;
}

WordIndex * isThereChildWithletter(WordIndex * currentPosition, char letter)
{
    for(int i = 0; i < currentPosition->numberOfChilds; i++)
    {
        if(currentPosition->childs[i].childLetter == letter)
        {
            return currentPosition->childs[i].node;
        }
    }
    return NULL;
}

void startTree(Dictionary * dictionary)
{
    WordIndex * newStart = (WordIndex *) malloc(sizeof(WordIndex));
    newStart->letter = '@';
    newStart->numberOfChilds = 0;
    dictionary->tree = newStart;
    dictionary->currentPosition = newStart;
}

void createNode(Dictionary * dictionary, WordIndex ** word, ChildInfo * newChild, int positionInFile, char index, int numberOfChilds,int *nodeID)
{
    (*word) = (WordIndex *) malloc(sizeof(WordIndex));
    (*word)->letter = index;
    (*word)->verbatePosition = positionInFile;
    (*word)->numberOfChilds = 0;
    (*newChild).childLetter = index;
    (*newChild).fileReference = (*nodeID);
    (*newChild).node = (*word);
    dictionary->currentPosition->childs[numberOfChilds] = (*newChild);
    dictionary->currentPosition->numberOfChilds++;
    (*nodeID)++;
}

void addNode(Dictionary * dictionary, int positionInFile, int * nodeID, char index)
{
    WordIndex * word;
    ChildInfo newChild;
    int numberOfChilds = dictionary->currentPosition->numberOfChilds;
    word = isThereChildWithletter(dictionary->currentPosition,index);
    if(word == NULL)
    {
        createNode(dictionary, &word, &newChild, positionInFile, index, numberOfChilds,nodeID);
    }
    dictionary->currentPosition = word;
}

void startDictionaryReading(Dictionary * dic, FILE * dictionary)
{
    char actualLine[1300];
    startTree(dic);
    setFileRegisterToStartPoint(dictionary);
    int nodeID = 1;
    for(int verbateNumber = 0; !feof(dictionary); verbateNumber++)
    {
        fgets(actualLine,1300,dictionary);
        for(int i = 0; i < 4 && actualLine[i] != '@'; i++)
        {
            addNode(dic,verbateNumber,&nodeID,actualLine[i]);
        }
        refreshTree(dic);
    }
}