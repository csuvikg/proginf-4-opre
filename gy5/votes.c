#include <stdio.h>
#include <stdlib.h>
/*
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        perror("Provide only 1 argument: number of voters\n");
        exit(EXIT_FAILURE);
    }

    int voter_count = (int)strtol(argv[0], (char **)NULL, 10);

    return 0;
}
*/

// sigaction alapján, de a parent processben kell egy második fork
