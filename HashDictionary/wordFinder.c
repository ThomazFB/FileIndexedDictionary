//
//  wordFinder.c
//  HashDictionary
//
//  Created by Thomaz Freitas Barbosa Cortez on 11/8/14.
//  Copyright (c) 2014 Thomaz F B. All rights reserved.
//

#include "wordFinder.h"

char * removeWordFromLine(char * wordLine)
{
    char * word;
    int wordSize = 1;
    int cont = 0;
    while (wordLine[cont] != '@' && wordLine[cont] != '\n')
    {
        if(cont > 1300)
        {
            puts(wordLine);
        }
        wordSize++;
        cont++;
    }
    word = (char *) malloc(sizeof(char) * wordSize);
    cont = 0;
    while(wordLine[cont] != '@')
    {
        word[cont] = wordLine[cont];
        cont++;
    }
    word[cont] = '\0';
    return word;
}

char * findWordByPosition(FILE * dictionary, int wordPosition)
{
    int cont = 0;
    char * line = (char *) malloc(sizeof(char) * 1300);
    while ((!feof(dictionary)) && cont <= wordPosition)
    {
        fgets(line, 1300, dictionary);
        cont++;
    }
    
    return removeWordFromLine(line);
}