#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OFFLINE 0
#define ONLINE 1
int toll[24];
typedef char name[21];
typedef char state_name[10];
typedef struct phone_bill_node* ptrto_bill_node;
typedef ptrto_bill_node phone_bill;
struct phone_bill_node
{
	name _name;
	int month;
	int day;
	int hour;
	int minute;
	int state;
	ptrto_bill_node next;
};

ptrto_bill_node create_new_phone_bill()
{
	ptrto_bill_node new_bill = (ptrto_bill_node)malloc(sizeof(struct phone_bill_node));
	state_name s;
	scanf("%s %d:%d:%d:%d %s", new_bill->_name, &new_bill->month, &new_bill->day, &new_bill->hour, &new_bill->minute, s);
	if(s[1] == 'n')
		new_bill->state = 1;
	else
		new_bill->state = 0;
	new_bill->next = NULL;
	return new_bill;
}

void insert(phone_bill phone_bill_list, phone_bill new_phone_bill)
{
	ptrto_bill_node prev = phone_bill_list;
	ptrto_bill_node ptr = prev->next;
	if(ptr == NULL){
		phone_bill_list->next = new_phone_bill;
	}else{
		while(ptr){
			if(strcmp(new_phone_bill->_name, ptr->_name) > 0){
				prev = ptr;
				ptr = ptr->next;
			}else if(strcmp(new_phone_bill->_name, ptr->_name) == 0){
				if(new_phone_bill->day > ptr->day){
					prev = ptr;
					ptr = ptr->next;
				}else if(new_phone_bill->day == ptr->day){
					if(new_phone_bill->hour > ptr->hour){
						prev = ptr;
						ptr = ptr->next;
					}else if(new_phone_bill->hour == ptr->hour){
						if(new_phone_bill->minute > ptr->minute){
							prev = ptr;
							ptr = ptr->next;
						}else if(new_phone_bill->minute == ptr->minute){
							if(new_phone_bill->state == OFFLINE){
								prev = ptr;
								ptr = ptr->next;
							}else{
								break;
							}
						}else{
							break;
						}
					}else{
						break;
					}
				}else{
					break;
				}
			}else{
				break;
			}
		}
		prev->next = new_phone_bill;
		new_phone_bill->next = ptr;
	}
}

void print_phone_bill(phone_bill phone_bill_list)
{
	phone_bill ptr = phone_bill_list->next;
	while(ptr){
		printf("name = %s %02d:%02d:%02d:%02d %s\n", ptr->_name, ptr->month, ptr->day, ptr->hour, ptr->minute, ptr->state ? "ONLINE" : "OFFLINE");
		ptr = ptr->next;
	}
}

int calculate_toll(ptrto_bill_node pre, ptrto_bill_node ptr, int *tm)
{
	int total_toll = 0;
	if(pre->day == ptr->day && pre->hour == ptr->hour){
		total_toll = total_toll + (ptr->minute - pre->minute) * toll[ptr->hour];
		*tm = ptr->minute - pre->minute;
	}else if(pre->day == ptr->day){
		int hour = pre->hour;
		int minute = pre->minute;
		total_toll = (60 - minute) * toll[hour];
		*tm = 60 - minute;
		for(hour++; hour < ptr->hour; hour++){
			*tm = *tm + 60;
			total_toll = total_toll + 60 * toll[hour];
		}
		total_toll = total_toll + ptr->minute * toll[ptr->hour];
		*tm = *tm + ptr->minute;
	}else{
		int day, hour, minute;
		day = pre->day;
		hour = pre->hour;
		minute = pre->minute;
		// 算出prev 当天所需要的费用
		total_toll = (60 - minute) * toll[hour];
		*tm = 60 - minute;
		for(hour++; hour < 24; hour++){
			*tm = *tm + 60;
			total_toll = total_toll + 60* toll[hour];
		}
		// 算出中间天数的费用
		day = day + 1;
		if(day < ptr->day){
			int day_fee = 0;
			int i = 0;
			for(i = 0; i < 24; i++)
				day_fee += toll[i]*60;
			for(; day < ptr->day; day++){
				total_toll += day_fee;
				*tm = *tm + 24 * 60;
			}
		}
		// 算出最后一天的费用
		for(hour = 0; hour < ptr->hour; hour++){
			total_toll = total_toll + toll[hour] * 60;
			*tm = *tm + 60;
		}
		total_toll = total_toll + toll[ptr->hour] * ptr->minute;
		*tm = *tm + ptr->minute;
	}
	return total_toll;
}
int main(int argc, char const *argv[])
{
	int i;
	for(i = 0; i < 24; i++)
		scanf("%d", &toll[i]);
	int N;
	scanf("%d", &N);
	phone_bill bill_list;
	bill_list = (ptrto_bill_node)malloc(sizeof(struct phone_bill_node));
	bill_list->next = NULL;
	for(i = 0; i < N; i++){
		ptrto_bill_node new_node = create_new_phone_bill();
		insert(bill_list, new_node);
	}
	ptrto_bill_node prev;
	ptrto_bill_node ptr = bill_list->next;
	if(ptr == NULL || ptr->next == NULL)return 0;
	prev = ptr;
	ptr = ptr->next;
	while(ptr){
		float total_amount = 0;
		int print_name_flag = 1;
		int print_total_flag = 0;
		while(ptr && strcmp(ptr->_name, prev->_name) == 0){
			if(prev->state == ONLINE && ptr->state == OFFLINE){
				if(print_name_flag){
					printf("%s %02d\n", ptr->_name, ptr->month);
					print_name_flag = 0;
				}
				int total_minute = 0;
				int toll = calculate_toll(prev, ptr, &total_minute);
				total_amount += toll;
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%0.2f\n", prev->day, prev->hour, prev->minute, ptr->day, ptr->hour, ptr->minute, total_minute, (float)toll/100);
				print_total_flag = 1;
			}
			prev = ptr;
			ptr = ptr->next;
		}
		if(print_total_flag){
			printf("Total amount: $%0.2f\n", total_amount/100);
			print_total_flag = 0;
		}
		prev = ptr;
		if(ptr)
			ptr = ptr->next;
		else
			break;
	}
	return 0;
}