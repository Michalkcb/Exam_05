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
    
}
