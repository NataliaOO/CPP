#include "s21_main.h"

TEST(Suite_Queue, Default_Constructor) {
  queue<int> std_queue;
  Queue<int> s21_queue;
  EXPECT_EQ(std_queue.empty(), s21_queue.empty());
  EXPECT_EQ(std_queue.size(), s21_queue.size());
}
TEST(Suite_Queue, Initializer_ListConstructor) {
  Queue<unsigned int> my_queue1{1, 2, 3};
  ASSERT_EQ(my_queue1.size(), 3u);
  ASSERT_EQ(my_queue1.front(), 1u);
  ASSERT_EQ(my_queue1.back(), 3u);
  Queue<string> my_queue2{"hello", "world"};
  ASSERT_EQ(my_queue2.size(), 2u);
  ASSERT_EQ(my_queue2.front(), "hello");
  ASSERT_EQ(my_queue2.back(), "world");
}
TEST(Suite_Queue, InitializerList_Constructor_Pair) {
  Queue<pair<string, int>> my_queue1{{"one", 1}, {"two", 2}, {"three", 3}};
  queue<pair<string, int>> my_queue2;
  my_queue2.push({"one", 1});
  my_queue2.push({"two", 2});
  my_queue2.push({"three", 3});
  EXPECT_EQ(my_queue1.empty(), my_queue2.empty());
  EXPECT_EQ(my_queue1.size(), my_queue2.size());
  while (!my_queue2.empty()) {
    EXPECT_EQ(my_queue1.front().first, my_queue2.front().first);
    EXPECT_EQ(my_queue1.front().second, my_queue2.front().second);
    my_queue1.pop();
    my_queue2.pop();
  }
}

TEST(Suite_Queue, Empty_Initializer_ListConstructor) {
  Queue<unsigned int> q{};
  ASSERT_EQ(q.size(), 0);
  ASSERT_TRUE(q.empty());
}

TEST(Suite_Queue, Copy_InitializerList_Constructor) {
  Queue<unsigned int> my_queue1{1, 2, 3};
  Queue<unsigned int> my_queue2{my_queue1};
  ASSERT_EQ(my_queue1.size(), my_queue2.size());
  ASSERT_EQ(my_queue1.front(), my_queue2.front());
  ASSERT_EQ(my_queue1.back(), my_queue2.back());
}

TEST(Suite_Queue, Move_InitializerList_Constructor) {
  Queue<unsigned int> my_queue1{1, 2, 3};
  Queue<unsigned int> my_queue2{move(my_queue1)};
  ASSERT_EQ(my_queue1.size(), 0u);
  ASSERT_EQ(my_queue2.size(), 3u);
  ASSERT_EQ(my_queue2.front(), 1u);
  ASSERT_EQ(my_queue2.back(), 3u);
}
TEST(Suite_Queue, insert_many_back) {
  Queue<int> my_queue;
  my_queue.insert_many_back(10);
  my_queue.insert_many_back(20);
  my_queue.insert_many_back(30);

  ASSERT_EQ(my_queue.front(), 10);
  my_queue.pop();
  ASSERT_EQ(my_queue.front(), 20);
  my_queue.pop();
  ASSERT_EQ(my_queue.front(), 30);
}
TEST(Suite_Queue, Push_Pop_Front_Back) {
  queue<int> std_queue;
  Queue<int> s21_queue;
  for (int i = 1; i <= 10; ++i) {
    std_queue.push(i);
    s21_queue.push(i);
  }
  while (!std_queue.empty()) {
    EXPECT_EQ(std_queue.front(), s21_queue.front());
    EXPECT_EQ(std_queue.back(), s21_queue.back());
    std_queue.pop();
    s21_queue.pop();
  }
}

