#include "s21_main.h"

TEST(MultisetTest, DefaultConstructor) {
  Multiset<int> ms;
  ASSERT_EQ(ms.size(), 0);
}

TEST(MultisetTest, InitializerListConstructor) {
  Multiset<int> ms = {1, 2, 2, 3, 3, 3};
  ASSERT_EQ(ms.size(), 6);
  ASSERT_EQ(ms.count(1), 1);
  ASSERT_EQ(ms.count(2), 2);
  ASSERT_EQ(ms.count(3), 3);
}

TEST(MultisetTest, CopyConstructor) {
  Multiset<int> ms1 = {1, 2, 2, 3, 3, 3};
  Multiset<int> ms2(ms1);
  ASSERT_EQ(ms2.size(), 6);
  ASSERT_EQ(ms2.count(1), 1);
  ASSERT_EQ(ms2.count(2), 2);
  ASSERT_EQ(ms2.count(3), 3);
}

TEST(MultisetTest, MoveConstructor) {
  Multiset<int> ms1 = {1, 2, 2, 3, 3, 3};
  Multiset<int> ms2(move(ms1));
  ASSERT_EQ(ms1.size(), 0);
  ASSERT_EQ(ms2.size(), 6);
  ASSERT_EQ(ms2.count(1), 1);
  ASSERT_EQ(ms2.count(2), 2);
  ASSERT_EQ(ms2.count(3), 3);
}

TEST(MultisetTest, Destructor) {
  Multiset<int>* ms = new Multiset<int>({1, 2, 2, 3, 3, 3});
  delete ms;
  SUCCEED();
}

TEST(MultisetTest, IteratorBeginEnd) {
  Multiset<int> ms = {1, 2, 2, 3, 3, 3};
  vector<int> values = {1, 2, 2, 3, 3, 3};
  int i = 0;
  for (auto it = ms.begin(); it != ms.end(); ++it) {
    ASSERT_EQ(*it, values[i++]);
  }
}

TEST(MultisetTest, ConstIteratorBeginEnd) {
  const Multiset<int> ms = {1, 2, 2, 3, 3, 3};
  vector<int> values = {1, 2, 2, 3, 3, 3};
  int i = 0;
  for (auto it = ms.begin(); it != ms.end(); ++it) {
    ASSERT_EQ(*it, values[i++]);
  }
}

TEST(MultisetTest, Insert) {
  Multiset<int> ms = {1, 2, 2, 3, 3, 3};
  ms.insert(2);
  ms.insert(4);
  ASSERT_EQ(ms.size(), 8);
  ASSERT_EQ(ms.count(1), 1);
  ASSERT_EQ(ms.count(2), 3);
  ASSERT_EQ(ms.count(3), 3);
  ASSERT_EQ(ms.count(4), 1);
}

TEST(MultisetTest, Clear) {
  Multiset<int> ms = {1, 2, 2, 3, 3, 3};
  ms.clear();
  ASSERT_EQ(ms.size(), 0);
}

TEST(MultisetTest, Swap) {
  Multiset<int> ms1 = {1, 2, 2, 3, 3, 3};
  Multiset<int> ms2 = {4, 5, 5, 6, 6, 6};
  ms1.swap(ms2);
  ASSERT_EQ(ms1.size(), 6);
  ASSERT_EQ(ms1.count(5), 2);
  ASSERT_EQ(ms1.count(6), 3);
  ASSERT_EQ(ms2.size(), 6);
  ASSERT_EQ(ms2.count(1), 1);
  ASSERT_EQ(ms2.count(2), 2);
  ASSERT_EQ(ms2.count(3), 3);
}

TEST(MultisetTest, Swap1) {
  Multiset<int> ms1 = {1, 2, 2, 3, 3, 3};
  Multiset<int> ms2 = {1, 2};
  ms1.swap(ms2);
  ASSERT_EQ(ms1.size(), 2);
  ASSERT_EQ(ms1.count(1), 1);
  ASSERT_EQ(ms1.count(2), 1);
  ASSERT_EQ(ms2.size(), 6);
  ASSERT_EQ(ms2.count(1), 1);
  ASSERT_EQ(ms2.count(2), 2);
  ASSERT_EQ(ms2.count(3), 3);
}

