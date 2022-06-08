#include "Nodo.h"
#include "Arbol.h"
#include <iostream>

using namespace std;
Nodo* tree = NULL;
    Tree object_tree;

void insertarArbol() {
    object_tree.insert_Data(tree, 15, NULL);
    object_tree.insert_Data(tree, 7, NULL);
    object_tree.insert_Data(tree, 18, NULL);
    object_tree.insert_Data(tree, 5, NULL);
    object_tree.insert_Data(tree, 12, NULL);
    object_tree.insert_Data(tree, 25, NULL);
    object_tree.insert_Data(tree, 10, NULL);
    object_tree.insert_Data(tree, 14, NULL);
    object_tree.insert_Data(tree, 23, NULL);
}

int main(void) {
    int data = 0, opc = 0, counter = 0;
    

    cout << "Bienvenido al programa \"ARBOLES\"" << endl;
    system("pause");
    insertarArbol();

    do {
        system("cls");
        cout << "MENU:" << endl;
        cout << "1.- Insert a new Data." << endl;
        cout << "2.- Return the amount of data in the tree." << endl;
        cout << "3.- Return the amount of data leaf of the tree." << endl;
        cout << "4.- Print values in PREORDDER." << endl;
        cout << "5.- Return the height of the tree." << endl;
        cout << "6.- Print the maximiunm value of the tree." << endl;
        cout << "7.- Delete minimium data." << endl;
        cout << "8.- Show All Tree." << endl;
        cout << "9.- Exit" << endl;
        cout << "Enter the option to execute: ";
        cin >> opc;

        switch (opc) {
        case 1:
            system("cls");
            cout << "INSERT A NEW DATA." << endl;
            cout << "Please enter the number that will be registered in your tree: ";
            cin >> data;
            object_tree.insert_Data(tree, data, NULL);
            cout << "The data has been inserted successfully!!" << endl;
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "RETURN THE AMOUNT OF DATA IN THE TREE." << endl;
            cout << "The amount of data in the tree is: " << object_tree.Count_Data(tree) << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "RETURN THE AMOUNT OF LEAF DATA OF THE TREE." << endl;
            cout << "The amount of leaf data int the tree is: " << object_tree.Count_Data_leaf(tree) << endl;
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "PRINT VALUES IN PREORDER." << endl;
            object_tree.Show_Data_Preorder(tree);
            cout << endl;
            system("pause");
            break;
        case 5:
            system("cls");
            cout << "RETURN THE HEIGHT OF TREE." << endl;
            cout << "The height of tree is: " << object_tree.Tree_Height(tree);
            cout << endl;
            system("pause");
            break;
        case 6:
            system("cls");
            cout << "PRINT THE MAXIMIUM VALUE OF TREE." << endl;
            cout << "The maximium data in the tree is: " << object_tree.maximium_Data(tree)->get_Data() << endl;
            system("pause");
            break;
        case 7:
            system("cls");
            cout << "DELETE MINIMIUM DATA." << endl;
            cout << object_tree.minumium_Data(tree)->get_Data() << endl;
            object_tree.Delete_All(tree, object_tree.minumium_Data(tree)->get_Data());
            cout << "The minimium value was successfully removed from the tree!!" << endl;
            system("pause");
            break;
        case 8:
            system("cls");
            cout << "SHOW ALL TREE." << endl;
            object_tree.Show(tree, counter);
            system("pause");
            break;
        case 9:
            system("cls");
            cout << "You have successfully exited the program thank you!!";
            system("pause");
            break;
        default: 
            cout << "This option does not exist, please enter existing option.";
        }
    } while (opc != 9);

    return 0;
}