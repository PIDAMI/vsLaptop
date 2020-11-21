
#pragma warning (disable:4996)
#define _CRTDBG_MAP_ALLOC

#include <assert.h>
#include <crtdbg.h>
#include "AAL2.h"


//CUL: —амоподобные кривые, часть 2
//“ема : јбстрактные типы и структуры данных(ј“ƒ / —ƒ), массивы и св€зные списки
typedef struct node_t {
    point_t val;
    struct node_t* next;
} node_t;

typedef struct {
    int size;
    node_t* head;
} curve_t;

curve_t* CurveCreate(double ax, double ay, double bx, double by) {
    int size = 2;
    node_t* head = malloc(sizeof(node_t));
    node_t* tail = malloc(sizeof(node_t));
    curve_t* curve = malloc(sizeof(curve_t));

    if (head && curve && tail) {
        head->val.x = ax;
        head->val.y = ay;
        tail->val.x = bx;
        tail->val.y = by;
        head->next = tail;
        tail->next = NULL;

        curve->size = size;
        curve->head = head;
        return curve;
    }

    free(curve);
    free(head);
    free(tail);

    return NULL;
}

void CurveDestroy(curve_t* curve) {
    node_t* tmp = NULL;
    while (curve->head) {
        tmp = curve->head;
        curve->head = curve->head->next;
        free(tmp);
    }
    free(curve);
}

void CurveDraw(curve_t* curve) {
    node_t* actual;
    node_t* next;

    assert(curve);
    assert(curve->head);

    actual = curve->head;
    next = actual->next;
    do {
        LabDrawLine((int)actual->val.x, (int)actual->val.y, (int)next->val.x, (int)next->val.y);
        actual = actual->next;
        next = next->next;
    } while (next);
}

void CurveNext(curve_t* curve) {
    int direction = 1;

    node_t* actual;
    node_t* next;
    int size;

    assert(curve);
    assert(curve->head);

    // вычисл€ем новую длину кривой
    size = curve->size * 2 - 1;
  
    actual = curve->head;
    next = actual->next;

    // добавление узлов
    do {
        node_t* spike = malloc(sizeof(node_t));
        if (!spike) {
            return;
        }
        double dx, dy, cx, cy;

        // вычисл€ем координаты 
        dx = next->val.x - actual->val.x;
        dy = next->val.y - actual->val.y;
        cx = 0.5 * (actual->val.x + next->val.x + dy * direction);
        cy = 0.5 * (actual->val.y + next->val.y - dx * direction);

        // добавл€ем полученный узел "между" actual и next
        spike->val.x = cx;
        spike->val.y = cy;
        spike->next = next;
        actual->next = spike;


        // двигаемс€ к следующей паре узлов
        actual = next;
        next = next->next;

        direction = -direction;
    } while(next);

    // обновл€ем размер кривой
    curve->size = size;
}


void CurvePrev(curve_t* curve) {
    node_t* actual;
    node_t* next;
    int size;

    assert(curve);
    assert(curve->head);

    if (curve->size <= 2)
        return;

    assert(curve->size % 2 == 1);

    size = curve->size / 2 + 1;
    actual = curve->head;
    next = actual->next;

    while (next) {
        // обновл€ем указатель
        actual->next = next->next;
        // освобождаем ненужный узел
        free(next);
        // переходим к следующей паре узлов
        actual = actual->next;
        next = actual->next;
    }
    // обновл€ем размер кривой
    curve->size = size;
}

//
//int main(void) {
//    // включаем уведомлени€ об утечках пам€ти
//    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
//    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
//
//
//
//    if (LabInit()) {
//        curve_t* curve;
//        labkey_t key;
//        int width = LabGetWidth();
//        int height = LabGetHeight();
//
//        curve = CurveCreate(width / 4, height / 2, 3 * width / 4, 3 * height / 4);
//
//        // рисуем кривую дл€ n=1
//        LabClear();
//        CurveDraw(curve);
//        LabDrawFlush();
//
//        // мен€ем кол-во итераций
//        while ((key = LabInputKey()) != LABKEY_ESC) {
//            switch (key) {
//            case '+':
//                CurveNext(curve);
//                break;
//
//            case '-':
//                CurvePrev(curve);
//                break;
//
//            default:
//                continue;
//            }
//
//            LabClear();
//            CurveDraw(curve);
//            LabDrawFlush();
//        }
//
//        CurveDestroy(curve);
//    }
//
//    LabTerm();
//    return 0;
//}

