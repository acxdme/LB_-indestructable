#include <iostream>
#include <string>

using namespace std;

string deletePosRec(string str, int pos) {
    string res = str;
    
    while(res.size() > 1){
        int n = res.size();
        if(pos == 0){
            res.erase(0,1);
            continue;
        }
        if(pos == n){
            res.erase(n-1,1);
            continue;
        }

        int indexToErase = pos % n;

        res.erase(indexToErase-1 ,1);

    }

    return res;
}

int main() {
    string str = "ayush";

    string ans = deletePosRec(str, 5);
    cout << ans << endl;
    return 0;
}
