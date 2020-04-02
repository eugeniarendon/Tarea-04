 // Empleado.h
#include <iostream>

class Empleado
{
  public:
  Empleado();//default
  //metodos de modificación
  void setId(int id){ idEmpleado=id;};
  void setHorasT(int h){ horasTrabajadas=h;};
  void setSueldoF(double f){ sueldoFijo=f;};
  void setSueldoH(double shora){ sueldoHora=shora;};
  //metodos de acceso
  int getId(){ return idEmpleado;};
  int getHorasT(){ return horasTrabajadas;};
  double getSueldoF(){ return sueldoFijo;};
  double getSueldoH(){ return sueldoHora;};
  //meodos necesarios
  int registroHoras(int hT);
  double calculoPago(double sueldoFijo, int horasTrabajadas, double sueldoHora);
  void getDetails();

  private:
  int idEmpleado, horasTrabajadas;
  double sueldoFijo, sueldoHora;
};

Empleado::Empleado(){
  idEmpleado=0;
  horasTrabajadas=0;
  sueldoFijo=0;
  sueldoHora=0;
}

int Empleado::registroHoras(int hT){
  horasTrabajadas=horasTrabajadas+hT;
  return horasTrabajadas;
}

double Empleado::calculoPago(double sueldoFijo, int horasTrabajadas, double sueldoHora){
return sueldoFijo+(horasTrabajadas * sueldoHora);

}

void Empleado::getDetails()
{ cout << idEmpleado << " " <<sueldoFijo << " "<< sueldoHora << " "<< horasTrabajadas << endl;
}