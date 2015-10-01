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
	void print(const char* file_out);
	
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

// Поиск компонента в списке по имени
//Возвращать наша функция будет адрес найденного узла или NULL, если ничего не найдено. Искать начнем с компонента, 
//на который указывает head и, двигаясь вперед, сравнивать имя текущей переменной с искомым. В функции поиска мы можем 
//не боясь, передвигать ссылку head, так как передаем ее НЕ по ссылке. 
//Функция int *strcmp(char *s1, char *s2) сравнивает строки и возвращает отрицат. (если s1 меньше s2), нулевое (если s1 равно s2)
//или положительное (если s1 больше s2) значение
node* list::search(const char *n){
		node* c = new node;
		c = head;
		while (c) {
			if (!strcmp(c->name,n))
				return c;
			c = c->next;
		}
		return c;
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
void list::print(const char* file_out){
	std::ofstream* out = new std::ofstream(file_out, std::ios::out | std::ios::trunc);
	//std::ofstream* out = new std::ofstream(file_out);
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
	char* buf_name = new char[20];
	char* buf_value = new char [10];
	
	// Создаем входной и выходной потоки
	// ios::in - файл открыт для чтения
	//ios::out - файл открыт для записи
	//ios::trunc - если файл существует, удалить
	std::ifstream inpf ("value.txt", std::ios::in);
	//std::ofstream outf ("value1.txt", ios::out | ios::trunc);
	
	if (!inpf.good()){
		cout << "File opening error!\n";
		return 0;
	} 
	
	list vars;							// Создание объекта vars
	
	while (!inpf.eof()){
		inpf.getline(buf_name, 20, ' ');
		inpf.getline(buf_value, 10, ' ');
		vars.node_in(buf_name, buf_value);
	}
	inpf.close();
		
	vars.name_del("hty");
	vars.ch_val("abc", "605");
	
	vars.print("value1.txt");
	
	return 0;
} 
