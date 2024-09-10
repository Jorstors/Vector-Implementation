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
    TYPE *ptr;
    iterator() : ptr(nullptr) {}                  // default
    iterator(TYPE *ptr) : ptr(ptr) {}             // construct from pointer
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
    iterator operator+(const size_t distance) { return ptr + distance; }
    iterator operator-(const size_t distance) { return ptr - distance; }
    TYPE &operator*() { return *ptr; }                                  // *
    bool operator==(const iterator &other) { return ptr == other.ptr; } // ==
    bool operator!=(const iterator &other) { return ptr != other.ptr; } // !=
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
  iterator current_it;
  iterator begin_it;
  iterator end_it;
  iterator max_size_it;

  // Helper functions...

  // copy function: copies from one iterator to another
  void copy(const iterator &from, const iterator &to, const iterator &output) const
  {
    std::copy(from.ptr, to.ptr, output.ptr);
  }
  // resize function: allocates new space, copies data
  void resizeContainer(const size_t &size)
  {
    elements = size;
    max_size = size + size / 2;
    TYPE *newContainer = new TYPE[max_size]; // reallocates new container size + buffer

    if (container != nullptr)
    {
      copy(begin_it, end_it, iterator(newContainer));
      delete[] container;
    }

    // updating container, data, pointers
    container = newContainer;

    begin_it = iterator(container);               // points to the first element
    end_it = iterator(container + elements);      // points one past the last element
    current_it = iterator(container + elements);  // initially set current to the end
    max_size_it = iterator(container + max_size); // points one past max size
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
      resizeContainer(max_size);
    *(current_it.ptr + 1) = value; // add new element
    current_it++;
    end_it++;
    elements++;
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
    delete *(current_it);
  }

  // shrink_to_fit function: shrinks the container to fit the current size
  void shrink_to_fit()
  {
    if (elements <= 1)
      return;
    resizeContainer((elements * 2) / 3 + 1);
  }

  // erase function (iterator): removes elements in a range
  void erase(const iterator &from, const iterator &to = nullptr)
  {
    size_t iFrom = std::distance(begin_it, from);
    size_t iTo = std::distance(begin_it, to);
    size_t iCurrent = std::distance(begin_it, current_it);

    size_t k = iFrom;
    for (size_t i = iTo; i <= iCurrent; i++)
      container[i] = container[k++];
  }

  // erase function (index): removes elements in a range
  void erase(const size_t &from, const size_t &to = -1)
  {
    size_t iCurrent = std::distance(begin(), current_it);

    size_t k = from;
    for (size_t i = to; i <= iCurrent; i++)
      container[i] = container[k++];
  }

  // TRAVERSAL/TOOLS
  size_t size() const { return distance(begin_it, end_it); }

  size_t capacity() const { return max_size; }

  TYPE front() const { return *(begin_it.ptr); }

  TYPE back() const { return *(end_it.ptr - 1); }

  iterator begin() const { return begin_it; }

  iterator end() const { return end_it; }

  TYPE at(size_t const &i) const { return container[i]; }

  TYPE operator[](size_t const &i) const { return container[i]; }

  // BOOL OPERATIONS
  bool empty(void) { return (elements == 0) ? true : false; }
};

int main()
{
  // BATCH TESTING WITH DIFFERENT TYPES... (manual testing)

  Vector<int> copyMe = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Vector<int> v = copyMe;
  // Vector<float> v = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
  // Vector<char> v = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
  // Vector<double> v = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
  // Vector<bool> v = {true, false, true, false, true, false, true, false, true, false};
  // Vector<string> v = {"start", "2", "3", "4", "5", "6", "7", "8", "9", "end"};

  //  Printing the vector
  std::cout << "front: " << v.front() << "\nback: " << v.back() << "\nsize: " << v.size() << "\ncapacity: " << v.capacity() << std::endl;

  // Thanks to our member iterator, we can iterate through the vector
  for (const auto &i : v)
    std::cout << i << ", ";

  return 0;
}