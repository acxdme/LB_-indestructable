class StockSpanner {
public:
    stack<pair<int,int>> st; // index,value
    int indx = 0 ;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        if(st.empty()) {
           st.push({indx,price});
        }else{
            while(!st.empty() && st.top().second <= price){
                st.pop();
            }
            if(!st.empty()){
                ans = indx - st.top().first;
            }else{
                ans = indx+1;
            }


            st.push({indx,price});
        }
        
        indx++;
        return ans;
    }
};
