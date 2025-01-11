#include <iostream>
using namespace std;
void print_2darr( int arr[][100], int row, int colm )
{
    for( int i=0; i<row; ++i ){
        for( int j=0; j<colm; ++j )
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
