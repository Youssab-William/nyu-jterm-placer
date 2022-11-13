#include "controlswidget.h"

#include <QLabel>

ControlsWidget::ControlsWidget(QWidget *parent)
	: QWidget{parent} {
	layout = new QGridLayout(this);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(5);

	file_prompts[0] = new FilePrompt("upload preferences:");
	file_prompts[1] = new FilePrompt("upload courses:");
	file_prompts[2] = new FilePrompt("export students:");
	file_prompts[3] = new FilePrompt("export courses:");

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			layout->addWidget(file_prompts[2 * j + i], i, j);
		}
	}

	match_button = new QPushButton("Match");
	match_button->setMinimumSize(75, 100);
	layout->addWidget(match_button, 10, 0);

	export_button = new QPushButton("Export");
	export_button->setMinimumSize(75, 100);
	layout->addWidget(export_button, 10, 1);
}