TEST(Suite_Queue, Front_Back_Pair) {
  Queue<pair<string, int>> q{{"one", 1}, {"two", 2}, {"three", 3}};
  queue<pair<string, int>> my_queue2;
  my_queue2.push({"one", 1});
  my_queue2.push({"two", 2});
  my_queue2.push({"three", 3});
  EXPECT_EQ(q.front().first, my_queue2.front().first);
  EXPECT_EQ(q.front().second, my_queue2.front().second);
  EXPECT_EQ(q.back().first, my_queue2.back().first);
  EXPECT_EQ(q.back().second, my_queue2.back().second);
}

TEST(Suite_Queue, Push_Pop_Pair) {
  Queue<pair<string, int>> q;
  queue<pair<string, int>> my_queue2;
  q.push({"one", 1});
  my_queue2.push({"one", 1});
  q.push({"two", 2});
  my_queue2.push({"two", 2});
  q.push({"three", 3});
  my_queue2.push({"three", 3});
  EXPECT_EQ(q.empty(), my_queue2.empty());
  EXPECT_EQ(q.size(), my_queue2.size());
  while (!my_queue2.empty()) {  // fake node -> never empty
    EXPECT_EQ(q.front().first, my_queue2.front().first);
    EXPECT_EQ(q.front().second, my_queue2.front().second);
    q.pop();
    my_queue2.pop();
  }
}

TEST(Suite_Queue, Copy_Constructor) {
  queue<int> std_queue;
  Queue<int> s21_queue;
  for (int i = 1; i <= 10; ++i) {
    std_queue.push(i);
    s21_queue.push(i);
  }
  queue<int> std_copy(std_queue);
  Queue<int> s21_copy(s21_queue);
  EXPECT_EQ(std_copy.size(), s21_copy.size());
  while (!std_copy.empty()) {
    EXPECT_EQ(std_copy.front(), s21_copy.front());
    std_copy.pop();
    s21_copy.pop();
  }
  EXPECT_EQ(std_queue.size(), s21_queue.size());
}

TEST(Suite_Queue, Copy_Constructor_Pair) {
  Queue<pair<string, int>> my_queue1{{"one", 1}, {"two", 2}, {"three", 3}};
  Queue<pair<string, int>> my_queue2(my_queue1);
  EXPECT_EQ(my_queue1.empty(), my_queue2.empty());
  EXPECT_EQ(my_queue1.size(), my_queue2.size());
  while (my_queue1.size()) {
    EXPECT_EQ(my_queue1.front().first, my_queue2.front().first);
    EXPECT_EQ(my_queue1.front().second, my_queue2.front().second);
    my_queue1.pop();
    my_queue2.pop();
  }
}

TEST(Suite_Queue, Copy_Empty_Constructor) {
  queue<int> std_queue;
  Queue<int> s21_queue;
  queue<int> std_copy(std_queue);
  Queue<int> s21_copy(s21_queue);
  EXPECT_EQ(std_copy.size(), s21_copy.size());
  EXPECT_EQ(std_queue.size(), s21_queue.size());
}

TEST(Suite_Queue, Copy_Constructor_Size) {
  queue<int> std_queue;
  Queue<int> s21_queue;
  for (int i = 1; i <= 10; ++i) {
    std_queue.push(i);
    s21_queue.push(i);
  }
  queue<int> std_copy(std_queue);
  Queue<int> s21_copy(s21_queue);
  std_queue.push(11);
  s21_queue.push(11);
  EXPECT_EQ(std_copy.size(), s21_copy.size());
  EXPECT_EQ(std_queue.size(), s21_queue.size());
}

TEST(Suite_Queue, Copy_Assignment_Operator) {
  queue<int> std_queue;
  Queue<int> s21_queue;
  for (int i = 1; i <= 10; ++i) {
    std_queue.push(i);
    s21_queue.push(i);
  }
  queue<int> std_copy;
  Queue<int> s21_copy;
  std_copy = std_queue;
  s21_copy = s21_queue;
  while (!std_copy.empty()) {
    EXPECT_EQ(std_copy.front(), s21_copy.front());
    std_copy.pop();
    s21_copy.pop();
  }
}

