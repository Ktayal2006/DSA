#include <iostream>
#include <math.h>
using namespace std;
bool isprime(int p);
int main()
{
    int n;
    cin >> n;
    for( int i=1; i<=n; ++i ){
        if (isprime(i) == true)
            cout << i << endl;
    }
}
