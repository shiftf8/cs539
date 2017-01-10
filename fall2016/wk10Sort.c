/*
    insertion sort
    good:
    simple to program
    efficient for small arrays
    in-place, doesn't require more than a constant amount of memory
    we can sort as the data comes in (adaptive sort)
    stable sort
    bad:
    very inefficient for large arrays
    
    void qsort( void * ptr, size_t els, size_t bytesPerEl,
                int (*comp)( const void * p0, const void * p1));
    
    if p0 must come before p1: comp returns < 0
    if p0 must come after p1: comp returns > 0
    if either p0 or p1 can come first: comp returns 0
    
    
*/

#include <stdio.h>
#include <stdlib.h> // sort, rand, exit

int compare0( const void * p0, const void * p1 ); // increasing
int compare1( const void * p0, const void * p1 ); // decreasing
int die( const char * msg );
void show( const unsigned arr[], unsigned els );
void sort( unsigned arr[], unsigned els );
void exchange( unsigned * a, unsigned * b );

int main(){
    unsigned i = 0;
    unsigned * a = malloc( 10 * sizeof(*a));
    if( a == NULL)  die( "allocation failure" );
    for( i;  i < 10;  i++  )
        a[i] = rand(); // [0, 32768)
    show( a, 10 );
    qsort( a, 10, sizeof(*a), a[0]%2 ? compare1 : compare0);
    //sort( a, 10 );
    show( a, 10 );
} // main

int compare0( const void * p0, const void * p1 ){ // increasing
    unsigned u0 = *(const unsigned *)p0;
    unsigned u1 = *(const unsigned *)p1;
    int ret = 0;
    if( u0 < u1 )  ret = -1;
    if( u0 > u1 )  ret =  1;
    static unsigned comparisons;
    comparisons++;
    //printf( "%u: comparing %u and %u, returning %i\n", comparisons,
    //    u0, u1, ret
    //);
    return ret;
}

int compare1( const void * p0, const void * p1 ){ // decreasing
    unsigned u0 = *(const unsigned *)p0;
    unsigned u1 = *(const unsigned *)p1;
    int ret = 0;
    if( u0 < u1 )  ret =  1;
    if( u0 > u1 )  ret = -1;
    static unsigned comparisons;
    comparisons++;
    //printf( "%u: comparing %u and %u, returning %i\n", comparisons,
    //    u0, u1, ret
    //);
    return ret;
}

int die( const char * msg ){
    printf( "Fatal error: %s\n", msg );
    exit( EXIT_FAILURE );
} // die

void show( const unsigned arr[], unsigned els ){
    if( els > 0 ){
        printf( "  %u", arr[0] );
        show( arr+1, els-1);
    }else{
        printf( "\n" );
    }
}

void sort( unsigned arr[], unsigned els ){
    unsigned j = 1;
    
    for(  j; j < els; j++ ){
        unsigned i = j;
        for(  i; i > 0 && arr[i-1] > arr[i];  i-- )
            exchange( arr+(i-1), arr+i );
    }
}
void exchange( unsigned * a, unsigned * b ){
    unsigned t = *a;
    *a = *b;
    *b = t;
}