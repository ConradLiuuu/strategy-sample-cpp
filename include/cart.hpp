#ifndef __SHOPPING_CART_CPP_CART_HPP__
#define __SHOPPING_CART_CPP_CART_HPP__

#include <stdexcept>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <functional>

#include "product.hpp"

using std::invalid_argument;
using std::string;
using std::min;
using std::unordered_map;
using std::function;

using MyFunctionType = function<double(Product)>;

class Cart
{
 public:
  unordered_map<string, MyFunctionType> shippingFeeFuncs()
  {
    unordered_map<string, MyFunctionType> my_dict;

    my_dict["black cat"] = calculateFeeByBlackCat;
    my_dict["hsinchu"] = calculateFeeByHsinchu;
    my_dict["post office"] = calculateFeeByPostOffice;

    return my_dict;
  }

  double shippingFee(const string& shipper, Product product)
  {
    auto dict = this->shippingFeeFuncs();
    auto it = dict.find(shipper);

    if (it != dict.end())
    {
      return it->second(product);
    }
    else
    {
      throw invalid_argument("shipper not exist");
    }
  }
  
 private:
  static double calculateFeeByBlackCat(Product product)
  {
    if (product.getWeight() > 20)
    {
      return 500;
    }
    else
    {
      return 100 + product.getWeight() * 10;
    }
  }

  static double calculateFeeByHsinchu(Product product)
  {
    if ((product.getLength() > 100) || (product.getWidth() > 100) || (product.getHeight() > 100))
    {
      return product.getSize() * 0.00002 * 1100 + 500;
    }
    else
    {
      return product.getSize() * 0.00002 * 1200;
    }
  }

  static double calculateFeeByPostOffice(Product product)
  {
    double fee_by_weight = 80 + product.getWeight() * 10;
    double fee_by_size = product.getSize() * 0.00002 * 1100;

    return min(fee_by_weight, fee_by_size);
  }
};

#endif