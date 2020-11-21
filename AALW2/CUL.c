
#pragma warning (disable:4996)
#define _CRTDBG_MAP_ALLOC

#include <assert.h>
#include <crtdbg.h>
#include "AAL2.h"


//CUL: ������������ ������, ����� 2
//���� : ����������� ���� � ��������� ������(��� / ��), ������� � ������� ������
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

    // ��������� ����� ����� ������
    size = curve->size * 2 - 1;
  
    actual = curve->head;
    next = actual->next;

    // ���������� �����
    do {
        node_t* spike = malloc(sizeof(node_t));
        if (!spike) {
            return;
        }
        double dx, dy, cx, cy;

        // ��������� ���������� 
        dx = next->val.x - actual->val.x;
        dy = next->val.y - actual->val.y;
        cx = 0.5 * (actual->val.x + next->val.x + dy * direction);
        cy = 0.5 * (actual->val.y + next->val.y - dx * direction);

        // ��������� ���������� ���� "�����" actual � next
        spike->val.x = cx;
        spike->val.y = cy;
        spike->next = next;
        actual->next = spike;


        // ��������� � ��������� ���� �����
        actual = next;
        next = next->next;

        direction = -direction;
    } while(next);

    // ��������� ������ ������
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
        // ��������� ���������
        actual->next = next->next;
        // ����������� �������� ����
        free(next);
        // ��������� � ��������� ���� �����
        actual = actual->next;
        next = actual->next;
    }
    // ��������� ������ ������
    curve->size = size;
}

//
//int main(void) {
//    // �������� ����������� �� ������� ������
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
//        // ������ ������ ��� n=1
//        LabClear();
//        CurveDraw(curve);
//        LabDrawFlush();
//
//        // ������ ���-�� ��������
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

