#include "mainwindow.h"
#include "controlswidget.h"

#include <QApplication>
#include <QPushButton>
#include <QGridLayout>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QWidget *window = new QWidget;
	ControlsWidget *controls = new ControlsWidget;
	QPushButton *button3 = new QPushButton("Three");
	QPushButton *button4 = new QPushButton("Four");
	QPushButton *button5 = new QPushButton("Five");

	QGridLayout *layout = new QGridLayout(window);
	layout->addWidget(controls, 0, 0, 1, 2);
	layout->addWidget(button3, 1, 0, 1, 2);
	layout->addWidget(button4, 2, 0);
	layout->addWidget(button5, 2, 1);

	window->show();
	return app.exec();
}
