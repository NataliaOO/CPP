#include "s21_main.h"

TEST(map_test, constructorInit) {
  Map<int, int> m1 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  map<int, int> m2 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  auto it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); it1++, it2++)
    EXPECT_EQ((*it1).second, (*it2).second);
  it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); it1++, it2++)
    EXPECT_EQ((*it1).first, (*it2).first);
  EXPECT_EQ(m1.Size(), m2.size());
}

TEST(map_test, constructorEmpty) {
  Map<int, int> m1;
  map<int, int> m2;
  EXPECT_EQ(m1.Size(), m2.size());
  m1.insert({1, 1});
  m2.insert({1, 1});
  EXPECT_EQ(m1.Size(), m2.size());
}

TEST(map_test, constructorCopy) {
  Map<int, int> m1({{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}});
  Map<int, int> m2(m1);
  EXPECT_EQ(m1.Size(), m2.Size());
  auto it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1), (*it2));
}

TEST(map_test, constructorCopy2) {
  Map<int, int> m1 = {{5, 5}, {4, 4}, {1, 1}, {2, 2}, {3, 3}};
  Map<int, int> m2(m1);
  EXPECT_EQ(m1.Size(), m2.Size());
  auto it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1), (*it2));
}

TEST(map_test, constructorCopy3) {
  Map<int, int> m1 = {{5, 5}, {4, 4}, {1, 1}, {2, 2}, {3, 3}};
  Map<int, int> m2 = m1;
  EXPECT_EQ(m1.Size(), m2.Size());
  auto it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); it1++, it2++)
    EXPECT_EQ((*it1), (*it2));
}

TEST(map_test, constructorMove) {
  Map<int, int> m1 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  Map<int, int> m3 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  Map<int, int> m2 = move(m1);
  cout << m1.Size() << endl;
  EXPECT_EQ(m1.Size(), 0);
  auto it1 = m2.begin();
  for (auto it2 = m3.begin(); it2 != m3.end(); it1++, it2++)
    EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, Max_size) {
  Map<int, int> m1 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  map<int, int> m2 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.max_size(), m2.max_size());
}

TEST(map_test, at1) {
  Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  for (size_t i = 1; i < m1.Size(); i++) EXPECT_EQ(m1.at(i), m2.at(i));
}

TEST(map_test, begin) {
  Map<int, int> m1 = {{1, 1}};
  map<int, int> m2 = {{1, 1}};
  auto it1 = m1.begin();
  auto it2 = m2.begin();
  EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, emptyFalse) {
  Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, emptyTrue) {
  Map<int, int> m1;
  map<int, int> m2;
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, size) {
  Map<int, int> m1;
  map<int, int> m2;
  pair<int, int> pair = {3, 1};
  m1.insert(pair);
  m2.insert(pair);
  EXPECT_EQ(m1.Size(), m2.size());
}

TEST(map_test, size0) {
  Map<int, int> m1;
  map<int, int> m2;
  EXPECT_EQ(m1.Size(), m2.size());
}

TEST(map_test, clear) {
  Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.Size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, clearEmpty) {
  Map<int, int> m1;
  map<int, int> m2;
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.Size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, insertPair) {
  Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  pair<int, int> pair = {6, 6};
  EXPECT_EQ(m1.insert(pair).second, m2.insert(pair).second);
  EXPECT_EQ(m1.Size(), m2.size());
}

TEST(map_test, insertInEmpty) {
  Map<int, int> m1;
  map<int, int> m2;
  pair<int, int> pair = {3, 1};
  EXPECT_EQ(m1.insert(pair).second, m2.insert(pair).second);
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.Size(), m2.size());
}

TEST(map_test, insertNumKey) {
  Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.empty(), m2.empty());
  pair<int, int> pair = {3, 1};
  EXPECT_EQ(m1.insert(3, 1).second, m2.insert(pair).second);
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.Size(), m2.size());
}

TEST(map_test, insert_or_assign) {
  Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  map<int, int> m2 = {{1, 1}, {2, 2}, {3, 4}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.empty(), m2.empty());
  m1.insert_or_assign(3, 4);
  EXPECT_EQ(m1.at(3), m2.at(3));
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.Size(), m2.size());
}

TEST(map_test, insert_or_assign2) {
  Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 4}};
  EXPECT_EQ(m1.empty(), m2.empty());
  m1.insert_or_assign(6, 4);
  EXPECT_EQ(m1.at(6), m2.at(6));
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.Size(), m2.size());
}

TEST(map_test, swap) {
  Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  Map<int, int> m11;
  map<int, int> m22;
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.Size(), m2.size());
  EXPECT_EQ(m11.Size(), m22.size());
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); it1++, it2++)
    EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, swapEmpty) {
  Map<int, int> m1;
  map<int, int> m2;
  Map<int, int> m11;
  map<int, int> m22;
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.Size(), m2.size());
  EXPECT_EQ(m11.Size(), m22.size());
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); it1++, it2++)
    EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, containsTrue) {
  Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.contains(1), true);
}

