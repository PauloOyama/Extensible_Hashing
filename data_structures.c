#include "./data_structures.h\"



/* Structure to load directory*/
struct directory{
    int global_depth;
    /*Array of Buckets*/
    Bucket* buckets_pointers;
};

/* Structure to represent bucket*/
struct bucket{
    int local_depth;
    /*POINT TO DIR to go back ?*/
    Directory* back_dir;
    int* slot;
};
