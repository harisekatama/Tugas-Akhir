import bluetooth
import json

# ESP32 Bluetooth address
esp32_address = "EC:62:60:9B:E4:92"  # Replace with your ESP32's Bluetooth address

# esp32_address = "30:C6:F7:2F:31:86" # Iqbal's ESP32

# Create a Bluetooth socket
sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)

# Connect to the ESP32
sock.connect((esp32_address, 1))

while True:
    # Get keyboard input for two values
    arah = input("Masukkan Arah: ")
    kecepatan = input("Masukkan Kecepatan: ")

    # Create a JSON object
    json_data = {"arah": arah, "kecepatan": kecepatan}

    # Serialize the JSON data
    json_string = json.dumps(json_data)

    if arah == "q" or kecepatan == "q":
        break

    # Send the serialized JSON over Bluetooth
    sock.send(json_string)

# Close the Bluetooth socket
sock.close()
