// queueproblem.c – Lab 02 – Alexandra, Cramarossa

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    unsigned int val;
};
typedef struct node node_1, *p_node;

struct queue {
    int length;
    p_node head;
};
typedef struct queue queue_1, *p_queue;

//Makes nodes with specified value
p_node make_node(int value) {
    p_node node_new = (p_node) malloc(sizeof(node_1));
    node_new->val = value;
    node_new->next = NULL;
    return node_new;
}
//Adding value to queue
void queue_add(queue_1 *queue, node_1 *node) {
    if (queue->head == NULL) {
        queue->head = node;
    } else {
        p_node counter = queue->head;
        while (counter->next != NULL) {
            counter = counter->next;
        }
        counter->next = node;
    }
    queue->length++;
}
//Printing queue
void queue_print(queue_1 queue) {
    node_1 current = *queue.head;
    if (queue.head != NULL) {
        for (int i = 0; i<queue.length; i++){
            if (i % 12 == 0)
                printf("\n");
            printf("%5d ", current.val);
        }
    }
}
int main() {
    //Creates 4 different queues
    queue_1 list[4];
    for (int i = 0; i < 4; i++) {
        p_queue pq;
        pq = (p_queue) malloc(sizeof(queue_1));
        pq->head = NULL;
        pq->length = 0;
        list[i] = *pq;
    }
    //Gets input from user of up to 400 terms
    int input[400];
    for (int i = 0; i<400; i++) {
        scanf("%d", &input[i]);
        if (input[i] < 0) {
            break;
        }
        //Adds the value to the queue
        queue_add(&list[input[i] % 4], node_new(input[i]));
    }
    for (int i = 0; i < 4; i++) {
        queue_print(list[i]);
    }
    printf("\n");
}
