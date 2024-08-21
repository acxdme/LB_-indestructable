// Tc : O(N)
// Sc : O(1)
// gfg : https://www.geeksforgeeks.org/problems/valid-compressed-string--170647/1

int checkCompressed(string S, string T) {
         int i = 0; // Index for S
        int j = 0; // Index for T
        
        while (j < T.length()) {
            if (isdigit(T[j])) {
                int num = 0;
                // Calculate the full number in the compressed string
                while (j < T.length() && isdigit(T[j])) {
                    num = num * 10 + (T[j] - '0');
                    j++;
                }
                i += num; // Move forward in S by the number
            } else {
                if (i >= S.length() || S[i] != T[j]) {
                    return false;
                }
                i++;
                j++;
            }
        }
        return i == S.length();
    }
