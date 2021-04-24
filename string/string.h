#include<iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;
////////Class declaration///////
#define delimiter "\n---------------------------------------------\n"
class String;
String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);
//String& operator=(const String& other);

class String
{
	int size;	//–азмер строки в Ѕайтах
	char* str;	//”казатель на строку в динамической пам€ти
public:
	int get_size()const;
	/* v возвращает константный указатель (нельз€ изменить значение по адресу)*/
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
