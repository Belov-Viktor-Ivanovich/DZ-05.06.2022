

#include <iostream>
#include"Student.cpp"

#include<ctime>
#define random(a,b) a+rand()%(b-a+1)

using namespace std;

int main()
{
    srand(time(NULL));

    Student st1("Below", "Viktor", "Ivanovich");
    Student st2("Ivanov", "Ivan", "Ivanovich");
    Student st3("Petrov", "Oleg", "Ivanovich");
    for (int i = 0; i < 5; i++)
    {
        st1.AddMat(random(2, 5));
        st2.AddMat(random(2, 5));
        st3.AddMat(random(2, 5));
        st1.AddRus(random(2, 5));
        st2.AddRus(random(2, 5));
        st3.AddRus(random(2, 5));
        st1.AddFiz(random(2, 5));
        st2.AddFiz(random(2, 5));
        st3.AddFiz(random(2, 5));
    }
    st1.print();
    st2.print();
    st3.print();
    Jornal jor;
    jor.addStudent(st1);
    jor.addStudent(st2);
    jor.addStudent(st3);
    jor.show3();

}

