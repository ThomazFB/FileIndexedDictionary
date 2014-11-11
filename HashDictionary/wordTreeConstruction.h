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
#include "Queue.h"
#include "wordFinder.h"
#include "file.h"

Queue layerOneWordCounter(FILE * dictionary);

int layerTwoWordCounter(FILE * dictionary, char firstLayerWord);

int layerThreeWordCounter(FILE * dictionary, char firstLayerWord, char secondLayerWord);

int layerFourWordCounter(FILE * dictionary, char firstLayerWord, char secondLayerWord, char thirdLayerWord);

int getWordAmount(FILE * dictionary, int layer, char * actualWord);

int createRelativeChilds(FILE * dictionary, int layer, char * referenceLetters);

void startIndexGenerator(FILE * dictionary);

#endif /* defined(__HashDictionary__wordTreeConstruction__) */
