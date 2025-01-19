import numpy as np 
import cv2 
import serial
import time

# Initialize serial communication with Arduino
arduino = serial.Serial('COM7', 9600)  # Change 'COM3' to the appropriate port for your system
time.sleep(2)  # Allow time for the serial connection to initialize

# Capturing video through webcam 
webcam = cv2.VideoCapture(1) 

def send_signal_to_arduino(signal):
    if signal:
        arduino.write(b'1')  # Send '1' to Arduino to turn on the LED
        print("Sent 1 to Arduino")
    else:
        arduino.write(b'0')  # Send '0' to Arduino to turn off the LED
        print("Sent 0 to Arduino")

# Start a while loop 
while True: 
    # Reading the video from the webcam in image frames 
    _, imageFrame = webcam.read() 

    # Convert the imageFrame in BGR(RGB color space) to HSV(hue-saturation-value) color space 
    hsvFrame = cv2.cvtColor(imageFrame, cv2.COLOR_BGR2HSV) 

    # Set range for red color and define mask 
    red_lower = np.array([136, 87, 111], np.uint8) 
    red_upper = np.array([180, 255, 255], np.uint8) 
    red_mask = cv2.inRange(hsvFrame, red_lower, red_upper) 

    # Set range for yellow color and define mask 
    yellow_lower = np.array([20, 100, 100], np.uint8)
    yellow_upper = np.array([30, 255, 255], np.uint8)
    yellow_mask = cv2.inRange(hsvFrame, yellow_lower, yellow_upper)

    # Morphological Transform, Dilation for red and yellow colors
    kernel = np.ones((5, 5), "uint8") 
    red_mask = cv2.dilate(red_mask, kernel) 
    yellow_mask = cv2.dilate(yellow_mask, kernel) 

    # Creating contours to track red color 
    contours_red, _ = cv2.findContours(red_mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE) 
    
    red_detected = False
    for pic, contour in enumerate(contours_red): 
        area = cv2.contourArea(contour) 
        if area > 300: 
            x, y, w, h = cv2.boundingRect(contour) 
            imageFrame = cv2.rectangle(imageFrame, (x, y), (x + w, y + h), (0, 0, 255), 2) 
            cv2.putText(imageFrame, "Red Colour", (x, y), cv2.FONT_HERSHEY_SIMPLEX, 1.0, (0, 0, 255))     
            red_detected = True

    # Creating contours to track yellow color 
    contours_yellow, _ = cv2.findContours(yellow_mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE) 
    
    yellow_detected = False
    for pic, contour in enumerate(contours_yellow): 
        area = cv2.contourArea(contour) 
        if area > 300: 
            x, y, w, h = cv2.boundingRect(contour) 
            imageFrame = cv2.rectangle(imageFrame, (x, y), (x + w, y + h), (0, 255, 255), 2) 
            cv2.putText(imageFrame, "Yellow Colour", (x, y), cv2.FONT_HERSHEY_SIMPLEX, 1.0, (0, 255, 255))     
            yellow_detected = True

    # Send signal to Arduino if either red or yellow is detected
    send_signal_to_arduino(yellow_detected)

    # Display the result frame
    cv2.imshow("Multiple Color Detection in Real-Time", imageFrame) 

    # Break the loop if 'q' key is pressed
    if cv2.waitKey(10) & 0xFF == ord('q'): 
        send_signal_to_arduino(False)  # Ensure LED is turned off before exiting
        webcam.release() 
        cv2.destroyAllWindows() 
        break
