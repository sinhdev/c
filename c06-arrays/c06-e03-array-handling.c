#include <stdio.h>

int main()
{
	int a[100], count = 0, i;
	int position;

    int choice;
    do{
        printf("\n+----------------------------------------+\n");
        printf("|%-40s|\n", " MENU");
        printf("+----------------------------------------+\n");
        printf("|%-40s|\n", " 1. Them");
        printf("|%-40s|\n", " 2. Sua");
        printf("|%-40s|\n", " 3. Xoa");
        printf("|%-40s|\n", " 4. Chen phan tu vao mang");
        printf("|%-40s|\n", " 5. Tim kiem");
        printf("|%-40s|\n", " 6. Xap xep");
        printf("|%-40s|\n", " 7. Hien thi");
        printf("|%-40s|\n", " 8. Thoat");
        printf("+----------------------------------------+\n");
        printf("  Chon chuc nang (tu 1 den 7): ");
        
        //Xoa bo dem ban phim
        fseek(stdin, 0, SEEK_END);
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
            	printf("Them phan tu a[%d] = ", count);
            	scanf("%d", &a[count]);
            	count++;
                break;
            case 2:
            	printf("Nhap vao vi tri can sua: ");
            	scanf("%d", &position);
            	if(position < 0 || position >= count){
            		printf("Vi tri nay khong co trong mang.\n");
            	}else{
            		printf("a[%d] = ", position);
            		scanf("%d", &a[position]);
            	}
                break;
            case 3:
            	printf("Nhap vao vi tri can xoa: ");
            	scanf("%d", &position);
            	if(position < 0 || position >= count){
            		printf("Vi tri nay khong co trong mang.\n");
            	}else{
            		//xoa phan tu position khoi mang
            		for(i=position; i<count-1; i++){
            			a[i] = a[i+1];
            		}
            		count--;
            		printf("Da xoa phan tu o vi tri thu %d\n", position);
            	}
                break;
            case 4:
            	printf("Nhap vao vi tri can chen: ");
            	scanf("%d", &position);
            	if(position < 0 || position >= count){
            		printf("Vi tri nay khong co trong mang.\n");
            	}else{
            		//Chen phan tu
            		
            	}
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
            	printf("Hien thi mang:\n");
            	for(i=0; i<count; i++){
            		printf("%8d ", a[i]);
            	}
                break;
            case 8:
            	printf("Thoat khoi chuong trinh.\n");
            	break;
            default:
                printf("Chon sai, hay an phim enter de chon lai!\n");
                fseek(stdin, 0, SEEK_END);
                getchar();
                break;
        }
    }while(choice != 7);
    return 0;
}

