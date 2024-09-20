/*
============================================================================
Name : 13b.c
Author : Nishad Bagade
Question : Sending SIGSTOP Signal
Date: 19th - Sept - 2024

Output:
nishad@nishad-ROG-Zephyrus-G14-GA401QM-GA401QM:~/Desktop/Hands_On_List_2$ ./12
Parent process with PID: 6508
Child process created with PID: 6509
Child will now kill the parent process (PID: 6508)
Child process (orphan) is running with parent terminated.
Killed
nishad@nishad-ROG-Zephyrus-G14-GA401QM-GA401QM:~/Desktop/Hands_On_List_2$ Child process (orphan) is now adopted by init (or systemd) with PID 1.
^C
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    pid_t pid;
    printf("Enter the PID of the first program: ");
    scanf("%d", &pid);

    // Send SIGSTOP signal to the first program
    if (kill(pid, SIGSTOP) == 0) {
        printf("SIGSTOP signal sent to process %d\n", pid);
    } else {
        perror("Failed to send SIGSTOP");
    }

    // Wait for a few seconds and send SIGCONT to resume the process
    sleep(5);
    if (kill(pid, SIGCONT) == 0) {
        printf("SIGCONT signal sent to resume process %d\n", pid);
    } else {
        perror("Failed to send SIGCONT");
    }

    return 0;
}
