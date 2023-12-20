// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
  return stack_size_;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
  if(is_empty() == false) {
    return this->arr_[this->stack_size_ - 1]; 
  }
  else {
    return 0;
  }
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
  if (arr_.size() == 0) {
    return true;
  }

  return false;
}
