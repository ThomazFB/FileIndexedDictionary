//
//  list.h
//  HashDictionary
//
//  Created by Thomaz Freitas Barbosa Cortez on 11/22/14.
//  Copyright (c) 2014 Thomaz F B. All rights reserved.
//

#ifndef __HashDictionary__list__
#define __HashDictionary__list__

#include "typeDefinition.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    WordIndex * info;
    struct node * next;
}listNode;

listNode * createList();

void listAdd(listNode ** list, WordIndex * info);

#endif /* defined(__HashDictionary__list__) */
