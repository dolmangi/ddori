#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <tf/tf.h>

ros::Publisher * imu_pub;
double yaw_offset;

void publishImuCallback(const sensor_msgs::Imu::ConstPtr& msg){

        sensor_msgs::Imu imu_corrected;

        imu_corrected.header.stamp = msg->header.stamp;
        imu_corrected.header.frame_id = msg->header.frame_id;

        imu_corrected.angular_velocity=msg->angular_velocity;
        imu_corrected.linear_acceleration=msg->linear_acceleration;
        imu_corrected.angular_velocity_covariance=msg->angular_velocity_covariance;
        imu_corrected.linear_acceleration_covariance=msg->linear_acceleration_covariance;

        imu_corrected.orientation_covariance=msg->orientation_covariance;

        double roll, pitch , yaw;
        tf::Quaternion q(msg->orientation.x,msg->orientation.y,msg->orientation.z,msg->orientation.w);
        tf::Matrix3x3 m(q);
        m.getRPY(roll, pitch, yaw);
        yaw +=yaw_offset;
        tf::Quaternion q_new;
        q_new.setRPY(roll,pitch,yaw);
        imu_corrected.orientation.x=q_new.getX();
        imu_corrected.orientation.y=q_new.getY();
        imu_corrected.orientation.z=q_new.getZ();
        imu_corrected.orientation.w=q_new.getW();

        imu_pub->publish(imu_corrected);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "imu_yaw_offset");

    ros::NodeHandle n;
    ros::NodeHandle pn("~");

    std::string topic;
    pn.param<std::string>("imu_topic",topic,"/imu/data");
    pn.param<double>("yaw_offset",yaw_offset,0);

    ros::Publisher pub = n.advertise<sensor_msgs::Imu>("/imu/data_corrected", 10);

    imu_pub=&pub;

    ros::Subscriber sub = n.subscribe<sensor_msgs::Imu>(topic,10,publishImuCallback);

    ros::spin();


    return 0;
}
