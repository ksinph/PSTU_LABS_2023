#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h> // Обязательно для SetConsoleCP() и SetConsoleOutputCP()
using namespace std;

struct abt
{
	char surname[30];
	char name[30];
	char patronymic[30];
	int year;
	int ekz_math;
	int ekz_rush;
	int ekz_choose;
	float certificate;
	void read()
	{
		cout << "Введённые данные:" << endl;
		cout << surname<<" ";
		cout << name<<" ";
		cout << patronymic << endl;
		cout << year << endl;
		cout << ekz_math << endl;
		cout << ekz_rush << endl;
		cout << ekz_choose << endl;
		cout << certificate << endl;
	}
	void write()
	{
		cout << endl << "Введите фамилию абитуриента ";
		cin>>surname;
		cout <<"Введите имя абитуриента ";
		cin>>name;
		cout << "Введите отчество абитуриента ";
		cin>>patronymic;
		cout << "Введите год рождения ";
		cin >> year;
		cout << "Введите оценку за математику ";
		cin >> ekz_math;
		cout << "Введите оценку за русский ";
		cin >> ekz_rush;
		cout << "Введите оценку за экзамен на выбор ";
		cin >> ekz_choose;
		cout << "Введите среднюю оценку за аттестат ";
		cin >> certificate;
	}
};
void deleter(int num)
{
	abt user;
	FILE* f1;
	FILE* f2;
	int n;
	if ((f1 = fopen("file.bin", "rb")) == NULL) exit(1);
	if ((f2 = fopen("filetmp.bin", "wb")) == NULL) exit(2);
	fread(&n, sizeof(int), 1, f1);
	n -= 1;
	fwrite(&n, sizeof(int), 1, f2);
	for (int i = 0; i < num - 1; i++)
	{
		fread(&user, sizeof(abt), 1, f1);
		fwrite(&user, sizeof(abt), 1, f2);
	}
	fread(&user, sizeof(abt), 1, f1);
	for (int i = num; i < n + 1; i++)
	{
		fread(&user, sizeof(abt), 1, f1);
		fwrite(&user, sizeof(abt), 1, f2);
	}
	fclose(f1);
	fclose(f2);
}
void insert(string surnamep)
{
	int n;
	abt user;
	FILE* f1;
	FILE* f2;
	
	if ((f1 = fopen("filetmp.bin", "rb")) == NULL) exit(3);
	if ((f2 = fopen("file.bin", "wb")) == NULL) exit(4);
	fread(&n, sizeof(int), 1, f1);
	n += 1;
	fwrite(&n, sizeof(int), 1, f2);

	for (int i = 0; i < n; i++)
	{
		fread(&user, sizeof(abt), 1, f1);
		fwrite(&user, sizeof(abt), 1, f2);
		
		if (surnamep==user.surname)
		{
			user.write();
			fwrite(&user, sizeof(abt), 1, f2);
		}
	}
	fclose(f1);
	fclose(f2);
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	FILE* F;
	abt user;
	if ((F = fopen("file.bin", "wb")) == NULL) exit(5);
	cout << "Введите колво абитуриентов "; cin >> n;
	fwrite(&n, sizeof(int), 1, F);
	for (int i = 0; i < n; i++)
	{
		user.write();
		fwrite(&user, sizeof(abt), 1, F);
	}
	fclose(F);
	if ((F = fopen("file.bin", "rb")) == NULL) exit(6);
	fread(&n, sizeof(int), 1, F);
	for (int i = 0; i < n; i++)
	{
		fread(&user, sizeof(abt), 1, F);
		user.read();
	}
	fclose(F);

	int num;
	cout << "Введите номер записи, которую нужно удалить ";
	cin >> num;
	deleter(num);

	if ((F = fopen("filetmp.bin", "rb")) == NULL) exit(7);
	fread(&n, sizeof(int), 1, F);
	for (int i = 0; i < n; i++)
	{
		fread(&user, sizeof(abt), 1, F);
		user.read();
	}
	fclose(F);

	cout << "Введите фамилию, после которой нужно вставить элемент: ";
	string surnamep; cin >> surnamep;
	insert(surnamep);
	if ((F = fopen("file.bin", "rb")) == NULL) exit(8);
	fread(&n, sizeof(int), 1, F);
	for (int i = 0; i < n; i++)
	{
		fread(&user, sizeof(abt), 1, F);
		user.read();
	}
	fclose(F);
	return 0;
}
