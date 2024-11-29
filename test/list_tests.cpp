#include "gtest.h"
#include "tlist.h"

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