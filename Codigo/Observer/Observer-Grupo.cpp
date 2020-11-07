#include <iostream>
using namespace std;
// ------------------------------ INTERFACE Observer
class Observer{
public:
    virtual void Actualizar(){};
};
// --------------------------------------------

// ----------------------------------- INTERFACE DISPLAY
class Display{
public:
    virtual void MostrarDisplay()=0;
};
//---------------------------------------------
// ------------------------------ Implementacion de Observer y Display
class Alumno:private Observer,private Display{
public:
    string Fecha;
    string Nombre;
    string Mensaje;
public:
    void Actualizar(string date, string name,string men);
    void MostrarDisplay();
};
void Alumno::Actualizar(string date, string name,string men){
        Fecha=date;
        Nombre=name;
        Mensaje=men;
        MostrarDisplay();
}
void Alumno::MostrarDisplay()
{
    cout << "\nFecha: " << Fecha << endl;
    cout << "Remitente: " << Nombre << endl;
    cout << "Mensaje: " << Mensaje << endl;
    cout << endl;
}
//------------------------------------------------------------------------

//--------------------------INTERFACE SUBJECT
class Subject{
public:
    virtual void Registrar(Observer){};
    virtual void Eliminar()=0;  //<----- SOLO ES PARA EL CONCEPTO
    virtual void Notificar()=0;
};
// --------------------------------------------

//------------------------------------ IMPLEMENTACION DE LA INTERFACE SUBJECT
class Grupo:private Subject{
private:
    string nombre;
    string mensaje;
    string fecha;
    int contador;
    Alumno personas[];
public:
    void Registrar(Alumno A);
    void Eliminar (); //<----- SOLO ES PARA EL CONCEPTO
    void Notificar ();

    Grupo();
    void Cambios();
    void MandarMensaje(string,string,string);
};
void Grupo::Registrar(Alumno A){
    personas[contador]=A;
    contador++;
}
void Grupo::Eliminar(){
    contador--;
}
void Grupo::Notificar(){
    for (int j=0;j<contador;j++){
        personas[j].Actualizar(fecha,nombre, mensaje);
    }
}
Grupo::Grupo(){
    contador = 0;
    nombre = "";
    fecha = "";
    mensaje = "";
}
void Grupo::MandarMensaje(string Nombre,string Mensaje, string Fecha){
    nombre = Nombre;
    fecha = Fecha;
    mensaje = Mensaje;
    Cambios();
}
void Grupo::Cambios(){
    Notificar();
}
// -------------------------------------------------------------------------
int main()
{
    //CREAR ALUMNOS
    Alumno A1;
    Alumno A2;
    Alumno A3;
    Alumno A4;
    //GRUPO
    Grupo AmigosA;
    //Registrar 2 Alumnos
    AmigosA.Registrar(A1);
    AmigosA.Registrar(A2);
    cout << "\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<< endl;
    cout << "^^^^^^^^^^^   MANDAR MENSAJE  ^^^^^^^^^^^^"<< endl;
    cout << "^^^^^^^^^^^^   2 INTEGRANTES   ^^^^^^^^^^^"<< endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"<< endl;
    AmigosA.MandarMensaje("Carlos","Hola amigos!!!","21/11/2020");
    //Registrar más alumnos
    AmigosA.Registrar(A3);
    AmigosA.Registrar(A4);
    cout << "\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<< endl;
    cout << "^^^^^^^^^^^   MANDAR MENSAJE  ^^^^^^^^^^^^"<< endl;
    cout << "^^^^^^^^^^^^   4 INTEGRANTES   ^^^^^^^^^^^"<< endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"<< endl;
    AmigosA.MandarMensaje("Brian","¿Como estas?","21/11/2020");
    return 0;
}
