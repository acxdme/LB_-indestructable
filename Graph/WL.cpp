// Word ladder-1 
// leetcode-127
// time complexity :  wordSet Creation + priority queue operations

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int n = wordList.size();
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        // for(int i = 0 ;i<n ;i++){
        //     wordSet.insert(wordList[i]);
        // }

        priority_queue < pair<int,string>, vector<pair<int,string>> , greater<pair<int,string>>> pq;

        pq.push({1,beginWord});

        while(!pq.empty()){
            auto frontNode = pq.top();
            pq.pop();
            int distance = frontNode.first;
            string word = frontNode.second;

            if(word == endWord){
                return distance;
            }

            for(int i = 0 ;i < word.size() ; i++){
                char ch = word[i];
                for(char c = 'a' ; c <= 'z' ; c++){
                    word[i] = c;
                    if(wordSet.find(word) != wordSet.end()){
                        auto pos = wordSet.find(word);
                        pq.push({distance +1 , word});
                        wordSet.erase(pos);

                    }
                }
                word[i] = ch; // revert back the change in character.
            }
        }

        return 0;
        
    }
};
