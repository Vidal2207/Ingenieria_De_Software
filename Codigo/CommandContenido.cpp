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
            case 'A':
                cout << "El sistema abre el documento." << endl;
                break;
            case 'E':
                cout << "El sistema elimina el documento." << endl;
                break;
            case 'I':
                cout << "El sistema imprime el documento." << endl;
                break;
            case 'D':
                cout << "El sistema descarga el documento." << endl;
                break;
            case 'C':
                cout << "El sistema copia el documento." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
            }
        }
};


class OpcionAbrir : public OpcionesComando{
    private:
        Receptor *r;
    public:
        OpcionAbrir(Receptor *r){
            this->r = r;
        }
        void ejecutar(){
            r->ejecucion('A');
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
            r->ejecucion('E');
        }
};

class OpcionImprimir : public OpcionesComando{
    private:
        Receptor *r;
    public:
        OpcionImprimir(Receptor *r){
            this->r = r;
        }
        void ejecutar(){
            r->ejecucion('I');
        }
};

class OpcionDescargar : public OpcionesComando{
    private:
        Receptor *r;
    public:
        OpcionDescargar(Receptor *r){
            this->r = r;
        }
        void ejecutar(){
            r->ejecucion('D');
        }

};

class OpcionCopiar : public OpcionesComando{
    private:
        Receptor *r;
    public:
        OpcionCopiar(Receptor *r){
            this->r = r;
        }
        void ejecutar(){
            r->ejecucion('C');
        }

};


int main(){
  // Crear un objeto InvocadorOpcion(Invocador)
  InvocadorOpcion *invocador = new InvocadorOpcion();

  //Crear el receptor
  Receptor *receptor = new Receptor();

  // Crear los comandos deseados, indicándoles el Receptor
  OpcionesComando *opcAbrir = new OpcionAbrir(receptor);
  OpcionesComando *opcImprimir = new OpcionImprimir(receptor);
  OpcionesComando *opcEliminar = new OpcionEliminar(receptor);
  OpcionesComando *opcDescargar = new OpcionDescargar(receptor);
  OpcionesComando *opcCopiar = new OpcionCopiar(receptor);

    cout << "******** CONSULTA DE CONTENIDOS ********\n";
    cout << "\nEl usuario elige diferentes comandos a ejecutar.\n" << "Resultado: \n";
  //Establecer los comandos y ejecutarlos a través del invocador
  invocador->setComando(opcAbrir);
  invocador->ejecutarComando();
  invocador->setComando(opcImprimir);
  invocador->ejecutarComando();
  invocador->setComando(opcEliminar);
  invocador->ejecutarComando();
  invocador->setComando(opcDescargar);
  invocador->ejecutarComando();
  invocador->setComando(opcCopiar);
  invocador->ejecutarComando();

  delete invocador, receptor;
  return 0;
}
