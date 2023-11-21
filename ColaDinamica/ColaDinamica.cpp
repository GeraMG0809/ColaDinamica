#include <iostream>
#include"Solicitud.cpp"

template<class T>
class Cola;

template<class T>
class node{
private:
    T data;
    node<T>* sig;
public:
    node();
    node(const T&);

    void setData(const T&);
    void setSiguiente(node<T>*);

    T getData();
    node<T>* getSiguiente();
};

template<class T >
node<T>::node(){sig == nullptr;}


template<class T>
node<T>::node(const T& dat){
    data  = dat;
    sig  = nullptr;
}


template<class T>
void node<T>::setData(const T& dat){
    data = dat;
}

template<class T>
void node<T>::setSiguiente(node<T>* pos){
    sig = pos;
}

template<class T>
T node<T>::getData(){
    return data;
}

template<class T>
node<T>* node<T>::getSiguiente(){
    return sig;
}


template<class T>
class Cola{
private:
    node<T>* header;
    node<T>* ultimo()const;
    node<T>* primero()const;
    node<T>* anterior(node<T>* pos)const;
    void insertar(node<T>* pos, T elem);
    bool eliminar(node<T>* pos);
public:
    Cola():header(nullptr){};
    bool vacia()const;
    void imprimir()const;
    void Enqueue(T elem);
    void Dequeue();
    T Front();
};

template<class T>
T Cola<T>::Front(){
    if(!vacia()){
       return primero()->getData();
    }
}

template<class T>
void Cola<T>::Dequeue(){
    eliminar(primero());
}

template<class T>
void Cola<T>::Enqueue(T elem){
    insertar(ultimo(),elem);
}

template<class T>
void Cola<T>::imprimir()const{
    node<T>* aux=header;
    while(aux!=nullptr){
        std::cout<<aux->getData()<<"-> ";
        aux=aux->getSiguiente();
    }
}

template<class T>
bool Cola<T>::eliminar(node<T>* pos){
    if(vacia() || pos==nullptr){
        return false;
    }
    if(pos==header){
        header=header->getSiguiente();
    }
    else{
        anterior(pos)->setSiguiente(pos->getSiguiente());
    }
    delete pos;
    return true;
}

template<class T>
void Cola<T>::insertar(node<T>* pos, T elem){
    node<T>* aux= new node<T>;
    aux->setData(elem);
    if(pos==nullptr){
        aux->setSiguiente(header);
        header=aux;
    }
    else{
        aux->setSiguiente(pos->getSiguiente());
        pos->setSiguiente(aux);
    }
}

template<class T>
node<T>* Cola<T>::anterior(node<T>* pos)const{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    node<T>* aux=header;
    while(aux!=nullptr && aux->getSiguiente()!=pos){
        aux=aux->getSiguiente();
    }
    return aux;
}

template<class T>
node<T>* Cola<T>::primero()const{
    if(vacia()){
        return nullptr;
    }
    return header;
}


template<class T>
node<T>* Cola<T>::ultimo()const{
    if(vacia()){
        return nullptr;
    }
    node<T>* aux=header;
    while(aux->getSiguiente()!=nullptr){
        aux=aux->getSiguiente();
    }
    return aux;
}

template<class T>
bool Cola<T>::vacia()const{
    if(header==nullptr)
        return true;
    return false;
}

