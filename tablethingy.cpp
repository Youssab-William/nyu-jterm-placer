#include "tablethingy.h"

TableThingy::TableThingy(int r, int c, QString ***data, QWidget *parent)
{
    this->parent = parent;
    this->r = r;
    this->c = c;
    this->table = new QTableWidget(r, c, parent);
    for(int i = 0; i < this->r; ++i){
        for(int j = 0; j < this->c; ++j){
            QTableWidgetItem *newItem = new QTableWidgetItem();
//            newItem->setData(Qt::DisplayRole, data[i][j]);
            newItem->setText(*data[i][j]);
//            if(i == 0){
//                this->table->setHorizontalHeaderItem(j, newItem);
//            }
//            else{
//            }
            this->table->setItem(i, j, newItem);
        }
    }
}

TableThingy::~TableThingy(){
    for(int i = 0; i < this->r; ++i){
        for(int j = 0; j < this->c; ++j){
            delete this->table->item(i, j);
        }
    }
    delete this->table;
}

void TableThingy::toggleVisibility(){
    this->table->setVisible(this->table->isVisible());
}
/* Tabs code:
    QTabWidget *tabs = new QTabWidget(&W);
    tabs->setGeometry(QRect(QPoint(0, 50), QSize(500, 500)));

    TableThingy *tb = new TableThingy(r, c, array, &W);
    tb->table->setGeometry(QRect(QPoint(0, 50), QSize(500, 500)));

    TableThingy *tb2 = new TableThingy(r-2, c-2, array, &W);
    tb2->table->setGeometry(QRect(QPoint(0, 50), QSize(500, 500)));

    std::string tab1 = "Students";
    tabs->addTab(tb->table, *new QString(tab1.c_str()));
    std::string tab2 = "Courses";
    tabs->addTab(tb2->table, *new QString(tab2.c_str()));
*/
