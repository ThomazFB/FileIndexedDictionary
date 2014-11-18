//
//  wordTreeConstruction.h
//  HashDictionary
//
//  Created by Thomaz Freitas Barbosa Cortez on 11/8/14.
//  Copyright (c) 2014 Thomaz F B. All rights reserved.
//

#ifndef __HashDictionary__wordTreeConstruction__
#define __HashDictionary__wordTreeConstruction__


#include <stdio.h>
#include <stdlib.h>
#include "typeDefinition.h"
#include "wordFinder.h"
#include "file.h"

void createNode(Dictionary * dictionary, WordIndex ** word, ChildInfo * newChild, int positionInFile, char index, int numberOfChilds, int * nodeID);

WordIndex * isThereChildWithletter(WordIndex * currentPosition, char letter);

void addNode(Dictionary * dictionary, int positionInFile, int * nodeID, char index);

void startDictionaryReading(Dictionary * dic, FILE * dictionary);

void startTree(Dictionary * dictionary);

void refreshTree(Dictionary * dictionary);

#endif /* defined(__HashDictionary__wordTreeConstruction__) */
