//
// ifct_element.h
// infection path

#ifndef ifct_element_h
#define ifct_element_h

#define N_PLACE
#define N_HISTORY
#define MAX_PLACENAME

void* ifctele_genElement(int index, int age, unsigned int detected_time, int history_place[N_HISTORY]);
char* ifctele_getPlaceName(int placeIndex);
int ifctele_getHisplaceIndex(void* obj, int index);
unsigned int ifctele-getinfestedTime(void* obj);
int ifctele_getAge(void* obj);
void ifctele_printElement(void* obj);
#endif /*ifct_element_h*/
