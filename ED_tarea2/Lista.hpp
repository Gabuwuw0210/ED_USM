#ifndef LISTA_HPP
#define LISTA_HPP

class tLista {
private:
    int* elements;
    unsigned int size;
    unsigned int maxSize;

public:
    tLista(unsigned int MAXSIZE);
    ~tLista();
    tLista();

    void clear();
    int erase(unsigned int position);
    int append(int item);
    int insert(unsigned int position, int item);
    int get_value(unsigned int position);
    int length();
};

#endif // LISTA_HPP

