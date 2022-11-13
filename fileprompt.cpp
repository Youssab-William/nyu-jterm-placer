#include "fileprompt.h"

#include <QFileDialog>

FilePrompt::FilePrompt(QString label_text, QWidget *parent)
	: QWidget{parent} {
	layout = new QHBoxLayout(this);

	label = new QLabel(label_text);
	label->setFixedSize(150, 16);
	layout->addWidget(label);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(5);

	button = new QPushButton(default_button_text);
	layout->addWidget(button);

	QObject::connect(button, &QPushButton::clicked, [&]() {
			QUrl file_url = QFileDialog::getOpenFileUrl();
			QString file_name = file_url.fileName();
			if (file_name.toStdString() == "") return;

			button->setText(file_name);

			file_path = file_url.path();
			file_changed();
		});
}
