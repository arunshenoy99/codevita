def sieve(n):
    primes = [True for i in range(n + 1)]
    p = 2
    while p * p <= n:
        if primes[p] == True:
            for i in range(p * p, n + 1, p):
                primes[i] = False
        p += 1
    return primes


N = int(input("N: "))
primer = sieve(N)
primes = []
count = 0
for i in range(2, N + 1):
    if primer[i]:
        primes.append(i)
        count += 1

m = count
sum = 2
count = 0
for i in range(1, m):
    sum += primes[i]
    if sum < N and primes.count(sum) != 0:
        count += 1

print(count)

    