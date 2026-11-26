#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int masv;
    char ten[50];
    float d1,d2,d3;
} SV;

typedef struct tagNode {
    struct tagNode* prev;
    struct tagNode* next;
    SV infor;
} Node;

typedef struct {
    int spt;
    Node* pHead;
    Node* pTail;
} LList;

/////////////////////////////
void initList(LList* L) {
    L->spt = 0;
    L->pHead = NULL;
    L->pTail = NULL;
}

/////////////////////////////
int emptyList(LList L) {
    return L.spt == 0;
}

/////////////////////////////
void nhap(SV* x) {
    printf("Nhap ma sv: ");
    scanf("%d", &x->masv);

    while(x->masv <= 0) {
        printf("Ma sv khong hop le, nhap lai: ");
        scanf("%d", &x->masv);
    }

    printf("Nhap ten sv: ");
    scanf(" %[^\n]", x->ten);

    printf("Nhap diem mon 1: ");
    scanf("%f", &x->d1);

    printf("Nhap diem mon 2: ");
    scanf("%f", &x->d2);

    printf("Nhap diem mon 3: ");
    scanf("%f", &x->d3);
}

/////////////////////////////
void in(SV x) {
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 3: %.2f\n",
    x.ten, x.masv, x.d1, x.d2, x.d3);
}

/////////////////////////////
void insert_Head(LList* L, SV x) {
    Node* pp = (Node*)malloc(sizeof(Node));

    pp->infor = x;
    pp->prev = NULL;
    pp->next = L->pHead;

    if(emptyList(*L)) {
        L->pTail = pp;
    }
    else {
        L->pHead->prev = pp;
    }

    L->pHead = pp;
    L->spt++;
}

/////////////////////////////
void insert_Tail(LList* L, SV x) {
    Node* pp = (Node*)malloc(sizeof(Node));

    pp->infor = x;
    pp->next = NULL;
    pp->prev = L->pTail;

    if(emptyList(*L)) {
        L->pHead = pp;
    }
    else {
        L->pTail->next = pp;
    }

    L->pTail = pp;
    L->spt++;
}

/////////////////////////////
void insert(LList* L, int ma, SV x) {
    Node* pp = L->pHead;

    while(pp != NULL && pp->infor.masv != ma) {
        pp = pp->next;
    }

    if(pp == NULL) {
        printf("Khong tim thay sv\n");
        return;
    }

    Node* q = (Node*)malloc(sizeof(Node));

    q->infor = x;
    q->prev = pp;
    q->next = pp->next;

    if(pp == L->pTail) {
        L->pTail = q;
    }
    else {
        pp->next->prev = q;
    }

    pp->next = q;
    L->spt++;

    printf("Them thanh cong\n");
}

/////////////////////////////
void XoaTheoTen(LList* L, char ten[]) {
    Node* pp = L->pHead;

    while(pp != NULL && strcmp(pp->infor.ten, ten) != 0) {
        pp = pp->next;
    }

    if(pp == NULL) {
        printf("Khong tim thay sv\n");
    }
    else {
        if(pp == L->pHead) {
            L->pHead = pp->next;
        }
        else {
            pp->prev->next = pp->next;
        }

        if(pp == L->pTail) {
            L->pTail = pp->prev;
        }
        else {
            pp->next->prev = pp->prev;
        }

        free(pp);
        L->spt--;

        printf("Xoa thanh cong\n");
    }
}

/////////////////////////////
void XoaTheoMa(LList* L, int ma) {
    Node* pp = L->pHead;

    while(pp != NULL && pp->infor.masv != ma) {
        pp = pp->next;
    }

    if(pp == NULL) {
        printf("Khong tim thay sv\n");
    }
    else {
        if(pp == L->pHead) {
            L->pHead = pp->next;
        }
        else {
            pp->prev->next = pp->next;
        }

        if(pp == L->pTail) {
            L->pTail = pp->prev;
        }
        else {
            pp->next->prev = pp->prev;
        }

        free(pp);
        L->spt--;

        printf("Xoa thanh cong\n");
    }
}

/////////////////////////////
void TimTheoMa(LList* L, int ma) {
    Node* pp = L->pHead;

    while(pp != NULL && pp->infor.masv != ma) {
        pp = pp->next;
    }

    if(pp == NULL) {
        printf("Khong tim thay sv\n");
    }
    else {
        in(pp->infor);
    }
}

