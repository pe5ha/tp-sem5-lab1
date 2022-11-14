#include "Keeper.h"

keeper::keeper()
{
	this->size_p = 0;
	this->size_n = 0;
	this->size_f = 0;
	p = new Poet[1];
	n = new Novelist[1];
	f = new Fantasist[1];
}

keeper::keeper(int size_p, int size_n, int size_f, Poet* p, Novelist* n, Fantasist* f)
{
	this->size_p = size_p;
	this->size_n = size_n;
	this->size_f = size_f;
	this->p = p;
	this->n = n;
	this->f = f;
}

keeper::keeper(const keeper& ref_k)
{
	this->size_p = ref_k.size_p;
	this->size_n = ref_k.size_n;
	this->size_f = ref_k.size_f;
	this->p = ref_k.p;
	this->n = ref_k.n;
	this->f = ref_k.f;
	//TODO: сделать присваивание и для других классов
}

int keeper::get_size()
{
	return size_p + size_n + size_f;
}

void keeper::add_poet(Poet new_p)
{
	size_p++;
	Poet* new_poets = new Poet[size_p];
	for (int i = 0; i < size_p - 1; i++) {
		new_poets[i] = p[i];
	}
	new_poets[size_p - 1] = new_p; // проверить
	p = new_poets;
}

void keeper::delete_poet(int id)
{
	if (size_p <= 0) exception;
	Poet* new_poets = new Poet[size_p - 1];
	int k = 0;
	for (int i = 0; i < size_p; i++) {
		if (i == id) continue;
		new_poets[k] = p[i];
		k++;
	}
	//delete[] new_poets;
	p = new_poets;
	size_p--;
}

void keeper::add_novelist(Novelist new_n)
{
	size_n++;
	Novelist* new_novelists = new Novelist[size_n];
	for (int i = 0; i < size_n - 1; i++) {
		new_novelists[i] = n[i];
	}
	new_novelists[size_n - 1] = new_n;
	n = new_novelists;
}

void keeper::delete_novelist(int id)
{
	if (size_n <= 0) exception;
	Novelist* new_novelists = new Novelist[size_n - 1];
	int k = 0;
	for (int i = 0; i < size_n; i++) {
		if (i == id) continue;
		new_novelists[k] = n[i];
		k++;
	}
	//delete[] new_poets;
	n = new_novelists;
	size_n--;
}

void keeper::add_fantast(Fantasist new_f)
{
	size_f++;
	Fantasist* new_fantast = new Fantasist[size_f];
	for (int i = 0; i < size_f - 1; i++) {
		new_fantast[i] = f[i];
	}
	new_fantast[size_f - 1] = new_f;
	f = new_fantast;
}

void keeper::delete_fantast(int id)
{
	if (size_f <= 0) exception;
	Fantasist* new_fantast = new Fantasist[size_f - 1];
	int k = 0;
	for (int i = 0; i < size_f; i++) {
		if (i == id) continue;
		new_fantast[k] = f[i];
		k++;
	}
	//delete[] new_poets;
	f = new_fantast;
	size_f--;
}

Poet keeper::get_poet(int id)
{
	if (id >= size_p) { cout << "замени на эксепшен!" << endl; return p[0]; }//TODO: замени на эксепшен! 
	return p[id];
}

Novelist keeper::get_novelist(int id)
{
	if (id >= size_n) { cout << "замени на эксепшен!" << endl; return n[0]; }//TODO: замени на эксепшен! 
	return n[id];
}

Fantasist keeper::get_fantast(int id)
{
	if (id >= size_f) { cout << "замени на эксепшен!" << endl; return f[0]; }//TODO: замени на эксепшен! 
	return f[id];
}

void keeper::Save()
{
	ofstream out;          // поток для записи
	out.open("data.txt");  // окрываем файл для записи
	bool firstIteration = true;   // проверка на первую строку в сохранение (избежание первого \n)
	if (out.is_open())
	{
		//записываем поэтов
		for (int i = 0; i < size_p; i++) {
			if (firstIteration == true) firstIteration = false;
			else out << "\n";

			out << "Poet" << endl;
			out << p[i].get_fullname() << endl;
			out << p[i].get_years_of_birth() << endl;
			out << p[i].get_years_of_death() << endl;

			//записываем количество книг
			out << p[i].get_number_of_books();
			for (int j = 0; j < p[i].get_number_of_books(); j++) {
				out << ";" << p[i].get_books()[j];
			}
		}
		//записываем новелистов
		for (int i = 0; i < size_n; i++) {
			if (firstIteration == true) firstIteration = false;
			else out << "\n";
			out << "Novelist" << endl;
			out << n[i].get_fullname() << endl;
			out << n[i].get_years_of_birth() << endl;
			out << n[i].get_years_of_death() << endl;

			//записываем количество книг
			out << n[i].get_number_of_books();
			for (int j = 0; j < n[i].get_number_of_books(); j++) {
				out << ";" << n[i].get_books()[j];
			}
			out << '\n' << n[i].get_biography();
		}
		// записываем фантастов
		for (int i = 0; i < size_f; i++) {
			if (firstIteration == true) firstIteration = false;
			else out << "\n";
			out << "Fantasist" << endl;
			out << f[i].get_fullname() << endl;
			//записываем количество книг
			out << f[i].get_number_of_books();
			for (int j = 0; j < f[i].get_number_of_books(); j++) {
				out << ";" << f[i].get_books()[j];
			}
			out << '\n' << f[i].is_filmed();
		}
	}
	out.close();
}

