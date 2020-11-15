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
//ConcreteProduct
 class TareaMatematicas: public Tarea
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
}

 class TareaPoo: public Tarea
 {
    public:
        TareaPoo();
 };


TareaPoo::TareaPoo()
{
    materia = "Programacion Orientada a Objetos";
    rubrica = "***********";
    calificacionMax = 10;
    contenido = "************";
}


 //Creator
 class CreadorTarea
 {
public:
    Tarea t1;
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
    Facultad F;
    F.Creador.CrearTarea("Matematicas");
    F.Creador.t1.mostrar();

    F.Creador.CrearTarea("Poo");
    F.Creador.t1.mostrar();


	return 0;
 }
