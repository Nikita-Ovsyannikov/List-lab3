#include "gtest.h"
#include "tlist.h"

TEST(TlistIterator, can_create_iterator)
{
    list<int> a;
    ASSERT_NO_THROW(auto it = a.begin());
}

TEST(TlistIterator, can_iterate_empty_list)
{
    list<int> a;
    auto it = a.begin();
    ASSERT_EQ(it, a.end());
}

TEST(TlistIterator, can_iterate_non_empty_list)
{
    list<int> a;
    a.push_back(2);
    a.push_back(4);

    int i = 2;
    for (auto it = a.begin(); it != a.end(); ++it) {
        ASSERT_EQ(*it, i);
        i += 2;
    }
    auto it = a.begin();
    ++it;
    ++it;
    ++it;
    ASSERT_EQ(it, a.end());
}

TEST(TlistIterator, can_insert_after_begin)
{
    list<int> a;
    a.push_back(2);
    a.push_back(6);
    a.push_back(8);
    auto it = a.begin();
    a.insert_after(it, 4);

    ASSERT_EQ(a.size(), 4);
    int i = 2;
    for (auto it2 = a.begin(); it2 != a.end(); ++it2) {
        ASSERT_EQ(*it2, i);
        i += 2;
    }
}


TEST(TlistIterator, can_insert_after_middle)
{
    list<int> a;
    a.push_back(2);
    a.push_back(4);
    a.push_back(8);
    auto it = a.begin();
    ++it;
    a.insert_after(it, 6);

    ASSERT_EQ(a.size(), 4);
    int i = 2;
    for (auto it2 = a.begin(); it2 != a.end(); ++it2) {
        ASSERT_EQ(*it2, i);
        i += 2;
    }
}

TEST(TlistIterator, can_insert_at_end)
{
    list<int> a;
    a.push_back(2);
    a.push_back(4);
    auto it = a.begin();
    ++it; ++it;
    a.insert_after(it, 6);

    ASSERT_EQ(a.size(), 3);
    int i = 2;
    for (auto it2 = a.begin(); it2 != a.end(); ++it2) {
        ASSERT_EQ(*it2, i);
        i += 2;
    }
}

TEST(TlistIterator, can_erase_after_begin)
{
    list<int> a;
    a.push_back(2);
    a.push_back(4);
    a.push_back(6);
    auto it = a.begin();
    a.erase_after(it);

    ASSERT_EQ(a.size(), 2);
    int i = 2;
    for (auto it2 = a.begin(); it2 != a.end(); ++it2) {
        ASSERT_EQ(*it2, i);
        i += 4;
    }
}

TEST(TlistIterator, can_erase_after_middle)
{
    list<int> a;
    a.push_back(2);
    a.push_back(4);
    a.push_back(6);
    auto it = a.begin();
    ++it;
    a.erase_after(it);

    ASSERT_EQ(a.size(), 2);
    int i = 2;
    for (auto it2 = a.begin(); it2 != a.end(); ++it2) {
        ASSERT_EQ(*it2, i);
        i += 2;
    }
}

TEST(TlistIterator, erase_after_last_does_nothing_without_throw)
{
    list<int> a;
    a.push_back(2);

    auto it = a.begin();
    ++it;
    ASSERT_NO_THROW(a.erase_after(it));
    ASSERT_EQ(a.size(), 1);
}

TEST(TlistIterator, erase_from_empty_list_does_nothing_without_throw)
{
    list<int> a;
    auto it = a.begin();
    a.erase_after(it);

    ASSERT_NO_THROW(a.erase_after(it));
    ASSERT_EQ(a.size(), 0);
}

TEST(TlistIterator, can_insert_at_front)
{
    list<int> a;
    a.insert_front(4);
    a.insert_front(2);

    ASSERT_EQ(a.size(), 2);
    int i = 2;
    for (auto it2 = a.begin(); it2 != a.end(); ++it2) {
        ASSERT_EQ(*it2, i);
        i += 2;
    }
}

TEST(TlistIterator, can_insert_at_front_empty_list)
{
    list<int> a;
    a.insert_front(2);

    ASSERT_EQ(a.size(), 1);
    ASSERT_EQ(a.front_val(), 2);
}

TEST(TlistIterator, can_erase_front)
{
    list<int> a;
    a.push_back(2);
    a.push_back(4);
    a.push_back(6);

    a.erase_front();
    ASSERT_EQ(a.size(), 2);
    int i = 4;
    for (auto it2 = a.begin(); it2 != a.end(); ++it2) {
        ASSERT_EQ(*it2, i);
        i += 2;
    }
}

TEST(TlistIterator, erase_front_empty_list_without_throw)
{
    list<int> a;

    ASSERT_NO_THROW(a.erase_front());
    ASSERT_EQ(a.size(), 0);
}

TEST(TlistIterator, erase_front_single_element)
{
    list<int> a;
    a.push_back(10);
    a.erase_front();

    ASSERT_EQ(a.size(), 0);
}

TEST(TlistIterator, erase_front_multiple_elements)
{
    list<int> a;
    a.push_back(2);
    a.push_back(4);
    a.push_back(6);
    a.erase_front();
    a.erase_front();

    ASSERT_EQ(a.size(), 1);
    ASSERT_EQ(a.front_val(), 6);
}

TEST(Tlist, copy_constructor_content_check)
{
    list<int> a;
    a.push_back(2);
    a.push_back(4);
    a.push_back(6);
    list<int> b(a);

    ASSERT_EQ(a.size(), b.size());
    auto it_a = a.begin();
    auto it_b = b.begin();
    while (it_a != a.end()) {
        ASSERT_EQ(*it_a, *it_b);
        ++it_a;
        ++it_b;
    }
}

TEST(Tlist, copy_assignment_content_check)
{
    list<int> a;
    a.push_back(2);
    a.push_back(4);
    a.push_back(6);
    list<int> b;
    b = a;

    ASSERT_EQ(a.size(), b.size());
    auto it_a = a.begin();
    auto it_b = b.begin();
    while (it_a != a.end()) {
        ASSERT_EQ(*it_a, *it_b);
        ++it_a;
        ++it_b;
    }
}

TEST(Tlist, move_constructor_content_check)
{
    list<int> a;
    a.push_back(2);
    a.push_back(4);
    a.push_back(6);
    list<int> b(std::move(a));

    ASSERT_EQ(b.size(), 3);
    ASSERT_TRUE(a.empty());
    auto it_b = b.begin();
    ASSERT_EQ(*it_b, 2);
    ++it_b;
    ASSERT_EQ(*it_b, 4);
    ++it_b;
    ASSERT_EQ(*it_b, 6);

}

TEST(Tlist, move_assignment_content_check)
{
    list<int> a;
    a.push_back(10);
    list<int> b;
    b.push_back(2);
    b.push_back(4);
    b.push_back(6);
    a = std::move(b);

    ASSERT_EQ(a.size(), 3);
    ASSERT_TRUE(b.empty());
    auto it_a = a.begin();
    ASSERT_EQ(*it_a, 2);
    ++it_a;
    ASSERT_EQ(*it_a, 4);
    ++it_a;
    ASSERT_EQ(*it_a, 6);
}
