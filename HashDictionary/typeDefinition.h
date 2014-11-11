//
//  typeDefinition.h
//  HashDictionary
//
//  Created by Thomaz Freitas Barbosa Cortez on 11/8/14.
//  Copyright (c) 2014 Thomaz F B. All rights reserved.
//

#ifndef HashDictionary_typeDefinition_h
#define HashDictionary_typeDefinition_h


typedef struct childInfo
{
    char letter;
    char position;
}ChildInfo;

typedef struct wordIndex
{
    char letter;
    char wordPosition;
    char numberOfChilds;
    ChildInfo * childs;
}WordIndex;

typedef struct dictionary
{
    WordIndex * trees;
}Dictionary;

#endif
