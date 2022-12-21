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
        printf("[ERROR] syntax : infestPath (file path)."); //argc는 기본적으로 실행경로가 하나 들어가므로 환자정보 파일 위치만을 넣으면 2가 된다. 
        return -1; //따라서 2가 아닐 경우 이상한게 더 들어갔거나 환자 정보가 없는 것이므로 -1 return 
    }
    
    fp = fopen(argv[1],"r");
    if (fp == NULL)
    {
        printf("[ERROR] Failed to open database file!! (%s)\n", argv[1]);//argc[1]에 환자정보 파일이 들어가 있으므로 read모드로 fopen한걸 fp에 담는다 
        return -1;//fp가 NULL이면 fopen 실패한것이므로 -1return 
    }
    
    // 실행 파라미터를 통해 파일 경로 및 이름을 받아와서 파일을 읽음

    
    //1-2. loading each patient informations
    while (3 == fscanf(fp, "%d %d %d", &Index, &age, &time))
    {
    	//fscanf로 공백단위로 3개의 정수를 읽어들여서 순서대로 pIndex, age, time에 넣는다.
        //fscanf는 읽은 데이터 수를 return하므로 3개를 정상적으로 읽었을때만 뒤에 실행하는 용도로 while문 사용
    	fscanf(fp, "%d %d %d %d %d", &placeHist[0], &placeHist[1], &placeHist[2], &placeHist[3], &placeHist[4]);
    	//첫 3개 뒤에는 placeHist이므로 다섯개를 읽어서 placeHist배열안에 넣어서 기록한다.

    	//ifct_element = ifctele_genElement(pIndex, age, time, placeHist);
    	//위에서 파일로부터 읽어들이고 변수에 넣은 한 환자의 정보들을 환자정보 구조체를 생성하는 함수인 ifctele_genElement에 인자로 넣고
        //그렇게 생성된 환자정보 구조체를 ifct_element에 담는다.
    	//ifctdb_addTail(obj: ifct_element);
    	//위에서 ifct_element에 저장된 환자정보를 linked list 꼬리에 저장하는 add_Tail함수에 인자로 넣어 저장한다.

	}
	
	// 주어진 linked list 소스 코드를 활용하여 저장 
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
                printf("환자 번호를 입력하세요 ");
				scanf("%d", &pIndex);
				
				printf()
                
                break;
                
            case MENU_PLACE:
                printf("장소를 입력하세요 :");
                scanf("%d", &place);
                break;
                
            case MENU_AGE:
                printf("환자 나이를 입력하세요 ");
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
