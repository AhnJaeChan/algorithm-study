
d = [[0 for i in range(65)] for i in range(10)]


def main():

    for i in range(10):
        d[i][1] = i + 1

    for i in range(2, 65):
        d[0][i] = 1
        for j in range(1, 10):
            d[j][i] = d[j - 1][i] + d[j][i - 1]

    T = int(input())
    while T:
        T -= 1
        N = int(input())
        print(d[9][N])


if __name__ == "__main__":
    main()