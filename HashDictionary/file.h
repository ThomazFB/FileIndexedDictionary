//
//  file.h
//  HashDictionary
//
//  Created by Thomaz Freitas Barbosa Cortez on 11/8/14.
//  Copyright (c) 2014 Thomaz F B. All rights reserved.
//

#ifndef HashDictionary_file_h
#define HashDictionary_file_h

#include <stdio.h>
#include <stdlib.h>
#include "wordTreeIterator.h"

FILE * getDictionaryReference();

FILE * getIndexedDictionaryReference();

void setFileRegisterToStartPoint(FILE * dictionary);

void setFileRegisterToEndPoint(FILE * dictionary);

#endif
