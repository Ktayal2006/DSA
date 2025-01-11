#include <iostream>
using namespace std;
int main()
{
    int n,i,j;
    // cout << "Enter n" << endl;
    cin >> n;
    for (i=1; i<=n; i++){
        for(j=0; j<(2*(n-i)) ;++j)
            cout << " ";
        for(j=i; j>0; --j)
            cout << j;
        for( j=2; j<=i; j++ )
            cout << j;
        cout << endl;
    }
	return 0;
}
