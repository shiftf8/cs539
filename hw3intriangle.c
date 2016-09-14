// CS 539, HW 3 Triangle, Rob Lamog

#include <stdio.h>
#include <stdlib.h>

int inTriangle( double x0, double y0, double x1, double y1,
                double x2, double y2, double xp, double yp );
    //  Is the point (xp, yp) on the interior of the triangle made up of three
    //  points (x0, y0), (x1, y1), (x2, y2)? We return 0 or 1 for no or yes.
    //  (If the point is exactly on the triangle, we return 0)
    //  For instance, if the args were
    //      (1.0, 1.0, -1.0, -2.0, 3.0, 2.0,   0.5, -0.4)
    //  we would return 1, since the triangle made up of points
    //  (1.0, 1.0), (-1.0, -2.0), and (3.0, 2.0) encloses the point
    //  (0.5, -0.4), but if the args were
    //      (1.0, 1.0, -1.0, -2.0, 3.0, 2.0,   0.5, -0.6)
    //  we would return 0, since that same triangle does not enclose the point
    //  (0.5, -0.6).
    //  The three points of the triangle may appear in any order.
    
int die( const char * msg );

int main(){
    double a0, b0, a1, b1, a2, b2, ap, bp;
    
    printf("6 coords for 3 vertices of triangle: ");
    if (!scanf("%lf %lf %lf %lf %lf %lf", &a0, &b0, &a1, &a1, &a2, &a2)) die("Input failure.\n");
    printf("Now input coordinate pairs of points to test, non-# to quit.\nx y: ");
    while (scanf("%lf %lf", &ap, &bp)){
        if (inTriangle(a0, b0, a1, b1, a2, a2, ap, bp)) printf("in\n");
        else printf("not in\n");
        printf("x y: ");
    }
    
    return 0;
}

int inTriangle( double x0, double y0, double x1, double y1,
                double x2, double y2, double xp, double yp ){
    
    return 0;
}

int die(const char* msg){
    printf("Fatal error: %s", msg);
    exit(EXIT_FAILURE);
}