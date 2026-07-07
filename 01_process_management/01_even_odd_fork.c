/*
============================================================
Program : Parent Prints Even Numbers
          Child Prints Odd Numbers using fork()
Author  : Dheenu
Purpose : Demonstrate process creation using fork().
============================================================
*/

#include <stdio.h>      // For printf()
#include <unistd.h>     // For fork(), getpid(), getppid()
#include <sys/wait.h>   // For wait()

int main()
{
    int pid;

    // Create a child process
    pid = fork();

    // Check whether fork() failed
    if (pid < 0)
    {
        printf("Error: Child process could not be created.\n");
        return 1;
    }

    // Child Process
    else if (pid == 0)
    {
        printf("\n========== CHILD PROCESS ==========\n");
        printf("Child PID  : %d\n", getpid());
        printf("Parent PID : %d\n\n", getppid());

        printf("Odd Numbers (1 to 100):\n");

        for (int i = 1; i <= 100; i++)
        {
            if (i % 2 != 0)
            {
                printf("%d ", i);
            }
        }

        printf("\n");
    }

    // Parent Process
    else
    {
        printf("\n========== PARENT PROCESS ==========\n");
        printf("Parent PID : %d\n", getpid());
        printf("Child PID  : %d\n\n", pid);

        printf("Even Numbers (1 to 100):\n");

        for (int i = 1; i <= 100; i++)
        {
            if (i % 2 == 0)
            {
                printf("%d ", i);
            }
        }

        printf("\n");

        // Wait until the child process finishes
        wait(NULL);

        printf("\nChild process completed.\n");
    }

    return 0;
}
