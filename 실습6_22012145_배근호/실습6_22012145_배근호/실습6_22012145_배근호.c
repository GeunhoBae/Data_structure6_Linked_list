#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct {//�⺻���� ����Ʈ
    int data;
    struct node* next;
} node;
node* ptr = NULL;

//�⺻���� �Լ�
void print_list(node* A) {
    printf("����Ʈ: Head");
    for (ptr = A; ptr != NULL; ptr = ptr->next) {
        printf("->%d", ptr->data);
    }
    printf("->Null\n\n");
}

void insert_front(node** A, int data) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = *A;
    *A = temp;
}

void insert_last(node** A, int data) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if (*A == NULL) {
        *A = temp;
    }
    else {
        for (ptr = *A; ptr->next != NULL; ptr = ptr->next) {}
        ptr->next = temp;
    }
}

int search(node* A, int data) {
    int count = 0;
    for (ptr = A; ptr != NULL; ptr = ptr->next, count++) {
        if (ptr->data == data) return count;
    }
    return -999;
}

int delete_front(node** A) {
    if (*A == NULL) return -999;
    int deleted_data;
    ptr = *A;
    deleted_data = ptr->data;
    *A = (*A)->next;
    free(ptr);
    return deleted_data;
}

int delete(node** A, int data) {
    if (*A == NULL) return -999;
    int deleted_data; node* before = *A;
    if ((*A)->data == data) return delete_front(&(*A));
    for (ptr = *A; ptr->data != data; ptr = ptr->next) {
        before = ptr;
        if (before->next == NULL) return -999;
    }
    before->next = ptr->next;
    deleted_data = ptr->data;
    free(ptr);
    return deleted_data;
}

//���ÿ��� �Լ�
void push(node** B, int data) {
    insert_front(&(*B), data);
}

int pop(node** B) {
    int deleted_data;
    deleted_data = delete_front(&(*B));
    return deleted_data;
}

//ť���� �Լ�
void addq(node** C, int data) {
    insert_last(&(*C), data);
}

int deleteq(node** C) {
    int deleted_data;
    deleted_data = delete_front(&(*C));
    return deleted_data;
}

void main() {
    int menu, data, node_count, deleted_data;
    node* A = NULL;
    while (1) {
        printf("����Ʈ �⺻����\n");
        printf("0. print list\n1. insert_front\n2. insert_last\n3. delete_front\n4. delete\n5. search\n-1. exit\n");
        printf("� ����� �����ұ��? : ");
        scanf("%d", &menu);

        if (menu == -1) { printf("Bye Bye\n"); break; }
        switch (menu) {
        case 0: //print_list
            print_list(A);
            break;
        case 1: //insert_front
            printf("������: ");
            scanf("%d", &data);
            insert_front(&A, data);
            print_list(A);
            break;
        case 2: //insert_last
            printf("������: ");
            scanf("%d", &data);
            insert_last(&A, data);
            print_list(A);
            break;
        case 3: //delete_front
            deleted_data = delete_front(&A);
            printf("���� ������: %d\n", deleted_data);
            print_list(A);
            break;
        case 4: //delete
            printf("������: ");
            scanf("%d", &data);
            deleted_data = delete(&A, data);
            printf("���� ������: %d\n", deleted_data);
            print_list(A);
            break;
        case 5: //search
            printf("������: ");
            scanf("%d", &data);
            node_count = search(A, data);
            printf("����ȣ: %d\n", node_count);
            print_list(A);
            break;
        default:
            printf("-1~5�� ���� �Է��Ͻÿ�\n");
            break;
        }
    }
    //stack
    int stack_menu;
    node* stack = NULL;
    while (1) {
        printf("����Ʈ�� ������ ����\n");
        printf("1.push\n2.pop\n-1.exit\n");
        printf("� ����� �����ұ��? : ");
        scanf("%d", &stack_menu);
        if (stack_menu == -1) { printf("Stack Bye\n"); break; }
        switch (stack_menu) {
        case 1:
            printf("push item: ");
            scanf("%d", &data);
            push(&stack, data);
            printf("Stack: ");
            print_list(stack);
            break;
        case 2:
            deleted_data = pop(&stack);
            printf("pop item: %d\n", deleted_data);
            print_list(stack);
            break;
        default:
            printf("-1~2�� ���� �Է��Ͻÿ�\n");
            break;
        }
    }
    //que
    int que_menu;
    node* que = NULL;
    while (1) {
        printf("����Ʈ�� ������ ť\n");
        printf("1.addq\n2.deleteq\n-1.exit\n");
        printf("� ����� �����ұ��? : ");
        scanf("%d", &que_menu);
        if (que_menu == -1) { printf("Que Bye\n"); break; }
        switch (que_menu) {
        case 1:
            printf("addq item: ");
            scanf("%d", &data);
            addq(&que, data);
            printf("Que: ");
            print_list(que);
            break;
        case 2:
            deleted_data = deleteq(&que);
            printf("delete item: %d\n", deleted_data);
            print_list(que);
            break;
        default:
            printf("-1~2�� ���� �Է��Ͻÿ�\n");
            break;
        }
    }
}