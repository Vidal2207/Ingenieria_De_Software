#include <iostream>

using namespace std;

///Implementación de interfaz
class estrategia{
public:
    virtual ~estrategia(){}
    virtual string ejecutar()=0;
};

///La clase contexto se comunica con las estrategias concretas
///a través de la interfaz estrategia.
class contexto{
private:
    estrategia *estrategia1;
public:
    contexto(estrategia *estrategiaA)
    {
        estrategia1 =estrategiaA;
    }
    ~contexto(){
        delete this->estrategia1;
    }
    void setEstrategia(estrategia *estrategiaA){
        delete this ->estrategia1;
        this->estrategia1=estrategiaA;
    }
    void mostrarTareas() const
    {
        //cout << "AQUI SE MUESTRAN LAS TAREAS\n";
        string resultado = this->estrategia1->ejecutar();
        cout << resultado << "\n";
    }
};

///Implementación de estrategiaAlumno
class estrategiaAlumno: public estrategia{
public:
    string ejecutar() {
        string resultado;
        cout << "El alumno vera las opciones que tiene disponibles\n";
        cout << "* Tareas Asignadas\n";
        cout << "* Tareas Entregadas\n";
        resultado = "Se ejecuto con exito.";
        return resultado;
    }
};

///Implementación de estrategiaDocente
class estrategiaDocente: public estrategia{
public:
    string ejecutar() {
        string resultado;
        cout << "El docente vera las opciones que tiene disponibles\n";
        cout << "* Tareas Asignadas\n";
        cout << "* Tareas Calificadas\n";
        resultado = "Se ejecuto con exito.";
        return resultado;
    }
};

///Función que define las estrategias elegidas por el usuario
///comunica la estrategia elegida al contexto para que la muestre.
void CodigoUsuario()
{
    contexto *contexto= new class contexto(new estrategiaAlumno );
    cout << "Usuario: La estrategia de alumno fue elegida.\n";
    contexto->mostrarTareas();
    cout << "\nUsuario: La estrategia de docente fue elegida.\n";
    contexto->setEstrategia(new estrategiaDocente);
    contexto->mostrarTareas();
    cout << endl;
    delete contexto;
}

int main() {
    CodigoUsuario();
    return 0;
}
