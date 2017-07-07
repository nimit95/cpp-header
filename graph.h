#include "Vector.h"
#include <queue>
#ifndef GRAPH_H
#define GRAPH_H
class Graph {
    Vector< Vector<T> > graph;
    int v;
public:
    Graph(int vertices) {
        v = vertices;
        graph.resize(v);
    }
    void addEdge(int u, int v, bool bidirec = true) {
        graph[u].push_back(v);
        if(bidirec)
            graph[v].push_back(u);
    }
    void dfsHelper(Vector< Vector<T> >& graph, int src, vector<bool>& visited) {
        for(int i=0;i<v[src].size();i++) {
            if(!visited[v[src][i]])
            {
                visited[v[src][i]] = true;
                dfsHelper(graph, v[src][i], visited);
            }
        }
    }
    void dfs() {
        vector<bool> vi#include "Vector.h"
#include <queue>
#ifndef GRAPH_H
#define GRAPH_H
class Graph {
    Vector< Vector<T> > graph;
    int v;
public:
    Graph(int vertices) {
        v = vertices;
        graph.resize(v);
    }
    void addEdge(int u, int v, bool bidirec = true) {
        graph[u].push_back(v);
        if(bidirec)
            graph[v].push_back(u);
    }
    void dfsHelper(Vector< Vector<T> >& graph, int src, vector<bool>& visited) {
        for(int i=0;i<v[src].size();i++) {
            if(!visited[v[src][i]])
            {
                visited[v[src][i]] = true;
                dfsHelper(graph, v[src][i], visited);
            }
        }
    }
    void dfs() {
        vector<bool> visited(v,false);
        dfsHelper(graph, 0, visited);
    }
    void bfs(int src) {
        queue<int> q;
        vector<bool> visited(v,false);
        q.push(src);
        while(!q.empty()) {
            int u = q.top();
            q.pop();
            for(int i=0;i<v[u].length();i++) {
                if(!visited[v[u][i]]){
                    q.push(v[i][u]);
                    visited[v[i][u]] = true;
                }
            }
        }
    }

};
#endif
sited(v,false);
        dfsHelper(graph, 0, visited);
    }
    void bfs(int src) {
        queue<int> q;
        vector<bool> visited(v,false);
        q.push(src);
        while(!q.empty()) {
            int u = q.top();
            q.pop();
            for(int i=0;i<v[u].length();i++) {
                if(!visited[v[u][i]]){
                    q.push(v[i][u]);
                    visited[v[i][u]] = true;
                }
            }
        }
    }

};
#endif
