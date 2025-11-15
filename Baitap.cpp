#include <stdio.h>

#define MAX 100

int main() {
    int a[MAX];
    int n = 0;
    int chon;
    
    do {
        printf("+---Chuong trinh quan ly danh sach so nguyen---+\n");
        printf("|----------------------MENU---------------------|\n");
        printf("|1. Khai tao mang ban dau                       |\n");
        printf("|2. Hien thi danh sach phan tu                  |\n");
        printf("|3. Chen them 1 so vào vi tri nhap vao          |\n");
        printf("|4. Xoa theo vi tri                             |\n");
        printf("|5. Cap nhat gia tri theo vi tri                |\n");
        printf("|6. Thoat chuong trinh                          |\n");
        printf("+------------------------------------------------+\n");
        printf("->> Moi ban nhap chuc nang : ");
        scanf("%d", &chon);	

        switch(chon) {
        case 1: {
            printf("\n---------------------#1#------------------------\n");
            printf("Nhap so luong phan tu can khoi tao : ");
            scanf("%d", &n);

            for(int i = 0; i < n; i++) {
                printf("\n----------------Phan tu %d-----------------------\n", i+1);
                printf("Nhap gia tri phan tu : ");
                scanf("%d", &a[i]);
            }

            printf("\n<<--- Nhap thanh cong %d phan tu vao mang --->>\n", n);
            printf("---------------------###------------------------\n\n");
            break;
        }

        case 2: {
            printf("\n---------------------#2#------------------------\n");
            printf("\n-------DANH SACH CAC PHAN TU TRONG MANG---------\n");

            if(n == 0) {
                printf("[Mang rang]\n");
            } else {
                printf("[ ");
                for(int i = 0; i < n; i++) {
                    printf("%d ", a[i]);
                }
                printf("]\n");
            }

            printf("---------------------###------------------------\n\n");
            break;
        }

        case 3: {
            int pos, value;
            printf("\n---------------------#3#------------------------\n");
            printf("Nhap vi tri can them phan tu : ");
            scanf("%d", &pos);

            if(pos < 0 || pos > n) {
                printf("Vi tri khong hop li!\n\n");
                break;
            }

            printf("Nhap gia tri can them tai vi tri %d : ", pos);
            scanf("%d", &value);

            for(int i = n; i > pos; i--) {
                a[i] = a[i - 1];
            }
            a[pos] = value;
            n++;

            printf("\n<<--Them thanh cong so %d vào vi tri index %d-->>\n", value, pos);
            printf("---------------------###------------------------\n\n");
            break;
        }

        case 4: {
            int pos;
            char confirm;

            printf("\n---------------------#4#------------------------\n");
            printf("Nhap vao vi tri can xoa phan tu : ");
            scanf("%d", &pos);

            if(pos < 0 || pos >= n) {
                printf("Vi tri khong hop li!\n\n");
                break;
            }

            printf("Ban co chac chan muon xoa phan tu nay khong(Y/N)?\n");
            scanf(" %c", &confirm);

            if(confirm == 'Y' || confirm == 'y') {
                for(int i = pos; i < n - 1; i++) {
                    a[i] = a[i + 1];
                }
                n--;
                printf("\n<<--Da xoa thanh cong phan tu tai vi tri %d!!-->>\n", pos);
            } else {
                printf("Da huy thao tac xoa.\n");
            }

            printf("---------------------###------------------------\n\n");
            break;
        }

        case 5: {
            int pos, newValue;
            printf("\n---------------------#5#------------------------\n");
            printf("Nhap vao vi tri phan tu con cap nhat : ");
            scanf("%d", &pos);

            if(pos < 0 || pos >= n) {
                printf("Vi tri khong hop li!\n\n");
                break;
            }

            printf("Nhap vao gia tri moi (gia tri cu(%d)): ", a[pos]);
            scanf("%d", &newValue);

            a[pos] = newValue;

            printf("\n<<Da cap nhat thanh cong phan tu tai vi tri %d>>\n", pos);
            printf("---------------------###------------------------\n\n");
            break;
        }

        case 6:
            printf("\nThoat chuong trinh...\n");
            break;

        default:
            printf("Chac nang khong hop li! Moi nhap lai.\n\n");
        }

    } while(chon != 6);

    return 0;
}

