// tc : O(N)
// sc : O(N)
// lc-448

class Solution {
public:
    int compress(vector<char>& chars) {

        int count = 0;
        char ch = chars[0];
        string s = "";

        for(char c :  chars){
            if(c == ch){
                count++;
            }
            else{
                // string mei push karto ch aur occurence
                s += ch;
                if(count > 1){
                    string number = "";
                    while(count > 0){
                        char digit =  '0' + count % 10;
                        count = count /10;
                        number += digit;
                    }
                    reverse(number.begin() , number.end());
                    s += number;
                    
                }
                cout<< s<<endl;

                count = 1;
                ch = c;
            }
        }


        s +=ch;
        if(count > 1){
            string number = "";
            while(count > 0){
                char digit =  '0' + count % 10;
                count = count /10;
                number += digit;
            }
            reverse(number.begin() , number.end());
            s += number;
            
        }
                cout<< s<<endl;


        for (int i = 0 ; i < s.size() ; i++){
            chars[i] = s[i];
        }

        return s.size();
        
    }
};
