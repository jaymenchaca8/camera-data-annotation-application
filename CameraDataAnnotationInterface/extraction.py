#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Copyright 2016 Massachusetts Institute of Technology

"""Extract images from a rosbag.
"""
import sys
import os
import argparse

import cv2

import rosbag
from sensor_msgs.msg import Image
from cv_bridge import CvBridge

def main():

    """Extract a folder of images from a rosbag.
    """
    bag_file = sys.argv[1]
    image_topic = "/front_camera/image_raw"
    output_dir = sys.argv[2]
    

    print "Extract images from %s on topic %s into %s" % (bag_file,
                                                          image_topic, output_dir)

    bag = rosbag.Bag(bag_file, "r")
    print(bag)
    bridge = CvBridge()
    count = 0
    for topic, msg, t in bag.read_messages(topics=[image_topic]):
        cv_img = bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

        cv2.imwrite(os.path.join(output_dir, "frame%06i.png" % count), cv_img)
        print "Wrote image frame%06i.png" % count

        count += 1

    bag.close()

    return

if __name__ == '__main__':
    main()
