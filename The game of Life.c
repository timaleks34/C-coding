#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// задаём размеры сетки для игры
#define rows 15
#define cols 15
int generate_random(int max) {
    return rand() % max;
}
// генерируем сетку
void create_grid(int grid[rows][cols]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            grid[i][j] = generate_random(2);
        }
    }
}
// выводим сетку
void print_grid(int grid[rows][cols]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}
// начинаем игру
void game_of_life(int grid[rows][cols]) {
    int i, j, count, next_grid[rows][cols];

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            count = 0;
            // проверка наличия "соседей"
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue;
                    int nx = (i + x + rows) % rows;
                    int ny = (j + y + cols) % cols;

                    count += grid[nx][ny];
                }
            }
            if (grid[i][j] == 1) {
                if (count < 2 || count > 3) {
                    next_grid[i][j] = 0;
                } else {
                    next_grid[i][j] = 1;
                }
            } else {
                if (count == 3) {
                    next_grid[i][j] = 1;
                } else {
                    next_grid[i][j] = 0;
                }
            }
        }
    }
    // обновляем сетку следующей генерацией
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            grid[i][j] = next_grid[i][j];
        }
    }
}
int main() {
    int grid[rows][cols];
    int generation = 0;
    srand(time(NULL));
    create_grid(grid);
    printf("Generation %d\n", generation);
    print_grid(grid);
    while (1) {
        char choice;
        printf("Создать новую генерацию? (Y/N): ");
        scanf(" %c", &choice);
        if (choice == 'N') break;
        game_of_life(grid);
        printf("Generation %d\n", ++generation);
        print_grid(grid);
    }
    return 0;
}
