#include <stdlib.h>
#include <stdio.h>
#include "functions.h"
#include <./data_structures.c>

/*init_dir() return a directory with global depth of [initial_d] and 2^[initial_d] spaces, i.e,
[initial_d] is the number of bits to be seen while indexing each data entry*/
Directory init_dir(int initial_d)
{
    int i = 0;
    int spaces = 1;
    Directory dir = (Directory)malloc(sizeof(Directory));

    if (dir == NULL)
    {
        printf("Error while creating directory... Exiting.\n");
        exit(0);
    }
    else
    {
        dir->global_depth = initial_d;

        for (i = 0; i < initial_d; i++)
            spaces *= 2;

        // Create Table with 2 ^ [initial_d] spaces
        dir->buckets_pointers = (Bucket *)malloc(spaces * sizeof(Bucket));

        if (dir->buckets_pointers == NULL)
            printf("Error\n");

        // Create Bucket Pointers
        for (i = 0; i < spaces; i++)
        {
            dir->buckets_pointers[i] = init_bucket(initial_d, i, &dir);
            if (dir->buckets_pointers[i] == NULL)
                printf("Error in directory pointer %d\n", &i);
        }
    }
}

/*init_bucket() return a bucket with local depth of [initial_d], and 2^[initial_d] spaces, the [bucket_id]
is the h(k) value of the hash function and [dir] it's just a pointer to go back to the
origin directory more easily */
Bucket init_bucket(int initial_d, int bucket_id, Directory *dir)
{
    int i = 0;
    int spaces = 1;
    Bucket bucket = (Bucket)malloc(sizeof(Bucket));

    for (i = 0; i < initial_d; i++)
        spaces *= 2;

    if (bucket == NULL)
    {
        printf("Error while creating bucket %d... Exiting.\n", &bucket_id);
        exit(0);
    }
    else
    {
        bucket->local_depth = initial_d;
        bucket->back_dir = dir;
        bucket->slot = (int *)malloc(spaces * sizeof(int));
        if (bucket->slot == NULL)
        {
            printf("Error while creating spaces in bucket %d... Exiting.\n", &bucket_id);
            exit(0);
        }
        else
        {
            for (i = 0; i < spaces; i++)
                bucket->slot[i] = 0;
        }
    }
    return bucket;
}