n = int(input())
k = int(input())
res = ""
nums = []
bad_nums = []
for num in input().split():
    bad_nums.append(int(num))
for i in range(10):
    if i not in bad_nums:
        nums.append(i)    
while n > 0:
    res = str(n % (10 - k)) + res
    n //= (10 - k)
ans = ""    
for i in range(len(res)):
    ans += str(nums[int(res[i])])
print(ans)
