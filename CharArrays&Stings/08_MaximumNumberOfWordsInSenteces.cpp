// tc : O(N* M) , N sentences & M is the max length of sentence
// sc : O(1)
// lc - 2114

    int mostWordsFound(vector<string>& sentences) {
        int mxcount = 0;
        int n = sentences.size();
        for(int i =0 ; i < n ; i++){
            string sentence = sentences[i];
            int count = 1;
            int m = sentence.size();
            for(int j =0 ; j < m ; j++){
                if(sentence[j] == ' '){
                    count++;
                }
            }
            mxcount = max(mxcount,count);
            
        }

        return mxcount;
    }
