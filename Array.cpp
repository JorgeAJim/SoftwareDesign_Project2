// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array(void)
{
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
  :Array_Base<T>(length)
{
}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
  :Array_Base<T>(length, fill)
{
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
  :Array_Base<T>(array.cur_size_)
{
  for (size_t i = 0; i < array.cur_size_; i++) {
    this->data_[i] = array.data_[i];
  }
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
  // Base destructor will be used when out of scope.
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
  // Check for self assignment.
  if (this == &rhs) {
    return *this;
  }

  // Use the operator = already defined in the base class.
  Array_Base<T>::operator=(rhs);

  return *this;

}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
  if (this->cur_size_ == new_size) {
    return;
  }

  if (new_size <= this->max_size_) {
    this->cur_size_ = new_size;
    return;
  }

  T* temp = new T[new_size];
  for (size_t i = 0; i < this->cur_size_; i++) {
    temp[i] = this->data_[i];
  }

  this->delete_data();
  this->data_ = temp;

  this->cur_size_ = new_size;
  this->max_size_ = new_size;

}

//
// shrink
// 
template <typename T>
void Array<T>::shrink(void)
{
  if (this->cur_size_ == this->max_size_) {
    return;
  }
  else {
    T* arr = new T[this->cur_size_];
    for (size_t i = 0; i < this->cur_size_; i++) {
      arr[i] = this->data_[i];
    }

    this->delete_data();
    this->data_ = arr;

    this->max_size_ = this->cur_size_;
  }
}

//
// slice
//
template <typename T>
Array<T> Array<T>::slice(size_t begin) const
{
  this->check_range_exception(begin);

  int temp_size_ = (this->cur_size_ - begin) - 1;

  Array<T> temp(temp_size_);

  int j = 0;
  for (size_t i = begin; i < (this->cur_size_ - 1); i++) {
    temp.data_[j] = this->data_[i];
    j++;
  }

  return temp;

}

//
// slice
//
template <typename T>
Array<T> Array<T>::slice(size_t begin, size_t end) const
{
  this->check_range_exception(begin);
  this->check_range_exception(end);

  int temp_size_ = (end - begin);

  Array<T> temp(temp_size_);

  int j = 0;
  for (size_t i = begin; i < end; i++) {
    temp.data_[j] = this->data_[i];
    j++;
  }

  return temp;
}
