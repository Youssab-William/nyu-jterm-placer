#include "controlswidget.h"
#include "fileprompt.h"
#include "datareader.h"
#include "datawriter.h"
#include "student.h"
#include "course.h"

#include <vector>

#include <QApplication>
#include <QPushButton>
#include <QGridLayout>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	std::vector<Student> *students = new std::vector<Student>;
	std::vector<Course> *courses = new std::vector<Course>;

	DataReader reader(students, courses);
	DataWriter writer;

	QWidget *window = new QWidget;
	ControlsWidget *controls = new ControlsWidget;

	QGridLayout *layout = new QGridLayout(window);
	layout->addWidget(controls, 0, 0, 1, 2);

	QObject::connect(controls->file_prompts[0], &FilePrompt::file_changed, [&]() {
			reader.read_students(controls->file_prompts[0]->file_path.toStdString().c_str());
			// redisplay grid
			});

	QObject::connect(controls->file_prompts[1], &FilePrompt::file_changed, [&]() {
			reader.read_courses(controls->file_prompts[1]->file_path.toStdString().c_str());
			// redisplay grid
			});

	QObject::connect(controls->file_prompts[2], &FilePrompt::file_changed, [&]() {
			writer.students_path = controls->file_prompts[2]->file_path.toStdString().c_str();
			});

	QObject::connect(controls->file_prompts[3], &FilePrompt::file_changed, [&]() {
			writer.courses_path = controls->file_prompts[3]->file_path.toStdString().c_str();
			});

	window->show();
	return app.exec();
}
