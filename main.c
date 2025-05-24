#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUM_STUDENTS 5
#define NUM_TESTS 13

int main() {
    char names[NUM_STUDENTS][11];  // Имена (до 10 символов + '\0')
    int grades[NUM_STUDENTS][NUM_TESTS];
    double averages[NUM_STUDENTS];

    // Ввод данных
    for (int i = 0; i < NUM_STUDENTS; i++) {
        scanf("%10s", names[i]);
        for (int j = 0; j < NUM_TESTS; j++) {
            scanf("%d", &grades[i][j]);
        }
    }

    // Вычисление средних баллов
    for (int i = 0; i < NUM_STUDENTS; i++) {
        int sum = 0;
        for (int j = 0; j < NUM_TESTS; j++) {
            sum += grades[i][j];
        }
        averages[i] = sum / (double)NUM_TESTS;
    }

    // Находим ученика с наивысшим средним баллом
    int top_index = 0;
    for (int i = 1; i < NUM_STUDENTS; i++) {
        if (averages[i] > averages[top_index]) {
            top_index = i;
        }
    }

    // Вычисляем среднее по группе
    double total_sum = 0;
    for (int i = 0; i < NUM_STUDENTS; i++) {
        total_sum += averages[i];
    }
    double group_avg = total_sum / NUM_STUDENTS;

    // Вывод ученика с наивысшим средним баллом
    names[top_index][0] = toupper(names[top_index][0]);  // Преобразуем первую букву в большую
    printf("%s\n", names[top_index]);

    // Вывод учеников с средним баллом ниже среднего по группе
    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (averages[i] < group_avg) {
            names[i][0] = toupper(names[i][0]);
            printf("%s\n", names[i]);
        }
    }

    return 0;
}