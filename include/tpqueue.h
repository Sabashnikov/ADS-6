// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
#include <string>

template<typename T, int size>	template<typename T, int size>
class TPQueue {	class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере	 private:
  T* data;
  int begin, end, count;

 public:
  TPQueue(): begin(0), end(0), count(0), data(new T[size]) {}
  void push(const T& item) {
    if (count >= size) {
      throw std::string("Empty");
    } else {
      count++;
      int pos = end, i = begin;
      while (i < end) {
        if (data[i].prior < item.prior) {
          pos = i;
          break;
        }
        i++;
      }
      for (int i = end; i > pos; i--)
        data[i % size] = data[(i - 1) % size];
      data[pos % size] = item;
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

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
