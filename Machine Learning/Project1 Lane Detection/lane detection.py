import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np
import cv2
import math



# Define a kernel size and apply Gaussian smoothing
kernel_size = 5
# Define our parameters for Canny and apply
low_threshold = 50
high_threshold = 150
# Define the Hough transform parameters
# Make a blank the same size as our image to draw on
rho = 2 # distance resolution in pixels of the Hough grid
theta = np.pi/180 # angular resolution in radians of the Hough grid
threshold = 25     # minimum number of votes (intersections in Hough grid cell)
min_line_length = 20 #minimum number of pixels making up a line
max_line_gap = 20    # maximum gap in pixels between connectable line segments



#reading in an image
image = cv2.imread('test_images/whiteCarLaneSwitch.jpg')

#printing out some stats and plotting
print('This image is:', type(image), 'with dimensions:', image.shape)

#converting image to greyscale
gray = cv2.cvtColor(image,cv2.COLOR_RGB2GRAY)

#"""Applies a Gaussian Noise kernel"""
blur_gray = cv2.GaussianBlur(gray,(kernel_size, kernel_size),0)

#"""Applies the Canny transform"""
edges = cv2.Canny(blur_gray, low_threshold, high_threshold)

# This time we are defining a four sided polygon to mask
imshape = image.shape
vertices = np.array([[(0,imshape[0]),(450, 320) ,(490, 320), (imshape[1],imshape[0])]], dtype=np.int32)
ignore_mask_color = 255


# Next we'll create a masked edges image using cv2.fillPoly()
mask = np.zeros_like(edges)   
cv2.fillPoly(mask, vertices, ignore_mask_color)
masked_edges = cv2.bitwise_and(edges, mask)

# Run Hough on edge detected image
# Output "lines" is an array containing endpoints of detected line segments
line_image = np.copy(image)*0 # creating a blank to draw lines on
lines = cv2.HoughLinesP(masked_edges, rho, theta, threshold, np.array([]),min_line_length, max_line_gap)

# Iterate over the output "lines" and draw lines on a blank image
for line in lines:
    for x1,y1,x2,y2 in line:
        cv2.line(line_image,(x1,y1),(x2,y2),(255,0,0),10)

# Draw the lines on the edge image
lines_edges = cv2.addWeighted(image, 0.8, line_image, 1, 0)

plt.imshow(lines_edges)
plt.show()

