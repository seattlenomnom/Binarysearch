/* binarysearch.c
 * soruce file for binarysearch, an example program that creates a dictionary,
 * (a sorted array of entries) and uses a binary search to find the definition
 * associated with the word.
 *
 * An example program from Kochan, Stephen, G., "Programming in C 3rd ed.",
 * Sams Publsihing, p.224.
 *
 * The function comparestrings() is replanced by the C standard library
 * function strcmp().
 *
 * Programmer: Mark Crapser
 *
 *
 */

/* includes */

#include <stdio.h>




/* structure defs */

struct entry
{
    char word[15];
    char definition[50];
};









/* function declarations */

int lookup(const struct entry dictionary[], const char search[],
        const int entries);











int main(int argc, char *argv[]) {



    /* create dictionary using an ordered array of entries. Why is it
     * here, shouldn't be outside main()? And maybe static? */


    const struct entry dictionary[100] =
    {{"aardvark", "a burrowing African mammal"                       },
        {"abyss", "a bottomless pit"                                 },
        {"acumen", "mentally sharp; keen"                            },
        {"addle", "to become confused"                               },
        {"aerie", "a high nest"                                      },
        {"affix", "to append; attach"                                },
        {"agar", "a jelly made from seaweed"                         },
        {"ahoy", "a nautical call of greeting"                       },
        {"aigrette", "an ornamental cluster of feathers"             },
        {"ajar", "partially opened"                                  }};

    /* variable defs/declarations */

    int num_of_entries = 10;
    char word[15];
    int entry_index;



    /* get word to look up */

    printf("Enter word: ");
    scanf("%14s", word);




    /* entry_index = lookup(dictionary, word, num_entries) */


    /* if(entry_index != -1)                      */
    /*    printf the info dictionary[entry_index] */
    /* else                                       */
    /*    printf(word not in dictionary)          */


    return(0);
}



int lookup(const struct entry dictionary[], const char search[],
        const int entries) {

    int index = 0;












    return(index);
}

