#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string tarea;

class Usuario{
	private:
		int matricula;
		string Nombre;
	
	public:
		
		Usuario(int, string);
		
		void checarTarea();
		
		void AsignarTarea(string _tarea)
		{
			tarea = _tarea;
		}
		
		void NuevaTarea()
		{
			cout<< "Tu tarea es :" << tarea << endl;
		}
		
		void mostrarUsuario()
		{
		cout<< "Nombre	" << Nombre << endl;
		cout << "Matricula " << matricula << endl;
		}
		
	
};

Usuario::Usuario(int _matricula,string _nombre) //Constructor Clase Padre
		{
			matricula = _matricula;
			Nombre = _nombre;
		}
		
		
class Alumno : public Usuario {
	
	private://Atributos
		int MateriasCursadas;
		float NotaFinal;
	
	public://Metodos
		Alumno(int,string,int,float); // Constructor Clase Alumno
		
			~ Alumno();
		void mostrarAlumno()
		{
		mostrarUsuario();
		cout << "El alumno esta cursando " << MateriasCursadas << endl;
		cout << "El alumno tiene como nota final " << NotaFinal << endl;	
		}	
	
	
};

Alumno::Alumno(int _matricula, string _nombre , int _matC, float _NF) : Usuario(_matricula,_nombre) 
{
	MateriasCursadas = _matC;
	NotaFinal = _NF;
}

class Docente : public Usuario{
	private:
		string Materia;
	public:
		Docente (int, string, string);
		
		~Docente();
		
		void SubirTarea(){
			string tarea;
			cout << "Cual es la nueva tarea " ;
			getline(cin,tarea);
			AsignarTarea(tarea);
			
		}
	
		void ImprimirDatos()
		{
		
		mostrarUsuario();
		
		cout << "Imparte la materia de " << Materia << endl;
		
		}
	
};

Docente::Docente(int _matricula, string _nombre , string _Materia) : Usuario(_matricula,_nombre) 
{
	Materia = _Materia;
}
int main (){
	
	Docente maestro1(201853596,"Carlos Rios","Base de Datos");
	Alumno alumno1(201853595,"Erick Nu�ez",5,9.8);
	Alumno alumno2(201874512,"Alfredo Rosales",7,8.2);
	Alumno alumno3(201814789,"David Palma",6,9.2);
	Alumno alumno4(201823698,"Armando Mora",4,8.7);
	Alumno alumno5(201825478,"Diana Cruz",6,10);
	
	maestro1.ImprimirDatos();
	
	system("PAUSE");
	system("CLS");
	
	maestro1.SubirTarea();
	
	system("PAUSE");
	system("CLS");
	
	alumno1.NuevaTarea();
	alumno2.NuevaTarea();
	alumno3.NuevaTarea();
	alumno4.NuevaTarea();
	alumno5.NuevaTarea();
	

	
	return 0;
}
