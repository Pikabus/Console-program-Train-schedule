//�������� ������_������ �������_���-832_2019 ���
#include <iostream>     //����������� ���������� ��� ���������� ����� � ������
#include <clocale>      //����������� ���������� ��� ��������� �������� ����� � ���������
#include <string>       //����������� ���������� ��� ������������� ���� ������ string � ���������
#include <vector>       //����������� ���������� ��� ������������� ��������� ������ vector
#include <fstream>      //����������� ���������� ��� ������ � �������
#include <string.h>     //����������� ���������� ��� ������ �� ��������
#include <iomanip>      //����������� ���������� ��� �������������� ������
#include <windows.h>    //����������� ���������� ��� ��������� ��������� � �������

using namespace std;    //���������� ������������ ���

struct TRAINS   //���������� � �������� ��������� TRAINS
{
    string departure;   //���� �����������
    string destination; //���� ����������
    int number;         //���� ����� ������
    string day;         //���� ���� ����������� ������
    float time;         //���� ����� ����������� ������
};
struct TRAINDES //���������� � �������� ��������� TRAINDES
{
    string departure;   //���� �����������
    string destination; //���� ����������
    int number;         //���� ����� ������
    string day;         //���� ���� ����������� ������
    float time;         //���� ����� ����������� ������
    int daynumber;      //���� ����� ��� ������ �����������
};
struct TRAINSORT    //���������� � �������� ��������� TRAINSORT
{
    string departure;   //���� �����������
    string destination; //���� ����������
    int number;         //���� ����� ������
    string day;         //���� ���� ����������� ������
    float time;         //���� ����� ����������� ������
};

vector<TRAINS> v;           //���������� ������� ��� �������� ����������
TRAINS train;               //���������� ������� ��� ��������� TRAINS
vector<TRAINDES> vdes;      //���������� ������� ��� �������� ���������� ����� ���������� �� ������� ����������
TRAINDES traindes;          //���������� ������� ��� ��������� TRAINDES
vector<TRAINSORT> vsort;    //���������� ������� ��� �������� ���������� ����� ���������� �� ������� ����������� � ����������
TRAINSORT trainsort;        //���������� ������� ��� ��������� TRAINSORT
int i, j;                   //���������� ���������� ���������� ��� ������������� ������� for() � ����� ����� ���������
string destination;         //���������� ���������� ��� ����� ������ ����������
bool check = false;         //���������� ���������� ��� �������� �� ���������� �������� �����

void Outputdata();  //���������� ������� ����� ���������� ������� �� ����� �� �����
void Sorting();     //���������� ������� ���������� ���������� ������� �� ������� ����������� � ����������
void Inf();         //���������� ������� ������ ����������
void Departure();   //���������� ������� �� ������� �����������
void Timeday();     //���������� ������� ����� �� ���� � �������
void Destination(); //���������� ������� �� ������� ����������
void Menu();        //���������� ������� ���� ������������
void Infsort();     //���������� ������� ����� ���������� ����� ���������� �� ������� ����������� � ����������
void Infdes();      //���������� ������� ����� ���������� �� ������� ����������
void Pole();        //���������� ������� ���������� ���������� �� ���� ������

