/*
 * Author: Жулего Алина
 * Group: 10а группа
 *
 * Description:
 * Задание 1, вариант 37.
 * Программа читает две строки из аргументов командной строки,
 * проверяет их равенство по длине и строит новую строку по правилу:
 * на нечетных позициях - символы первой строки,
 * на четных позициях - символы второй строки.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Объединяет две строки по заданному правилу.
 *
 * @param str1 Указатель на первую строку.
 * @param str2 Указатель на вторую строку.
 * @return char* Указатель на новую строку (должна быть освобождена через free()).
 *         В случае ошибки (разная длина) возвращает NULL.
 */
char* merge_strings(const char *str1, const char *str2) {
		size_t len1 = strlen(str1);
		size_t len2 = strlen(str2);

		// Проверка на равенство длин
		if (len1 != len2) {
				fprintf(stderr, "Ошибка: строки имеют разную длину.\n");
				return NULL;
		}

		size_t new_len = len1 + len2;
		// Выделяем память для новой строки (+1 для завершающего нуля)
		char *result = (char*)malloc(new_len + 1);
		if (result == NULL) {
				fprintf(stderr, "Ошибка: не удалось выделить память.\n");
				return NULL;
		}

		int i, j;
		// Заполняем строку
		for (i = 0, j = 0; i < len1; i++) {
				result[j++] = str1[i]; // Нечетное место - элемент первой строки
				result[j++] = str2[i]; // Четное место - элемент второй строки
		}
		result[j] = '\0';

		return result;
}

/**
 * @brief Точка входа в программу.
 *
 * @param argc Количество аргументов командной строки.
 * @param argv Массив аргументов.
 * @return int Код возврата (0 - успех, 1 - ошибка).
 */
int main(int argc, char *argv[]) {
		// Проверка количества аргументов
		if (argc != 3) {
				fprintf(stderr, "Использование: %s \"строка1\" \"строка2\"\n", argv[0]);
				fprintf(stderr, "Строки должны быть одинаковой длины.\n");
				return 1;
		}

		char *str1 = argv[1];
		char *str2 = argv[2];

		printf("Исходные данные:\n");
		printf("Строка 1: %s\n", str1);
		printf("Строка 2: %s\n", str2);
		printf("----------------------------------------\n");

		char *merged = merge_strings(str1, str2);

		if (merged != NULL) {
				printf("Результат: %s\n", merged);
				free(merged);
				return 0;
		} else {
				return 1;
		}
}