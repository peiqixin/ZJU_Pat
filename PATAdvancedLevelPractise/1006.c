#include <stdio.h>
#include <stdlib.h>
typedef struct person_node* person;
struct person_node{
	char *id;
	int in_hour, in_minute, in_second;
	int leave_hour, leave_minute, leave_second;
};

/*
1
CS301111 15:30:28 17:12:10
*/
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int i;
	person p[N];
	for(i = 0; i < N; i++){
		p[i] = (person)malloc(sizeof(struct person_node));
		p[i]->id = (char *)malloc(sizeof(char) * 10);
		scanf("%s", p[i]->id);
		scanf("%d:%d:%d", &(p[i]->in_hour), &(p[i]->in_minute), &(p[i]->in_second));
		scanf("%d:%d:%d", &(p[i]->leave_hour), &(p[i]->leave_minute), &(p[i]->leave_second));
	}
	int in_person, leave_person;
	in_person = 0;
	leave_person = 0;
	for(i = 1; i < N; i++){
		if(p[i]->in_hour < p[in_person]->in_hour){
			in_person = i;
		}else if(p[i]->in_hour == p[in_person]->in_hour){
			if(p[i]->in_minute < p[in_person]->in_minute){
				in_person = i;
			}else if(p[i]->in_minute == p[in_person]->in_minute){
				if(p[i]->in_second < p[in_person]->in_second){
					in_person = i;
				}
			}
		}

		if(p[i]->leave_hour > p[leave_person]->leave_hour){
			leave_person = i;
		}else if(p[i]->leave_hour == p[leave_person]->leave_hour){
			if(p[i]->leave_minute > p[leave_person]->leave_minute){
				leave_person = i;
			}else if(p[i]->leave_minute == p[leave_person]->leave_minute){
				if(p[i]->leave_second > p[leave_person]->leave_second){
					leave_person = i;
				}
			}
		}
	}
	printf("%s %s\n", p[in_person]->id, p[leave_person]->id);
	return 0;
}