#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int die( const char * msg );

int main(){
    char inName[81];
    printf("input file name: ");
    scanf("%s", inName) == 1 || die("input failure");
    
    FILE * fin;
    fin = fopen(inName, "r");
    if(errno){
        perror("opening input file");
        exit(EXIT_FAILURE);
    }
    
    char outName[81];
    printf("output file name: ");
    scanf("%s", outName) == 1 || die("input failure");
    
    FILE * fout;
    fout = fopen(outName, "w");
    if(errno){
        perror("opening output file");
        exit(EXIT_FAILURE);
    }
    
    unsigned qs = 0;
    double a, b, c, d;
    for( a, b, c, d; fscanf(fin, "%lf%lf%lf%lf", &a, &b, &c, &d) == 4; ){
        qs++;
        double mn, av, mx;
        mn = a<b && a<c && a<d ? a : b<c && b<d ? b : c<d ? c : d;
        av = (a+b+c+d) / 4;
        mx = a>b && a>c && a>d ? a : b>c && b>d ? b : c>d ? c : d;
        fprintf(fout, "<%f, %f, %f>:  %f  %f  %f  %f\n", mn, av, mx, a, b, c, d);
    } // for
    
    printf("%u quartets processed\n", qs);
    fclose(fout);
    if(ferror(fout)) die("problem writing/closing output file");
    fclose(fin);
} // main

int die( const char * msg ){
    printf( "Fatal error: %s\n", msg );
    exit( EXIT_FAILURE );
} // die