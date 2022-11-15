//
// Created by Weder on 06.11.2022.
//
#include "gtest/gtest.h"
#include "../TComplexEditor.h"

TEST(TComplex_init,construction){
std::string expected = "0";
TComplexEditor a;
ASSERT_TRUE(expected == a.getComplexString());
}

TEST (TComplex_init,isZero_1) {
TComplexEditor a;
ASSERT_TRUE(a.isZero());
}

TEST (TComplex_init,isZero_2) {
TComplexEditor a;
a.addNumber(1);
ASSERT_FALSE(a.isZero());
}

TEST (TComplex_init,add_1) {
std::string expected = "1";
TComplexEditor a;
a.addNumber(1);
ASSERT_TRUE(expected == a.getComplexString());
}

TEST (TComplex_init,add_2) {
std::string expected = "-16";
TComplexEditor a;
a.addNumber(-16);
ASSERT_TRUE(expected == a.getComplexString());
}

TEST (TComplex_init,add_minus)  {
std::string expected = "-16";
TComplexEditor a;
a.addNumber(16);
a.addSign();
ASSERT_TRUE(expected == a.getComplexString());
}

TEST  (TComplex_init,add_minus_1)  {
std::string expected = "16+i*12";
TComplexEditor a;
a.setComplexString("-16+i*12");
a.addSign();
ASSERT_TRUE(expected == a.getComplexString());
}

TEST  (TComplex_init,add_minus_2)  {
std::string expected = "-5-i*10";
TComplexEditor a;
a.addNumber(-5);
a.addImPart();
a.addNumber(10);
a.addSign();
ASSERT_TRUE(expected == a.getComplexString());
}

TEST  (TComplex_init,add_im_1) {
std::string expected = "15+i*4";
TComplexEditor a;
a.addNumber(15);
a.addImPart();
a.addNumber(4);
ASSERT_TRUE(expected == a.getComplexString());
}

TEST  (TComplex_init,add_im_2) {
std::string expected = "-5+i*10";
TComplexEditor a;
a.addNumber(-5);
a.addImPart();
a.addNumber(10);
ASSERT_TRUE(expected == a.getComplexString());
}

TEST  (TComplex_init,add_im_3) {
TComplexEditor a;
a.addImPart();
ASSERT_THROW(a.addImPart(), std::logic_error);
}

TEST  (TComplex_init,edit) {
std::string expected = "-8";
TComplexEditor a;
a.addNumber(8);
a.editComplex(ComplexOperations::ADD_SIGN);
ASSERT_TRUE(expected == a.getComplexString());
}

TEST  (TComplex_init,edit_1){
std::string expected = "8";
TComplexEditor a;
a.addNumber(-8);
a.editComplex(ComplexOperations::ADD_SIGN);
ASSERT_TRUE(expected == a.getComplexString());
}

TEST  (TComplex_init,edit_2) {
std::string expected = "8+i*4";
TComplexEditor a;
a.addNumber(8);
a.editComplex(ComplexOperations::ADD_IMPART);
a.addNumber(4);
ASSERT_TRUE(expected == a.getComplexString());
}

TEST(TComplex_init,edit_3) {
std::string expected = "8+i*40";
TComplexEditor a;
a.addNumber(8);
a.editComplex(ComplexOperations::ADD_IMPART);
a.addNumber(4);
a.editComplex(ComplexOperations::ADD_ZERO);
ASSERT_TRUE(expected == a.getComplexString());
}

TEST(TComplex_init,edit_4){
std::string expected = "8-i*4";
TComplexEditor a;
a.addNumber(8);
a.editComplex(ComplexOperations::ADD_IMPART);
a.addNumber(4);
a.editComplex(ComplexOperations::ADD_SIGN);
ASSERT_TRUE(expected == a.getComplexString());
}

TEST(TComplex_init,complex_string){
std::string expected = "8+i*4";
TComplexEditor a;
a.setComplexString("8+i*4");
ASSERT_TRUE(expected == a.getComplexString());
}

TEST(TComplex_init,complex_string_1) {
std::string expected = "-8-i*4";
TComplexEditor a;
a.setComplexString("-8-i*4");
ASSERT_TRUE(expected == a.getComplexString());
}

TEST(TComplex_init,complex_string_2){
TComplexEditor a;
    ASSERT_THROW(a.setComplexString("i*4"), std::invalid_argument);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}