#include<stdlib.h>
#include<stdio.h>

typedef struct node* pnode;

struct node {
    int data;
    pnode next ;
};

void print_list(pnode head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insert_node(pnode head, pnode new_node, pnode prev_node) {
    pnode list;
    list = head;

    while (list != prev_node) {
        list = list->next;
    }
    if(list->next != NULL)
        new_node->next = list->next;
    list->next = new_node;
}

void delete_node(pnode head, pnode del_node){
    pnode list;
    list = head;
    while(list->next != del_node){
        list = list->next;
    }
    list->next = del_node->next;
}

int main() {
    struct node node1, node2, node3;
    node1.next = NULL;
    node2.next = NULL;
    node3.next = NULL;
    node1.data = 5;
    node2.data = 4;
    node3.data = 3;

    insert_node(&node1, &node2, &node1);
    insert_node(&node1, &node3, &node2);
    print_list(&node1);
    delete_node(&node1, &node2);

    print_list(&node1);
}