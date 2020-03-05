#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   //fork
#include <sys/wait.h> //waitpid
#include <errno.h>

int main()
{
    pid_t child = fork();
    if (child > 0) // parent
    {
        pid_t child = fork();
        if (child > 0) // parent
        {
            pid_t child = fork();
            if (child > 0) // parent
            {
                pid_t child = fork();
                if (child > 0) // parent
                {
                    pid_t child = fork();
                    if (child > 0) // parent
                    {
                        printf("Parent\n");
                    }
                    else
                    {
                        printf("Child\n");
                    }
                }
                else
                {
                    printf("Child\n");
                }
            }
            else
            {
                printf("Child\n");
            }
        }
        else
        {
            printf("Child\n");
        }
    }
    else
    {
        printf("Child\n");
    }
    return 0;
}
