#include <iostream>
using namespace std;

// -------------------------------- Atributos_Tareas
class Atributos_Tareas{
protected:
    string Titulo;
    string Fecha;
    bool Confirmacion;
};
// -------------------------------------------
// --------------------------------------------------- INTERFACE OBSERVER
class Observer{
public:
    virtual void Actualizar(string,string,bool){};
};
// ----------------------------------------------------------------------

// ------------------------------------------------ INTERFACE DISPLAY
class Display{
public:
    virtual void MostrarDisplay()=0;
};
// ------------------------------------------------------------------

// ---------- IMPLEMENTACION DE OBSERVER Y DISPLAY ------------------------------------------------------ ALUMNO
class AlumObserver:protected Observer,protected Atributos_Tareas, private Display{

public:
    void Actualizar(string,string,bool);
    void MostrarDisplay();
};
void AlumObserver::Actualizar(string tit, string fech, bool tarea){
    Titulo=tit;
    Fecha=fech;
    Confirmacion=tarea;
    MostrarDisplay();
}
void AlumObserver::MostrarDisplay(){
    cout << "-------------------------------" << endl;
    cout << "--------DISPLAY-ALUMNO---------" << endl;
    cout << "-------------------------------\n" << endl;
    Confirmacion?
    cout << "**** Nueva tarea por entregar ****\n Nombre: " << Titulo <<"\n Fecha: " << Fecha << "\n\n"<< endl:
    cout << "**** No hay tareas pendientes ****\n\n" << endl;
}
// -------------------------------------------------------------------------------------------------------------------

// ------------------------------------------------------------- IMPLEMENTACION DE OBSERVER Y DISPLAY -------- DOCENTE
class DoceObserver:private Observer, protected Atributos_Tareas, private Display{
public:
    void Actualizar(string,bool,string);
    void MostrarDisplay();
};
void DoceObserver::Actualizar(string t1, bool cal, string t2){
    Titulo=t1;
    Fecha=t2;
    Confirmacion=cal;
    MostrarDisplay();
}
void DoceObserver::MostrarDisplay(){
    cout << "-------------------------------" << endl;
    cout << "--------DISPLAY-DOCENTE--------" << endl;
    cout << "-------------------------------\n" << endl;
    Confirmacion?
    cout << "**** Nueva tarea para calificar ****\n Alumno: " << Titulo <<"\n Fecha de entrega: " << Fecha << "\n\n"<< endl:
    cout << "**** ¿Quieres dejar tarea? ****\n\n" << endl;
}
// ---------------------------------------------------------------------------------------------------------------------------

// ----------------------------------------------------INTERFACE SUBJECT
class Subject{
public:
    virtual void Registrar(Observer){}
    virtual void Eliminar(){};
    virtual void Notificar()=0;
};
// ------------------------------------------------------

//----------------------------------------------------------------------- IMPLEMENTACION DE LA CLASE SUBJECT EN TAREAS PARA EL DOCENTE
class Publicar_Tarea:private Subject,protected Atributos_Tareas{
    int contador=0;
    AlumObserver Alumno[];
public:
    void Registrar(AlumObserver A);
    void Eliminar(){contador--;}; // <---- Falta por mejorar esta condicion, solo es de prueba
    void Notificar();

    Publicar_Tarea();
    void CrearTarea(string T, string F);
    void CambiosP();
};
void Publicar_Tarea::Registrar(AlumObserver A){
    Alumno[contador]=A;
    contador++;
}
void Publicar_Tarea::Notificar(){
        for(int i=0;i<=contador;i++){
            this->Alumno[i].Actualizar(Titulo,Fecha,Confirmacion);}

}
Publicar_Tarea::Publicar_Tarea(){
    Titulo=" ";
    Fecha=" ";
    Confirmacion=false;
    contador=0;
}
void Publicar_Tarea::CrearTarea(string T,string F){
    Titulo=T;
    Fecha=F;
    Confirmacion=true;
    CambiosP();
}
void Publicar_Tarea::CambiosP(){
    this->Notificar();
}
// ----------------------------------------------------------------------------------------------------------

//---------------------------------- IMPLEMENTACION DE LA CLASE SUBJECT ENTREGA DE TAREAS PARA EL Alumno
class Entregar_Tarea:private Subject,protected Atributos_Tareas{
private:
    DoceObserver Docente;
public:
    void Registrar(DoceObserver D);
    //~Entregar_Tarea(){delete this->Docente;}
    void Notificar();

    Entregar_Tarea();
    void Entregar(string nombre, string fecha);
    void CambiosE();
};
void Entregar_Tarea::Registrar(DoceObserver D){
    Docente=D;
}
void Entregar_Tarea::Notificar(){
    Docente.Actualizar(Titulo,Confirmacion,Fecha);
}
void Entregar_Tarea::CambiosE(){
    this->Notificar();
}
Entregar_Tarea::Entregar_Tarea(){
    Titulo=" ";
    Fecha=" ";
    Confirmacion=false;
}
void Entregar_Tarea::Entregar(string nombre,string fecha){
    Titulo=nombre;
    Fecha=fecha;
    Confirmacion=true;
    this->Notificar();
}

// ------------------------------------------------------------------------------------------------------
int main(){
    //ALUMNOS
    AlumObserver Alumno_1;
    AlumObserver Alumno_2;
    AlumObserver Alumno_3;
    //DOCENTE
    DoceObserver Docente;
    //TAREAS
    Publicar_Tarea Plataforma;
    Entregar_Tarea Ventana;
    //REGISTRO DE DOCENTES
    Ventana.Registrar(Docente);
    //REGISTRO DE ALUMNOS
    Plataforma.Registrar(Alumno_1);
    Plataforma.Registrar(Alumno_2);
    cout<<"\n----------- PROFESOR NO HA CREADO UNA TAREA -------------------" << endl;
    cout<<"-------------- SOLO 2 ALUMNOS REGISTRADOS -----------------------\n" << endl;
    Plataforma.CambiosP();
    Ventana.CambiosE();
    Plataforma.Registrar(Alumno_3);
    cout<<"\n------------ PROFESOR CREA UNA TAREA --------------------------" << endl;
    cout<<"-------------- SOLO 3 ALUMNOS REGISTRADOS -----------------------\n" << endl;
    Plataforma.CrearTarea("Codigo HTML","20 de noviembre de 2020");
    cout<<"\n------------ ALUMNO ENTREGA UNA TAREA --------------------------\n" << endl;
    Ventana.Entregar("Juan Perez","07 de octubre de 2020");
    return 0;
}
