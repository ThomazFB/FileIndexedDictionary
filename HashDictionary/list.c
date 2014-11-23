//
//  list.c
//  HashDictionary
//
//  Created by Thomaz Freitas Barbosa Cortez on 11/22/14.
//  Copyright (c) 2014 Thomaz F B. All rights reserved.
//

#include "list.h"

listNode * createList()
{
    return NULL;
}

void listAdd(listNode ** list, WordIndex * info)
{
    listNode * newNode;
    listNode * aux;
    listNode * aux2;
    newNode = (listNode *) malloc (sizeof(listNode));
    newNode->info = info;
    newNode->next = NULL;
    aux = (*list);
    if(info == NULL)
    {
        return;
    }
    if(*list == NULL)
    {
        (*list) = newNode;
        return;
    }
    
    else if(newNode->info->nodePosition < aux->info->nodePosition)
    {
        newNode->next = (*list);
        (*list) = newNode;
        return;
    }
    
    else
    {
        if(aux->next == NULL)
        {
            aux->next = newNode;
            return;
        }
        else if(newNode->info->nodePosition < aux->info->nodePosition)
        {
            newNode->next = aux->next;
            aux->next = newNode;
            return;
        }
        else
        {
            aux2 = aux->next;
            while(aux2 != NULL)
            {
                if(newNode->info->nodePosition == aux->info->nodePosition)
                {
                    return;
                }
                else if(newNode->info->nodePosition < aux2->info->nodePosition)
                {
                    newNode->next = aux2;
                    aux->next = newNode;
                    return;
                }
                aux = aux2;
                aux2 = aux2->next;
            }
            if(newNode->info->nodePosition == aux->info->nodePosition)
            {
                return;
            }
            else
            {
                (aux)->next = newNode;
                return;
            }
        }
    }
}