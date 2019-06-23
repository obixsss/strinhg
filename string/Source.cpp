#include<iostream>
#include <Windows.h>
using namespace std;

//#define STRING_BASICS
//define CONSTRUCTOR_CHECK
#define OPERATORS_CHECK
class String
{
	int size; //размер строки
	char* str; // адрес строки динамической памяти
public:
	int get_size() const
	{
		return size;
	}
 char* get_str()
	{
		return str;
	}
	const char* get_str() const
	{
		return str;
	}
	void set_size(int size)
	{
		if (size > 0)
		{
			this->size = size;
		}
		else
		{
			this->size = 80;
		}
	}
	// Constructors
	String(int size = 80)
	{
		set_size(size);
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}

	String(const char str[])
	{
		//cout << StrLen(str) << endl;
		this->size = StrLen(str) + 1;
		this->str = new char [size] {};
		for (int i = 0; str[i]; i++) this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char [size] {};
		for (int i = 0; other.str[i]; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;

	}
	//Operators:
	String& operator=(const String& other)
	{
		if (this == &other) return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char [size] {};
		for (int i = 0; other.str[i]; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:" << this << endl;
		return *this;
	}

	// Methods
	int StrLen(const char str[])
	{
		int i = 0;
		for (; str[i]; i++);
		return i;
	}
	void print()
	{
		cout << "str:" << str << endl;
		cout << "size:" << size << endl;
	}
};

ostream& operator << (ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String res = left.get_size() + right.get_size() - 1;
	for (int i= 0; i< left.get_size() - 1; i++) res.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		res.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return res;
}
void InputLine(char str[], const int n)
{
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866);
}
void main()
{
	setlocale(LC_ALL, "");
#ifdef STRING_BASICS
	/*char str[] = { 'H', 'e', 'l','l', 'o','\0' };
	cout << str << endl;*/
	/*char str[] = "Hello";
	cout << str << endl;*/
	const int n = 20;
	char str[n] = {};
	cout << "Input line:";
	//cin >> str;
	InputLine(str, n);

	cout << str << endl;
#endif // STRING_BASICS   
#ifdef CONSTRUCTOR_CHECK
	String str;
	str.print();
	cout << str << endl;
	String str1 = "Hello";
	cout << str1 << endl;
	//cout<< typeid("Hello").name()<<endl;
	String str2 = str1; //Copyconstructor
	cout << str2 << endl;
	str = str1;
	cout << str << endl;
#endif //CONSTRUCTOR_CHECK

#ifdef OPERATORS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << str3 << endl;
#endif
}