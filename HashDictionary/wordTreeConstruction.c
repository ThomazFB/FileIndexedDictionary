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

WordIndex * isThereChildWithletter(WordIndex * node, char letter)
{
    for(int i = 0; i < node->numberOfChilds; i++)
    {
        if(node->childs[i].letter == letter)
        {
            return node->childs[i].node;
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

void createNode(Dictionary * dictionary, WordIndex ** word, ChildInfo * newChild, int positionInFile, char index, int numberOfChilds)
{
    (*word) = (WordIndex *) malloc(sizeof(WordIndex));
    (*word)->letter = index;
    (*word)->wordPosition = positionInFile;
    (*word)->numberOfChilds = 0;
    (*newChild).letter = index;
    (*newChild).position = positionInFile;
    (*newChild).node = (*word);
    dictionary->currentPosition->childs[numberOfChilds] = (*newChild);
    dictionary->currentPosition->numberOfChilds++;
}

void addNode(Dictionary * dictionary, int positionInFile, char index)
{
    WordIndex * word;
    ChildInfo newChild;
    int numberOfChilds = dictionary->currentPosition->numberOfChilds;
    word = isThereChildWithletter(dictionary->currentPosition,index); //se existe filho, retorna o endereço, se não, retorna nulo
    if(word == NULL)
    {
        createNode(dictionary, &word, &newChild, positionInFile, index, numberOfChilds);
    }
    dictionary->currentPosition = word;
}

void startDictionaryReading(Dictionary * dic, FILE * dictionary)
{
    char actualLine[1300];
    startTree(dic);
    setFileRegisterToStartPoint(dictionary);
    for(int countLine = 0; !feof(dictionary); countLine++)
    {
        fgets(actualLine,1300,dictionary);
        for(int i = 0; i < 4 && actualLine[i] != '@'; i++)
        {
            addNode(dic,countLine,actualLine[i]);
        }
        refreshTree(dic);
    }
}