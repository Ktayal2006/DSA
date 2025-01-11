#include<iostream>
using namespace std;

int inputArr( int input[] ){
    int n;
    cout << "Enter the number of elements" << endl;
    cin >> n;
    cout << "enter elements" << endl;
    for ( int i=0; i<n; ++i )
        cin >> input[i];
    return n;
}

void outputArr( int b[], int n ){
     for ( int i=0; i<n; ++i )
         cout << b[i] << " " ;
     cout << endl;
 }
