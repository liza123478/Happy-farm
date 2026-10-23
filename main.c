#define _CRT_SECURE_NO_WARNINGS //полезная штука для визуалки
#include <stdio.h>
#include <windows.h>

//глобальные константы
#define HOURS_PER_DAY 24
#define INVENTORY_SIZE 10
#define ITEMS_COUNT 10

//даем каждому предмету свой уникальныый id
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
    int symbol;

    //создаем и заполняем инвентарь начальными предметами
    int inventory[INVENTORY_SIZE] = {
        ITEM_WOOD, ITEM_STONE, ITEM_EMPTY,
        ITEM_WATER, ITEM_CARROT, ITEM_HOE,
        ITEM_SEEDS, ITEM_EMPTY, ITEM_ROD, ITEM_ROPE
    };
	//основной цикл программы
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

		//проверка ввода на корректность
        if (scanf("%d", &choice) != 1)
        {
            while ((symbol = getchar()) != '\n' && symbol != EOF)
            {
            }

            printf("Ошибка! Введите число.\n");
            continue;
        }

        //очистка неправильного ввода
        while ((symbol = getchar()) != '\n' && symbol != EOF)
        {
        }


        switch (choice)
        {
        case 0:
            printf("Выход из программы.\n");
            return 0;

        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            break;

        default:
            printf("Неверный пункт меню.\n");
            break;
        }
    }
}