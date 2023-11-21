#include<iostream>
#include<string>


class Solicitud{
    private:
        std::string Nombre;
        std::string Carrera;
        int  MateriasAprobadas;
        float Promedio;


    public:
        Solicitud();
        Solicitud(std::string, std::string, int, float);

        void setNombre(std::string);
        void setCarrera(std::string);
        void setMaterias(int);
        void setPromedio(float);


        std::string getNombre();
        std::string getCarrera();
        int getMaterias();
        float getPromedio();

        bool operator == (const Solicitud&)const;

        bool operator < (const Solicitud&)const;
        bool operator > (const Solicitud&)const;

        friend std::ostream& operator<<(std::ostream& os, Solicitud& solicitud){
            os << "Nombre del alumno: " << solicitud.getNombre() << std::endl;
            os << "Nombre de la carrera: " << solicitud.getCarrera() << std::endl;
            os << "Materias aprobadas: " << solicitud.getMaterias() << std::endl;
            os << "Promedio general: " << solicitud.getPromedio() << std::endl;
            return os;
        }

        
        friend std::istream& operator>>(std::istream& is ,  Solicitud& solicitud ){
            is.ignore();
            std::string Nombre,Carrera;
            std::cout << "Nombre del alumno: ";
            getline(is, Nombre);
            solicitud.setNombre(Nombre);
            std::cout << "Nombre de la carrera: ";
            getline(is, Carrera);
            solicitud.setCarrera(Carrera);
            std::cout << "Materias aprobadas: ";
            is >> solicitud.MateriasAprobadas;
            std::cout << "Promedio general: ";
            is >> solicitud.Promedio;
            return is;
                    
        };
        

};






Solicitud::Solicitud(){}


Solicitud::Solicitud(std::string name , std::string carrer, int mat, float prom){
    Nombre = name;
    Carrera = carrer;
    MateriasAprobadas = mat;
    Promedio = prom;
}


void Solicitud::setNombre(std::string name){
    Nombre = name;
}

void Solicitud::setCarrera(std::string carr){
    Carrera = carr;
}

void Solicitud::setMaterias(int mat){
    MateriasAprobadas  = mat;
}

void Solicitud::setPromedio(float prom){
    Promedio = prom;
}

std::string Solicitud::getNombre(){return Nombre;}

std::string Solicitud::getCarrera(){return Carrera;}

int Solicitud::getMaterias(){return MateriasAprobadas;}

float Solicitud::getPromedio(){return Promedio;}



bool Solicitud::operator==(const Solicitud& dat)const{
    return Nombre == dat.Nombre;
    return Carrera == dat.Carrera;
    return MateriasAprobadas == dat.MateriasAprobadas;
    return Promedio == dat.Promedio;
}

bool Solicitud::operator<(const Solicitud& dat)const{
    return Promedio < dat.Promedio;
}

bool Solicitud::operator > (const Solicitud& dat)const{
    return Promedio > dat.Promedio;
}