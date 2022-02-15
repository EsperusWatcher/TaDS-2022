#include "../include/structure.h"
#include "../include/matrix.h"
#include "../include/print.h"
#include "../include/list.h"
#include "../include/multiplication.h"
#include "../include/efficiency.h"

#if DEBUG == TRUE
#include "../include/test.h"
#endif

/*
Разреженная (содержащая много нулей) матрица хранится в форме 3-х объектов:
    - вектор А содержит значения ненулевых элементов
    - вектор JA содержит номера столбцов для элементов вектора А
    - связный список IA, в элементе Nk которого находится номер компонент
    в A и JA, с которых начинается описание строки Nk и матрицы A

    1. Смоделировать операцию умножения матрицы и вектора-столбца,
    хранящихся в этой форме, с получением результата в той же форме.
    2. Произвести операцию умножения, применяя стандартный алгоритм работы с матрицами
    3. Сравнить время выполнения операций и объем памяти при использовании этих 2-х
    алгоритмов при различном проценте заполнения матриц.

*/

int main()
{
    #if DEBUG == TRUE
    printf("DEBUG MODE ON\n");
    tests();
    #else
    char choice;

    std_matrix_t *matrix1;
    std_matrix_t *matrix2;

    matrix_t *s_matrix;

    vector_t *s_vector;
    vector_t *s_vector_res;

    while (choice != '4')
    {
        print_menu();
        if (scanf(" %c", &choice) == FALSE)
        {
            printf("Wrong input\n");
            return ERROR_INPUT;
        }

        switch(choice)
        {
            case '1':
                system("cls");
                printf("Creating sparse matrix...\n");
                create_s_matrix(&s_matrix);

                if (s_matrix->col < 50 && s_matrix->row < 50)
                {
                    print_s_matrix_normal_view(s_matrix);
                    print_s_matrix(s_matrix);
                }

                printf("Creating sparse vector...\n");
                create_s_vector(&s_vector);

                auto_create_s_vector(&s_vector_res, s_matrix->col);

                if (s_vector->row < 50)
                {
                    print_s_vector_std_view(s_vector);
                    print_s_vector(s_vector);
                }

                printf("Multiplication...\n");
                matrix_multiplication_s(s_matrix, s_vector, &s_vector_res);

                print_s_vector(s_vector_res);

                free_s_matrix(&s_matrix);
                free_s_vector(&s_vector);
                free_s_vector(&s_vector_res);
                system("pause");
                break;
            case '2':
                system("cls");

                printf("Creating standart matrices...\n");
                create_std_matrix(&matrix1);

                if (matrix1->row < MAX_STD_SIZE && matrix1->col < MAX_STD_SIZE)
                {
                    print_matrix(matrix1);
                }

                create_std_matrix(&matrix2);

                if (matrix2->row < MAX_STD_SIZE && matrix2->col < MAX_STD_SIZE)
                {
                    print_matrix(matrix1);
                }

                matrix_multiplication_std(matrix1, matrix2);

                free_std_matrix(&matrix1);
                free_std_matrix(&matrix2);
                system("pause");
                break;
            case '3':
                system("cls");

                system("pause");
                break;
            case '4':
                break;
            default:
                printf("Not a valid command\n");
                return ERROR_INPUT;
        }
    }

    #endif
    return ERROR_NONE;
}