#include <iostream>
using namespace std;

int fibonacciSeries( int n ){
    if ( n == 1 )
        return 0;
    else if( n == 2 )
        return 1;
    int num = fibonacciSeries( n-1 ) + fibonacciSeries( n-2 );
    return num;
}
