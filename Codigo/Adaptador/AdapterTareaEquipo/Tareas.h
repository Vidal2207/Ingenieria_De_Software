#include <iostream>
 
 using namespace std;
 //Product
 class Tarea
 {
	public:
		void guardarT();
 };
 //ConcreteProduct
 class TareaIS: public Tarea
 {
 }; 
 //Creator
 class CreatorTarea
 {
	public:
		string rubrica;
	int calificacionMax;  
		void set_rubrica(string rubrica) { this->rubrica = rubrica;}
	    string get_rubrica() { return rubrica; }
	    void set_calificacionMax(int calificacionMax) { this->calificacionMax = calificacionMax; }
	    int get_calificacionMax() { return calificacionMax; } 	
 };
 
 //ConcreteCreator
 class FactoryTareaIS: public CreatorTarea{
	string contenido;
	public:
		FactoryTareaIS();
		void set_contenido(string contenido) { this->contenido = contenido; }
	    string get_contenido() { return contenido; }				
	    void mostrar();
		Tarea guardarT();
 };
 FactoryTareaIS::FactoryTareaIS()
 {
	rubrica ="Datos de rubrica xxxx";
	calificacionMax=10;
	contenido ="******";
 }
 void FactoryTareaIS::mostrar()
 {
	cout << "Datos dela tarea de Ingenieria de software"<<endl;
	cout << "Contenido:\n" << get_contenido()<<endl;
	cout <<"Rubrica: "<< get_rubrica()<<endl;
	cout << "Calificacion maxima: "<<get_calificacionMax()<<endl; };
 Tarea FactoryTareaIS::guardarT()
 {
 	cout << "\n\nTarea asignada"<<endl;
 }
 
