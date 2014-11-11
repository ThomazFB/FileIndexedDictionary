#include <stdio.h>
#include <stdlib.h>
#include "wordFinder.h"
#include "file.h"
#include "typeDefinition.h"
#include "wordTreeConstruction.h"

int main()
{
    FILE * dictionary = getDictionaryReference();
    //startIndexGenerator(dictionary);
    char * line = findWordByPosition(dictionary, 33000);
    puts(line);
    return 0;
}