 #include <iostream>
 
 using namespace std;
 //Product
 class Curso
 {
	public:
		void guardarC();
 };
 //ConcreteProduct- Producto concreto "curso"
 class IS: public Curso
 {
 }; 
 //Creator- Creador del curo 
 class CreatorCurso
 {
	int nrc; 
	string nombreC;
	string nombreP;
	public:
		void set_nrc(int nrc) { this->nrc = nrc;}
	    int get_nrc() { return nrc; }
	    void set_nombreC(string nombreC) { this->nombreC = nombreC; }//metodos nombre del curso
	    string get_nombreC() { return nombreC; }
	    void set_nombreP(string nombreP) { this->nombreP = nombreP; }//metodos nombre del profesor del curso 
	    string get_nombreP() { return nombreP; } 	
 };
 
 //ConcreteCreator-fabrica de ingenieria de software 
 class FactoryIS: public CreatorCurso{
	string contenido;
	string tareas;
	string notas;
	public:
		void set_tareas(string tareas) { this->tareas = tareas; }
	    string get_tareas() { return tareas; }		
	    void set_contenido(string contenido) { this->contenido = contenido; }
	    string get_contenido() { return contenido; }
		void set_notas(string notas) { this->notas = notas; }
	    string get_notas() { return notas; }		
	    void mostrar();
		Curso guardarC();
 };
 //implementacion de metodos 
 void FactoryIS::mostrar()
 {
	cout << "Datos del curso "<<endl;
	cout << "\n NRC: "<< get_nrc()<<endl;
	cout << "Nombre del curso: "<<get_nombreC()<<endl;
	cout << "Nombre del profesor: "<<get_nombreP()<<endl;
	cout << "\nContenido del curso:\n"<<get_contenido()<<endl;
	cout << "\nApartado de tareas del curso:\n"<<get_tareas()<<endl;
	cout << "\nApartado de notas del curso:\n"<<get_notas()<<endl;
 };
 Curso FactoryIS::guardarC()
 {
 	cout << "\n\nCurso guardado"<<endl;
 }
 
 int main()
 {
	FactoryIS c1;
	c1.set_nombreC("Ingenieria Software");
	c1.set_nrc(1000);
	c1.set_nombreP("Manuel GonzaleZ");
	c1.set_contenido("Semana 1");
	c1.set_tareas("Evaluacion 3");
	c1.set_notas("No hay notas que mostrar");
	
	c1.mostrar();	
	c1.guardarC();
	return 0;
 }
