#include <iostream>
using namespace std;
//-------------- CLASE ABSTRACTA PRODUCT
class Curso{
public:
    int nrc;
    int cupo;
    string nombre=" ";
    string profesor=" ";
    string carrera=" ";
     ~Curso(){};
     void Mostrar();
};
void Curso::Mostrar(){
    if(nombre==" "){
        cout<<"\n *********** NO SE IDENTIFICO EL CURSO***********" << endl;
    }
    else{
        cout << "\n     <<<<<<<<<<<<  " << nombre << "  >>>>>>>>>>>>  " << endl;
        cout << "\n      NRC >>  " << nrc << endl;
        cout << "      Carrera >>  " <<carrera<<endl;
        cout << "      Profesor >>  " << profesor << endl;
        cout << "      Cupo >> " << cupo << endl;
    }
}
// -------------------------------------
// CLASE DE CURSO VACIA
class CursoVacio:public Curso{
public:
    CursoVacio();
};
CursoVacio::CursoVacio(){
    nombre=" ";
}
// ---------------------------------------
// ---------------- IMPLEMENTACION DE PRODUCT
class Ingenieria_Sistemas:public Curso{
public:
    Ingenieria_Sistemas();
};
Ingenieria_Sistemas::Ingenieria_Sistemas(){
    nombre = "INGENIERIA EN SISTEMAS";
    carrera = "Ingenieria en tecnologias de la informacion";
    nrc=304;
    profesor="Juan Manuel";
}
//----------------------------
// ---------------- IMPLEMENTACION DE PRODUCT
class HerramientasWeb:public Curso{
public:
    HerramientasWeb();
};
HerramientasWeb::HerramientasWeb(){
    nombre = "HERRAMIENTAS WEB";
    carrera = "Ingenieria en tecnologias de la informacion";
    nrc=306;
    profesor="Hilda Mejia";
}
//----------------------------
// ---------------- IMPLEMENTACION DE PRODUCT
class Sistemas:public Curso{
public:
    Sistemas();
};
Sistemas::Sistemas(){
    nombre = "SISTEMAS";
    carrera = "Ingenieria en sistemas";
    nrc=206;
    profesor="Guillermo Lopez";
}
//----------------------------
// ---------------- IMPLEMENTACION DE PRODUCT
class MatematicasD:public Curso{
public:
    MatematicasD();
};
MatematicasD::MatematicasD(){
    nombre = "MATEMATICAS 3";
    carrera = "Ingenieria en sistemas";
    nrc=216;
    profesor="Jose Carlos Mejia";
}
//----------------------------
//-------------------------- CLASE ABSTRACTA FACTORY
class Factory{
public:
    Curso curso;
    virtual Curso ObtenerCarrera(string C){};
};
// --------------------------------------------------
// ---------------------------------------- IMPLEMENTACION DE FACTORY
class Carrera_ITI:public Factory{
public:
    Curso ObtenerCarrera(string C);
};
Curso Carrera_ITI::ObtenerCarrera(string C){
    if(C=="Ingenieria en sistemas"){
        Ingenieria_Sistemas iti;
        curso = iti;
    }
    else if(C=="Herramientas web"){
         HerramientasWeb sistema;
         curso = sistema;
    }
    else{
        CursoVacio V;
        curso = V;}
    return curso;
}
// --------------------------------------------------------------
// ---------------------------------------- IMPLEMENTACION DE FACTORY-2
class Carrera_Sistema:public Factory{
public:
    Curso ObtenerCarrera(string C);
};
Curso Carrera_Sistema::ObtenerCarrera(string C){
    if(C=="Sistemas"){
        Sistemas iti;
        curso = iti;
    }
     else if(C=="Matematicas 3"){
         MatematicasD s;
         curso = s;
    }
    else{
        CursoVacio V;
        curso = V;}
    return curso;
}
// --------------------------------------------------------------


int main(){
    Carrera_ITI ITI;
    ITI.ObtenerCarrera("Ingenieria en sistemas");
    ITI.curso.Mostrar();

    Carrera_ITI T;
    T.ObtenerCarrera("Herramientas web");
    T.curso.Mostrar();

    Carrera_Sistema S;
    S.ObtenerCarrera("Matematicas 3");
    S.curso.Mostrar();
    return 0;
}
