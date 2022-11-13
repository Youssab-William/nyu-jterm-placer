#include "student.h"
#include "course.h"

#include <string>
#include <vector>

#ifndef DATAREADER_H 
#define DATAREADER_H 

class DataReader {
	int choice_count = 6;
	std::vector<Student> *students = nullptr;
	std::vector<Course> *courses = nullptr;

	public:
		DataReader(std::vector<Student> *_students, std::vector<Course> *_courses);

		void read_students(std::string students_path);
		void read_courses(std::string students_path);
};

#endif
