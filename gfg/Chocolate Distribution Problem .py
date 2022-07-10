class Solution:

    def findMinDiff(self, A, N, M):
        A.sort()
        min_d = A[-1] - A[0]
        for i in range(N - M + 1):
            min_d = min(min_d, A[i + M - 1] - A[i])
        return min_d


if __name__ == "__main__":

    t = int(input())
    for _ in range(t):
        N = int(input())
        A = [int(x) for x in input().split()]
        M = int(input())

        solObj = Solution()

        print(solObj.findMinDiff(A, N, M))
