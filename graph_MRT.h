#include<stdio.h>
#include<stdlib.h> 
typedef struct MRT_Node{
	int stop_num;
	char stop_color;
	int time;
	double distance;
	struct MRT_Node* linking;
	struct MRT_Node* inverse_linking;
}Node;

typedef struct MRT_Line{
	struct MRT_Node* head;	
}Line;

Node* New_Node(void);

Line* New_Line(void);


Node* New_Node(void){	//it declare a new data(cell) space in the memory
	Node *pt;
	pt = (Node*)malloc(sizeof(Node));
	if(pt==NULL){
		printf("Memory is not sufficient!!");
		exit(1);
	}
	return pt;
} 

Line* New_Line(void){
	Line* pt;
	pt = (Line*)malloc(sizeof(Line));
	if(pt==NULL){
		printf("Memory is not sufficient!!");
		exit(1);
	}
	return pt;	
}


