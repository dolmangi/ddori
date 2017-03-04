#!/usr/bin/env python
#   Copyright 2012 Jon Stephan
#   jfstepha@gmail.com
#
#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program.  If not, see <http://www.gnu.org/licenses/>.

from array import array
import socket
import time
import sys
import rospy
import roslib
import re
from std_msgs.msg import Int16
# roslib.load_manifest('knex_ros')

############################################################
def sendScratchCommand(cmd):
############################################################
    n = len(cmd)
    a = array('c')
    a.append(chr((n >> 24) & 0xFF))
    a.append(chr((n >> 16) & 0xFF))
    a.append(chr((n >>  8) & 0xFF))
    a.append(chr(n & 0xFF))
    scratchSock.send(a.tostring() + cmd)
    
############################################################
def rangeCallback(msg):
############################################################
    sendScratchCommand("sensor-update \"range\" %d" % msg.data)
    
############################################################
if __name__ == '__main__':
############################################################
    rospy.loginfo("-I- knex_scratch_connector started")
    rospy.init_node('knex_scratch_connector')
    PORT = 42001
    HOST = 'localhost'

    rospy.loginfo("-D- Connecting...")
    scratchSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    scratchSock.connect((HOST, PORT))
    rospy.loginfo("-D- Connected!")
   
    pub_servo = [] 
    pub_servo.append(rospy.Publisher("servo1_cmd", Int16), queue_size=10)
    pub_servo.append(rospy.Publisher("servo2_cmd", Int16), queue_size=10)
    pub_servo.append(rospy.Publisher("servo3_cmd", Int16), queue_size=10)
    pub_servo.append(rospy.Publisher("servo4_cmd", Int16), queue_size=10)
    pub_servo.append(rospy.Publisher("servo5_cmd", Int16), queue_size=10)
    pub_servo.append(rospy.Publisher("servo6_cmd", Int16), queue_size=10)
    pub_servo.append(rospy.Publisher("servo7_cmd", Int16), queue_size=10)
    pub_servo.append(rospy.Publisher("servo8_cmd", Int16), queue_size=10)
    pub_servo.append(rospy.Publisher("servo9_cmd", Int16), queue_size=10)
    pub_servo.append(rospy.Publisher("servo10_cmd", Int16), queue_size=10)
    
    rospy.Subscriber("range", Int16, rangeCallback)

    while True:
        data = scratchSock.recv(1024)
        if not data: break
        l = list(data)
        # print ("list: %s" % str(l))
        msg_len = (ord(l[0]) << 24) + (ord(l[1]) << 16) + (ord(l[2]) << 8) + ord(l[3])
        l2 = l[4:]
        msg_str = ''.join(l2)
        rospy.loginfo("received %d bytes:%s" % (msg_len, msg_str))
        if(len(msg_str) != msg_len):
            rospy.logerr("-E- ERROR - message length differs from sent length.  (%d vs %d)" % (msg_len, len(msg_str)))
            
        print("find: %d" % msg_str.find('sensor-update "servo'))
        if(msg_str.find('sensor-update "servo') == 0):
            rospy.loginfo('-D- found sensor update')
            r = re.compile('servo(\d+)"\s+(\d+)')
            m = r.search(msg_str)
            servo_no = int(m.group(1))
            servo_val = int(m.group(2))
            if(servo_no > 0 and servo_no <= 10):
                pub_servo[servo_no-1].publish(servo_val)
            else:
                rospy.logerr("-E- servo %s out of range" % servo_no)
            
            
            