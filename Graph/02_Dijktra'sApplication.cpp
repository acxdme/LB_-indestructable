// gfg - https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// hard to frame the mindset , need to revise again (bura haal hai)

    void findShortestPath(int &V , vector<vector<int>> adj[] , int &src , vector<int> &distance ,vector<int> &visited,set<pair<int,int>> &st){
        
        distance[src] = 0;
        visited[src] = 1;
        
        st.insert({0,src});
        
        while(!st.empty()){
            
            auto it = st.begin();
            int currD = it->first;
            int node = it->second;
            
            st.erase(it);
            
            for(auto nbr : adj[node]){
                if(currD + nbr[0] <= distance[nbr[1]]){
                    distance[nbr[1]] =  currD + nbr[0];
                    st.insert({distance[nbr[1]],nbr[1]});
                }
            }
        }
    }
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        //distance array
        vector<int> distance(V,INT_MAX); 
        
        //visited array
        vector<int> visited(V,0);
        
        
        //set<weight,node>
        set<pair<int,int>> st;
        
        findShortestPath(V,adj,S,distance,visited,st);
        
        
        return distance;
    }


// {node,weight} confusion , lot of logical mistake , set removal set totally not in sync/logic weak
// after hints : 

 void findShortestPath(int &V , vector<vector<int>> adj[] , int &src , vector<int> &distance,set<pair<int,int>> &st){
        
        distance[src] = 0;
        
        st.insert({0,src});
        
        while(!st.empty()){
            
            auto it = *st.begin();
            int currD = it.first;
            int node = it.second;
            
            st.erase(st.begin());
            
            for(auto nbr : adj[node]){
                if(distance[node] != INT_MAX  && currD + nbr[1] < distance[nbr[0]]){
                    
                    if(st.find({distance[nbr[0]],nbr[0]}) != st.end()){
                        auto pos = st.find({distance[nbr[0]],nbr[0]});
                        st.erase(pos);
                    }
                    distance[nbr[0]] =  currD + nbr[1];
                    st.insert({distance[nbr[0]],nbr[0]});
                }
            }
        }
    }
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        //distance array
        vector<int> distance(V,INT_MAX); 
        
        
        //set<weight,node>
        set<pair<int,int>> st;
        
        findShortestPath(V,adj,S,distance,st);
        
        
        return distance;
    }


//----------------------------------------------------------------------------------
// Manual Code written from scratch 
// Dijkstras algorithm using priority queue without updating priority_queue entries


#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include<limits.h>
#include<queue>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    unordered_map<int, list<pair<int, int>>> adjList2;

    void addEdge(int u, int v, int isDirected)
    {
        // 1 -> directed
        // 0 -> undirected
        adjList[u].push_back(v);
        if (!isDirected)
        {
            adjList[v].push_back(u);
        }
    }

    void addWeightedEdge(int u, int v, int w, int isDirected)
    {
        // 1 ->directed
        // 0 -> undirected
        adjList2[u].push_back({v, w});
        if (!isDirected)
        {
            adjList2[v].push_back({u, w});
        }
    }

    void printAdjList()
    {

        for (auto item : adjList)
        {
            cout << item.first << "-> ";
            for (auto nbr : item.second)
            {
                cout << nbr << " ,";
            }
            cout << endl;
        }
    }

    void printAdjList2()
    {
        for (auto item : adjList2)
        {
            cout << item.first << "-> ";
            for (auto nbr : item.second)
            {
                cout << "{" << nbr.first << "," << nbr.second << "} ";
            }
            cout << endl;
        }
    }


    void shortestPathDijk(int N){
      int src = 0;
      vector<int> dist(N,INT_MAX);
      dist[src] = 0;
      priority_queue< pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>  > pq;
      pq.push({0,0}); // {wt,node}

      while(!pq.empty()){
        auto frontItem = pq.top();
        pq.pop();
        int w = frontItem.first;
        int u = frontItem.second;
        for(auto nbr : adjList2[u]){
            if( dist[u] != INT_MAX && nbr.second + w < dist[nbr.first]){
                 
                 // remove from pq : find method is not available in priority_queue
                //  auto itr = pq.find({dist[nbr.first],nbr.first})
                //  if( itr != pq.end()){
                //     pq.erase(itr);
                //  }
                 // update the distance array
                 dist[nbr.first] = nbr.second + w;
                 // insert the updated weight in priority_queue
                 pq.push({dist[nbr.first],nbr.first});
            }

        }

      }

      for(int i =0 ; i < dist.size() ; i++){
        cout<< dist[i]<<" ";
      }cout<<endl;


      
    }
};

int main()
{

    Graph g;
    int n = 8;
    g.addWeightedEdge(0, 1, 4, 0);
    g.addWeightedEdge(0, 7, 8, 0);
    g.addWeightedEdge(1, 7, 11, 0);
    g.addWeightedEdge(1, 2, 8, 0);
    g.addWeightedEdge(7, 8, 7, 0);
    g.addWeightedEdge(7, 6, 1, 0);
    g.addWeightedEdge(2, 8, 2, 0);
    g.addWeightedEdge(8, 6, 6, 0);
    g.addWeightedEdge(6, 5, 2, 0);
    g.addWeightedEdge(2, 5, 4, 0);
    g.addWeightedEdge(2, 3, 7, 0);
    g.addWeightedEdge(5, 4, 10, 0);
    g.addWeightedEdge(3, 4, 9, 0);
    g.addWeightedEdge(5, 3, 14, 0);
    g.printAdjList2();

    g.shortestPathDijk(n);

    

    return 0;
}
