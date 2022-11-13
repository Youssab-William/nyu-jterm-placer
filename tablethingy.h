#ifndef TABLETHINGY_H
#define TABLETHINGY_H

#include <cstring>
#include <QWidget>
#include <QTableWidget>

class TableThingy
{
public:
    QWidget *parent;
    QTableWidget *table;
    int r, c;
    TableThingy(int r, int c, QString ***data, QWidget *parent = nullptr);
    ~TableThingy();
    void toggleVisibility();
};

#endif // TABLETHINGY_H
