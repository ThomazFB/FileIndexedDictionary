//
//  wordTreeIterator.h
//  HashDictionary
//
//  Created by Thomaz Freitas Barbosa Cortez on 11/15/14.
//  Copyright (c) 2014 Thomaz F B. All rights reserved.
//

#ifndef __HashDictionary__wordTreeIterator__
#define __HashDictionary__wordTreeIterator__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void doJump(FILE * indexedDictionary);

void jumpStructAmount(int amount, FILE * indexedDictionary);

WordIndex readNode(FILE * indexedDictionary);

void getVerbates(FILE * dictionary, int verbatePosition, char verbatesToLoad[10][1300]);

int findChild(char keyLetter, WordIndex node);

int getWordPosition(char * buffer, int layer, FILE * indexedDictionary);

#endif /* defined(__HashDictionary__wordTreeIterator__) */
