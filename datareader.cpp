#include "datareader.h"
#include "qxlsx.h"

#include <QDebug>

DataReader::DataReader(std::vector<Student> *_students, std::vector<Course> *_courses) {
    students = _students;
    courses = _courses;
}

void DataReader::read_students(std::string students_path) {
	// QXlsx::Document xlsx;
	// xlsx.write("A1", "Hello Qt!"); // write "Hello Qt!" to cell(A,1). it's shared string.
	// xlsx.saveAs("Test.xlsx"); // save the document as 'Test.xlsx'
}

void DataReader::read_courses(std::string students_path) {

}
