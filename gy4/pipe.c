#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for pipe()
#include <string.h>
#include <sys/wait.h>
//
// unnamed pipe example
//
int main(int argc, char *argv[])
{
    int pipefd_p[2]; // unnamed pipe file descriptor array for the parent process
    int pipefd_c[2]; // unnamed pipe file descriptor array for the child process
    pid_t pid;
    char sz[100]; // char array for reading from pipe

    if (pipe(pipefd_p) == -1 || pipe(pipefd_c) == -1)
    {
        perror("Hiba a pipe nyitaskor!");
        exit(EXIT_FAILURE);
    }
    pid = fork(); // creating parent-child processes
    if (pid == -1)
    {
        perror("Fork hiba");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {                     // child process
        // Reading parent pipe
        printf("Gyerek indul!\n");
        sleep(2);         // sleeping a few seconds, not necessary
        close(pipefd_p[1]); //Usually we close the unused write end
        printf("Gyerek elkezdi olvasni a csobol az adatokat!\n");
        read(pipefd_p[0], sz, sizeof(sz)); // reading max 100 chars
        printf("Gyerek olvasta uzenet: %s", sz);
        printf("\n");
        close(pipefd_p[0]); // finally we close the used read end

        // Writing child pipe
        close(pipefd_c[0]);
        write(pipefd_c[1], "Hajra Fradi!", 13);
        close(pipefd_c[1]);
        printf("Gyerek beirta az adatokat a csobe!\n");
        fflush(NULL);
        wait(NULL);
        printf("Gyerek befejezte!");
    }
    else
    { // szulo process
        // Writing child pipe
        printf("Szulo indul!\n");
        close(pipefd_p[0]); //Usually we close unused read end
        write(pipefd_p[1], "Hajra Fradi!", 13);
        close(pipefd_p[1]); // Closing write descriptor
        printf("Szulo beirta az adatokat a csobe!\n");
        fflush(NULL); // flushes all write buffers (not necessary)
        wait(NULL);   // waiting for child process (not necessary)
                      // try it without wait()

        // Reading parent pipe
        sleep(3);
        close(pipefd_c[1]);
        printf("Szulo elkezdi olvasni a csobol az adatokat!\n");
        read(pipefd_c[0], sz, sizeof(sz));
        printf("Szulo olvasta uzenet: %s", sz);
        printf("\n");
        close(pipefd_c[0]);
        printf("Szulo befejezte!");
    }
    exit(EXIT_SUCCESS); // force exit, not necessary
}
