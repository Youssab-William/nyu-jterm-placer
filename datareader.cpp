#include "datareader.h"
#include "qxlsx.h"

#include <QDebug>

DataReader::DataReader(std::vector<Student> *_students, std::vector<Course> *_courses) {
    students = _students;
    courses = _courses;
}

void DataReader::read_students(std::string students_path) {
	QXlsx::Document students_doc(students_path.c_str());
	if (!students_doc.load()) return;

	int row_count = students_doc.dimension().rowCount();

	auto read_cell = [&](int rr, int cc) -> QString {
		Cell *cell = students_doc.cellAt(rr, cc);
		return cell->readValue().toString();
	};

	students->clear();
	for (int row = 1; row <= row_count; row++) {
		std::string name = read_cell(row, 1).toStdString();
		int year = read_cell(row, 2).toInt();

		std::vector<std::string> choices;
		for (int col = 3; col <= choice_count + 2; col++) {
			std::string course = read_cell(row, col).toStdString();
			choices.push_back(course);
		}

		students->emplace_back(name, year, choices);
	}

	// for (Student student : *students) {
	// 	qDebug() << "{" << student.name.c_str() << ", " << student.year << ", " << student.choices[0].c_str() << "}";
	// }
}

void DataReader::read_courses(std::string courses_path) {
	QXlsx::Document courses_doc(courses_path.c_str());
	if (!courses_doc.load()) return;

	int row_count = courses_doc.dimension().rowCount();

	auto read_cell = [&](int rr, int cc) -> QString {
		Cell *cell = courses_doc.cellAt(rr, cc);
		return cell->readValue().toString();
	};

	courses->clear();
	for (int row = 1; row <= row_count; row++) {
		std::string id = read_cell(row, 1).toStdString();
		int cap = read_cell(row, 2).toInt();
		courses->emplace_back(id, cap);
	}

	// for (Course course : *courses) {
	// 	qDebug() << "{" << course.id.c_str() << ", " << course.cap << "}";
	// }
}
