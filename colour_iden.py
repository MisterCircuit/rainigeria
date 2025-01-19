import cv2
import numpy as np
img = cv2.imread('C:/Users/lenovo/Downloads/cat_dog.jpg')
cv2.imshow('Original Image', img)
cv2.waitKey(0)
hsv_img = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

lower_range = np.array([50, 100, 100]) 
upper_range = np.array([70, 255, 255])

# lower range of red color in HSV
# lower_range = (0, 50, 50)

# upper range of red color in HSV
# upper_range = (150, 255, 255)

# upper_range = (86, 255, 255) # upper range of green color in HSV
# lower_range = (12, 25, 25) # lower range of green color in HSV
mask = cv2.inRange(hsv_img, lower_range, upper_range)
color_image = cv2.bitwise_and(img, img, mask=mask)

# Display the color of the image
cv2.imshow('Coloured Image', color_image)
cv2.waitKey(0)
cv2.destroyAllWindows()
