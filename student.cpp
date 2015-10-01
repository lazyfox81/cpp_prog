#include <iostream>
#include <cstring>
#include <cstdlib>

/*СТРУКТУРА СТУДЕНТ*/
struct Student
{
	char Name[20]; 				//Имя
	char NameLast[30]; 			//Фамилия
	int Age; 				//Возраст
	char School[30]; 			//Место учебы
	void Input(Student &student);  		//Функция ввода данных в структуру
	Student *Next; 				//Адрес на следующий элемент
};
class List
{
	Student *Head; //Указатель на начало списка
public:
	List():Head(NULL){}; //Конструктор по умолчанию (Head=NULL)
	~List();//Деструктор
	void Add(Student &student);
	void Show();
};
/*ФУНКЦИЯ ЗАПОЛНЕНИЯ ДАННЫХ ПО СТУДЕНТУ*/
void Student::Input(Student &student)
{
    cout<<endl; //Небольшой разрыв при каждом новом вводе
    cout<<"Имя:  "; cin.getline(Name,20); //Ввод имени
    cout<<"Фамилия:  ";cin.getline(NameLast,30); //Ввод  фамилии
    cout<<"Полных лет ";cin>>Age;  //Ввод возраста
    cin.ignore(); //Игнорируем символ
    cout<<"Где учится ";cin.getline(School,30); //Ввод места учебы
}
List::~List() //Деструктор класса List
{
        while (Head!=NULL) //Пока по адресу есть хоть что-то
        {
            Student *temp=Head->Next; //Сразу запоминаем указатель на адрес следующего элемента структуры
            delete Head; //Освобождаем память по месту начала списка
            Head=temp; //Меняем адрес начала списка
        }
}
/*ФУНКЦИЯ ДОБАВЛЕНИЯ НОВОЙ СТРУКТУРЫ В СПИСОК*/
void List::Add(Student &student)
{
     Student *temp=new Student; //Выделение памяти под новую структуру
     temp->Next=Head; //Указываем, что адрес следующего элемента это начало списка
//Копирование содержимого параметра student в только что созданную переменную
       strcpy(temp->Name,student.Name);
       strcpy(temp->NameLast,student.NameLast);
       temp->Age=student.Age;
       strcpy(temp->School,student.School);
     Head=temp; //Смена адреса начала списка
}
/*ФУНКЦИЯ КЛАССА LIST ДЛЯ ВЫВОДА СПИСКА НА ЭКРАН*/
void List::Show()
{
     Student *temp=Head; //Объявляем указатель и изначально он указывает на начало
     while (temp!=NULL) //Пока по адресу на начало хоть что-то есть
     {
     //Выводим все элементы структуры
         cout<<temp->Name<<"tt"; //Вывод имени
         cout<<temp->NameLast<<"tt"; //Вывод фамилии
         cout<<temp->Age<<"tt"; //Вывод возраста
         cout<<temp->School<<endl; //Вывод места учебы
    
         temp=temp->Next; //Указываем на следующий адрес из списка
     }
     cout<<endl;
}
int main ()
{
  Student student; //Обяъвили переменную, тип которой Студент
  int N;  //Объявили переменную - число студентов
  List lst; //Объявили переменную типа Список. Она выступает как контейнер данных
    cout<<"N = ";cin>>N; //Ввели число студентов
    cin.ignore(); //Игнорируем клавишу Enter
    for (int i=0;i<N;i++)
    {
     student.Input(student); //Передаем в функцию заполнения переменную студент
     lst.Add(student); //Добавляем заполненную структуру в список
    }
    cout<<endl;
    lst.Show(); //Показываем список на экране
  system("PAUSE");
} 