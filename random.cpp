#include"unorderedMap.hpp"
#include<iostream>
using namespace std;

int main(){
    ourmap<int> map;
    map.insert("a",1);
    map.insert("b", 2);
    map.insert("c",3);
    //map.insert("d",4);
    int a = map.getValue("a");
    //cout << "Value of a " << a << endl;
    //map.remove("b");
    int b = map.getValue("b");
    //cout << "Value of b " << b << endl;
    cout << map.loadFactor() << endl;
    cout << "Size = " << map.size() << endl;
    //cout << map.isPresent("b") << endl;
}
