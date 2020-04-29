#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

#define MAX_NUM     123456789

typedef struct {
    int R, G, B;
} RGB;

int N, M;
RGB picture[400][400];
char asciiart[400][400];

char inten(RGB& pixel) {
    int intensity = pixel.R * 2126 + pixel.G * 7152 + pixel.B * 722;
    if (intensity < 510000)
        return '#';
    else if (intensity < 1020000)
        return 'o';
    else if (intensity < 1530000)
        return '+';
    else if (intensity < 2040000)
        return '-';
    else
        return '.';
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d %d %d", &picture[i][j].R, &picture[i][j].G, &picture[i][j].B);
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            //asciiart[i][j] = inten(picture[i][j]);
            printf("%c", inten(picture[i][j]));
        }
        printf("\n");
    }

    return 0;
}