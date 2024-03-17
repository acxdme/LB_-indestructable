// sorting with departure time and checking is not a valid solution  but why(??).
// gfg - https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
    static bool cmp(pair<int,int> &a , pair<int,int> &b){
        return a.second < b.second;
    }
    int findPlatform(int arr[], int dep[], int n)
    {
    	vector<pair<int,int>> timings;
    	for(int i =0 ; i< n;i++){
    	    int arrivalTime = arr[i];
    	    int departureTime = dep[i];
    	    timings.push_back({arrivalTime,departureTime});
    	}
    	
    	sort(timings.begin(),timings.end(),cmp);
    	
    	int overlappingIntervals = 0;
    	int maxVal = 0;
    	for(int i=0 ; i< n-1;i++){
    	   int arrNext = timings[i+1].first;
    	   int departureCurr= timings[i].second;
    	   if(departureCurr > arrNext){
    	       overlappingIntervals++;
    	       maxVal = max(maxVal,overlappingIntervals);
    	   }
    	   else{
    	       overlappingIntervals = 0;
    	   }
    	    
    	}
    	
    	return maxVal + 1;
    }
