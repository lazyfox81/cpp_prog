#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
using std::cin;
using std::cout;

//------------------------------------------------------

//Элемент списка
struct node {
		char name[20]; 		// Имя переменной
		char value[10]; 	// Значение переменной
		node* next; 		//Ссылка на следующий элемент списка
};	

//Собственно список	
struct list {
//public:
	//Конструктор по умолчанию (Head=NULL)
	list():head(NULL){};
	
	// Проверка списка на пустоту
	bool chk_empty() const;
	
	// Деструктор
	~list();
	
	// Очистка списка
	void clean();
	
//private:
	
	node* head; 			// Первый элемент (голова) списка
	node* tail; 			// Последний элемент (хвост) списка
	
	// Включение в список нового компонента
	void node_in(char* n, char* v);
	
	// Поиск компонента в списке по имени
	node* search(const char *n);
		
	// Удаление компонента из списка
	void node_del(node* c);
	
	// Изменение значения компонента
	void node_edit(node &c, const char* v);
	
	//Вывод списка в файл
	void print(char* file_out);
	
	//Удаление компонента из списка с указанием имени
	void name_del(const char* n){
		node* p = new node;
		p = search(n);
		if (p) node_del(p);
	}
	
	//Изменение значения переменной
	void ch_val(const char* n, const char* v){
		node* p = new node;
		p = search(n);
		if (p) node_edit(*p, v);
	}
}; 


//------------------------------------------------------

// Проверка списка на пустоту
bool list::chk_empty()const {
	return (head==NULL);
}

 // Включение в список нового компонента
void list::node_in(char* n, char* v){
	node* c = new node;
	strncpy(c->name, n, 20);
	strncpy(c->value, v, 10);
	c->next = 0;
	if (chk_empty())
		head = c;
	else
		tail->next = c;
	tail = c;
} 
node* list::search(const char *n){
		node* c = new node;
		c = head;
		while (c) {
			if (!strcmp(c->name,n))
				return c;
			c = c->next;
		}
		return 0;
} 

// Удаление компонента из списка
void list::node_del(node* c){
	if (c == head){
		head = c->next;
		return;
	}
	node* r = new node;
	r = head; 
	while (r->next != c)
		r = r->next;
	
	//Нашли элемент r->next = c. Тогда передвигаем указатель на следующий: r->next = c->next и удаляем эл-т с.
	r->next = c->next; 
	delete c;
} 

// Изменение значения компонента
void list::node_edit(node &c, const char* v){
	strncpy(c.value, v, 10);
} 

// Вывод списка в файл
void list::print(char* file_out){
	std::ofstream* out = new std::ofstream(file_out);
	while (head != NULL) {
		out->write(head->name, strlen(head->name));
		out->write(" ",1);
		out->write(head->value, strlen(head->value));
		out->write(" ",1);
		head = head->next;
	}
	out->close();
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

int main(){
	char* file_input = new char[50];
	char* file_output = new char[50];
	char* buf_name = new char[20];
	char* buf_value = new char [10];
	
	cout << "Enter name of input file -> ";
	cin >> file_input;
	cout << "Enter name of output file -> ";
	cin >> file_output;
	
	std::ifstream* inp = new std::ifstream(file_input);
	
	if (!inp->good()){
		cout << "File opening error!\n";
		return 0;
	} 
	
	list vars;							// Создание объекта vars
	
	while (!inp->eof()){
		inp->getline(buf_name, 20, ' ');
		inp->getline(buf_value, 10, ' ');
		vars.node_in(buf_name, buf_value);
	}
	inp->close();
		
	vars.name_del("x");
	vars.ch_val("abc", "605");
	
	
	vars.print(file_output);
	
	return 0;
} 
