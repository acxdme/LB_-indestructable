#include<set>

vector < int > sortedArray(vector < int > a, vector < int > b) {
    set<int> result;
    int sizea = a.size();
    int sizeb = b.size();
    
    for(int i = 0 ; i< sizea ;i++){
        result.insert(a[i]);
    }
        
    
    for(int i = 0 ; i< sizeb ;i++){

        result.insert(b[i]);
    }
    
    
    vector<int> ans;
    for(auto it : result){
        ans.push_back(it);
    }
    
    
    return ans;

}
