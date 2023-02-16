#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = __INT_MAX__;

typedef struct node_letter {
    char letter;
    struct node_letter* next;
} node_letter;

typedef struct Head_Word_letter {
    node_letter* start;
    node_letter* end;
} Head_Word_letter;

typedef struct node_main_list {
    Head_Word_letter* head_word_letter;
    struct node_main_list* next;
} node_main_list;

typedef struct Head_main_list {
    node_main_list* start;
    node_main_list* end;
} Head_main_list;

Head_Word_letter* start_word() {
    Head_Word_letter* h = (Head_Word_letter*)malloc(sizeof(Head_Word_letter));
    h->start = NULL;
    h->end = NULL;
    return h;
}

Head_main_list* start_main_list() {
    Head_main_list* h = (Head_main_list*)malloc(sizeof(Head_main_list));
    h->start = NULL;
    h->end = NULL;
    return h;
}

node_letter*    create_node_word(char value) {
    node_letter* temp = (node_letter*)malloc(sizeof(node_letter));
    if (temp == NULL) return NULL;
    temp->letter = value;
    temp->next = NULL;
    return temp;
}

node_main_list* create_node_main_list(Head_Word_letter* head_letter) {
    struct node_main_list* temp =
        (node_main_list*)malloc(sizeof(node_main_list));
    if (temp == NULL) return NULL;
    temp->head_word_letter = head_letter;
    temp->next = NULL;
    return temp;
}

Head_Word_letter* add_node_word(Head_Word_letter* head_word, char word[],
                                int lenght) {
    node_letter* temp = (node_letter*)malloc(sizeof(node_letter));
    if (temp == NULL) {
        return NULL;
    } else {
        for (int i = 0; i < lenght; i++) {
            if (word[i] != '\0') {
                temp = create_node_word(word[i]);
                if (head_word->start == NULL) {
                    head_word->start = temp;
                    head_word->end = temp;
                } else {
                    head_word->end->next = temp;
                    head_word->end = temp;
                }
            }
        }
    }
    return head_word;
}

Head_main_list* add_node_main_list(Head_main_list* main_list,
                                   Head_Word_letter* head_word) {
    node_main_list* temp = (node_main_list*)malloc(sizeof(node_main_list));
    if (temp == NULL) {
        return NULL;
    } else {
        temp = create_node_main_list(head_word);
        if (main_list->start == NULL) {
            main_list->start = temp;
            main_list->end = temp;
        } else {
            main_list->end->next = temp;
            main_list->end = temp;
        }
    }
    return main_list;
}

void search_string(Head_main_list* main_list, Head_Word_letter* last_word) {
    node_main_list* temp_list = main_list->start;

    node_letter* search_word = last_word->start;

    while (temp_list->next != NULL) {
        node_letter* target_word = temp_list->head_word_letter->start;
        unsigned long long count = 0;
        while (target_word != NULL) {
            if (target_word->letter == search_word->letter) {
                search_word = search_word->next;
                target_word = target_word->next;

                if (search_word == NULL) {
                    count++;
                    search_word = last_word->start;
                }
                if (target_word == NULL) {
                    break;
                }

            } else {
                target_word = target_word->next;
            }
        }
        printf("%lld\n",count);
        temp_list = temp_list->next;
    }
}

int main() {
    Head_main_list* main_list = start_main_list();

    char word[4194304 - 1];
    Head_Word_letter* last_word = start_word();

    while (scanf(" %s", word) != EOF) {
        Head_Word_letter* temp = start_word();
        add_node_word(temp, word, strlen(word));
        add_node_main_list(main_list, temp);

        last_word = temp;
    }
    
    search_string(main_list, last_word);
}