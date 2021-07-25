#include<stdio.h>
#include<stdlib.h> 
#include"MRT_Name.h"
#include"graph_MRT.h"
Node* Node_head[8],*temp;
Line* line_head[8],*line_temp;
void MRT_Graph(void);
Node* Look_for_Begin(char,int);
void MRT_Path(Node*,Node*);
void Path_SameColor(Node*,Node*);
void Path_diff_Color(Node*,Node*);

double total_cost=0;
int total_time=0;
double total_distance=0;
double price(double);
void Time(int);

int main(){
	
	Node *Begin_Stop,*Destination_Stop;
	Node *List_Begin,*tmp;
	Node *List_End;
	
	Begin_Stop=New_Node();
	Destination_Stop=New_Node();
	Begin_Stop->linking=NULL;
	Begin_Stop->inverse_linking=NULL;
	Destination_Stop->linking=NULL;
	Destination_Stop->inverse_linking=NULL;
	
	
	printf("MRT Map:\n");
	printf("Blue_Line :1.Dingpu 2.Yongning 3.Tucheng 4.Haishan 5.Far Eastern Hospital 6.Fuzhong 7.Banqiao 8.Xinpu 9.Jiangzicui"); 
	printf("10.Longshan Temple 11.Ximen 12.Taipei Main Station 13.Shandao Temple 14.Zhonhxiao Xinsheng 15.Zhonhxiao Fuxing 16.Zhonhxiao Dunhua"); 
	printf("17.Sun Yat-sen Memorial Hall 18.Taipei City Hall 19.Yongchun 20.Houshanpi 21.Kunyang 22.Nangang 23.Taipei Nangang Exhibition Center\n");
	printf("\n");
	printf("Red_Line :1.Tamsui 2.Hongshulin 3.Zhuwei 4.Guandu 5.Zhongyi 6.Fuxinggang 7.Beitou 8.Qiyan 9.Qilian");
	printf("10.Shipai 11.Mingde 12.Zhishan 13.Shilin 14.Jiantan 15.Yuanshan 16.Minquan W.Rd. 17.Shuanglian 18.Zhonhshan");
	printf("19.Taipei Main Station 20. NTU Hospital 21.Chiang Kai-Shek Memorial Hall 22.Dongmen 23.Dann Park 24.Daan 25.Xinyi Anhe 26.Taipei 101/World Trade Center 27.Xiangshan\n");
	printf("\n");
	printf("Green_Line : 1.Songshan 2.Nanjing Sanmin 3.Taipei Arena 4.Nanjing Fuxing 5.Songjiang Nanjing 6.Zohongshan 7.Beimen 8. Ximen  9.Xiaonamen");
	printf(" 10.Chiang Kai-Shek Memorial Hall 11.Guting 12.Taipower Building 13.Gongguan 14.Wanlong 15.Jingmei 16.Dapinglin 17.Qizhang");
	printf("18.Xindan District Office 19.Xindian 20.Xiaobitan \n");
	printf("\n");
	printf("Wenhu_Line :1.Taipei Zoo 2.Muzha 3.Wanfang Community 4.Wanfang Hospital 5.Xinhai 6.Linguang 7.Liuzhangli 8.Technology Builiding 9.Daan");
	printf("10.Zhongxiao Fuxing 11.Nanjing Fuxing 12.Zhongshan Junior High School 13.Shongshan Airport 14.Dazhi 15.Jiannan Rd. 16.Xihu 17.Gangqian");
	printf("18.Wende 19.Neihu 20.Dahu Park 21.Huzhou 22.Donghu 23.Nangang Software Park 24.Taipei Nangang Exhibition Center \n"); 
	printf("\n");
	printf("Yellow_Line :1.Nanshijiao 2.Jingan 3.Yongan Market4.Dingxi 5. Guting 6. Dongmen 7.Zhonhxiao Xinsheng 8.Songjiang Nanjing 9.Xingtian Temple");
	printf("10.Zhonhshan Elementary School 11.Minquan W.Rd. 12.Daquaotou 13.Sanchong Elementary School 14.Sanhe Junior High School 15. St. Ignatius High School 16.Sanmin Senior High School 17.Luzhou");
	printf("18.Taipei Bridge 19.Cailiao 20.Sanchong 21.Xianse Temple 22.Touqianzhung 22.Xinzhuang 24.Fu Jen University 25.Danfeng 26Huilong\n\n"); 
	MRT_Graph();
	
	//User input
	printf("Please input which is your beginning stop:\n");
	printf("Which line( Color :Wenhu Line-> 'w',Red_Line->'r',Blue_Line->'b',Green_Line->'g',Yellow_Line->'y'):") ;
	fflush(stdin);
	scanf("%c",&Begin_Stop->stop_color);
	printf("Which stop? (Input stop number)");
	scanf("%d",&Begin_Stop->stop_num);
	printf("\nPlease input which is your terminal stop:\n");
	printf("Which line( Color :Wenhu Line-> 'w',Red_Line->'r',Blue_Line->'b',Green_Line->'g',Yellow_Line->'y'):") ;
	fflush(stdin);
	scanf("%c",&Destination_Stop->stop_color);
	printf("Which stop? (Input stop number)");
	scanf("%d",&Destination_Stop->stop_num);
	
	//let *List_Begin 
	List_Begin=Look_for_Begin(Begin_Stop->stop_color,Begin_Stop->stop_num);
	printf("\nBeginning stop:color %c /t stop number %d",List_Begin->stop_color,List_Begin->stop_num );
	printf("\t Stop name:");
	MRT_Name(List_Begin->stop_color,List_Begin->stop_num);
	List_End=Look_for_Begin(Destination_Stop->stop_color,Destination_Stop->stop_num);
	printf("\nTerminal stop:color %c /t stop number %d",List_End->stop_color,List_End->stop_num );
	printf("\t Stopname:");
	MRT_Name(List_End->stop_color,List_End->stop_num);
	printf("\n");
	//Transfer info
	MRT_Path(List_Begin,List_End);	
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MRT_Graph(void){
	int i,k;
	for(i=0;i<8;i++) {
		Node_head[i]=New_Node();
	}
	//Blue_Line
	temp=Node_head[0];
	for(i=1;i<=23;i++){
		switch(i){
			case 1://���H 
				temp->stop_num=1;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.95;
				temp->time=180;
				temp->inverse_linking=NULL;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 2://�ù� 
				temp->stop_num=2;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.13;
				temp->time=95;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 3://�g�� 
				temp->stop_num=3;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.64;
				temp->time=106;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 4://���s 
				temp->stop_num=4;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=0.91;
				temp->time=142;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 5://�ȪF��| 
				temp->stop_num=5;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.31;
				temp->time=92;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 6://���� 
				temp->stop_num=6;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=0.65;
				temp->time=89;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 7://�O�� 
				temp->stop_num=7;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.28;
				temp->time=102;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 8://�s�H 
				temp->stop_num=8;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.28;
				temp->time=74;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 9://���l�A 
				temp->stop_num=9;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=3.08;
				temp->time=190;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 10://�s�s�x 
				temp->stop_num=10;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.27;
				temp->time=103;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 11://��� 
				temp->stop_num=11;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.43;
				temp->time=132;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 12://�x�_���� 
				temp->stop_num=12;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=0.89;
				temp->time=132;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 13://���ɦx 
				temp->stop_num=13;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=0.94;
				temp->time=64;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case (14)://�����s�� 
				temp->stop_num=14;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.13;
				temp->time=76;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 15://�����_�� 
				temp->stop_num=15;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=0.67;
				temp->time=63;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 16://�������� 
				temp->stop_num=16;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=0.72;
				temp->time=67;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 17://��������] 
				temp->stop_num=17;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=0.85;
				temp->time=72;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 18://���F�� 
				temp->stop_num=18;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.13;
				temp->time=82;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 19://�ìK 
				temp->stop_num=19;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=0.82;
				temp->time=73;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 20://��s�� 
				temp->stop_num=20;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.31;
				temp->time=73;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 21://���� 
				temp->stop_num=21;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.19;
				temp->time=99;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 22://�n�� 
				temp->stop_num=22;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.13;
				temp->time=105;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 23://�n��i���] 
				temp->stop_num=23;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=0;
				temp->time=114;
				temp->linking=NULL;
				break;
			default:
				printf("blue line information is wrong!!");
				break;
		}
	
	}
	//red line 
	temp=Node_head[1];
	for(i=1;i<=27;i++){
		switch(i){
			case 1:// �H�� 
				temp->stop_num=1;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=2.07;
				temp->time=175;
				temp->inverse_linking=NULL;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 2:// ����L 
				temp->stop_num=2;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=1.93;
				temp->time=136;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 3://�˳� 
				temp->stop_num=3;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=2.05;
				temp->time=145;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 4://���� 
				temp->stop_num=4;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.88;
				temp->time=78;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 5://���q 
				temp->stop_num=5;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=1.44;
				temp->time=109;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;					
			case 6://�_���^ 
				temp->stop_num=6;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=1.62;
				temp->time=145;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;					
			case 7://�_�� 
				temp->stop_num=7;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.76;
				temp->time=91;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;					
			case 8://�_�� 
				temp->stop_num=8;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.86;
				temp->time=73;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;		
			case 9:// ����� 
				temp->stop_num=9;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=1.24;
				temp->time=100;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 10://�۵P 
				temp->stop_num=10;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.61;
				temp->time=61;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;					
			case 11://���w 
				temp->stop_num=11;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.88;
				temp->time=76;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;					
			case 12://�ۤs 
				temp->stop_num=12;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.98;
				temp->time=91;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;				
			case 13://�h�L 
				temp->stop_num=13;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=1.19;
				temp->time=92;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 14:// �C�� 
				temp->stop_num=14;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=1.52;
				temp->time=109;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 15://��s 
				temp->stop_num=15;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=1.02;
				temp->time=90;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 16://���v��� 
				temp->stop_num=16;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.56;
				temp->time=57;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 17://���s 
				temp->stop_num=17;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.54;
				temp->time=58;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 18://���s 
				temp->stop_num=18;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.63;
				temp->time=65;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 19://�x�_���� 
				temp->stop_num=19;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.63;
				temp->time=63;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 20://�O�j��| 
				temp->stop_num=20;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.95;
				temp->time=83;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 21://���������� 
				temp->stop_num=21;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=1.2;
				temp->time=165;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 22://�F�� 
				temp->stop_num=22;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.66;
				temp->time=65;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 23://�j�w�˪L���� 
				temp->stop_num=23;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.88;
				temp->time=70;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 24://�j�w 
				temp->stop_num=24;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.798;
				temp->time=81;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 25://�H�q�w�M 
				temp->stop_num=25;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=1.08;
				temp->time=81;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 26://�x�_101 
				temp->stop_num=26;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.86;
				temp->time=93;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 27://�H�s 
				temp->stop_num=27;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0;
				temp->time=0;
				temp->linking=NULL;
				break;
			default:
				printf("red line information is wrong!!");
				break;
		}
	}
	//Wenhu_Line
	temp=Node_head[2];
	for(i=1;i<=24;i++){
		switch(i){
			case 1://�ʪ��� 
				temp->stop_num=1;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=0.8;
				temp->time=67;
				temp->inverse_linking=NULL;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 2://��] 
				temp->stop_num=2;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=0.59;
				temp->time=47;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 3://�U�ڪ��� 
				temp->stop_num=3;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=1.2;
				temp->time=99;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 4://�U����| 
				temp->stop_num=4;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=0.75;
				temp->time=106;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 5://���� 
				temp->stop_num=5;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=1.55;
				temp->time=124;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 6://��� 
				temp->stop_num=6;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=0.8;
				temp->time=72;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 7://���i�p 
				temp->stop_num=7;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=1.13;
				temp->time=122;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 8://��ޤj�� 
				temp->stop_num=8;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=0.76;
				temp->time=69;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 9://�j�w 
				temp->stop_num=9;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=0.9;
				temp->time=67;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 10://�����_�� 
				temp->stop_num=10;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=1.15;
				temp->time=86;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 11://�n�ʴ_�� 
				temp->stop_num=11;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=1.13;
				temp->time=66;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 12://���s�ꤤ 
				temp->stop_num=12;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=1.48;
				temp->time=142;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 13://�Q�s���� 
				temp->stop_num=13;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=2.58;
				temp->time=172;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case (14)://�j�� 
				temp->stop_num=14;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=1.33;
				temp->time=103;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 15://�C�n�� 
				temp->stop_num=15;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.29;
				temp->time=110;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 16://��� 
				temp->stop_num=16;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=0.83;
				temp->time=65;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 17://���Y 
				temp->stop_num=17;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=1.01;
				temp->time=72;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 18://��w 
				temp->stop_num=18;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=1.13;
				temp->time=78;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 19://���� 
				temp->stop_num=19;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=0.87;
				temp->time=71;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 20://�j�򤽶� 
				temp->stop_num=20;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=1.63;
				temp->time=121;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 21://���w 
				temp->stop_num=21;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=0.89;
				temp->time=78;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 22://�F�� 
				temp->stop_num=22;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=1.01;
				temp->time=85;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 23://�n��i����� 
				temp->stop_num=22;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=0.6;
				temp->time=85;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 24://�n��i���] 
				temp->stop_num=24;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=0;
				temp->time=0;
				temp->linking=NULL;
				break;
			default:
				printf("Wenhu line information is wrong!!");
				break;
		}
	
	}
	//green_Line
	temp=Node_head[3];
	for(i=1;i<=19;i++){
		switch(i){
			case 1://�Q�s 
				temp->stop_num=1;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=1.34;
				temp->time=138;
				temp->inverse_linking=NULL;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 2://�n�ʤT�� 
				temp->stop_num=2;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=1.05;
				temp->time=102;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 3://�x�_�p���J 
				temp->stop_num=3;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=1.05;
				temp->time=84;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 4://�n�ʴ_�� 
				temp->stop_num=4;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=1.08;
				temp->time=92;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 5://�Q���n�� 
				temp->stop_num=5;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=1.32;
				temp->time=106;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 6://���s 
				temp->stop_num=6;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=1.2;
				temp->time=114;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 7://�_�� 
				temp->stop_num=7;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=0.84;
				temp->time=75;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 8://��� 
				temp->stop_num=8;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=0.758;
				temp->time=81;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 9://�p�n�� 
				temp->stop_num=9;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=0.838;
				temp->time=75;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 10://���������� 
				temp->stop_num=10;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=1.17;
				temp->time=83;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 11://�j�F 
				temp->stop_num=11;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=0.64;
				temp->time=88;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 12://�x�q�j�� 
				temp->stop_num=12;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=0.9;
				temp->time=67;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 13://���] 
				temp->stop_num=13;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=1.56;
				temp->time=119;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case (14)://�U�� 
				temp->stop_num=14;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=1.07;
				temp->time=87;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 15://���� 
				temp->stop_num=15;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=1.15;
				temp->time=89;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 16://�j�W�L 
				temp->stop_num=16;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=0.852;
				temp->time=75;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 17://�C�i 
				temp->stop_num=17;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=0.9;
				temp->time=78;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 18://�s���Ϥ��� 
				temp->stop_num=18;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=1.1;
				temp->time=111;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 19://�s�� 
				temp->stop_num=19;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=0;
				temp->time=0;
				temp->linking=NULL;
				break;
			default:
				printf("green line information is wrong!!");
				break;
		}
	
	}
		//yellow_Line
	temp=Node_head[4];
	for(i=1;i<=17;i++){
		switch(i){
			case 1://�n�ը� 
				temp->stop_num=1;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=0.69;
				temp->time=103;
				temp->inverse_linking=NULL;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 2://���w 
				temp->stop_num=2;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.15;
				temp->time=88;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 3://�æw���� 
				temp->stop_num=3;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.3;
				temp->time=100;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 4://���� 
				temp->stop_num=4;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=2.16;
				temp->time=187;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 5://�j�F 
				temp->stop_num=5;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.25;
				temp->time=192;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 6://�F�� 
				temp->stop_num=6;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.18;
				temp->time=118;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 7://�����s�� 
				temp->stop_num=7;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.15;
				temp->time=114;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 8: 
				temp->stop_num=8;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=0.82;
				temp->time=75;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 9://��Ѯc 
				temp->stop_num=9;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=0.93;
				temp->time=89;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 10://���s��p
				temp->stop_num=10;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=0.66;
				temp->time=72;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 11://���v���  
				temp->stop_num=11;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=0.69;
				temp->time=75;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 12://�j���Y 
				temp->stop_num=12;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.88;
				temp->time=148;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 13://�T����p 
				temp->stop_num=13;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.2;
				temp->time=104;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 14://�T�M�ꤤ 
				temp->stop_num=14;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.01;
				temp->time=82;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 15://�}�פ���
				temp->stop_num=15;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.1;
				temp->time=87;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 16://�T������  
				temp->stop_num=16;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=0.95;
				temp->time=110;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 17://�s�� 
				temp->stop_num=17;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=0;
				temp->time=0;
				temp->linking=NULL;
				break;
			default:
				printf("green line information is wrong!!");
				break;
		}
	
	}
	//yellow_Line
	temp=Node_head[5];
	for(i=12;i<=26;i++){
		
		switch(i){
			
			case 12://�j���Y 
				temp->stop_num=12;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.33;
				temp->time=115;
				temp->inverse_linking=NULL;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				i+=5;
				break;
			case 18://�x�_�� 
				temp->stop_num=18;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.01;
				temp->time=93;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 19://��d 
				temp->stop_num=19;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=0.89;
				temp->time=84;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 20://�T�� 
				temp->stop_num=20;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.68;
				temp->time=142;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 21://���ޮc  
				temp->stop_num=21;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.29;
				temp->time=105;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 22://�Y�e��  
				temp->stop_num=22;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1;
				temp->time=93;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 23://�s��  
				temp->stop_num=23;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.83;
				temp->time=130;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 24://���j  
				temp->stop_num=24;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.25;
				temp->time=110;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 25://����  
				temp->stop_num=25;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.29;
				temp->time=159;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 26://�j�s 
				temp->stop_num=26;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=0;
				temp->time=0;
				temp->linking=NULL;
				break;
			default:
				printf("yellow line information is wrong!!");
				break;
		}
	
	}
	//���s�_�� 
	temp=Node_head[6];
	for(i=7;i<=28;i++){
		switch(i){
			case 7://�_�� 
				temp->stop_num=7;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=1.03;
				temp->time=157;
				temp->inverse_linking=NULL;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				i+=20; 
				break;
			case 28:// �s�_�� 
				temp->stop_num=28;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0;
				temp->time=0;
				temp->linking=NULL;
				break;
			default:
				printf("pink line information is wrong!!");
				break;
		}
	
	}
	//���p�Ѽ� 
	temp=Node_head[7];
	for(i=17;i<=20;i++){
		switch(i){
			case 17://�C�i 
				temp->stop_num=17;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=2.5;
				temp->time=203;
				temp->inverse_linking=NULL;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				i+=2; 
				break;
			case 20:// 
				temp->stop_num=20;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=0;
				temp->time=0;
				temp->linking=NULL;
				break;
			default:
				printf("green line information is wrong!!");
				break;
		}
	
	}		
	return;
}

Node* Look_for_Begin(char color,int number){
	char col=color;
	int num=number;
	Node* pt; 
	switch(col){
		case'w':
			pt=Node_head[2];
			while(pt!=NULL){
				if(pt->stop_color==col && pt->stop_num==num)
					break;
				pt=pt->linking;
			}
		break;
		case'b':
			pt=Node_head[0];
			while(pt!=NULL){
				if(pt->stop_color==col && pt->stop_num==num)
					break;
				pt=pt->linking;
			}
		break;
		case'r':
			pt=Node_head[1];
			while(pt!=NULL){
				if(pt->stop_color==col && pt->stop_num==num)
					break;
				pt=pt->linking;
			}
		break;
		case'y':
			pt=Node_head[4];
			while(pt!=NULL){
				if(pt->stop_color==col && pt->stop_num==num)
					break;
				pt=pt->linking;
			}
		break;
		case'g':
			pt=Node_head[3];
			while(pt!=NULL){
				if(pt->stop_color==col && pt->stop_num==num)
					break;
				pt=pt->linking;
			}
		break;
		default:
			printf("Inpur is wrong, please do it again");
		break;
	}
	return pt;
	
};	

void MRT_Path(Node* List_Begin,Node* List_End){
	printf("\nPath:");
	if(List_Begin->stop_color==List_End->stop_color)
		Path_SameColor(List_Begin, List_End);
	else
		Path_diff_Color(List_Begin, List_End);
	printf("\ndistance:%4.2f",total_distance);
	total_cost=price(total_distance);
	printf("\nNormal card:%4.0f ��\t Easy card:%4.0f ��",total_cost,total_cost*0.8);
	Time(total_time);
	return;
};

void Path_SameColor(Node* List_Begin,Node* List_End){

	char col=List_Begin->stop_color;
	Node *Begin,*End,*tmp;
	Begin=List_Begin;
	tmp=Begin;
	End=List_End;
	switch(col){
		case'w':
			if(Begin->stop_num < End->stop_num){
				while(tmp->stop_num != End->stop_num){
					MRT_Name(tmp->stop_color,tmp->stop_num);
					printf("%c%d->",tmp->stop_color,tmp->stop_num);
					total_time+=tmp->time;
					total_distance+=tmp->distance;
					tmp=tmp->linking;
				}
				MRT_Name(tmp->stop_color,tmp->stop_num);
				printf("%c%d",tmp->stop_color,tmp->stop_num);
			}
			else if(Begin->stop_num > End->stop_num){
				while(tmp->stop_num != End->stop_num){
					MRT_Name(tmp->stop_color,tmp->stop_num);
					printf("%c%d->",tmp->stop_color,tmp->stop_num);
					tmp=tmp->inverse_linking;
					total_time+=tmp->time;
					total_distance+=tmp->distance;
				}
				MRT_Name(tmp->stop_color,tmp->stop_num);
				printf("%c%d",tmp->stop_color,tmp->stop_num);
			}
		break;
		case'b':
			if(Begin->stop_num < End->stop_num){
				while(tmp->stop_num != End->stop_num){
					MRT_Name(tmp->stop_color,tmp->stop_num);
					printf("%c%d->",tmp->stop_color,tmp->stop_num);
					total_time+=tmp->time;
					total_distance+=tmp->distance;
					tmp=tmp->linking;
				}
				MRT_Name(tmp->stop_color,tmp->stop_num);
				printf("%c%d",tmp->stop_color,tmp->stop_num);
			}
			else if(Begin->stop_num > End->stop_num){
				while(tmp->stop_num != End->stop_num){
					MRT_Name(tmp->stop_color,tmp->stop_num);
					printf("%c%d->",tmp->stop_color,tmp->stop_num);
					tmp=tmp->inverse_linking;
					total_time+=tmp->time;
					total_distance+=tmp->distance;
				}
				MRT_Name(tmp->stop_color,tmp->stop_num);
				printf("%c%d",tmp->stop_color,tmp->stop_num);
			}
		break;
		case'r':
			if(Begin->stop_num < End->stop_num){
				while(tmp->stop_num != End->stop_num){
					MRT_Name(tmp->stop_color,tmp->stop_num);
					printf("%c%d->",tmp->stop_color,tmp->stop_num);
					total_time+=tmp->time;
					total_distance+=tmp->distance;
					tmp=tmp->linking;
				}
				MRT_Name(tmp->stop_color,tmp->stop_num);
				printf("%c%d",tmp->stop_color,tmp->stop_num);
			}
			else if(Begin->stop_num > End->stop_num){
				while(tmp->stop_num != End->stop_num){
					MRT_Name(tmp->stop_color,tmp->stop_num);
					printf("%c%d->",tmp->stop_color,tmp->stop_num);
					tmp=tmp->inverse_linking;
					total_time+=tmp->time;
					total_distance+=tmp->distance;
				}
				MRT_Name(tmp->stop_color,tmp->stop_num);
				printf("%c%d",tmp->stop_color,tmp->stop_num);
			}
		break;
		case'y':
			if(Begin->stop_num < End->stop_num){
				while(tmp->stop_num != End->stop_num){
					MRT_Name(tmp->stop_color,tmp->stop_num);
					printf("%c%d->",tmp->stop_color,tmp->stop_num);
					total_time+=tmp->time;
					total_distance+=tmp->distance;
					tmp=tmp->linking;
				}
				MRT_Name(tmp->stop_color,tmp->stop_num);
				printf("%c%d",tmp->stop_color,tmp->stop_num);
			}
			else if(Begin->stop_num > End->stop_num){
				while(tmp->stop_num != End->stop_num){
					MRT_Name(tmp->stop_color,tmp->stop_num);
					printf("%c%d->",tmp->stop_color,tmp->stop_num);
					tmp=tmp->inverse_linking;
					total_time+=tmp->time;
					total_distance+=tmp->distance;
				}
				MRT_Name(tmp->stop_color,tmp->stop_num);
				printf("%c%d",tmp->stop_color,tmp->stop_num);
			}
		break;
		case'g':
			if(Begin->stop_num < End->stop_num){
				while(tmp->stop_num != End->stop_num){
					MRT_Name(tmp->stop_color,tmp->stop_num);
					printf("%c%d->",tmp->stop_color,tmp->stop_num);
					total_time+=tmp->time;
					total_distance+=tmp->distance;
					tmp=tmp->linking;
				}
				MRT_Name(tmp->stop_color,tmp->stop_num);
				printf("%c%d",tmp->stop_color,tmp->stop_num);
			}
			else if(Begin->stop_num > End->stop_num){
				while(tmp->stop_num != End->stop_num){
					MRT_Name(tmp->stop_color,tmp->stop_num);
					printf("%c%d->",tmp->stop_color,tmp->stop_num);
					tmp=tmp->inverse_linking;
					total_time+=tmp->time;
					total_distance+=tmp->distance;
				}
				MRT_Name(tmp->stop_color,tmp->stop_num);
				printf("%c%d",tmp->stop_color,tmp->stop_num);
			}
		break;
		default:
			printf("�䤣���J���W!!,�Э��s�ާ@�@��");
		break;
	}
	
	return;
	
};

void Path_diff_Color(Node* List_Begin,Node* List_End){
	char col=List_Begin->stop_color;
	Node *Begin,*End,*tmp;
	Begin=List_Begin;
	tmp=Begin;
	End=List_End;
	//beginning=blue 
	if(Begin->stop_color=='b'){
		switch(End->stop_color){
			case 'y':
				if(tmp->stop_num<=14){//�쩾���s�ͯ� 
					while(tmp->stop_num!=14){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[4];
					while(tmp->stop_num!=7)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>14){//�쩾���s�ͯ� 
					while(tmp->stop_num!=14){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[4];
					while(tmp->stop_num!=7)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
			break;
			case 'w':
				if(tmp->stop_num<=15){//�쩾���_���� 
					while(tmp->stop_num!=15){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[2];
					while(tmp->stop_num!=10)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>15){//�쩾���_���� 
					while(tmp->stop_num!=15){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[2];
					while(tmp->stop_num!=10) 
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
			break;
			case 'g':
				if(tmp->stop_num<=11){//������ 
					while(tmp->stop_num!=11){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[3];
					while(tmp->stop_num!=8)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>11){//������ 
					while(tmp->stop_num!=11){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[3];
					while(tmp->stop_num!=8) 
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
			break;
			case 'r':
				if(tmp->stop_num<=12){//��_���� 
					while(tmp->stop_num!=12){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[1];
					while(tmp->stop_num!=19)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>12){//��_���� 
					while(tmp->stop_num!=12){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[1];
					while(tmp->stop_num!=19) 
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
			break;
			
		}
	}
	//beginning=red
	if(Begin->stop_color=='r'){
		switch(End->stop_color){
			case 'y':
				if(tmp->stop_num<=16){//����v����� 
					while(tmp->stop_num!=16){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[4];
					while(tmp->stop_num!=11)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>16){//����v����� 
					while(tmp->stop_num!=16){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[4];
					while(tmp->stop_num!=11)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
			break;
			case 'w':
				if(tmp->stop_num<=24){//��j�w�� 
					while(tmp->stop_num!=24){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[2];
					while(tmp->stop_num!=9)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>24){//��j�w�� 
					while(tmp->stop_num!=24){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[2];
					while(tmp->stop_num!=9) 
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
			break;
			case 'g':
				if(tmp->stop_num<=19){
				
				if(tmp->stop_num<=18){//�줤�s�� 
					while(tmp->stop_num!=18){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[3];
					while(tmp->stop_num!=5)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>18){//������ 
					while(tmp->stop_num!=18){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[3];
					while(tmp->stop_num!=5) 
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				}
				}
				else{
					if(tmp->stop_num<=21){//�쯸 
					while(tmp->stop_num!=21){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[3];
					while(tmp->stop_num!=10)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>21){//������ 
					while(tmp->stop_num!=21){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[3];
					while(tmp->stop_num!=10) 
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				}
				}
			break;
			case 'b':
				if(tmp->stop_num<=19){//��_���� 
					while(tmp->stop_num!=19){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[1];
					while(tmp->stop_num!=1)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>19){//��_���� 
					while(tmp->stop_num!=19){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[1];
					while(tmp->stop_num!=11) 
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
			break;
			
		}
	}
	//beginning=green 
	if(Begin->stop_color=='g'){
		switch(End->stop_color){
			case 'y':
			  if(tmp->stop_num<=8){
			  
				if(tmp->stop_num<=5){//��Q���n�ʯ� 
					while(tmp->stop_num!=5){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[4];
					while(tmp->stop_num!=8)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>5){//�쩾���s�ͯ� 
					while(tmp->stop_num!=5){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[4];
					while(tmp->stop_num!=8)
						tmp=tmp->linking;
						Path_SameColor(tmp, List_End);	
				} 
			  }else if(tmp->stop_num>8){
			  		if(tmp->stop_num<=11){//��j�F�� 
					while(tmp->stop_num!=11){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[4];
					while(tmp->stop_num!=5)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>11){//��F���� 
					while(tmp->stop_num!=11){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[4];
					while(tmp->stop_num!=5)
						tmp=tmp->linking;
						Path_SameColor(tmp, List_End);	
			  } 
			break;
			case 'w':
				if(tmp->stop_num<=4){//��n�ʴ_���� 
					while(tmp->stop_num!=4){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[2];
					while(tmp->stop_num!=11)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>4){//��n�ʴ_���� 
					while(tmp->stop_num!=4){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[2];
					while(tmp->stop_num!=11) 
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
			break;
			case 'b':
				if(tmp->stop_num<=8){//������ 
					while(tmp->stop_num!=8){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[3];
					while(tmp->stop_num!=11)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>8){//������ 
					while(tmp->stop_num!=8){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[3];
					while(tmp->stop_num!=11) 
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
			break;
			case 'r':
				if(tmp->stop_num<=8) { 
					if(tmp->stop_num<=5){//�줤�s�� 
						while(tmp->stop_num!=5){
							MRT_Name(tmp->stop_color,tmp->stop_num);
							printf("%c%d->",tmp->stop_color,tmp->stop_num);
							total_time+=tmp->time;
							total_distance+=tmp->distance;
							tmp=tmp->linking;
						}					
						tmp=Node_head[1];
						while(tmp->stop_num!=18)
							tmp=tmp->linking;
						Path_SameColor(tmp, List_End);	
					} 
					else if(tmp->stop_num>5){//��_���� 
						while(tmp->stop_num!=5){
							MRT_Name(tmp->stop_color,tmp->stop_num);
							printf("%c%d->",tmp->stop_color,tmp->stop_num);
							tmp=tmp->inverse_linking;
							total_time+=tmp->time;
							total_distance+=tmp->distance;
						}					
						tmp=Node_head[1];
						while(tmp->stop_num!=18) 
							tmp=tmp->linking;
						Path_SameColor(tmp, List_End);	
					} 
				}else if(tmp->stop_num>8){
					if(tmp->stop_num<=10){//�줤�������� 
						while(tmp->stop_num!=10){
							MRT_Name(tmp->stop_color,tmp->stop_num);
							printf("%c%d->",tmp->stop_color,tmp->stop_num);
							total_time+=tmp->time;
							total_distance+=tmp->distance;
							tmp=tmp->linking;
						}					
						tmp=Node_head[1];
						while(tmp->stop_num!=21)
							tmp=tmp->linking;
						Path_SameColor(tmp, List_End);	
					} 
					else if(tmp->stop_num>10){//�줤�������� 
						while(tmp->stop_num!=10){
							MRT_Name(tmp->stop_color,tmp->stop_num);
							printf("%c%d->",tmp->stop_color,tmp->stop_num);
							tmp=tmp->inverse_linking;
							total_time+=tmp->time;
							total_distance+=tmp->distance;
						}					
						tmp=Node_head[1];
						while(tmp->stop_num!=21) 
							tmp=tmp->linking;
						Path_SameColor(tmp, List_End);	
					} 
				}
			break;
			
		}
		}
	} 
	//beginning=wenhu 
	if(Begin->stop_color=='w'){
		switch(End->stop_color){
			case 'y':
			  if(tmp->stop_num>=11){
			  	if(tmp->stop_num<=11){//��n�ʴ_���� 
					while(tmp->stop_num!=11){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[3];
					while(tmp->stop_num!=4)//��Q���n�� 
						tmp=tmp->linking;
					while(tmp->stop_num!=5){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}				
					tmp=Node_head[4];
					while(tmp->stop_num!=8) 
						tmp=tmp->linking;		
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>11){//��n�ʴ_���� 
					while(tmp->stop_num!=11){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[3];
					while(tmp->stop_num!=4)//��Q���n�� 
						tmp=tmp->linking;
					while(tmp->stop_num!=5){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}				
					tmp=Node_head[4];
					while(tmp->stop_num!=8) 
						tmp=tmp->linking;	
					Path_SameColor(tmp, List_End);	
				} 
			  
			  } 
			  else if(tmp->stop_num==12){
			  	if(tmp->stop_num<=10){//�쩾���_���� 
					while(tmp->stop_num!=10){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[0];
					while(tmp->stop_num!=15)//�쩾���s�� 
						tmp=tmp->linking;
					while(tmp->stop_num!=14){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}				
					tmp=Node_head[4];
					while(tmp->stop_num!=7) 
						tmp=tmp->linking;		
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>10){//�쩾���_���� 
					while(tmp->stop_num!=10){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[0];
					while(tmp->stop_num!=15)//�쩾���s�� 
						tmp=tmp->linking;
					while(tmp->stop_num!=14){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}				
					tmp=Node_head[4];
					while(tmp->stop_num!=7) 
						tmp=tmp->linking;	
					Path_SameColor(tmp, List_End);	
				} 
			  
			  } 
			  else if(tmp->stop_num<=9){
			  	if(tmp->stop_num<=9){//��j�w�� 
					while(tmp->stop_num!=9){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[1];
					while(tmp->stop_num!=24)//��j�w�� 
						tmp=tmp->linking;
					while(tmp->stop_num!=22){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						
					}				
					tmp=Node_head[4];
					while(tmp->stop_num!=22) 
						tmp=tmp->linking;		
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>11){//��n�ʴ_���� 
					while(tmp->stop_num!=11){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[3];
					while(tmp->stop_num!=4)//��Q���n�� 
						tmp=tmp->linking;
					while(tmp->stop_num!=5){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}				
					tmp=Node_head[4];
					while(tmp->stop_num!=8) 
						tmp=tmp->linking;	
					Path_SameColor(tmp, List_End);	
				} 
			  
			  } 
				
			break;
			case 'b':
				if(tmp->stop_num>=17){
				if(tmp->stop_num<=24){//��n��i���� 
					while(tmp->stop_num!=24){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[2];
					while(tmp->stop_num!=23)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>24){//���n��i����
					while(tmp->stop_num!=24){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[2];
					while(tmp->stop_num!=23) 
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				} 
				else if(tmp->stop_num<17){
				if(tmp->stop_num<=10){//�쩾���_���� 
					while(tmp->stop_num!=10){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[2];
					while(tmp->stop_num!=15)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>10){//�쩾���_���� 
					while(tmp->stop_num!=10){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[2];
					while(tmp->stop_num!=15) 
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				} 
				
			break;
			case 'g':
				if(tmp->stop_num<=11){//��n�ʴ_���� 
					while(tmp->stop_num!=11){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[3];
					while(tmp->stop_num!=4)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>11){//��n�ʴ_����  
					while(tmp->stop_num!=11){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[3];
					while(tmp->stop_num!=4) 
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
			break;
			case 'r':
				if(tmp->stop_num<=9){//��j�w�� 
					while(tmp->stop_num!=9){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[1];
					while(tmp->stop_num!=24)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>9){//��j�w�� 
					while(tmp->stop_num!=19){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[1];
					while(tmp->stop_num!=24) 
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
			break;
			
		}
	}
	//beginning=yellow 
	if(Begin->stop_color=='y'){
		switch(End->stop_color){
			case 'b':
				if(tmp->stop_num<=7){//�쩾���s�ͯ� 
					while(tmp->stop_num!=7){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[0];
					while(tmp->stop_num!=14)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>7){//�쩾���s�ͯ� 
					while(tmp->stop_num!=7){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[0];
					while(tmp->stop_num!=14)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
			break;
			case 'w':
			  if(tmp->stop_num>=8){
				if(tmp->stop_num<=8){//��Q���n�ʯ� 
					while(tmp->stop_num!=8){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}
					tmp=Node_head[3];
					while(tmp->stop_num!=5)//�n�ʴ_���� 
						tmp=tmp->linking;
					while(tmp->stop_num!=4){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						
					}					
					tmp=Node_head[2];
					while(tmp->stop_num!=11)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>8){//�쩾���_���� 
					while(tmp->stop_num!=8){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}		
					tmp=Node_head[3];
					while(tmp->stop_num!=5)//�n�ʴ_���� 
						tmp=tmp->linking;
					while(tmp->stop_num!=4){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						
					}					
					tmp=Node_head[2];
					while(tmp->stop_num!=11)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
			  }
			  else if(tmp->stop_num==7){
				if(tmp->stop_num<=7){//�쩾���s�ͯ� 
					while(tmp->stop_num!=7){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}
					tmp=Node_head[0];
					while(tmp->stop_num!=14)//�����_���� 
						tmp=tmp->linking;
					while(tmp->stop_num!=15){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[2];
					while(tmp->stop_num!=10)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>7){//�쩾���s�ͯ�  
					while(tmp->stop_num!=7){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}		
					tmp=Node_head[0];
					while(tmp->stop_num!=14)//�����_����  
						tmp=tmp->linking;
					while(tmp->stop_num!=15){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
						
					}					
					tmp=Node_head[2];
					while(tmp->stop_num!=10)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				}
			} 
			  else if(tmp->stop_num<=6){
				if(tmp->stop_num<=6){//��F���� 
					while(tmp->stop_num!=6){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}
					tmp=Node_head[1];
					while(tmp->stop_num!=22)//��j�w�� 
						tmp=tmp->linking;
					while(tmp->stop_num!=24){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[2];
					while(tmp->stop_num!=9)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>6){//��F���� 
					while(tmp->stop_num!=6){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}		
					tmp=Node_head[1];
					while(tmp->stop_num!=22)//��j�w�� 
						tmp=tmp->linking;
					while(tmp->stop_num!=24){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						
					}					
					tmp=Node_head[2];
					while(tmp->stop_num!=11)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
			  }  
			  
				
			break;
			case 'g':
				if(tmp->stop_num<=8){//������ 
					while(tmp->stop_num!=8){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[3];
					while(tmp->stop_num!=5)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>8){//������ 
					while(tmp->stop_num!=5){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[3];
					while(tmp->stop_num!=5) 
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
			break;
			case 'r':
			  if(tmp->stop_num>=9){
			  	if(tmp->stop_num<=11){//����v����� 
					while(tmp->stop_num!=11){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[1];
					while(tmp->stop_num!=16)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>11){//����v����� 
					while(tmp->stop_num!=11){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[1];
					while(tmp->stop_num!=16) 
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
			  }
			  else if(tmp->stop_num<=8){
			  	if(tmp->stop_num<=6){//��F���� 
					while(tmp->stop_num!=6){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[1];
					while(tmp->stop_num!=22)
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
				else if(tmp->stop_num>6){//��F����
					while(tmp->stop_num!=6){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[1];
					while(tmp->stop_num!=22) 
						tmp=tmp->linking;
					Path_SameColor(tmp, List_End);	
				} 
			  }
				
			break;
			
		}
	}
	
	return;
};
double price(double distance){
	printf("\n");
	if(distance<5)
		return 20;
	else if(distance>=5 && distance<8)
		return 25;
	else if(distance>=8 && distance<11)
		return 30;
	else if(distance>=11 && distance<14)
		return 35;
	else if(distance>=14 && distance<17)
		return 40;
	else if(distance>=17 && distance<20)
		return 45;
	else if(distance>=20 && distance<23)
		return 50;
	else if(distance>=23 && distance<26)
		return 55;
	else if(distance>=26 && distance<31)
		return 60;
	else if(distance>=31)
		return 65;	
}

void Time(int time){
	int Hour=time/3600;
	int Min=(time-Hour*3600)/60;
	int Sec=time-Hour*3600-60*Min;
	
	if(time>=3600)
		printf("\n\nTotal time:%d hr %d min %d s",Hour,Min,Sec);
	else if(time<3600 && time>=60)
		printf("\n\nTotal time: %d min %d s",Min,Sec);
	if(time<60)
		printf("\n\nTotal time: %d s",Sec);
}