TEST(map_test, containsFalse) {
  Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.contains(0), false);
}

TEST(map_test, Merge2) {
  Map<int, int> s1{{1, 1}, {2, 2}, {3, 3}, {4, 4},
                   {5, 5}, {6, 6}, {7, 7}, {8, 8}};
  Map<int, int> s2{{9, 9}, {-1, -1}, {3, 3}};
  map<int, int> s3{{1, 1}, {2, 2}, {3, 3}, {4, 4},
                   {5, 5}, {6, 6}, {7, 7}, {8, 8}};
  map<int, int> s4{{9, 9}, {-1, -1}, {3, 3}};
  s1.merge(s2);
  s3.merge(s4);
  EXPECT_EQ(s1.Size(), s3.size());
}

TEST(map_test, Erase) {
  Map<int, int> m1;
  m1.insert({1, 1});

  auto s_pr = m1.insert({2, 2});
  m1.erase(s_pr.first);
  EXPECT_EQ(m1.contains(2), false);
}

TEST(map_test, Erase_Test_2) {
  Map<int, int> m1 = {{60, 60}, {58, 58}, {63, 63}, {1, 1},
                      {59, 59}, {61, 61}, {65, 65}};
  map<int, int> m2 = {{60, 60}, {58, 58}, {63, 63}, {1, 1},
                      {59, 59}, {61, 61}, {65, 65}};

  auto it1 = m1.begin();
  auto it2 = m2.begin();
  m1.erase(it1);
  m2.erase(it2);
  it1 = m1.begin();
  it2 = m2.begin();
  for (; it1 != m1.end() && it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, Erase_Test_3) {
  Map<int, int> m1 = {{60, 60}, {58, 58}, {63, 63}, {1, 1},
                      {59, 59}, {61, 61}, {65, 65}};
  map<int, int> m2 = {{60, 60}, {58, 58}, {63, 63}, {1, 1},
                      {59, 59}, {61, 61}, {65, 65}};

  auto pair1 = m1.insert(62, 62);
  auto it1 = pair1.first;
  auto it2 = m2.begin();
  m1.erase(it1);
  it1 = m1.begin();
  it2 = m2.begin();
  for (; it1 != m1.end() && it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, Erase_Test_4) {
  Map<int, int> m1 = {{60, 60}, {63, 63}, {1, 1}, {61, 61}, {65, 65}, {62, 62}};
  map<int, int> m2 = {{60, 60}, {63, 63}, {1, 1}, {61, 61}, {65, 65}, {62, 62}};

  auto pair1 = m1.insert(58, 58);
  auto it1 = pair1.first;
  auto it2 = m2.begin();
  m1.erase(it1);
  it1 = m1.begin();
  it2 = m2.begin();
  for (; it1 != m1.end() && it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, Erase_Test_5) {
  Map<int, int> m1 = {{10, 10}, {12, 12}};
  map<int, int> m2 = {{10, 10}, {12, 12}};

  auto it1 = m1.begin();
  auto it2 = m2.begin();
  m1.erase(it1);
  m2.erase(it2);
  it1 = m1.begin();
  it2 = m2.begin();
  for (; it1 != m1.end() && it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, Erase_Test_6) {
  Map<int, int> m1 = {{60, 60}, {55, 55}, {63, 63}, {1, 1},
                      {61, 61}, {65, 65}, {62, 62}};
  map<int, int> m2 = {{60, 60}, {55, 55}, {63, 63}, {1, 1},
                      {61, 61}, {65, 65}, {62, 62}};

  auto pair1 = m1.insert(58, 58);
  auto it1 = pair1.first;
  auto it2 = m2.begin();
  m1.erase(it1);
  it1 = m1.begin();
  it2 = m2.begin();
  for (; it1 != m1.end() && it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, Erase_Test_7) {
  Map<int, int> m1 = {{4, 4}, {2, 2}, {1, 1}};
  map<int, int> m2 = {{4, 4}, {1, 1}};

  auto it1 = m1.begin();
  auto it2 = m2.begin();
  it1++;
  m1.erase(it1);
  it1 = m1.begin();
  it2 = m2.begin();
  for (; it1 != m1.end() && it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, Erase_Test_8) {
  Map<int, int> m1 = {{4, 4}, {2, 2}, {1, 1}, {3, 3}, {0, 0}};
  map<int, int> m2 = {{4, 4}, {1, 1}, {3, 3}, {0, 0}};

  auto it1 = m1.begin();
  auto it2 = m2.begin();
  it1++;
  it1++;
  m1.erase(it1);
  it1 = m1.begin();
  it2 = m2.begin();
  for (; it1 != m1.end() && it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, MergeTest_3) {
  Map<int, int> m1 = {{1, 1}};
  Map<int, int> m2 = {{5, 5}, {1, 1}, {7, 7}, {2, 2}, {3, 3}};
  map<int, int> m3 = {{1, 1}};
  map<int, int> m4 = {{5, 5}, {1, 1}, {7, 7}, {2, 2}, {3, 3}};

  m1.merge(m2);
  m3.merge(m4);
  auto it1 = m1.begin();
  auto it2 = m3.begin();
  for (; it1 != m1.end() && it2 != m3.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, MergeTest_4) {
  Map<int, int> m1 = {{1, 1}, {0, 0}};
  Map<int, int> m2 = {{5, 5}, {2, 2}, {7, 7}, {0, 0},
                      {3, 3}, {6, 6}, {9, 9}, {10, 10}};
  map<int, int> m3 = {{1, 1}, {0, 0}};
  map<int, int> m4 = {{5, 5}, {2, 2}, {7, 7}, {0, 0},
                      {3, 3}, {6, 6}, {9, 9}, {10, 10}};

  m1.merge(m2);
  m3.merge(m4);
  auto it1 = m1.begin();
  auto it2 = m3.begin();
  for (; it1 != m1.end() && it2 != m3.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, MergeTest_5) {
  Map<int, int> m1 = {{5, 5}, {2, 2}, {6, 6}};
  Map<int, int> m2 = {{5, 5}, {2, 2}, {7, 7}, {0, 0},
                      {3, 3}, {6, 6}, {9, 9}, {10, 10}};
  map<int, int> m3 = {{5, 5}, {2, 2}, {6, 6}};
  map<int, int> m4 = {{5, 5}, {2, 2}, {7, 7}, {0, 0},
                      {3, 3}, {6, 6}, {9, 9}, {10, 10}};

  m1.merge(m2);
  m3.merge(m4);
  auto it1 = m1.begin();
  auto it2 = m3.begin();
  for (; it1 != m1.end() && it2 != m3.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, MergeTest_6) {
  Map<int, int> m1 = {{10, 10}, {13, 13}, {15, 15}};
  Map<int, int> m2 = {{10, 10}, {20, 20}, {15, 15}, {13, 13}, {25, 25}};
  map<int, int> m3 = {{10, 10}, {13, 13}, {15, 15}};
  map<int, int> m4 = {{10, 10}, {20, 20}, {15, 15}, {13, 13}, {25, 25}};
  m1.merge(m2);
  m3.merge(m4);
  auto it1 = m1.begin();
  auto it2 = m3.begin();
  for (; it1 != m1.end() && it2 != m3.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, Emplace_Test) {
  Map<int, int> m1 = {{10, 10}, {13, 13}, {15, 15}};
  map<int, int> m2 = {{10, 10}, {13, 13}, {15, 15}};
  m1.insert_many(make_pair(5, 5));
  m2.emplace(make_pair(5, 5));
  auto it1 = m1.begin();
  auto it2 = m2.begin();
  for (; it1 != m1.end() && it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, Emplace) {
  Map<int, int> m1;
  m1.insert_many(make_pair(1, 1));
  EXPECT_EQ(m1.contains(1), true);
}

TEST(map_test, EraseOneChild) {
  Map<int, int> m1{{1, 1}, {2, 2}, {3, 3}};
  auto it = m1.begin();
  it++;
  m1.erase(it);
  EXPECT_EQ(m1.contains(2), false);
}

TEST(map_test, EraseOneChild2) {
  Map<int, int> m1{{2, 2}};
  auto it = m1.begin();
  m1.erase(it);
  EXPECT_EQ(m1.contains(2), false);
}

TEST(map_test, EraseTwoChild) {
  Map<int, int> m1{{2, 2}, {1, 1}, {3, 3}};
  auto it = m1.begin();
  it++;
  m1.erase(it);
  EXPECT_EQ(m1.contains(2), false);
}

TEST(map_test, Operator) {
  Map<int, int> m1 = {{1, 1}};
  Map<int, int> m2 = m1;
  auto it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); it1++, it2++)
    EXPECT_EQ((*it1), (*it2));
}

TEST(map_test, operatorBrace) {
  Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1[1], 1);
  EXPECT_EQ(m2[1], 1);
  EXPECT_EQ(m1[5], 5);
  EXPECT_EQ(m2[5], 5);
  EXPECT_EQ(m1[1], m2[1]);
  EXPECT_EQ(m1[3], m2[3]);
  EXPECT_EQ(m1[5], m2[5]);
  m1[10] = 10;
  m2[10] = 10;
  m1.at(10) = 5;
  m2.at(10) = 5;
  EXPECT_EQ(m1.at(10), m2.at(10));
}
