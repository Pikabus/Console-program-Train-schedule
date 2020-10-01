//Курсовая работа_Орехов Аркадий_ИСТ-832_2019 год
#include <iostream>     //подключение библиотеки для потокового ввода и вывода
#include <clocale>      //подключение библиотеки для настройки русского языка в программе
#include <string>       //подключение библиотеки для использования типа данных string в программе
#include <vector>       //подключение библиотеки для использования структуры данных vector
#include <fstream>      //подключение библиотеки для работы с файлами
#include <string.h>     //подключение библиотеки для работы со строками
#include <iomanip>      //подключение библиотеки для форматирования вывода
#include <windows.h>    //подключение библиотеки для установки кодировки в консоли

using namespace std;    //объявление пространства имён

struct TRAINS   //объявление и описание структуры TRAINS
{
    string departure;   //поле отправление
    string destination; //поле назначение
    int number;         //поле номер поезда
    string day;         //поле день отправления поезда
    float time;         //поле время отправления поезда
};
struct TRAINDES //объявление и описание структуры TRAINDES
{
    string departure;   //поле отправление
    string destination; //поле назначение
    int number;         //поле номер поезда
    string day;         //поле день отправления поезда
    float time;         //поле время отправления поезда
    int daynumber;      //поле номер дня недели отправления
};
struct TRAINSORT    //объявление и описание структуры TRAINSORT
{
    string departure;   //поле отправление
    string destination; //поле назначение
    int number;         //поле номер поезда
    string day;         //поле день отправления поезда
    float time;         //поле время отправления поезда
};

vector<TRAINS> v;           //объявление вектора для хранения расписания
TRAINS train;               //объявление объекта для структуры TRAINS
vector<TRAINDES> vdes;      //объявление вектора для хранения расписания после сортировки По пунктам назначения
TRAINDES traindes;          //объявление объекта для структуры TRAINDES
vector<TRAINSORT> vsort;    //объявление вектора для хранения расписания после сортировки По пунктам отправления и назначения
TRAINSORT trainsort;        //объявление объекта для структуры TRAINSORT
int i, j;                   //объявление глобальных переменных для использования функции for() в любом месте программы
string destination;         //объявление переменной для ввода пункта назначения
bool check = false;         //объявление переменной для проверки на отсутствие введённых полей

void Outputdata();  //объявление функции Вывод расписания поездов из файла на экран
void Sorting();     //объявление функции Сортировка расписания поездов по пунктам отправления и назначения
void Inf();         //объявление функции Полная информация
void Departure();   //объявление функции По пунктам отправления
void Timeday();     //объявление функции Поиск по дням и времени
void Destination(); //объявление функции По пунктам назначения
void Menu();        //объявление функции Меню пользователя
void Infsort();     //объявление функции Вывод расписания после сортировки по пунктам отправления и назначения
void Infdes();      //объявление функции Вывод расписания По пунктам назначения
void Pole();        //объявление функции Сортировка расписания по дням недели

