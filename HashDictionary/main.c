#include <stdio.h>
#include <stdlib.h>
#include "wordFinder.h"
#include "file.h"
#include "typeDefinition.h"
#include "wordTreeConstruction.h"
#include "wordTreeTranslation.h"
#include "wordTreeIterator.h"

int main()
{
    char * buffer = (char *) malloc(sizeof(char) * 4);
    char * word;
    buffer[0] = 's';
    buffer[1] = 'u';
    buffer[2] = 'r';
    buffer[3] = 'u';
    char verbates[10][1300];
    FILE * dictionary = getDictionaryReference();
    FILE * indexedDictionary = getIndexedDictionaryReference();
    Dictionary * mainTreeDescriptor = (Dictionary *) malloc(sizeof(Dictionary));
    startDictionaryReading(mainTreeDescriptor, dictionary);
    startTranslation(mainTreeDescriptor,indexedDictionary);
    getVerbates(dictionary, getWordPosition(buffer, 4, indexedDictionary), verbates);
    return 0;
}