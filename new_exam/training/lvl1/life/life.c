#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int ac, char **av) {
    if (ac != 4)
        return 0;
    int width = atoi(av[1]);
    int height = atoi(av[2]);
    int iterations = atoi(av[3]);
    int arr[2][height + 2][width + 2];

    for (int i = 0; i < 2; i++)
        for (int y = 0; y < height + 2; y++)
            for (int x = 0; x < width + 2; x++)
                arr[i][y][x] = 0;
    int x = 1, y=1;
    int prt = 0;
    char cmd;
    while (read(0, &cmd, 1) > 0) {
        if (cmd == 'w' && y >1)
            y--;
        else if (cmd == 'a' && x >1)
            x--;
        else if (cmd == 's' && y < height)
            y++;
        else if (cmd == 'd' && x < width)
            x++;
        else if (cmd == 'x')
            prt = !prt;
        if (prt)
            arr[0][y][x] = 1;
    }
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j < width; j++)
            putchar(arr[iterations % 2][i][j] ? 'O' : ' ');
        putchar('\n');
    }
    return 0;
}
