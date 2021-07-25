#include<stdio.h>
#include<stdlib.h>
void MRT_Name(char,int);

void MRT_Name(char color,int Number){
	if(color=='b'){
		switch(Number){
			case 1:
				printf("Dingpu");
			break;
			case 2:
				printf("Yongning");
			break;
			case 3:
				printf("Tucheng");
			break;
			case 4:
				printf("Haishan");
			break;
			case 5:
				printf("Far Eastern Hospital");
			break;
			case 6:
				printf("Fuzhong");
			break;
			case 7:
				printf("Banqiao");
			break;
			case 8:
				printf("Xinpu");
			break;
			case 9:
				printf("Jiangzicui");
			break;
			case 10:
				printf("Longshan Temple");
			break;
			case 11:
				printf("Ximen");
			break;
			case 12:
				printf("Taipei Main Station");
			break;
			case 13:
				printf("Shandao Temple");
			break;
			case 14:
				printf("Zhonhxiao Xinsheng");
			break;
			case 15:
				printf("Zhonhxiao Fuxing");
			break;	
			case 16:
				printf("Zhonhxiao Dunhua");
			break;
			case 17:
				printf("Sun Yat-sen Memorial Hall");
			break;
			case 18:
				printf("Taipei City Hall");
			break;
			case 19:
				printf("Yongchun");
			break;
			case 20:
				printf("Houshanpi");
			break;
			case 21:
				printf("Kunyang");
			break;
			case 22:
				printf("Nangang");
			break;
			case 23:
				printf("Taipei Nangang Exhibition Center");
			break;
			default:
				printf("Please only input the value in the list");
			break;
		}		
	}
	else if(color=='r'){
		switch(Number){
			case 1:
				printf("Tamsui");
			break;
			case 2:
				printf("Hongshulin");
			break;
			case 3:
				printf("Zhuwei");
			break;
			case 4:
				printf("Guandu");
			break;
			case 5:
				printf("Zhongyi");
			break;
			case 6:
				printf("Fuxinggang");
			break;
			case 7:
				printf("Beitou");
			break;
			case 8:
				printf("Qiyan");
			break;
			case 9:
				printf("Qilian");
			break;
			case 10:
				printf("Shipai");
			break;
			case 11:
				printf("Mingde");
			break;
			case 12:
				printf("Zhishan");
			break;
			case 13:
				printf("Shilin");
			break;
			case 14:
				printf("Jiantan");
			break;
			case 15:
				printf("Yuanshan");
			break;	
			case 16:
				printf("Minquan W.Rd.");
			break;
			case 17:
				printf("Shuanglian");
			break;
			case 18:
				printf("Zhonhshan");
			break;
			case 19:
				printf("Taipei Main Station");
			break;
			case 20:
				printf("NTU Hospital");
			break;
			case 21:
				printf("Chiang Kai-Shek Memorial Hall");
			break;
			case 22:
				printf("Dongmen");
			break;
			case 23:
				printf("Daan Park");
			break;
			case 24:
				printf("Daan");
			break;
			case 25:
				printf("Xinyi Anhe");
			break;
			case 26:
				printf("Taipei 101/World Trade Center");
			break;
			case 27:
				printf("Xiangshan");
			break;
			default:
				printf("Please only input the value in the list");
			break;
		}
	} 
	else if(color=='y'){
		switch(Number){
		
			case 1:
				printf("Nanshijiao");
			break;
			case 2:
				printf("Jingan");
			break;
			case 3:
				printf("Yongan Market");
			break;
			case 4:
				printf("Dingxi");
			break;
			case 5:
				printf("Guting");
			break;
			case 6:
				printf("Dongmen");
			break;
			case 7:
				printf("Zhonhxiao Xinsheng");
			break;
			case 8:
				printf("Songjiang Nanjing");
			break;
			case 9:
				printf("Xingtian Temple");
			break;
			case 10:
				printf("Zhonhshan Elementary School");
			break;
			case 11:
				printf("Minquan W.Rd.");
			break;
			case 12:
				printf("Daquaotou");
			break;
			case 13:
				printf("Sanchong Elementary School");
			break;
			case 14:
				printf("Sanhe Junior High School");
			break;
			case 15:
				printf("St. Ignatius High School");
			break;	
			case 16:
				printf("Sanmin Senior High School");
			break;
			case 17:
				printf("Luzhou");
			break;
			case 18:
				printf("Taipei Bridge");
			break;
			case 19:
				printf("Cailiao");
			break;
			case 20:
				printf("Sanchong");
			break;
			case 21:
				printf("Xianse Temple");
			break;
			case 22:
				printf("Touqianzhung");
			break;
			case 23:
				printf("Xinzhuang");
			break;
			case 24:
				printf("Fu Jen University");
			break;
			case 25:
				printf("Danfeng");
			break;
			case 26:
				printf("Huilong");
			break;
			default:
				printf("Please only input the value in the list");
			break;
		}
	}
	else if(color=='w'){
	  switch(Number){
			case 1:
				printf("Taipei Zoo");
			break;
			case 2:
				printf("Muzha");
			break;
			case 3:
				printf("Wanfang Community");
			break;
			case 4:
				printf("Wanfang Hospital");
			break;
			case 5:
				printf("Xinhai");
			break;
			case 6:
				printf("Linguang");
			break;
			case 7:
				printf("Liuzhangli");
			break;
			case 8:
				printf("Technology Builiding");
			break;
			case 9:
				printf("Daan");
			break;
			case 10:
				printf("Zhongxiao Fuxing");
			break;
			case 11:
				printf("Nanjing Fuxing");
			break;
			case 12:
				printf("Zhongshan Junior High School");
			break;
			case 13:
				printf("Shongshan Airport");
			break;
			case 14:
				printf("Dazhi");
			break;
			case 15:
				printf("Jiannan Rd.");
			break;	
			case 16:
				printf("Xihu");
			break;
			case 17:
				printf("Gangqian");
			break;
			case 18:
				printf("Wende");
			break;
			case 19:
				printf("Neihu");
			break;
			case 20:
				printf("Dahu Park");
			break;
			case 21:
				printf("Huzhou");
			break;
			case 22:
				printf("Donghu");
			break;
			case 23:
				printf("Nangang Software Park");
			break;
			case 24:
				printf("Taipei Nangang Exhibition Center");
			break;
			default:
				printf("Please only input the value in the list");
			break;
		}
	}
	else if(color=='g'){
		switch(Number){
		    case 1:
				printf("Songshan");
			break;
			case 2:
				printf("Nanjing Sanmin");
			break;
			case 3:
				printf("Taipei Arena");
			break;
			case 4:
				printf("Nanjing Fuxing");
			break;
			case 5:
				printf("Songjiang Nanjing");
			break;
			case 6:
				printf("Zohongshan");
			break;
			case 7:
				printf("Beimen");
			break;
			case 8:
				printf("Ximen");
			break;
			case 9:
				printf("Xiaonamen");
			break;
			case 10:
				printf("Chiang Kai-Shek Memorial Hall");
			break;
			case 11:
				printf("Guting");
			break;
			case 12:
				printf("Taipower Building");
			break;
			case 13:
				printf("Gongguan");
			break;
			case 14:
				printf("Wanlong");
			break;
			case 15:
				printf("Jingmei");
			break;	
			case 16:
				printf("Dapinglin");
			break;
			case 17:
				printf("Qizhang");
			break;
			case 18:
				printf("Xindan District Office");
			break;
			case 19:
				printf("Xindian");
			break;
			case 20:
				printf("Xiaobitan");
			break;
			default:
				printf("Please only input the value in the list");
			break;
		}
	}
}
