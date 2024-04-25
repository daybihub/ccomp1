// Definición de la clase GradeBook que utiliza un
// arreglo bidimensional para almacenar las calificaciones de los exámenes.
#include <array>
#include <string>
#include <iostream>
#include <iomanip> // manipuladores de flujo parametrizados

// Definición de la clase GradeBook
class GradeBook {
public:
    // constantes
    static const size_t students{10}; // número de estudiantes
    static const size_t tests{3}; // número de exámenes

    // constructor con dos argumentos inicializa courseName y el arreglo de calificaciones
    GradeBook(const std::string& name, 
            std::array<std::array<int, tests>, students>& gradesArray)
        : courseName(name), grades(gradesArray) {
    }

    // función para establecer el nombre del curso
    void setCourseName(const std::string& name) {
        courseName = name; // almacena el nombre del curso
    }

    // función para recuperar el nombre del curso
    const std::string& getCourseName() const {
        return courseName;
    }

    // muestra un mensaje de bienvenida al usuario de GradeBook
    void displayMessage() const {
        // llama a getCourseName para obtener el nombre del curso de este GradeBook
        std::cout << "Bienvenido al libro de calificaciones de\n" << getCourseName() 
                << "!" << std::endl;
    }

    // realiza varias operaciones en los datos
    void processGrades() const {
        outputGrades(); // muestra el arreglo de calificaciones

        // llama a las funciones getMinimum y getMaximum
        std::cout << "\nLa calificación más baja en el libro de calificaciones es " << getMinimum()
                << "\nLa calificación más alta en el libro de calificaciones es " << getMaximum()
                << std::endl;

        outputBarChart(); // muestra el gráfico de distribución de calificaciones
    }

    // encuentra la calificación mínima en todo el libro de calificaciones
    int getMinimum() const {
        int lowGrade{100}; // asume que la calificación más baja es 100

        // recorre las filas del arreglo de calificaciones
        for (const auto& student : grades) {
            // recorre las columnas de la fila actual
            for (const auto& grade : student) {
                if (grade < lowGrade) { // si la calificación es menor que lowGrade
                    lowGrade = grade; // la calificación es la nueva más baja
                }
            }
        }

        return lowGrade; // devuelve la calificación más baja
    }

    // encuentra la calificación máxima en todo el libro de calificaciones
    int getMaximum() const {
        int highGrade{0}; // asume que la calificación más alta es 0

        // recorre las filas del arreglo de calificaciones
        for (const auto& student : grades) {
            // recorre las columnas de la fila actual
            for (const auto& grade : student) {
                if (grade > highGrade) { // si la calificación es mayor que highGrade
                    highGrade = grade; // la calificación es la nueva más alta
                }
            }
        }

        return highGrade; // devuelve la calificación más alta
    }

    // determina la calificación promedio para un conjunto particular de calificaciones
    double getAverage(const std::array<int, tests>& setOfGrades) const {
        int total{0}; // inicializa total

        // suma las calificaciones en el arreglo
        for (int grade : setOfGrades) {
            total += grade;
        }

        // devuelve el promedio de calificaciones
        return static_cast<double>(total) / setOfGrades.size();
    }

    // muestra un gráfico de barras que muestra la distribución de las calificaciones
    void outputBarChart() const {
        std::cout << "\nDistribución general de las calificaciones:" << std::endl;

        // almacena la frecuencia de las calificaciones en cada rango de 10 calificaciones
        const size_t frequencySize{11};
        std::array<unsigned int, frequencySize> frequency{}; // inicializa a 0s

        // para cada calificación, incrementa la frecuencia apropiada
        for (const auto& student : grades) {
            for (const auto& test : student) {
                ++frequency[test / 10];
            }
        }

        // para cada frecuencia de calificación, imprime una barra en el gráfico
        for (size_t count{0}; count < frequencySize; ++count) {
            // imprime la etiqueta de la barra ("0-9:", ..., "90-99:", "100:")
            if (0 == count) {
                std::cout << "  0-9: ";
            }
            else if (10 == count) {
                std::cout << "  100: ";
            }
            else {
                std::cout << count * 10 << "-" << (count * 10) + 9 << ": ";
            }

            // imprime una barra de asteriscos
            for (unsigned int stars{0}; stars < frequency[count]; ++stars) {
                std::cout << '*';
            }

            std::cout << std::endl; // comienza una nueva línea de salida
        }
    }

    // muestra el contenido del arreglo de calificaciones
    void outputGrades() const {
        std::cout << "\nLas calificaciones son:\n\n";
        std::cout << "            "; // alinea las cabeceras de columna

        // crea un encabezado de columna para cada uno de los exámenes
        for (size_t test{0}; test < tests; ++test) {
            std::cout << "Prueba " << test + 1 << "  ";
        }

        std::cout << "Promedio" << std::endl;

        // crea filas/columnas de texto que representan las calificaciones del arreglo
        for (size_t student{0}; student < grades.size(); ++student) {
            std::cout << "Estudiante " << std::setw(2) << student + 1;

            // muestra las calificaciones del estudiante
            for (size_t test{0}; test < grades[student].size(); ++test) {
                std::cout << std::setw(8) << grades[student][test];
            }

            // llama a la función miembro getAverage para calcular el promedio del estudiante
            // pasa una fila de calificaciones como argumento
            double average{getAverage(grades[student])};
            std::cout << std::setw(9) << std::setprecision(2) << std::fixed
                    << average << std::endl;
        }
    }
private:
    std::string courseName; // nombre del curso para este libro de calificaciones
    std::array<std::array<int, tests>, students> grades; // arreglo 2D
};
