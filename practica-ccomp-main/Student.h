#include <string>

class Student {
public:
  explicit Student(std::string n, int a) : name(n), age(a) {}

  std::string getName() const { return name; }
  void setName(std::string n) { name = n; }
  int getAge() const { return age; }
  void setAge(int a) { age = a; }

  bool isOlder() const { return age >= 18; }

private:
  std::string name;
  int age;
};
