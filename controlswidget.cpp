#include "controlswidget.h"

#include <QLabel>

ControlsWidget::ControlsWidget(QWidget *parent)
	: QWidget{parent}
{
	layout = new QGridLayout(this);
	static int margins = 0;
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(5);
	file_prompts[0] = new FilePrompt("upload prefrences:");
	file_prompts[1] = new FilePrompt("upload courses:");
	file_prompts[2] = new FilePrompt("export students:");
	file_prompts[3] = new FilePrompt("export courses:");

	for (int i = 0; i < 4; i++) {
		file_prompts[i]->setContentsMargins(0, 0, 0, 0);
	}


	layout->addWidget(file_prompts[0], 0, 0);
	layout->addWidget(file_prompts[1], 1, 0);
	layout->addWidget(file_prompts[2], 0, 1);
	layout->addWidget(file_prompts[3], 1, 1);
}
