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
    setFileRegisterToStartPoint(dictionary);
    while (!feof(dictionary) && referenceWord < letterAfterZ)
    {
        fgets(actualLine, 1300, dictionary);
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
    setFileRegisterToStartPoint(dictionary);
    while (!feof(dictionary) && referenceWord < letterAfterZ)
    {
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
    setFileRegisterToStartPoint(dictionary);
    while (!feof(dictionary) && referenceWord < letterAfterZ)
    {
        fgets(actualLine, 1300, dictionary);
        if(actualLine[0] == firstLayerWord && actualLine[1] == secondLayerWord && actualLine[2] == thirdLayerWord && referenceWord == actualLine[3])
        {
            
            wordCounter++;
            referenceWord++;
        }
    }
    
    return wordCounter;
}

int getWordAmount(FILE * dictionary, int layer, char * actualWord)
{
    switch (layer)
    {
        case 1:
            //return layerOneWordCounter(dictionary);
            
        case 2:
            return layerTwoWordCounter(dictionary, actualWord[0]);
            
        case 3:
            return layerThreeWordCounter(dictionary, actualWord[0], actualWord[1]);
            
        case 4:
            return layerFourWordCounter(dictionary, actualWord[0], actualWord[1], actualWord[2]);
            
        default:
            return -1;
    }
}

int createRelativeChilds(FILE * dictionary, int layer, char * referenceLetters)
{
    int wordAmount = getWordAmount(dictionary,layer,referenceLetters);
    return wordAmount;
}

int secondLayerIteration(FILE * dictionary)
{
    char referenceLetter = 97;
    int wordAmount = 0;
    while (referenceLetter < letterAfterZ)
    {
        wordAmount = wordAmount + layerTwoWordCounter(dictionary, referenceLetter);
        referenceLetter++;
    }
    return wordAmount;
}

int thirdLayerIteration(FILE * dictionary)
{
    char referenceLetters[2] = {97,97};
    int wordAmount = 0;
    while (referenceLetters[0] < letterAfterZ)
    {
        referenceLetters[1] = 97;
        while (referenceLetters[1] < letterAfterZ)
        {
            wordAmount = wordAmount + layerThreeWordCounter(dictionary, referenceLetters[0], referenceLetters[1]);
            referenceLetters[1]++;
        }
        referenceLetters[0]++;
    }
    return wordAmount;
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

void startIndexGenerator(FILE * dictionary)
{
    int wordAmount = 0;
    //wordAmount = layerOneWordCounter(dictionary);
    wordAmount = wordAmount + secondLayerIteration(dictionary);
    wordAmount = wordAmount + thirdLayerIteration(dictionary);
    wordAmount = wordAmount + fourthLayerIteration(dictionary);
    printf("%i",wordAmount);
}