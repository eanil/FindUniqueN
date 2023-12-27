#include "../src/FindUniqueMax.h"

#include <sstream>
#include <iostream>

#include "gtest/gtest.h"

const char *kTestData = "1426828011 9\n1426828028 350\n1426828037 25\n1426828056 231\n1426828058 109\n1426828066 111";
const char *kTestDataRepeating = "1426828011 9\n1426828028 350\n1426828037 25\n1426828056 231\n1426828058 109\n1426828066 111\n1426828028 350";

TEST(FindUniqueMaxTest, FindUniqueMax_EmptyStream)
{
    std::istream dataStream({});
    EXPECT_NO_THROW(
        std::vector<std::string> res = FindUniqueMaxN(dataStream, 2));
}

TEST(FindUniqueMaxTest, FindUniqueMax_TestStream)
{
    std::istringstream s1(kTestData);
    std::istream dataStream(s1.rdbuf());
    std::vector<std::string> res;

    EXPECT_NO_THROW(res = FindUniqueMaxN(dataStream, 2));

    EXPECT_EQ(res.size(), 2);
    EXPECT_EQ(res[0], "1426828056"); // 231
    EXPECT_EQ(res[1], "1426828028"); // 350
}

TEST(FindUniqueMaxTest, FindUniqueMax_RepeatingIds2)
{
    std::istringstream s1(kTestDataRepeating);
    std::istream dataStream(s1.rdbuf());
    std::vector<std::string> res;

    EXPECT_NO_THROW(res = FindUniqueMaxN(dataStream, 2));

    EXPECT_EQ(res.size(), 2);
    EXPECT_EQ(res[0], "1426828028"); // 350
    EXPECT_EQ(res[1], "1426828028"); // 350
}

TEST(FindUniqueMaxTest, FindUniqueMax_RepeatingIds3)
{
    std::istringstream s1(kTestDataRepeating);
    std::istream dataStream(s1.rdbuf());
    std::vector<std::string> res;

    EXPECT_NO_THROW(res = FindUniqueMaxN(dataStream, 3));
    
    EXPECT_EQ(res[0], "1426828056"); // 231
    EXPECT_EQ(res[1], "1426828028"); // 231
    EXPECT_EQ(res[2], "1426828028"); // 350
}

TEST(FindUniqueMaxTest, FindUniqueMax_LargeN)
{
    std::istringstream s1(kTestData);
    std::istream dataStream(s1.rdbuf());
    std::vector<std::string> res;

    EXPECT_NO_THROW(res = FindUniqueMaxN(dataStream, 100000));

    // the result cannot be larger than the stream.
    EXPECT_EQ(res.size(), 6);
    EXPECT_EQ(res[0], "1426828011"); // 9
    EXPECT_EQ(res[5], "1426828028"); // 350
}

// Second solution

TEST(FindUniqueMaxTest, FindUniqueMaxN2_TestStream)
{
    std::istringstream s1(kTestData);
    std::istream dataStream(s1.rdbuf());
    std::vector<std::string> res;

    EXPECT_NO_THROW(res = FindUniqueMaxN2(dataStream, 2));

    EXPECT_EQ(res.size(), 2);
    EXPECT_EQ(res[0], "1426828056"); // 231
    EXPECT_EQ(res[1], "1426828028"); // 350
}

TEST(FindUniqueMaxTest, FindUniqueMaxN2_RepeatingIds2)
{
    std::istringstream s1(kTestDataRepeating);
    std::istream dataStream(s1.rdbuf());
    std::vector<std::string> res;

    EXPECT_NO_THROW(res = FindUniqueMaxN2(dataStream, 2));

    EXPECT_EQ(res.size(), 2);
    EXPECT_EQ(res[0], "1426828028"); // 350
    EXPECT_EQ(res[1], "1426828028"); // 350
}

TEST(FindUniqueMaxTest, FindUniqueMaxN2_RepeatingIds3)
{
    std::istringstream s1(kTestDataRepeating);
    std::istream dataStream(s1.rdbuf());
    std::vector<std::string> res;

    EXPECT_NO_THROW(res = FindUniqueMaxN2(dataStream, 3));
    
    EXPECT_EQ(res[0], "1426828056"); // 231
    EXPECT_EQ(res[1], "1426828028"); // 231
    EXPECT_EQ(res[2], "1426828028"); // 350
}

TEST(FindUniqueMaxTest, FindUniqueMaxN2_LargeN)
{
    std::istringstream s1(kTestData);
    std::istream dataStream(s1.rdbuf());
    std::vector<std::string> res;

    EXPECT_NO_THROW(res = FindUniqueMaxN2(dataStream, 100000));

    // the result cannot be larger than the stream.
    EXPECT_EQ(res.size(), 6);
    EXPECT_EQ(res[0], "1426828011"); // 9
    EXPECT_EQ(res[5], "1426828028"); // 350
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
