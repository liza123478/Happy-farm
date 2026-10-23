#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

#define HOURS_PER_DAY 24
#define INVENTORY_SIZE 10
#define ITEMS_COUNT 10

#define ITEM_EMPTY 0
#define ITEM_WOOD 1
#define ITEM_STONE 2
#define ITEM_SEEDS 3
#define ITEM_WATER 4
#define ITEM_CARROT 5
#define ITEM_HAY 6
#define ITEM_ROPE 7
#define ITEM_ROD 8
#define ITEM_HOE 9

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int current_day = 1;
    int current_hour = 8;
    int choice;
    int work_hours;

    int inventory[INVENTORY_SIZE] = {
        ITEM_WOOD, ITEM_STONE, ITEM_EMPTY,
        ITEM_WATER, ITEM_CARROT, ITEM_HOE,
        ITEM_SEEDS, ITEM_EMPTY, ITEM_ROD, ITEM_ROPE
    };

    while (1)
    {
        printf("\n====== ВЕСЁЛЫЙ ФЕРМЕР ======\n");
        printf("[0] Выход\n");
        printf("[1] Посмотреть на часы\n");
        printf("[2] Промотать время (Поработать)\n");
        printf("[3] Посмотреть инвентарь\n");
        printf("[4] Положить предмет в слот\n");
        printf("[5] Выбросить предмет\n");
        printf("[6] Выполнить задание по варианту\n");
        printf("Выберите пункт: ");

        if (scanf("%d", &choice) != 1)
        {
            scanf("%*s");
            printf("Ошибка! Введите число.\n");
            continue;
        }

        switch (choice)
        {
        case 0:
            printf("Выход из программы.\n");
            return 0;

        case 1:
            printf("Текущее время: День %d, %02d:00\n",
                current_day, current_hour);
            break;

        case 2:
            printf("Сколько часов хотите поработать? ");

            if (scanf("%d", &work_hours) != 1)
            {
                scanf("%*s");
                printf("Ошибка! Введите число.\n");
                break;
            }

            if (work_hours < 0)
            {
                printf("Количество часов не может быть отрицательным.\n");
                break;
            }

            current_hour += work_hours;
            current_day += current_hour / HOURS_PER_DAY;
            current_hour %= HOURS_PER_DAY;

            printf("Текущее время: День %d, %02d:00\n",
                current_day, current_hour);
            break;

        case 3:
        case 4:
        case 5:
        case 6:
            printf("Этот пункт пока не реализован.\n");
            break;

        default:
            printf("Неверный пункт меню.\n");
            break;
        }
    }
}