for _ in range(int(input())):
    n,k = map(int,input().split())
    ls = list(map(int,input().split()))
    ans = 0
    if k == 1:
        ans = (n-1)/2
    else:
       for i in range(1,n-1):
           if ls[i]>ls[i-1]+ls[i+1]:
               ans +=1
    print(int(ans))
