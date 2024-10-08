// tc : O(N)
// sc : O(1)
// lc-1108

class Solution {
public:
    string defangIPaddr(string address) {

        int i = 0 ;
        int size = address.length();

        for(int i = 0 ; i < size ; i++){
            if(address[i] == '.' ){
                address.replace(i,1,"[.]");
                size = address.length();
                i++;
            }
        }

        return address;
        
    }
};

// more optimized approach with i+2 skips if . is found

class Solution {
public:
    string defangIPaddr(string address) {

        int i = 0 ;
        int size = address.length();

        for(int i = 0 ; i < size ; i++){
            if(address[i] == '.' ){
                address.replace(i,1,"[.]");
                size = address.length();
                i+=2;
            }
        }

        return address;
        
    }
};
