#include <gtest/gtest.h>
#include "learn/animals.hpp"
#include <vector>
#include <algorithm>
TEST(learn, learn_animals_test)
{
    // sleep(3);
    std::vector<Animals> animVector(10000000);
    std::generate_n(animVector.begin(),10000000,[](){
        Animals a;
        return a;
    });
    
    auto assertion=[](Animals item){
        ASSERT_FALSE(std::find(Animals::names.cbegin(),Animals::names.cend(),item.getName())==Animals::names.cend());
    };
    std::for_each(animVector.begin(),animVector.end(),assertion);

}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}