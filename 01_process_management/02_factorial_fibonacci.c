/*
=========================================================
Program : Parent creates two child processes
          Child 1 -> Factorial
          Child 2 -> Fibonacci
Author  : Dheenu
=========================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int num;
    pid_t pid1, pid2;

    printf("Enter a number: ");
    scanf("%d", &num);

    // Create Child 1
    pid1 = fork();

    if (pid1 < 0)
    {
        printf("Failed to create Child 1\n");
        return 1;
    }

    // Child 1
    if (pid1 == 0)
    {
        long long factorial = 1;

        printf("\n========== CHILD 1 ==========\n");
        printf("Child PID  : %d\n", getpid());
        printf("Parent PID : %d\n", getppid());

        for (int i = 1; i <= num; i++)
        {
            factorial = factorial * i;
        }

        printf("Factorial of %d = %lld\n", num, factorial);

        exit(0);
    }

    // Only the parent reaches here
    pid2 = fork();

    if (pid2 < 0)
    {
        printf("Failed to create Child 2\n");
        return 1;
    }

    // Child 2
    if (pid2 == 0)
    {
        int first = 0;
        int second = 1;
        int next;

        printf("\n========== CHILD 2 ==========\n");
        printf("Child PID  : %d\n", getpid());
        printf("Parent PID : %d\n", getppid());

        printf("Fibonacci Series:\n");

        for (int i = 0; i < num; i++)
        {
            printf("%d ", first);

            next = first + second;
            first = second;
            second = next;
        }

        printf("\n");

        exit(0);
    }

    // Parent waits for both children
    wait(NULL);
    wait(NULL);

    printf("\n========== PARENT ==========\n");
    printf("Parent PID : %d\n", getpid());
    printf("Both child processes have completed.\n");

    return 0;
}
