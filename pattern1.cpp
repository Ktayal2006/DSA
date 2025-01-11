#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter n" << endl;
    cin >> n;
    int i=1;
    int val=1;
    while (i<=n){
        int j=0;
        while (j<(n-i)){
            cout << " ";
            j+=1;
        }
        j=0;
        while (j<i){
            cout << val;
            val+=1;
            j+=1;
        }
        cout << endl;
        i+=1;
    }
	return 0;
}
