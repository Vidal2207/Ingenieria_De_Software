#include <iostream>
#include "Tareas.h"

using namespace std;

//Target o clase a la que quiere hacer la adaptacion
class TargetTareaIndividual//: public Tareas
{
	public:
		void asignarTarea()
		{
			cout << "Tarea asignada"<<endl;
			
		}
};
//Clase que se quiere adaptar
class AdapteeTareaEquipo
{
	public:
		void AsignarTareaEquipo()
		{
			FactoryTareaIS m1;
			m1.mostrar();
			cout <<"La tarea se asigno a los equipos correctamente"<<endl;
		}	
};
//Adaptador que utilizará 
class Adapter:public TargetTareaIndividual
{
	public:
		void asignarTarea()
		{
			AdapteeTareaEquipo tareaEquipo;
			tareaEquipo.AsignarTareaEquipo();	
		}
};

//codigo usuario haciendo uso dl adaptador 
void CodigoUsuario()
{
	cout << "\t\tMostrando datos de la tarea  "<<endl;
	TargetTareaIndividual t1;
	t1.asignarTarea();
	Adapter a1;
	a1.asignarTarea();
}
int main()
{
	CodigoUsuario();
}
