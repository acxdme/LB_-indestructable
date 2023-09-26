// tc : O(N)
// sc : O(1) , for the given question.
// lc-13

    int romanToInt(string s) {
        unordered_map<char,int> value;
        value['I'] = 1;
        value['V'] = 5;
        value['X'] = 10;
        value['L'] = 50;
        value['C'] = 100;
        value['D'] = 500;
        value['M'] = 1000;

        int res = 0;
        for(int i = 0 ; i < s.size() ;i++){
            if(i+1 < s.size() && value[s[i]]  < value[s[i+1]]){
                res += ( value[s[i+1]] - value[s[i]]);
                i++;
            }
            else{
                res += (value[s[i]]);
            }
        }
        return res;
    }
