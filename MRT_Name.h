#include<stdio.h>
#include<stdlib.h>
void MRT_Name(char,int);

void MRT_Name(char color,int Number){
	if(color=='b'){
		switch(Number){
			case 1:
				printf("頂埔");
			break;
			case 2:
				printf("永寧");
			break;
			case 3:
				printf("土城");
			break;
			case 4:
				printf("海山");
			break;
			case 5:
				printf("亞東醫院");
			break;
			case 6:
				printf("府中");
			break;
			case 7:
				printf("板橋");
			break;
			case 8:
				printf("新埔");
			break;
			case 9:
				printf("江子翠");
			break;
			case 10:
				printf("龍山寺");
			break;
			case 11:
				printf("西門");
			break;
			case 12:
				printf("台北車站");
			break;
			case 13:
				printf("善導寺");
			break;
			case 14:
				printf("忠孝新生");
			break;
			case 15:
				printf("忠孝復興");
			break;	
			case 16:
				printf("忠孝敦化");
			break;
			case 17:
				printf("國父紀念館");
			break;
			case 18:
				printf("市政府");
			break;
			case 19:
				printf("永春");
			break;
			case 20:
				printf("後山埤");
			break;
			case 21:
				printf("昆陽");
			break;
			case 22:
				printf("南港");
			break;
			case 23:
				printf("南港展覽館");
			break;
			default:
				printf("找不到!!");
			break;
		}		
	}
	else if(color=='r'){
		switch(Number){
			case 1:
				printf("淡水");
			break;
			case 2:
				printf("紅樹林");
			break;
			case 3:
				printf("竹圍");
			break;
			case 4:
				printf("關渡");
			break;
			case 5:
				printf("忠義");
			break;
			case 6:
				printf("復興崗");
			break;
			case 7:
				printf("北投");
			break;
			case 8:
				printf("奇岩");
			break;
			case 9:
				printf("其哩岸");
			break;
			case 10:
				printf("石牌");
			break;
			case 11:
				printf("明德");
			break;
			case 12:
				printf("芝山");
			break;
			case 13:
				printf("士林");
			break;
			case 14:
				printf("劍潭");
			break;
			case 15:
				printf("圓山");
			break;	
			case 16:
				printf("民權西路");
			break;
			case 17:
				printf("雙連");
			break;
			case 18:
				printf("中山");
			break;
			case 19:
				printf("台北車站");
			break;
			case 20:
				printf("臺大醫院");
			break;
			case 21:
				printf("中正紀念堂");
			break;
			case 22:
				printf("東門");
			break;
			case 23:
				printf("大安森林公園");
			break;
			case 24:
				printf("大安");
			break;
			case 25:
				printf("信義安和");
			break;
			case 26:
				printf("台北101/世貿");
			break;
			case 27:
				printf("象山");
			break;
			default:
				printf("找不到!!");
			break;
		}
	} 
	else if(color=='y'){
		switch(Number){
		
			case 1:
				printf("南勢角");
			break;
			case 2:
				printf("景安");
			break;
			case 3:
				printf("永安市場");
			break;
			case 4:
				printf("頂溪");
			break;
			case 5:
				printf("古亭");
			break;
			case 6:
				printf("東門");
			break;
			case 7:
				printf("忠孝新生");
			break;
			case 8:
				printf("松江南京");
			break;
			case 9:
				printf("行天宮");
			break;
			case 10:
				printf("中山國小");
			break;
			case 11:
				printf("民權西路");
			break;
			case 12:
				printf("大橋頭");
			break;
			case 13:
				printf("三重國小");
			break;
			case 14:
				printf("三和國中");
			break;
			case 15:
				printf("徐匯中學");
			break;	
			case 16:
				printf("三民高中");
			break;
			case 17:
				printf("蘆洲");
			break;
			case 18:
				printf("台北橋");
			break;
			case 19:
				printf("菜寮");
			break;
			case 20:
				printf("三重");
			break;
			case 21:
				printf("先嗇宮");
			break;
			case 22:
				printf("頭前庄");
			break;
			case 23:
				printf("新莊");
			break;
			case 24:
				printf("輔大");
			break;
			case 25:
				printf("丹鳳");
			break;
			case 26:
				printf("迴籠");
			break;
			default:
				printf("找不到!!");
			break;
		}
	}
	else if(color=='w'){
	  switch(Number){
			case 1:
				printf("動物園");
			break;
			case 2:
				printf("木柵");
			break;
			case 3:
				printf("萬芳社區");
			break;
			case 4:
				printf("萬芳醫院");
			break;
			case 5:
				printf("辛亥");
			break;
			case 6:
				printf("麟光");
			break;
			case 7:
				printf("六張犁");
			break;
			case 8:
				printf("科技大樓");
			break;
			case 9:
				printf("大安");
			break;
			case 10:
				printf("忠孝復興");
			break;
			case 11:
				printf("南京復興");
			break;
			case 12:
				printf("中山國中");
			break;
			case 13:
				printf("松山機場");
			break;
			case 14:
				printf("大直");
			break;
			case 15:
				printf("劍南路");
			break;	
			case 16:
				printf("西湖");
			break;
			case 17:
				printf("港墘");
			break;
			case 18:
				printf("文德");
			break;
			case 19:
				printf("內湖");
			break;
			case 20:
				printf("大湖公園");
			break;
			case 21:
				printf("葫州");
			break;
			case 22:
				printf("東湖");
			break;
			case 23:
				printf("南港軟體園區");
			break;
			case 24:
				printf("南港展覽區");
			break;
			default:
				printf("找不到!!");
			break;
		}
	}
	else if(color=='g'){
		switch(Number){
		    case 1:
				printf("松山");
			break;
			case 2:
				printf("南京三民");
			break;
			case 3:
				printf("台北小巨蛋");
			break;
			case 4:
				printf("南京復興");
			break;
			case 5:
				printf("松江南京");
			break;
			case 6:
				printf("中山");
			break;
			case 7:
				printf("北門");
			break;
			case 8:
				printf("西門");
			break;
			case 9:
				printf("小南門");
			break;
			case 10:
				printf("中正紀念堂");
			break;
			case 11:
				printf("古亭");
			break;
			case 12:
				printf("台電大樓");
			break;
			case 13:
				printf("公館");
			break;
			case 14:
				printf("萬隆");
			break;
			case 15:
				printf("景美");
			break;	
			case 16:
				printf("大坪林");
			break;
			case 17:
				printf("七張");
			break;
			case 18:
				printf("新店區公所");
			break;
			case 19:
				printf("新店");
			break;
			case 20:
				printf("小碧潭");
			break;
			default:
				printf("找不到!!");
			break;
		}
	}
}
