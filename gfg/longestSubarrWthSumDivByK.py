# User function Template for python3
class Solution:

    @staticmethod
    def longSubarrWthSumDivByK(arr, n, k):
        mep = {}
        max_len = 0
        curr_sum = 0

        for i in range(n):
            curr_sum += arr[i]
            mod = ((curr_sum % k) + k) % k
            if mod == 0:
                max_len = i + 1
            elif mod in mep.keys():
                max_len = max(max_len, i - mep[mod])
            else:
                mep[mod] = i
        return max_len


# {
#  Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":

    for _ in range(0, int(input())):
        n, K = map(int, input().split())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        res = ob.longSubarrWthSumDivByK(arr, n, K)
        print(res)

# } Driver Code Ends
