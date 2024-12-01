#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define WORD_SIZE 50

typedef struct Node{
    char key[WORD_SIZE];
    char value[WORD_SIZE];
    struct Node *next;
} Node;

Node* HashTable[SIZE]; // definindo a tabela hash como um array de ponteiros para node

int Hash(const char *key){
    int hash = 0;
    int i;

    for (i = 0; i < strlen(key); i++){
        hash = hash + (int)key[i];
    }   
    return hash % SIZE;
}

void insert(const char *key, const char *value){
    int index = Hash(key);
    Node *node = (Node*)malloc(sizeof(Node)); // conversão do ponteiro genérico que é devolvido pelo malloc através casting (Node*)
    strcpy(node->key, key);
    strcpy(node->value, value);
    node->next = NULL;

    if (HashTable[index] == NULL){
        HashTable[index] = node;
    } else {
        Node *temp = HashTable[index];

        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = node; 
    }
}

char* search(const char *key){
    int index = Hash(key);
    Node *temp = HashTable[index];

    while (temp != NULL){
        if(strcmp(temp->key, key) == 0){ // 0 significa que as chaves são iguais
            return temp->value;
        }
        temp = temp->next;
    }
    return "A chave não foi encontrada!";
}

int main(){
    for (int i = 0; i < SIZE; i++){
        HashTable[i] = NULL;
    }
    
    insert("Sofia", "Santos");
    insert("Felipe", "Lima");

    printf("O valor associado a essa chave é: %s\n", search("Sofia"));
    
    return 0;
}