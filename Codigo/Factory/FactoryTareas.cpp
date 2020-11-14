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
	string rubrica;
	int calificacionMax;  
	public:
		void set_rubrica(string rubrica) { this->rubrica = rubrica;}
	    string get_rubrica() { return rubrica; }
	    void set_calificacionMax(int calificacionMax) { this->calificacionMax = calificacionMax; }
	    int get_calificacionMax() { return calificacionMax; } 	
 };
 
 //ConcreteCreator
 class FactoryTareaIS: public CreatorTarea{
	string contenido;
	public:
		void set_contenido(string contenido) { this->contenido = contenido; }
	    string get_contenido() { return contenido; }				
	    void mostrar();
		Tarea guardarT();
 };
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
 
 int main()
 {
	FactoryTareaIS t1;
	t1.set_contenido("Realizar investigacion");
	t1.set_calificacionMax(10);
	t1.set_rubrica("Rasgos a evaluar 5");
	t1.mostrar();
	t1.guardarT();
	return 0;
 }