TEST(Suite_Queue, Copy_Assignment_Pair) {
  Queue<pair<string, int>> my_queue1{{"one", 1}, {"two", 2}, {"three", 3}};
  Queue<pair<string, int>> my_queue2;
  queue<pair<string, int>> my_queue3;
  my_queue2 = my_queue1;
  EXPECT_EQ(my_queue1.empty(), my_queue2.empty());
  EXPECT_EQ(my_queue1.size(), my_queue2.size());
  while (my_queue1.size()) {
    EXPECT_EQ(my_queue1.front().first, my_queue2.front().first);
    EXPECT_EQ(my_queue1.front().second, my_queue2.front().second);
    my_queue1.pop();
    my_queue2.pop();
  }
}

TEST(Suite_Queue, Assignment_Operator) {
  queue<int> std_queue;
  Queue<int> s21_queue;
  for (int i = 1; i <= 10; ++i) {
    std_queue.push(i);
    s21_queue.push(i);
  }
  queue<int> std_copy;
  Queue<int> s21_copy;
  std_copy = std_queue;
  s21_copy = s21_queue;
  EXPECT_EQ(std_copy.size(), s21_copy.size());
  while (std_copy.size()) {
    EXPECT_EQ(std_copy.front(), s21_copy.front());
    std_copy.pop();
    s21_copy.pop();
  }
  EXPECT_EQ(std_queue.size(), s21_queue.size());
}

TEST(Suite_Queue, Assignment_Operator_Empty) {
  queue<int> std_queue;
  Queue<int> s21_queue;
  queue<int> std_copy;
  Queue<int> s21_copy;
  std_copy = std_queue;
  s21_copy = s21_queue;
  EXPECT_EQ(std_copy.size(), s21_copy.size());
  EXPECT_EQ(std_queue.size(), s21_queue.size());
}

TEST(Suite_Queue, Assignment_Operator_Size) {
  queue<int> std_queue;
  Queue<int> s21_queue;
  for (int i = 1; i <= 10; ++i) {
    std_queue.push(i);
    s21_queue.push(i);
  }
  queue<int> std_copy;
  Queue<int> s21_copy;
  std_copy = std_queue;
  s21_copy = s21_queue;
  std_queue.push(11);
  s21_queue.push(11);
  EXPECT_EQ(std_copy.size(), s21_copy.size());
  EXPECT_EQ(std_queue.size(), s21_queue.size());
}

TEST(QueueTest, MoveAssignmentOperator) {
  queue<int> std_queue;
  Queue<int> s21_queue;
  for (int i = 1; i <= 10; ++i) {
    std_queue.push(i);
    s21_queue.push(i);
  }
  queue<int> std_move;
  Queue<int> s21_move;
  std_move = move(std_queue);
  s21_move = move(s21_queue);
  while (!std_move.empty()) {
    EXPECT_EQ(std_move.front(), s21_move.front());
    std_move.pop();
    s21_move.pop();
  }
}

TEST(Suite_Queue, Move_Assignment_Pair) {
  Queue<pair<string, int>> my_queue1{{"one", 1}, {"two", 2}, {"three", 3}};
  Queue<pair<string, int>> my_queue2;
  queue<pair<string, int>> my_queue3;
  my_queue2 = move(my_queue1);
  my_queue3.push({"one", 1});
  my_queue3.push({"two", 2});
  my_queue3.push({"three", 3});
  EXPECT_TRUE(my_queue1.empty());
  EXPECT_EQ(my_queue2.size(), my_queue3.size());
  while (my_queue2.size()) {
    EXPECT_EQ(my_queue2.front().first, my_queue3.front().first);
    EXPECT_EQ(my_queue2.front().second, my_queue3.front().second);
    my_queue2.pop();
    my_queue3.pop();
  }
}
