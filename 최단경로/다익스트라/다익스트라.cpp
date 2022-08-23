#include <vector>
#include <queue>

const int INF=987654321;
//아직 방문하지 않은 연결된 노드 중에 가장 거리가 짧은 노드 선택하기 
//지금 위치에서 가장 짧으면 최단거리임! 
int Find_Shortest_Node()
{
    int min_dist = INF;
    int min_idx = -1;
    for (int i = 0; i<= N; i++)
    {
    	if (visited[i] == true)
        	continue;
        if (dist[i] < min_dist)
        {
        	min_dist = dist[i];
            min_idx = i;
        }
    }
    return min_idx;    
}


void Dijkstra()
{
    for (int i = 1; i <= N; i++)
    	dist[i] = map[start][i];
    
    dist[start] = 0;
    visited[start] = true;
    
    for (int i = 0; i < N - 1; i++)
    {
    	int new_node = Find_Shortest_Node();
        visited[new_node] = true;
        
        for(int j = 0; j <= N; j++)
        {
        	if (visited[j] == true)
            	continue;
            if (dist[j] > dist[new_node] + map[new_node][j])
            	dist[j] = dist[new_node] + map[new_node][j];
        }
    }
}
