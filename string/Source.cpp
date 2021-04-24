#include<iostream>
using namespace std;

#define delimiter "\n---------------------------------------------\n"
class String;
String operator+(const String& left, const String& right);
class String
{
	int size;	//Размер строки в Байтах
	char* str;	//Указатель на строку в динамической памяти
public:
	int get_size()const;
	/* v возвращает константный указатель (нельзя изменить значение по адресу)*/
	const char* get_str()const;
	char* get_str();
	//			Constructors:
	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	
	~String();
	String(String&& other);
	//			Operators:
	String& operator=(const String& other);
	String& operator+=(const String& other);
	//			Methods:
	
	void print() const;
};


int String::get_size()const
{
	return size;
}
/* v возвращает константный указатель (нельзя изменить значение по адресу)*/
const char* String::get_str()const//Показывает что это константный метод
{
	return str;
}
char* String::get_str()
{
	return str;
}
//			Constructors:
String::String(int size) :size(size), str(new char[size] {})//список инициализаций

{
	//this->size = size;
	//this->str = new char[size] {};
	cout << (size == 80 ? "Default" : "Size") << "Constructor:\t" << this << endl;
}
String::String(const char str[]) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size] {};
	for (int i = 0; str[i]; i++)
		this->str[i] = str[i];
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	//this->size = other.size;
	//this->str = new char[size] {};
	//for (int i = 0; i < size; i++)
		//this->str[i] = other.str[i];
	cout << "CopyConstructor:\t" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t\t" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	//this->size = other.size;
	//this->str = other.str;
	other.str = nullptr;//это указатель на 0
	cout << "Moveconstructor:\t\t" << this << endl;
}
//			Operators:
String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
		this->str[i] = other.str[i];
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}

String& String::operator+=(const String& other)
{
	return *this = *this + other;
}

//			Methods:
void String::print() const
{
	cout << "size:\t" << size << endl;
	cout << "str:\t" << str << endl;
}


ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return result;
}

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef CONSTRUCTORS_CHECK
	String str;		//Default constructor
	str.print();

	String str1 = "Hello";	//Single argument constructor
	str1.print();
	cout << "str1:" << str1 << endl;
	String str2 = str1;		//Copy constructor
	cout << "str2:" << str2 << endl;

	str = str2;		//Copy assignment
	cout << str << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	String str1 = "Hello";
	String str2;
	str1 = str1;
	str1.print();
	cout << "str1:" << str1 << endl;
	cout << "str2:" << str2 << endl;

	int a = 2;
	a = a;
	cout << a << endl;
#endif // ASSIGNMENT_CHECK

	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	String str3 = str1 + str2;//Operator + будет выполнять конкатенацию (слияние, объединение) строк
	cout << delimiter << endl;
	cout << str3 << endl;

	str1 += str2;
	cout << delimiter << endl;
	cout << str1 << endl;

	//String str3 = str1; //Copy constructor
	//String str4;
	//str4 = str2; 
	//String str4 = str3;
	//cout << str4 << endl;
}