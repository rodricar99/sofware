#include<iostream>
using namespace std;

class fecha{
    private:
        int dis;
        int mess;
        int anioo;
    public:
        fecha(int dia, int mes,int anio):dis(dia),mess(mes),anioo(anio){  
        };
        ~fecha()=default;
        bool recibir_fecha(fecha*f){
            if (f->get_anioo()-18 == get_anioo()){
                if(f->get_mess()<get_mess()){
                    return false;
                }
                else if(f->get_mess() ==  get_mess()){
                    if(f->get_dia() >= get_dia()){
                        return true;
                    }
                    else {
                        return false;
                    }
                }
                else{
                    return true;
                }
            }
            else if(f->get_anioo()-18 > get_anioo()){
                return true;
            }
            else{
                return false;
            }
        };
         int get_dia()const{
            return dis;
        } 
         int get_mess() const{
            return mess;
        } 
         int  get_anioo()const{
            return anioo;
        } 

};

class Registro_naci:public fecha{
    public:
        Registro_naci(int _dia,int _mes, int _anio):fecha(_dia,_mes,_anio){};
};

class Registro_consulta:public fecha{
    public:
        Registro_consulta(int _dia,int _mes, int _anio):fecha(_dia,_mes,_anio){};
};
int main(){
    int dia_n;
    int mes_n;
    int anio_n;
    int dia_c;
    int mes_c;
    int anio_c;
    cout << "Datos de nacimiento\n";
    cout << "Dia: ";
    cin >> dia_n;
    cout << "Mes: ";
    cin >> mes_n;
    cout << "Anio: ";
    cin >> anio_n;
    cout << "Datos de consulta\n";
    cout << "Dia: ";
    cin >> dia_c;
    cout << "Mes: ";
    cin >> mes_c;
    cout << "Anio: ";
    cin >> anio_c;
    auto registro_nacimiento = new Registro_naci(dia_n,mes_n,anio_n);
    auto registro_consulta = new Registro_consulta(dia_c,mes_c,anio_c);
    bool res = registro_nacimiento->recibir_fecha(registro_consulta);
    delete registro_consulta;
    delete registro_nacimiento;
    cout <<  boolalpha<< res << endl;
};