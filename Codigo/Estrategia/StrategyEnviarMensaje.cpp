#include <iostream>

using namespace std;

///Implementación de interfaz estrategia
class estrategiaM{
public:
    virtual ~estrategiaM(){}
    virtual string ejecutarM()=0;
};

///La clase contexto se comunica con las estrategias concretas
///a través de la interfaz estrategiaM.
class contextoMensaje{
private:
    estrategiaM *estrategia1;
public:
    contextoMensaje(estrategiaM *estrategia)
    {
        estrategia1 =estrategia;
    }
    ~contextoMensaje(){
        delete this->estrategia1;
    }
    void setEstrategia(estrategiaM *estrategia){
        delete this ->estrategia1;
        this->estrategia1=estrategia;
    }
    void mostrarMensaje() const
    {
        //cout << "AQUI SE MUESTRA EL CONTENIDO DISPONIBLE\n";
        string resultado = this->estrategia1->ejecutarM();
        cout << resultado << "\n";
    }
};

///Implementación de estrategiaMPersonaA
class estrategiaMPersonaA: public estrategiaM{
public:
    string ejecutarM() {
        string resultado;
        cout << "\nLa persona A envia un mnensaje a una Persona B:\n";
        cout << "* Enviar un mensaje\n";
        cout << "* Borrar mensaje\n";
        resultado = "Se ejecuto la estrategiaMPersonaA.";
        return resultado;
    }
};

///Implementación de estrategiaMPersonaB
class estrategiaMPersonaB: public estrategiaM{
public:
    string ejecutarM() {
        string resultado;
        cout << "\nLa persona B podrá visualizar el mensaje de la persona A y tambien :\n";
        cout << "* Ver mesaje\n";
        cout << "* Borrar mensaje\n";
        resultado = "Se ejecuto la estrategiaMPersonaB.";
        return resultado;
    }
};

///Función que define las estrategias elegidas por el usuario
///comunica la estrategiaM elegida al contexto para que la muestre.
void CodigoUsuarioM()
{
    contextoMensaje *contextoM = new contextoMensaje(new estrategiaMPersonaA);
    cout << "Usuario: La estrategiaM de persona A fue elegida.\n";
    contextoM->mostrarMensaje();
    cout << "\nUsuario: La estrategiaM de persona B fue elegida.\n";
    contextoM->setEstrategia(new estrategiaMPersonaB);
    contextoM->mostrarMensaje();
    delete contextoM;
}

int main() {
    CodigoUsuarioM();
    return 0;
}
