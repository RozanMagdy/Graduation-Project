# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import tensorflow as tf
import numpy as np

import matplotlib.pyplot as plt
import matplotlib.font_manager as fm

import random
import math
import cv2

from sklearn.utils import shuffle

mnist = tf.keras.datasets.mnist

(x_train, y_train), (x_test, y_test) = mnist.load_data()
x_valid, y_valid = x_train[:10000], y_train[:10000]
x_train, y_train = x_train[10000:], y_train[10000:] 
x_train, x_valid, x_test = x_train / 255.0, x_valid / 255.0, x_test / 255.0

x_train = np.asarray([np.pad(img, ((2,2),(2,2)), 'constant') for img in x_train])
x_valid = np.asarray([np.pad(img, ((2,2),(2,2)), 'constant') for img in x_valid])
x_test  = np.asarray([np.pad(img, ((2,2),(2,2)), 'constant') for img in x_test])

# Number of training examples
n_train = len(x_train)

n_test = len(x_test)
n_valid = len(x_valid)
image_shape = x_train.shape[1:]
n_classes = len(np.unique(y_train))
classes = np.unique(y_train)

print("Number of training examples =", n_train)
print("Number of testing examples =", n_test)
print("Number of validation examples =", n_valid)
print("Image data shape =", image_shape)
print("Number of classes =", n_classes)


plt.rcdefaults()
fig, ax = plt.subplots()

samples_per_category = [len(np.where(y_train==cat_id)[0]) for cat_id in classes]
category_names = [str(element) for element in classes]

min_cnt = min(samples_per_category)
max_cnt = max(samples_per_category)

y_pos = np.arange(len(category_names))

rects = ax.barh(y_pos, 
                samples_per_category, 
                align='center', 
                color=['green' if val != min_cnt and val != max_cnt \
                       else 'yellow' if val == min_cnt \
                       else 'red' for val in samples_per_category])

# setting labels for each bar
for i in range(0,len(rects)):
    ax.text(int(rects[i].get_width()), 
            int(rects[i].get_y()+rects[i].get_height()/2.0),
            samples_per_category[i],
            fontproperties=fm.FontProperties(size=5))

ax.set_yticks(y_pos)
ax.set_yticklabels(category_names,fontproperties=fm.FontProperties(size=5))
ax.invert_yaxis()
ax.set_title('Samples per Category')

plt.show()

# Visualizations will be shown in the notebook.
#%matplotlib inline

h_or_w = image_shape[0]
fig = plt.figure(figsize=(h_or_w,h_or_w))
for i in range(0, n_classes):
    samples = np.where(y_train==i)[0]
    index = random.randint(0, len(samples) - 1)
    image = x_train[samples[index]]
    
    ax = fig.add_subplot(math.ceil(n_classes/5), 5, i+1)
    ax.set_title(category_names[i])
    ax.set_ylabel("id: {id}".format(id=i))
    plt.imshow(image)
plt.savefig("fig")
plt.show()

x_train, y_train = shuffle(x_train, y_train)

