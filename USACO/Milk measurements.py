milk = [7,7,7]
cow = ["Bessie","Elsie","Mildred"]
measurement = []

for _ in range(int(input())):
    entry = list(input().split())
    measurement.append([int(entry[0]),cow.index(entry[1]),int(entry[2])])

measurement.sort()

curr = 7
ans = 0
for date,name,amt in measurement:
    milk[name]+=amt
    new = sum((2**i) for i in range(3) if milk[i]==max(milk))
    if curr != new:
        ans += 1
        curr = new

print(ans)
