import java.util.*;
import java.io.*;
public class Main {
  public static void main(String[] args) throws IOException{
    BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
    String [] tokens = input.readLine().split(" ");
    int n = Integer.parseInt(tokens[0]);int m = Integer.parseInt(tokens[1]);
    int[][] adj = new int[n+1][n+1];
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
      tokens = input.readLine().split(" ");
      u = Integer.parseInt(tokens[0]);v = Integer.parseInt(tokens[1]);w = Integer.parseInt(tokens[2]);
      if (adj[u][v] != 0 && w > adj[u][v])
      {
        continue;
      }
      adj[u][v] = w;
      adj[v][u] = w;
    }
    dijkstra(adj);
  }
  public static void dijkstra(int[][] adj)
  {
    int len = adj.length;
    boolean[] visited = new boolean[len];
    int[] dist = new int[len];
    dist[1] = 0;
    for (int i = 2; i < len; i++)
    {
      dist[i] = Integer.MAX_VALUE;
    }
    PriorityQueue<Node> pq = new PriorityQueue<Node>(len-1,new Node());
    pq.add(new Node(1,0));
    int tempDist;Node node;
    while (!pq.isEmpty())
    {
      node = pq.remove();visited[node.node] = true;
      if(node.cost > dist[node.node]){continue;}
      for (int i = 1; i < len; i++)
      {
        if (adj[node.node][i] != 0 && !visited[i])
        {
          tempDist = dist[node.node] + adj[node.node][i];
          if (tempDist < dist[i])
          {
            dist[i] = tempDist;pq.add(new Node(i, dist[i]));
          }
        }
      }
    }
    for (int i = 1; i < len;i++)
    {
      if (dist[i] == Integer.MAX_VALUE)
      {
        System.out.println(-1);
        continue;
      }
      System.out.println(dist[i]);
    }
  }
}
class Node implements Comparator<Node>
{
  public int node;
  public int cost;
  public Node()
  {

  }
  public Node(int node, int cost)
  {
    this.node = node;
    this.cost = cost;
  }
  public int compare(Node a, Node b)
  {
    if (a.cost < b.cost)
    {
      return -1;
    }
    if (a.cost > b.cost)
    {
      return 1;
    }
    return 0;
  }
}
