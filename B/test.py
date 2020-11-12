def f(n):
    if n == 1: return 0
    elif n%2 == 1: return f(3*n+1)+1
    else: return f(n/2)+1

print(f(27))
