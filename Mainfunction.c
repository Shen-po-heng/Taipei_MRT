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
	printf("Blue_Line :1.頂埔 2.永寧 3.土城 4.海山 5.亞東醫院 6.府中 7.板橋 8.新埔 9.江子翠"); 
	printf("10.龍山寺 11.西門 12.台北車站 13.善導寺 14.忠孝新生 15.忠孝復興 16.忠孝敦化"); 
	printf("17.國父紀念館 18.市政府 19.永春 20.後山埤 21.昆陽 22.南港 23.南港展覽館\n");
	printf("\n");
	printf("Red_Line :1.淡水 2.紅樹林 3.竹圍 4.關渡 5.忠義 6.復興崗 7.北投 8.奇岩 9.唭哩岸");
	printf("10.石牌 11.明德 12.芝山 13.士林 14.劍潭 15.圓山 16.民權西路 17.雙連 18中山");
	printf("19.台北車站 20.台大醫院 21.中正紀念堂 22.東門 23.大安森林公園 24.大安 25.信義安和 26.台北101/世貿 27.象山 28.新北投\n");
	printf("\n");
	printf("Green_Line : 1.松山 2.南京三民 3.台北小巨蛋 4.南京復興 5.松江南京 6.中山 7.北門 8.西門 9.小南門");
	printf(" 10.中正紀念堂 11.古亭 12.台電大樓 13.公館 14.萬隆 15.景美 16.大坪林 17.七張");
	printf("18.新店區公所 19.新店 20.小碧潭\n");
	printf("\n");
	printf("Wenhu_Line :1.動物園 2.木柵 3.萬芳社區 4.萬芳醫院 5.辛亥 6.麟光 7.六張犁 8.科技大樓 9.大安");
	printf("10.忠孝復興 11.南京復興 12.中山國中 13.松山機場 14.大直 15.劍南路 16.西湖 17.港墘");
	printf("18.文德 19.內湖 20.大湖公園 21.葫洲 22.東湖 23.南港軟體園區 24.南港\n"); 
	printf("\n");
	printf("Yellow_Line :1.南勢角 2.景安 3.永安市場 4.頂溪 5.古亭 6.東門 7.忠孝新生 8.松江南京 9.行天宮");
	printf("10.中山國小 11.民權西路 12.大橋頭 13.三重國小 14.三和國中 15.徐匯中學 16.三民高中 17.蘆洲");
	printf("18.台北橋 19.菜寮 20.三重 21.先嗇宮 22.頭前庄 22.新莊 24.輔大 25.丹鳳 26.迴龍\n\n"); 
	MRT_Graph();
	
	//User input
	printf("請輸入起程站:\n");
	printf("哪一線(顏色:Wenhu Line-> 'w',Red_Line->'r',Blue_Line->'b',Green_Line->'g',Yellow_Line->'y'):") ;
	fflush(stdin);
	scanf("%c",&Begin_Stop->stop_color);
	printf("哪一站(站的號碼如上):");
	scanf("%d",&Begin_Stop->stop_num);
	printf("\n請輸入終點站:\n");
	printf("哪一線(顏色:Wenhu Line-> 'w',Red_Line->'r',Blue_Line->'b',Green_Line->'g',Yellow_Line->'y'):") ;
	fflush(stdin);
	scanf("%c",&Destination_Stop->stop_color);
	printf("哪一站(站的號碼如上):");
	scanf("%d",&Destination_Stop->stop_num);
	
	//let *List_Begin 
	List_Begin=Look_for_Begin(Begin_Stop->stop_color,Begin_Stop->stop_num);
	printf("\n起程站:顏色 %c 站號%d",List_Begin->stop_color,List_Begin->stop_num );
	printf("\t站名:");
	MRT_Name(List_Begin->stop_color,List_Begin->stop_num);
	List_End=Look_for_Begin(Destination_Stop->stop_color,Destination_Stop->stop_num);
	printf("\n終點站:顏色 %c 站號%d",List_End->stop_color,List_End->stop_num );
	printf("\t站名:");
	MRT_Name(List_End->stop_color,List_End->stop_num);
	printf("\n");
	//搭車資訊
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
			case 1://頂埔 
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
			case 2://永寧 
				temp->stop_num=2;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.13;
				temp->time=95;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 3://土城 
				temp->stop_num=3;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.64;
				temp->time=106;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 4://海山 
				temp->stop_num=4;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=0.91;
				temp->time=142;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 5://亞東醫院 
				temp->stop_num=5;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.31;
				temp->time=92;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 6://府中 
				temp->stop_num=6;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=0.65;
				temp->time=89;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 7://板橋 
				temp->stop_num=7;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.28;
				temp->time=102;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 8://新埔 
				temp->stop_num=8;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.28;
				temp->time=74;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 9://江子翠 
				temp->stop_num=9;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=3.08;
				temp->time=190;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 10://龍山寺 
				temp->stop_num=10;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.27;
				temp->time=103;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 11://西門 
				temp->stop_num=11;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.43;
				temp->time=132;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 12://台北車站 
				temp->stop_num=12;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=0.89;
				temp->time=132;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 13://善導寺 
				temp->stop_num=13;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=0.94;
				temp->time=64;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case (14)://忠孝新生 
				temp->stop_num=14;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.13;
				temp->time=76;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 15://忠孝復興 
				temp->stop_num=15;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=0.67;
				temp->time=63;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 16://忠孝敦化 
				temp->stop_num=16;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=0.72;
				temp->time=67;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 17://國父紀念館 
				temp->stop_num=17;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=0.85;
				temp->time=72;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 18://市政府 
				temp->stop_num=18;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.13;
				temp->time=82;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 19://永春 
				temp->stop_num=19;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=0.82;
				temp->time=73;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 20://後山埤 
				temp->stop_num=20;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.31;
				temp->time=73;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 21://昆陽 
				temp->stop_num=21;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.19;
				temp->time=99;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 22://南港 
				temp->stop_num=22;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.13;
				temp->time=105;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 23://南港展覽館 
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
			case 1:// 淡水 
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
			case 2:// 紅樹林 
				temp->stop_num=2;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=1.93;
				temp->time=136;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 3://竹圍 
				temp->stop_num=3;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=2.05;
				temp->time=145;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 4://關渡 
				temp->stop_num=4;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.88;
				temp->time=78;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 5://忠義 
				temp->stop_num=5;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=1.44;
				temp->time=109;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;					
			case 6://復興崗 
				temp->stop_num=6;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=1.62;
				temp->time=145;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;					
			case 7://北投 
				temp->stop_num=7;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.76;
				temp->time=91;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;					
			case 8://奇岩 
				temp->stop_num=8;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.86;
				temp->time=73;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;		
			case 9:// 其哩岸 
				temp->stop_num=9;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=1.24;
				temp->time=100;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 10://石牌 
				temp->stop_num=10;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.61;
				temp->time=61;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;					
			case 11://明德 
				temp->stop_num=11;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.88;
				temp->time=76;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;					
			case 12://芝山 
				temp->stop_num=12;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.98;
				temp->time=91;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;				
			case 13://士林 
				temp->stop_num=13;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=1.19;
				temp->time=92;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 14:// 劍潭 
				temp->stop_num=14;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=1.52;
				temp->time=109;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 15://圓山 
				temp->stop_num=15;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=1.02;
				temp->time=90;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 16://民權西路 
				temp->stop_num=16;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.56;
				temp->time=57;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 17://雙連 
				temp->stop_num=17;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.54;
				temp->time=58;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 18://中山 
				temp->stop_num=18;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.63;
				temp->time=65;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 19://台北車站 
				temp->stop_num=19;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.63;
				temp->time=63;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 20://臺大醫院 
				temp->stop_num=20;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.95;
				temp->time=83;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 21://中正紀念堂 
				temp->stop_num=21;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=1.2;
				temp->time=165;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 22://東門 
				temp->stop_num=22;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.66;
				temp->time=65;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 23://大安森林公園 
				temp->stop_num=23;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.88;
				temp->time=70;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 24://大安 
				temp->stop_num=24;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.798;
				temp->time=81;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 25://信義安和 
				temp->stop_num=25;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=1.08;
				temp->time=81;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;	
			case 26://台北101 
				temp->stop_num=26;
				fflush(stdin);
				temp->stop_color='r';
				temp->distance=0.86;
				temp->time=93;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 27://象山 
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
			case 1://動物園 
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
			case 2://木柵 
				temp->stop_num=2;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=0.59;
				temp->time=47;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 3://萬芳社區 
				temp->stop_num=3;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=1.2;
				temp->time=99;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 4://萬芳醫院 
				temp->stop_num=4;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=0.75;
				temp->time=106;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 5://辛亥 
				temp->stop_num=5;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=1.55;
				temp->time=124;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 6://麟光 
				temp->stop_num=6;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=0.8;
				temp->time=72;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 7://六張犁 
				temp->stop_num=7;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=1.13;
				temp->time=122;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 8://科技大樓 
				temp->stop_num=8;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=0.76;
				temp->time=69;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 9://大安 
				temp->stop_num=9;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=0.9;
				temp->time=67;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 10://忠孝復興 
				temp->stop_num=10;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=1.15;
				temp->time=86;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 11://南京復興 
				temp->stop_num=11;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=1.13;
				temp->time=66;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 12://中山國中 
				temp->stop_num=12;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=1.48;
				temp->time=142;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 13://松山機場 
				temp->stop_num=13;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=2.58;
				temp->time=172;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case (14)://大直 
				temp->stop_num=14;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=1.33;
				temp->time=103;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 15://劍南路 
				temp->stop_num=15;
				fflush(stdin);
				temp->stop_color='b';
				temp->distance=1.29;
				temp->time=110;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 16://西湖 
				temp->stop_num=16;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=0.83;
				temp->time=65;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 17://港墘 
				temp->stop_num=17;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=1.01;
				temp->time=72;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 18://文德 
				temp->stop_num=18;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=1.13;
				temp->time=78;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 19://內湖 
				temp->stop_num=19;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=0.87;
				temp->time=71;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 20://大湖公園 
				temp->stop_num=20;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=1.63;
				temp->time=121;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 21://葫洲 
				temp->stop_num=21;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=0.89;
				temp->time=78;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 22://東湖 
				temp->stop_num=22;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=1.01;
				temp->time=85;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 23://南港展覽園區 
				temp->stop_num=22;
				fflush(stdin);
				temp->stop_color='w';
				temp->distance=0.6;
				temp->time=85;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 24://南港展覽館 
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
			case 1://松山 
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
			case 2://南京三民 
				temp->stop_num=2;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=1.05;
				temp->time=102;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 3://台北小巨蛋 
				temp->stop_num=3;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=1.05;
				temp->time=84;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 4://南京復興 
				temp->stop_num=4;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=1.08;
				temp->time=92;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 5://松江南京 
				temp->stop_num=5;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=1.32;
				temp->time=106;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 6://中山 
				temp->stop_num=6;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=1.2;
				temp->time=114;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 7://北門 
				temp->stop_num=7;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=0.84;
				temp->time=75;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 8://西門 
				temp->stop_num=8;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=0.758;
				temp->time=81;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 9://小南門 
				temp->stop_num=9;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=0.838;
				temp->time=75;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 10://中正紀念堂 
				temp->stop_num=10;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=1.17;
				temp->time=83;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 11://古亭 
				temp->stop_num=11;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=0.64;
				temp->time=88;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 12://台電大樓 
				temp->stop_num=12;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=0.9;
				temp->time=67;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 13://公館 
				temp->stop_num=13;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=1.56;
				temp->time=119;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case (14)://萬隆 
				temp->stop_num=14;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=1.07;
				temp->time=87;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 15://景美 
				temp->stop_num=15;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=1.15;
				temp->time=89;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 16://大坪林 
				temp->stop_num=16;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=0.852;
				temp->time=75;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 17://七張 
				temp->stop_num=17;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=0.9;
				temp->time=78;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 18://新店區公所 
				temp->stop_num=18;
				fflush(stdin);
				temp->stop_color='g';
				temp->distance=1.1;
				temp->time=111;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 19://新店 
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
			case 1://南勢角 
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
			case 2://景安 
				temp->stop_num=2;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.15;
				temp->time=88;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 3://永安市場 
				temp->stop_num=3;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.3;
				temp->time=100;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 4://頂溪 
				temp->stop_num=4;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=2.16;
				temp->time=187;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 5://古亭 
				temp->stop_num=5;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.25;
				temp->time=192;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 6://東門 
				temp->stop_num=6;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.18;
				temp->time=118;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 7://忠孝新生 
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
			case 9://行天宮 
				temp->stop_num=9;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=0.93;
				temp->time=89;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 10://中山國小
				temp->stop_num=10;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=0.66;
				temp->time=72;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 11://民權西路  
				temp->stop_num=11;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=0.69;
				temp->time=75;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 12://大橋頭 
				temp->stop_num=12;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.88;
				temp->time=148;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 13://三重國小 
				temp->stop_num=13;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.2;
				temp->time=104;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 14://三和國中 
				temp->stop_num=14;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.01;
				temp->time=82;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 15://徐匯中學
				temp->stop_num=15;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.1;
				temp->time=87;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 16://三民高中  
				temp->stop_num=16;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=0.95;
				temp->time=110;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 17://新店 
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
			
			case 12://大橋頭 
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
			case 18://台北橋 
				temp->stop_num=18;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.01;
				temp->time=93;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 19://菜寮 
				temp->stop_num=19;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=0.89;
				temp->time=84;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 20://三重 
				temp->stop_num=20;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.68;
				temp->time=142;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 21://先嗇宮  
				temp->stop_num=21;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.29;
				temp->time=105;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 22://頭前庄  
				temp->stop_num=22;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1;
				temp->time=93;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 23://新莊  
				temp->stop_num=23;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.83;
				temp->time=130;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 24://輔大  
				temp->stop_num=24;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.25;
				temp->time=110;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 25://丹鳳  
				temp->stop_num=25;
				fflush(stdin);
				temp->stop_color='y';
				temp->distance=1.29;
				temp->time=159;
				temp->linking=New_Node();
				temp->linking->inverse_linking=temp;
				temp=temp->linking;
				break;
			case 26://迴龍 
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
	//接新北投 
	temp=Node_head[6];
	for(i=7;i<=28;i++){
		switch(i){
			case 7://北投 
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
			case 28:// 新北投 
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
	//接小碧潭 
	temp=Node_head[7];
	for(i=17;i<=20;i++){
		switch(i){
			case 17://七張 
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
			printf("找不到輸入站名!!,請重新操作一次");
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
	printf("\n普通票:%4.0f 元\t 悠遊卡:%4.0f 元",total_cost,total_cost*0.8);
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
			printf("找不到輸入站名!!,請重新操作一次");
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
				if(tmp->stop_num<=14){//到忠孝新生站 
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
				else if(tmp->stop_num>14){//到忠孝新生站 
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
				if(tmp->stop_num<=15){//到忠孝復興站 
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
				else if(tmp->stop_num>15){//到忠孝復興站 
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
				if(tmp->stop_num<=11){//到西門站 
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
				else if(tmp->stop_num>11){//到西門站 
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
				if(tmp->stop_num<=12){//到北車站 
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
				else if(tmp->stop_num>12){//到北車站 
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
				if(tmp->stop_num<=16){//到民權西路站 
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
				else if(tmp->stop_num>16){//到民權西路站 
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
				if(tmp->stop_num<=24){//到大安站 
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
				else if(tmp->stop_num>24){//到大安站 
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
				
				if(tmp->stop_num<=18){//到中山站 
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
				else if(tmp->stop_num>18){//到西門站 
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
					if(tmp->stop_num<=21){//到站 
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
				else if(tmp->stop_num>21){//到西門站 
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
				if(tmp->stop_num<=19){//到北車站 
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
				else if(tmp->stop_num>19){//到北車站 
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
			  
				if(tmp->stop_num<=5){//到松江南京站 
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
				else if(tmp->stop_num>5){//到忠孝新生站 
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
			  		if(tmp->stop_num<=11){//到古亭站 
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
				else if(tmp->stop_num>11){//到東門站 
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
				if(tmp->stop_num<=4){//到南京復興站 
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
				else if(tmp->stop_num>4){//到南京復興站 
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
				if(tmp->stop_num<=8){//到西門站 
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
				else if(tmp->stop_num>8){//到西門站 
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
					if(tmp->stop_num<=5){//到中山站 
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
					else if(tmp->stop_num>5){//到北車站 
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
					if(tmp->stop_num<=10){//到中正紀念堂站 
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
					else if(tmp->stop_num>10){//到中正紀念堂站 
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
			  	if(tmp->stop_num<=11){//到南京復興站 
					while(tmp->stop_num!=11){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[3];
					while(tmp->stop_num!=4)//到松江南京 
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
				else if(tmp->stop_num>11){//到南京復興站 
					while(tmp->stop_num!=11){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[3];
					while(tmp->stop_num!=4)//到松江南京 
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
			  	if(tmp->stop_num<=10){//到忠孝復興站 
					while(tmp->stop_num!=10){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[0];
					while(tmp->stop_num!=15)//到忠孝新生 
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
				else if(tmp->stop_num>10){//到忠孝復興站 
					while(tmp->stop_num!=10){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[0];
					while(tmp->stop_num!=15)//到忠孝新生 
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
			  	if(tmp->stop_num<=9){//到大安站 
					while(tmp->stop_num!=9){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}					
					tmp=Node_head[1];
					while(tmp->stop_num!=24)//到大安站 
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
				else if(tmp->stop_num>11){//到南京復興站 
					while(tmp->stop_num!=11){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}					
					tmp=Node_head[3];
					while(tmp->stop_num!=4)//到松江南京 
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
				if(tmp->stop_num<=24){//到南港展覽站 
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
				else if(tmp->stop_num>24){//到到南港展覽站
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
				if(tmp->stop_num<=10){//到忠孝復興站 
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
				else if(tmp->stop_num>10){//到忠孝復興站 
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
				if(tmp->stop_num<=11){//到南京復興站 
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
				else if(tmp->stop_num>11){//到南京復興站  
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
				if(tmp->stop_num<=9){//到大安站 
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
				else if(tmp->stop_num>9){//到大安站 
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
				if(tmp->stop_num<=7){//到忠孝新生站 
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
				else if(tmp->stop_num>7){//到忠孝新生站 
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
				if(tmp->stop_num<=8){//到松江南京站 
					while(tmp->stop_num!=8){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}
					tmp=Node_head[3];
					while(tmp->stop_num!=5)//南京復興站 
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
				else if(tmp->stop_num>8){//到忠孝復興站 
					while(tmp->stop_num!=8){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}		
					tmp=Node_head[3];
					while(tmp->stop_num!=5)//南京復興站 
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
				if(tmp->stop_num<=7){//到忠孝新生站 
					while(tmp->stop_num!=7){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}
					tmp=Node_head[0];
					while(tmp->stop_num!=14)//忠孝復興站 
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
				else if(tmp->stop_num>7){//到忠孝新生站  
					while(tmp->stop_num!=7){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						tmp=tmp->inverse_linking;
						total_time+=tmp->time;
						total_distance+=tmp->distance;
					}		
					tmp=Node_head[0];
					while(tmp->stop_num!=14)//忠孝復興站  
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
				if(tmp->stop_num<=6){//到東門站 
					while(tmp->stop_num!=6){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}
					tmp=Node_head[1];
					while(tmp->stop_num!=22)//到大安站 
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
				else if(tmp->stop_num>6){//到東門站 
					while(tmp->stop_num!=6){
						MRT_Name(tmp->stop_color,tmp->stop_num);
						printf("%c%d->",tmp->stop_color,tmp->stop_num);
						
						total_time+=tmp->time;
						total_distance+=tmp->distance;
						tmp=tmp->linking;
					}		
					tmp=Node_head[1];
					while(tmp->stop_num!=22)//到大安站 
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
				if(tmp->stop_num<=8){//到西門站 
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
				else if(tmp->stop_num>8){//到西門站 
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
			  	if(tmp->stop_num<=11){//到民權西路站 
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
				else if(tmp->stop_num>11){//到民權西路站 
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
			  	if(tmp->stop_num<=6){//到東門站 
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
				else if(tmp->stop_num>6){//到東門站
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
		printf("\n\n花費時間:%d hr %d min %d s",Hour,Min,Sec);
	else if(time<3600 && time>=60)
		printf("\n\n花費時間: %d min %d s",Min,Sec);
	if(time<60)
		printf("\n\n花費時間: %d s",Sec);
}


