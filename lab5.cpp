#include <iostream>
#include <vector>

using namespace std;

int main(){
    int H[5][5]={
        {4, 4, 3, 1, 3},
        {4, 1, 1, 2, 7},
        {4, 1, 2, 7, 7},
        {8, 3, 8, 1, 5},
        {1, 3, 3, 3, 6}
    };

    int V[4][6] = {
        {6, 2, 3, 4, 5, 8},
        {1, 7, 5, 7, 1, 3},
        {7, 4, 7, 1, 2, 8},
        {5, 2, 3, 1, 3, 7}
    };

    int rows = 5;
    int cols = 6;
    int total = rows * cols;

    int dist[30];
    int parent[30];
    bool visited[30];

    for(int i = 0; i < total; i++){
        dist[i] = 1000000;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[0] = 0;

    for(int i = 0; i < total; i++){
        int u = -1;
        int min_val = 1000000;

        for(int j = 0; j < total; j++){
            if(!visited[j] && dist[j] < min_val){
                min_val = dist[j];
                u = j;
            }
        }

        if(u == -1 || dist[u] == 1000000){
            break;
        }

        visited[u] = true;

        int r = u / cols;
        int c = u % cols;

        if(c < cols - 1){
            int v = u + 1;
            int weight = H[r][c];
            
            if(dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }

        if(c > 0){
            int v = u - 1;
            int weight = H[r][c - 1];
            
            if(dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }

        if(r < rows - 1){
            int v = u + cols;
            int weight = V[r][c];
            
            if(dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }

        if(r > 0){
            int v = u - cols;
            int weight = V[r - 1][c];
            
            if(dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }

    int endNode = 29;

    if(dist[endNode] == 1000000){
        cout << "Шляху немає!" << endl;
    } 
    else{
        cout << "Найкоротший шлях (вартість): " << dist[endNode] << endl;

        vector<int> path;
        
        int curr = endNode;
        while(curr != -1){
            path.push_back(curr);
            curr = parent[curr];
        }

        cout << "Маршрут: ";
        for (int i = path.size() - 1; i >= 0; i--){
            int nodeIndex = path[i];
            int r = nodeIndex / cols;
            int c = nodeIndex % cols;
            
            cout << "(" << r << "," << c << ")";
            
            if(i > 0){
                cout << " -> ";
            }
        }
    }

    return 0;
}