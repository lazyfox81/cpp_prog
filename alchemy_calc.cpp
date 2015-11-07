#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using std::cin;
using std::cout;

struct node {
	char name[100];
	char eff1[100];
	char eff2[100];
	char eff3[100];
	char eff4[100];
	char weight[10];
	char cost[10];
	node* next;
};

struct list {

	//Конструктор по умолчанию (Head=NULL)
	list():head(NULL){};

	// Проверка списка на пустоту
	bool chk_empty() const;

	// Деструктор
	~list();

	// Очистка списка
	void clean();

	node* head; 			// Первый элемент (голова) списка
	node* tail; 			// Последний элемент (хвост) списка

	// Включение в список нового компонента
	void node_in(char* n, char* ef1, char* ef2, char* ef3, char* ef4, char* wt, char* cst);

	// Поиск компонента в списке по имени
	node* search_name(const char *n);

	// Вывод полей указанного узла на консоль. Имя узла вводится с консоли
	void write_ing();

	// Вывод полей указанного узла на консоль. Перед выводом необходимо проверить,
	//не равно ли p нулю.
	// Если p=NULL обращение к полям узла приведет к падению программы.
	void write_ing(node* n){
		if (n)
			cout << n->name << '\n' << n->eff1 << '\n' << n->eff2 << '\n' << n->eff3
			<< '\n' << n->eff4 << '\n';
	}
	// Вывод ингредиентов с указанным эффектом
	void write_eff();
};


//------------------------------------------------------

// Проверка списка на пустоту
bool list::chk_empty()const {
	return (head==NULL);
}

 // Включение в список нового компонента
void list::node_in(char* n, char* ef1, char* ef2, char* ef3, char* ef4, char* wt, char* cst){
	node* c = new node;
	strncpy(c->name, n, 100);
	strncpy(c->eff1, ef1, 100);
	strncpy(c->eff2, ef2, 100);
	strncpy(c->eff3, ef3, 100);
	strncpy(c->eff4, ef4, 100);
	strncpy(c->weight, wt, 10);
	strncpy(c->cost, cst, 10);
	c->next = 0;
	if (chk_empty())
		head = c;
	else
		tail->next = c;
	tail = c;
	/*cout << c->name << '\n' << c->eff1 << '\n' << c->eff2 << '\n' << c->eff3 << '\n' << c->eff4 << '\n';*/
}

// Поиск компонента в списке по имени
// Возвращать наша функция будет адрес найденного узла или NULL, если ничего не найдено.
// Функция int *strcmp(char *s1, char *s2) сравнивает строки и возвращает отрицат.
// (если s1 меньше s2), нулевое (если s1 равно s2)
// или положительное (если s1 больше s2) значение
node* list::search_name(const char *n){
		node* c = new node;
		c = head;
		while (c) {
			if (!strcmp(c->name, n))
				return c;
			c = c->next;
		// Если ничего не нашли, после обработки последнего значения "с", узел "с"
		//принимает значение NULL
		}
        cout << "Uncorrect name of ingredient!!";
		return c;
		//если мы ничего не нашли, то возвращаем с, которое принимает значение NULL
}

// Ввывод полей указанного узла на консоль
void list::write_ing(){
	char ing_name[100];					//название ингредиента
	cout << "Enter name of ingredient -> ";
	cin.getline(ing_name, 100);
	//cout << ing_name << '\n';

	node* p = new node;
	p = search_name(ing_name);

	write_ing(p);
}

// Вывод ингредиентов с указанным эффектом
void list::write_eff(){
	char eff_name[100];					//название эффекта
	cout << "Enter name of effect -> ";
	cin.getline(eff_name, 100);

	node* el = new node;
	el = head;
	while (el) {
		if ((!strcmp(el->eff1, eff_name)) || (!strcmp(el->eff2, eff_name)) || (!strcmp(el->eff3, eff_name)) || (!strcmp(el->eff4, eff_name))){
			write_ing(el);
			cout << '\n';
		}
		el = el->next;
	}
}

// Очистка списка
void list::clean(){
	while(head){
		node *temp = head->next;
		delete head;
		head = temp;
	}
}

//Деструктор
list::~list() {
	clean();
}

int main() {
	char* buf_name = new char[100];
	char* buf_eff1 = new char[100];
	char* buf_eff2 = new char[100];
	char* buf_eff3 = new char[100];
	char* buf_eff4 = new char[100];
	char* buf_weight = new char[10];
	char* buf_cost = new char[10];

	// Создаем входной и выходной потоки
	// ios::in - файл открыт для чтения
	//ios::out - файл открыт для записи
	//ios::trunc - если файл существует, удалить
	std::ifstream inpf ("alchemy_ingredients.txt", std::ios::in);
	//std::ofstream outf ("value1.txt", ios::out | ios::trunc);

	if (!inpf.good()){
		cout << "File opening error!\n";
		return 0;
	}

	// Создание объекта lst_ing
	list lst_ing;

	//Считывание данный из файла и заполнение списка
	int n = 0;
	while (!inpf.eof()){
		inpf.getline(buf_name, 100, '|');		//считывать до вертикальной черты
		inpf.getline(buf_eff1, 100, '|');
		inpf.getline(buf_eff2, 100, '|');
		inpf.getline(buf_eff3, 100, '|');
		inpf.getline(buf_eff4, 100, '|');
		inpf.getline(buf_weight, 10, '|');
		inpf.getline(buf_cost, 10);			//считывать до начала новой строки
		lst_ing.node_in(buf_name, buf_eff1, buf_eff2, buf_eff3, buf_eff4, buf_weight, buf_cost);
		//cout << buf_name << '|' << buf_eff1 << '|' << buf_eff2 << '|' << buf_eff3 << '|' << buf_eff4 << '|' << buf_weight << '|' << buf_cost << '\n';
		n = n + 1;
	}
	inpf.close();
	// Выбор операции
	//0 - поиск по названию
	//1 - поиск по эффекту

	char op[2];
	cout << "Enter code of operation->";
	cin.getline(op, 2);

	//Печать полей выбранного с консоли узла
	if (!strcmp(op, "0")) lst_ing.write_ing();

	// Печать ингредиентов с заданным эффектом
	if (!strcmp(op, "1")) lst_ing.write_eff();
	return 0;
}

