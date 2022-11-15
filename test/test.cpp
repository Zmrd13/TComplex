//
// Created by Weder on 06.11.2022.
//
#include "gtest/gtest.h"
#include "../TComplex.h"

TEST(TFrac_init,double_){
    double t1=23.1,t2=25.1;
auto c = TComplex(t1,t2);
    ASSERT_EQ(c.getReal(),t1);
    ASSERT_EQ(c.getImaginary(),t2);
}
TEST(TFrac_init,int_){
    int t1=23,t2=25;
    auto c = TComplex(t1,t2);
    ASSERT_EQ(c.getReal(),t1);
    ASSERT_EQ(c.getImaginary(),t2);
}
TEST(TFrac_init,str_int){
    auto c = TComplex("2+i*3");
    ASSERT_EQ(c.getReal(),2);
    ASSERT_EQ(c.getImaginary(),3);
}
TEST(TFrac_init,str_float){
    auto c = TComplex("2.1+i*3.2");
    ASSERT_EQ(c.getReal(),2.1);
    ASSERT_EQ(c.getImaginary(),3.2);
}
TEST(TFrac_math,square){
    ASSERT_TRUE(TComplex(3, 4).square() == TComplex(-7, 24));
}

TEST(TFrac_math,inv) {
ASSERT_TRUE(TComplex(3, 4).inverse() == TComplex(0.12, -0.16));
}

TEST(TFrac_math,abs)  {
    ASSERT_TRUE(TComplex(3, 4).abs() == hypot(3, 4));
}

TEST(TFrac_math,rad) {
    ASSERT_NEAR(TComplex(1, 1).angle_rad(),0.79,0.1);
}

TEST(TFrac_math,deg) {
    ASSERT_TRUE(TComplex(1, 1).angle_deg() == 45);
}

TEST(TFrac_math,add){
ASSERT_TRUE(TComplex(3, 4) + TComplex(2, 3) == TComplex(5, 7));
}

TEST(TFrac_math,mul){
ASSERT_TRUE(TComplex(2, 3) * TComplex(2, 2) == TComplex(-2, 10));
}

TEST(TFrac_math,sub){
ASSERT_TRUE(TComplex(3, 4) - TComplex(2, 3) == TComplex(1, 1));
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}