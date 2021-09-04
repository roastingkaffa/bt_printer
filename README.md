# bt_printer
Function : bluetooth printer
Printer Devices : EPSON
Host Devices : raspberry pi4 

Bluetooth Printer need install package :

ubuntu install package for bluetooth
1. sudo apt-get install libbluetooth-dev
2. sudo apt-get install python-dev or python3-dev
3. sudo apt-get install bluez
4. sudo apt-get install bluetooth

install python package for printer used
1. sudo apt install python-pip
2. sudo pip install PyESCPOS
3. sudo pip install pyescpos[bluetooth]
4. suod pip install pip install pybluez==0.22   (if used python2.7 versoin need used pybluez0.22 veriosn))
python command Bluetooth Example
Support for Bluetooth (via RFCOMM) connection is optional.
If you need it you should have PyBluez library installed.
One option may be installing PyESCPOS through PIP issuing pip install PyESCPOS[bluetooth].

Here is how you can make a Bluetooth connection:
============ python example code ==============
import bluetooth

from escpos import BluetoothConnection
from escpos.impl.epson import GenericESCPOS

# uses SPD (service port discovery) services to find which port to connect to
conn = BluetoothConnection.create('00:01:02:03:04:05')
printer = GenericESCPOS(conn)
printer.init()
printer.text('Hello World!')

=============== example code ==================


================= C Code =======================
Used gcc compiler C file need include bluetooth libe
command : gcc c_code_name .c -o c_code_name -lm -lbluetooth

create RFCOMM c code example
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
        status = write(s, "hello!", 6);
        printf("Hello, world!\n");
    }

    if( status < 0 ){
            perror("uh oh");
            printf("uh oh!\n");
    }

    close(s);
    return 0;
}

================ C code example =================

