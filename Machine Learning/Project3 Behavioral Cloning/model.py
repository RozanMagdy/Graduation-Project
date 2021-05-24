import csv
import cv2
import numpy as np
import sklearn

lines = []
with open('data/driving_log.csv') as csvfile:
    reader = csv.reader(csvfile)
    for line in reader :
        lines.append(line)
lines = lines[1:]

from sklearn.model_selection import train_test_split
from sklearn.utils import shuffle
train_samples, validation_samples = train_test_split(lines, test_size=0.2)

#images = []
#measurements = []
#
#for line in lines :
#    for i in range(3) :
#        source_path = line[i]
#        filename = source_path.split('/')[-1]
#        current_path = 'data/IMG/' + filename
#        image = cv2.imread(current_path)
#        images.append(image)
#        measurement = float(line[3])
#        measurements.append(measurement)
#        if i != 0:
#            images.append(cv2.flip(image, 1))
#            measurements.append(measurement*-1)
#
#X_train = np.array(images)
#y_train = np.array(measurements)

def generator(samples, batch_size=32):
    num_samples = len(samples)
    while 1: # Loop forever so the generator never terminates
        shuffle(samples)
        for offset in range(0, num_samples, batch_size):
            batch_samples = samples[offset:offset+batch_size]

            images = []
            angles = []
            for batch_sample in batch_samples:
                for i in range(3):
                    name = 'data/IMG/'+ batch_sample[i].split('/')[-1]
                    image = cv2.imread(name)
                    images.append(image)
                    angle = float(batch_sample[3])
                    angles.append(angle)
                    if i != 0:
                        images.append(cv2.flip(image, 1))#flip the images in order
                        angles.append(angle*-1)          ##to generalize better
            # trim image to only see section with road
            X_train = np.array(images)
            y_train = np.array(angles)
            yield shuffle(X_train, y_train)

train_generator = generator(train_samples, batch_size=32)
validation_generator = generator(validation_samples, batch_size=32)

from keras.models import Sequential
from keras.layers import Flatten, Dense, Lambda, Cropping2D
from keras.layers.pooling import MaxPooling2D
from keras.layers.convolutional import Convolution2D
from math  import ceil
import matplotlib.pyplot as plt

batch_size=32

model = Sequential()
model.add(Lambda(lambda x: x/127.5 -1, input_shape=(160, 320, 3)))#normalization
model.add(Cropping2D(cropping=((70, 25), (0, 0))))
model.add(Convolution2D(6, 5, 5, activation='relu'))
model.add(MaxPooling2D())
model.add(Convolution2D(6, 5, 5, activation='relu'))
model.add(MaxPooling2D())
model.add(Flatten())
model.add(Dense(128))
model.add(Dense(84))
model.add(Dense(1))

model.compile(loss='mse', optimizer='adam', metrics=['accuracy'])
history_object = model.fit_generator(train_generator, \
                 steps_per_epoch  = ceil(len(train_samples)/batch_size), \
                 validation_data  = validation_generator, \
                 validation_steps = ceil(len(validation_samples)/batch_size), \
                 epochs = 5, verbose = 1)
### print the keys contained in the history object
print(history_object.history.keys())

### plot the training and validation loss for each epoch
plt.plot(history_object.history['loss'])
plt.plot(history_object.history['val_loss'])
plt.title('model mean squared error loss')
plt.ylabel('mean squared error loss')
plt.xlabel('epoch')
plt.legend(['training set', 'validation set'], loc='upper right')
plt.show()

model.save('model.h5')