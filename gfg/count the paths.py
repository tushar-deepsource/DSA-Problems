# User function Template for python3


class Solution:

    def count_paths(self, graph, curr, dest, visited):
        if curr == dest:
            return 1
        visited[curr] = True
        ans = 0
        for vertex in graph[curr]:
            if visited[vertex] == False:
                ans += self.count_paths(graph, vertex, dest, visited)
        visited[curr] = False
        return ans

    def possible_paths(self, edges, n, source, dest):
        graph = [[] for i in range(n)]
        for edge in edges:
            graph[edge[0]].append(edge[1])
        visited = [False for i in range(n)]
        return self.count_paths(graph, source, dest, visited)


# {
#  Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n, m, s, d = input().split()
        n = int(n)
        m = int(m)
        s = int(s)
        d = int(d)
        edges = []
        for _ in range(m):
            x, y = input().split()
            x = int(x)
            y = int(y)
            edges.append([x, y])
        obj = Solution()
        ans = obj.possible_paths(edges, n, s, d)
        print(ans)

# } Driver Code Ends
