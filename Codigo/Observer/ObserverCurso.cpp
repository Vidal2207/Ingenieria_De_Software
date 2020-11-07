#include <iostream>
#include <list>
#include <string>
#include <windows.h>

using namespace std;

class IServer {
public:
	virtual ~IServer(){};
	virtual void Actualizar(const string &mens_Suj) = 0;
};

class ISujeto {
public:
	
	virtual void Agregar(IServer *server) = 0;
	virtual void Eliminar(IServer *server) = 0;
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
	void Eliminar(IServer *Server) override {
		lista_Server_.remove(Server);
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

class  Grupo : public IServer {
private:
	string mens_suj_;
	Alumno &alumno_;
	static int ns;
	int numero;
	
public:
	Grupo(Alumno &alumno) : alumno_(alumno) {
		this->alumno_.Agregar(this);
		cout << "Alumno " << ++Grupo::ns << " registrado con exito.\n\n";
		this->numero = Grupo::ns;
	}
	void Quitar() {
		alumno_.Eliminar(this);
		std::cout << "Alumno \"" << numero << "\" eliminado del grupo.\n";
	}
	void Actualizar(const string &mens_suj) override {
		mens_suj_ = mens_suj;
		print();
	}
	
	void print() {
		cout << "Alumno \"" << this->numero << "\": Nueva Notificación --> " << this->mens_suj_ << "\n";
	}
	
	
};
int Grupo::ns = 0;

void Interfaz() {
	int opc = 0, opc2 = 0,num,opc3=0;
	Alumno *alumno = new Alumno;
	string anunc = "Nuevo anuncio : ", res;
	char noti [50];
	Grupo *Observador1 = new Grupo(*alumno);
	Grupo *Observador2 = new Grupo(*alumno);
	Grupo *Observador3 = new Grupo(*alumno);
	Grupo *Observador4 = new Grupo(*alumno);
	Grupo *Observador5 = new Grupo(*alumno);
	
	do{
		cout << "1. Notificar Grupo" << endl;
		cout << "2. Eliminar Alumno" << endl;
		cout << "3. Salir " << endl;
		cin >> opc;
		
		switch(opc){
		case 1 : 
				
			do {
			
			cout<< "Que desea notificar ?" << endl;
			
			cin >> noti;
			
			cout << "Esta bien " << noti << " - ? (1 = Si, 2 = No)" << endl;
			cin >> opc3;
			system("CLS");
			} while(opc3 != 1);
			
			res = anunc + " " + noti;
			
			alumno->NNotificacion(res);
			
			system("PAUSE");
			
			system("CLS");
			
			break;
			
		case 2 :
				
				cout << "Escriba la el numero del alumno que desea eliminar " ;
				cin >> num;
				system("CLS");
				cout << "Esta correcto el numero= " << num << " ? (1 = Si, 2 = No)" << endl;
				cin >> opc2;
				if( opc2 == 1 )
				{
				if( num == 1){
					
				
				Observador1->Quitar();
				}
				else if(num == 2)
				{
			Observador2->Quitar();
				}
				else if(num == 3)
				{
					Observador3->Quitar();
				}
				else if( num == 4)
				{
					Observador4->Quitar();
				}
				else if(num == 5 )
				{
					Observador5->Quitar();
				}
		break;

				}
	
	delete Observador1;
	delete Observador2;
	delete Observador3;
	delete Observador4;
	delete Observador5;
	delete alumno;
}
	} while(opc !=3);
}
int main() {
	Interfaz();
	return 0;
}
