#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (int ac, char **av) {
    if ac != 4 {
        return 1;
    }
    int width = atoi(av[1]);
    int height = atoi(av[2]);
    int iterations = atoi(av[3]);
    int arr[2][height + 2][width + 2];
    for (int i = 0; i < 2; i++) {
        
    }
}
