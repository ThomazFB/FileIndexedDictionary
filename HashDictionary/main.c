#include <stdio.h>
#include <stdlib.h>
#include "wordFinder.h"
#include "file.h"
#include "typeDefinition.h"
#include "wordTreeConstruction.h"
#include "wordTreeTranslation.h"

int main()
{
    FILE * dictionary = getDictionaryReference();
    FILE * indexedDictionary = getIndexedDictionaryReference();
    Dictionary * mainTreeDescriptor = (Dictionary *) malloc(sizeof(Dictionary));
    startDictionaryReading(mainTreeDescriptor, dictionary);
    startTranslation(mainTreeDescriptor,indexedDictionary);
    return 0;
}