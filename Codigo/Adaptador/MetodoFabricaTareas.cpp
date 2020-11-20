#include <iostream>

 using namespace std;
 //Product
 class Tarea
 {
    public:
    string materia;
	string rubrica;
	int calificacionMax;
	string contenido;

    void set_Materia( string materia) {this->materia = materia;}
    void set_contenido(string contenido) { this->contenido = contenido; }
	string get_contenido() { return contenido; }
    void set_rubrica(string rubrica) { this->rubrica = rubrica;}
    string get_rubrica() { return rubrica; }
    void set_calificacionMax(int calificacionMax) { this->calificacionMax = calificacionMax; }
    int get_calificacionMax() { return calificacionMax; }
    void mostrar();
 };
 void Tarea::mostrar()
{
    cout<<"Materia: "<<materia<<endl;
    cout<<"Rubrica: "<<rubrica<<endl;
    cout<<"Calificacion: "<<calificacionMax<<endl;
    cout<<"Contenido: "<<contenido<<endl<<endl;

}

class ProgresoTarea : public Tarea
{
public:

    ProgresoTarea();
    float progreso=0;
    float progresoaux=0;
    int partes=1;
    void set_partes(int x){partes = x;}
    int get_partes(){return partes;}

    void actualizarProgreso(bool x);
    float get_progreso(){return progreso;}
    void Mostrar();
};

ProgresoTarea::ProgresoTarea()
{
    calificacionMax=10;
    partes = 1;
    progreso = 0;
    progresoaux;
}

void ProgresoTarea::actualizarProgreso(bool c)
{
    if(c == true)
    {
        progresoaux++;
        progreso = progresoaux/partes*10;
    }
}



//ConcreteProduct
 class TareaMatematicas : public ProgresoTarea
 {
    public:
        TareaMatematicas();
 };


TareaMatematicas::TareaMatematicas()
{
    materia = "Matematicas";
    rubrica = "***********";
    calificacionMax = 10;
    contenido = "************";
    partes = 1;
    progreso = 0;
}

///Clase que se adapta=================
 class TareaPoo : public ProgresoTarea
 {
    public:
        TareaPoo();
        void Mostrar();
 };
///=================================

TareaPoo::TareaPoo()
{
    materia = "Programacion Orientada a Objetos";
    rubrica = "***********";
    calificacionMax = 10;
    contenido = "************";
    partes = 1;
    progreso = 0;
}
void TareaPoo::Mostrar()
{
    cout<<"Materia: "<<materia<<endl;
    cout<<"Rubrica: "<<rubrica<<endl;
    cout<<"Calificacion: "<<calificacionMax<<endl;
    cout<<"Contenido: "<<contenido<<endl;
    cout<<"Progreso: "<<progreso*10<<"% |";
    char t = -2;
    int aux=0;
    for(int i=progreso;i>=1;i--)
    {
        cout<<t;
        aux++;
    }
    while(aux!=10)
    {
        cout<<" ";
        aux++;
    }
    cout<<"|";

    cout<<endl<<endl;
}


/// Target ======================
class TareaEquipoMatematicas
{
public:
    TareaMatematicas M;
    void MostrarProgreso();

};
///==============================

void TareaEquipoMatematicas::MostrarProgreso()
{

    cout<<"Materia: "<<M.materia<<endl;
    cout<<"Rubrica: "<<M.rubrica<<endl;
    cout<<"Calificacion: "<<M.calificacionMax<<endl;
    cout<<"Contenido: "<<M.contenido<<endl;
    cout<<"Progreso: "<<M.progreso*10<<"% |";
    char t = -2;
    int aux=0;
    for(int i=M.progreso;i>=1;i--)
    {
        cout<<t;
        aux++;
    }
    while(aux!=10)
    {
        cout<<" ";
        aux++;
    }
    cout<<"|";

    cout<<endl<<endl;

}

///Adaptador===========================================
class TareaEquipoPoo : public TareaEquipoMatematicas
{
    public:
    TareaPoo t;
    void MostrarProgreso(){ t.Mostrar(); }
};
///================================================

 //Creator
class CreadorTarea
{
public:
    ProgresoTarea t1;
    Tarea CrearTarea(string materia);
};

Tarea CreadorTarea::CrearTarea(string nombre)
{
    if(nombre == "Matematicas")
    {
        TareaMatematicas t;
        t1 = t;
        return t1;
    }
    else if(nombre=="Poo")
    {
        TareaPoo p;
        t1 = p;
        return t1;
    }
}

//ConcreteCreator
 class Facultad{
    public:
	CreadorTarea Creador;
 };


 int main()
 {

    /*
    Facultad F;
    F.Creador.CrearTarea("Matematicas");
    F.Creador.t1.set_partes(27);
    F.Creador.t1.actualizarProgreso(true);
    F.Creador.t1.actualizarProgreso(true);
    F.Creador.t1.actualizarProgreso(true);
    F.Creador.t1.mostrar();



    F.Creador.CrearTarea("Poo");
    F.Creador.t1.set_partes(3);
    F.Creador.t1.actualizarProgreso(true);
    F.Creador.t1.mostrar();

    F.Creador.CrearTarea("Matematicas");
    F.Creador.t1.set_partes(9);
    F.Creador.t1.set_rubrica("Que quede chido o lo mando a extra");
    F.Creador.t1.actualizarProgreso(true);
    F.Creador.t1.actualizarProgreso(true);
    F.Creador.t1.actualizarProgreso(true);
    F.Creador.t1.actualizarProgreso(true);
    F.Creador.t1.actualizarProgreso(true);
    F.Creador.t1.actualizarProgreso(true);
    F.Creador.t1.actualizarProgreso(true);
    F.Creador.t1.actualizarProgreso(true);
    F.Creador.t1.mostrar();
    */

    TareaEquipoPoo p;
    p.MostrarProgreso();
    p.t.set_partes(5);
    p.t.actualizarProgreso(true);
    p.MostrarProgreso();


	return 0;
 }
