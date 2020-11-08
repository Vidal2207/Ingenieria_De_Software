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


class Usuario : public Display , public Observer
{
public:
    string ultimoMensaje;
    void update(string m);
    void display();
};

void Usuario::display()
{
    cout<<ultimoMensaje;
}

void Usuario::update(string m)
{
    ultimoMensaje = m;
}


class subject
{
public:
     void RegistrarObservador(Usuario u);
     void EliminarObservador(Usuario u);
     void Notificar();

};


class Conversacion : public subject
{
public:
    int contadorRegistro=0;
    int contadorHistoria=0;
    Usuario arr[];
    string ultimoMensaje;
    void RegistrarObservador(Usuario u);
    void EliminarObservador(Usuario u);
    void Notificar();

    void RegistrarMensaje(string m);
    void EliminarMensaje();
    void CambiodeEstado();

};

void Conversacion::CambiodeEstado()
{
    Notificar();
}
void Conversacion::RegistrarObservador(Usuario u)
{
    arr[contadorRegistro]= u;
    contadorRegistro++;
}

void Conversacion::EliminarObservador(Usuario u)
{

}

void Conversacion::Notificar()
{
    cout<<endl<<"MENSAJE NUEVO: ";
}

void Conversacion::RegistrarMensaje(string m)
{
    ultimoMensaje = m;
    Notificar();
}

void Conversacion::EliminarMensaje()
{
    string aux = "\nMensaje borrado";
    ultimoMensaje = aux;
}


int main()
{
    string a = "hola!.";
    string b = "como estas.";
    string t = "bien";

    Conversacion c;
    Usuario u;

    c.RegistrarObservador(u);



    c.RegistrarMensaje(a);
    u.update(a);
    u.display();

    c.RegistrarMensaje(b);
    u.update(b);
    u.display();

    c.EliminarMensaje();
    u.update(c.ultimoMensaje);
    u.display();


return 0;
}
