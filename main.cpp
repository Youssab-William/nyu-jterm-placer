#include "controlswidget.h"
#include "fileprompt.h"
#include "datareader.h"
#include "datawriter.h"
#include "matcher.h"
#include "student.h"
#include "course.h"
#include "tablethingy.h"
#include "tabholder.h"

#include <vector>

#include <QApplication>
#include <QPushButton>
#include <QGridLayout>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	std::vector<Student> *students = new std::vector<Student>;
	std::vector<Course> *courses = new std::vector<Course>;

	DataReader reader(students, courses);
	DataWriter writer(students, courses);

	QWidget *window = new QWidget;
	ControlsWidget *controls = new ControlsWidget;

    QGridLayout *layout = new QGridLayout(window);
    layout->addWidget(controls, 0, 0, 1, 2);

    QString ***array;
    int r = 5, c = 9;
    array = new QString **[r];
    for(int i = 0; i < r; i++){
        array[i] = new QString*[c];
        for(int j = 0; j < c; ++j){
            std::string s = " ";
            array[i][j] = new QString(s.c_str());
        }
    }

    TabHolder *tabs = new TabHolder(window);

    TableThingy *tb = new TableThingy(r, c, array, window);

    TableThingy *tb2 = new TableThingy(r-2, c-2, array, window);

    tabs->addTable(tb, (std::string)"Students");
    tabs->addTable(tb2, (std::string)"Courses");

    layout->addWidget(tabs->tabs, 1, 0, 2, 2);

	// connect the file upload buttons
	QObject::connect(controls->file_prompts[0], &FilePrompt::file_changed, [&]() {
			reader.read_students(controls->file_prompts[0]->file_path.toStdString().c_str());
            // redisplay grid
			});

	QObject::connect(controls->file_prompts[1], &FilePrompt::file_changed, [&]() {
			reader.read_courses(controls->file_prompts[1]->file_path.toStdString().c_str());
            // redisplay grid
			});

	// connect the file export buttons
	QObject::connect(controls->file_prompts[2], &FilePrompt::file_changed, [&]() {
			writer.students_path = controls->file_prompts[2]->file_path.toStdString().c_str();
			});

	QObject::connect(controls->file_prompts[3], &FilePrompt::file_changed, [&]() {
			writer.courses_path = controls->file_prompts[3]->file_path.toStdString().c_str();
			});

	// connect the match button
	Matcher matcher;
	QObject::connect(controls->match_button, &QPushButton::clicked, [&]() {
			matcher.match(*students, *courses);
            // redisplay grid
			});

	// connect the export button
	QObject::connect(controls->export_button, &QPushButton::clicked, [&]() {
			writer.write_students();
			writer.write_courses();
			});

	window->show();
	return app.exec();
}
