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
 * Brain storming:
 *   Develop "projects", but within each project study algorithms. Maybe
 *   go through an Algorithm text book.
 */

/* includes */

#include <stdio.h>
#include <string.h>




/* structure defs */

struct entry
{
    char word[15];
    char definition[50];
};


/* function declarations */

int my_strcmp(const char dictionaryword[], const char search[]);
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


    /* lookup(a dictionary, the word to lookup, the number of entries
     * in the dictionary)
     *
     * a dictionary: various dictionaries could be passed.
     * the word to look up:
     * the number of entries: maybe a better way to handle this.
     * entry_index: the index into the dictionary where the definition is
     * located.
     *
     * another way: definition of word = lookup(dictionary, word, max defs)
     *
    */

     entry_index = lookup(dictionary, word, num_of_entries);


     if(entry_index != -1)
        printf("%s\n", dictionary[entry_index].definition);
     else
         printf("Sorry, the word %s is not in my dictionary.\n", word);


    return(0);
}



int lookup(const struct entry dictionary[], const char search[],
        const int entries) {

    /* lookup:
     *   input:
     *     dictionary - an array of entries[word, definition].
     *     searrch - aString, the word to lookup.
     *     entries - the maximum number of items in the dictionary.
     *
     *   output:
     *     index - the position of the definition. -1 for no definition
     *     found, or anInteger of the position in dictionary where the
     *     definition is located.
     *
     *  Notes: this search uses a binary search technique. The technique
     *  assumes that the dictionary is lexigraphically ordered.
     *
    */


    int index = 0;
    int low = 0;
    int high = entries - 1;
    int mid;
    int result;

    while(low <= high) {
        mid = (low + high) / 2;
        result = my_strcmp(dictionary[mid].word, search);

        if(result == -1)
            low = mid + 1;
        else if(result == 1)
            high = mid - 1;
        else
            return(mid);    /* found it */
    }

    return(-1);


}


int my_strcmp(const char dictionaryword[], const char search[]) {

    /* my_strcmp()
     *   input: adictionary word and the search word
     *   output: -1 dictionary.word < search word
     *   output: 1 dictionary.word > search word
     *   output: 0 dictionary.word = search word
     *
    */

    int result, cmp_result;

    cmp_result = strcmp(dictionaryword, search);

    if(cmp_result > 0)
        result = 1;
    else if(cmp_result < 0)
        result = -1;
    else
        result = 0;

    return(result);
}
