//
//  ifs_element.c
//  InfestPath
//
//  Created by Juyeop Kim on 2020/10/20.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ifct_element.h"

typedef enum place {
    Seoul,          //0
    Jeju,           //1
    Tokyo,          //2
    LosAngeles,     //3
    NewYork,        //4
    Texas,          //5
    Toronto,        //6
    Paris,          //7
    Nice,           //8
    Rome,           //9
    Milan,          //10
    London,         //11
    Manchester,     //12
    Basel,          //13
    Luzern,         //14
    Munich,         //15
    Frankfurt,      //16
    Berlin,         //17
    Barcelona,      //18
    Madrid,         //19
    Amsterdam,      //20
    Stockholm,      //21
    Oslo,           //22
    Hanoi,          //23
    Bangkok,        //24
    KualaLumpur,    //25
    Singapore,      //26
    Sydney,         //27
    SaoPaulo,       //28
    Cairo,          //29
    Beijing,        //30
    Nairobi,        //31
    Cancun,         //32
    BuenosAires,    //33
    Reykjavik,      //34
    Glasgow,        //35
    Warsow,         //36
    Istanbul,       //37
    Dubai,          //38
    CapeTown        //39
} place_t;

char countryName[N_PLACE+1][MAX_PLACENAME] =
{   "Seoul",
    "Jeju",
    "Tokyo",
    "LosAngeles",
    "NewYork",
    "Texas",
    "Toronto",
    "Paris",
    "Nice",
    "Rome",
    "Milan",
    "London",
    "Manchester",
    "Basel",
    "Luzern",
    "Munich",
    "Frankfurt",
    "Berlin",
    "Barcelona",
    "Madrid",
    "Amsterdam",
    "Stockholm",
    "Oslo",
    "Hanoi",
    "Bangkok",
    "KualaLumpur",
    "Singapore",
    "Sydney",
    "SaoPaulo",
    "Cairo",
    "Beijing",
    "Nairobi",
    "Cancun",
    "BuenosAires",
    "Reykjavik",
    "Glasgow",
    "Warsow",
    "Istanbul",
    "Dubai",
    "CapeTown",
    "Unrecognized"
};

typedef struct ifs_ele {
	int index;//number
	int age;//age
	int time;//time
	place_t place[N_HISTORY];//place[N_HISTORY]
} ifs_ele_t;



void* ifctele_genElement(int index, int age, unsigned int detected_time, int history_place[N_HISTORY])
{
	//이 함수는 main에서 파일로부터 읽어들인 index, age, time, placeHist를 매개변수로 받아 ifs_ele_t 타입으로 저장하는 함수이다
	ifs_ele_t* ptr;
	//구조체를 담을 ptr 포인터 변수를 만들고
	ptr = malloc();
	//일단 메모리에 구조체 크기만큼 할당하여주고
	ptr->index = index;
	ptr->age = age;
	ptr->time = detected_time;
	//ptr의 index, age, time에 매개변수로 받은 값들을 넣어준다

	for (int i=0;i<5;i++) {
		ptr->place[i]=history_palce[i];
		//place는 5개의 int값이 담긴 배열이므로 for문을 이용하여 넣어준다.

	}
		
	return ptr;
    //이렇게 만들어진 구조체를 가리키는 ptr 리턴해준다.

}

int ifctele_getAge(void* obj)
{
	ifs_ele_t* ptr = (ifs_ele_t*)obj;
	
	return ptr->age;
}

int ifctele_getHistPlaceIndex(void* obj, int index);
unsigned int ifctele_getinfestedTime(void* obj);


//char* ifctele_getPlaceName(int placeIndex);


void ifctele_printElement(void* obj)
{
	ifs_ele_t* ptr = (ifs_ele_t*)obj;
	
	printf("Age : %i\n", ptr->age);
}




char* ifctele_getPlaceName(int placeIndex)
{
	return countryName[placeIndex];
}
