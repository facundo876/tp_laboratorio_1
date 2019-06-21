#ifndef __ARRAYEMPLOYEES
#define __ARRAYEMPLOYEES

struct
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
}typedef Employee;

int opcionMenu(void);
int initEmployees(Employee* list, int len);
int buscarLibre(Employee* list, int len);
int altaEmpleado(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[], char lastName[],float salary,int sector);
int findEmployeeById(Employee* list, int len,int id);
void mostrarEmpleado(Employee empleado);
int bajaEmpelado(Employee* list, int len);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);
int modificarEmpleado(Employee* list, int len);
int opcionMenuModificar(void);
void cambiarNombre(Employee* empleado);
void cambiarApellido(Employee* empleado);
void cambiarSueldo(Employee* empleado);
void cambiarSector(Employee* empleado);
int funcionInformar(Employee* list, int len);
int opcionMenuInformar(void);
int promedioSueldo(Employee* list, int len);
void noSuperaElSalario(Employee* list, int len);
void cargaDeDatos(Employee *list,int len);

#endif // __ARRAYEMPLOYEES

