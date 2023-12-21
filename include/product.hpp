#ifndef __SHOPPING_CART_CPP_PRODUCT_HPP__
#define __SHOPPING_CART_CPP_PRODUCT_HPP__

class Product
{
 public:
  Product(const double& length, const double& width, const double& height, const double& weight)
  {
    this->length_ = length;
    this->width_ = width;
    this->height_ = height;
    this->weight_ = weight;
  }

  inline double getLength() {return this->length_;}
  inline double getWidth() {return this->width_;}
  inline double getHeight() {return this->height_;}
  inline double getWeight() {return this->weight_;}
  inline double getSize() {return this->length_ * this->width_ * this->height_;}

 private:
  double length_, width_, height_, weight_;
};

#endif