int main()
{   //������ ���������
    SetConsoleCP(1251);         //��������� ��������� ����� � �������
    SetConsoleOutputCP(1251);   //��������� ��������� ������ � �������

    setlocale(LC_ALL, "Russian");   //��������� �������� ����� � ���������

    Outputdata();   //����� ������� ����� ���������� ������� �� ����� �� �����
    Menu();         //����� ������� ���� ������������

    return 0;
}   //����� ���������
//�������� ������� ����� ���������� ������� �� ����� �� �����
void Outputdata()
{
    ifstream F("data.txt"); //�������� ����� � �����������
    if(!F) cout<<"������! ���� � ������� �� ������!"<<endl; //����� ������ ��� ���������� ����� � �����������
    while (F)
    {   //���������� ����� ������� train � ���������� ��� � ������ v ���� ������� � ����� �� �����������
        F>>train.departure;
        F>>train.destination;
        F>>train.number;
        F>>train.day;
        F>>train.time;
        v.push_back(train);
    }
    F.close();  //�������� ����� � �����������
    Inf();  //����� ������� ������ ����������
}
//�������� ������� ������ ����������
void Inf()
{   //����� ����� ����������
    cout<<setw(20)<<left<<"�����������";
    cout<<setw(20)<<left<<"����������";
    cout<<setw(10)<<left<<"�����";
    cout<<setw(15)<<left<<"����";
    cout<<setw(10)<<left<<"�����"<<endl;
    cout<<"_______________________________________________________________________"<<endl;
    for(i = 0;i < v.size()-1;i++)
    {   //����� ������� ���������� ������� �� ������� v
        cout<<setw(20)<<left<<v[i].departure;
        cout<<setw(20)<<left<<v[i].destination;
        cout<<setw(10)<<left<<v[i].number;
        cout<<setw(15)<<left<<v[i].day;
        cout<<setw(6)<<left<<setprecision(2)<<fixed<<v[i].time<<endl;
    }
    cout<<endl;
}
//�������� ������� ���������� ���������� ������� �� ������� ����������� � ����������
void Sorting()
{
    for(i = 0;i < v.size();i++)
    {   //���������� ����� ������� trainsort � ���������� ��� � ������ vsort �� ������� v
        trainsort.departure = v[i].departure;
        trainsort.destination = v[i].destination;
        trainsort.number = v[i].number;
        trainsort.day = v[i].day;
        trainsort.time = v[i].time;
        vsort.push_back(trainsort);
    }
    //���������� ���������� ���������� �� ������� ����������� � ����������
    for(i = 0;i < vsort.size()-2;i++)
        for(j = 0;j < vsort.size()-i-2;j++)
            if(strcmp(vsort[j].departure.c_str(), vsort[j+1].departure.c_str()) > 0)
                swap(vsort[j], vsort[j+1]); //����� ����� ���������� ��� ���������� ������� ����������
            else    if(strcmp(vsort[j].departure.c_str(), vsort[j+1].departure.c_str()) == 0 && strcmp(vsort[j].destination.c_str(), vsort[j+1].destination.c_str()) > 0)
                        swap(vsort[j], vsort[j+1]); //����� ����� ���������� ��� ���������� ������� ����������
    Infsort(); //����� ������� ����� ���������� ����� ���������� �� ������� ����������� � ����������
    Menu();    //����� ������� ���� ������������
}
//�������� ������� ����� ���������� ����� ���������� �� ������� ���������� � ����������
void Infsort()
{   //����� ����� ����������
    cout<<setw(20)<<left<<"�����������";
    cout<<setw(20)<<left<<"����������";
    cout<<setw(10)<<left<<"�����";
    cout<<setw(15)<<left<<"����";
    cout<<setw(10)<<left<<"�����"<<endl;
    cout<<"_______________________________________________________________________"<<endl;
    for(i = 0;i < vsort.size()-1;i++)
    {   //����� ���������� ����� ���������� �� ������� ���������� � ����������
        cout<<setw(20)<<left<<vsort[i].departure;
        cout<<setw(20)<<left<<vsort[i].destination;
        cout<<setw(10)<<left<<vsort[i].number;
        cout<<setw(15)<<left<<vsort[i].day;
        cout<<setw(6)<<left<<setprecision(2)<<fixed<<vsort[i].time<<endl;
    }
    cout<<endl;
    vsort.clear();  //������� ������� ��� ���������� �������������
}
//�������� ������� ����� �� ���� � �������
void Timeday()
{
    int ch = 0; //���������� ���������� ��� ������������ ������ ����� ����������
    string day; //���������� ���������� ��� ����� ��� ������
    float time; //���������� ���������� ��� ����� ������� ������

    cout<<"���� => ";
    cin>>day;   //���� ��� ������
    cout<<"����� => ";
    cin>>time;  //���� ������� ������
    while(!cin)
    {   //������ �� ������������� �����
        cin.clear();
        fflush(stdin);
        cout<<"������! ������� ����� =>";
        cin>>time;
    }
    //������ ������ �� �������� ��� � ������� � ����� ��������� ����������
    for(i = 0;i < v.size()-1;i++)
        if(day == v[i].day && time < v[i].time)
        {
            if(ch == 0)
            {   //����������� ����� ����� ����������
                cout<<setw(20)<<"�����������";
                cout<<setw(20)<<"����������";
                cout<<setw(10)<<"�����";
                cout<<setw(15)<<"����";
                cout<<setw(6)<<"�����"<<endl;
                cout<<"_______________________________________________________________________"<<endl;
                ch++;
            }   //����� ��������� ������� �� ��������� ��� � �������
            cout<<setw(20)<<left<<v[i].departure;
            cout<<setw(20)<<left<<v[i].destination;
            cout<<setw(10)<<left<<v[i].number;
            cout<<setw(15)<<left<<v[i].day;
            cout<<setw(6)<<left<<setprecision(2)<<fixed<<v[i].time<<endl;
            check = true;
        }
    if(!check) cout<<"������! ���� ����� �������!"<<endl;   //����� ������ ��� ���������� ����������
    cout<<endl;
    check = false;  //��������� ���������� ��� ���������� �������������
    //����� ������ � ������ ��������� ����������
}
//�������� ������� �� ������� �����������
void Departure()
{
    int ch = 0;         //���������� ���������� ��� ������������ ������ ����� �������
    string departure;   //���������� ���������� ��� ����� ������ �����������

    cout<<"����������� => ";
    cin>>departure; //���� ������ �����������
    if(departure[0] > '�' && departure[0] < '�')
        departure[0] -= 32; //��������� �������� ������� ������� ��� �������� ����� ������������
    //����� ���������� �� ��������� ������ �����������
    for(i = 0;i < v.size()-1;i++)
    {
        if(departure == v[i].departure)
        {
            if(ch == 0)
            {   //����������� ����� ����� �������
                cout<<setw(20)<<left<<"�����������";
                cout<<setw(20)<<left<<"����������";
                cout<<setw(10)<<left<<"�����";
                cout<<setw(15)<<left<<"����";
                cout<<setw(10)<<left<<"�����"<<endl;
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
    if(!check) cout<<"������! ���� ����� �������!"<<endl;   //����� ������ ��� ���������� ����������
    cout<<endl;
    check = false;  //��������� ���������� ��� ���������� �������������
}
//�������� ������� �� ������� ����������
void Destination()
{
    cout<<"����������� => ";
    cin>>destination;   //���� ������ ����������
    if(destination[0] > '�' && destination[0] < '�')
        destination[0] -= 32;   //��������� �������� ������� ������� ��� �������� ����� ������������
    //���������� ������� vdes �� ��������� ������ ����������
    Pole();
    //������ ���������� �� ������� ����������
    if(!check) cout<<"������! ���� ����� �������!"<<endl;   //����� ������ ��� ���������� ����������
    else   //����� ������ ���������� ��������� ������� �� ��������� ������ ����������
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
        Infdes();   //����� ������� ����� ���������� �� ������� ����������
    }
    check = false;  //��������� ���������� ��� ���������� �������������
}
//�������� ��������������� ������� ��� ���������� ���������� �� ���� ������
void Pole()
{   //���������� ���� daynumber ������� vdes
    for(i = 0;i < v.size()-1;i++)
        if(destination == v[i].destination)
        {
            traindes.departure = v[i].departure;
            traindes.destination = v[i].destination;
            traindes.number = v[i].number;
            traindes.day = v[i].day;
            traindes.time = v[i].time;
            if(v[i].day == "�����������") traindes.daynumber = 1;
            else if(v[i].day == "�������") traindes.daynumber = 2;
                 else if(v[i].day == "�����") traindes.daynumber = 3;
                      else if(v[i].day == "�������") traindes.daynumber = 4;
                           else if(v[i].day == "�������") traindes.daynumber = 5;
                                else if(v[i].day == "�������") traindes.daynumber = 6;
                                     else traindes.daynumber = 7;
            vdes.push_back(traindes);
            check = true;
        }
}
//�������� ������� ����� ���������� �� ������� ����������
void Infdes ()
{       //����� ����� ����������
        cout<<setw(20)<<left<<"�����������";
        cout<<setw(20)<<left<<"����������";
        cout<<setw(10)<<left<<"�����";
        cout<<setw(15)<<left<<"����";
        cout<<setw(10)<<left<<"�����"<<endl;
        cout<<"_______________________________________________________________________"<<endl;
        for(i=0;i<vdes.size();i++)
        {   //����� ���������������� ������� vdes
            cout<<setw(20)<<left<<vdes[i].departure;
            cout<<setw(20)<<left<<vdes[i].destination;
            cout<<setw(10)<<left<<vdes[i].number;
            cout<<setw(15)<<left<<vdes[i].day;
            cout<<setw(6)<<left<<setprecision(2)<<fixed<<vdes[i].time<<endl;
        }
        vdes.clear();   //������� ������� vdes ��� ���������� �������������
        cout<<endl;
}
//�������� ������� ���� ������������
void Menu()
{
    int a = 1;  //���������� ���������� ��� ������ ����������� �������� �������������
    while (a != 6)
    {   //����� ��������� ������������ ��������
        cout<<"���������� �������� �������"<<endl;
        cout<<"************************************"<<endl;
        cout<<"������ ���������� -> ������� 1"<<endl;
        cout<<"�� ������� ����������� -> ������� 2"<<endl;
        cout<<"����� �� ���� � ������� -> ������� 3"<<endl;
        cout<<"�� ������� ���������� -> ������� 4"<<endl;
        cout<<"���������� �� ������� ����������� -> ������� 5"<<endl;
        cout<<"����� �� ���� -> ������� 6"<<endl;
        //���� ���������� �������� � ����� ������� ������������ �� ������
        cin>>a;
        //������ �� ������������� �����
        while(!cin)
        {
            cin.clear();
            fflush(stdin);
            cout<<"������! ������� ����� �� 1 �� 6:"<<endl<<endl;
            Menu();
        }
        switch (a)
        {
        case 1:
            Inf();          //����� ������� ������ ����������
            break;
        case 2:
            Departure();    //����� ������� �� ������� �����������
            break;
        case 3:
            Timeday();      //����� ������� ����� �� ���� � �������
            break;
        case 4:
            Destination();  //����� ������� �� ������� ����������
            break;
        case 5:
            Sorting();      //����� ������� ���������� �� ������� ����������� � ����������
            break;
        case 6:
            return;         //����� �� ���������
        default:
            cout<<endl<<"������� ����� �� 1 �� 6: "<<endl;  //����� ������ ��� ������������ �����
            break;
        }
    }
}
