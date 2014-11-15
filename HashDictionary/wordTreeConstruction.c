//
//  wordTreeConstruction.c
//  HashDictionary
//
//  Created by Thomaz Freitas Barbosa Cortez on 11/8/14.
//  Copyright (c) 2014 Thomaz F B. All rights reserved.
//

#include "wordTreeConstruction.h"

void getFirstWord(char * line, char * buffer)
{
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

void addNode(Dictionary * dictionary, char positionInFile, char index)
{
    WordIndex * word;
    ChildInfo newChild;
    int numberOfChilds = dictionary->currentPosition->numberOfChilds;
    word = isThereChildWithletter(dictionary->currentPosition,index); //se existe filho, retorna o endereço, se não, retorna nulo
    if(word == NULL)
    {
        word = (WordIndex *) malloc(sizeof(WordIndex));
        word->letter = index;
        word->wordPosition = positionInFile;
        word->numberOfChilds = 0;
        newChild->letter = index;
        newChild->position = positionInFile;
        newChild->node = word;
        dictionary->currentPosition->childInfo[numberOfChilds] = child;
    }
    dictionary->currentPosition = word;
}

void startDictionaryReading(Dictionary * dic, FILE * dictionary)
{
    char * actualLine;
    startTree(dic);
    for(int countLine = 0; !feof(dictionary); countLine++)
    {
        actualLine = fgets(dictionary);
        for(int i = 0; i < 4 && actualLine[i] != '@'; i++)
        {
            addNode(dic,countLine,actualLine[i]);
        }
        refreshTree(dic);
    }
}

void startTree(Dictionary * dictionary)
{
    WordIndex * newStart = (WordIndex *) malloc(sizeof(WordIndex));
    newStart->letter = '@';
    newStart->numberOfChilds = 0;
    dictionary->tree = newStart;
    dictionary->currentPosition = newStart;

}

void refreshTree(Dictionary * dictionary)
{
    dictionary->currentPosition = dictionary->tree;
}

/*Dictionary * createTree(FILE * dictionary)
{
    //Leio cada palavra, e verifico suas 4 primeiras letras
    //chamo um método que verifica se tal combinação na arvore
    //Se sim, insere
    //Se nao, ignora
    Dictionary * tree = (Dictionary *) malloc(sizeof(<#expression-or-type#>))
    char * line = (char *) malloc(sizeof(char) * 1300);
    char * buffer = (char *) malloc(sizeof(char) * 5);
    setFileRegisterToStartPoint(dictionary);
    while (!feof(dictionary))
    {
        fgets(line, 1300, dictionary);
        getFirstWord(line, buffer);
        addWord(line);
    }
    return NULL;
}*/