#pragma warning(disable:4996)
#include "AAL2.h"

//UNI: Объединение
//Дан бинарный файл(uni_shapes.bin), в котором сохранены вперемешку различные
//геометрические фигуры.Необходимо прочитать файл и посчитать некоторые
//значения, вывести их на экран


// программа не работает, видимо
// структура неправильно написана.
// альтернативный способ написать
// не могу придумать, по заданию кажется
// что такая реализация должна подойти
typedef enum {
	CIRCLE,
    RECTANGLE,
    POLYGON
} figtyp_t;

typedef enum {
    RED,
    GREEN,
    BLUE
} figcolor_t;

typedef struct {
    float width;
    float height;
} rectan_t;

typedef struct {
    int dimension;
    float length;
} polygon_t;

typedef union {
    float radius;
    polygon_t polygon;
    rectan_t rectangle;
} figsize_t;

typedef struct {
    figtyp_t type;
    figcolor_t color;
    figsize_t size;
} figure;



figure* ReadBin(char const* filename, int* length) {
    int size;
    figure* arr;
    int count;
    FILE* f;
    if ((f = fopen("uni_shapes.bin", "r")) == NULL) {
        perror("file not found; ");
        return NULL;
    }

    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fseek(f, 0, SEEK_SET);
    arr = malloc(size);
    if (!arr) {
        perror("not enough memory;");
        return NULL;
    }
    if (size % sizeof(figure) != 0) { 
        printf("wrong struct size\n");
        return NULL;
    }
    *length = size / sizeof(figure);
    

    if ((count = fread(arr, sizeof(figure), *length, f)) != *length) {
        printf("incorrect number of elements read;\n");
    }

    return arr;
}
//
//int main() {
//    int length;
//    int i;
//    figure* arr;
//    int circleCount, rectangleCount, polygonCount;
//    int redCount, greenCount, blueCount;
//    float sum;
//    const float pi = 3.14;
//    arr = ReadBin("uni_shapes.bin", &length);
//    if (arr == NULL) {
//        printf("error while reading");
//        return 1;
//    }
//    printf("size of array: %d\n", length);
//
//    circleCount = rectangleCount = polygonCount = 0;
//    for (i = 0; i < length; i++) {
//        if (arr[i].type == CIRCLE) {
//            circleCount++;
//        }
//        else if (arr[i].type == RECTANGLE) {
//            rectangleCount++;
//        }
//        else if (arr[i].type == POLYGON) {
//            polygonCount++;
//        }
//    }
//
//    printf("circles: %d\nrectangles: %d\npolygons: %d\n",
//           circleCount, rectangleCount, polygonCount);
//
//    redCount = greenCount = blueCount = 0;
//    for (i = 0; i < length; i++) {
//        if (arr[i].color == RED) {
//            redCount++;
//        }
//        else if (arr[i].color == GREEN) {
//            greenCount++;
//        }
//        else if (arr[i].color == BLUE) {
//            blueCount++;
//        }
//    }
//    printf("red figures: %d\ngreen figures: %d\nblue figures: %d\n",
//            redCount, greenCount, blueCount);
//    sum = 0;
//    for (i = 0; i < length; i++) {
//        if (arr[i].type == CIRCLE) {
//            sum+= pi * arr[i].size.radius * arr[i].size.radius;
//        }
//        else if (arr[i].type == RECTANGLE) {
//            sum += arr[i].size.rectangle.height * arr[i].size.rectangle.width;
//        }
//        else if (arr[i].type == POLYGON) {
//            sum += arr[i].size.polygon.length * arr[i].size.polygon.dimension
//                * arr[i].size.polygon.length / (4 * (float)tan(pi / arr[i].size.polygon.dimension));
//        }
//    }
//    printf("total area: %.2f", sum);
//    return 0;
//}