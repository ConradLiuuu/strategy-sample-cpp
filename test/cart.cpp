#include "cart.hpp"
#include "gtest/gtest.h"

class CartTest : public testing::Test
{
 protected:
  Cart cart_;

  string black_cat_ = "black cat";
  string hsinchu_ = "hsinchu";
  string post_office_ = "post office";

  void feeShouldBe(const double& expected, const double& shipping_fee)
  {
    ASSERT_DOUBLE_EQ(expected, shipping_fee);
  }
};

// Test for black cat
TEST_F(CartTest, black_cat_with_light_weight)
{
  double shipping_fee = this->cart_.shippingFee(this->black_cat_, Product(30, 20, 10, 5));
  
  this->feeShouldBe(150, shipping_fee);
}

TEST_F(CartTest, black_cat_with_heavy_weight)
{
  double shipping_fee = this->cart_.shippingFee(this->black_cat_, Product(30, 20, 10, 50));
  
  this->feeShouldBe(500, shipping_fee);
}

// Test for hsinchu
TEST_F(CartTest, hsinchu_with_small_size)
{
  double shipping_fee = this->cart_.shippingFee(this->hsinchu_, Product(30, 20, 10, 50));
  
  this->feeShouldBe(144, shipping_fee);
}

TEST_F(CartTest, hsinchu_with_huge_size)
{
  double shipping_fee = this->cart_.shippingFee(this->hsinchu_, Product(100, 20, 10, 50));
  
  this->feeShouldBe(480, shipping_fee);
}

// Test for post office
TEST_F(CartTest, post_office_by_weight)
{
  double shipping_fee = this->cart_.shippingFee(this->post_office_, Product(100, 20, 10, 3));
  
  this->feeShouldBe(110, shipping_fee);
}

TEST_F(CartTest, post_office_by_size)
{
  double shipping_fee = this->cart_.shippingFee(this->post_office_, Product(100, 20, 10, 300));
  
  this->feeShouldBe(440, shipping_fee);
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}