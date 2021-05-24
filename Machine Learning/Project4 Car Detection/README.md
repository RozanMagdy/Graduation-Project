## Vehicle Detection Project

[![Udacity - Self-Driving Car NanoDegree](https://s3.amazonaws.com/udacity-sdc/github/shield-carnd.svg)](http://www.udacity.com/drive)

The steps of this project are the following:

* Perform a Histogram of Oriented Gradients (HOG) feature extraction on a labeled training set of images and train a classifier Linear SVM classifier
* Optionally, you can also apply a color transform and append binned color features, as well as histograms of color, to your HOG feature vector.
* Note: for those first two steps don't forget to normalize your features and randomize a selection for training and testing.
* Implement a sliding-window technique and use your trained classifier to search for vehicles in images.
* Run your pipeline on a video stream (start with the test_video.mp4 and later implement on full project_video.mp4) and create a heat map of recurring detections frame by frame to reject outliers and follow detected vehicles.
* Estimate a bounding box for vehicles detected.

[//]: # (Image References)
[image1]: ./output_images/car_not_car.png
[image2]: ./output_images/HOG_example.png
[image3]: ./output_images/sliding_windows.png
[image4]: ./output_images/sliding_window.jpg
[image5]: ./output_images/bboxes_and_heat.png
[image6]: ./output_images/labels_map.png
[image7]: ./output_images/output_bboxes.png
[video1]: ./project_video.mp4

---
### Histogram of Oriented Gradients (HOG)

#### 1. Perform a Histogram of Oriented Gradients (HOG) feature extraction on a labeled training set of images and train a classifier Linear SVM classifier

I started by reading in all the `vehicle` and `non-vehicle` images provided. Checked to see if the number of examples images loaded was correct and the set was well balanced in terms of the 2 classes of images. Here is an example of one of each of the `vehicle` and `non-vehicle` classes:

![alt text][image1]

I then explored different color spaces and different `HOG` parameters (`orientations`, `pixels_per_cell`, and `cells_per_block`).  I grabbed random images from each of the two classes and displayed them to get a feel for what the `HOG` output looks like.
Here is an example using the `YCrCb` color space and HOG parameters of `orientations=9`, `pixels_per_cell=(8, 8)` and `cells_per_block=(2, 2)`:

![alt text][image2]

#### 2. Choice of HOG parameters.

Having tried various combinations of parameters and measuring the accuracy of the Linear SVM classifier on a small set of 1000 test images, I found choosing the following parameters provided the highest accuracy of ~99%
```python
test_cars = np.array(cars)[random_idxs]
test_notcars = np.array(notcars)[random_idxs]

color_space = 'YCrCb'
orient = 9
pix_per_cell = 8
cell_per_block = 2
hog_channel = "ALL"
spatial_size = (32, 32)
hist_bins = 32
```
Features were scaled to zero mean and unit variance before training the classifier using scikit's `StandardScaler()` function.

#### 3. Training a classifier using the selected HOG features and color features

I used a Linear SVM classifier to train a classification model based on the parameters above. The code is present in the `test_performance()` method in `./VehicleDetection.ipynb#Train-and-test-a-Linear-SVM-classifier`. The classifier was trained on all training images after the choice of best parameters was established.

### Sliding Window Search

#### 1. Implementation of sliding window search and selecting and scale overlap windows

It was pretty clear from the sample images that cropping the portion of image above 400px would be favorable since it would cut down the number of windows that have to be searched. I played around with window sizes of `(64, 64)`, `(96, 96)`, and `(128, 128)`. `(96, 96)` window size gave the best results for identifying cars in the set of test images. I experimented with a few overlap and scale values but in the end found the default values of `0.5` overlap gave the optimal performance. For scale I found a combination of `1.5`, `2.0` and `2.5` worked pretty well and decided to stick to it.

![alt text][image3]

#### 2. Applying pipeline to test images and optimizing the performance of the classifier

Ultimately I searched on the 3 scales (`1.5`, `2.0` and `2.5`) using YCrCb 3-channel HOG features plus spatially binned color and histograms of color in the feature vector, which provided a nice result. For optimizing the performance, I used the HOG sub-sampling approach mentioned in the lesson (`./VehicleDetection.ipynb#Hog-Sub-sampling-Window-Search`) so that I can calculate HOG features once and just sub-sample per window.

![alt text][image5]
---

### Video Implementation
Here's a link to my video result

[![Vehicle-Detection](http://img.youtube.com/vi/GXr8r_DH3Ko/0.jpg)](http://www.youtube.com/watch?v=GXr8r_DH3Ko "Vehicle-Detection")


#### 2. Filter implementation for false positives and for combining overlapping bounding boxes.

I recorded the positions of positive detection bounding boxes in each frame of the video. From the positive detections I created a heatmap and then thresholded that map to identify vehicle positions. I then used `scipy.ndimage.measurements.label()` to identify individual blobs in the heatmap. I then assumed each blob corresponded to a vehicle. I constructed bounding boxes to cover the area of each blob detected.
I created a `collections.deque()` to keep track of the last 10 heatmaps to threshold over and avoid false positives and jittering. I experimented with threshold values and found 8 to be the value which provided the best results.

---

### Discussion

#### 1. Briefly discuss any problems / issues you faced in your implementation of this project.  Where will your pipeline likely fail?  What could you do to make it more robust?

The pipeline performs fairly well on the project video. However, there are some points to be addressed and scope for improvement
* The pipeline doesn't perform very well when there are vehicles overlapping or very close by
* While adding thresholding over last 10 frames removed some false positives, there are still some frames where false positives are identified, especially in regions of shadow. There is scope for improving the logic for thresholding over the last few frames as well as improving the model
* Also, improving thresholding logic, as stated in the above, over the last few frames can remove the frequent changes in bounding box sizes and reduce jitter
