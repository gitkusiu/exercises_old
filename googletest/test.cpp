// tests.cpp
#include "whattotest.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::AtLeast; 

 class QueueTest : public ::testing::Test {
 protected:
//  virtual void SetUp() {
    QueueTest() {
    a0.f();
    a1.f();
    a2.f();
  }
  // virtual void TearDown() {}
  A a0;
  A a1;
  A a2;
};
    
 
TEST(SquareRootTest, PositiveNos) { 
    ASSERT_EQ(6, squareRoot(36.0));
    ASSERT_EQ(18.0, squareRoot(324.0));
    ASSERT_EQ(25.4, squareRoot(645.16));
    ASSERT_EQ(0, squareRoot(0.0));
}
 
TEST(SquareRootTest, NegativeNos) {
    ASSERT_EQ(-1.0, squareRoot(-15.0));
    ASSERT_EQ(-1.0, squareRoot(-0.2));
}
 
 
TEST_F(QueueTest, IsEmptyInitially) {
  EXPECT_EQ(true, a0.is());
}

TEST_F(QueueTest, IsClassEqual) {
  ASSERT_LT(a1,a2);
//  FAIL();
//  ADD_FAILURE();
//  ADD_FAILURE_AT("my.txt",123);
//  ASSERT_HRESULT_SUCCEEDED(false);
}



TEST(PainterTest, CanDrawSomething) {
  MockTurtle turtle;                          // #2
  EXPECT_CALL(turtle, PenDown())              // #3
//      .Times(AtLeast(1));
      .Times(1);
      
  Painter painter(&turtle);                   // #4

  EXPECT_TRUE(painter.DrawCircle(0, 0, 10));
}                                             // #5


int main(int argc, char **argv) {
 //   ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