/////////////////////////////
void TimTheoTen(LList* L, char ten[]) {
    Node* pp = L->pHead;

    while(pp != NULL && strcmp(pp->infor.ten, ten) != 0) {
        pp = pp->next;
    }

    if(pp == NULL) {
        printf("Khong tim thay sv\n");
    }
    else {
        in(pp->infor);
    }
}

/////////////////////////////
void SapXepList(LList* L) {
    Node* pp;
    Node* q;
    SV tg;

    for(pp = L->pHead; pp != NULL; pp = pp->next) {
        for(q = pp->next; q != NULL; q = q->next) {
            if(strcmp(pp->infor.ten, q->infor.ten) > 0) {
                tg = pp->infor;
                pp->infor = q->infor;
                q->infor = tg;
            }
        }
    }

    printf("\nDanh sach sinh vien da sap xep:\n");
    printf("Ten SV\tMa SV\tDiem 1\tDiem 2\tDiem 3\n");

    for(pp = L->pHead; pp != NULL; pp = pp->next) {
        printf("%s\t%d\t%.2f\t%.2f\t%.2f\n",
        pp->infor.ten,
        pp->infor.masv,
        pp->infor.d1,
        pp->infor.d2,
        pp->infor.d3);
    }
}

/////////////////////////////
void Duyet(LList L) {
    Node* pp = L.pHead;

    while(pp != NULL) {
        in(pp->infor);
        pp = pp->next;
    }
}

/////////////////////////////
void freeList(LList* L) {
    Node* pp = L->pHead;
    Node* q;

    while(pp != NULL) {
        q = pp->next;
        free(pp);
        pp = q;
    }

    L->pHead = NULL;
    L->pTail = NULL;
    L->spt = 0;
}

/////////////////////////////
int main() {
    int chon;
    int kt = 0;

    LList L;
    initList(&L);

    SV x;

    while(!kt) {
        printf("\nChuong trinh lam viec voi ds lk kep SV\n");
        printf("1.Them nut vao dau danh sach\n");
        printf("2.Them nut vao cuoi danh sach\n");
        printf("3.Them nut vao sau mot nut khac trong ds\n");
        printf("4.Xoa nut theo ten\n");
        printf("5.Xoa nut theo ma\n");
        printf("6.Tim kiem nut theo ma\n");
        printf("7.Tim kiem nut theo ten\n");
        printf("8.Sap xep ds theo ten\n");
        printf("9.Duyet DS\n");
        printf("10.Thoat\n");

        printf("Nhap lua chon: ");
        scanf("%d", &chon);

        switch(chon) {
            case 1: {
                nhap(&x);
                insert_Head(&L, x);
                printf("Them thanh cong\n");
                break;
            }

            case 2: {
                nhap(&x);
                insert_Tail(&L, x);
                printf("Them thanh cong\n");
                break;
            }

            case 3: {
                int msv;
                printf("Ban muon chen nut vao sau sv co msv bao nhieu: ");
                scanf("%d", &msv);
                nhap(&x);
                insert(&L, msv, x);
                break;
            }

            case 4: {
                char ten[50];
                printf("Nhap ten sv can xoa: ");
                scanf(" %[^\n]", ten);
                XoaTheoTen(&L, ten);
                break;
            }

            case 5: {
                int m;
                printf("Nhap ma sv can xoa: ");
                scanf("%d", &m);
                XoaTheoMa(&L, m);
                break;
            }

            case 6: {
                int m;
                printf("Nhap ma sv can tim: ");
                scanf("%d", &m);
                TimTheoMa(&L, m);
                break;
            }

            case 7: {
                char ten[50];
                printf("Nhap ten sv can tim: ");
                scanf(" %[^\n]", ten);
                TimTheoTen(&L, ten);
                break;
            }

            case 8: {
                SapXepList(&L);
                break;
            }

            case 9: {
                Duyet(L);
                break;
            }

            case 10: {
                printf("Bye bye\n");
                kt = 1;
                break;
            }

            default: {
                printf("Lua chon khong hop le\n");
                break;
            }
        }
    }

    freeList(&L);
    return 0;
}
