#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000; 

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    /* TODO */
    students[num_of_students] = Student(name, last_student_id, midterm, final);
    num_of_students++;
}

void StudentManager::deleteStudent(int id) {
    /* TODO */
    int idx = findStudentByID(id);
    if (idx > -1) {
        students[idx].~Student();
        for (int i = idx; i < num_of_students - 1; i++)
        {
            students[i] = students[i + 1];
        }
        num_of_students--;
    }
}

void StudentManager::modifyStudent(const Student& student) {
    /* TODO */
    int idx = findStudentByID(student.getID());
    if (idx > -1 ) {
        students[idx] = student;
    }
}

int StudentManager::findStudentByID(int id) const {
    /* TODO */
    for (int i = 0; i < num_of_students; i++)
    {
        if (students[i].getID() == id) {
            return i;
        }
    }
    
    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    /* TODO */
    float max = 0;
    int idx;
    for (int i = 0; i < num_of_students; i++)
    {
        if (max < students[i].getRecord().getMidterm()) {
            max =  students[i].getRecord().getMidterm();
            idx = i;
        }
    }
    
    return idx;
}

int StudentManager::findBestStudentInFinal() const {
    /* TODO */
    float max = 0;
    int idx;
    for (int i = 0; i < num_of_students; i++)
    {
        if (max < students[i].getRecord().getFinal()) {
            max =  students[i].getRecord().getFinal();
            idx = i;
        }
    }
    
    return idx;
}

int StudentManager::findBestStudent() const {
    /* TODO */
    float max = 0;
    int id;
    for (int i = 0; i < num_of_students; i++)
    {
        if (max < students[i].getRecord().getTotal()) {
            max =  students[i].getRecord().getTotal();
            id = students[i].getID();
        }
    }
    
    return id;
}

float StudentManager::getMidtermAverage() const {
    /* TODO */
    float sum = 0;
    for (int i = 0; i < num_of_students; i++)
    {
        sum += students[i].getRecord().getMidterm();
    }
    
    return sum / num_of_students;
}

float StudentManager::getFinalAverage() const {
    /* TODO */
    float sum = 0;
    for (int i = 0; i < num_of_students; i++)
    {
        sum += students[i].getRecord().getFinal();
    }
    
    return sum / num_of_students;
}

float StudentManager::getTotalAverage() const {
    /* TODO */
    float sum = 0;
    for (int i = 0; i < num_of_students; i++)
    {
        sum += students[i].getRecord().getTotal();
    }
    
    return sum / num_of_students;
}

