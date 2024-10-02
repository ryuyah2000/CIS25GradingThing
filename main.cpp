// gradebook implementation
// code by Ryuya

#include <iostream>

// gets highest grade (requires grades and array size as input)
int getHighestGrade(int (&grades)[], int arraySize) {
    int highest = grades[0];
    for (int i = 0; i < arraySize; ++i) {
        if (grades[i] > highest) {
            highest = grades[i];
        }
    }
    return highest;
}

// gets lowest grade (requires grades and array size as input)
int getLowestGrade(int (&grades)[], int arraySize) {
    int lowest = grades[0];
    for (int i = 0; i < arraySize; ++i) {
        if (grades[i] < lowest) {
            lowest = grades[i];
        }
    }
    return lowest;
}

// gets average grade (requires grades and array size as input)
double getAverageGrade(int (&grades)[], int arraySize) {
    double avg = 0;
    for (int i = 0; i < arraySize; ++i) {
        avg += grades[i];
    }
    return avg / arraySize;
}

// returns number of students above average grade (requires grades and array size as input)
// puts the indices of students in studentIndices (second input array)
int getStudentsAboveAverage(int (&grades)[], int (&studentIndices)[], int arraySize) {
    double avg = getAverageGrade(grades, arraySize);
    int studentCount = 0;
    for (int i = 0; i < arraySize; ++i) {
        if (grades[i] > avg) {
            studentIndices[studentCount++] = i;
        }
    }
    return studentCount;
}

// compares 2 students (requires student indices and grades)
// returns the student index who has the higher grade
int compareStudents(int studentIndex1, int studentIndex2, int (&grades)[]) {
    return grades[studentIndex1] > grades[studentIndex2] ? studentIndex1 : studentIndex2;
}

// changes grade of a student
// requires grade array and student index and the new grade value
void changeGrade(int (&grades)[], int index, int newValue) {
    grades[index] = newValue;
}


int main() {
    
    // test cases
    std::string names[5] = {
        "joe", "donald", "scrooge", "ben", "quincy"
    };
    
    int grades[5] = {
        50, 90, 60, 33, 25
    };
    
    std::cout << "getHighestGrade(): " << getHighestGrade(grades, 5) << std::endl;
    std::cout << "getLowestGrade():  " << getLowestGrade(grades, 5) << std::endl;
    std::cout << "getAverageGrade(): " << getAverageGrade(grades, 5) << std::endl;
    int studentsAboveAverage[5];
    int arraySize = getStudentsAboveAverage(grades, studentsAboveAverage, 5);
    std::cout << "getStudentsAboveAverage(): " << std::endl;
    for (int i = 0; i < arraySize; ++i) {
        std::cout << names[studentsAboveAverage[i]] << " with grade " << grades[studentsAboveAverage[i]] << std::endl;
    }
    std::cout << "Changing scrooge's grade to 30" << std::endl;
    changeGrade(grades, 2, 30);
    std::cout << "changeGrade(): " << names[2] << "'s new grade is " << grades[2] << std::endl;
    
    std::cout << std::endl << "testing functions with changed data" << std::endl << std::endl;
    
    std::cout << "getHighestGrade(): " << getHighestGrade(grades, 5) << std::endl;
    std::cout << "getLowestGrade():  " << getLowestGrade(grades, 5) << std::endl;
    std::cout << "getAverageGrade(): " << getAverageGrade(grades, 5) << std::endl;
    arraySize = getStudentsAboveAverage(grades, studentsAboveAverage, 5);
    std::cout << "getStudentsAboveAverage(): " << std::endl;
    for (int i = 0; i < arraySize; ++i) {
        std::cout << names[studentsAboveAverage[i]] << " with grade " << grades[studentsAboveAverage[i]] << std::endl;
    }

    return 0;
}
