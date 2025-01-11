#include <iostream>
#include <vector>
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

int partition( int vec[], int start, int end ){
    
    int count = 0; 
    for( int i = start+1; i<=end; ++i ){
        if( vec[i] < vec[start] )
            ++count;
    }
    int index = count+start;
    
    int temp = vec[start];
    vec[start] = vec[index];
    vec[index] = temp;

    for( int i = start, j =end; (i<index) && (j>index);  ){
        if( vec[i] < vec[index])
            ++i;
        else if( vec[j] >= vec[index] ) 
            --j;
        else{
            int temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
        }
    }
    return index;
}

void quickSort( int vec[], int start, int end ){
    if( start >= end )
        return;
    int c = partition( vec, start, end );
    quickSort( vec, start, c-1 );
    quickSort( vec, c+1, end );
}
int binarysearch( int arr[], int n, int x) {
    int start=0, end= n-1;
    while( start<=end){
        int mid = (start+end)/2;
        mid = (start+end)/2;
        if ( arr[mid] == x )
            return mid;
        else if ( arr[mid] < x )
            start = mid+1;
        else
            end = mid-1;
    }
    return -1;
}

void intersection(int *arr1, int *arr2, int n, int m) 
{
    quickSort( arr1, 0, n);
    for( int i =0; i<m; ++i){
        int index = binarysearch(arr1, n, arr2[i]);
        if( index != -1)
            cout << arr2[i] << " ";
    }
}
int main(){
    vector<int> v;
    v.push_back(3);
    v[2] = 1;
    cout << v[2] << endl;
}
