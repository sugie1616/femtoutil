#include<stdio.h>
#include<stdlib.h>
#include<readline/readline.h>
#include<readline/history.h>
#include<string.h>
#include"lispo.h"

int decode(int n)
{
	int x;
	x = n - '0';
	return x;
}

ans_stack* ans_alloc(ans_stack* ans_head)
{
	ans_stack* temp;
	
	if(ans_counter < 300){
		ans_list[ans_counter].next = ans_head;
		ans_head = &ans_list[ans_counter];
		ans_counter++;
	}
	else{
		temp = ans_free_head->next;
		ans_free_head->next = ans_head;
		ans_head = ans_free_head;
		ans_free_head = temp;
	}
	return ans_head;
}

ans_stack* ans_free(ans_stack* ans_head)
{
	ans_stack* temp;
	ans_head->ans = 0;
	temp = ans_head->next;
	ans_head->next = ans_free_head;
	ans_free_head = ans_head;
	ans_head = temp;
	return ans_head;
}

arg_list* arg_alloc(arg_list* arg_head)
{
	arg_list* temp;
	
	if(arg_counter < 300){
		arg_pool[arg_counter].next = arg_head;
		arg_head = &arg_pool[arg_counter];
		arg_counter++;
	}
	else{
		temp = arg_free_head->next;
		arg_free_head->next = arg_head;
		arg_head = arg_free_head;
		arg_free_head = temp;
	}
	return arg_head;
}

arg_list* arg_free(arg_list* arg_head)
{
	arg_list* temp;
	arg_head-> arg = 0;
	temp = arg_head->next;
	arg_head->next = arg_free_head;
	arg_free_head = arg_head;
	arg_head = temp;
	return arg_head;
}

void print(int x)
{
	if(char_flag == 1){
		if(x == 'F')
			printf("NIL\n");
		else
			printf("%c\n",x);
		char_flag = 0;
	}
	else if(setq_flag == 1){
		printf("%s: %d\n", name_temp, x);
		setq_flag = 0;
	}
	else if(defun_flag == 1){
		printf("defun %s\n", name_temp);
		defun_flag = 0;
	}
	else
		printf("%d\n", x); 
	return;
}
