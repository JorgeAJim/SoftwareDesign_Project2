// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
// COMMENT There is no need to explicitly call the default constructor of
// an object contained in a class. This is actually calling the copy constructor
// using a temp-const object.

// REPLY: I removed the un-needed call to the default constructor for arr_.
  :stack_size_ (0)
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
// COMMENT You are using the copy constructor to initialize the array. There
// is no need to explicitly call a constuctor if you are going to use the
// default constructor to initilize the member variable/.

// REPLY: I removed the un-needed use of the default constructor to initialize the array
  :stack_size_ (stack.stack_size_)
{
  this->arr_ = stack.arr_;
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
  // The arr_ will fall out of scope and be automatically deconstructed.
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
  // Increase the size of the stack by one, and then update the size
  // of the arr_ instance.
  this->stack_size_++;
  this->arr_.resize(this->stack_size_);
  this->arr_[int(this->stack_size_) - 1] = element;

}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
  if (this->stack_size_ == 0) {
    throw empty_exception();
  }
  
  this->stack_size_ -= 1;
  this->arr_.resize(this->stack_size_);
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
  if (this == &rhs) {
    return *this;
  }

  clear();
  this->arr_.resize(rhs.stack_size_);
  this->stack_size_ = rhs.stack_size_;
  
  //Refill the stack from the bottom up.
  for (int i = int(this->stack_size_ - 1); i >= 0; i--) {
    this->arr_[i] = rhs.arr_[i];
  }

  return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
  this->arr_.resize(0);
  this->stack_size_ = 0;
}
