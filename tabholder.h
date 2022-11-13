#ifndef TABHOLDER_H
#define TABHOLDER_H

#include<QTabWidget>
#include "tablethingy.h"

class TabHolder
{
public:
    QTabWidget *tabs;
    TabHolder(QWidget *parent = nullptr);
    void addTable(TableThingy *tb, std::string label);
};

#endif // TABHOLDER_H
