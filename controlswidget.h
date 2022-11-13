#ifndef CONTROLSWIDGET_H
#define CONTROLSWIDGET_H

#include "fileprompt.h"

#include <QWidget>
#include <QGridLayout>

class ControlsWidget : public QWidget {
	Q_OBJECT;

	QGridLayout *layout;

	public:
		FilePrompt *file_prompts[4];
		QPushButton *match_button;
		QPushButton *export_button;

		explicit ControlsWidget(QWidget *parent = nullptr);

	signals:
};

#endif // CONTROLSWIDGET_H