def LeNet(x, channels, classes, keep_prob, mu=0, sigma=0.01):    
    # Arguments used for tf.truncated_normal, randomly defines variables 
    # for the weights and biases for each layer
    
    # Layer 1: Convolutional. Input = 32x32xchannels. Output = 28x28x6.
    conv1_W = tf.Variable(tf.truncated_normal(shape=(5, 5, channels, 6), mean = mu, stddev = sigma))
    conv1_b = tf.Variable(tf.zeros(6))
    conv1   = tf.nn.conv2d(x, conv1_W, strides=[1, 1, 1, 1], padding='VALID') + conv1_b

    # Layer 1: Activation.
    conv1 = tf.nn.relu(conv1)

    # Layer 1: Pooling. Input = 28x28x6. Output = 14x14x6.
    conv1 = tf.nn.max_pool(conv1, ksize=[1, 2, 2, 1], strides=[1, 2, 2, 1], padding='VALID')

    # Layer 2: Convolutional. Output = 10x10x16.
    conv2_W = tf.Variable(tf.truncated_normal(shape=(5, 5, 6, 16), mean = mu, stddev = sigma))
    conv2_b = tf.Variable(tf.zeros(16))
    conv2   = tf.nn.conv2d(conv1, conv2_W, strides=[1, 1, 1, 1], padding='VALID') + conv2_b
    
    # Layer 2: Activation.
    conv2 = tf.nn.relu(conv2)

    # Layer 2: Pooling. Input = 10x10x16. Output = 5x5x16.
    conv2 = tf.nn.max_pool(conv2, ksize=[1, 2, 2, 1], strides=[1, 2, 2, 1], padding='VALID')

    # Layer 2: Flatten. Input = 5x5x16. Output = 400.
    fc0   = tf.nest.flatten(conv2)
    fc0   = tf.nn.dropout(fc0, keep_prob=keep_prob)
    
    # Layer 3: Fully Connected. Input = 400. Output = 120.
    fc1_W = tf.Variable(tf.truncated_normal(shape=(400, 120), mean = mu, stddev = sigma))
    fc1_b = tf.Variable(tf.zeros(120))
    fc1   = tf.matmul(fc0, fc1_W) + fc1_b
    
    # Layer 3: Activation.
    fc1    = tf.nn.relu(fc1)

    # Layer 4: Fully Connected. Input = 120. Output = 84.
    fc2_W  = tf.Variable(tf.truncated_normal(shape=(120, 84), mean = mu, stddev = sigma))
    fc2_b  = tf.Variable(tf.zeros(84))
    fc2    = tf.matmul(fc1, fc2_W) + fc2_b
    
    # Layer 4: Activation.
    fc2    = tf.nn.relu(fc2)

    # Layer 5: Fully Connected. Input = 84. Output = 10.
    fc3_W  = tf.Variable(tf.truncated_normal(shape=(84, classes), mean = mu, stddev = sigma))
    fc3_b  = tf.Variable(tf.zeros(classes))
    logits = tf.matmul(fc2, fc3_W) + fc3_b
    
    return logits

# x is a placeholder for a batch of input images
x = tf.placeholder(tf.float32, (None,) + image_shape + (1,))
#
## y is a placeholder for a batch of output labels
y = tf.placeholder(tf.int32, (None))
    
one_hot_y = tf.one_hot(y, n_classes)

# hyperparameters of the training process
RATE = 0.0008
EPOCHS = 30
BATCH_SIZE = 128
KEEP_PROB = 0.7
STDDEV = 0.01

keep_prob = tf.placeholder(tf.float32)
logits = LeNet(x, 1, n_classes, keep_prob, sigma=STDDEV)
cross_entropy = tf.nn.softmax_cross_entropy_with_logits(labels=one_hot_y, logits=logits)
loss_operation = tf.reduce_mean(cross_entropy)
optimizer = tf.train.AdamOptimizer(learning_rate = RATE)
training_operation = optimizer.minimize(loss_operation)

correct_prediction = tf.equal(tf.argmax(logits, 1), tf.argmax(one_hot_y, 1))
accuracy_operation = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))
saver = tf.train.Saver()

def evaluate(X_data, y_data):
    num_examples = len(X_data)
    total_accuracy = 0
    sess = tf.get_default_session()
    for offset in range(0, num_examples, BATCH_SIZE):
        batch_x, batch_y = X_data[offset:offset+BATCH_SIZE], y_data[offset:offset+BATCH_SIZE]
        accuracy = sess.run(accuracy_operation, feed_dict={x: batch_x, y: batch_y, keep_prob: 1})
        total_accuracy += (accuracy * len(batch_x))
    return total_accuracy / num_examples

with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())
    num_examples = len(x_train)
    
    print("Training...")
    print()
    for i in range(EPOCHS):
        x_train, y_train = shuffle(x_train, y_train)
        for offset in range(0, num_examples, BATCH_SIZE):
            end = offset + BATCH_SIZE
            batch_x, batch_y = x_train[offset:end], y_train[offset:end]
            sess.run(training_operation, feed_dict={x: batch_x, y: batch_y, keep_prob: KEEP_PROB})
            
        train_accuracy = evaluate(x_train, y_train)    
        validation_accuracy = evaluate(x_valid, y_valid)
        print("EPOCH {} ...".format(i+1))
        print("Train Accuracy = {:.3f}".format(train_accuracy))
        print("Validation Accuracy = {:.3f}".format(validation_accuracy))
        print()
    
    test_accuracy = evaluate(x_test, y_test)
    
#    saver.save(sess, './model.ckpt')
#    print("Model saved")
    
    
########################################################
########################################################
########################################################
    
#with tf.Session() as sess:
#    saver.restore(sess, './model.ckpt')
#    print("Test Accuracy = {:.3f}".format(test_accuracy))
