#ifndef FILEPROMPT_H
#define FILEPROMPT_H

#include <QString>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

class FilePrompt : public QWidget
{
	Q_OBJECT;

	QHBoxLayout *layout;
	QLabel *label;
	QPushButton *button;

	QString default_button_text = "choose file...";

	public:
		explicit FilePrompt(QString label_text, QWidget *parent = nullptr);

	signals:

};

#endif // FILEPROMPT_H
