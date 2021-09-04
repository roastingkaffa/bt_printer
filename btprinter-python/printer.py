import bluetooth

from escpos import BluetoothConnection
from escpos.impl.epson import GenericESCPOS

# uses SPD (service port discovery) services to find which port to connect to
conn = BluetoothConnection.create('00:01:90:76:EC:60')
printer = GenericESCPOS(conn)
printer.init()
printer.text('teo')

# cut paper  command " \x0a\x0a\x0a\x1b\x69 "
