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

int readInt()
{
    int value;
    int symbol;

    while (scanf("%d", &value) != 1)
    {
        while ((symbol = getchar()) != '\n' && symbol != EOF)
        {
        }

        printf("Ошибка! Введите число: ");
    }

    while ((symbol = getchar()) != '\n' && symbol != EOF)
    {
    }

    return value;
}

// Вывод содержимого инвентаря
void showInventory(int inventory[], const char* item_names[])
{
    int i;

    for (i = 0; i < INVENTORY_SIZE; i++)
    {
        printf("Слот %d: %s\n",
            i, item_names[inventory[i]]);
    }
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int current_day = 1;
    int current_hour = 8;
    int choice, work_hours;
    int slot_index, item_id, i;

    int inventory[INVENTORY_SIZE] = {
        ITEM_EMPTY, ITEM_STONE, ITEM_WOOD,
        ITEM_WATER, ITEM_CARROT, ITEM_HOE,
        ITEM_SEEDS, ITEM_EMPTY, ITEM_ROD, ITEM_ROPE
    };

    const char* item_names[ITEMS_COUNT] = {
        "Пусто", "Дерево", "Камень", "Семена", "Вода",
        "Морковь", "Сено", "Верёвка", "Удочка", "Мотыга"
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
        printf("[6] Быстрый доступ\n");
        printf("Выберите пункт: ");

        choice = readInt();

        switch (choice)
        {
        case 0:
            system("cls");
            printf("Выход из программы.\n");
            return 0;

        case 1:
            system("cls");
            printf("Текущее время: День %d, %02d:00\n",
                current_day, current_hour);
            break;

        case 2:
            system("cls");
            printf("Сколько часов хотите поработать? ");
            work_hours = readInt();

            if (work_hours < 0)
            {
                printf("Количество часов не может быть отрицательным.\n");
                break;
            }
            if (work_hours > 16)
            {
                printf("Слишком много часов, вы столько не сможете поработать.\n");
                break;
            }

            current_hour += work_hours;
            current_day += current_hour / HOURS_PER_DAY;
            current_hour %= HOURS_PER_DAY;

            printf("Текущее время: День %d, %02d:00\n",
                current_day, current_hour);
            break;

        case 3:
            system("cls");
            printf("\n--- Инвентарь ---\n");
            showInventory(inventory, item_names);
            break;

        case 4:
            system("cls");
            printf("\n--- Текущий инвентарь ---\n");
            showInventory(inventory, item_names);

            printf("\n--- Доступные предметы ---\n");

            for (i = 0; i < ITEMS_COUNT; i++)
            {
                printf("ID %d: %s\n", i, item_names[i]);
            }

            printf("\nВведите номер слота: ");
            slot_index = readInt();

            if (slot_index < 0 || slot_index >= INVENTORY_SIZE)
            {
                printf("Неверный номер слота!\n");
                break;
            }

            printf("Введите ID предмета: ");
            item_id = readInt();

            if (item_id < 0 || item_id >= ITEMS_COUNT)
            {
                printf("Неверный ID предмета!\n");
                break;
            }

            inventory[slot_index] = item_id;

            printf("В слот %d помещен предмет (%s).\n",
                slot_index, item_names[item_id]);
            break;

        case 5:
            system("cls");
            printf("\n--- Текущий инвентарь ---\n");
            showInventory(inventory, item_names);

            printf("Введите номер слота: ");
            slot_index = readInt();

            if (slot_index < 0 || slot_index >= INVENTORY_SIZE)
            {
                printf("Неверный номер слота!\n");
                break;
            }

            printf("Выброшен предмет: %s\n",
                item_names[inventory[slot_index]]);

            inventory[slot_index] = ITEM_EMPTY;

            printf("Слот %d очищен.\n", slot_index);
            break;

        case 6:
        {
            system("cls");
            int temp;

            for (i = 0; i < ITEMS_COUNT; i++)
            {
                printf("ID %d: %s\n", i, item_names[i]);
            }
            printf("Введите ID предмета: ");
            item_id = readInt();

            if (item_id < 0 || item_id >= ITEMS_COUNT)
            {
                printf("Неверный ID предмета!\n");
                break;
            }

            printf("\n--- Инвентарь до перестановки ---\n");
            showInventory(inventory, item_names);

            slot_index = -1;

            for (i = 0; i < INVENTORY_SIZE; i++)
            {
                if (inventory[i] == item_id)
                {
                    slot_index = i;
                    break;
                }
            }

            if (slot_index == -1)
            {
                printf("Предмет \"%s\" не найден!\n",
                    item_names[item_id]);
            }
            else
            {
                temp = inventory[0];
                inventory[0] = inventory[slot_index];
                inventory[slot_index] = temp;

                printf("Предмет \"%s\" перемещен в нулевой слот.\n",
                    item_names[item_id]);
            }

            printf("\n--- Инвентарь после перестановки ---\n");
            showInventory(inventory, item_names);
            break;
        }

        default:
            printf("Неверный пункт меню.\n");
            break;
        }
    }
}