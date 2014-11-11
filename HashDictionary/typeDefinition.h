//
//  typeDefinition.h
//  HashDictionary
//
//  Created by Thomaz Freitas Barbosa Cortez on 11/8/14.
//  Copyright (c) 2014 Thomaz F B. All rights reserved.
//

#ifndef HashDictionary_typeDefinition_h
#define HashDictionary_typeDefinition_h

typedef enum boolean
{
    TRUE,
    FALSE
}bool;

typedef struct childInfo
{
    char letter;
    char position;
    struct wordIndex * node;
}ChildInfo;

typedef struct wordIndex
{
    char letter;
    char wordPosition;
    char filePosition;
    char numberOfChilds;
    ChildInfo * childs;
}WordIndex;

typedef struct dictionary
{
    WordIndex * trees;
    char * fileTrees;
}Dictionary;

#endif