TEST(MultisetTest, MoveAssignmentOperator) {
  Multiset<int> ms1 = {1, 2, 2, 3, 3, 3};
  Multiset<int> ms2;
  ms2 = move(ms1);
  ASSERT_EQ(ms1.size(), 0);
  ASSERT_EQ(ms2.size(), 6);
  ASSERT_EQ(ms2.count(1), 1);
  ASSERT_EQ(ms2.count(2), 2);
  ASSERT_EQ(ms2.count(3), 3);
}

TEST(MultisetTest, Empty) {
  Multiset<int> ms;
  ASSERT_TRUE(ms.empty());
  ms.insert(42);
  ASSERT_FALSE(ms.empty());
}

TEST(MultisetTest, Size) {
  Multiset<int> ms;
  ASSERT_EQ(ms.size(), 0u);
  ms.insert(1);
  ASSERT_EQ(ms.size(), 1u);
  ms.insert(2);
  ASSERT_EQ(ms.size(), 2u);
}

TEST(MultisetTest, MaxSize) {
  Multiset<int> ms;
  ASSERT_GT(ms.max_size(), 0u);
}

TEST(MultisetTest, Count) {
  Multiset<int> ms = {1, 2, 2, 3, 3, 3};
  ASSERT_EQ(ms.count(1), 1u);
  ASSERT_EQ(ms.count(2), 2u);
  ASSERT_EQ(ms.count(3), 3u);
  ASSERT_EQ(ms.count(4), 0u);
}

TEST(MultisetTest, Find) {
  Multiset<int> s = {1, 2, 2, 3, 3, 3};
  auto it = s.find(2);
  ASSERT_EQ(*it, 2);
  it = s.find(4);
  ASSERT_EQ(it, s.end());
}

TEST(MultisetTest, Contains) {
  Multiset<int> mset;
  mset.insert(1);
  mset.insert(2);
  mset.insert(2);
  mset.insert(3);

  EXPECT_TRUE(mset.contains(1));
  EXPECT_TRUE(mset.contains(2));
  EXPECT_TRUE(mset.contains(3));
  EXPECT_FALSE(mset.contains(0));
  EXPECT_FALSE(mset.contains(4));
}

TEST(MultisetTest, EmptyContains) {
  Multiset<int> mset;
  EXPECT_FALSE(mset.contains(0));
}

TEST(MultisetTest, StringContains) {
  Multiset<string> mset;
  mset.insert("apple");
  mset.insert("banana");
  mset.insert("banana");
  mset.insert("cherry");

  EXPECT_TRUE(mset.contains("apple"));
  EXPECT_TRUE(mset.contains("banana"));
  EXPECT_TRUE(mset.contains("cherry"));
  EXPECT_FALSE(mset.contains("orange"));
}

TEST(MultisetTest, UpperBound) {
  Multiset<int> s = {1, 3, 5, 7, 9};
  auto it = s.upper_bound(3);
  EXPECT_EQ(*it, 5);
  it = s.upper_bound(6);
  EXPECT_EQ(*it, 7);
  it = s.upper_bound(9);
  EXPECT_EQ(it, s.end());
}

TEST(MultisetTest, UpperBoundEmpty) {
  Multiset<int> s;
  auto it = s.upper_bound(1);
  EXPECT_EQ(it, s.begin());
}

TEST(MultisetTest, UpperBoundLowerThanAll) {
  Multiset<int> s = {1, 3, 5, 7, 9};
  auto it = s.upper_bound(0);
  EXPECT_EQ(*it, 1);
}

