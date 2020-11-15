#include <iostream>
#include<stdlib.h>
#include <cstdlib>

using namespace std;

class Alumno{

	private:
		string nombre;
		int matricula;
	public:
		Alumno(){};

		Alumno(string _nom, int _matr) // Constructor de la clase Alumno
		{
			nombre = _nom;
			matricula = _matr;
		}

		void MostrarAlumno()
		{
			cout << "El estudiante es : " << nombre << endl;
			cout << "La matricula del estudiante es : " << matricula << endl;
		}

		void DevuelveNombre()
		{
			cout << nombre ;
		}


};

    class Nodo {
    public:
        Alumno info;
        Nodo *sig;
    };

    class Registro {
private:
    Nodo *raiz;
    Nodo *fondo;
public:
    Registro()
    {
    raiz = NULL;
    fondo = NULL;
	}
    ~Registro()
    {
    Nodo *reco = raiz;
    Nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        delete bor;
    }
}
    void insertar(Alumno x)
    	{
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->info = x;
    nuevo->sig = NULL;
    if (vacia())
    {
        raiz = nuevo;
        fondo = nuevo;
    }
    else {
        fondo->sig = nuevo;
        fondo = nuevo;
    }
}
    void imprimir()
    {
    Nodo *reco = raiz;
    cout << "Listado de todos los Alumnos que asistieron.\n";
    while (reco != NULL)
    {
        reco->info.MostrarAlumno();
        cout << "\n" ;
        reco = reco->sig;
    }
    cout << "\n";
}
    bool vacia()
    {
    if (raiz == NULL)
        return true;
    else
        return false;
}
};


class Sesion {
private:
    Nodo *raiz;
    Nodo *fondo;

public:
    Sesion()
    {
    raiz = NULL;
    fondo = NULL;
	}
    ~Sesion()
    {
    Nodo *reco = raiz;
    Nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        delete bor;
    }
}

	Registro *logs = new Registro();

	void insertar(Alumno x)
    	{
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->info = x;
    nuevo->sig = NULL;
    if (vacia())
    {
        raiz = nuevo;
        fondo = nuevo;
    }
    else {
        fondo->sig = nuevo;
        fondo = nuevo;
    }
    cout<< "Ingreso el alumno ";
	x.DevuelveNombre();
	cout << "\n" ;
	logs->insertar(x);
}
    bool vacia()
    {
    if (raiz == NULL)
        return true;
    else
        return false;
}
};

class SesionFactory
{
public:
    string nombre;
    Sesion s;
    Registro r;
    SesionFactory();
    SesionFactory(string);
    void set_nombre_reunion(string);
};
SesionFactory::SesionFactory()
{
    nombre = "Reunion";

}
SesionFactory::SesionFactory(string n)
{
    nombre = n;

}

void SesionFactory::set_nombre_reunion(string n)
{
    nombre = n;
}

int main (){

	 Alumno alumno1("Erick Nunez",201853595);
     Alumno alumno2("Alfredo Rosales",201814789);
	 Alumno alumno3("David Palma",201812369);
	 Alumno alumno4("Armando Mora",201815963);




     SesionFactory f("Matematicas Discretas");
     cout << "Se abre la sesion de "<<f.nombre<< endl<<endl;
     system("PAUSE");
     system("CLS");

	 f.s.insertar(alumno1);
	 f.s.insertar(alumno2);
	 f.s.insertar(alumno3);
	 f.s.insertar(alumno4);

	 f.s.logs->imprimir();

     system("PAUSE");
     system("CLS");
	 SesionFactory w("Programacion orienta a objetos");
     cout << "Se abre la sesion de "<<w.nombre<< endl<<endl;
     system("PAUSE");
     system("CLS");
	 w.s.insertar(alumno1);
	 w.s.insertar(alumno2);
	 w.s.insertar(alumno3);
	 w.s.insertar(alumno4);

	 w.s.logs->imprimir();

	return 0;
}
