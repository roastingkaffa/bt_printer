#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

int main(int argc, char **argv)
{
    struct sockaddr_rc addr = { 0 };
    int s, status;
    char dest[18] = "00:01:90:76:EC:60";

    // allocate a socket
    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

    // set the connection parameters (who to connect to)
    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = (uint8_t) 1;
    str2ba( dest, &addr.rc_bdaddr );

    // connect to server
    status = connect(s, (struct sockaddr *)&addr, sizeof(addr));

    // send a message
    if( status == 0 ) {
	status = write(s, "\x1B\x40",3); // init write function
        status = write(s, "Hello world!\n\n", 20); // printer message
        status = write(s, "***** start print =====\n\n", 20); // printer message
        status = write(s, "\n\x0a\x0a\x0a\x1b\x69", 6); // cut paper 
	printf("Hello, world!\n");
    }

    if( status < 0 ){
	    perror("uh oh");
	    printf("uh oh!\n");
    }

    close(s);
    return 0;
}
