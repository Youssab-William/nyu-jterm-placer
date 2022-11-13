#include "datawriter.h"
#include "qxlsx.h"

#include <QDebug>

DataWriter::DataWriter(std::vector<Student> *_students, std::vector<Course> *_courses) {
    students = _students;
    courses = _courses;
}

void DataWriter::write_students() {
	qDebug() << "// write_students()";

	Document students_doc;
	for (int i = 0; i < students->size(); i++) {
		qDebug() << "// i : " << i;
		students_doc.write(i + 1, 1, ((*students)[i]).name.c_str());
		students_doc.write(i + 1, 2, ((*students)[i]).placement.c_str());
	}

	qDebug() << "// saving students at " << students_path.c_str();
	students_doc.saveAs(students_path.c_str());
}

void DataWriter::write_courses() {
	qDebug() << "// write_courses()";

	Document courses_doc;
	for (int i = 0; i < courses->size(); i++) {
		qDebug() << "// i : " << i;
		courses_doc.write(i + 1, 1, ((*courses)[i]).id.c_str());
		courses_doc.write(i + 1, 2, ((*courses)[i]).enrollment_count);
	}
	
	qDebug() << "// saving courses at " << courses_path.c_str();
	courses_doc.saveAs(courses_path.c_str());
}
