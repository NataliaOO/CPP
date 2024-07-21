#ifndef SRC_S21_CONTAINERS_STACK_H_
#define SRC_S21_CONTAINERS_STACK_H_

#include "s21_list.h"

namespace s21 {
template <class T, class Container = List<T>>
class Stack {
 public:
  using value_type = typename Container::value_type;
  using reference = typename Container::reference;
  using const_reference = typename Container::const_reference;
  using size_type = typename Container::size_type;

 protected:
  Container ListBased;

 public:
  Stack() : ListBased() {}
  Stack(std::initializer_list<value_type> const& items) : ListBased(items) {}
  Stack(const Stack& s) : ListBased(s.ListBased) {}
  Stack(Stack&& s) : ListBased(std::move(s.ListBased)) {}
  ~Stack() {}
  Stack& operator=(const Stack& s) {
    ListBased = s.ListBased;
    return *this;
  }
  Stack& operator=(Stack&& s) noexcept {
    ListBased = std::move(s.ListBased);
    return *this;
  }

  const_reference top() { return ListBased.back(); }

  bool empty() { return ListBased.empty(); }
  size_type size() { return ListBased.size(); }

  void push(const_reference value) { this->ListBased.push_back(value); }
  void pop() { this->ListBased.pop_back(); }
  void Swap(Stack& other) { this->ListBased.Swap(other.ListBased); }

  template <class... Args>
  decltype(auto) insert_many_front(Args&&... args) {
    ListBased.insert_many_back(std::forward<Args>(args)...);
  }
};
}  // namespace s21

#endif  // SRC_S21_CONTAINERS_STACK_H_
