#include <stdio.h>
#include <string.h>

#define SIZE 5   // حجم المخزن 

// مخزن بحرف واحد 
char buffer[SIZE];
int head = 0;
int tail = -1;
int count = 0;

// التحقق من الامتلاء
int isFull() {
    return count == SIZE;
}

// التحقق من الفراغ
int isEmpty() {
    return count == 0;
}

// إضافة 
void enqueue(char value) {
    if (isFull()) {
        printf("Overflow: Buffer is full!\n");
        return;
    }

    tail = (tail + 1) % SIZE;
    buffer[tail] = value;
    count++;
}

// حذف 
char dequeue() {
    if (isEmpty()) {
        printf("Underflow: Buffer is empty!\n");
        return '\0';
    }

    char value = buffer[head];
    head = (head + 1) % SIZE;
    count--;
    return value;
}

int main() {
    char name[50];

    // إدخال الاسم
    printf("Enter your name: ");
    scanf("%s", name);

    int length = strlen(name);

    // إدخال كل حرف في المخزن
    for (int i = 0; i < length; i++) {
        enqueue(name[i]);
    }

    //  CE-ESYإضافة
    printf("output: ");
    while (!isEmpty()) {
        printf("%c", dequeue());
    }
    printf("_CE-ESY\n");

    // التأكد أن المخزن فارغ
    if (isEmpty()) {
        printf("Buffer is now empty.\n");
    }

    return 0;
}