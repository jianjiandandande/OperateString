#include<iostream>
#include <string>
using namespace std;

class MyString
{
private:

	string s;

public:

	/*
	 * 获取s的方法
	 */
	string getS() {
		return s;
	}

	/*
	 *s 的赋值方法
	 */
	void setS(string string) {
		this->s = string;
	}

	/*
	 *生成字符串
	 */
	string create() {
		cout << "请输入你要生成的字符串：" << endl;
		string string;
		cin >> string;

		setS(string);

		return getS();
	}

	/*
	 * 获取s的长度
	 */
	int getLen() {
		return s.size();
	}

	/*
	 * 在字符串的某个位置插入某个字符
	 */
	string insert(int index,string newString) {
		this->s = this->s.substr(0, index - 1) + newString + this->s.substr(index);
		return getS();
	}

	/*
	 * 字符串的替换
	 */
	string repl(string oldString, string newString) {
	
		int index = this->s.find(oldString, 0);
		while (index != -1) {
			
			this->s = this->s.substr(0, index) + newString + this->s.substr(index+oldString.size());
			index = this->s.find(oldString, 0 + index + newString.size());

		}

		return getS();

	}
	/*
	 * 字符串的删除
	 */
	string del() {
		setS("");
		return getS();
	}

	/*
	 * 字符串的连接
	 */
	string connect(string p) {

		this->s = this->s + p;
		return getS();
	}

};
MyString* myString = new MyString();

void menu();
void choice();
void back();

void back() {
	cout << "输入0返回主菜单，输入其他字符，退出程序！  " << endl;
	int back;
	cin >> back;
	if (back == 0) {
		menu();
	}
}
void choice() {

	int choose;

	cin >> choose;

	switch (choose) {
		case 1: 
		{
			system("cls");
			string s = myString->create();
			cout << "字符串已生成，为：" << s << endl;
			back();
		}
			break;
		case 2:
			system("cls");
			cout <<"当前字符串为："<< myString->getS()<<endl;
			back();
			break;
		case 3:
			system("cls");
			cout << myString->getLen() << endl;
			back();
			break;
		case 4:
		{
			system("cls");
			int index;
			cout << "请输入你要插入的位置:" << endl;
			cin >> index;
			string newString;
			cout << "请输入你要插入的字符:" << endl;
			cin >> newString;
			string s = myString->insert(index, newString);
			cout << '\n' << s << endl;
			back();
		}
			break;
		case 5:
		{	
			system("cls");
			string oldString;
			cout << "请输入你要替换的字符:" << endl;
			cin >> oldString;
			string newString;
			cout << '\n' << "请输入新字符:" << endl;
			cin >> newString;
			string s = myString->repl(oldString, newString);
			cout << "替换后的字符串为：" << s<< endl;
			back();
		}
			break;
		case 6:
		{
			system("cls");
			string s = myString->del();
			cout << "字符串已删除" << endl;
			back();
		}
			break;
		case 7:
		{
			system("cls");
			string newString;
			cout << "请输入你要插入的字符:" << endl;
			cin >> newString;
			string s = myString->connect(newString);
			cout << "连接之后的字符串为：" << s << endl;
			back();
		}
			break;
		case 0:
			break;
	}


}
void menu()
{
	FILE *fp;
	fp = fopen("menu_1.txt", "r");
	char ch;
	ch = fgetc(fp);
	while (ch != '#')
	{
		putchar(ch);
		ch = fgetc(fp);
	}
	fclose(fp);
	printf("\n");
	choice();
}



int main()
{
	system("color 3f");
	menu();


	//string s = myString->create();

	////string a = myString->repl("BC", "LMN");
	//string a = myString->insert(3, "XYZ");
	//cout << a << endl;
}

