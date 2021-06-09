#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX = 50;
typedef struct{
    string name;
    string score;
    string time;
}tPlayer;

typedef tPlayer tArray [MAX];

typedef struct{
    tArray elements;
    int counter;
}tList;

int i;

void up_load_file(tList &lista);
void store_file(tList &lista);
void add_data (tList &lista);
void show_data(tList &lista);

int main()
{
  tList lista;
  lista.counter = 0;

  up_load_file(lista);
  add_data(lista);
  store_file(lista);
  show_data(lista);


 return 0;
}

void up_load_file (tList &lista)
{
    ifstream _file;
    _file.open("Puntajes_01_c++.bin", ios::in | ios::binary);
    if (_file.is_open())
    {
        while(!_file.eof())
            {
                _file >> lista.elements[lista.counter].name;
                _file.get();
                _file >> lista.elements[lista.counter].score;
                _file.get();
                _file >> lista.elements[lista.counter].time;

                if ((!lista.elements[lista.counter].name.empty())&&
                    (!lista.elements[lista.counter].score.empty()) &&
                    (!lista.elements[lista.counter].time.empty()))
                {
                    lista.counter++;
                }
            }
    }
     _file.close();
}

void store_file(tList &lista)
{
    ofstream _Ffile;
    _Ffile.open("Puntajes_01_c++.bin", ios::out | ios::binary);
    if (_Ffile.is_open())
    {
        for (i = 0; i < lista.counter; i++)
        {
            _Ffile << lista.elements[i].name << " "<< lista.elements[i].score << " " <<
            lista.elements[i].time << endl;
        }
    }
     _Ffile.close();
}

void add_data(tList &lista)
{

    if (lista.counter < MAX)
    {
        cout << "Ingrese nombre del participante: ";

        getline(cin, lista.elements[lista.counter].name);
        cout << "Ingrese puntaje del participante: ";
        getline(cin, lista.elements[lista.counter].score);
        cout << "Ingrese tiempo del participante: ";
        getline(cin, lista.elements[lista.counter].time);

        lista.counter = (lista.counter + 1);
    }
    else
        cout << "Maximo de participantes admitidos (50)" << endl;

}

void show_data(tList &lista)
{
    string name_, score_, time_;

    cout <<endl<< "PARTICIPANTES" << endl<<endl;
    for (i = 0; i < lista.counter; i++)
    {
        name_ = lista.elements[i].name;
        score_ = lista.elements[i].score;
        time_ = lista.elements[i].time;
        cout << name_<<endl
            <<"    Puntaje: " << score_<< endl
            << "    Tiempo: " << time_ << endl<< endl;
    }
}
