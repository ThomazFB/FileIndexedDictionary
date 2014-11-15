#include <stdio.h>
#include <stdlib.h>
#include "wordFinder.h"
#include "file.h"
#include "typeDefinition.h"
#include "wordTreeConstruction.h"

int main()
{
    FILE * dictionary = getDictionaryReference();
    Dictionary * mainTreeDescriptor = (Dictionary *) malloc(sizeof(Dictionary));
    startDictionaryReading(mainTreeDescriptor, dictionary);
    return 0;
}