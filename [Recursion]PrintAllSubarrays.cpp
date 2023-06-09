// Iterative approach (Brute force)
#include <iostream>
#include<vector>

using namespace std;

int main() {
    // Write C++ code here
    vector<int> ip = {1,2,3};
    int n= ip.size();
    for(int i=0 ; i< n;i++){
        for(int j = i; j< n;j++){
                    cout<<"[";
            for(int k = i ; k<=j;k++){
                cout<<ip[k]<<" ";
            }cout<<"]"<<endl;
        }
        
    }

    return 0;
}
