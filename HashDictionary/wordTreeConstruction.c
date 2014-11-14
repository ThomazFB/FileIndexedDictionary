//
//  wordTreeConstruction.c
//  HashDictionary
//
//  Created by Thomaz Freitas Barbosa Cortez on 11/8/14.
//  Copyright (c) 2014 Thomaz F B. All rights reserved.
//

#include "wordTreeConstruction.h"

#define letterAfterZ 123

//Trecho de código experimental, refatoramento pendente em vários métodos.

Queue layerOneWordCounter(FILE * dictionary)
{
    char referenceWord = 97;
    char * actualLine = (char *) malloc(sizeof(char) * 1300);
    WordIndex newWord;
    int wordCounter = 0;
    int positionCounter = 0;
    Queue queue;
    initialize(&queue);
    setFileRegisterToStartPoint(dictionary);
    
    while(!feof(dictionary) && referenceWord < letterAfterZ)
    {
        fgets(actualLine, 1300, dictionary);
        if(actualLine[0] == referenceWord)
        {
            newWord.numberOfChilds = positionCounter;
            enqueue(queue, newWord);
            wordCounter++;
            referenceWord++;
        }
        positionCounter++;
    }
    return queue;
}

int layerTwoWordCounter(FILE * dictionary, char firstLayerWord)
{
    char referenceWord = 97;
    char * actualLine = (char *) malloc(sizeof(char) * 1300);
    int wordCounter = 0;
    char * word;
    setFileRegisterToStartPoint(dictionary);
    while (!feof(dictionary) && referenceWord < letterAfterZ)
    {
        fgets(actualLine, 1300, dictionary);
        word = removeWordFromLine(actualLine);
        puts(word);
        if(actualLine[0] == firstLayerWord && referenceWord == actualLine[1])
        {
            wordCounter++;
            referenceWord++;
        }
    }
    
    return wordCounter;
}

int layerThreeWordCounter(FILE * dictionary, char firstLayerWord, char secondLayerWord)
{
    char referenceWord = 97;
    char * actualLine = (char *) malloc(sizeof(char) * 1300);
    int wordCounter = 0;
    char * word;
    setFileRegisterToStartPoint(dictionary);
    while (!feof(dictionary) && referenceWord < letterAfterZ)
    {
        word = removeWordFromLine(actualLine);
        puts(word);
        fgets(actualLine, 1300, dictionary);
        if(actualLine[0] == firstLayerWord && actualLine[1] == secondLayerWord && referenceWord == actualLine[2])
        {
            wordCounter++;
            referenceWord++;
        }
    }
    
    return wordCounter;
}

int layerFourWordCounter(FILE * dictionary, char firstLayerWord, char secondLayerWord, char thirdLayerWord)
{
    char referenceWord = 97;
    char * actualLine = (char *) malloc(sizeof(char) * 1300);
    int wordCounter = 0;
    char * word;
    setFileRegisterToStartPoint(dictionary);
    while (!feof(dictionary) && referenceWord < letterAfterZ)
    {
        word = removeWordFromLine(actualLine);
        puts(word);
        fgets(actualLine, 1300, dictionary);
        if(actualLine[0] == firstLayerWord && actualLine[1] == secondLayerWord && actualLine[2] == thirdLayerWord && referenceWord == actualLine[3])
        {
            
            wordCounter++;
            referenceWord++;
        }
    }
    
    return wordCounter;
}

int fourthLayerIteration(FILE * dictionary)
{
    char referenceLetters[3] = {97,97,97};
    int wordAmount = 0;
    while (referenceLetters[0] < letterAfterZ)
    {
        referenceLetters[1] = 97;
        while (referenceLetters[1] < letterAfterZ)
        {
            referenceLetters[2] = 97;
            while (referenceLetters[2] < letterAfterZ)
            {
                wordAmount = wordAmount + layerFourWordCounter(dictionary, referenceLetters[0], referenceLetters[1], referenceLetters[2]);
                referenceLetters[2]++;
            }
            referenceLetters[1]++;
        }
        referenceLetters[0]++;
    }
    return wordAmount;
}

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
    child = isThereChildWithLetter(dictionary->currentPosition,index); //se existe filho, retorna o endereço, se não, retorna nulo
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

void startIndexGenerator(FILE * dictionary)
{
    int wordAmount = 0;
    //wordAmount = layerOneWordCounter(dictionary);
    wordAmount = wordAmount + secondLayerIteration(dictionary);
    wordAmount = wordAmount + thirdLayerIteration(dictionary);
    wordAmount = wordAmount + fourthLayerIteration(dictionary);
    printf("%i",wordAmount);
}