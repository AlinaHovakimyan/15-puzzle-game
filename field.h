#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <algorithm>

#define N 4

enum Direction
{
    lft,
    rght,
    up,
    down
};

class Field
{
private:
    std::vector<int> m_field;
    int m_emptyIndex;
    int m_emptyX;
    int m_oneIndex;
    int m_twoIndex;
    void swapHelper(int row, int col,Direction dir);
public:
    Field();
    ~Field();
    void initNew();
    void initField(std::vector<int>& fields);
    std::vector<int>& getField();
    int getInvCount();
    void createSolvablePuzzle();

    static const int SIZE = 16;

    void setEmptyLabel(int index);
    void swap(Direction dir);
    bool win() const;

};

#endif // FIELD_H
