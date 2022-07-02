#User function Template for python3

class Solution:
    def count_paths(self, graph, s, d, visited):
        if s == d:
            return 1
        visited[s] = True
        ans = 0
        for vertex in graph[s]:
            if(visited[vertex] == False):
                ans += self.count_paths(graph, vertex, d, visited)
        visited[s] = False
        return ans
    def possible_paths(self, edges, n, s, d):
        graph = [[] for i in range(n)]
        for edge in edges:
            graph[edge[0]].append(edge[1])
        visited = [False for i in range(n)]
        return self.count_paths(graph, s, d, visited)

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T=int(input())
    for i in range(T):
        n, m, s, d = input().split()
        n = int(n); m = int(m); s = int(s); d = int(d);
        edges = []
        for _ in range(m):
            x,y = input().split()
            x = int(x); y = int(y);
            edges.append([x,y])
        obj = Solution()
        ans = obj.possible_paths(edges, n, s, d)
        print(ans)


# } Driver Code Ends
