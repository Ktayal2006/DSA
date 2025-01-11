#include <bits/stdc++.h> 

int part(vector<int>& arr, int s, int e){

    int pivot = arr[s];
    int count = 0;

    for(int i=s+1; i<=e; i++){

        if(arr[i] <= pivot){

            count++;
        }
    }

    int index= count+s;
    swap(arr[s], arr[index]);

    int i=s;
    int j=e;

    while(i<index && j> index){

        if(arr[i]>= pivot && arr[j]<= pivot){

            swap(arr[i++], arr[j--]);
        }

        while(arr[i] < pivot){

            i++;
        }

        while(arr[j] > pivot){

            j--;
        }

        
    }

    return index;
}

void sort(vector<int> &arr, int s, int e){

    if(s>=e){
        return;
    }

    int p = part(arr, s, e);

    sort(arr, s, p-1);
    sort(arr, p+1, e);

}

vector<int> quickSort(vector<int> arr)
{
    
    sort(arr, 0, arr.size()-1);
    return arr;

}
