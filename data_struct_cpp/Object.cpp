//
// Created by eagle on 2022/4/18.
//
#include <string>
#include <iostream>

using namespace std;

class Person {
private:
    string name;
    int age;
    int sex;
public:
    Person(string name, int age, int sex) : name(name), age(age), sex(sex) {
        cout << "new Person" << endl;
    }

    ~Person() {
        cout << "delete Obj" << endl;
    }

    void setName(string name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }

    void setSex(int sex) {
        this->sex = sex;
    }

    string getName() {
        return this->name;
    }

    int getAge() {
        return this->age;
    }

    string getSex() {
        return this->sex == 1 ? "man" : "woman";
    }
};

class Student : public Person {
public:
    string major;
    int grade;
};
class Parent{
public:
    virtual void speak()=0;
};
class Son:public Parent{
public:
    void speak(){
        cout<<"hello"<<endl;
    }
};
int main() {
    Person person("tom", 10, 1);
    cout << person.getName() << endl;
    return 0;
}