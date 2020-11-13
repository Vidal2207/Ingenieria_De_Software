#include <iostream>

using namespace std;

/*La interfaz tarea define operaciones que pueden ser alteradas
por los decoradores*/
class tarea{
public:
    virtual ~tarea(){}
    virtual string mostrar() const =0;
};

/*Las tareas concretas dan una implementacion por defecto de
las operaciones. Pueden haber muchas variaciones de estas clases*/
class tareaConcreta:public tarea{
public:
    string mostrar() const override{
        return "Tarea concreta";
    }
};

/*El Decorador base utiliza la misma interfaz que las tareas concretas
Su propósito es definir los envoltorios(wrapps) para los decoradores concretos
*/
class decoradorTarea:public tarea{
protected:
    tarea *tarea1;
public:
    decoradorTarea(tarea *tarea1){
        this->tarea1 = tarea1;
    }
    string mostrar()const override{
        return this->tarea1->mostrar();
    }
};

/*Decoradores concretos llaman al objeto envuelto y alteran su resultado*/

class tareaCuestionario: public decoradorTarea{
public:
    tareaCuestionario(tarea *tarea1): decoradorTarea(tarea1){
    }
    string mostrar() const override{
        cout << "\nEsta es una Tarea que muestra al usuario un cuestionario para responder.";
        return "Decorador TareaCuestionario(" + decoradorTarea::mostrar()+")";
    }
};

class tareaAgregar: public decoradorTarea{
public:
    tareaAgregar(tarea *tarea1): decoradorTarea(tarea1){
    }
    string mostrar() const override{
        cout << "\nEsta es una Tarea que da la opcion de adjuntar documentos.";
        return "Decorador TareaAgregar(" + decoradorTarea::mostrar()+")";
    }
};

void UsuarioCodigo(tarea *tarea1){
    cout << "\nResultado: " << tarea1->mostrar();
}


int main()
{
    tarea *tareasimple = new tareaConcreta;
    cout << "Usuario: Tengo una tarea simple.";
    UsuarioCodigo(tareasimple);
    cout << endl << endl;

    tarea *tareaDecorada1 = new tareaCuestionario(tareasimple);
    cout << "Usuario: Ahora tengo una tarea decorada.";
    UsuarioCodigo(tareaDecorada1);
    cout << endl << endl;

    tarea *tareaDecorada2 = new tareaAgregar(tareaDecorada1);
    cout << "Usuario: Ahora tengo una tarea doblemente decorada.";
    UsuarioCodigo(tareaDecorada2 );
    cout << endl << endl;

    delete tareasimple;
    delete tareaDecorada1;
    delete tareaDecorada2;

    return 0;
}
