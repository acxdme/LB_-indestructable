// Floyd Warshall mssp algo
// gfg , TC : O(N^3)

	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
    
	    for(int i = 0 ;i< n ;i++){
	        for(int j =0 ; j<n;j++){
	            if(matrix[i][j] == -1){
	                matrix[i][j] = 1e9;
	            }
	        }
	    }
    
	    for(int helper = 0 ;helper < n;helper++){
	        for(int i = 0 ;i< n;i++){
	            for(int j = 0 ; j<n;j++){  
	              matrix[i][j]= min(matrix[i][j],matrix[i][helper] + matrix[helper][j]);
	            }
	        }
	    }
	    
	    for(int i = 0 ;i< n ;i++){
	        for(int j =0 ; j<n;j++){
	            if(matrix[i][j] == 1e9){
	                matrix[i][j] = -1;
	            }
	        }
	    }
	}
