//------------------------------------------------------------
// Do not modify this file.
//------------------------------------------------------------

#pragma once

#include <iostream>
#include <string>

class Person {
 public:
  Person() {
    _name = "";
    _age = 0;
  }

  Person(const std::string& name, const int age) {
    _name = name;
    _age = age;
  }

  const std::string& name() const { return _name; }
  const int age() const { return _age; }

  bool operator==(const Person& rhs) const {
    return name() == rhs.name() && age() == rhs.age();
  }

  bool operator!=(const Person& rhs) const {
    return !(*this == rhs);
  }

  friend std::ostream& operator<<(std::ostream& out, const Person& p) {
    out << p.name() << " " << p.age();
    return out;
  }

 private:
  std::string _name;
  int _age;
};
