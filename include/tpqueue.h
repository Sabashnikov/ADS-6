// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
#include <string>

template<typename T, int size>
class TPQueue {
 private:
  T data[size];
  int begin, end, count;

 public:
  TPQueue(): begin(0), end(0), count(0) {}
  void push(const T& item) {
    if (count >= size) {
      throw std::string("Empty");
    } else if (isEmpty()) {
      data[(end) % size] = item;
      begin = end;
      count++;
    } else {
      int pos = end;
      data[pos + 1] = item;
      for (int i = pos + 1; i < count; i++) {
        if (data[pos].prior < data[pos + 1].prior) {
          T temp = data[pos];
          data[pos] = data[pos + 1];
          data[pos + 1] = temp;
        }
        pos--;
      }
      count++;
      end++;
    }
  }
  T pop() {
    if (count == 0) {
      throw std::string("Empty!");
    } else {
      count--;
      return data[(begin++) % size];
    }
  }
  bool isEmpty()const {
    return count == 0;
  }
  T getFront()const {
    if (count == 0)
      throw std::string("No front");
    else
      return data[begin % size];
  }
  T getBack()const {
    if (count == 0)
      throw std::string("No back");
    else
      return data[end % size];
  }
  int getSize()const {
    return count;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
