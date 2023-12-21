#include <stdexcept>
#include <string>

using std::invalid_argument;
using std::string;

class Cart
{
 public:
  double shippingFee(const string& shipper, const double& length, const double& width, const double& height, const double& weight)
  {
    if (shipper == "black cat")
    {
      if (weight > 20)
      {
        return 500;
      }
      else
      {
        return 100 + weight * 10;
      }
    }
    else if (shipper == "hsinchu")
    {
      double size = length * width * height;

      if ((length > 100) || (width > 100) || (height > 100))
      {
        return size * 0.00002 * 1100 + 500;
      }
      else
      {
        return size * 0.00002 * 1200;
      }
    }
    else if (shipper == "post office")
    {
      double fee_by_weight = 80 + weight * 10;
      double size = length * width * height;
      double fee_by_size = size * 0.00002 * 1100;

      return fee_by_weight < fee_by_size ? fee_by_weight : fee_by_size;
    }
    else
    {
      throw invalid_argument("shipper not exist.");
    }
  }
};