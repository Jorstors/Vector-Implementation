#pragma once
#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <string>
#include <cstring>
using std::string;

template <typename TYPE>
class Vector
{
private:
  TYPE *container = nullptr;
  size_t elements = 0;
  size_t max_size = 0;

  // Functional class for iterators...
  struct iterator
  {
    // Adding required typedefs for std::iterator_traits
    using difference_type = std::ptrdiff_t;                    // Used for pointer arithmetic
    using value_type = TYPE;                                   // The type of value stored in the vector
    using pointer = TYPE *;                                    // Pointer to the value type
    using reference = TYPE &;                                  // Reference to the value type
    using iterator_category = std::random_access_iterator_tag; // Iterator category

    mutable TYPE *ptr;
    iterator() : ptr(nullptr) {}                  // default
    explicit iterator(TYPE *ptr) : ptr(ptr) {}    // construct from pointer
    iterator(const iterator &it) : ptr(it.ptr) {} // copy from iterator

    // Iterator functions...
    iterator &operator++() // ++
    {
      ptr++;
      return *this;
    }
    iterator operator++(int) // ++
    {
      iterator temp = *this;
      ptr++;
      return temp; // *this
    }
    iterator &operator--() // --
    {
      ptr--;
      return *this;
    }
    iterator operator--(int) // --
    {
      iterator temp = *this;
      ptr--;
      return temp; // *this
    }
    iterator operator+(const size_t &distance) const // + (integer)
    {
      if (distance == 0)
        return *this;
      return iterator(ptr + distance);
    }
    iterator operator-(const size_t &distance) const // - (integer)
    {
      if (distance == 0)
        return *this;
      return iterator(ptr - distance);
    }
    difference_type operator-(const iterator &other) const { return ptr - other.ptr; } // - (iterator)
    TYPE &operator*() { return *ptr; }                                                 // *
    const TYPE &operator*() const { return *ptr; }                                     // * (const)
    bool operator>(const iterator &other) const { return ptr > other.ptr; }            // >
    bool operator<(const iterator &other) const { return ptr < other.ptr; }            // <
    bool operator==(std::nullptr_t) const { return ptr == nullptr; }                   // ==
    bool operator==(const iterator &other) const { return ptr == other.ptr; }          // ==
    bool operator!=(const iterator &other) const { return ptr != other.ptr; }          // !=
    iterator &operator=(const iterator &other)
    {
      if (this != &other)
      { // Check for self-assignment
        this->ptr = other.ptr;
      }
      return *this;
    }
  };
  // general iterators
  iterator current_it;  // points to the last element
  iterator begin_it;    // points to the first element
  iterator end_it;      // points one past the last element
  iterator max_size_it; // points one past max size

  // Helper functions...

  // copy function: copies from one iterator to another
  void copy(const iterator &from, const iterator &to, const iterator &output) const
  {
    std::copy(from.ptr, to.ptr, output.ptr);
  }
  // resize function: allocates new space, copies data
  void resizeContainer(const size_t &size, bool shrink = false)
  {
    elements = size;
    max_size = shrink ? size : size + size / 2;
    TYPE *newContainer = new TYPE[max_size]; // reallocates new container size + buffer

    if (container != nullptr)
    {
      end_it = begin_it + size; // setting end iterator to the new size
      copy(begin_it, end_it, iterator(newContainer));
      delete[] container;
      container = nullptr;
    }

    // updating container, data, pointers
    container = newContainer;

    begin_it = iterator(container);                  // points to the first element
    end_it = iterator(container + elements);         // points one past the last element
    current_it = iterator(container + elements - 1); // points to the last element
    max_size_it = iterator(container + max_size);    // points one past max size
  }
  // distance function: calculates the distance between two iterators
  size_t distance(const iterator &start, const iterator &end) const
  {
    size_t distance = 0;
    for (iterator it = start; it != end; it++)
      distance++;
    return distance;
  }

public:
  // CONSTRUCTORS
  // default constructor
  Vector() {};
  // sized constructor
  Vector(const size_t &size) { resizeContainer(size); }
  // sized + fill constructor
  Vector(const size_t &size, TYPE fill)
  {
    resizeContainer(size);
    std::fill(begin_it, end_it, fill);
  }
  // initialized list constructor
  Vector(std::initializer_list<TYPE> initList)
  {
    resizeContainer(initList.size());
    std::copy(initList.begin(), initList.end(), begin_it);
  }

  // copy constructor
  Vector(const Vector<TYPE> &source)
  {
    resizeContainer(source.size());
    copy(source.begin(), source.end(), begin_it);
  }
  // DESTRUCTOR
  ~Vector() { delete[] container; }

  // CREATION

  //  push function: adds an element to the end
  void push_back(const TYPE &value)
  {
    if (end_it == max_size_it)
    {
      resizeContainer(max_size);
      *end_it = value; // add new element
    }
    else
    {
      *end_it = value;
      current_it++;
      end_it++;
      elements++;
    }
  }

  // resize function: allocates new space, copies data
  void resize(const size_t &value) { resizeContainer(value); }
  // reserve function: allocates new space
  void reserve(const size_t &value) { resizeContainer((value * 2) / 3); }

  // ERASURE

  // pop function: removes the last element
  void pop_back()
  {
    if (current_it == begin_it)
      return;
    current_it--;
    end_it--;
    elements--;
  }

  // shrink_to_fit function: shrinks the container to fit the current size
  void shrink_to_fit()
  {
    if (elements <= 1)
      return;
    resizeContainer(elements, true);
  }

  // erase function (iterator): removes elements in a range
  void erase(const iterator &from = nullptr, const iterator &to = nullptr)
  {
    if (from == nullptr && to == nullptr)
    {
      resizeContainer((size_t)(0));
      return;
    }

    size_t iFrom = std::distance(begin_it, from);      // get the index of the first element to erase
    size_t iTo = std::distance(begin_it, to);          // get the index of the last element to erase
    size_t iCurrent = std::distance(begin_it, end_it); // get the index of the last element

    size_t k = iFrom;                        // initialize a counter to keep track of the elements to copy
    for (size_t i = iTo; i <= iCurrent; i++) // loop through the elements from the last one to erase to the last one
      container[i] = container[k++];         // copy the element at index k to the current index and increment k

    resizeContainer(elements - (iTo - iFrom));
  }

  // TRAVERSAL/TOOLS
  // returns the current size of the vector
  size_t size() const { return distance(begin_it, end_it); }

  // returns the capacity of the vector
  size_t capacity() const { return max_size; }

  // returns the first element of the vector
  TYPE front() const
  {
    if (empty())
      throw std::out_of_range("Vector is empty");
    return *begin_it;
  }

  // returns the last element of the vector
  TYPE back() const
  {
    if (empty())
      throw std::out_of_range("Vector is empty");
    return *(end_it - (size_t)(1));
  }

  // returns a pointer to the first element of the vector
  iterator begin() const { return begin_it; }

  // returns a pointer to the last element of the vector
  iterator end() const { return end_it; }

  // returns the element at the given index
  TYPE at(size_t const &i) const
  {
    if (i >= elements || i < 0)
      throw std::out_of_range("Index out of range");
    else
      return container[i];
  }

  // returns the element at the given index
  TYPE operator[](size_t const &i) const { return container[i]; }

  // BOOL OPERATIONS
  // checks if the vector is empty
  bool empty(void) const { return (elements == 0) ? true : false; }
};