TEST(MultisetTest, LowerBound) {
  Multiset<int> s = {1, 3, 5, 7, 9};
  auto it = s.lower_bound(3);
  EXPECT_EQ(*it, 3);
  it = s.lower_bound(6);
  EXPECT_EQ(*it, 7);
  it = s.lower_bound(9);
  EXPECT_EQ(*it, 9);
  it = s.lower_bound(10);
  EXPECT_EQ(it, s.end());
}

TEST(MultisetTest, LowerBoundEmpty) {
  Multiset<int> s;
  auto it = s.lower_bound(1);
  EXPECT_EQ(it, s.begin());
}

TEST(MultisetTest, LowerBoundLowerThanAll) {
  Multiset<int> s = {1, 3, 5, 7, 9};
  auto it = s.lower_bound(0);
  EXPECT_EQ(*it, 1);
}

TEST(MultisetTest, Merge) {
  Multiset<int> set1, set2;
  const int size1 = 100;
  const int size2 = 50;
  for (int i = 0; i < size1; ++i) {
    set1.insert(rand() % 100);
  }
  for (int i = 0; i < size2; ++i) {
    set2.insert(rand() % 100);
  }
  set1.merge(set2);
  for (const auto& element : set2) {
    ASSERT_TRUE(set1.count(element) > 0);
  }
  ASSERT_EQ(set2.size(), 0);
}

TEST(MultisetTest, Erase) {
  Multiset<int> s;
  s.insert(4);
  s.insert(2);
  s.insert(6);
  s.insert(1);
  s.insert(3);
  s.insert(5);
  s.insert(7);

  auto it = s.find(0);
  ASSERT_EQ(it, s.end());
  ASSERT_EQ(s.size(), 7);
  it = s.find(4);
  ASSERT_NE(it, s.end());
  s.erase(it);
  ASSERT_EQ(s.size(), 6);

  it = s.find(1);
  ASSERT_NE(it, s.end());
  s.erase(it);
  ASSERT_EQ(s.size(), 5);
  ASSERT_EQ(*s.find(2), 2);

  it = s.find(6);
  ASSERT_NE(it, s.end());
  s.erase(it);
  ASSERT_EQ(s.size(), 4);
  ASSERT_EQ(*s.find(5), 5);

  it = s.find(5);
  ASSERT_NE(it, s.end());
  s.erase(it);
  ASSERT_EQ(s.size(), 3);
  ASSERT_EQ(s.find(5), s.end());
}

TEST(MultisetTest, EqualRange) {
  Multiset<int> s = {1, 3, 3, 5, 7, 9};
  auto [it1, it2] = s.equal_range(3);
  EXPECT_EQ(*it1, 3);
  EXPECT_EQ(*it2, 5);
  auto [it3, it4] = s.equal_range(6);
  EXPECT_EQ(it3, it4);
  auto [it5, it6] = s.equal_range(9);
  EXPECT_EQ(*it5, 9);
  EXPECT_EQ(it6, s.end());
}

TEST(MultisetTest, EqualRangeEmpty) {
  Multiset<int> s;
  auto [it1, it2] = s.equal_range(1);
  EXPECT_EQ(it1, s.begin());
  EXPECT_EQ(it2, s.end());
}

TEST(MultisetTest, insert_many) {
  Multiset<string> s;
  auto result = s.insert_many("one");
  auto [it1, inserted1] = result.front();
  EXPECT_TRUE(inserted1);
  EXPECT_EQ(*it1, "one");
  result = s.insert_many("two", "two");
  auto [it2, inserted2] = result.front();
  EXPECT_TRUE(inserted2);
  EXPECT_EQ(*it2, "two");
  result = s.insert_many("three", "three", "three");
  auto [it3, inserted3] = result.front();
  EXPECT_TRUE(inserted3);
  EXPECT_EQ(*it3, "three");
  EXPECT_EQ(s.size(), 6);
}

TEST(MultisetTest, insert_manyEmpty) {
  Multiset<int> s;
  auto result = s.insert_many(1);
  auto [it, inserted] = result.front();
  EXPECT_TRUE(inserted);
  EXPECT_EQ(*it, 1);
}
