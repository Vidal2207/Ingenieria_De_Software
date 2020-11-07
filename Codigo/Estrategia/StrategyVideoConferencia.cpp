#include <iostream>
using namespace std;

///Implementación de interfaz estrategiaD
class estrategiaD{
public:
    virtual ~estrategiaD(){}
    virtual string ejecutarD() = 0;
};

///La clase contextoVideoConferencia se comunica con las estrategias concretas
///a través de la interfaz estrategiaD.
class contextoVideoConferencia{
private:
    estrategiaD *estrategia1;
public:
    contextoVideoConferencia(estrategiaD *estrategia)
    {
        estrategia1 =estrategia;
    }
    ~contextoVideoConferencia(){
        delete this->estrategia1;
    }
    void setEstrategia(estrategiaD *estrategia){
        delete this ->estrategia1;
        this->estrategia1=estrategia;
    }
    void mostrarContenido() const
    {
        //cout << "AQUI SE MUESTRA EL CONTENIDO DISPONIBLE\n";
        string resultado = this->estrategia1->ejecutarD();
        cout << resultado << "\n";
    }
};

///Implementación de estrategiaCAlumno
class estrategiaDAlumno: public estrategiaD{
public:
    string ejecutarD() {
        string resultado;
        cout << "\nEl alumno vera las opciones disponibles para una videoconferencia:\n";
        cout << "* Iniciar videoconferencia\n";
        cout << "* Encender/apagar microfono\n";
        cout << "* Encender/apagar camara\n";
        cout << "* Salir de videoconferencia\n";
        resultado = "Se ejecuto la estrategiaDAlumno.";
        return resultado;
    }
};

///Implementación de estrategiaCDocente
class estrategiaDDocente: public estrategiaD{
public:
    string ejecutarD() {
        string resultado;
        cout << "\nEl docente vera las opciones disponibles para una videoconferencia:\n";
        cout << "* Iniciar videoconferencia\n";
        cout << "* Encender/apagar microfono\n";
        cout << "* Encender/apagar camara\n";
        cout << "* Grabar la videoconferencia\n";
        cout << "* Compartir pantalla\n";
        cout << "* Salir de videoconferencia\n";
        cout << "* Terminar la videoconferencia\n";
        resultado = "Se ejecuto la estrategiaDDocente.";
        return resultado;
    }
};

///Función que define las estrategias elegidas por el usuario
///comunica la estrategiaC elegida al contexto para que la muestre.
void CodigoUsuarioD()
{
    contextoVideoConferencia *contextoD = new contextoVideoConferencia(new estrategiaDAlumno);
    cout << "Usuario: La estrategiaD de alumno fue elegida.\n";
    contextoD->mostrarContenido();
    cout << "\nUsuario: La estrategiaD de docente fue elegida.\n";
    contextoD->setEstrategia(new estrategiaDDocente);
    contextoD->mostrarContenido();
    delete contextoD;
}

int main() {
    CodigoUsuarioD();
    return 0;
}
