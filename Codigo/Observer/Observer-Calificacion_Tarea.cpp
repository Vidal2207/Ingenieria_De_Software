#include <iostream>
using namespace std;

class Observer
{
public:
    void update();
};

void Observer::update()
{
    void update(string mensaje);
}

class Display
{
public:
    virtual void display();
};

void Display::display()
{
    //UNA FORMA DE MOSTRAR LA NOTIFICACION
}

class Atributos
{
    public:
    string nombre;
    float calificacion;
};


class Alumno : public Display , public Observer , public Atributos
{
public:

    void update(string nom,float cal);
    void display();
};

void Alumno::display()
{
    cout<<"Nombre de actividad: "<<nombre<<endl;
    cout<<"Calificacion: "<<calificacion<<endl;
}

void Alumno::update(string nom,float cal)
{
    calificacion = cal;
    nombre = nom;
}


class subject
{
public:
     void RegistrarObservador(Alumno a);
     void EliminarObservador(Alumno a);
     void Notificar();

};


class Entrega : public subject , public Atributos
{
public:
    int contadorRegistro=0;
    int contadorHistoria=0;
    Alumno arr[];
    void RegistrarObservador(Alumno a);
    void EliminarObservador(Alumno a);
    void Notificar();

    void RegistrarEntrega(string,float);
    void EliminarEntrega();
    void CambiodeEstado();

};

void Entrega::CambiodeEstado()
{
    Notificar();
}
void Entrega::RegistrarObservador(Alumno a)
{
    arr[contadorRegistro]= a;
    contadorRegistro++;
}

void Entrega::EliminarObservador(Alumno a)
{

}

void Entrega::Notificar()
{
    cout<<endl<<"Entrega calificada"<<endl<<endl;
}

void Entrega::RegistrarEntrega(string nom,float cal)
{
    nombre = nom;
    calificacion = cal;
    Notificar();
}

void Entrega::EliminarEntrega()
{
    // Concepto
}


int main()
{

    Entrega e;
    Alumno a;

    e.RegistrarObservador(a);
    e.RegistrarEntrega("Poo",4.0);
    a.update("Poo",4.0);
    cout<<"Comentarios del profesor: Reprobado por burro xdxd"<<endl;
    a.display();

    e.RegistrarEntrega("Ingenieria de Sistemas",10);
    a.update("Ingenieria de Sistemas",10);
    a.display();






return 0;
}