int main()
{   //начало программы
    SetConsoleCP(1251);         //установка кодировки ввода в консоли
    SetConsoleOutputCP(1251);   //установка кодировки вывода в консоли

    setlocale(LC_ALL, "Russian");   //настройка русского языка в программе

    Outputdata();   //вызов функции Вывод расписания поездов из файла на экран
    Menu();         //вызов функции Меню пользователя

    return 0;
}   //конец программы
//описание функции Вывод расписания поездов из файла на экран
void Outputdata()
{
    ifstream F("data.txt"); //открытие файла с расписанием
    if(!F) cout<<"Ошибка! Файл с данными не найден!"<<endl; //вывод ошибки при отсутствии файла с расписанием
    while (F)
    {   //заполнение полей объекта train и добавление его в вектор v пока символы в файле не закончились
        F>>train.departure;
        F>>train.destination;
        F>>train.number;
        F>>train.day;
        F>>train.time;
        v.push_back(train);
    }
    F.close();  //закрытие файла с расписанием
    Inf();  //вызов функции Полная информация
}
//описание функции Полная информация
void Inf()
{   //вывод шапки расписания
    cout<<setw(20)<<left<<"ОТПРАВЛЕНИЕ";
    cout<<setw(20)<<left<<"НАЗНАЧЕНИЕ";
    cout<<setw(10)<<left<<"ПОЕЗД";
    cout<<setw(15)<<left<<"ДЕНЬ";
    cout<<setw(10)<<left<<"ВРЕМЯ"<<endl;
    cout<<"_______________________________________________________________________"<<endl;
    for(i = 0;i < v.size()-1;i++)
    {   //вывод полного расписания поездов из вектора v
        cout<<setw(20)<<left<<v[i].departure;
        cout<<setw(20)<<left<<v[i].destination;
        cout<<setw(10)<<left<<v[i].number;
        cout<<setw(15)<<left<<v[i].day;
        cout<<setw(6)<<left<<setprecision(2)<<fixed<<v[i].time<<endl;
    }
    cout<<endl;
}
//описание функции Сортировка расписания поездов по пунктам отправления и назначения
void Sorting()
{
    for(i = 0;i < v.size();i++)
    {   //заполнение полей объекта trainsort и добавление его в вектор vsort из вектора v
        trainsort.departure = v[i].departure;
        trainsort.destination = v[i].destination;
        trainsort.number = v[i].number;
        trainsort.day = v[i].day;
        trainsort.time = v[i].time;
        vsort.push_back(trainsort);
    }
    //сортировка расписания расписания по пунктам отправления и назначения
    for(i = 0;i < vsort.size()-2;i++)
        for(j = 0;j < vsort.size()-i-2;j++)
            if(strcmp(vsort[j].departure.c_str(), vsort[j+1].departure.c_str()) > 0)
                swap(vsort[j], vsort[j+1]); //обмен строк расписания при выполнении условия сортировки
            else    if(strcmp(vsort[j].departure.c_str(), vsort[j+1].departure.c_str()) == 0 && strcmp(vsort[j].destination.c_str(), vsort[j+1].destination.c_str()) > 0)
                        swap(vsort[j], vsort[j+1]); //обмен строк расписания при выполнении условий сортировки
    Infsort(); //вызов функции Вывод расписания после сортировки по пунктам отправления и назначения
    Menu();    //вызов функции Меню пользователя
}
//описание функции Вывод расписания после сортировки по пунктам отпрвления и назначения
void Infsort()
{   //вывод шапки расписания
    cout<<setw(20)<<left<<"ОТПРАВЛЕНИЕ";
    cout<<setw(20)<<left<<"НАЗНАЧЕНИЕ";
    cout<<setw(10)<<left<<"ПОЕЗД";
    cout<<setw(15)<<left<<"ДЕНЬ";
    cout<<setw(10)<<left<<"ВРЕМЯ"<<endl;
    cout<<"_______________________________________________________________________"<<endl;
    for(i = 0;i < vsort.size()-1;i++)
    {   //вывод расписания после сортировки по пунктам отпрвления и назначения
        cout<<setw(20)<<left<<vsort[i].departure;
        cout<<setw(20)<<left<<vsort[i].destination;
        cout<<setw(10)<<left<<vsort[i].number;
        cout<<setw(15)<<left<<vsort[i].day;
        cout<<setw(6)<<left<<setprecision(2)<<fixed<<vsort[i].time<<endl;
    }
    cout<<endl;
    vsort.clear();  //очистка вектора для повторного использования
}
//описание функции Поиск по дням и времени
void Timeday()
{
    int ch = 0; //объявление переменной для однократного вывода шапки расписания
    string day; //объявление переменной для ввода дня поиска
    float time; //объявление переменной для ввода времени поиска

    cout<<"День => ";
    cin>>day;   //ввод дня поиска
    cout<<"Время => ";
    cin>>time;  //ввод времени поиска
    while(!cin)
    {   //защита от некорректного ввода
        cin.clear();
        fflush(stdin);
        cout<<"Ошибка! Введите Время =>";
        cin>>time;
    }
    //начало поиска по введённым дню и времени и вывод найденной информации
    for(i = 0;i < v.size()-1;i++)
        if(day == v[i].day && time < v[i].time)
        {
            if(ch == 0)
            {   //однократный вывод шапки расписания
                cout<<setw(20)<<"ОТПРАВЛЕНИЕ";
                cout<<setw(20)<<"НАЗНАЧЕНИЕ";
                cout<<setw(10)<<"ПОЕЗД";
                cout<<setw(15)<<"ДЕНЬ";
                cout<<setw(6)<<"ВРЕМЯ"<<endl;
                cout<<"_______________________________________________________________________"<<endl;
                ch++;
            }   //вывод найденных поездов по введённому дню и времени
            cout<<setw(20)<<left<<v[i].departure;
            cout<<setw(20)<<left<<v[i].destination;
            cout<<setw(10)<<left<<v[i].number;
            cout<<setw(15)<<left<<v[i].day;
            cout<<setw(6)<<left<<setprecision(2)<<fixed<<v[i].time<<endl;
            check = true;
        }
    if(!check) cout<<"Ошибка! Нету таких поездов!"<<endl;   //вывод ошибки при отсутствии информации
    cout<<endl;
    check = false;  //обнуление переменной для повторного использования
    //конец поиска и вывода найденной информации
}
//описание функции По пунктам отправления
void Departure()
{
    int ch = 0;         //объявление переменной для однократного вывода шапки таблицы
    string departure;   //объявление переменной для ввода пунтка отправления

    cout<<"Отправление => ";
    cin>>departure; //ввод пункта отправления
    if(departure[0] > 'а' && departure[0] < 'я')
        departure[0] -= 32; //повышение регистра первого символа для удобства ввода пользователю
    //вывод расписания по введённому пункту отправления
    for(i = 0;i < v.size()-1;i++)
    {
        if(departure == v[i].departure)
        {
            if(ch == 0)
            {   //однократный вывод шапки таблицы
                cout<<setw(20)<<left<<"ОТПРАВЛЕНИЕ";
                cout<<setw(20)<<left<<"НАЗНАЧЕНИЕ";
                cout<<setw(10)<<left<<"ПОЕЗД";
                cout<<setw(15)<<left<<"ДЕНЬ";
                cout<<setw(10)<<left<<"ВРЕМЯ"<<endl;
                cout<<"_______________________________________________________________________"<<endl;
                ch++;
            }
            cout<<setw(20)<<left<<v[i].departure;
            cout<<setw(20)<<left<<v[i].destination;
            cout<<setw(10)<<left<<v[i].number;
            cout<<setw(15)<<left<<v[i].day;
            cout<<setw(6)<<left<<v[i].time<<endl;
            check = true;
        }
    }
    if(!check) cout<<"Ошибка! Нету таких поездов!"<<endl;   //вывод ошибки при отсутствии информации
    cout<<endl;
    check = false;  //обнуление переменной для повторного использования
}
//описание функции По пунктам назначения
void Destination()
{
    cout<<"Направление => ";
    cin>>destination;   //ввод пункта назначения
    if(destination[0] > 'а' && destination[0] < 'я')
        destination[0] -= 32;   //повышение регистра первого символа для удобства ввода пользователю
    //заполнение вектора vdes по введённому пункту назначения
    Pole();
    //начало сортировки по пунктам назначения
    if(!check) cout<<"Ошибка! Нету таких поездов!"<<endl;   //вывод ошибки при отсутствии информации
    else   //иначе начало сортировки найденных поездов по введённому пунтку назначения
    {
        if(vdes.size() > 2)
        {
            for(i = 0;i < vdes.size()-2;i++)
                for(j = 0;j < vdes.size()-i-2;j++)
                    if(vdes[j].daynumber > vdes[j+1].daynumber)
                        swap(vdes[j], vdes[j+1]);
                    else
                        if(vdes[j].daynumber == vdes[j+1].daynumber && vdes[j].time < vdes[j+1].time)
                            swap(vdes[j], vdes[j+1]);
        }
        else
            if(vdes.size() == 2 && vdes[0].daynumber > vdes[1].daynumber)
                swap(vdes[0], vdes[1]);
            else
                if(vdes[0].daynumber == vdes[1].daynumber && vdes[0].time > vdes[1].time)
                    swap(vdes[0], vdes[1]);
        Infdes();   //вызов функции Вывод расписания По пунктам назначения
    }
    check = false;  //обнуление переменной для повторного использования
}
//описание вспомогательной функции для сортировки расписания по дням недели
void Pole()
{   //заполнение поля daynumber вектора vdes
    for(i = 0;i < v.size()-1;i++)
        if(destination == v[i].destination)
        {
            traindes.departure = v[i].departure;
            traindes.destination = v[i].destination;
            traindes.number = v[i].number;
            traindes.day = v[i].day;
            traindes.time = v[i].time;
            if(v[i].day == "понедельник") traindes.daynumber = 1;
            else if(v[i].day == "вторник") traindes.daynumber = 2;
                 else if(v[i].day == "среда") traindes.daynumber = 3;
                      else if(v[i].day == "четверг") traindes.daynumber = 4;
                           else if(v[i].day == "пятница") traindes.daynumber = 5;
                                else if(v[i].day == "суббота") traindes.daynumber = 6;
                                     else traindes.daynumber = 7;
            vdes.push_back(traindes);
            check = true;
        }
}
//описание функции Вывод расписания По пунктам назначения
void Infdes ()
{       //вывод шапки расписания
        cout<<setw(20)<<left<<"ОТПРАВЛЕНИЕ";
        cout<<setw(20)<<left<<"НАЗНАЧЕНИЕ";
        cout<<setw(10)<<left<<"ПОЕЗД";
        cout<<setw(15)<<left<<"ДЕНЬ";
        cout<<setw(10)<<left<<"ВРЕМЯ"<<endl;
        cout<<"_______________________________________________________________________"<<endl;
        for(i=0;i<vdes.size();i++)
        {   //вывод отсортированного вектора vdes
            cout<<setw(20)<<left<<vdes[i].departure;
            cout<<setw(20)<<left<<vdes[i].destination;
            cout<<setw(10)<<left<<vdes[i].number;
            cout<<setw(15)<<left<<vdes[i].day;
            cout<<setw(6)<<left<<setprecision(2)<<fixed<<vdes[i].time<<endl;
        }
        vdes.clear();   //очистка вектора vdes для повторного использования
        cout<<endl;
}
//описание функции Меню пользователя
void Menu()
{
    int a = 1;  //объявление переменной для выбора дальнейшего действия пользователем
    while (a != 6)
    {   //вывод доступных пользователю действий
        cout<<"РАСПИСАНИЕ ДВИЖЕНИЯ ПОЕЗДОВ"<<endl;
        cout<<"************************************"<<endl;
        cout<<"Полная информация -> нажмите 1"<<endl;
        cout<<"По пунктам отправления -> нажмите 2"<<endl;
        cout<<"Поиск по дням и времени -> нажмите 3"<<endl;
        cout<<"По пунктам назначения -> нажмите 4"<<endl;
        cout<<"Сортировка по пунктам отправления -> нажмите 5"<<endl;
        cout<<"Выход из меню -> нажмите 6"<<endl;
        //ввод выбранного действия и вызов функции взависимости от выбора
        cin>>a;
        //защита от некорректного ввода
        while(!cin)
        {
            cin.clear();
            fflush(stdin);
            cout<<"Ошибка! Введите число от 1 до 6:"<<endl<<endl;
            Menu();
        }
        switch (a)
        {
        case 1:
            Inf();          //вызов функции Полная информация
            break;
        case 2:
            Departure();    //вызов функции По пунктам отправления
            break;
        case 3:
            Timeday();      //вызов функции Поиск по дням и времени
            break;
        case 4:
            Destination();  //вызов функции По пунктам назначения
            break;
        case 5:
            Sorting();      //вызов функции Сортировка по пунктам отправления и назначения
            break;
        case 6:
            return;         //выход из программы
        default:
            cout<<endl<<"Введите число от 1 до 6: "<<endl;  //вывод ошибки при некорректном вводе
            break;
        }
    }
}
