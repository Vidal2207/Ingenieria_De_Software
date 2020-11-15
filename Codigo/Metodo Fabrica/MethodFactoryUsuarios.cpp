#include <iostream>

using namespace std;
//-------------- CLASE ABSTRACTA PRODUCT
class Usuario{
public:
    int matricula;
    string ocupacion=" ";
    string carrera=" ";

     ~Usuario(){};
     void Mostrar();
};
void Usuario::Mostrar(){
    if(ocupacion=="-"){
        cout<<"\n *********** NO SE IDENTIFICO AL USUARIO***********" << endl;
    }
    else{
        matricula= matricula*13*23+3000;
        cout << "\n\n     <<<<<<<<<<<<  " << ocupacion << "  >>>>>>>>>>>>  " << endl;
        cout << "          Matricula >>  2019" << matricula << endl;
        cout << "          Carrera  >>  " <<carrera<<endl;
    }
}
// -------------------------------------
// CLASE DE CURSO VACIA
class CursoVacio:public Usuario{
public:
    CursoVacio();
};
CursoVacio::CursoVacio(){
    ocupacion="-";
}
// ---------------------------------------
// ---------------- IMPLEMENTACION DE PRODUCT
class Alumno_ITI:public Usuario{
public:
    Alumno_ITI();
};
Alumno_ITI::Alumno_ITI(){
    ocupacion = "Alumno";
    matricula = 223;
    carrera = "Ingenieria en tecnologias de la informacion";
}
//----------------------------
// ---------------- IMPLEMENTACION DE PRODUCT
class Docente_ITI:public Usuario{
public:
    Docente_ITI();
};
Docente_ITI::Docente_ITI(){
    ocupacion="Docente";
    matricula=523;
    carrera="Ingenieria en tecnologias de la informacion";
}
//----------------------------
// ---------------- IMPLEMENTACION DE PRODUCT
class Alumno_Sistema:public Usuario{
public:
    Alumno_Sistema();
};
Alumno_Sistema::Alumno_Sistema(){
    ocupacion="Alumno";
    matricula=123;
    carrera="Ingenieria en sistemas";
}
//----------------------------
// ---------------- IMPLEMENTACION DE PRODUCT
class Docente_Sistema:public Usuario{
public:
    Docente_Sistema();
};
Docente_Sistema::Docente_Sistema(){
    ocupacion="Docente";
    matricula=823;
    carrera="Ingenieria en sistemas";
}
//----------------------------
//-------------------------- CLASE ABSTRACTA FACTORY
class Factory{
public:
    Usuario usuario;
    virtual Usuario ObtenerUsuario(string){};
};
// --------------------------------------------------
// ---------------------------------------- IMPLEMENTACION DE FACTORY
class Carrera_ITI:public Factory{
public:
    Usuario ObtenerUsuario(string C);
};
Usuario Carrera_ITI::ObtenerUsuario(string C){
    if(C=="Alumno"){
        Alumno_ITI iti;
        usuario = iti;
    }
    else if(C=="Docente"){
         Docente_ITI s;
         usuario = s;
    }
    else{
        CursoVacio vc;
        usuario= vc;
    }
    return usuario;
}
// --------------------------------------------------------------
// ---------------------------------------- IMPLEMENTACION DE FACTORY-2
class Carrera_Sistema:public Factory{
public:
    Usuario ObtenerUsuario(string C);
};
Usuario Carrera_Sistema::ObtenerUsuario(string C){
    if(C=="Alumno"){
        Alumno_Sistema sis;
        usuario = sis;
    }
    else if(C=="Docente"){
         Docente_Sistema s;
         usuario = s;
    }
    else{
        CursoVacio vc;
        usuario= vc;
    }
    return usuario;
}
// --------------------------------------------------------------

int main(){
    Carrera_ITI I;
    I.ObtenerUsuario("Alumno");
    I.usuario.Mostrar();

    Carrera_Sistema S;
    S.ObtenerUsuario("Docente");
    S.usuario.Mostrar();
    return 0;
}
