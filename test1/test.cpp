#include<iostream>
#include <string>
using namespace std;

class MyString
{
private:

	string s;

public:

	/*
	 * ��ȡs�ķ���
	 */
	string getS() {
		return s;
	}

	/*
	 *s �ĸ�ֵ����
	 */
	void setS(string string) {
		this->s = string;
	}

	/*
	 *�����ַ���
	 */
	string create() {
		cout << "��������Ҫ���ɵ��ַ�����" << endl;
		string string;
		cin >> string;

		setS(string);

		return getS();
	}

	/*
	 * ��ȡs�ĳ���
	 */
	int getLen() {
		return s.size();
	}

	/*
	 * ���ַ�����ĳ��λ�ò���ĳ���ַ�
	 */
	string insert(int index,string newString) {
		this->s = this->s.substr(0, index - 1) + newString + this->s.substr(index);
		return getS();
	}

	/*
	 * �ַ������滻
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
	 * �ַ�����ɾ��
	 */
	string del() {
		setS("");
		return getS();
	}

	/*
	 * �ַ���������
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
	cout << "����0�������˵������������ַ����˳�����  " << endl;
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
			cout << "�ַ��������ɣ�Ϊ��" << s << endl;
			back();
		}
			break;
		case 2:
			system("cls");
			cout <<"��ǰ�ַ���Ϊ��"<< myString->getS()<<endl;
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
			cout << "��������Ҫ�����λ��:" << endl;
			cin >> index;
			string newString;
			cout << "��������Ҫ������ַ�:" << endl;
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
			cout << "��������Ҫ�滻���ַ�:" << endl;
			cin >> oldString;
			string newString;
			cout << '\n' << "���������ַ�:" << endl;
			cin >> newString;
			string s = myString->repl(oldString, newString);
			cout << "�滻����ַ���Ϊ��" << s<< endl;
			back();
		}
			break;
		case 6:
		{
			system("cls");
			string s = myString->del();
			cout << "�ַ�����ɾ��" << endl;
			back();
		}
			break;
		case 7:
		{
			system("cls");
			string newString;
			cout << "��������Ҫ������ַ�:" << endl;
			cin >> newString;
			string s = myString->connect(newString);
			cout << "����֮����ַ���Ϊ��" << s << endl;
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

