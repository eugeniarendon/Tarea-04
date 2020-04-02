//Eugenia Rendón A00823813
#include <iostream>
#include <fstream>
using namespace std;
#include "Empleado.h"

int checar(int id, int k, Empleado arr[]){
  for(int x=0;x<k;x++){
    if(arr[x].getId() == id){
      return x;
    }
  }
  return -1;
  }

int main() {
  Empleado arr[20];
  int idEmpleado, horasTrabajadas, opcion,k=0,id,p, opcion1, opcion2, opcion3,opcion4,opcion5,opcion6,x,y,z;
  double sueldoFijo, sueldoHora,pago;
  ifstream archEntrada;

archEntrada.open("datosEmpleados.txt");
while(archEntrada>>idEmpleado>>sueldoFijo>>sueldoHora>>horasTrabajadas){ 
  arr[k].setId(idEmpleado);
  arr[k].setHorasT(horasTrabajadas);
  arr[k].setSueldoF(sueldoFijo);
  arr[k].setSueldoH(sueldoHora);
  k++;
}

do{
cout << "MENU EMPLEADO" << endl;
cout << "1. Modificar sueldo Fijo" << endl;
cout << "2. Modificar sueldo por horas" << endl;
cout << "3. Registrar horas trabajadas" << endl;
cout << "4. Calcular pago del empleado" << endl;
cout << "5. Ver lista empleados." << endl;
cout << "6. Terminar" << endl; 
cout << "Digite una opcion:"<< endl;
cin>> opcion;

switch(opcion){
//Modificar sueldo Empleado
  case 1:
  do{
    cout << "Escriba su ID" << endl;
    cin>>id;
    p=checar(id, k, arr);
    if(p>=0){
      do{
         cout << "¿Cual es su nuevo suledo fijo?" << endl;
         cin >> opcion1;
         arr[p].setSueldoF(opcion1);
       }while(sueldoFijo<0);
      }
    else{
      cout << "El ID no existe porfavor intente denuevo" << endl;
    }
  }while(p<0);

  break;

//Modificar sueldo por horas
  case 2:
  do{
   cout << "Escriba su ID" << endl;
    cin>>id;
    p=checar(id, k, arr);
    if(p>=0){
      do{
         cout << "¿Cual es su nuevo sueldo por horas?" << endl;
         cin >> opcion2;
         arr[p].setSueldoH(opcion2);
       }while(opcion2<0);
      }
    else{
      cout << "El ID no existe porfavor intente denuevo." << endl;
    }
    }while(p<0);

  break;

// Registrar horas trabajadas
  case 3:
  do{
  cout << "Escriba su ID" << endl;
    cin>>id;
    p=checar(id, k, arr);
    if(p>=0){
      do{
         cout << "¿Cuantas horas desea registrar?" << endl;
         cin >> opcion3;
         horasTrabajadas=arr[p].registroHoras(opcion3);
         arr[p].setHorasT(horasTrabajadas);
       }while(opcion3<0);
      }
    else{
      cout << "El ID no existe porfavor intente denuevo." << endl;
    }
  }while(p<0);
  break;

//Calcular pago del empleado
  case 4:
  do{
  cout << "Escriba su ID" << endl;
    cin>>id;
    p=checar(id, k, arr);
    if(p>=0){
      do{
         cout << "El pago que le corresponde es de:" << endl;
          z=arr[p].getHorasT();
          y=arr[p].getSueldoH();
          x=arr[p].getSueldoF();
         pago=arr[p].calculoPago(x,z,y);
         cout << "$" << pago << endl;

       }while(opcion3<0);
      }
    else{
      cout << "El ID no existe porfavor intente denuevo." << endl;
    }
    }while(p<0);
  break;

//Ver lista empleados
  case 5:
  cout<<"La lista de empleados es:" << endl; cout <<"ID:A" << endl;
  cout << "Sueldo Fijo:B" << endl;
  cout << "Sueldo por Horas:C" << endl;
  cout << "Horas Trabajadas:D" << endl;
  cout << "A " << " B " << " C" << "  D"<< endl;
  for(int i = 0; i < k; i++){ 
    arr[i].getDetails(); 
    }
  break;

//Terminar
  case 6:
  cout << "GRACIAS" << endl;
  break;

  default:
  if(opcion <0 || opcion >6){
    cout << "Esta opcion no es valida!"<< endl;
  }

}
}while(opcion!=6);
;

archEntrada.close();

return 0;
}



  