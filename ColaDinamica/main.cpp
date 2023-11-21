#include"ColaDinamica.cpp"


int main(){
    Cola<Solicitud> solicitudes;
    int opcion;
    do {
        std::cout << "\t \n === MENU ===" << std::endl;
        std::cout << "1. Dar de alta solicitud" << std::endl;
        std::cout << "2. Elaborar constancia" <<std:: endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Ingrese la opcion: ";
        std::cin >> opcion;
        std::cin.ignore();
        switch(opcion){
            case 1:{
                    Solicitud nueva_solicitud;
                    std::cin >> nueva_solicitud;
                    solicitudes.Enqueue(nueva_solicitud);
                    std::cout << "Solicitud encolada exitosamente." << std::endl;
                    break;
                }
            case 2:{
                    if(!solicitudes.vacia()){
                        Solicitud solicitud_actual = solicitudes.Front();
                        std::cout << "=== CONSTANCIA ===" << std::endl;
                        std::cout << solicitud_actual << std::endl;
                        solicitudes.Dequeue();
                        std::cout << "Solicitud eliminada de la cola exitosamente." << std::endl;
                    } else {
                        std::cout << "No hay solicitudes pendientes." << std::endl;
                    }
                    break;
                }
            case 3:{
                std::cout <<" Saliendo del programa...";
                break;
                }
            default:{
                std::cout<<"\nOpcion invalida "<<std::endl;
                break;
            }
        }
    }while(opcion != 3);
}