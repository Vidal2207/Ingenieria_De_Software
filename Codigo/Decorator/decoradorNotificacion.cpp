#include <iostream>
using namespace std;

//Definicion de interfaz Notificacion
class Notificacion{
	public:
		virtual ~Notificacion(){}
		virtual string mostrarNot() const = 0;
};

//Definicion de una Notificacion concreta de donde saldrán variaciones
class NotificacionBase : public Notificacion{
	public:
		string mostrarNot() const override{
			return "Notificacion Base";
		};
};

//El decorador va a definir los envoltorios posibles para los decoradores
class DecoradorNotificacion : public Notificacion{
	protected:
		Notificacion *notificacion;
	public:
		DecoradorNotificacion(Notificacion *notificacion){
			this->notificacion = notificacion;
		}
		string mostrarNot() const override{
			return notificacion->mostrarNot();
		}
};

//Primer decorador para una notificacion de plataforma
class NotificacionPlataforma : public DecoradorNotificacion{
	public:
		NotificacionPlataforma(Notificacion *notificacion) : DecoradorNotificacion(notificacion) {}
		string mostrarNot() const override{
			cout << "\nEsta es una notificacion que va dirigida hacia la misma plataforma";
			return "Decorador NotificarPlataforma(" + DecoradorNotificacion::mostrarNot() + ")";
		}
};

//Segundo decorador para una notificacion de correo
class NotificacionCorreo: public DecoradorNotificacion{
	public:
		NotificacionCorreo(Notificacion *notificacion) : DecoradorNotificacion(notificacion) {}
		string mostrarNot() const override{
			cout << "\nEsta es una notificacion que va dirigida hacia el correo de usuario";
			return "Decorador NotificarCorreo(" + DecoradorNotificacion::mostrarNot() + ")";
		}
};

//Codigo de usuario
void Usuario(Notificacion *notificacion){
	cout << "\nResultado: " << notificacion->mostrarNot();
}

int main(){
	Notificacion *notsencilla = new NotificacionBase;
	cout << "Notificacion Sencilla: ";
	Usuario(notsencilla);
	cout << endl << endl;
	
	Notificacion *notplataforma = new NotificacionPlataforma(notsencilla);
	cout << "Notificacion dirigida a plataforma: ";
	Usuario(notplataforma);
	cout << endl << endl;
	
	Notificacion *notcorreo = new NotificacionCorreo(notplataforma);
	cout << "Notificacion dirigida a palataforma y correo: ";
	Usuario(notcorreo);
	cout << endl << endl;
	
	delete notsencilla, notplataforma, notcorreo;
	
	return 0;
}
