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

    """Extract tipics: from a rosbag.
    """    
    bag_file = sys.argv[1]
    bag = rosbag.Bag(bag_file, "r")
    bridge = CvBridge()
    count = 0
    types = []
    topic_lis = []
    topics = bag.get_type_and_topic_info()[1].keys()
    print( "extracting topics")
    for i in range(0,len(bag.get_type_and_topic_info()[1].values())):
        types.append(bag.get_type_and_topic_info()[1].values()[i][0])
    for i in types:
            if i == "sensor_msgs/Image":
               topic_lis.append( topics[types.index(i)]  )
    print(topic_lis)
    f = open("topiclist.txt", "a")
    f.truncate(0)
    f.write('\n'.join(topic_lis))
    f.close()
    print("extraction done")
    return

if __name__ == '__main__':
    main()