#!/usr/bin/python3
from math import ceil, sqrt
from sys import argv


def main():
    try:
        with open(argv[1]) as f:
            data = f.read()
    except (FileNotFoundError,):
            exit(0)
    for str in data.split('\n'):
        m = int(str)
        n = ceil(sqrt(m))


        if n % 2 == 0:
            n -= 1
        for i in range(n, m+1, 2):
            c = m / i
            if c not in [2, 5] and (c % 5 == 0 or ((c - 1) % 6 != 0 and (c+1) % 6 != 0)) or (m % i) != 0:
                continue
            print(f"{m}={i}*{int(c)}")
            break


if __name__ == '__main__':
    main()
