//print out the last modification of file

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h> //stat
#include <unistd.h>   //stat
#include <time.h>     //ctime

int main(int argc, char **argv)
{
    struct stat st;
    stat(argv[0], &st); //fstat(file descriptor, stat structure)
    time_t t = st.st_mtime;
    int ot = st.st_size;
    printf("The last modification was: %s\n", ctime(&t)); //convert time_t to string
    printf("The file size is: %i bytes\n", ot);
    return 0;
}
