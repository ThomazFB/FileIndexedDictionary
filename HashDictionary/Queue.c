//
//  Queue.c
//  HashDictionary
//
//  Created by Thomaz Freitas Barbosa Cortez on 11/9/14.
//  Copyright (c) 2014 Thomaz F B. All rights reserved.
//

#include "Queue.h"
#define TRUE 1
#define FALSE 0

int isEmpty (Queue fila) {
    if (fila->inicio == NULL)
        return TRUE;
    else
        return FALSE;
}

void enqueue (Queue queue, WordIndex n) {
    TNo * novo;
    novo = (TNo *) malloc (sizeof (TNo));
    novo->info = n;
    novo->prox = NULL;
    if (isEmpty (queue) == TRUE)
        queue->inicio = novo;
    else
        queue->fim->prox = novo;
    queue->fim = novo;
}

WordIndex dequeue (Queue fila) {
    TNo * aux;
    WordIndex n;
    
    aux = fila->inicio;
    fila->inicio = fila->inicio->prox;
    if (isEmpty (fila) == TRUE)
        fila->fim = NULL;
    n = aux->info;
    free (aux);
    return n;
}

WordIndex head (Queue fila) {
    return fila->inicio->info;
}

void initialize (Queue * fila) {
    *fila = (TDescritor *) malloc (sizeof (TDescritor));
    (*fila)->inicio = NULL;
    (*fila)->fim = NULL;
}