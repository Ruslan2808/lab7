#include<iostream>
#include <conio.h>
#include <string>

using namespace std;

template<class T> 
class List {
private:
	T info;
	List<T>* begin;
	List<T>* end;
	List<T>* prev;
	List<T>* next;
public:
	List();
	List(const List<T>&);
	void add(T);
	void del();
	void show();
	template<class T> friend ostream& operator <<(ostream&, List<T>&);
	bool operator==(List<T>&);
	~List();
};

template <class T> List<T>::List() {
	info = 0;
	begin = NULL;
	end = NULL;
	prev = NULL;
	next = NULL;
}

template<class T> List<T>::List(const List<T>& list) {
	info = list.info;
	begin = list.begin;
	end = list.end;
	prev = list.prev;
	next = list.next;
}

template <class T> void List<T>::add(T inf) {
	List<T>* list = new List<T>();
	list->next = NULL;
	list->info = inf;
	if (!begin) {
		list->prev = NULL;
		begin = list;
		end = list;
	}
	else {
		list->prev = end;
		end->next = list;
		end = list;
	}
}

template <class T> void List<T>::del() {
	if (begin != NULL) {
		if (begin == end) {
			begin->next = NULL;
			begin = NULL;
			delete begin;
		}
		else {
			List<T>* list = end;
			end = end->prev;
			end->next = NULL;
			delete list;
		}
		cout << "Элемент удален" << endl;
	}
}

template <class T> void List<T>::show() {
	List<T>* list = begin;
	if (list == NULL) {
		cout << "Список пуст";
	}
	else {
		while (list) {
			cout << list->info << " ";
			list = list->next;
		}
	}
	cout << endl;
}

template<class T> ostream& operator <<(ostream& out, List<T>& list) {
	if (list.begin == NULL) out << "Список пуст";
	else {
		while (list.begin) {
			out << list.begin->info << " ";
			list.begin = list.begin->next;
		}
	}
	out << endl;
	return out;
}

template<class T> bool List<T>::operator ==(List<T>& list) {
	List<T>* list1 = begin;
	List<T>* list2 = list.begin;
	int len1 = 0, len2 = 0;
	while (list1) {
		len1++;
		list1 = list1->next;
	}
	while (list2) {
		len2++;
		list2 = list2->next;
	}
	return len1 == len2;
}

template <class T> List<T>::~List() {
	delete begin;
	delete end;
	delete prev;
	delete next;
}

int menuMain();
int menuvib(string, string);
int getInt();

int main()
{
	setlocale(LC_ALL, "rus");
	int vib = 0, d1 = 0, d2 = 0;
	bool quit = true;
	List<int> list1;
	List<int> list2;
	while (quit) {
		switch (menuMain()) {
		case 0:
			vib = menuvib("Добавление элемента в первый список", "Добавление элемента во второй список");
			cout << "Введите элемент: ";
			if (vib == 0) {
				d1 = getInt();
				list1.add(d1);
			}
			else {
				d2 = getInt();
				list2.add(d2);
			}
			system("pause");
			break;
		case 1:
			vib = menuvib("Вывод первого списка", "Вывод второго списка");
			if (vib == 0) list1.show();
			else list2.show();
			system("pause");
			break;
		case 2:
			vib = menuvib("Удаление последнего элемента первого списка", "Удаление последнего элемента второго списка");
			if (vib == 0) list1.del();
			else list2.del();
			system("pause");
			break;
		case 3:
			vib = menuvib("Перегрузка оператора вывода первого списка", "Перегрузка оператора вывода второго списка");
			if (vib == 0) cout << list1;
			else cout << list2;
			system("pause");
			break;
		case 4:
			if (list1 == list2) cout << "Списки равны" << endl;
			else cout << "Списки не равны" << endl;
			system("pause");
			break;
		case 5:
			quit = false;
			break;
		}
	}
	return 0;
}

int menuMain()
{
	int choiceButton = 0, button = 0;
	system("cls");
	while (true)
	{
		choiceButton = (choiceButton + 6) % 6;

		if (choiceButton == 0) cout << "->Добавление элементов в списки" << endl;
		else cout << "Добавление элементов в списки" << endl;

		if (choiceButton == 1) cout << "->Просмотр списков" << endl;
		else cout << "Просмотр списков" << endl;

		if (choiceButton == 2) cout << "->Удаление последнего элемента из списков" << endl;
		else cout << "Удаление последнего элемента из списков" << endl;

		if (choiceButton == 3) cout << "->Перегрузка оператора вывода" << endl;
		else cout << "Перегрузка оператора вывода" << endl;

		if (choiceButton == 4) cout << "->Перегрузка оператора сравнения" << endl;
		else cout << "Перегрузка оператора сравнения" << endl;

		if (choiceButton == 5) cout << "->Выход" << endl;
		else cout << "Выход" << endl;

		button = _getch();
		if (button == 224)
		{
			button = _getch();
			if (button == 72) choiceButton--;
			if (button == 80) choiceButton++;
		}
		if (button == 13) {
			system("cls");
			return choiceButton;
		}
		system("cls");
	}
}

int menuvib(string str1, string str2)
{
	int choiceButton = 0, button = 0;
	system("cls");
	while (true)
	{
		choiceButton = (choiceButton + 2) % 2;

		if (choiceButton == 0) cout << "->" << str1 << endl;
		else cout << str1 << endl;

		if (choiceButton == 1) cout << "->" << str2 << endl;
		else cout << str2 << endl;

		button = _getch();
		if (button == 224)
		{
			button = _getch();
			if (button == 72) choiceButton--;
			if (button == 80) choiceButton++;
		}
		if (button == 13) {
			system("cls");
			return choiceButton;
		}

		system("cls");
	}
}

int getInt() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13 && numbers.length() != 0) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	cout << endl;
	return stoi(numbers);
}
