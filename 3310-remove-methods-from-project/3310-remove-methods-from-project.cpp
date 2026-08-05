class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Track which methods are suspicious (potentially buggy)
        vector<bool> isSuspicious(n, false);
      
        // Track visited nodes for the second DFS
        vector<bool> visited(n, false);
      
        // Adjacency lists for the graph
        vector<vector<int>> undirectedGraph(n);  // Bidirectional edges
        vector<vector<int>> directedGraph(n);    // Original directed edges
      
        // Build both directed and undirected graphs from invocations
        for (const auto& invocation : invocations) {
            int caller = invocation[0];
            int callee = invocation[1];
          
            // Build undirected graph (both directions)
            undirectedGraph[caller].push_back(callee);
            undirectedGraph[callee].push_back(caller);
          
         
            directedGraph[caller].push_back(callee);
        }
      
  
        auto markSuspiciousFromBuggy = [&](this auto&& markSuspiciousFromBuggy, int currentMethod) -> void {
            isSuspicious[currentMethod] = true;
        
            for (int calledMethod : directedGraph[currentMethod]) {
                if (!isSuspicious[calledMethod]) {
                    markSuspiciousFromBuggy(calledMethod);
                }
            }
        };
      
       
        markSuspiciousFromBuggy(k);
      
        auto markConnectedAsNonRemovable = [&](this auto&& markConnectedAsNonRemovable, int currentMethod) -> void {
            visited[currentMethod] = true;
          
            for (int connectedMethod : undirectedGraph[currentMethod]) {
                if (!visited[connectedMethod]) {
               
                    isSuspicious[connectedMethod] = false;
                    markConnectedAsNonRemovable(connectedMethod);
                }
            }
        };
      

        for (int methodId = 0; methodId < n; ++methodId) {
            if (!isSuspicious[methodId] && !visited[methodId]) {
                markConnectedAsNonRemovable(methodId);
            }
        }

        vector<int> remainingMethodsList;
        for (int methodId = 0; methodId < n; ++methodId) {
            if (!isSuspicious[methodId]) {
                remainingMethodsList.push_back(methodId);
            }
        }
      
        return remainingMethodsList;
    }
};