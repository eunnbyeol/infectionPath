//
//  main.c
//  infestPath
//
//  Created by Juyeop Kim on 2022/10/20.
//

#include <stdio.h>
#include <string.h>
#include "ifct_element.h"
#include "ifct_database.h"

#define MENU_PATIENT        1
#define MENU_PLACE          2
#define MENU_AGE            3
#define MENU_TRACK          4
#define MENU_EXIT           0
#define TIME_HIDE           2


int trackInfester(int patient_no, int *detected_time, int *place);
int main(int argc, const char * argv[]) {
    
    int menu_selection;
    void *ifct_element;
    FILE* fp;
    int pIndex, age, time;
    int placeHist[N_HISTORY];
    
    //------------- 1. loading patient info file ------------------------------
    //1-1. FILE pointer open
    if (argc != 2)
    {
        printf("[ERROR] syntax : infestPath (file path)."); //argc�� �⺻������ �����ΰ� �ϳ� ���Ƿ� ȯ������ ���� ��ġ���� ������ 2�� �ȴ�. 
        return -1; //���� 2�� �ƴ� ��� �̻��Ѱ� �� ���ų� ȯ�� ������ ���� ���̹Ƿ� -1 return 
    }
    
    fp = fopen(argv[1],"r");
    if (fp == NULL)
    {
        printf("[ERROR] Failed to open database file!! (%s)\n", argv[1]);//argc[1]�� ȯ������ ������ �� �����Ƿ� read���� fopen�Ѱ� fp�� ��´� 
        return -1;//fp�� NULL�̸� fopen �����Ѱ��̹Ƿ� -1return 
    }
    
    // ���� �Ķ���͸� ���� ���� ��� �� �̸��� �޾ƿͼ� ������ ����

    
    //1-2. loading each patient informations
    while (3 == fscanf(fp, "%d %d %d", &Index, &age, &time))
    {
    	//fscanf�� ��������� 3���� ������ �о�鿩�� ������� pIndex, age, time�� �ִ´�.
        //fscanf�� ���� ������ ���� return�ϹǷ� 3���� ���������� �о������� �ڿ� �����ϴ� �뵵�� while�� ���
    	fscanf(fp, "%d %d %d %d %d", &placeHist[0], &placeHist[1], &placeHist[2], &placeHist[3], &placeHist[4]);
    	//ù 3�� �ڿ��� placeHist�̹Ƿ� �ټ����� �о placeHist�迭�ȿ� �־ ����Ѵ�.

    	//ifct_element = ifctele_genElement(pIndex, age, time, placeHist);
    	//������ ���Ϸκ��� �о���̰� ������ ���� �� ȯ���� �������� ȯ������ ����ü�� �����ϴ� �Լ��� ifctele_genElement�� ���ڷ� �ְ�
        //�׷��� ������ ȯ������ ����ü�� ifct_element�� ��´�.
    	//ifctdb_addTail(obj: ifct_element);
    	//������ ifct_element�� ����� ȯ�������� linked list ������ �����ϴ� add_Tail�Լ��� ���ڷ� �־� �����Ѵ�.

	}
	
	// �־��� linked list �ҽ� �ڵ带 Ȱ���Ͽ� ���� 
    //1-3. FILE pointer close
    fclose(fp); 
    
    {
    	int place1, place2;
    	
    	place1 = 3;
    	place2 = 15;
    	
    	printf("The first place is %s\n", ifctele_getPlaceName(place1));
    	printf("The second place is %s\n", ifctele_getPlaceName(place2));
	}
    
    do {
        printf("\n=============== INFECTION PATH MANAGEMENT PROGRAM (No. of patients : %i) =============\n", ifctdb_len());
        printf("1. Print details about a patient.\n");                      //MENU_PATIENT
        printf("2. Print list of patients infected at a place.\n");        //MENU_PLACE
        printf("3. Print list of patients in a range of age.\n");          //MENU_AGE
        printf("4. Track the root of the infection\n");                     //MENU_TRACK
        printf("0. Exit.\n");                                               //MENU_EXIT
        printf("=============== ------------------------------------------------------- =============\n\n");
        
        printf("Select a menu :");
        scanf("%d", &menu_selection);
        fflush(stdin);
        
        switch(menu_selection)
        {
            case MENU_EXIT:
                printf("Exiting the program... Bye bye.\n");
                break;
                
            case MENU_PATIENT:
                printf("ȯ�� ��ȣ�� �Է��ϼ��� ");
				scanf("%d", &pIndex);
				
				printf()
                
                break;
                
            case MENU_PLACE:
                printf("��Ҹ� �Է��ϼ��� :");
                scanf("%d", &place);
                break;
                
            case MENU_AGE:
                printf("ȯ�� ���̸� �Է��ϼ��� ");
				scanf("%d", &age);
				 
                break;
                
            case MENU_TRACK:
                    
                break;
                
            default:
                printf("[ERROR Wrong menu selection! (%i), please choose between 0 ~ 4\n", menu_selection);
                break;
        }
    
    } while(menu_selection != 0);
    
    
    return 0;
}
