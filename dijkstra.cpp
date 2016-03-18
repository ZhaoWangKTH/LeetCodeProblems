// Classic algorithm implementation: dijkstra's algorithm for searching the shortest path

// Thanks to http://rosettacode.org/wiki/Dijkstra%27s_algorithm 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>   // for numeric limits
#include <list>
#include <iterator>


using namespace std;

const double max_weight = numeric_limits<double>::infinity();

struct neighbor {
    int vertex;
    double weight;
    neighbor(int v, double w): vertex(v), weight(w) {}
};

typedef pair<double, int> weight_vertex_pair;

void dijkstraPathFinder(int start, const vector<vector<neighbor>> & adjList, vector<int> &prev, vector<double> &minDist) {
    // initialization
    auto n = adjList.size();
    prev.clear();
    prev.resize(n,-1);
    minDist.clear();
    minDist.resize(n,max_weight);
    minDist[start] = 0;
    
    // using priority queue to implement min_heap
    // this queue is used to save the pair of the distance to vertices, and vertices themself
    priority_queue<weight_vertex_pair, vector<weight_vertex_pair>, greater<weight_vertex_pair> > vertexQue;
    vertexQue.push(make_pair(minDist[start], start));
    
    // main body
    while(!vertexQue.empty()) {
        weight_vertex_pair curVertex = vertexQue.top();
        vertexQue.pop();
        
        double distToU = curVertex.first;
        int U = curVertex.second;
        
        if(distToU > minDist[U])
            continue;
        
        // visit its neighbor
        vector<neighbor> neighVec = adjList[U];
        for(int i=0; i<neighVec.size(); i++) {
            int V = neighVec[i].vertex;
            double distUtoV = neighVec[i].weight;
            // calculate the tentative distance
            double temp_minDist = distToU + distUtoV;
            // update minDist of V if temp is smaller
            if(temp_minDist < minDist[V]) {
                minDist[V] = temp_minDist;
                prev[V] = U;
                vertexQue.push(make_pair(minDist[V],V));
            }
        }
    }
}

list<int> dijkstraPathTo(vector<int> &prev, int destination) {
    list<int> pathNode;
    if(prev.size())
        return pathNode;
    
    int cur = destination;
    pathNode.push_front(cur);
    while(prev[cur] != -1) {
        cur = prev[cur];
        pathNode.push_front(cur);
    }
    
    return pathNode;
}

int main(int argc, const char * argv[]) {
    // remember to insert edges both ways for an undirected graph
    vector<vector<neighbor> > adjacency_list(6);
    // 0 = a
    adjacency_list[0].push_back(neighbor(1, 7));
    adjacency_list[0].push_back(neighbor(2, 9));
    adjacency_list[0].push_back(neighbor(5, 14));
    // 1 = b
    adjacency_list[1].push_back(neighbor(0, 7));
    adjacency_list[1].push_back(neighbor(2, 10));
    adjacency_list[1].push_back(neighbor(3, 15));
    // 2 = c
    adjacency_list[2].push_back(neighbor(0, 9));
    adjacency_list[2].push_back(neighbor(1, 10));
    adjacency_list[2].push_back(neighbor(3, 11));
    adjacency_list[2].push_back(neighbor(5, 2));
    // 3 = d
    adjacency_list[3].push_back(neighbor(1, 15));
    adjacency_list[3].push_back(neighbor(2, 11));
    adjacency_list[3].push_back(neighbor(4, 6));
    // 4 = e
    adjacency_list[4].push_back(neighbor(3, 6));
    adjacency_list[4].push_back(neighbor(5, 9));
    // 5 = f
    adjacency_list[5].push_back(neighbor(0, 14));
    adjacency_list[5].push_back(neighbor(2, 2));
    adjacency_list[5].push_back(neighbor(4, 9));
    
    std::vector<double> min_distance;
    std::vector<int> previous;
    dijkstraPathFinder(0, adjacency_list, previous, min_distance);
    std::cout << "Distance from 0 to 4: " << min_distance[4] << std::endl;
    list<int> path = dijkstraPathTo(previous, 4);
    std::cout << "Path : ";
    std::copy(path.begin(), path.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
