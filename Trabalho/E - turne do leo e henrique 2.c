#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 26

struct node {
    char name[MAX_NAME_LEN + 1];
    struct node *next;
};

struct queue {
    struct node *head;
    struct node *tail;
};

void enqueue(struct queue *q, char *name) {
    struct node *new_node = malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    new_node->next = NULL;
    
    if (q->head == NULL) {
        q->head = q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

void dequeue(struct queue *q) {
    if (q->head == NULL) {
        return;
    }
    
    struct node *temp = q->head;
    q->head = q->head->next;
    
    if (q->head == NULL) {
        q->tail = NULL;
    }
    
    free(temp);
}

char *front(struct queue *q) {
    return q->head->name;
}

int main() {
    struct queue q = {NULL, NULL};
    char city[MAX_NAME_LEN + 1];
    
    while (scanf("%s", city) != EOF) {
        enqueue(&q, city);
    }
    
    while (q.head != NULL) {
        printf("%s\n", front(&q));
        char *current_city = front(&q);
        dequeue(&q);
        
        int current_len = strlen(current_city);
        char next_char = current_city[current_len - 1];
        
        for (struct node *node = q.head; node != NULL; node = node->next) {
            if (node->name[0] == next_char) {
                char *temp = node->name;
                node->name[0] = q.tail->name;
                q.tail->name[0] = temp;
                q.tail = q.tail->next;
                break;
            }
        }
    }
    
    return 0;
}
