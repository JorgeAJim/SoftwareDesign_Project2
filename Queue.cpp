//
// Queue
//
template <typename T>
Queue <T>::Queue (void)
  :queue_size_ (0)
{
}

//
// Queue
//
template <typename T>
Queue <T>::Queue (const Queue & queue)
  :queue_size_ (queue.queue_size_)
{
  this->arr_ = queue.arr_;
}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void)
{
  //The arr_ will fall out of scope and be automatically deconstructed.
}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue (T element)
{
  this->queue_size_++;
  this->arr_.resize(queue_size_);
  this->arr_[queue_size_ - 1] = element;
}

//
// dequeue
//
template <typename T>
T Queue <T>::dequeue (void)
{
  if(is_empty() == true) {
    throw empty_exception();
  }
  
  // Store the first element of the queue to return at
  // the end of the array. 
  T first_element = this->arr_[0];

  // Remove the first element of the queue.
  Array<T> temp(queue_size_ - 1);
  for(size_t i = 1; i < this->queue_size_; i++) {
    temp[i - 1] = arr_[i];
  }

  this->queue_size_ -= 1;
  this->arr_ = temp;

  return first_element;
}

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
  if (this == &rhs) {
    return *this;
  }
  
  // If local size is the same as rhs size, no need for re-allocation
  if(this->queue_size_ == rhs.queue_size_) {
    this->arr_ = rhs.arr_;
    return *this;
  }


  clear();
  this->arr_.resize(rhs.queue_size_);
  this->queue_size_ = rhs.queue_size_;

  // Use array operator = overloading after the local array has been reset.
  this->arr_ = rhs.arr_;

  return *this;
}

//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{
  this->arr_.resize(0);
  this->queue_size_ = 0;
}
