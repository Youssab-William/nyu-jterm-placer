#include "tabholder.h"

TabHolder::TabHolder(QWidget *parent)
{
    this->tabs = new QTabWidget(parent);
//    tabs->setGeometry(QRect(QPoint(0, 50), QSize(500, 500)));
    tabs->setMinimumSize(75, 100);
}

void TabHolder::addTable(TableThingy *tb, std::string label){
    QString *qs = new QString(label.c_str());
    this->tabs->addTab(tb->table, *qs);
}
