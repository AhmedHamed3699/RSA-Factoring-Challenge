#!/usr/bin/python3
import sys

if __name__ == "__main__":
    MXSIZE = 1000001
    allPrimes = []
    primes = [1]*MXSIZE
    primes[0] = primes[1] = 0
    for i in range(2, MXSIZE):
        if primes[i]:
            allPrimes.append(i)
            for j in range(i + i, MXSIZE, i):
                primes[j] = 0

    with open(sys.argv[1], 'rb') as file:
        for line in file:
            n = int(line)
            i = 0
            while (i < len(allPrimes)) and (n % allPrimes[i]):
                i += 1
            if i >= len(allPrimes):
                i = MXSIZE
                while i*i <= n and n % i:
                    i += 1
                print(f'{n}={n // i}*{i}')
            else:
                print(f'{n}={n // allPrimes[i]}*{allPrimes[i]}')
