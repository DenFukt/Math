#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
    int u, v, w;
};

bool cmp(const Edge &a, const Edge &b){
    return a.w < b.w;
}

int findParent(int v, vector<int> &parent){
    if(parent[v] == v){
        return v;
    }
    return parent[v] = findParent(parent[v], parent);
}

void unionSets(int a, int b, vector<int> &parent, vector<int> &rank){
    a = findParent(a, parent);
    b = findParent(b, parent);
    if(a != b){
        if(rank[a] < rank[b]){
            swap(a, b);
        }
        parent[b] = a;
        if(rank[a] == rank[b]){
            rank[a]++;
        }
    }
}

int main(){
    vector<Edge> graph = {
        {1, 2, 4}, {1, 3, 3}, {1, 4 ,2},
        {2, 5, 2}, {2, 7, 1},
        {3, 6, 7}, {3, 5, 6},
        {4, 6, 2}, {4, 7, 7},
        {5, 8, 4}, {5, 9, 7},
        {6, 8, 4}, {6, 10, 3},
        {7, 9, 5}, {7, 10, 5},
        {8, 11, 4}, {9, 11, 1}, {10, 11, 3}
    };

    int n = 11;
    sort(graph.begin(), graph.end(), cmp);

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    cout << "Етапи побудови (алгоритм Краскала):\n";

    int totalWeight = 0;
    vector<Edge> mst;

    for(auto &e : graph){
        int a = findParent(e.u, parent);
        int b = findParent(e.v, parent);

        cout << "Розглядаємо ребро (" << e.u << ", " << e.v << ") з вагою " << e.w;

        if (a != b) {
            cout << " - додаємо в дерево.\n";
            totalWeight += e.w;
            mst.push_back(e);
            unionSets(a, b, parent, rank);
        } else{
            cout << " - пропускаємо (утворює цикл).\n";
        }
    }

    cout << "\nМінімальне остове дерево містить ребра:\n";
    for (auto &e : mst)
        cout << "(" << e.u << ", " << e.v << ") вага " << e.w << "\n";

    cout << "\nЗагальна вага МОД: " << totalWeight << endl;

    return 0;
}
