#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_FILE "myfifo"

int main() {
    int fd;
    char buffer[100];

    // Open the FIFO for reading
    fd = open(FIFO_FILE, O_RDONLY);

    // Read the message from the FIFO
    read(fd, buffer, sizeof(buffer));

    printf("Reader: Received message from FIFO: %s\n", buffer);

    // Close the FIFO
    close(fd);

    return 0;
}
