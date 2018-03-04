#include <iostream>
#include <fstream>

using namespace std;

class Serializable
{
public:
    Serializable() {}
    virtual ~Serializable() {}

    virtual void serialize(std::ostream& stream) = 0;
    virtual void deserialize(std::istream& stream) = 0;
};

struct PersonInfo : public Serializable // Yes! It's possible
{
public:
    unsigned int age;
    string name;

    virtual void serialize(std::ostream& stream)
    {
        stream << age << name;
    }

    virtual void deserialize(std::istream& stream)
    {
        stream >> age >> name;
    }

    void print()
    {
        cout << age << "/" << name << endl;
    }
};


int main()
{
    filebuf fb;
    fb.open("save.txt", ios::in); // call ios::in to load and ios::out to save

    PersonInfo person;
    person.age = 10;
    person.name = "Hello world";

    ostream os(&fb);
    person.serialize(os);

    istream is(&fb);
    person.deserialize(is);

    person.print();

}
