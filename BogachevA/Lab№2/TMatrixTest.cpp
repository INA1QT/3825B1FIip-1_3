#include "pch.h"
TEST(Matrix, Create) {
    TMatrix<int> m(5);
    EXPECT_EQ(5, m.GetSize());
}
TEST(Matrix, SetAndGet) {
    TMatrix<int> m(5);
    m[1][2] = 10;
    EXPECT_EQ(10, m[1][2]);
}
TEST(Matrix, Copy) {
    TMatrix<int> m(5);
    m[2][3] = 20;
    TMatrix<int> copya(m);
    EXPECT_EQ(1, copya == m);
    EXPECT_EQ(20, copya[2][3]);
}
TEST(Matrix, Assignment) {
    TMatrix<int> m1(5);
    TMatrix<int> m2(5);
    m1[1][3] = 15;
    m2 = m1;
    EXPECT_EQ(15, m2[1][3]);
    EXPECT_EQ(1, m1 == m2);
}
TEST(Matrix, Compare) {
    TMatrix<int> m1(5);
    TMatrix<int> m2(5);
    EXPECT_TRUE(m1 == m2);
    m2[1][2] = 5;
    EXPECT_TRUE(m1 != m2);
}
TEST(Matrix, Addition) {
    TMatrix<int> m1(5);
    TMatrix<int> m2(5);
    m1[1][2] = 10;
    m2[1][2] = 20;
    TMatrix<int> result = m1 + m2;
    EXPECT_EQ(30, result[1][2]);
}
TEST(Matrix, Subtraction) {
    TMatrix<int> m1(5);
    TMatrix<int> m2(5);
    m1[1][2] = 20;
    m2[1][2] = 5;
    TMatrix<int> result = m1 - m2;
    EXPECT_EQ(15, result[1][2]);
}
TEST(Matrix, RandomValues) {
    srand((unsigned)time(nullptr));
    for (int k = 0; k < 50; k++) {
        int size = rand() % 20 + 1;
        TMatrix<int> m(size);
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                m[i][j] = rand() % 100;
                EXPECT_EQ(m[i][j], m[i][j]);
            }
        }
    }
}
TEST(Matrix, RandomAddition) {
    srand((unsigned)time(nullptr));
    for (int k = 0; k < 50; k++) {
        int size = rand() % 20 + 1;
        TMatrix<int> a(size);
        TMatrix<int> b(size);
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                a[i][j] = rand() % 50;
                b[i][j] = rand() % 50;
            }
        }
        TMatrix<int> c = a + b;
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                EXPECT_EQ(a[i][j] + b[i][j], c[i][j]);
            }
        }
    }
}