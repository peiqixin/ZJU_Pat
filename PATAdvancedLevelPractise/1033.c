#include <stdio.h>
#include <stdlib.h>
int tank_capacity;
int des_distance;
int distance_per_litre;
int gas_station_num;
typedef struct station_node* ptr_station_node;
struct station_node
{
	double price;
	int distance;
	ptr_station_node next;
};

void insert(ptr_station_node station_list, ptr_station_node new_station)
{
	ptr_station_node pre = station_list;
	ptr_station_node ptr = pre->next;
	while(ptr && new_station->distance > ptr->distance){
		pre = ptr;
		ptr = ptr->next;
	}
	pre->next = new_station;
	new_station->next = ptr;
}
/*
 策略，找到当前车站后面的价格比当前车站小的，找到了，则直接返回，否则返回在可行驶距离内价格最小的车站
 */
ptr_station_node find_min_price(ptr_station_node ptr, double min_price, int total_distance)
{
	if(ptr == NULL) return NULL;
	// 保存下一个比当前价格小的站，找到了，则直接返回
	ptr_station_node next_min_ptr = ptr;
	// 如果没有找到下一个汽油价格比当前价格小的，从后面找出最小的价格
	ptr_station_node min_ptr = next_min_ptr;
	double total_min_price = 65535;
	while(next_min_ptr &&((next_min_ptr->distance - total_distance) <= tank_capacity * distance_per_litre)){
		if(next_min_ptr->price <= min_price )
			return next_min_ptr;
		if(next_min_ptr->price < total_min_price){
			min_ptr = next_min_ptr;
			total_min_price = min_ptr->price;
		}
		next_min_ptr = next_min_ptr->next;
	}
	return min_ptr;
}

int main(int argc, char const *argv[])
{
	scanf("%d %d %d %d", &tank_capacity, &des_distance, &distance_per_litre, &gas_station_num);
	int i;
	ptr_station_node station_list = (ptr_station_node)malloc(sizeof(struct station_node));
	station_list->next = NULL;
	ptr_station_node new_station;
	for(i = 0; i < gas_station_num; i++){
		new_station = (ptr_station_node)malloc(sizeof(struct station_node));
		scanf("%lf %d", &new_station->price, &new_station->distance);
		if(new_station->distance < des_distance)
			insert(station_list, new_station);
	}
	double total_distance = 0;
	double total_price = 0;
	ptr_station_node pre = station_list->next;
	ptr_station_node ptr;
	double tank_fuel = 0;
	while(pre){
		// 如果没找到接下来价格最小的加油站
		// 1.没有加油站了
		// 2.马上就到达目的地了
		ptr = find_min_price(pre->next, pre->price, total_distance);
		if(ptr == NULL){
			if(total_distance + tank_capacity * distance_per_litre < des_distance){
				total_distance += tank_capacity * distance_per_litre;
				printf("The maximum travel distance = %.2f\n", (double)total_distance);
			} else{
				double need_fuel = (des_distance - total_distance) / distance_per_litre;
				if(need_fuel > tank_fuel)
					total_price += (need_fuel - tank_fuel) * pre->price;
				printf("%.2f\n", total_price);
			}
			break;
		}
		// 如果在行驶范围内有车站的价格比当前车站的价格低
		// 则只用把油加到刚好可以到达该车站即可
		if(ptr->price <= pre->price){
			double need_fuel = (ptr->distance - total_distance) / distance_per_litre;
			total_price += (need_fuel - tank_fuel)* pre->price;
			// 到达下一站时， 油箱油量必定为零
			tank_fuel = 0;
			// 更新距离
			total_distance = ptr->distance;
		}else{
			// 如果下一个价格最低的车站的价格大于或等于当前车站
			// 则把油箱加满
			if(des_distance >= (total_distance + distance_per_litre * tank_capacity)){
				total_price += (tank_capacity - tank_fuel)* pre->price;
				// 到达下一站时，油箱剩余
				tank_fuel = tank_capacity - (ptr->distance - total_distance) / distance_per_litre;
				// 更新距离
				total_distance = ptr->distance;
			}else{
				double need_fuel = (des_distance - total_distance) / distance_per_litre - tank_fuel;
				tank_fuel =  (des_distance - ptr->distance) / distance_per_litre;
				total_price += need_fuel * pre->price;
				// 更新距离
				total_distance = ptr->distance;
			}
		}
		pre = ptr;
	}
	return 0;
}

/*
50 1300 12 8
7.20 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.10 1000
6.85 300
*/