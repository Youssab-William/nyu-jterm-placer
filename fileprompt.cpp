#include "fileprompt.h"

FilePrompt::FilePrompt(QString label_text, QWidget *parent)
    : QWidget{parent}
{
	layout = new QHBoxLayout(this);

	label = new QLabel(label_text);
	layout->addWidget(label);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(5);

	button = new QPushButton(default_button_text);
	layout->addWidget(button);
}
