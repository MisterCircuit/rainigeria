import serial
import time

# Initialize serial communication with the Arduino
arduino = serial.Serial(port='COM7', baudrate=115200, timeout=.1)

def write_read(x):
    # Send the string x to the Arduino
    arduino.write(bytes(x, 'utf-8'))
    # Wait for a short period to allow Arduino to process and respond
    time.sleep(0.05)
    # Read a line of data from the Arduino
    data = arduino.readline()
    return data

# Infinite loop to continuously interact with the user and Arduino
while True:
    # Take user input
    num = input("Enter a number: ")
    # Send the user input to the Arduino and read the response
    value = write_read(num)
    # Print the response from the Arduino
    # print(value)


    


