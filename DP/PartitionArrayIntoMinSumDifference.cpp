// my attempt very bad  recurive function unable to convert to memoization approch.
void findDiff(vector<int>& nums,int index,int &n ,int subset,int p2, int &ans,int& total){
         cout<<"index-"<<index<<" subset :"<<subset<<" p2 :"<<p2<<endl;
        if(index >= n || subset > n){
            return;
        }

        if(subset == n/2){
            int p1 = total - p2;
            ans = min(ans,abs(p2 - p1));
            return;
        }
        //include
        findDiff(nums,index+1,n,subset+1,p2+nums[index],ans,total);
        //exlude
        findDiff(nums,index+1,n,subset,p2,ans,total);

    }
