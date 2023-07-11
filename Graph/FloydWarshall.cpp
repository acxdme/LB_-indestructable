// Floyd Warshall mssp algo
// gfg , TC : O(N^3)

/*
Detecting negative cycle :
Distance of any node from itself is always zero.
But in some cases, as in this example, when we traverse further from 4 to 1, the distance comes out to be -2, i.e. distance of 1 from 1 will become -2.
This is our catch, we just have to check the nodes distance from itself and if it comes out to be negative, we will detect the required negative cycle.
*/

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
