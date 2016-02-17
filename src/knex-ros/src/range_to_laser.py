#!/usr/bin/env python

"""
   range_to_laser.py - makes the sony IR range finder look like a laser scanner
"""

# see http://www.ros.org/wiki/navigation/Tutorials/RobotSetup/Sensors for LaserScan setup

import rospy
import roslib
from numpy import array

from sensor_msgs.msg import LaserScan
from std_msgs.msg import Int16
from std_msgs.msg import Float32
from nav_msgs.msg import Odometry

########################################################
def rangeCallback(msg):
########################################################
    global latest_range
    latest_range = msg.data
    
########################################################
def stdCallback(msg):
########################################################
    global latest_std
    latest_std = msg.data
    
########################################################
def odomCallback(msg):
########################################################
    global moving
    if msg.twist.twist.linear.x != 0 or msg.twist.twist.angular.z != 0:
        # rospy.loginfo("-D- nonzero twist")
        moving = True
    


########################################################
def doAScan(direction):
########################################################
    global moving
    scan_rate = 50   # hertz between steps
    angle_slack = 0.25
   
    if direction:
        angle_start = 180
        angle_stop = 0
        angle_step = -1
    else:
        angle_start = 0
        angle_stop = 180
        angle_step = 1
    
    servo_pub.publish( angle_start )
    moving = False
    
    scan = LaserScan()
    num_readings = 0
    scan_time = rospy.Time.now()
    r = rospy.Rate(scan_rate)
    ranges = []
    for angle in range(angle_start, angle_stop, angle_step):
        if moving:
            break
        servo_pub.publish( angle )
        wait_start = rospy.Time.now()
        r.sleep()
#        while latest_std > std_threshold:
#            if rospy.Time.now() - wait_start > rospy.Duration(std_timeout):
#                rospy.loginfo("-W- range_to_laser timed out waiting for std_dev (%0.2f) to get below threshold (%0.2f)" % (latest_std, std_threshold) )
#                break
        # rospy.loginfo("angle %d range:%0.2f" % (angle, latest_range))
        num_readings += 1
        ranges_ary = array(ranges[-4:])
#        if ranges_ary.std() < 0.04: 
#        scan.intensities.append(100)
        ranges.append(latest_range * scale)
#        else:
#            ranges.append(1e4)
#            scan.intensities.append(0)
            
#        if latest_range > 0:
#            scan.intensities.append( 1 / ( ranges_ary.std() * 10 + .1 ) )
        if latest_range > 0:
            scan.intensities.append(1/latest_range)
        else:
            scan.intensities.append(0)
    scan.angle_min = -1.57
    scan.angle_max = 1.57
    
    if not direction:
        ranges.reverse()    
        scan.intensities.reverse()
        scan.angle_min += angle_slack
        scan.angle_max += angle_slack
        
    scan.ranges = ranges
    scan.header.stamp = scan_time;
    scan.header.frame_id = 'scanner'
    # TODO: change this to 'laser_frame'.  (create the transform first)
    scan.angle_increment = 3.14 / num_readings
    scan.time_increment = (1 / scan_rate)
    scan.range_min = 0.01 * scale
    scan.range_max = 2.0 * scale
    
    if not moving: 
        scan_pub.publish(scan)
    

########################################################
if __name__ == '__main__':
########################################################
    """main"""
    rospy.init_node("range_to_laser")
    rospy.loginfo("range_to_laser started")
    roslib.load_manifest('knex_ros')
    scale = rospy.get_param('~distance_scale', 1)
    std_threshold = rospy.get_param('std_threshold', 5)
    std_timeout = rospy.get_param('std_timeout', 40)
    rospy.loginfo("range_to_laser scale: %0.2f", scale)
    
    rospy.Subscriber("range_filtered", Float32, rangeCallback)
    rospy.Subscriber("range_std", Float32, stdCallback)
    servo_pub = rospy.Publisher('servo1_cmd', Int16, queue_size=10)
    scan_pub = rospy.Publisher('laser', LaserScan, queue_size=10)
    rospy.Subscriber("odom", Odometry, odomCallback)
    
    latest_range = 0.0;
    latest_std = 0.0
    
    r = rospy.Rate(1)  # hertz
    while not rospy.is_shutdown():
        moving = False
        doAScan(0)
        r.sleep()
        servo_pub.publish( 0 )
        rospy.sleep(1)
        
        # doAScan(1)
        #r.sleep()
        