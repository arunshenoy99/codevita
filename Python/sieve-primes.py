def sieve(n):
    primes = [True for i in range(n + 1)]
    p = 2
    while p * p <= n:
        if primes[p] == True:
            for i in range(p * p, n + 1, p):
                primes[i] = False
        p += 1
    for i in range(2, n + 1):
        if primes[i]:
            print(i)

sieve(15)