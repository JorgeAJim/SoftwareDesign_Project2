//
// size
//
template <typename T>
inline
size_t Queue <T>::size (void) const
{
  return queue_size_;
}

//
// is_empty
//
template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
  if(arr_.size() == 0) {
    return true;
  }

  return false;
}
