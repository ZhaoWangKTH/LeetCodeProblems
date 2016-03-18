//Leetcode problems/wordLadderDijkstra.cpp

/* Problem statement: Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

You must change exactly one character in every transformation
Each intermediate word must exist in the dictionary
Example :

Given:

start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note that we account for the length of the transformation path instead of the number of transformation itself.

 Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

/* Solution: Construct a graph, and find the minimum length path based on Dijkstra's algorithm 
  This solution exceeds time limits on Leetcode oj, but passed at interviewbit.com.
  Better solution is expected. 
*/

class Solution {
private:
    struct neighbor{
        int target;
        double weight;
        neighbor(int v, double w) : target(v), weight(w) {}
    };
    
    int strDist(string A, string B) {
        // only compare the strings with same length
        if(A.length() != B.length())
            return -1;
        
        int sum = 0;
        for(int i=0; i<A.length(); i++) {
            if(A[i]-B[i] != 0)
                sum++;
        }
        return sum;
    }
    
    vector<vector<neighbor> > generateGraph(vector<string> &strVec) {
        
        auto n = strVec.size();
        // the graph is saved by an adjacency list
        vector<vector<neighbor> > adjList(n, vector<neighbor>());
        if(strVec.size() == 0)
            return adjList;
        
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                if(strDist(strVec[i], strVec[j]) == 1) {
                    adjList[i].push_back(neighbor(j, 1));
                    adjList[j].push_back(neighbor(i, 1));
                }
            }
        }
        
        return adjList;
    }
    
    typedef pair<double, int> weight_vertex_pair;
    
    void dijkstraPathFinder(int start, int goal, const vector<vector<neighbor>> &adjList, vector<int> &prev, vector<double> &minDist) {
        auto n = adjList.size();
        prev.clear();
        prev.resize(n, -1);
        minDist.clear();
        minDist.resize(n, std::numeric_limits<double>::infinity());
        minDist[0] = 0.0;
        
        // min heap to maintain the open set with distance still to evaluate
        priority_queue<weight_vertex_pair, vector<weight_vertex_pair>, std::greater<weight_vertex_pair> > vertexQue;
        vertexQue.push(make_pair(minDist[0], 0));
        
        while(!vertexQue.empty()) {
            int u = vertexQue.top().second;
            double dist_u = vertexQue.top().first;
            vertexQue.pop();
            if(u == goal) 
                return;
            
            if(dist_u > minDist[u]) 
                continue;
                
            // visit all its neighbor
            vector<neighbor> neighVec = adjList[u];
            for(int i=0; i<neighVec.size(); i++) {
                int v = neighVec[i].target;
                double dist_u_v = neighVec[i].weight;
                double temp_dist_v = dist_u + dist_u_v;
                if(temp_dist_v < minDist[v]) {
                    minDist[v] = temp_dist_v;
                    prev[v] = u;
                    vertexQue.push(make_pair(minDist[v], v));
                }
            }
            
        }
    }
    
    list<int> dijkstraPathTo(const int goal, vector<int> &prev) {
        list<int> path;
        if(prev.size() == 0)
            return path;
        if(goal > prev.size() -1)
            return path;
        
        int cur = goal;
        while(cur != -1) {
            path.push_front(cur);
            cur = prev[cur];
        }
        
        return path;
    }
    
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if(beginWord == endWord)
            return 1;
        
        vector<string> myStrVec;
        myStrVec.push_back(beginWord);
        for(unordered_set<string>::iterator it=wordList.begin(); it!=wordList.end(); it++) {
            if((*it) != beginWord && (*it) != endWord) myStrVec.push_back(*it);
        }
        myStrVec.push_back(endWord);
        
        vector<vector<neighbor>> myAdjList = generateGraph(myStrVec);
        vector<int> prevNode;
        vector<double> minDist;
        
        dijkstraPathFinder(0, myStrVec.size()-1, myAdjList, prevNode, minDist);
        list<int> myPath = dijkstraPathTo(myStrVec.size()-1, prevNode);
        
        return myPath.size()<=1 ? 0 : myPath.size();
        
    }
};
