#include <iostream>
using namespace std;


class Observer{
public:
    virtual void Actualizar(){};
};

class Display{
public:
    virtual void MostrarDisplay()=0;
};

class Actuales : private Observer,private Display{
public:
    string Fecha;
    string Nombre;
public:
    void Actualizar(string date, string name);
    void MostrarDisplay();
};
void Actuales::Actualizar(string date, string name){
        Fecha=date;
        Nombre=name;
        MostrarDisplay();
}
void Actuales::MostrarDisplay()
{
    cout << "\nFecha: " << Fecha << endl;
    cout << "Recordatorio: " << Nombre << endl;
    cout << endl;
}

class Subject{
public:
    virtual void Registrar(Observer){};
    virtual void Eliminar()=0;
    virtual void Notificar()=0;
};

class Recordatorio:private Subject{
private:
    string nombre;
    string fecha;
    int contador;
    Actuales recordatorio[];
public:
    void Registrar(Actuales A);
    void Eliminar ();
    void Notificar ();

    Recordatorio();
    void Cambios();
    void SetRecordatorio(string,string);
};
void Recordatorio::Registrar(Actuales A){
    recordatorio[contador]=A;
    contador++;
}
void Recordatorio::Eliminar(){
    contador--;
}
void Recordatorio::Notificar(){
    for (int j=0;j<contador;j++){
        recordatorio[j].Actualizar(fecha,nombre);
    }
}
Recordatorio::Recordatorio(){
    contador = 0;
    nombre = "";
    fecha = "";
}
void Recordatorio::SetRecordatorio(string Nombre, string Fecha){
    nombre = Nombre;
    fecha = Fecha;
    Cambios();
}
void Recordatorio::Cambios(){
    Notificar();
}


int main()
{
    Actuales a;
    Recordatorio r;
    r.Registrar(a);

    r.SetRecordatorio("Levantarte","11/11/2020");
    r.SetRecordatorio("Hacer tarea","1/11/2020");
    r.SetRecordatorio("Jugar","11/11/2020");
    r.SetRecordatorio("Ver animemos","1/11/2020");

    r.Eliminar();
    r.Eliminar();


    return 0;
}
