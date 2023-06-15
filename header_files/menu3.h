// menu3.h
#ifndef MENU3_H
#define MENU3_H

#include "goback.h"
#include <iostream>
#include <fstream>
#include <string>

// Estructura para el nodo del árbol binario de búsqueda
struct TreeNode {
    std::string name;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const std::string& userName) : name(userName), left(nullptr), right(nullptr) {}
};

// Función para insertar un nuevo nombre de usuario en el árbol
TreeNode* insertUser(TreeNode* root, const std::string& userName) {
    if (root == nullptr) {
        return new TreeNode(userName);
    }

    if (userName < root->name) {
        root->left = insertUser(root->left, userName);
    } else if (userName > root->name) {
        root->right = insertUser(root->right, userName);
    }

    return root;
}

// Función para imprimir los nombres de usuario en orden ascendente
void printUsers(TreeNode* root) {
    if (root != nullptr) {
        printUsers(root->left);
        std::cout << root->name << std::endl;
        printUsers(root->right);
    }
}

void menu3() {
    TreeNode* root = nullptr; // Raíz del árbol binario de búsqueda

    std::ifstream data("database");
    std::string line;
    int i = 0;

    // Construir el árbol binario de búsqueda con los nombres de usuario
    while (getline(data, line)) {
        if (i % 2 == 0) {
            root = insertUser(root, line);
        }
        i++;
    }
    data.close();

    std::cout << std::endl << "Usuarios registrados (no amigos)" << std::endl << std::string(32, '=') << std::endl;

    // Imprimir los nombres de usuario en orden ascendente
    printUsers(root);

    // Resto del código para enviar solicitudes de amistad (sin cambios)

    goback();

    // Liberar la memoria del árbol (opcional si no se necesita más adelante)
    // Implementar función para liberar el árbol (eliminar todos los nodos)
}

#endif // MENU3_H

