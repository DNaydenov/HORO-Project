#include <gtest/gtest.h>
#include "../Horo.h"

TEST(HoroTest, AddDancersInEmptyDanceFormation) {
  Horo H({"B","A","C"});

  EXPECT_EQ(H.getNumberOfDancers(),3);
  EXPECT_TRUE(H.isExistDancerWithName({"A","B","C"}));
  EXPECT_TRUE(H.areDancersAdjacent({"A","B","C"}));
}

TEST(HoroTest, AddDancerInNonEmptyDanceFormation) {
  Horo H({"A","B","D"});
  H.add("C","B","D");

  EXPECT_EQ(H.getNumberOfDancers(),4);
  EXPECT_TRUE(H.isExistDancerWithName("D"));
  EXPECT_TRUE(H.areDancersAdjacent({"B","C","D"}));
}

TEST(HoroTest, AddExistingDancer) {
  Horo H({"A","B","C"});

  EXPECT_THROW(H.add("A","B","C"), runtime_error);
  EXPECT_EQ(H.getNumberOfDancers(),3);
}

TEST(HoroTest, AddDancerBetweenNonAdjacentDancers) {
  Horo H({"A","B","C"});
  H.add("D","C","A");

  EXPECT_THROW(H.add("E","B","D"), runtime_error);
  EXPECT_EQ(H.getNumberOfDancers(),4);
}

TEST(HoroTest, RemoveNonLinkedDancer) {

}

TEST(HoroTest, RemoveLinkedDancer) {

}

TEST(HoroTest, RemoveDancerFromDanceWithOnlyThreeDancers) {

}

TEST(HoroTest, SwapTwoNonLinkedDancers) {
  Horo H({"B","A","C"});
  H.release("A",'b');
  H.release("B",'b');
  H.release("C",'b');
  H.swap("A","C");

  EXPECT_EQ(H.getNumberOfDancers(),3);
  EXPECT_TRUE(H.isExistDancerWithName({"A","B","C"}));
  EXPECT_TRUE(H.areDancersAdjacent({"A","B","C"}));
}

TEST(HoroTest, SwapTwoLinkedDancers) {
  Horo H({"B","A","C"});

  EXPECT_THROW(H.swap("A","C"), runtime_error);
  EXPECT_EQ(H.getNumberOfDancers(),3);
}

TEST(HoroTest, SwapTwoNonAdjacentDancers) {
  Horo H({"B","A","C"});
  H.add("D","A","C");

  H.release("A",'b');
  H.release("B",'b');
  H.release("C",'b');
  H.release("D",'b');

  EXPECT_THROW(H.swap("B","D"), runtime_error);
  EXPECT_EQ(H.getNumberOfDancers(),4);
}
