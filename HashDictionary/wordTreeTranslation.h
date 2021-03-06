//
//  wordTreeTranslation.h
//  HashDictionary
//
//  Created by Thomaz Freitas Barbosa Cortez on 11/15/14.
//  Copyright (c) 2014 Thomaz F B. All rights reserved.
//

#ifndef __HashDictionary__wordTreeTranslation__
#define __HashDictionary__wordTreeTranslation__

#include "wordTreeConstruction.h"
#include "file.h"
#include "list.h"
#include "typeDefinition.h"
#include <stdio.h>
#include <stdlib.h>

void saveNode(WordIndex * node, FILE * indexedDictionary);

void preOrderTranslation(WordIndex * node, FILE * indexedDictionary, listNode ** list);

void saveListInFile(listNode * list, FILE * indexedDictionary);

void startTranslation(Dictionary * dictionary, FILE * indexedDictionary);

#endif /* defined(__HashDictionary__wordTreeTranslation__) */
