#include "pch.h"
TEST(Vector, Create) {
    TVector<int> v(5);
    EXPECT_EQ(5, v.GetSize());
}
TEST(Vector, SetAndGet) {
    TVector<int> v(5);
    v[2] = 10;
    EXPECT_EQ(10, v[2]);
}
TEST(Vector, Copy) {
    TVector<int> v(5);
    v[1] = 20;
    TVector<int> copy(v);
    EXPECT_EQ(1, copy == v);
    EXPECT_EQ(20, copy[1]);
}
TEST(Vector, Assignment) {
    TVector<int> v1(5);
    TVector<int> v2(5);
    v1[3] = 15;
    v2 = v1;
    EXPECT_EQ(15, v2[3]);
    EXPECT_EQ(1, v1 == v2);
}
TEST(Vector, Compare) {
    TVector<int> v1(5);
    TVector<int> v2(5);
    EXPECT_TRUE(v1 == v2);
    v2[0] = 5;
    EXPECT_TRUE(v1 != v2);
}
TEST(Vector, AddScalar) {
    TVector<int> v(5);
    v[0] = 10;
    TVector<int> result = v + 5;
    EXPECT_EQ(15, result[0]);
}
TEST(Vector, SubtractScalar) {
    TVector<int> v(5);
    v[0] = 10;
    TVector<int> result = v - 5;
    EXPECT_EQ(5, result[0]);
}
TEST(Vector, MultiplyScalar) {
    TVector<int> v(5);
    v[0] = 10;
    TVector<int> result = v * 2;
    EXPECT_EQ(20, result[0]);
}
TEST(Vector, AddVectors) {
    TVector<int> v1(5);
    TVector<int> v2(5);
    v1[0] = 10;
    v2[0] = 20;
    TVector<int> result = v1 + v2;
    EXPECT_EQ(30, result[0]);
}
TEST(Vector, SubtractVectors) {
    TVector<int> v1(5);
    TVector<int> v2(5);
    v1[0] = 20;
    v2[0] = 10;
    TVector<int> result = v1 - v2;
    EXPECT_EQ(10, result[0]);
}
TEST(Vector, DotProduct) {
    TVector<int> v1(3);
    TVector<int> v2(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    v2[0] = 4;
    v2[1] = 5;
    v2[2] = 6;
    EXPECT_EQ(32, v1 * v2);
}
TEST(Vector, RandomValues) {
    srand((unsigned)time(nullptr));
    for (int k = 0; k < 50; k++) {
        int size = rand() % 20 + 1;
        TVector<int> v(size);
        for (int i = 0; i < size; i++) {
            int value = rand() % 100;
            v[i] = value;
            EXPECT_EQ(value, v[i]);
        }
    }
}
TEST(Vector, RandomAddition) {
    srand((unsigned)time(nullptr));
    for (int k = 0; k < 50; k++) {
        int size = rand() % 20 + 1;
        TVector<int> a(size);
        TVector<int> b(size);
        for (int i = 0; i < size; i++) {
            a[i] = rand() % 50;
            b[i] = rand() % 50;
        }
        TVector<int> c = a + b;
        for (int i = 0; i < size; i++) {
            EXPECT_EQ(a[i] + b[i], c[i]);
        }
    }
}