#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SerialReaderLinux(char *argv[]);
void SerialReaderWindows(char *argv[]);

int main(int argc, char *argv []) {
    
    printf("\n====== Serial Reader Antares ======\n");

    #ifdef __linux__
        SerialReaderLinux(argv);
    #elif _WIN32
        SerialReaderWindows(argv);
    #else
        printf("Sorry, this app is not supported for you SO");
    #endif
        return 0;
}

void SerialReaderLinux(char *argv[]){
    printf("\nWorking on Linux system...\n");
    
    // GNU/Linux Headers
    #include <fcntl.h> // Contains file controls like O_RDWR
    #include <errno.h> // Error integer and stderror() function
    #include <termios.h> // Contains POSIX terminal control definitions
    #include <unistd.h> // write(), read(), close()
    
    printf("Including Linux libraries...\n");
    
    size_t port_size = strlen(argv[1]); // sizeof(argv[1][0]) ;

    if(argv[1] && port_size>3){
        // Loading a port 
        printf("The selected port is: %s\n", argv[1]);
        
        // Declaration and concatenation for the asigned port 
        char port[port_size+3]; 
        strcat(port, argv[1]);

        printf("\nConnecting to: %s\n", port);

        // Opening serial port 
        
        int serial_port = open(port, O_RDWR);

        if(serial_port < 0){
            printf("\nError %i from open %s, returned %s\n", errno, port, strerror(errno));
        }
    }else {
        // A port was not selected
        printf("Invalid port, please type a port for the conection\n");
    }

}

void SerialReaderWindows(char *argv[]){
    printf("Working on Windows system...\n");
}
