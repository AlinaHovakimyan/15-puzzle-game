#include "field.h"
#include <time.h>
#include <iostream>

void Field::initNew()
{
    m_field.clear();
    srand(time(0));
    for (int i = 0; i < SIZE; ++i)
    {
        m_field.push_back(i + 1);
    }
    m_field[15] = -1;
    std::random_shuffle(m_field.begin(), m_field.end());
    int i;
    for (i = 0; (i < SIZE) && (m_field[i] != -1); ++i)
    {
    }
    m_emptyIndex = i;
}

void Field::initField(std::vector<int> &fields)
{
    m_field.clear();
    for (int i = 0; i < SIZE; ++i)
    {
        m_field.push_back(fields[i]);
    }
}

std::vector<int>& Field::getField()
{
    return m_field;
}

void Field::swapHelper(int row, int col, Direction dir)
{
    int cur = 4 * row + col;
    int toSwap = 0;
    switch (dir) {
    case lft:
        if (col - 1 >= 0) {
            toSwap = 4 * row + col - 1;
            std::swap(m_field[cur], m_field[toSwap]);
        }
        break;
    case rght:
        if (col + 1 <= 3) {
            toSwap = 4 * row + col + 1;
            std::swap(m_field[cur], m_field[toSwap]);
        }
        break;
    case up:
        if (row - 1 >= 0) {
            toSwap = 4 * (row - 1) + col;
            std::swap(m_field[cur], m_field[toSwap]);
        }
        break;
    case down:
        if (row + 1 <= 3) {
            toSwap = 4 * (row + 1) + col;
            std::swap(m_field[cur], m_field[toSwap]);
        }
        break;
    default:
        break;
    }
}

void Field::swap(Direction dir)
{
    swapHelper(m_emptyIndex/4, m_emptyIndex%4, dir);
}

bool Field::win() const
{
    for (int i = 0; i < SIZE-1; i++)
    {
        if (m_field[i] != i+1) return false;
    }
    return true;
}

void Field::setEmptyLabel(int index)
{
    m_emptyIndex = index;
}

// A utility function to count inversions in fields
// Note that this function can be
// optimized to work in O(n Log n) time. The idea
// here is to keep code small and simple.
int Field::getInvCount()
{
    int inv_count = 0;
    for (int i = 0; i < (N * N - 1); ++i)
    {
        if (m_field[i] == 1) {
             m_oneIndex = i;
        } else if (m_field[i] == 2) {
            m_twoIndex = i;
        }
        for (int j = i + 1; j < N * N; ++j)
        {
            // count pairs(i, j) such that i appears
            // before j, but i > j.
            if ((m_field[i] != -1) && (m_field[i] > m_field[j]) && m_field[j] != -1)
                ++inv_count;
        }
    }
    return inv_count;
}

void Field::createSolvablePuzzle()
{
        // Count inversions in given puzzle
        int invCount = getInvCount();
        int index = N - m_emptyIndex / 4 ;
        if (index & 1) {
            if (invCount & 1) {
                m_field[m_oneIndex] = 2;
                m_field[m_twoIndex] = 1;
            }
        }
        else {
            if ((invCount & 1) == false) {
                m_field[m_oneIndex] = 2;
                m_field[m_twoIndex] = 1;
            }
        }
}

Field::Field()
{
    initNew();
}

Field::~Field()
{
}
