#include <math.h>
bool isprime(int p)
{
    if ( (p==2) || (p==1) )
        return true;
    else if (p%2==0)
        return false;
        else{
        int i=3;
        while(i<=sqrt(p)){
                if (p%i==0){
                return false;
            }
            else
                i+=2;
        }
        return true;
    }
}
