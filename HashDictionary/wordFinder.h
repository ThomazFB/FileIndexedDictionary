//
//  wordFinder.h
//  HashDictionary
//
//  Created by Thomaz Freitas Barbosa Cortez on 11/8/14.
//  Copyright (c) 2014 Thomaz F B. All rights reserved.
//

#ifndef HashDictionary_wordFinder_h
#define HashDictionary_wordFinder_h

#include <stdio.h>
#include <stdlib.h>

char * removeWordFromLine(char * wordLine);

char * findWordByPosition(FILE * dictionary, int wordPosition);

#endif
