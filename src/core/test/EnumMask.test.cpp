#include <aspire/core/EnumMask.h>
#include <gtest/gtest.h>

namespace
{
	enum class TestEnum : int
	{
		One = 0b0001,
		Two = 0b0010,
		Three = 0b0100
	};
}

TEST(EnumMask, constructor)
{
	aspire::core::EnumMask<TestEnum> test{TestEnum::One, TestEnum::Two, TestEnum::Three};
	EXPECT_TRUE(test.test(TestEnum::One));
	EXPECT_TRUE(test.test(TestEnum::Two));
	EXPECT_TRUE(test.test(TestEnum::Three));
}

TEST(EnumMask, set)
{
	aspire::core::EnumMask<TestEnum> test{};
	test.set(TestEnum::One);
	EXPECT_TRUE(test.test(TestEnum::One));
	EXPECT_FALSE(test.test(TestEnum::Two));
	EXPECT_FALSE(test.test(TestEnum::Three));

	test.set(TestEnum::Two);
	EXPECT_TRUE(test.test(TestEnum::One));
	EXPECT_TRUE(test.test(TestEnum::Two));
	EXPECT_FALSE(test.test(TestEnum::Three));

	test.set(TestEnum::Three);
	EXPECT_TRUE(test.test(TestEnum::One));
	EXPECT_TRUE(test.test(TestEnum::Two));
	EXPECT_TRUE(test.test(TestEnum::Three));
}

TEST(EnumMask, remove)
{
	aspire::core::EnumMask<TestEnum> test{};
	test.set(TestEnum::One);
	test.set(TestEnum::Two);
	test.set(TestEnum::Three);

	EXPECT_TRUE(test.test(TestEnum::One));
	EXPECT_TRUE(test.test(TestEnum::Two));
	EXPECT_TRUE(test.test(TestEnum::Three));

	test.remove(TestEnum::Two);

	EXPECT_TRUE(test.test(TestEnum::One));
	EXPECT_FALSE(test.test(TestEnum::Two));
	EXPECT_TRUE(test.test(TestEnum::Three));
}

TEST(EnumMask, flip)
{
	aspire::core::EnumMask<TestEnum> test{};
	EXPECT_FALSE(test.test(TestEnum::One));

	test.flip(TestEnum::One);
	EXPECT_TRUE(test.test(TestEnum::One));

	test.flip(TestEnum::One);
	EXPECT_FALSE(test.test(TestEnum::One));
}

TEST(EnumMask, clear)
{
	aspire::core::EnumMask<TestEnum> test{};
	test.set(TestEnum::One);
	test.set(TestEnum::Two);
	test.set(TestEnum::Three);

	EXPECT_TRUE(test.test(TestEnum::One));
	EXPECT_TRUE(test.test(TestEnum::Two));
	EXPECT_TRUE(test.test(TestEnum::Three));

	test.clear();

	EXPECT_FALSE(test.test(TestEnum::One));
	EXPECT_FALSE(test.test(TestEnum::Two));
	EXPECT_FALSE(test.test(TestEnum::Three));
}