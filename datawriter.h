#include "student.h"
#include "course.h"

#include <string>
#include <vector>

#ifndef DATAWRITER_H 
#define DATAWRITER_H 

class DataWriter {
	std::vector<Student> *students = nullptr;
	std::vector<Course> *courses = nullptr;

	public:
		std::string students_path = "";
		std::string courses_path = "";

		DataWriter(std::vector<Student> *_students, std::vector<Course> *_courses);

		void write_students();
		void write_courses();
};

#endif