void keeper::Read()
{
	string fn;//новое ФИО
	int yob;//года
	int yod;//года
	string new_name_of_book;
	ifstream in("data.txt");
	if (in.is_open())
	{
		/*
		1 строка - получаем символ: 'p' - поэт
		2 строка - получаем ФИО
		3 строка - получаем несколько основных произведений
		4-5 строки - получаем годы жизни
		и прочее...
		*/
		while (!in.eof()) {
			string c;
			getline(in, c);
			if (c == "Poet") {/*TODO: Вынести в отедельную функцию*/
				getline(in, fn);
				in >> yob;
				in >> yod;
				getline(in, new_name_of_book);//TODO: сделать красиво - сейчас применяется для переноса на другую строку
				getline(in, new_name_of_book);
				string* new_books = split(new_name_of_book, ';');
				int size_books = stoi(new_books[0]);
				//присваиваем новые значения
				Poet new_p(fn, yob, yod, new_books, size_books);//исправить последний параметр
				add_poet(new_p);
			}
			else if (c == "Novelist") {
				getline(in, fn);
				in >> yob;
				in >> yod;
				getline(in, new_name_of_book);//TODO: сделать красиво - сейчас применяется для переноса на другую строку
				getline(in, new_name_of_book);
				string* new_books = split(new_name_of_book, ';');
				int size_books = stoi(new_books[0]);
				string bio; getline(in, bio);
				//присваиваем новые значения
				Novelist new_n(fn, yob, yod, new_books, size_books, bio);//исправить последний параметр
				add_novelist(new_n);
			}
			else if (c == "Fantasist") {
				getline(in, fn);
				getline(in, new_name_of_book);
				string* new_books = split(new_name_of_book, ';');
				int size_books = stoi(new_books[0]);
				bool filmed; in >> filmed; // \n - проверить на перенос строки

				//присваиваем новые значения
				Fantasist new_f(fn, new_books, size_books, filmed);
				add_fantast(new_f);
			}
		}
	}
	in.close(); // закрываем файл
}

void keeper::print_poet()
{
	for (int i = 0; i < size_p; i++) {
		cout << "\nПоэт " << i + 1 << ": " << endl;
		print_poet(i);
	}
}

void keeper::print_poet(int id)
{
	if (id >= size_p) { return; }
	cout << "ФИО: " << p[id].get_fullname() << endl;
	cout << "Годы жизни: " << p[id].get_years_of_birth() << " - " << p[id].get_years_of_death() << endl;
	if (p[id].get_number_of_books() == 0) { cout << "Нету книг" << endl; }
	else {
		for (int i = 1; i <= p[id].get_number_of_books(); i++) {
			cout << "Книга " << i << ": ";
			cout << p[id].get_books()[i] << endl;
		}
	}
}

void keeper::print_novelist()
{
	for (int i = 0; i < size_n; i++) {
		cout << "\nНовелист " << i + 1 << ": " << endl;
		print_novelist(i);
	}
}

void keeper::print_novelist(int id)
{
	if (id >= size_n) { return; }
	cout << "ФИО: " << n[id].get_fullname() << endl;
	cout << "Годы жизни: " << n[id].get_years_of_birth() << " - " << n[id].get_years_of_death() << endl;
	if (n[id].get_number_of_books() == 0) { cout << "Нету книг" << endl; }
	else {
		for (int i = 1; i <= n[id].get_number_of_books(); i++) {
			cout << "Книга " << i << ": ";
			cout << n[id].get_books()[i] << endl;
		}
	}
	cout << "Краткая биография: " << n[id].get_biography() << endl;
}

void keeper::print_fantast()
{
	for (int i = 0; i < size_f; i++) {
		cout << "\nФантаст " << i + 1 << ": " << endl;
		print_fantast(i);
	}
}

void keeper::print_fantast(int id)
{
	if (id >= size_f) { return; }
	cout << "ФИО: " << f[id].get_fullname() << endl;
	if (f[id].get_number_of_books() == 0) { cout << "Нету книг" << endl; }
	else {
		for (int i = 1; i <= f[id].get_number_of_books(); i++) {
			cout << "Книга " << i << ": ";
			cout << f[id].get_books()[i] << endl;
		}
	}
	f[id].is_filmed() ? cout << "Снят по крайней мере 1 фильм" : cout << "Не снимались фильмы";
}

void keeper::print_all()
{
	print_poet();
	print_novelist();
	print_fantast();
}

void keeper::add_book_poet(string book, int id)
{
	p[id].add_book(book);
}

void keeper::delete_book_poet(int id)
{
	if (p[id].get_number_of_books() == 0) {
		cout << "Удалять нечего" << endl;
		return;
	}
	else p[id].delete_book();
}

void keeper::add_book_novelist(string book, int id)
{
	n[id].add_book(book);
}

void keeper::delete_book_novelist(int id)
{
	if (n[id].get_number_of_books() == 0) {
		cout << "Удалять нечего" << endl;
		return;
	}
	else n[id].delete_book();
}

void keeper::add_book_fantast(string book, int id)
{
	f[id].add_book(book);
}

void keeper::delete_book_fantast(int id)
{
	if (f[id].get_number_of_books() == 0) {
		cout << "Удалять нечего" << endl;
		return;
	}
	else f[id].delete_book();
}

string* keeper::split(string str, char ch)
{
	stringstream stream(str);
	string* s = new string();
	int size = 0;
	std::string item;
	while (getline(stream, item, ch)) {
		size++;
		string* new_s = new string[size];
		for (int i = 0; i < size - 1; i++) {
			new_s[i] = s[i];
		}
		new_s[size - 1] = item;
		s = new_s;
	}
	stream.flush();
	return s;
}

