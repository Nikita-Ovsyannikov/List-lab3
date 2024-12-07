#include "gtest.h"
#include "tlist.h"
#include <algorithm>

TEST(Tlist, can_create_list)
{
	EXPECT_NO_THROW(list<int> a(2));
}

TEST(Tlist, cant_create_list_with_negative_length)
{
	EXPECT_ANY_THROW(list<int> a(-2));
}

TEST(Tlist, correct_val_of_empty_for_empty_list)
{
	list<int> a;
	ASSERT_TRUE(a.empty());
}

TEST(Tlist, correct_val_of_empty_for_non_empty_list)
{
	list<int> a(1);
	ASSERT_FALSE(a.empty());
}

TEST(Tlist, correct_size)
{
	list<int> a(10);
	EXPECT_EQ(10, a.size());
}

TEST(Tlist, correct_back_val)
{
	list<int> a(10);
	a.back_val() = 20;
	EXPECT_EQ(20, a.back_val());
}

TEST(Tlist, correct_front_val)
{
	list<int> a(10);
	a.front_val() = 20;
	EXPECT_EQ(20, a.front_val());
}

TEST(Tlist, can_pop_back)
{
	list<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.pop_back();
	ASSERT_EQ(a.size(), 2);
	ASSERT_EQ(a.back_val(), 2);
}

TEST(Tlist, cant_pop_back_empty_list)
{
	list<int> a;
	ASSERT_ANY_THROW(a.pop_back());
}

TEST(Tlist, can_pop_back_list_with_one_elem)
{
	list<int> a;
	a.push_back(1);
	a.pop_back();
	ASSERT_TRUE(a.empty());
}

TEST(Tlist, can_pop_back_multiple_times)
{
	list<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.pop_back();
	a.pop_back();
	ASSERT_EQ(a.size(), 1);
	ASSERT_EQ(a.back_val(), 1);
	a.pop_back();
	ASSERT_TRUE(a.empty());
}

TEST(Tlist, can_pop_front)
{
	list<int> a;
	a.push_front(3);
	a.push_front(2);
	a.push_front(1);
	a.pop_front();
	ASSERT_EQ(a.size(), 2);
	ASSERT_EQ(a.front_val(), 2);
}

TEST(Tlist, cant_pop_front_empty_list)
{
	list<int> a;
	ASSERT_ANY_THROW(a.pop_front());
}

TEST(Tlist, can_pop_front_list_with_one_elem)
{
	list<int> a;
	a.push_front(1);
	a.pop_front();
	ASSERT_TRUE(a.empty());
}


TEST(Tlist, pop_front_multiple_times)
{
	list<int> a;
	a.push_front(3);
	a.push_front(2);
	a.push_front(1);
	a.pop_front();
	a.pop_front();
	ASSERT_EQ(a.size(), 1);
	ASSERT_EQ(a.front_val(), 3);
	a.pop_front();
	ASSERT_TRUE(a.empty());
}

TEST(Tlist, push_back_to_empty_list)
{
	list<int> a;
	a.push_back(1);
	ASSERT_EQ(a.size(), 1);
	ASSERT_EQ(a.front_val(), 1);
	ASSERT_EQ(a.back_val(), 1);
}

TEST(Tlist, push_front_to_empty_list)
{
	list<int> a;
	a.push_front(1);
	ASSERT_EQ(a.size(), 1);
	ASSERT_EQ(a.front_val(), 1);
	ASSERT_EQ(a.back_val(), 1);
}

TEST(Tlist, can_copy_empty_list) 
{
	list<int> a;
	list<int> b(a); 
	EXPECT_TRUE(b.empty());
	list<int> c;
	c = a;
	EXPECT_TRUE(c.empty());
}

TEST(Tlist, can_copy_by_constructor) {
	list<int> a;
	for (int i = 0; i < 7; i++) {
		a.push_back(i);
	}
	ASSERT_NO_THROW(list<int> b(a));

}

TEST(Tlist, can_copy_by_assignment_self) {
	list<int> a;
	for (int i = 0; i < 5; ++i) {
		a.push_back(i);
	}
	ASSERT_NO_THROW(a = a);

}

TEST(Tlist, move_constructor)
{
	list<int> b;
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	list<int> a(std::move(b));

	ASSERT_EQ(a.size(), 3);
	ASSERT_EQ(a.front_val(), 1);
	ASSERT_EQ(a.back_val(), 3);
	ASSERT_TRUE(b.empty());
}

TEST(Tlist, move_assignment)
{
	list<int> a;
	a.push_back(5);
	list<int> b;
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	a = std::move(b);

	ASSERT_EQ(a.size(), 3);
	ASSERT_EQ(a.front_val(), 1);
	ASSERT_EQ(a.back_val(), 3);
	ASSERT_TRUE(b.empty());
}

