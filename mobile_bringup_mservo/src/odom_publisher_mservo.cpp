#include <mobile_bringup_mservo/odom_publisher_mservo.hpp>


int main(int argc, char **argv)
{

    std::cout<<"Start\n";
    ros::init(argc,argv,"odom_mservo");
    
    OdomPublisher odom_publisher;

    const int rate = 200;
    ros::Rate loop_rate(rate);

    odom_publisher.publisher_set();
    odom_publisher.subscriber_set();
    odom_publisher.initiate_variables();

    tf::TransformBroadcaster broadcaster;

    while (ros::ok())
    {

        broadcaster.sendTransform(
        tf::StampedTransform(
    	tf::Transform(tf::Quaternion(cos(odom_publisher.yaw/2),0,0,sin(odom_publisher.yaw/2)), 
        tf::Vector3(odom_publisher.p_est_curr(0),odom_publisher.p_est_curr(1),0)),
    	ros::Time::now(),"odom", "base_footprint"
        )
      );
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;

}