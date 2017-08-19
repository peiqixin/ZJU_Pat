#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct customer_node* ptr_customer;
struct customer_node
{
	int hour;
	int minute;
	int second;
	int proccess_time;
	ptr_customer next;
};
// 按照时间从小到大的顺序，将顾客插入顾客列表
void insert(ptr_customer customer_list, ptr_customer new_customer)
{
	ptr_customer prev = customer_list;
	ptr_customer ptr = prev->next;
	while(ptr){
		if(ptr->hour < new_customer->hour){
			prev = ptr;
			ptr = ptr->next;
		}else if(ptr->hour == new_customer->hour){
			if(ptr->minute < new_customer->minute){
				prev = ptr;
				ptr = ptr->next;
			}else if(ptr->minute == new_customer->minute){
				if(ptr->second < new_customer->second){
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
	}
	prev->next = new_customer;
	new_customer->next = ptr;
}
// 找到当前窗口中最早结束业务的窗口，返回其序号
int find_min_wait_window(ptr_customer window[], int window_num)
{
	int i, min_index = 0;
	for(i = 1; i < window_num; i++){
		if(window[min_index]->hour > window[i]->hour){
			min_index = i;
		}else if(window[min_index]->hour == window[i]->hour){
			if(window[min_index]->minute > window[i]->minute){
				min_index = i;
			}else if(window[min_index]->minute == window[i]->minute){
				if(window[min_index]->second > window[i]->second){
					min_index = i;
				}
			}
		}
	}
	return min_index;
}

// 计算顾客等待时间，并且更新窗口可办理业务时间
int calculate_second(ptr_customer _customer, ptr_customer _window)
{
	int total_second = 0;
	int flag = 0;
	// 如果顾客到达时间大于等于当前窗口可开始业务时间
	if(_customer->hour > _window->hour){
		flag = 1;
	}else if(_customer->hour == _window->hour){
		if(_customer->minute > _window->minute){
			flag = 1;
		}else if(_customer->minute == _window->minute){
			if(_customer->second >= _window->second){
				flag = 1;
			}
		}
	}
	if(flag){
		// 当前窗口的秒数可直接更新
		_window->second = _customer->second;
		// 如果顾客到达分钟数加上业务办理所需时间大于等于60
		_window->minute = _customer->minute + _customer->proccess_time;
		if(_window->minute >= 60){
			_window->hour = _window->hour + 1;
			_window->minute = _window->minute % 60;
		}
		return 0;
	}
	// 如果顾客到达时间小于当前窗口可开始业务时间，即必须等待
	if(_customer->hour == _window->hour && _customer->minute == _window->minute){
		total_second = _window->second - _customer->second;
	}else if(_customer->hour == _window->hour){
		int second = _customer->second;
		int minute = _customer->minute;
		total_second = 60 - second;
		minute++;
		total_second = total_second + (_window->minute - minute) * 60 + _window->second;
	}else{
		int second = _customer->second;
		int minute = _customer->minute;
		int hour = _customer->hour;
		total_second = 60 - second;
		minute++;
		total_second = total_second + (60 - minute) * 60 + _window->minute * 60 +_window->second;
		hour++;
		total_second = total_second + (_window->hour - hour) * 3600 + _window->minute * 60 +_window->second;
	}
	// 更新窗口的开始时间，办理业务时间为分钟数，只用更新分钟数和小时数就可以
	_window->minute = _window->minute + _customer->proccess_time;
	if(_window->minute >= 60){
		_window->hour = _window->hour + 1;
		_window->minute = _window->minute % 60;
	}
	return total_second;
}

int main(int argc, char const *argv[])
{
	int customer_num, window_num;
	scanf("%d %d", &customer_num, &window_num);
	ptr_customer customer_list = (ptr_customer)malloc(sizeof(struct customer_node));
	customer_list->next = NULL;
	int i;
	for(i = 0; i < customer_num; i++){
		ptr_customer new_customer = (ptr_customer)malloc(sizeof(struct customer_node));
		scanf("%d:%d:%d %d", &new_customer->hour, &new_customer->minute, &new_customer->second, &new_customer->proccess_time);
		if(new_customer->proccess_time > 60){
			new_customer->proccess_time = 60;
		}
		// 当到达时间大于等于17时，不进行插入
		if(new_customer->hour < 17 || (new_customer->hour ==  17 && new_customer->minute == 0 && new_customer->second == 0)){
			insert(customer_list, new_customer);
		}
	}
	ptr_customer window[window_num];
	for(i = 0; i < window_num; i++){
		ptr_customer window_customer = (ptr_customer)malloc(sizeof(struct customer_node));
		window_customer->hour = 8;
		window_customer->minute = 0;
		window_customer->second = 0;
		window[i] = window_customer;
	}
	int total_second = 0;
	int total_customer = 0;
	ptr_customer ptr = customer_list->next;
	while(ptr){
		int min_index = find_min_wait_window(window, window_num);
		total_second = total_second + calculate_second(ptr, window[min_index]);
		total_customer++;
		ptr = ptr->next;
	}
	if(total_customer == 0){
		printf("0.0\n");
	}else{
		printf("%0.1f\n", (float)total_second/60/total_customer);
	}
	return 0;
}