#include <gtest/gtest.h>
#include "../Horo.h"

TEST(HoroTest, AddDancersInEmptyDanceFormation) {
  Horo H({"B","A","C"});

  EXPECT_EQ(H.getNumberOfDancers(),3);
  EXPECT_TRUE(H.isThereDancerWithName({"A","B","C"}));
  EXPECT_TRUE(H.areDancersAdjacent({"A","B","C"}));
}

TEST(HoroTest, AddDancerInNonEmptyDanceFormation) {
  Horo H({"A","B","D"});
  H.add("C","B","D");

  EXPECT_EQ(H.getNumberOfDancers(),4);
  EXPECT_TRUE(H.isThereDancerWithName("D"));
  EXPECT_TRUE(H.areDancersAdjacent({"B","C","D"}));
}

TEST(HoroTest, AddExistingDancer) {
  Horo H({"A","B","C"});

  EXPECT_THROW(H.add("A","B","C"), runtime_error);
  EXPECT_EQ(H.getNumberOfDancers(),3);
}

TEST(HoroTest, AddDancerBetweenNonAdjacentDancers) {
  Horo H({"A","B","C","D"});

  EXPECT_THROW(H.add("E","B","D"), runtime_error);
  EXPECT_EQ(H.getNumberOfDancers(),4);
}

TEST(HoroTest, RemoveDancer) {

}