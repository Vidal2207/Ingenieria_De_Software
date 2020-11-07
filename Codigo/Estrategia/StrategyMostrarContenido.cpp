#include <iostream>

using namespace std;

///Implementación de interfaz estrategiaC
class estrategiaC{
public:
    virtual ~estrategiaC(){}
    virtual string ejecutarC()=0;
};

///La clase contexto se comunica con las estrategias concretas
///a través de la interfaz estrategiaC.
class contextoContenido{
private:
    estrategiaC *estrategia1;
public:
    contextoContenido(estrategiaC *estrategia)
    {
        estrategia1 =estrategia;
    }
    ~contextoContenido(){
        delete this->estrategia1;
    }
    void setEstrategia(estrategiaC *estrategia){
        delete this ->estrategia1;
        this->estrategia1=estrategia;
    }
    void mostrarContenido() const
    {
        //cout << "AQUI SE MUESTRA EL CONTENIDO DISPONIBLE\n";
        string resultado = this->estrategia1->ejecutarC();
        cout << resultado << "\n";
    }
};

///Implementación de estrategiaCAlumno
class estrategiaCAlumno: public estrategiaC{
public:
    string ejecutarC() {
        string resultado;
        cout << "\nEl alumno vera el contenido y opciones disponibles:\n";
        cout << "* Ver contenido especifico\n";
        cout << "* Descargar contenido\n";
        resultado = "Se ejecuto la estrategiaCAlumno.";
        return resultado;
    }
};

///Implementación de estrategiaCDocente
class estrategiaCDocente: public estrategiaC{
public:
    string ejecutarC() {
        string resultado;
        cout << "\nEl docente vera el contenido y opciones disponibles:\n";
        cout << "* Ver contenido especifico\n";
        cout << "* Modificar contenido\n";
        cout << "* Subir contenido\n";
        resultado = "Se ejecuto la estrategiaCDocente.";
        return resultado;
    }
};

///Función que define las estrategias elegidas por el usuario
///comunica la estrategiaC elegida al contexto para que la muestre.
void CodigoUsuarioC()
{
    contextoContenido *contextoC = new contextoContenido(new estrategiaCAlumno);
    cout << "Usuario: La estrategiaC de alumno fue elegida.\n";
    contextoC->mostrarContenido();
    cout << "\nUsuario: La estrategiaC de docente fue elegida.\n";
    contextoC->setEstrategia(new estrategiaCDocente);
    contextoC->mostrarContenido();
    delete contextoC;
}

int main() {
    CodigoUsuarioC();
    return 0;
}
