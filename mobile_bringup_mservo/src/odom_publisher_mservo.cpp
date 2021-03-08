#include <mobile_bringup_mservo/odom_publisher_mservo.hpp>

int main(int argc, char **argv)
{
    ros::init(argc,argv,"bringup_mservo");
    const int rate = 200;
    ros::Rate loop_rate(rate);

    OdomPublisher odom_publisher;

    odom_publisher.publisher_set();
    odom_publisher.subscriber_set();
    odom_publisher.initiate_variables();


    tf::TransformBroadcaster broadcaster;

    while (ros::ok())
    {
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}