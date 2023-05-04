/*
 time complexity : O(N)
 Space complexity : O(N)
*/   

string removeDuplicates(string s) {
        stack<char> st;
        for(auto ch : s){
            if(st.empty()){
                st.push(ch);
            }else if (!st.empty() && st.top() == ch){
                while(!st.empty() && st.top() == ch){
                    st.pop();
                }
            }else{
                st.push(ch);
            }
        }

        string ans;
        while(!st.empty()){
            char top = st.top();
            st.pop();
            ans += top;
        }
       reverse(ans.begin(),ans.end());
        return ans;

    }

/*
More readable approach :

*/

class Solution {
public:
	string removeDuplicates(string s) {

		string ans;
		ans.push_back(s[0]);

		for(int i=1 ; i<s.length() ; i++){

			if(s[i] == ans.back()){
				ans.pop_back();
			}
			else{
				ans.push_back(s[i]);
			}
		}

		return ans;
	}
};
