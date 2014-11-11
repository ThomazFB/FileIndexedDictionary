//
//  Queue.h
//  HashDictionary
//
//  Created by Thomaz Freitas Barbosa Cortez on 11/9/14.
//  Copyright (c) 2014 Thomaz F B. All rights reserved.
//

#ifndef __HashDictionary__Queue__
#define __HashDictionary__Queue__

#include <stdio.h>
#include <stdlib.h>
#include "typeDefinition.h"

#define TRUE 1
#define FALSE 0

typedef struct no {
    WordIndex info;
    struct no * prox;
} TNo;

typedef struct descritor {
    TNo *inicio, *fim;
} TDescritor;

typedef TDescritor * Queue;

int isEmpty (Queue fila);

void enqueue (Queue fila, WordIndex n);

WordIndex dequeue (Queue fila);

WordIndex head (Queue fila);

void initialize (Queue * fila);
#endif /* defined(__HashDictionary__Queue__) */
