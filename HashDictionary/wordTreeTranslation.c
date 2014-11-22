//
//  wordTreeTranslation.c
//  HashDictionary
//
//  Created by Thomaz Freitas Barbosa Cortez on 11/15/14.
//  Copyright (c) 2014 Thomaz F B. All rights reserved.
//

#include "wordTreeTranslation.h"

void saveNode(WordIndex * node, FILE * indexedDictionary)
{
    ChildInfo child;
    fwrite(&(node->letter), sizeof(char), 1, indexedDictionary);
    fwrite(&(node->nodePosition), sizeof(int), 1, indexedDictionary);
    if (node->nodePosition == 27) {
        
    }
    fwrite(&(node->verbatePosition),sizeof(int),1,indexedDictionary);
    fwrite(&(node->numberOfChilds),sizeof(int),1,indexedDictionary);
    for(int i = 0; i < node->numberOfChilds; i++)
    {
        child = node->childs[i];
        fwrite(&(child.childLetter), sizeof(char), 1, indexedDictionary);
        fwrite(&(child.fileReference), sizeof(int), 1, indexedDictionary);
    }
}

void preOrderTranslation(WordIndex * node, FILE * indexedDictionary)
{
    saveNode(node,indexedDictionary);
    for(int i = 0; i < node->numberOfChilds; i++)
    {
        preOrderTranslation(node->childs[i].node,indexedDictionary);
    }
}

void startTranslation(Dictionary * mainTreeDescriptor, FILE * indexedDictionary)
{
    setFileRegisterToStartPoint(indexedDictionary);
    preOrderTranslation(mainTreeDescriptor->tree,indexedDictionary);
}