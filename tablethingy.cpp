#include "tablethingy.h"

TableThingy::TableThingy(int r, int c, QString ***data, QWidget *parent)
{
    this->parent = parent;
    this->r = r-1;
    this->c = c;
    this->table = new QTableWidget(r-1, c, parent);
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            QTableWidgetItem *newItem = new QTableWidgetItem();
//            newItem->setData(Qt::DisplayRole, data[i][j]);
            newItem->setText(*data[i][j]);
            if(i == 0){
                this->table->setHorizontalHeaderItem(j, newItem);
            }
            else{
                this->table->setItem(i-1, j, newItem);
            }
        }
    }
}

void TableThingy::toggleVisibility(){
    this->table->setVisible(this->table->isVisible());
}
