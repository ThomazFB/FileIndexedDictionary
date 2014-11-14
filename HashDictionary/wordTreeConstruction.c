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
    WordIndex * child;
    child = isThereChildWithletter(dictionary->currentPosition,index); //se existe filho, retorna o endereço, se não, retorna nulo
    if(child == NULL)
    {
        child = (WordIndex *) malloc(sizeof(WordIndex));
        child->letter = index;
        child->wordPosition = positionInFile;
        child->numberOfChilds = 0;
    }
    dictionary->currentPosition = child;
}

void startTree(Dictionary * dictionary)
{
    WordIndex * newStart = (WordIndex *) malloc(sizeof(WordIndex));
    newStart->letter = '@';
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