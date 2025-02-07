#include "hashTable.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
size = INITIAL_HT_SIZE_FACTOR*N;
    hashTable = (listT*)malloc(size*sizeof(listT));
    int i;
    for (i = 0; i < size; i++) {
        hashTable[i].head = hashTable[i].tail = NULL;
        hashTable[i].size = 0;
    }
}

void insertElement(char *element)
{
    //! insert an element
    int k;
    k = hashFunction(element);
    addToList(&hashTable[k], element);

}

int hashFunction0(char * content,int i)
{
    //! keep in mind, size in this case simply means the number of buckets
    return content[0]/4 % size;
}
int hashFunction1(char * content, int i)
{
	//! keep in mind, size in this case simply means the number of buckets

	unsigned long long h = 0xcbf29ce484222325ULL;
	int len;

	len = strlen(content);

	for ( i = 0; i < len; i++ )
		h = ( h ^ content[i] ) * 0x100000001b3ULL;

	return (h + i) % size;
}

int hashFunction(char * content)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return sum % size;
}

void computeDistributionsPerBucket()
{
    //! computes the distribution of elements for each bucket
    //! the output should look something like:
    /**
        MAX = 'x' * 20

        B0: ********** (~50%)
        B1: ************ (~60%)
        B2: ****** (~30%)
        B3: ******* (~35%)
        .....


        hint : the bigger you choose X, the better approximation
        hint2: choose it somewhere between 20-40 such that it fits in one row in the console nicely
    */
    int maxSize = 0;
    int i,j;
    for ( i = 0; i < size; i++)
        if (hashTable[i].size > maxSize)
            maxSize = hashTable[i].size;

    for ( i = 0; i < size; i++) {
        printf("B%i: ", i);
        int a = (float)hashTable[i].size/maxSize * 60.0;
        for (j = 0; j < a; j++)
            printf("*");
        printf("\n");
    }
}
