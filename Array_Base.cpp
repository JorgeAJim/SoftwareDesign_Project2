#include "Array_Base.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array_Base <T>::Array_Base (void)
  :data_(nullptr),
  cur_size_ (0),
  max_size_ (0)
{
}

//
// Array (size_t)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length)
  :data_ (nullptr),
  cur_size_ (length),
  max_size_ (length)
{
  // Make sure that length is greater than zero.
  if (length == 0) {
    // Leave the data_ set to nullptr.
  }
  else {
    this->data_ = new T[length];
  }
}

template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill)
  :Array_Base<T>(length)
{
  // Abstract by using the fill method.
  this->fill(fill);
}

//
// Array (const Array &)
//
template <typename T>
Array_Base <T>::Array_Base (const Array_Base & array)
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
Array_Base <T>::~Array_Base (void)
{
  this->delete_data();
}

//
// operator =
//
template <typename T>
const Array_Base <T> & Array_Base <T>::operator = (const Array_Base<T> & rhs)
{
  // Check for self assignment.
  if (this == &rhs) {
    return *this;
  }

  // Check if there is enough room in the local array to fit all the elements from the 
  // rhs object.
  if (this->cur_size_ == rhs.cur_size_) {
    for (size_t i = 0; i < rhs.cur_size_; i++) {
      this->data_[i] = rhs.data_[i];
    }

    this->max_size_ = rhs.max_size_;

    return *this;
  }

  // If nither of the two edge cases occur, then re-allocate the array.
  this->delete_data();

  this->data_ = new T[rhs.cur_size_];
  this->cur_size_ = rhs.cur_size_;
  this->max_size_ = rhs.max_size_;

  for (size_t i = 0; i < rhs.cur_size_; i++) {
    this->data_[i] = rhs.data_[i];
  }

  return *this;

}

//
// operator []
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
  this->check_range_exception(index);

  return this->data_[index];
}

//
// operator [] 
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
  this->check_range_exception(index);

  return this->data_[index];
}

//
// get
//
template <typename T>
T Array_Base <T>::get (size_t index) const
{
  this->check_range_exception(index);

  return this->data_[index];
}

//
// set
//
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
  this->check_range_exception(index);

  this->data_[index] = value;
}

//
// find (char)
//
template  <typename T>
int Array_Base <T>::find (T value) const
{
  for (size_t i = 0; i < this->cur_size_; i++) {
    if (this->data_[i] == value) {
      return i;
    }
  }

  return -1;
}

//
// find (char, size_t) 
//
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
  this->check_range_exception(start);

  for (size_t i = start; i < this->cur_size_; i++) {
    if (this->data_[i] == val) {
      return i;
    }
  }

  return -1;
}

//
// operator ==
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base<T> & rhs) const
{
  if (this == &rhs) {
    return true;
  }

  if (this->cur_size_ == rhs.cur_size_) {
    for (size_t i = 0; i < this->cur_size_; i++) {
      if (this->data_[i] != rhs.data_[i]) {
        return false;
      }
    }

    return true;
  }
  else {
    return false;
  }
}

//
// operator !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base<T> & rhs) const
{
  return !(*this == rhs);
}

//
// fill
//
template <typename T>
void Array_Base <T>::fill (T value)
{
  for (size_t i = 0; i < this->cur_size_; i++) {
    this->data_[i] = value;
  }
}

//
// reverse
//
template <typename T>
void Array_Base <T>::reverse(void)
{
  if (this->cur_size_ <= 1) {
    return;
  }

  int j = 0;
  int half = int(this->cur_size_) / 2;

  for (int i = int(this->cur_size_ - 1); i >= half; i--) {
    T temp = this->data_[i];
    this->data_[i] = this->data_[j];
    this->data_[j] = temp;
    j++;
  }
}

//
// delete_data
//
template <typename T>
void Array_Base <T>::delete_data () 
{
  // Make sure that the delete doesn't run if the data_ variable
  // is already pointing to nullptr.
  if (this->data_ != nullptr) {
    delete[] data_;
    // Reset data to nullptr for when the stack class calls is_empty().
    this->data_ = nullptr;
  }
}

//
// check_range_exception
//
template <typename T>
void Array_Base <T>::check_range_exception (size_t index) const 
{
  if (index >= cur_size_) {
    throw std::out_of_range("Invalid index");
  }
}
