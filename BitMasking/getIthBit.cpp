// program to find whether the ith bit is set or not.

#include <iostream>
#include <bitset>

using namespace std;

int getIthBit(int n , int i){
    int mask = (1 << i);
    if(n & mask){
        cout << i <<"-bit is set"<<endl;
    }else{
        cout<<i <<"-bit is not set"<<endl;
    }
}
int main()
{
    int n = 12;
    cout<< "orginal number"<<endl;
    string binary = bitset<32>(n).to_string(); //to binary
    cout<<binary<<"\n";
    getIthBit(n,0);
    

    return 0;
}
