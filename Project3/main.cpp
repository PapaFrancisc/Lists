#include<iostream>
#include<string>
using namespace std;

class Human
{
protected:
	string name;
	unsigned int age;
public:
	const string& get_name()const
	{
		return this->name;
	}
	unsigned int get_age()const
	{
		return this->age;
	}
	void set_name(string& name)
	{
		this->name = name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	Human(string name, unsigned int age) :name(name), age(age)
	{
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//		Methods
	void info()
	{
		cout << name << " " << age << " ëåò\n";
	}
};

class Student :public Human
{
	string specialty;
	unsigned int year;//ãîä îáó÷åíèÿ.
	int karma;	//óñïåâàåìîñòü
public:
	const string& get_specialty() const
	{
		return this->specialty;
	}
	unsigned int get_year() const
	{
		return this->year;
	}
	int get_karma() const
	{
		return this->karma;
	}
	const string& set_specialty(const string& specialty)
	{
		return this->specialty = specialty;
	}
	unsigned int set_year(unsigned int year)
	{
		return this->year = year;
	}
	int set_karma(int karma)
	{
		return this->karma = karma;
	}
	//			Constructors:
	Student
	(
		const string& name, unsigned int age,
		const string& specialty, unsigned int year = 1, int karma = 0
	) :Human(name, age)
	{
		this->specialty = specialty;
		this->year = year;
		this->karma = karma;
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//			Methods:
	void info()
	{
		Human::info();
		cout << ", ñïåöèàëüíîñòü " << specialty
			<< ", " << year << "-é êóðñ, óñïåâàåìîñòü " << karma << "!" << endl;
	}
};

class Teacher :public Human
{
	string specialty;
	unsigned int xp;
	int evil;
public:
	const string& get_specialty() const
	{
		return this->specialty;
	}
	unsigned int get_xp() const
	{
		return this->xp;
	}
	int get_evil() const
	{
		return this->evil;
	}
	const string& set_specialty(const string& specialty)
	{
		return this->specialty = specialty;
	}
	unsigned int set_xp(unsigned int xp)
	{
		return this->xp = xp;
	}
	int set_evil(int evil)
	{
		return this->evil = evil;
	}

	//				Constructors:
	Teacher
	(
		const string& name, unsigned int age,
		const string& specialty, unsigned int xp = 0, int evil = 0
	) :Human(name, age)
	{
		this->specialty = specialty;
		this->xp = xp;
		this->evil = evil;
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	//			Methods:
	void info()
	{
		Human::info();
		cout << "Ñïåöèàëüíîñòü: " << specialty
			<< ", îïûò ïðåïîäàâàíèÿ: " << xp << " ëåò, "
			<< "óðîâåíü çëîñòè: " << evil << "%" << endl;
	}
};

class Graduate :public Student
{
	string diploma_theme;
public:
	const string& get_diploma_theme() const
	{
		return this->diploma_theme;
	}
	const string& set_diploma_theme(const string& diploma_theme)
	{
		return this->diploma_theme = diploma_theme;
	}
	//			Constructors:
	Graduate
	(
		const string& name, unsigned int age,
		const string& specialty, unsigned int year, int karma,
		const string& diploma_theme
	) :Student(name, age, specialty, year, karma)
	{
		this->diploma_theme = diploma_theme;
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "Gdestructor:\t" << this << endl;
	}

	//			Methods:
	void info()
	{
		Student::info();
		cout << "Òåìà äèïëîìíîãî ïðîåêòà: " << diploma_theme << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Human h("Âàñèëèé", 20);
	h.info();

	Student durko("Äóðêî Âàñèëèé", 20, "ÐÏÎ");
	durko.info();

	Teacher pablo("Pablo Escobar", 40, "Ðàñïðîñòðàíåíèå íàðêîòèêîâ", 25, 50);
	pablo.info();

	Graduate tony
	("Antonio Montana", 22, "Ðàñïðîñòðàíåíèå íàðêîòèêîâ", 5, 90, "Ðàáîòà ñ ïðîáëåìíîé çàäîëæåííîñòüþ");
	tony.info();
}