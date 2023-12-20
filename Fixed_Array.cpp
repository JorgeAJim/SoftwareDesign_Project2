// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include <iostream>

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void)
  :Array_Base<T>(N)
{
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr)
  :Array_Base<T>(N)
{
  for (size_t i = 0; i < arr.size(); i++) {
    this->data_[i] = arr[i];
  }
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
  :Array_Base<T>(N, fill)
{
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
  // Not allocating anything on the heap, so the parent deconstructor
  // can be used instead. 
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
  if (this == &rhs) {
    return *this;
  }

  for (size_t i = 0; i < N; i++) {
    this->data_[i] = rhs[i];
  }

  return *this;
}

//
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
  // Can't re-allocate fixed_array space for any reason.
  try {
    throw (M);
  }
  catch (size_t different_size) {
    // Make the user aware of the impossibility of thier request and return
    // the local fixed array without any alterations.
    std::cout << "Can't set a fixed array to an array of a different fixed size." << std::endl;
    return *this;
  }
}
