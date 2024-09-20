#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_FILE "myfifo"

int main() {
    int fd;
    char *message = "Hello from Writer program!";
    
    // Create the FIFO (named pipe) if it doesn't exist
    mkfifo(FIFO_FILE, 0666);

    // Open the FIFO for writing
    fd = open(FIFO_FILE, O_WRONLY);

    // Write the message to the FIFO
    write(fd, message, sizeof(message));

    printf("Writer: Message sent to FIFO.\n");

    // Close the FIFO
    close(fd);

    return 0;
}
