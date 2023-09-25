// tc : O(N)
// sc : O(1)
// lc - 1168

class Solution {
public:
    string interpret(string command) {
        string res = "";
        int n = command.size();
        for(int i =0 ; i< n;i++){
            string temp = "";
            if(command[i] == 'G'){
                res += command[i];
            }
            else if(command[i] == '('){
                i++;
                string temp = "";
                while(i < n && command[i] != ')'){
                    
                    temp += command[i];
                    i++;
                }
                if(temp == "") temp = "o";
                res += temp;
            }
        }

        return res;
    }
};
