vector<int> dfs(int node,int vis[],vector<int>adj[]){
        vis[node]=1;
        vector<int>v;
        v.push_back(node);
    
        for(auto it:adj[node]){
          if (!vis[it]) {
            vector<int>sub_result=dfs(it, vis, adj);//to store the intermediate result as once called it will create every time  anew vector v;
            v.insert(v.end(),sub_result.begin(),sub_result.end());
          }
        }
        return v;
        
    }
    

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int>adj[V];
    for(int i=0;i<E;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
                adj[u].push_back(v);
                adj[v].push_back(u);
            
        
    }
    int vis[V]={0};
    vector<vector<int>>ans;
    for(int i=0;i<V;i++){

      if (!vis[i]) {
        
        ans.push_back(dfs(i, vis, adj));
        
      }
    }
    return ans;
}