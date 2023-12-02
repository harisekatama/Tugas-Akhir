import bluetooth
import datetime

# ESP32's Bluetooth MAC address
esp32_mac_address = "30:C6:F7:2F:31:86"  # Replace with your ESP32's MAC addres

# Establish a Bluetooth connection
sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
sock.connect(
    (esp32_mac_address, 1)
)  # Channel 1 is commonly used for SPP (Serial Port Profile)

while True:
    # Send two data values
    arah = input("Enter arah : ")
    kecepatan = input("Enter kecepatan : ")
    message = f"{arah},{kecepatan}"
    date = datetime.datetime.now()
    print(date)

    if arah == "q" or kecepatan == "q":
        break

    sock.send(message)

# Close the Bluetooth connection
sock.close()
