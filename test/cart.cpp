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
  double shipping_fee = this->cart_.shippingFee(this->black_cat_, 30, 20, 10, 5);
  
  this->feeShouldBe(shipping_fee, 150);
}

TEST_F(CartTest, black_cat_with_heavy_weight)
{
  double shipping_fee = this->cart_.shippingFee(this->black_cat_, 30, 20, 10, 50);
  
  this->feeShouldBe(shipping_fee, 500);
}

// Test for hsinchu
TEST_F(CartTest, hsinchu_with_small_size)
{
  double shipping_fee = this->cart_.shippingFee(this->hsinchu_, 30, 20, 10, 50);
  
  this->feeShouldBe(shipping_fee, 144);
}

TEST_F(CartTest, hsinchu_with_huge_size)
{
  double shipping_fee = this->cart_.shippingFee(this->hsinchu_, 100, 20, 10, 50);
  
  this->feeShouldBe(shipping_fee, 480);
}

// Test for post office
TEST_F(CartTest, post_office_by_weight)
{
  double shipping_fee = this->cart_.shippingFee(this->post_office_, 100, 20, 10, 3);
  
  this->feeShouldBe(shipping_fee, 110);
}

TEST_F(CartTest, post_office_by_size)
{
  double shipping_fee = this->cart_.shippingFee(this->post_office_, 100, 20, 10, 300);
  
  this->feeShouldBe(shipping_fee, 440);
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}