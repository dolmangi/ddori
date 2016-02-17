#!/usr/bin/env python

"""
   wheel_scaler
   scales the wheel readings (and inverts the sign)
   
     Copyright (C) 2012 Jon Stephan. 
     
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
   
"""

import rospy
import roslib

from std_msgs.msg import Int16
from std_msgs.msg import Float32

def lwheelCallback(msg):
    lscaled_pub.publish( msg.data * -1 * scale)
    
def rwheelCallback(msg):
    rscaled_pub.publish( msg.data * -1 * scale)
    

if __name__ == '__main__':
    """main"""
    rospy.init_node("wheel_scaler")
    rospy.loginfo("wheel_scaler started")
    
    scale = rospy.get_param('distance_scale', 1)
    rospy.loginfo("wheel_scaler scale: %0.2f", scale)
    
    rospy.Subscriber("lwheel", Float32, lwheelCallback)
    rospy.Subscriber("rwheel", Float32, rwheelCallback)
    
    lscaled_pub = rospy.Publisher("lwheel_scaled", Float32, queue_size=10)
    rscaled_pub = rospy.Publisher("rwheel_scaled", Float32, queue_size=10) 
    
    ### testing sleep CPU usage
    r = rospy.Rate(50) 
    while not rospy.is_shutdown:
        r.sleep()
        
    rospy.spin()
