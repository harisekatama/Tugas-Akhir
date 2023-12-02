import socket
import time

import datetime

host = "192.168.4.1"  # Set to ESP32 Access Point IP Address
port = 80

# Create a socket connection
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    # Connect to the ESP32 server
    s.connect((host, port))

    while True:
        # Send two data values
        arah = input("Enter arah : ")
        kecepatan = input("Enter kecepatan : ")
        message = f"{arah},{kecepatan}"
        date = datetime.datetime.now()
        print(date)

        if arah == "q" or kecepatan == "q":
            break

        s.send(message.encode("utf-8"))

s.close()
