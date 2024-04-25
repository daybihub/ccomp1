// Fig. 7.13: GradeBook.h
// Definición de la clase GradeBook que utiliza un arreglo bidimensional para almacenar las notas de los exámenes.
#include <array>
#include <string>
#include <iostream>
#include <iomanip> // manipuladores de flujo parametrizados

// Definición de la clase GradeBook
class GradeBook {
public:
    // número constante de estudiantes que tomaron la prueba
    static const size_t students{10}; // datos públicos

    // constructor que inicializa courseName y el arreglo de notas
    GradeBook(const std::string& name, 
            std::array<std::array<int, tests>, students>& gradesArray)
        : courseName(name), grades(gradesArray) {
    }

    // función para establecer el nombre del curso
    void setCourseName(const std::string& name) {
        courseName = name; // almacena el nombre del curso
    }

    // función para obtener el nombre del curso
    const std::string& getCourseName() const {
        return courseName;
    }

    // muestra un mensaje de bienvenida al usuario de GradeBook
    void displayMessage() const {
        // llama a getCourseName para obtener el nombre del curso de este GradeBook
        std::cout << "Bienvenido al libro de notas para\n" << getCourseName()
                << "!" << std::endl;
    }

    // realiza varias operaciones en los datos
    void processGrades() const {
        outputGrades(); // muestra el arreglo de notas

        // llama a las funciones getMinimum y getMaximum
        std::cout << "\nLa nota más baja es " << getMinimum()
                << "\nLa nota más alta es " << getMaximum() << std::endl;

        outputBarChart(); // muestra el gráfico de distribución de notas
    }

    // encuentra la nota mínima
    int getMinimum() const {
        int lowGrade{100}; // asume que la nota más baja es 100

        // recorre las filas del arreglo de notas
        for (const auto& student : grades) {
            // recorre las columnas de la fila actual
            for (const auto& grade : student) {
                if (grade < lowGrade) {
                    lowGrade = grade; // nueva nota más baja
                }
            }
        }

        return lowGrade; // devuelve la nota más baja
    }

    // encuentra la nota máxima
    int getMaximum() const {
        int highGrade{0}; // asume que la nota más alta es 0

        // recorre las filas del arreglo de notas
        for (const auto& student : grades) {
            // recorre las columnas de la fila actual
            for (const auto& grade : student) {
                if (grade > highGrade) {
                    highGrade = grade; // nueva nota más alta
                }
            }
        }

        return highGrade; // devuelve la nota más alta
    }

    // determina el promedio de notas para un examen
    double getAverage(const std::array<int, tests>& testScores) const {
        int total{0}; // inicializa el total

        // suma las notas en el arreglo
        for (int score : testScores) {
            total += score;
        }

        // devuelve el promedio de notas
        return static_cast<double>(total) / testScores.size();
    }

    // muestra un gráfico de barras que representa la distribución de notas
    void outputBarChart() const {
        std::cout << "\nDistribución de notas:" << std::endl;

        // almacena la frecuencia de notas en cada rango de 10 notas
        std::array<unsigned int, frequencySize> frequency{}; // inicializa a ceros

        // para cada nota, incrementa la frecuencia apropiada
        for (const auto& student : grades) {
            for (const auto& test : student) {
                ++frequency[test / 10];
            }
        }

        // para cada frecuencia de notas, imprime una barra en el gráfico
        for (size_t count = 0; count < frequencySize; ++count) {
            // imprime las etiquetas de las barras
            if (count == 0) {
                std::cout << "  0-9: ";
            } else if (count == 10) {
                std::cout << "  100: ";
            } else {
                std::cout << count * 10 << "-" << (count * 10 + 9) << ": ";
            }

            // imprime la barra de asteriscos
            for (unsigned int stars = 0; stars < frequency[count]; ++stars) {
                std::cout << '*';
            }

            std::cout << std::endl;
        }
    }

    // muestra el contenido del arreglo de notas
    void outputGrades() const {
        std::cout << "\nLas notas son:\n\n";
        
        // crea un encabezado de columna para cada prueba
        for (size_t test = 0; test < tests; ++test) {
            std::cout << "Prueba " << test + 1 << " ";
        }

        std::cout << "Promedio" << std::endl;

        // crea filas/columnas con las notas del arreglo
        for (size_t student = 0; student < grades.size(); ++student) {
            std::cout << "Estudiante " << std::setw(2) << student + 1 << " ";

            // muestra las notas del estudiante
            for (size_t test = 0; test < grades[student].size(); ++test) {
                std::cout << std::setw(8) << grades[student][test];
            }

            // llama a getAverage para calcular el promedio del estudiante y muestra el resultado
            double average = getAverage(grades[student]);
            std::cout << std::setw(9) << std::setprecision(2) << std::fixed
                    << average << std::endl;
        }
    }

private:
    std::string courseName; // nombre del curso de este libro de notas
    std::array<std::array<int, tests>, students> grades; // arreglo bidimensional de notas de los estudiantes
};