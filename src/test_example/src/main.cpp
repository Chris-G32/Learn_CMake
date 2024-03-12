#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include "learn/animals.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
// #include "learnTesting/Animals.hpp"

using namespace std::chrono_literals;

class AnimalMaker : public rclcpp::Node
{
public:
    AnimalMaker() : Node("animal_maker")
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
        timer_ = this->create_wall_timer(
            500ms, std::bind(&AnimalMaker::timer_callback, this));
    }

private:
    void timer_callback()
    {
        auto message = std_msgs::msg::String();
        Animals randAnim;
        std::string msgStr="Name: "+ randAnim.getName();
        message.data = msgStr.c_str();
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msgStr.c_str());
        publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<AnimalMaker>());
    rclcpp::shutdown();
    return 0;
}