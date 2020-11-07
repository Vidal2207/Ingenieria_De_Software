#include <iostream>
#include <list>
#include <string>
using namespace std;
class IServer {
public:
	virtual ~IServer(){};
	virtual void Actualizar(const string &mens_Suj) = 0;
};

class ISujeto {
public:

	virtual void Agregar(IServer *server) = 0;

	virtual void Notificar() = 0;
};

class Alumno : public ISujeto {
	
private:
	list<IServer *> lista_Server_;
	string mensaje_;
	
public:

	void Agregar(IServer *server) override {
		lista_Server_.push_back(server);
	}

	void Notificar() override {
		list<IServer *>::iterator iterator = lista_Server_.begin();
		N_miembros();
		while (iterator != lista_Server_.end()) {
			(*iterator)->Actualizar(mensaje_);
			++iterator;
		}
	}
	
	void NNotificacion(string mens = "NULL") {
		this->mensaje_ = mens;
		Notificar();
	}
	void N_miembros() {
		cout << lista_Server_.size() << " alumnos notificados.\n";
	}
	

	

};

class Reunion : public IServer {
private:
	string mens_suj_;
	Alumno &alumno_;
	static int ns;
	int numero;

public:
	Reunion(Alumno &alumno) : alumno_(alumno) {
		this->alumno_.Agregar(this);
		cout << "Alumno " << ++Reunion::ns << " registrado con exito.\n\n";
		this->numero = Reunion::ns;
	}
	
	void Actualizar(const string &mens_suj) override {
		mens_suj_ = mens_suj;
		print();
	}

	void print() {
		cout << "Alumno \"" << this->numero << "\": ha llegado un nuevo mensaje --> " << this->mens_suj_ << "\n";
	}
	

};
int Reunion::ns = 0;

void Interfaz() {
	int opc = 0, opc2 = 0;
	string fecha, pred = "Se ha programado una nueva Videoconferencia el dia ", res;
	Alumno *alumno = new Alumno;
	Reunion *Observador1 = new Reunion(*alumno);
	Reunion *Observador2 = new Reunion(*alumno);
	Reunion *Observador3 = new Reunion(*alumno);
	Reunion *Observador4 = new Reunion(*alumno);
	Reunion *Observador5;
	
	do{
		cout << "1. Programar conferencia" << endl;
		cout << "2. Salir " << endl;
		cin >> opc;
	
	switch(opc){
	case 1 : 
		do{
			
		
		cout << "Escriba la fecha en la cual sera la videoconferencia " ;
		cin >> fecha;
		system("CLS");
		cout << "Esta correcta la fecha " << fecha << " ? (1 = Si, 2 = No)" << endl;
		cin >> opc2;
		} while(opc2 != 1);
		res = pred + " " + fecha;
		alumno->NNotificacion(res);
		system("PAUSE");
		system("CLS");
	}
		
	} while(opc != 2);
	
	
	delete Observador1;
	delete Observador2;
	delete Observador3;
	delete Observador4;
	delete Observador5;
	delete alumno;
}

int main() {
	Interfaz();
	return 0;
}
