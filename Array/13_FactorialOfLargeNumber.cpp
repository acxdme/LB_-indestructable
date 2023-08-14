//gfg : factorial of large number.
//Time-complexity : O(N^2)
// Space complexity : O(1) , no extra space required.

  vector<int> factorial(int N){
      vector<int> res = {1};
      int carry = 0 ;
      for(int i = 2 ; i <= N ; i++){
          for(int j =0 ; j < res.size() ; j++){
              int cal = res[j] * i + carry;
              res[j] = cal % 10;
              carry = cal / 10;
          }
          
          while(carry > 0 ){
              res.push_back(carry % 10);
              carry = carry /10;
          }
          // for(int m = 0 ;m<res.size();m++){
          //     cout<< res[m]<<" ";
          // }cout<<endl;
      }
      reverse(res.begin(),res.end());
      return res;
  }
