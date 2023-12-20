#ifndef _CS507_QUEUE_H_
#define _CS507_QUEUE_H_

#include <exception>

/**
 * @class Queue
 *
 * Basic queue for abitrary elements. It contains
 * a dynamic array to hold the elements of queue.
 *
 */
template <typename T>
class Queue
{
public:
  /// Type definition of the type;
  typedef T type;

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the queue is empty.
   */
  class empty_exception : public std::exception
  {
    public:
      /// Default constructor.
      empty_exception(void)
	: std::exception () { }

      /**
       * Initializing constructor.
       * 
       * @param[in]    msg       Error message.
       */
	empty_exception (const char * msg)
	  : std::exception (msg) { }
  };

  /// Default constructor.
  Queue (void);

  /// Copy constructor.
  Queue (const Queue & q);

  /// Destructor.
  ~Queue (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Queue & operator = (const Queue & rhs);

  /**
   * Add a new \a element to the queue. The element is inserted
   * after all the other elements in the queue.
   */
  void enqueue( T element);

  /**
   * Remove and return the first element in the queue.
   *
   * @exception      empty_exception    The queue is empty.
   */
  T dequeue (void);

  /**
   * Test if the queue is empty.
   *
   * @retval         true          The queue is empty
   * @retval         false         The queue is not empty
   */
  bool is_empty (void) const;

  /**
   * Number of element on the queue.
   *
   * @return         Size of the queue.
   */
  size_t size (void) const;

  /// Remove all elements from the queue.
  void clear (void);

private:
  // Use an array to represent the queue.
  Array<T> arr_;

  // Have a variable represent the size of the queue.
  size_t queue_size_;
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"

#endif // !define _CS507_QUEUE_H_
