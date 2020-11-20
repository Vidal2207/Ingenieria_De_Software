#include <iostream>

using namespace std;

///Interfaz OpcionesComando cuya función es avisar
/// que algo se va a ejecutar
class OpcionesComando{
    public:
        virtual void ejecutar() = 0;
};

class InvocadorOpcion{
    OpcionesComando *comandoElegido;
    public:
        InvocadorOpcion(){}
        void setComando(OpcionesComando *comandoElegido){
          this->comandoElegido = comandoElegido;
        }
        void ejecutarComando(){
           this->comandoElegido->ejecutar();
        }
};


///Clase que ejecutará el comando establecido.
class Receptor{
    public:
        Receptor(){}
        void ejecucion(char ejecucion){
            switch (ejecucion)
            {
            case 'W':
                cout << "El sistema permite escribir un mensaje." << endl;
                break;
            case 'E':
                cout << "El sistema permite editar un mensaje." << endl;
                break;
            case 'D':
                cout << "El sistema permite eliminar un mensaje." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
            }
        }
};


class OpcionEscribir : public OpcionesComando{
    private:
        Receptor *r;
    public:
        OpcionEscribir(Receptor *r){
            this->r = r;
        }
        void ejecutar(){
            r->ejecucion('W');
        }
};


class OpcionEditar : public OpcionesComando{
    private:
        Receptor *r;
    public:
        OpcionEditar(Receptor *r){
            this->r = r;
        }
        void ejecutar(){
            r->ejecucion('E');
        }
};

class OpcionEliminar : public OpcionesComando{
    private:
        Receptor *r;
    public:
        OpcionEliminar(Receptor *r){
            this->r = r;
        }
        void ejecutar(){
            r->ejecucion('D');
        }
};

int main(){
  // Crear un objeto InvocadorOpcion(Invocador)
  InvocadorOpcion *invocador = new InvocadorOpcion();

  //Crear el receptor
  Receptor *receptor = new Receptor();

  // Crear los comandos deseados, indicándoles el Receptor
  OpcionesComando *opcEscribir = new OpcionEscribir(receptor);
  OpcionesComando *opcEditar = new OpcionEditar(receptor);
  OpcionesComando *opcEliminar = new OpcionEliminar(receptor);

    cout << "******** CHAT DEL SISTEMA ********\n";
    cout << "\nEl usuario elige diferentes comandos a ejecutar.\n" << "Resultado: \n";
  //Establecer los comandos y ejecutarlos a través del invocador
  invocador->setComando(opcEscribir);
  invocador->ejecutarComando();
  invocador->setComando(opcEditar);
  invocador->ejecutarComando();
  invocador->setComando(opcEliminar);
  invocador->ejecutarComando();

  delete invocador, receptor;
  return 0;
}

