#include "Arbol.h"

Tree::Tree() {//Constructor Definido.
    tree = NULL;
}

Tree:: ~Tree() {}//Destructor.

void Tree::insert_Data(Nodo*& tree, int number, Nodo* principal) {//Función que nos ayudará a insertar los datos dentro del arbol e irlos acomodando depende del grado del numero (<,>).
    if (tree == NULL) {
        Nodo* new_Nodo = new Nodo(number, principal);
        tree = new_Nodo;
    }else {
        int root_data = tree->get_Data();
        if (number < root_data)
            insert_Data(tree->get_Izq(), number, tree);
        else
            insert_Data(tree->get_Der(), number, tree);
    }
}

void Tree::Destroy_Data(Nodo* Data) {//Esta función nos ayudará a destruir los datos de los nodos, volviendo a poner nodos en NULL.
    Data->set_Der(NULL);
    Data->set_Izq(NULL);

    delete Data;
    Data = NULL;
}

void Tree::Show(Nodo* tree, int counter) {
    if (tree == NULL) {
        cout << "Imposible, no hay datos en el arbol." << endl;
    }
    else {
        show_All(tree, counter);
    }
}

void Tree::show_All(Nodo* tree, int counter) {//Función que nos mostrará el acomodo del arbol.
    if(tree == NULL) {
        return;
    }else{
        show_All(tree->get_Der(), counter + 1);
        for(int i = 0; i < counter; i++) cout << "   ";
        cout << tree->get_Data() << endl;
        show_All(tree->get_Izq(), counter + 1);
    }
}

void Tree::Delete_All(Nodo* tree, int number) {//Función que nos ayudará a borrar todo el arbol, en caso de ser necesario.
    if (tree == NULL)
        return;
    else if (number < tree->get_Data())
        Delete_All(tree->get_Izq(), number);
    else if (number > tree->get_Data())
        Delete_All(tree->get_Der(), number);
    else
        Delete_Data(tree);
}

bool Tree::search_Data(Nodo* tree, int number) {//Función que nos ayudará a ir buscando por nodo hoja para encontrar el valor deseado.
    if (tree == NULL)
        return false;
    else if (tree->get_Data() == number)
        return true;
        else if (number > tree->get_Data())
            return search_Data(tree->get_Der(), number);
        else
            return search_Data(tree->get_Izq(), number);
}

void Tree::Delete_Data(Nodo* aux) {//Esta función se implementará para poder eliminar un nodo en particular, se puede observar como irá buscando nodo por nodo para poder eliminarlo.
    if (aux->get_Izq() && aux->get_Der()) {
        Nodo* menor = minumium_Data(aux->get_Der());
        aux->set_Data(menor->get_Data());
        Delete_Data(menor);
    }
    else if (aux->get_Izq()) {
        Change_Someone(aux, aux->get_Izq());
        Destroy_Data(aux);
    }
    else if (aux->get_Der()) {
        Change_Someone(aux, aux->get_Der());
        Destroy_Data(aux);
    }
    else {
       Delete_Data_Leaf(aux, tree);
    }
}

void Tree::Show_Data_Preorder(Nodo* tree) {//Función que nos mostrará el arbol en un preorden.
    if (tree == NULL) {
        //cout << "Imposible mostrar, no hay datos en el arbol!!!";
        return;
    } else {
        cout << tree->get_Data() << ", ";
        Show_Data_Preorder(tree->get_Izq());
        Show_Data_Preorder(tree->get_Der());
    }
}

int Tree::Count_Data(Nodo* tree) {//Función que ayuda a contar los nodos totales dentro del arbol.
    if (tree == NULL)
        return 0;
    else
        return (Count_Data(tree->get_Izq())+1 + Count_Data(tree->get_Izq()));
}

int Tree::Count_Data_leaf(Nodo* tree) {//Funcion que nos permite contar las hojas totales del arbol.
    if (tree == NULL)
        return 0;
    if (tree->get_Der() == NULL && tree->get_Izq() == NULL)
        return 1;
    else
        return Count_Data_leaf(tree->get_Der()) + Count_Data_leaf(tree->get_Izq());
}

void Tree::Delete_Data_Leaf(Nodo*& suppress, Nodo*& root) {//Esta función eliminará solo aquel dato hoja que el usuario requiera, es parecita a la función eliminar nodo, pero esta se implementa con condiciones destinadas a las hojas en particular.
    if (suppress->get_Principal() != NULL) {
        if (right_Branch(suppress))
            suppress->get_Principal()->set_Der(NULL);
        else
            suppress->get_Principal()->set_Izq(NULL);
    }
    else if (root == suppress)
        root = NULL;
    Destroy_Data(suppress);
}

int Tree::Tree_Height(Nodo* nodo) {//Función que nos permite saber la altura total del arbol, importante recordar que esta empieza de la raiz base hasta las hojas.
    if (nodo == NULL)
        return 0;
    if (Tree_Height(nodo->get_Izq()) > Tree_Height(nodo->get_Der()))
        return Tree_Height(nodo->get_Izq()) + 1;
    else
        return Tree_Height(nodo->get_Der()) + 1;
}

bool Tree::right_Branch(Nodo*& son) {//Nos ayudará a poder identificar los nodos hijos encontrados del lado derecho para así en la función de eliminar nodos hoja, se elimine tambien los de la derecha.
    if (son->get_Principal()->get_Der() == son)
        return true;
    return false;
}

Nodo* Tree::minumium_Data(Nodo* aux) {
    if (aux == NULL)
        return NULL;
    if (aux->get_Izq())
        return minumium_Data(aux->get_Izq());
    else
        return aux;
}

Nodo* Tree::maximium_Data(Nodo* aux) {
    if (aux == NULL)
        return NULL;
    if (aux->get_Der())
        return maximium_Data(aux->get_Der());
    else
        return aux;
}

void Tree::Change_Someone(Nodo* tree, Nodo* new_Data) {
    if (tree->get_Principal()) {
        if (tree->get_Data() == tree->get_Principal()->get_Izq()->get_Data())
            tree->get_Principal()->set_Izq(new_Data);
        else if (tree->get_Data() == tree->get_Principal()->get_Der()->get_Data())
            tree->get_Principal()->set_Der(new_Data);
    }
    if (new_Data)
        new_Data->set_Principal(tree->get_Principal());
}