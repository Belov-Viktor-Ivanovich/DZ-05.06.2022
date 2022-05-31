#pragma once
class Student
{
	string surname;
	string name;
	string patronymic;
	int* mat = new int[0];
	int* rus = new int[0];
	int* fiz = new int[0];
	int counterM = 0;
	int counterR = 0;
	int counterF = 0;
	int size = 0;
public:
	Student()
	{

	}
	Student(string surname, string name, string patronymic)
	{
		this->surname = surname;
		this->name = name;
		this->patronymic = patronymic;
	}

	void operator =(Student& other)
	{
		if (this->mat != nullptr)delete[] this->mat;
		if (this->rus != nullptr)delete[] this->rus;
		if (this->fiz != nullptr)delete[] this->fiz;
		this->counterM = other.counterM;
		this->counterR = other.counterR;
		this->counterF = other.counterF;
		this->size = other.size;
		this->surname = other.surname;
		this->name = other.name;
		this->patronymic = other.patronymic;
		this->mat = new int[counterM];
		for (int i = 0; i < counterM; i++)
		{
			mat[i] = other.mat[i];
		}
		this->rus = new int[counterR];
		for (int i = 0; i < counterR; i++)
		{
			rus[i] = other.rus[i];
		}
		this->fiz = new int[counterF];
		for (int i = 0; i < counterF; i++)
		{
			fiz[i] = other.fiz[i];
		}
	}
	Student(const Student& other)
	{
		this->counterM = other.counterM;
		this->counterR = other.counterR;
		this->counterF = other.counterF;
		this->size = other.size;
		this->surname = other.surname;
		this->name = other.name;
		this->patronymic = other.patronymic;
		this->mat = new int[counterM];
		this->mat = new int[counterM];
		for (int i = 0; i < counterM; i++)
		{
			mat[i] = other.mat[i];
		}
		this->rus = new int[counterR];
		for (int i = 0; i < counterR; i++)
		{
			rus[i] = other.rus[i];
		}
		this->fiz = new int[counterF];
		for (int i = 0; i < counterF; i++)
		{
			fiz[i] = other.fiz[i];
		}
	}
	void AddMat(int n)
	{
		int* buf = new int[counterM + 1];
		for (int i = 0; i < counterM; i++)
		{
			buf[i] = mat[i];
		}
		buf[counterM] = n;
		delete[]mat;
		mat = buf;
		counterM++;
	}
	void AddRus(int n)
	{
		int* buf = new int[counterR + 1];
		for (int i = 0; i < counterR; i++)
		{
			buf[i] = rus[i];
		}
		buf[counterR] = n;
		delete[]rus;
		rus = buf;
		counterR++;
	}
	void AddFiz(int n)
	{
		int* buf = new int[counterF + 1];
		for (int i = 0; i < counterF; i++)
		{
			buf[i] = fiz[i];
		}
		buf[counterF] = n;
		delete[]fiz;
		fiz = buf;
		counterF++;
	}


	void creatMat(int index, int n)
	{
		for (int i = 0; i < counterM; i++)
		{
			if (i == index) {
				mat[i] = n;
			}
		}
	}
	void creatRus(int index, int n)
	{
		for (int i = 0; i < counterR; i++)
		{
			if (i == index) {
				rus[i] = n;
			}
		}
	}
	void creatFiz(int index, int n)
	{
		for (int i = 0; i < counterF; i++)
		{
			if (i == index) {
				fiz[i] = n;
			}
		}
	}
	int srmat()
	{
		int k = 0;
		for (int i = 0; i < counterM; i++)
		{
			k += mat[i];
		}
		return k / counterM;
	}
	int srfiz()
	{
		int k = 0;
		for (int i = 0; i < counterF; i++)
		{
			k += fiz[i];
		}
		return k / counterF;
	}
	int srrus()
	{
		int k = 0;
		for (int i = 0; i < counterR; i++)
		{
			k += rus[i];
		}
		return k / counterR;
	}
	string getSurname()
	{
		return surname;
	}
	string getName()
	{
		return name;
	}
	string getPatronymic()
	{
		return patronymic;
	}

	void print()
	{
		cout << surname << " " << name << " " << patronymic << endl;
		cout << "mat" << " : ";
		for (int i = 0; i < counterM; i++)
		{
			cout << mat[i] << " ";
		}
		cout << endl;
		cout << "Rus" << " : ";
		for (int i = 0; i < counterR; i++)
		{
			cout << rus[i] << " ";
		}
		cout << endl;
		cout << "Fiz" << " : ";
		for (int i = 0; i < counterF; i++)
		{
			cout << fiz[i] << " ";
		}
		cout << endl;
	}

	~Student()
	{
		delete[]mat;
		delete[]rus;
		delete[]fiz;

	}



};
class Jornal
{
	Student* joor = new Student[0];
	int size = 0;
public:
	Jornal()
	{

	}
	Jornal(Student*& st2)
	{
		this->size = size;
		joor = new Student[size];
		for (int i = 0; i < size; i++)
		{
			joor[i] = st2[i];
		}
	}
	void addStudent(Student st) {
		Student* buf = new Student[size + 1];
		for (int i = 0; i < size; i++)
		{
			buf[i] = joor[i];
		}
		buf[size] = st;
		delete[]joor;
		joor = buf;
		size++;
	}
	void delStudents(int index)
	{
		Student* buf = new Student[size - 1];
		for (int i = 0; i < index; i++)
		{
			buf[i] = joor[i];
		}
		for (int i = index; i < size; i++)
		{
			buf[i] = joor[i + 1];
		}
		size--;
	}

	void show3()
	{
		for (int i = 0; i < size; i++)
		{
			if (joor[i].srfiz() < 3 || joor[i].srrus() < 3 || joor[i].srmat() < 3) {
				cout << "Debtors :" << endl;
				cout << joor[i].getSurname() << " ";
				cout << joor[i].getName() << " " << joor[i].getPatronymic() << endl;
			}
		}
	}
	~Jornal()
	{
		delete[]joor;
	}
};
