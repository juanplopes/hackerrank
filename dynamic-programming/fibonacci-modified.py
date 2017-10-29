a, b, n = map(int, raw_input().split(' '))

for i in range(2, n):
    a, b = b, a+b*b
    
print b