TEST(Tlist, move_assignment_self_assignment)
{
	list<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a = std::move(a);
	ASSERT_TRUE(a.empty());
}

TEST(Tlist, clear_empty_list)
{
	list<int> a;
	a.clear();
	ASSERT_TRUE(a.empty());
}

TEST(Tlist, test_for_print)
{
	list<int> a;
	a.push_back(3);
	a.push_back(2);
	a.push_back(1);
	a.print();
	a.clear();
	a.print();
	ASSERT_TRUE(1);
}

//for task

TEST(Tlist, selection_sort) 
{
	list<int> a;
	a.push_back(5);
	a.push_back(2);
	a.push_back(8);
	a.push_back(1);
	a.push_back(9);
	a.push_back(4);

	a.sort();

	ASSERT_EQ(a.size(), 6);
	auto it = a.begin();
	ASSERT_EQ(*it, 1);
	++it;
	ASSERT_EQ(*it, 2);
	++it;
	ASSERT_EQ(*it, 4);
	++it;
	ASSERT_EQ(*it, 5);
	++it;
	ASSERT_EQ(*it, 8);
	++it;
	ASSERT_EQ(*it, 9);
}


TEST(Tlist, selection_sort_empty_list) 
{
	list<int> a;
	a.sort();
	ASSERT_TRUE(a.empty());
}

TEST(Tlist, selection_sort_one_element_list) 
{
	list<int> a;
	a.push_back(5);
	a.sort();
	ASSERT_EQ(a.size(), 1);
	ASSERT_EQ(a.front_val(), 5);
}

TEST(Tlist, selection_sort_already_sorted_list) 
{
	list<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.sort();

	ASSERT_EQ(a.size(), 3);
	auto it = a.begin();
	int i = 1;
	for (; it != a.end(); ++it, i++) {
		ASSERT_EQ(*it, i);
	}
}

TEST(Tlist, selection_sort_duplicates) 
{
	list<int> a;
	a.push_back(3);
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(1);

	a.sort();

	ASSERT_EQ(a.size(), 5);
	auto it = a.begin();
	ASSERT_EQ(*it, 1);
	++it;
	ASSERT_EQ(*it, 1);
	++it;
	ASSERT_EQ(*it, 2);
	++it;
	ASSERT_EQ(*it, 3);
	++it;
	ASSERT_EQ(*it, 3);
}

TEST(Tlist, insert_in_sorted_list) 
{
	list<int> a;
	a.push_back(1);
	a.push_back(3);
	a.push_back(5);

	a.insert_in_sorted_list(2);
	a.insert_in_sorted_list(4);
	a.insert_in_sorted_list(0);
	a.insert_in_sorted_list(6);

	ASSERT_EQ(a.size(), 7);
	auto it = a.begin();
	for (int i = 0; it != a.end(); ++it, i++) {
		ASSERT_EQ(*it, i);
	}
}

TEST(Tlist, insert_in_sorted_list_empty_list) 
{
	list<int> a;
	a.insert_in_sorted_list(5);
	ASSERT_EQ(a.size(), 1);
	ASSERT_EQ(a.front_val(), 5);
}

TEST(Tlist, insert_in_sorted_list_at_begin) 
{
	list<int> a;
	a.push_back(2);
	a.push_back(3);

	a.insert_in_sorted_list(1);

	ASSERT_EQ(a.size(), 3);
	auto it = a.begin();
	for (int i = 1; it != a.end(); ++it, i++) {
		ASSERT_EQ(*it, i);
	}
}

TEST(Tlist, insert_in_sorted_list_at_end) 
{
	list<int> a;
	a.push_back(1);
	a.push_back(2);
	a.insert_in_sorted_list(3);
	
	ASSERT_EQ(a.size(), 3);
	auto it = a.begin();
	
	for (int i = 1; it != a.end(); ++it, i++) {
		ASSERT_EQ(*it, i);
	}
}

TEST(Tlist, insert_in_sorted_list_duplicates) 
{
	list<int> a;
	a.push_back(1);
	a.push_back(3);
	a.push_back(3);
	a.push_back(5);

	a.insert_in_sorted_list(1); 
	a.insert_in_sorted_list(3); 
	a.insert_in_sorted_list(5); 

	ASSERT_EQ(a.size(), 7);
	auto it = a.begin();
	
	ASSERT_EQ(*it, 1);
	++it;
	ASSERT_EQ(*it, 1);
	++it;
	ASSERT_EQ(*it, 3);
	++it;
	ASSERT_EQ(*it, 3);
	++it;
	ASSERT_EQ(*it, 3);
	++it;
	ASSERT_EQ(*it, 5);
	++it;
	ASSERT_EQ(*it, 5);
}