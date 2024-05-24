#include <stdio.h>
#include<conio.h>
#define MAX_BUFFER_SIZE 100

int main() {
  char buffer[MAX_BUFFER_SIZE]; // Define a buffer to store input
    printf("Enter some text: ");
    
    // Read input into the buffer
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Print the contents of the buffer
    printf("Buffer contents: %s\n", buffer);
    getch();
    return 0;
}
