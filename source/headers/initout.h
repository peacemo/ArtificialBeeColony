//每次调用完函数之后，都要进行初始化
//

#include "../classes/Food.h"
//#include "head.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <sstream>
#include <algorithm>
#include <time.h>
#include <memory.h>
#include <string>
#include <random>
#include <functional>
#include <list>
using namespace std;
//判断入库堵塞队列长度
double ddj_r(int r_n){
    if(r_n % 11 == 1){
        return 610.11;
    }
    else if(r_n % 11 == 2){
        return 685.05;
    }
    else if(r_n % 11 == 3){
        return 762.21;
    }
    else if(r_n % 11 == 4){
        return 838.12;
    }
    else if(r_n % 11 == 5){
        return 871.61;
    }
    else if(r_n % 11 == 6){
        return 947.12;
    }
    else if(r_n % 11 == 7){
        return 982.30;
    }
    else if(r_n % 11 == 8){
        return 1057.17;
    }
    else if(r_n % 11 == 9){
        return 1091.41;
    }
    else if(r_n % 11 == 10){
        return 1165.13;
    }
    else if(r_n % 11 == 0){
        return 1199.48;
    }
    else{
        cout<<"ddj_r error!"<<endl;
    }

}

void enterBlock(double TI,int ddj,char flag){//flag = cargo_now[p-1].flag
    int cargo_num = 3;
    int block_num = 0;
    int i = 0;
    if(flag == 'A'){
        cargo_num = 0;
    }
    else if(flag == 'B'){
        cargo_num = 1;
    }
    else{
        cout<<"enterBlock flag error!"<<endl;
    }
    for(;i<R;i++){
        if(enter_block[ddj-1][i][cargo_num][1] < TI){
            block_num++;
        }
        else{
            break;
        }
    }
    if(block_num>5){
        enterI++;
    }
}
// void arr_block(double TI,int ddj){
// 	block = 0;
// 	int gi_n = g_number(ddj);
// 	for(int i=0;i<gi_n;i++){//循环遍历堆垛机的gp数组
// 		if(gp[ddj-1][i][1]<TI){
// 			block++;
// 		}
// 	}
// 	arr_p[gpi][0] = gpi;
// 	arr_p[gpi][1] = block;
//     arr_p[gpi][2] = ddj;
// 	arr_p[gpi][3] = TI;
// 	gpi++;
// }
//判断该编码属于哪台堆垛机
int stacker(int p){
	int ddj = 0;
	if(cargo_now[p-1].line-4==1 || cargo_now[p-1].line-4==2)		//如果货架坐标为1、2，则为堆垛机1
		ddj = 1;
	else if(cargo_now[p-1].line-4==3 || cargo_now[p-1].line-4==4)	//如果货架坐标为3、4，则为堆垛机2
		ddj = 2;
	else if(cargo_now[p-1].line-4==5 || cargo_now[p-1].line-4==6)//如果货架坐标为5、6，则为堆垛机3
		ddj = 3;
	else if(cargo_now[p-1].line-4==7 || cargo_now[p-1].line-4==8)//如果货架坐标为7、8，则为堆垛机4
		ddj = 4;
	else if(cargo_now[p-1].line-4==10 || cargo_now[p-1].line-4==9)//如果货架坐标为9、10，则为堆垛机5
		ddj = 5;
	else if(cargo_now[p-1].line-4==11 || cargo_now[p-1].line-4==12)//如果货架坐标为11、12，则为堆垛机6
		ddj = 6;
	else{
		cout<<"ddj error!"<<endl;				//如果是其他货位坐标则说明错误
		ddj = 0;
	}
	return ddj;
}
char judge_type(int p,int a);
char judge_type(int p);
//当two_falg == true 时调用此函数，使得该堆垛机编码数组的下标连续增加两个单位
void add_ddjCode(int ddj){
    if(ddj == 1){
        j_1++;
    }
    else if(ddj == 2){
        j_2++;
    }
    else if(ddj == 3){
        j_3++;
    }
    else if(ddj == 4){
        j_4++;
    }
    else if(ddj == 5){
        j_5++;
    }
    else if(ddj == 6){
        j_6++;
    }
    else{
        cout<<"add_ddjCode error!"<<endl;
    }
}
//重载该函数，two == true and type == 'H' 时调用
void add_ddjCode(int ddj,char type){
    if(type != 'H'){
        cout<<"add_ddjCode type error!"<<endl; 
    }
    if(ddj == 1){
        h1++;
        j_1++;
    }
    else if(ddj == 2){
        h2++;
        j_2++;
    }
    else if(ddj == 3){
        h3++;
        j_3++;
    }
    else if(ddj == 4){
        h4++;
        j_4++;
    }
    else if(ddj == 5){
        h5++;
        j_5++;
    }
    else if(ddj == 6){
        h6++;
        j_6++;
    }
    else{
        cout<<"add_ddjCode 'H' error!"<<endl;
    }
}

//判断资产到达的货架 1 ddj 2 'A' 'B' 货架的左或者右
void enter_xyz(int ddj,char side){
    if(ddj == 1){
        if(side == 'A'){
            enter_x = -4.21;
            enter_y = 0.71;
            enter_z = 36.52;
        }
        else if(side == 'B'){
            enter_x = -4.21;
            enter_y = 0.71;
            enter_z = 38.43;
        }
        else{
            cout<<"enter_xyz_ddj 1 error!"<<endl;
        }
    }
    else if(ddj == 2){
        if(side == 'A'){
            enter_x = -4.21;
            enter_y = 0.71;
            enter_z = 40.34;
        }
        else if(side == 'B'){
            enter_x = -4.21;
            enter_y = 0.71;
            enter_z = 42.23;
        }
        else{
            cout<<"enter_xyz_ddj 2 error!"<<endl;
        }
    }
    else if(ddj == 3){
        if(side == 'A'){
            enter_x = -4.21;
            enter_y = 0.71;
            enter_z = 43.08;
        }
        else if(side == 'B'){
            enter_x = -4.21;
            enter_y = 0.71;
            enter_z = 44.96;
        }
        else{
            cout<<"enter_xyz_ddj 3 error!"<<endl;
        }
    }
    else if(ddj == 4){
        if(side == 'A'){
            enter_x = -4.21;
            enter_y = 0.71;
            enter_z = 45.81;
        }
        else if(side == 'B'){
            enter_x = -4.21;
            enter_y = 0.71;
            enter_z = 47.69;
        }
        else{
            cout<<"enter_xyz_ddj 4 error!"<<endl;
        }
    }
    else if(ddj == 5){
        if(side == 'A'){
            enter_x = -4.21;
            enter_y = 0.71;
            enter_z = 48.54;
        }
        else if(side == 'B'){
            enter_x = -4.21;
            enter_y = 0.71;
            enter_z = 50.42;
        }
        else{
            cout<<"enter_xyz_ddj 5 error!"<<endl;
        }
    }
    else if(ddj == 6){
        if(side == 'A'){
            enter_x = -4.21;
            enter_y = 0.71;
            enter_z = 51.27;
        }
        else{
            cout<<"enter_xyz_ddj 6 error!"<<endl;
        }
    }
    else
        cout<<"enter_xyz_side error!"<<endl;
} 
//根据编码判断堆垛机入库口
void enter_xyz(int p){
    int ddj = stacker(p);
    if(ddj == 1){
        enter_x = 1902.58;
        enter_y = 0.63;
        enter_z = 37.49;
    }
    else if(ddj == 2){
        enter_x = 1902.58;
        enter_y = 0.63;
        enter_z = 41.27;
    }
    else if(ddj == 3){
        enter_x = 1902.58;
        enter_y = 0.63;
        enter_z = 44.04;
    }
    else if(ddj == 4){
        enter_x = 1902.58;
        enter_y = 0.63;
        enter_z = 46.74;
    }
    else if(ddj == 5){
        enter_x = 1902.58;
        enter_y = 0.63;
        enter_z = 49.48;
    }
    else if(ddj == 6){
        enter_x = 1902.58;
        enter_y = 0.63;
        enter_z = 52.38;
    }
    else
        cout<<"enter_xyz error!"<<endl;
}
//根据编码判断送检口
void inspect_xyz(int p){
    int ddj = stacker(p);
    if(ddj == 1){
        inspect_x = 1902.58;
        inspect_y = 6.08;
        inspect_z = 37.49;
    }
    else if(ddj == 2){
        inspect_x = 1902.58;
        inspect_y = 6.08;
        inspect_z = 41.27;
    }
    else if(ddj == 3){
        inspect_x = 1902.58;
        inspect_y = 6.08;
        inspect_z = 44.04;
    }
    else if(ddj == 4){
        inspect_x = 1902.58;
        inspect_y = 6.08;
        inspect_z = 46.74;
    }
    else if(ddj == 5){
        inspect_x = 1902.58;
        inspect_y = 6.08;
        inspect_z = 49.48;
    }
    else if(ddj == 6){
        inspect_x = 1902.58;
        inspect_y = 6.08;
        inspect_z = 52.38;
    }
    // if(cargo_now[p-1].model==0){
    //     inspect_x = 0;
    //     inspect_y = 2;
    //     inspect_z = 2;
    // }
    // else if(cargo_now[p-1].model==1){
    //     inspect_x = 0;
    //     inspect_y = 3;
    //     inspect_z = 3;
    // }
    // else if(cargo_now[p-1].model==2){
    //     inspect_x = 0;
    //     inspect_y = 4;
    //     inspect_z = 4;
    // }
    // else if(cargo_now[p-1].model==3){
    //     inspect_x = 0;
    //     inspect_y = 5;
    //     inspect_z = 5;
    // }
    // else if(cargo_now[p-1].model==4){
    //     inspect_x = 0;
    //     inspect_y = 6;
    //     inspect_z = 6;
    // }
    else
        cout<<"inspect_xyz error!"<<endl;
}
//根据编码判断回库口
void return_xyz(int p){
    int ddj = stacker(p);
    if(ddj == 1){
        return_x = 1902.58;
        return_y = 6.08;
        return_z = 37.49;
    }
    else if(ddj == 2){
        return_x = 1902.58;
        return_y = 6.08;
        return_z = 41.27;
    }
    else if(ddj == 3){
        return_x = 1902.58;
        return_y = 6.08;
        return_z = 44.04;
    }
    else if(ddj == 4){
        return_x = 1902.58;
        return_y = 6.08;
        return_z = 46.74;
    }
    else if(ddj == 5){
        return_x = 1902.58;
        return_y = 6.08;
        return_z = 49.48;
    }
    else if(ddj == 6){
        return_x = 1902.58;
        return_y = 6.08;
        return_z = 52.38;
    }
    else
        cout<<"return_xyz error!"<<endl;
}
//根据编码判断出库口
void out_xyz(int p){
    int ddj = stacker(p);
    if(ddj == 1){
        out_x = 1867.51;
        out_y = 1.35;
        out_z = 37.49;
    }
    else if(ddj == 2){
        out_x = 1867.51;
        out_y = 1.35;
        out_z = 41.29;
    }
    else if(ddj == 3){
        out_x = 1867.51;
        out_y = 1.35;
        out_z = 44.04;
    }
    else if(ddj == 4){
        out_x = 1867.51;
        out_y = 1.35;
        out_z = 46.77;
    }
    else if(ddj == 5){
        out_x = 1867.51;
        out_y = 1.35;
        out_z = 49.49;
    }
    else if(ddj == 6){
        out_x = 1867.51;
        out_y = 1.35;
        out_z = 52.29;
    }
    else{
        cout<<"out_xyz error!"<<endl;
        out_y = 1.35;
    }
        
}
//根据第三个编码的类型确定堆垛机最后一个动作要去的位置
void ddj_last(char type,int p){
    if(type == 'R'){
        enter_xyz(p);
        third_x = enter_x;
        third_y = enter_y;
        third_z = enter_z;
        //入库口
    }
    else if(type == 'S' || 'C'){
        enter_xyz(p);
        third_x = cargo_now[p-1].x + smShiftX;
        third_y = cargo_now[p-1].y;
        third_z = enter_z;
    }
    else if(type == 'H'){
        inspect_xyz(p);
        third_x = inspect_x;
        third_y = inspect_y;
        third_z = inspect_z;
        //回库口
    }
    else
        cout<<"ddj_last error!"<<endl;
}
//将出库堵塞队列长度输出到文件
void get_out_block(){
    ofstream output;
    output.open("output/out_block.txt");
    for(int i=0;i<H;i++){
        output<<i<<":"<<outbound[i][0]<<endl;
    }
    output.close();
}
//判断出库堵塞
void out_block(int out_time){//参数为出库的时间间隔，单位 秒
    int i = 1;
    int j = 0; 
    double TI = 0;
    for(i=0;i<H;i++){
        outbound[i][0] = 0;
    }
    i = 1;
    while(j!=H){
        TI += out_time;
        if(TI>=outbound[j][1]){
            outbound[j][1] = INT32_MAX;//出库一个
            for(int a = 0;a<H;a++){
                if(outbound[a][1]<TI){
                    outbound[j][0]++;
                }
            }
            j++;
        }
    }
}

//将出库数组输出到文件
void get_outbound(){
    double temp2 = 0;
    int sit = 0;
    for(int i=0;i<H;i++){
        for(int j=0;j<H-i;j++){
            if(outbound[j+1][1]<outbound[j][1]){//以时间为顺序排列
            temp2=outbound[j+1][1];
            outbound[j+1][1]=outbound[j][1];
            outbound[j][1]=temp2;

			sit = outbound[j+1][0];
            outbound[j+1][0] = outbound[j][0];
            outbound[j][0] = sit;
            }
        }
    }
    ofstream output_outbound;
    output_outbound.open("output/outbound.txt");
    for(int i=0;i<H;i++){
        output_outbound<<outbound[i][0]<<":"<<outbound[i][1]<<endl;
    }
    output_outbound.close();
}
//将送检长度数组输出到文件
void get_inspect(){
    ofstream out_inspect;
    out_inspect.open("output/inspect.txt");
    out_inspect<<"assets a inspect"<<endl;
    for(int i = 0;i<assets_a;i++){
        out_inspect<<i<<":"<<inspect_volume_a_now[i]<<endl;
    }
    out_inspect<<"*************************"<<endl;
    out_inspect<<"assets b inspect"<<endl;
    for(int i = 0;i<assets_b;i++){
        out_inspect<<i<<":"<<inspect_volume_b_now[i]<<endl;
    }
    out_inspect.close();
}
//计算送检口送检长度
void inspection_NUM(char type,int inspect_model){
    if(aa > assets_a || bb > assets_b){
        cout<<"aa || bb out"<<endl;
        type = 4;
    }
    if(type=='S'){
        switch (inspect_model)
        {
        case 0:
            if(aa!=0){
                inspect_volume_a_now[aa++] = inspect_volume_a_now[aa-1] + 1;
            }
            else{
                inspect_volume_a_now[aa++] = +1;
            }
            break;
        case 1:
            if(bb!=0){
                inspect_volume_b_now[bb++] = inspect_volume_b_now[bb-1] + 1;
            }
            else{
                inspect_volume_b_now[bb++] = +1;
            }
            break;
        default:
            cout<<"inspection_NUM error"<<endl;
            break;
        }
    }
    else if(type=='H'){
         switch (inspect_model)
        {
        case 0:
                inspect_volume_a_now[aa++] = inspect_volume_a_now[aa-1] - 1;
            break;
        case 1:
            inspect_volume_b_now[bb++] = inspect_volume_b_now[bb-1] - 1;
            break;
        default:
            cout<<"inspection_NUM error"<<endl;
            break;
        }
    }
    else{
        cout<<"inspection_NUM error"<<endl;
    }
}
//得到本周期货位，并输出货位信息到文件
void getCargo_now(string File_name1,string File_name2){
    //R:500 S:500 H:500 C:500
    //选取规则：从下往上，选取每排的堆垛机
    int j = 0,r = 0,s = 0,h = 0,c = 0;
    int s_model[S];
    for(int i=0;i<n_total;i++){
        if(cargo[i].s1 == 0 && cargo[i].s2 == 0 && r<R){
            cargo_now[j] = cargo[i];
            cargo_now[j].num = j + 1;
            j++,r++;
        }
        else if(cargo[i].s1 == 0 && cargo[i].s2 == 1 && s<S){
            cargo_now[j] = cargo[i];
            cargo_now[j].num = j + 1;
            s_model[s] = cargo_now[j].model;
            j++,s++;
        }
        else if(cargo[i].s1 == 0 && cargo[i].s2 == 0 && r==R && h<H && s==S){
            cargo_now[j] = cargo[i];
            cargo_now[j].num = j + 1;
            cargo_now[j].s1 = 1;
            cargo_now[j].model = s_model[h];
            j++,h++;
        }
        else if(cargo[i].s1 == 1 && cargo[i].s2 == 1 && c<C){
            cargo_now[j] = cargo[i];
            cargo_now[j].num = j + 1;
            j++,c++;
        }
        else if(j>NUMBER){
            cout<<"2000 over!"<<endl;
            break;
        }
    }
    ofstream out1;
    ofstream out_sit;
    out1.open(File_name1);
    out_sit.open(File_name2);
    for(int i=0;i<CODELENGTH;i++){
        out1<<"{"<<cargo_now[i].x<<","<<cargo_now[i].y<<","<<cargo_now[i].z<<","<<cargo_now[i].s1<<","<<cargo_now[i].s2<<","<<cargo_now[i].num<<","
        <<cargo_now[i].model<<","<<cargo_now[i].time<<","<<"\'"<<cargo_now[i].flag<<"\'"<<","<<cargo_now[i].line<<","<<cargo_now[i].row<<","<<cargo_now[i].column<<","<<"\""<<cargo_now[i].id<<"\""<<"}"<<",";
        out_sit<<cargo_now[i].line<<","<<cargo_now[i].column<<","<<cargo_now[i].row<<","<<judge_type(i)<<endl;
        if((i+1)%5==0){
            out1<<endl;
        }
    }
    out1.close();
    out_sit.close();
}
//将cargo货位输出到文件
void getCargo(string file_name1,string file_name2){
    ofstream outf,outd;
    outf.open(file_name1);
    outd.open(file_name2);
    for(int i=0;i<n_total;i++){
        outf<<"{"<<cargo[i].x<<","<<cargo[i].y<<","<<cargo[i].z<<","<<cargo[i].s1<<","<<cargo[i].s2<<","<<cargo[i].num<<","<<"0"<<","<<cargo[i].model<<","<<cargo[i].time<<"}"<<",";
        outd<<cargo[i].x<<","<<cargo[i].y<<","<<cargo[i].z<<","<<judge_type(i,1)<<endl;
        if((i+1)%5==0){
            outf<<endl;
        }
    }
    outf.close();
    outd.close();
}

/*!
 * 初始化货位
 * @param N 货位数量
 * @param r 入库货位所在的列 pre~r
 * @param s 送检货位所在的列 pre~s
 * @param h 回库货位所在的列 pre~h
 * @param c 出库货位所在的列 pre~c
 */
void startCargo(int N,int r,int s,int h,int c){//货位数量,入库、送检、回库、出库
    int point_x = 1,point_y = 1,point_z = 1;
    for(int i=0;i<N;i++){
        cargo[i].x = point_x;
        cargo[i].y = point_y;
        cargo[i].z = point_z;
        cargo[i].time = 20211220;
        cargo[i].model = 0;
        //cargo[i].model = 1;
        cargo[i].num = i + 1;
        point_z++;
        if(point_x>12){
            point_x = point_x % 12;
        }
        if(point_y>52){
            point_y = point_y % 52;
            point_x++;
        }
        if(point_z>26){
            point_z = point_z %26;
            point_y++;
        }
    }
    for(int i=0;i<N;i++){
        if((cargo[i].y >= 1) && (r >= cargo[i].y)){ // 对所有货位进行分块
            cargo[i].s1 = 0;
            cargo[i].s2 = 0;
        }
        else if((cargo[i].y >= r) && (s >= cargo[i].y)){
            cargo[i].s1 = 0;
            cargo[i].s2 = 1;
        }
        else if((cargo[i].y >= s) && (h >= cargo[i].y)){
            cargo[i].s1 = 1;
            cargo[i].s2 = 0;
        }
        else if((cargo[i].y >= h) && (c >= cargo[i].y)){
            cargo[i].s1 = 1;
            cargo[i].s2 = 1;
        }
    }
}

//候选集
void candidate(){
    int r=0,s=0,h=0,c=0;
    for(int i=0;i<n_total;i++){
        if(cargo[i].s1 == 0){
            if(cargo[i].s2 == 0){//00:入库
                G_r[r++] = cargo[i];
            }
            else if(cargo[i].s2 == 1){//01：送检
                G_s[s++] = cargo[i];
            }
        }
        else if(cargo[i].s1 == 1){
            if(cargo[i].s2 == 0){//10:入库
                G_h[h++] = cargo[i];
            }
            else if(cargo[i].s2 == 1){//11：送检
                G_c[c++] = cargo[i];
            }
        }
    }
}

//输出候选集到文件
void getCandidate(){
    ofstream out;
    out.open("output/candidate.txt");
    for(int i=0;i<candidate_num;i++){
        out<<"{"<<G_r[i].x<<","<<G_r[i].y<<","<<G_r[i].z<<","<<G_r[i].s1<<","<<G_r[i].s2<<","<<G_r[i].num<<","<<"0"<<","<<G_r[i].model<<","<<G_r[i].time<<"}"<<",";
        if((i+1)%5==0){
            out<<endl;
        }
    }
    out<<endl;
    for(int i=0;i<candidate_num;i++){
        out<<"{"<<G_s[i].x<<","<<G_s[i].y<<","<<G_s[i].z<<","<<G_s[i].s1<<","<<G_s[i].s2<<","<<G_s[i].num<<","<<"0"<<","<<G_s[i].model<<","<<G_s[i].time<<"}"<<",";
        if((i+1)%5==0){
            out<<endl;
        }
    }
    out<<endl;
    for(int i=0;i<candidate_num;i++){
        out<<"{"<<G_h[i].x<<","<<G_h[i].y<<","<<G_h[i].z<<","<<G_h[i].s1<<","<<G_h[i].s2<<","<<G_h[i].num<<","<<"0"<<","<<G_h[i].model<<","<<G_h[i].time<<"}"<<",";
        if((i+1)%5==0){
            out<<endl;
        }
    }
    out<<endl;
    for(int i=0;i<candidate_num;i++){
        out<<"{"<<G_c[i].x<<","<<G_c[i].y<<","<<G_c[i].z<<","<<G_c[i].s1<<","<<G_c[i].s2<<","<<G_c[i].num<<","<<"0"<<","<<G_c[i].model<<","<<G_c[i].time<<"}"<<",";
        if((i+1)%5==0){
            out<<endl;
        }
    }
}

// 根据到库时间，对候选集内的资产进行排序
void selectCargo(int day){//参数为天数
    bool flag = true;
    int count = 0;//计数
    int q = -1;//天数增量
    int cargo_now_i = 0;
    for(int i=0;i<R;i++){
        cargo_now[cargo_now_i++] = G_r[i];
    }

    while (flag){
        if(count == S){
            flag = false;
            continue;
        }
        else{
            q++;
            for(int i=0;i<candidate_num && count<S;i++){
                if(G_s[i].time == day + q){
                    count++;
                    cargo_now[cargo_now_i++] = G_s[i];
                }
            }
        }
    }
    for(int i=0;i<H;i++){
        cargo_now[cargo_now_i++] = G_h[i];
    }
    count = 0,q = -1,flag = true;;
    while (flag){
        if(count == C){
            flag = false;
            continue;
        }
        else{
            q++;
            for(int i=0;i<candidate_num && count<C;i++){
                if(G_c[i].time == day + q){
                    count++;
                    cargo_now[cargo_now_i++] = G_c[i];
                }
            }
        }
    }
}

//更新货位信息
void updateCargo(){
    for(int i=0;i<CODELENGTH;i++){
        if((cargo_now[i].s1==0) && (cargo_now[i].s2 ==0)){//入库变送检
            cargo[cargo_now[i].num-1].s1 = 0;
            cargo[cargo_now[i].num-1].s2 = 1;
            cargo[cargo_now[i].num-1].time++;
        }
        else if((cargo_now[i].s1==0) && (cargo_now[i].s2 ==1)){//送检变回库
            cargo[cargo_now[i].num-1].s1 = 1;
            cargo[cargo_now[i].num-1].s2 = 0;
        }
        else if((cargo_now[i].s1==1) && (cargo_now[i].s2 ==0)){//回库变出库
            cargo[cargo_now[i].num-1].s1 = 1;
            cargo[cargo_now[i].num-1].s2 = 1;
            cargo[cargo_now[i].num-1].time++;
        }
        else if((cargo_now[i].s1==1) && (cargo_now[i].s2 ==1)){//出库变入库
            cargo[cargo_now[i].num-1].s1 = 0;
            cargo[cargo_now[i].num-1].s2 = 0;
        }
    }
}
//货架分配规则
void cargoRule(string first,string second,string third,string fourth){
    int s11 = 0, s12 = 0,s21 = 0,s22 = 0,s31 = 0,s32 = 0,s41 = 0,s42 = 0;
    if(first == "R"){
        s11 = 0;
        s12 = 0;
    }
    else if(first == "S"){
        s21 = 0;
        s22 = 1;
    }
    else if(first == "H"){
        s31 = 1;
        s32 = 0;
    }
    else if(first == "C"){
        s41 = 1;
        s42 = 1;
    }
    if(second=="R"){
        s11 = 0;
        s12 = 0;
    }
    else if(second == "S"){
        s21 = 0;
        s22 = 1;
    }
    else if(second == "H"){
        s31 = 1;
        s32 = 0;
    }
    else if(second == "C"){
        s41 = 1;
        s42 = 1;
    }
    if(third=="R"){
        s11 = 0;
        s12 = 0;
    }
    else if(third == "S"){
        s21 = 0;
        s22 = 1;
    }
    else if(third == "H"){
        s31 = 1;
        s32 = 0;
    }
    else if(third == "C"){
        s41 = 1;
        s42 = 1;
    }
    if(fourth=="R"){
        s11 = 0;
        s12 = 0;
    }
    else if(fourth == "S"){
        s21 = 0;
        s22 = 1;
    }
    else if(fourth == "H"){
        s31 = 1;
        s32 = 0;
    }
    else if(fourth == "C"){
        s41 = 1;
        s42 = 1;
    }

    for(int i=0;i<n_total;i++){
        if(cargo[i].z<=4){
            cargo[i].s1 = s11;
            cargo[i].s2 = s12;
        }
        else if(cargo[i].z<=8 && cargo[i].z>4){
            cargo[i].s1 = s21;
            cargo[i].s2 = s22;
        }
        else if(cargo[i].z<=12 && cargo[i].z>8){
            cargo[i].s1 = s31;
            cargo[i].s2 = s32;
        }
        else if(cargo[i].z<=16 && cargo[i].z>12){
            cargo[i].s1 = s41;
            cargo[i].s2 = s42;
        }
        else if(cargo[i].z == 17 || cargo[i].z == 21 || cargo[i].z == 25){
            cargo[i].s1 = s11;
            cargo[i].s2 = s12;
        }
        else if(cargo[i].z == 18 || cargo[i].z == 22 || cargo[i].z == 26){
            cargo[i].s1 = s21;
            cargo[i].s2 = s22;
        }
        else if(cargo[i].z == 19 || cargo[i].z == 23){
            cargo[i].s1 = s31;
            cargo[i].s2 = s32;
        }
        else if(cargo[i].z == 20 || cargo[i].z == 24){
            cargo[i].s1 = s41;
            cargo[i].s2 = s42;
        }
    }
}

//根据堵塞队列的长度和超过规定最大容量所出现次数，对适应度值进行一定程度的惩罚
void punish(){
	block_long = 0,block_times = 0;
	int temp2,sit;
	//遍历数组，找到最大堵塞队列长度，并计算超出次数。
	for(int i=0;i<CODELENGTH;i++){
        for(int j=0;j<CODELENGTH-i;j++){
            if(arr_p[j+1][1]>arr_p[j][1]){//以时间为顺序排列
            temp2=arr_p[j+1][1];
            arr_p[j+1][1]=arr_p[j][1];
            arr_p[j][1]=temp2;

			sit = arr_p[j+1][0];
            arr_p[j+1][0] = arr_p[j][0];
            arr_p[j][0] = sit;

            // ddj = arr_p[j+1][2];
            // arr_p[j+1][2] = arr_p[j][2];
            // arr_p[j][2] = ddj;

			// TT = arr_p[j+1][3];
            // arr_p[j+1][3] = arr_p[j][3];
            // arr_p[j][3] = TT;
            }
        }
	}
	if(arr_p[0][1]>r_volume){
		block_long = arr_p[0][1] - r_volume;
	}
	else{
		block_long = 0;
	}
	for(int i=0;i<CODELENGTH;i++){
		if(arr_p[i][1]>r_volume){
			block_times++;
		}
	}
}

//由堆垛机序号判断堆垛机处理货物数量
int g_number(int ddj){
	switch (ddj)
	{
	case 1:
		return g1_r;
		break;
	case 2:
		return g2_r;
		break;
	case 3:
		return g3_r;
		break;
	case 4:
		return g4_r;
		break;
	case 5:
		return g5_r;
		break;
	case 6:
		return g6_r;
		break;
    case 7:
		return g7_r;
		break; 
    case 8:
		return g8_r;
		break;   
	default:
		cout<<"g_number error!"<<endl;
		break;
		return -1;
	}
    cout<<"g_number error!"<<endl;
    return -1;
}
//判断堵塞
void arr_block(double TI,int ddj){
	block = 0;
	int gi_n = g_number(ddj);
	for(int i=0;i<gi_n;i++){//循环遍历堆垛机的gp数组
		if(gp[ddj-1][i][1]<TI){
			block++;
		}
	}
	arr_p[gpi][0] = gpi;
	arr_p[gpi][1] = block;
    arr_p[gpi][2] = ddj;
	arr_p[gpi][3] = TI;
	gpi++;
}

//快速排序
//选择基准（轴）
int partition(double array[][2], int low, int high)
{
    while (low < high)
    {
        //low位置为轴点，low右边的不小于low左边的
        while (low < high&&array[low][1] <= array[high][1])
        {
            high--;
        }
        double temp = array[low][1];
        array[low][1] = array[high][1];
        array[high][1] = temp;

        temp = array[low][0];
        array[low][0] = array[high][0];
        array[high][0] = temp;
        //high位置为轴点，high左边的不大于high右边的
        while (low < high&&array[low][1] <= array[high][1])
        {
            low++;
        }
        temp = array[low][1];
        array[low][1] = array[high][1];
        array[high][1] = temp;

        temp = array[low][0];
        array[low][0] = array[high][0];
        array[high][0] = temp;
    }
    return low;
}
//快速排序
void quickSortHelp(double array[][2], int low, int high)
{
    if (low < high)
    {
        //找枢轴元位置
        int location = partition(array, low, high);
        //递归调用
        quickSortHelp(array, low, location - 1);
        quickSortHelp(array, location + 1, high);
    }
}
//快速排序
void quickSort(double array[][2], int sort_n)
{
    //以第一个数组元素为基准（轴）
    quickSortHelp(array, 0, sort_n - 1);
}
//根据编码判断资产型号
int judge_model(int p){
    if(cargo_now[p - 1].model>4){
        cout<<p<<" "<<cargo_now[p - 1].model<<endl;
        cout<<"judge_model error!"<<endl;
    }
    return cargo_now[p-1].model;
}
//判断货物类型
char judge_type(int p){
	if(cargo_now[p-1].s1==0 && cargo_now[p-1].s2==0)
		return 'R';
	else if(cargo_now[p-1].s1==0 && cargo_now[p-1].s2==1)
		return 'S';
	else if(cargo_now[p-1].s1==1 && cargo_now[p-1].s2==0)
		return 'H';
	else if(cargo_now[p-1].s1==1 && cargo_now[p-1].s2==1)
		return 'C';
	else{
		cout<<"judge_type error!"<<endl;
		cout<<p<<endl;
		return 'C';
	}
}
char judge_type(int p,int a){
	if(cargo[p-1].s1==0 && cargo[p-1].s2==0)
		return 'R';
	else if(cargo[p-1].s1==0 && cargo[p-1].s2==1)
		return 'S';
	else if(cargo[p-1].s1==1 && cargo[p-1].s2==0)
		return 'H';
	else if(cargo[p-1].s1==1 && cargo[p-1].s2==1)
		return 'C';
	else{
		cout<<"judge_type error!"<<endl;
		cout<<p<<endl;
		return 'C';
	}
}
//交换货位坐标
void CS_swap(){
	srand((double)clock());
	for(int i=0; i < CODELENGTH / 2; i++){
		int sit = rand()%(CODELENGTH - 1);
		int temp_x=0,temp_y=0,temp_z=0;
		temp_x = cargo_now[i].x;
		temp_y = cargo_now[i].y;
		temp_z = cargo_now[i].z;
		cargo_now[i].x = cargo_now[sit].x;
		cargo_now[i].y = cargo_now[sit].y;
		cargo_now[i].z = cargo_now[sit].z;
		cargo_now[sit].x = temp_x;
		cargo_now[sit].y = temp_y;
		cargo_now[sit].z = temp_z;
	}
	ofstream out1;
	ofstream out_sit;
	out1.open("rand_2000_1.txt");
	out_sit.open("rand_2000_1_sit.txt");
	for(int i=0; i < CODELENGTH; i++){
		out1<<"{"<<cargo_now[i].x<<","<<cargo_now[i].y<<","<<cargo_now[i].z<<","<<cargo_now[i].s1<<","<<cargo_now[i].s2<<","<<cargo_now[i].num<<","<<"0"<<","<<cargo_now[i].model<<","<<cargo_now[i].time<<"}"<<",";
		out_sit<<cargo_now[i].x<<","<<cargo_now[i].y<<","<<cargo_now[i].z<<","<<judge_type(i)<<endl;
		if((i+1)%5==0){
			out1<<endl;	
		}
	}
	out1.close();
	out_sit.close();
}

//入库仿真
//获得入库编码
// void get_R(int g[]){
// 	int j=0;
// 	for(int i=0; i < CODELENGTH; i++){
// 		if(g[i]<=R && j<R){//遍历数组，如果数组编码小于R，则说明为回库编码
// 			r_arry[j] = g[i];
// 			j++;
// 		}
// 	}
// }
void get_R(int g[]){
	int j=0;
	for(int i=0; i < CODELENGTH; i++){
		if(cargo_now[g[i]-1].s1 == 0 && cargo_now[g[i]-1].s2 == 0){//遍历数组，如果数组编码小于R，则说明为回库编码
			r_arry[j] = g[i];
            //r[j] = g[i];
			j++;
		}
	}
}
//货物从上货点到叠箱机的时间
void getT_load(int i,char type){
	//int n_load1 = R_n/fre; //从上货点1发出的货物数量 fre为每秒中一共出货的总数量
	//int n_load2 = R_n - n_load1;//从上货点2发出的货物数量 
		//判断是否从上货点2发出:
		//1: fre1 + t_load1
		//2: fre2 + t_load2
		//3: fre1*2 + t_load1
		//4: fre2*2 + t_load2
		//5: fre1*3 + t_load1
		//6: fre2*3 + t_load2
    ofstream loadPointTask,crossTask;
    loadPointTask.open("output/loadPointTask.txt",ios::app);
    crossTask.open("output/crossTask.txt",ios::app);
    if(i%2==0){
        t_R = fre2*(i/2);//上货点2发出
        enter_box_2++,temp_p++;
        
        //cout<<t_R<<"，上货点2发出一箱">>endl;
        //t_R为发出一箱时长
        init_json();
        lpt[1].taskNumber = 1;
        runTime = t_R;
        creat_json_file();

        // init_json();
        // runTime = t_R + 0.1;
        // creat_json_file();
        
        t_R = t_R + 68.23 + 120 + 111.28;
        //上货点2 -> 第一个交通点
        //到第一个交通点的时间
        //runTime = t_R + traffic_point[0].upPoint[1].runtime;

        //tp[0][tp_1] =  t_R + traffic_point[0].upPoint[1].runtime;


        //crossTask<<taskNum++<<","<<"["<<
        //cout<<t_R + traffic_point[0].upPoint[1].runtime<<""
        //tp_1++;
    }
    else{
        t_R = fre1*((i+1)/2) + 17.5;//上货点1发出
        enter_box_1++,temp_p++;
        //上货点1 发货
        init_json();
        lpt[0].taskNumber = 1;
        runTime = t_R;
        creat_json_file();

        // init_json();
        // runTime = t_R + 0.1;
        // creat_json_file();

        t_R = t_R + 621.9 + 120 + 111.28;

        //上货点1 -> 第一个交通点
        //到第一个交通点的时间
        // tp[0][tp_1] = t_R + traffic_point[0].upPoint[0].runtime;
        // tp_1++;
    }

    //叠箱机
    // init_json();
    // runTime = t_R + 120 + 111.28;
    // fm[0].currentTaskIndex = temp_p - 1;
    // fm[0].taskNumber = 1;
    // creat_json_file();


    //temp_p++;
    if(type=='A'){//如果属于A类型 3箱成一垛  
        if(temp_p==a_num){
            temp_p = 0;
            flag_R++;//发送一垛
            send_t = t_R + ddj_r(rNum);//发送时间
            rNum++;

        }
    }
    else{
        if(temp_p==b_num){//B类型，5箱一垛
            temp_p = 0;
            flag_R++;//发送一垛
            send_t = t_R + + ddj_r(rNum);
            rNum++;
        }
    }
}       
//传入堆垛机的序号，返回到该堆垛机的时间
double getT(int ddj){
	switch(ddj){		//根据到不同堆垛机的距离，计算出到达堆垛机的时间
		case 1:
			return r_ji1/v_R;
		case 2:
			return r_ji2/v_R;
		case 3:
			return r_ji3/v_R;
		case 4:
			return r_ji4/v_R;
		case 5:
			return r_ji5/v_R;
		case 6:
			return r_ji6/v_R;
		default:return 0;
	}
}
//计算入库
void R_Test(int r[]){
	int an=0;
	int ddj;
    int p1=0,p2=0,p3=0,p4=0,p5=0,p6=0;
    int nums = 1,send_num = 1;
    char cargo_flag = 'C';//货架左右排 'A' 或者 'B'
    ofstream write_send,write_get;
	write_get.open("output/r_get.txt");//表示你要把内容输出到“text.txt"这个文件里 如果没有这个文件，会自动创建这个文件
    write_send.open("output/r_send.txt");
	int p_R = 0;//入库编码下标
    flag_R = 0;//是否成功发送一垛
	for(int i =1;i<=R_n;i++){
        if(enter_box_1==1500 || enter_box_2 == 1500){
            break;
        }
		if(p_R>R)	//	防止出现数组访问越界
			break;
		if(an>R)	//	防止出现数组访问越界
			break;
        // if(nums<num_A+1)
        // {
        //     getT_load(i,'A');//按照上货箱数的编号，从1~R_n开始上货物，类型A    
        //     nums++;
        // }
        // else if (nums<num_B+1)
        // {
        //     getT_load(I,'B');//类型B
        //     nums++;
        // }
        getT_load(i,'A');//按照上货箱数的编号，从1~R_n开始上货物，类型A、

        if(flag_R==1 && p_R<R){//集齐1垛 开始计算到达堆垛机入口的时间
			flag_R = 0;	//将标记归0
            cargo_flag = 'C';
            ddj = stacker(r_arry[p_R]);//根据入库编码，计算出堆垛机序号
            cargo_flag = cargo_now[r_arry[p_R]-1].flag;
			p_R++;
            get_t = send_t;//计算到达时间 = 发送时间+到达堆垛机的时间
			//cout<<"get_t:"<<get_t<<endl;
            if(ddj==1){//判断是否属于堆垛机1
                //cout<<"The ddj is "<<ddj<<"\tThe num "<<p_R<<"\tstack arrive ddj time is "<<get_t<<endl;
                //write<<"The ddj is "<<ddj<<"\tThe num "<<p_R<<"\tstack arrive ddj time is "<<get_t<<endl;
                    //cout<<1<<endl;
                a[an] = get_t;//写入数组a中
                an++;
                if(cargo_flag == 'A'){
                    enter_block[0][p1][0][1] = get_t; 
                }
                else if(cargo_flag == 'B'){
                    enter_block[0][p1][1][1] = get_t;
                }
                else{
                    cout<<"cargo_flag error!"<<endl;
                }
                //gp[0][p1][1] = get_t;//同时写入数组gp中
                p1++;
                write_send<<send_num<<" from dxj, send duo ,to ddj: "<<ddj<<" send time "<<send_t<<endl;//将发送一垛的时间记录在文件中
                write_get<<an<<" "<<get_t<<endl;
                get_t = 0;//将到达时间变量归0
                continue;//提高程序效率，不再进行下面的判断
            }
            if(ddj==2){
                a[an] = get_t;
                an++;
                if(cargo_flag == 'A'){
                    enter_block[1][p2][0][1] = get_t; 
                }
                else if(cargo_flag == 'B'){
                    enter_block[1][p2][1][1] = get_t;
                }
                else{
                    cout<<"cargo_flag error!"<<endl;
                }
                //gp[1][p2][1] = get_t;
                p2++;
                write_send<<send_num<<" from dxj, send duo ,to ddj: "<<ddj<<" send time "<<send_t<<endl;//将发送一垛的时间记录在文件中
                write_get<<an<<" "<<get_t<<endl;
                get_t = 0;
                continue;
            }
            if(ddj==3){
                a[an] = get_t;
                an++;
                if(cargo_flag == 'A'){
                    enter_block[2][p3][0][1] = get_t; 
                }
                else if(cargo_flag == 'B'){
                    enter_block[2][p3][1][1] = get_t;
                }
                else{
                    cout<<"cargo_flag error!"<<endl;
                }
                //gp[2][p3][1] = get_t;
                p3++;
                write_send<<send_num<<" from dxj, send duo ,to ddj: "<<ddj<<" send time "<<send_t<<endl;//将发送一垛的时间记录在文件中
                write_get<<an<<" "<<get_t<<endl;
                get_t = 0;
                continue;
            }
            if(ddj==4){
                a[an] = get_t;
                an++;
                if(cargo_flag == 'A'){
                    enter_block[3][p4][0][1] = get_t; 
                }
                else if(cargo_flag == 'B'){
                    enter_block[3][p4][1][1] = get_t;
                }
                else{
                    cout<<"cargo_flag error!"<<endl;
                }
                //gp[3][p4][1] = get_t;
                p4++;
                write_send<<send_num<<" from dxj, send duo ,to ddj: "<<ddj<<" send time "<<send_t<<endl;//将发送一垛的时间记录在文件中
                write_get<<an<<" "<<get_t<<endl;
                get_t = 0;
                continue;
            }
            if(ddj==5){
                a[an] = get_t;
                an++;
                if(cargo_flag == 'A'){
                    enter_block[4][p5][0][1] = get_t; 
                }
                else if(cargo_flag == 'B'){
                    enter_block[4][p5][1][1] = get_t;
                }
                else{
                    cout<<"cargo_flag error!"<<endl;
                }
                //gp[4][p5][1] = get_t;
                p5++;
                write_send<<send_num<<" from dxj, send duo ,to ddj: "<<ddj<<" send time "<<send_t<<endl;//将发送一垛的时间记录在文件中
                write_get<<an<<" "<<get_t<<endl;
                get_t = 0;
                continue;
            }
            if(ddj==6){
                a[an] = get_t;
                an++;
                if(cargo_flag == 'A'){
                    enter_block[5][p6][0][1] = get_t; 
                }
                else if(cargo_flag == 'B'){
                    enter_block[5][p6][1][1] = get_t;
                }
                else{
                    cout<<"cargo_flag error!"<<endl;
                }
                //gp[5][p6][1] = get_t;
                p6++;
                write_send<<send_num<<" from dxj, send duo ,to ddj: "<<ddj<<" send time "<<send_t<<endl;//将发送一垛的时间记录在文件中
                write_get<<an<<" "<<get_t<<endl;
                get_t = 0;
                continue;
            }
        }
    }
	write_get.close(); // 输出完毕后关闭这个文件
    write_send.close();
}

//随机序列，G为编码数组,len为编码数组长度
void randomArr(int G[],int len){    
    for(int i=0;i<len;i++){
        int sit = rand()%(len-1) +1;//随机位置
        int temp =G[i];		//交换当前位置的编码和随机位置的编码
        G[i] = G[sit];
        G[sit] = temp;
        //cout<<sit<<endl;
    }
}
//检定时间
void inspect(char type_inspect){//输入货物类型
            switch(type_inspect){//根据不同货物类型，计算不同的检定时间
                case 0:
                    t_inspect = t_inspect_a * s_h;  //将a的检定时间（小时）换算成秒 赋值给 检定时间
                    inspect_z = 2;
                    break;
                case 1:
                    t_inspect = t_inspect_b * s_h;
                    inspect_z = 3;
                    break;
                case 2:
                    t_inspect = t_inspect_c * s_h;
                    inspect_z = 4;
                    break;
                case 3:
                    t_inspect = t_inspect_d * s_h;
                    inspect_z = 5;
                    break;
                case 4: 
                    t_inspect = t_inspect_e * s_h;
                    inspect_z = 6;
                    break;
                case 'f':
                    t_inspect = t_inspect_f * s_h;
                    inspect_z = 7;
                    break;    
                default:
                cout<<"t_inspect error!"<<endl;
                t_inspect = 0;
                break;
            }
}
//行走时间
double Walk_time(int x,int y){//输入 x、y坐标
    float v1 = 0.5;//堆垛机垂直移动速度
    float v2 = 10;//堆垛机水平移动速度
    float l = 2;//垛 长度
    float h = 1.5;//货架的一个高
    float d = 0.2;//货位间的距离
    int Xn = x;//x坐标
    int Yn = y;//y坐标
    float High_In = 0;//垂直移动的距离
    float Long_In = 0;//水平移动的距离
    float time_in_high = 0;//垂直移动的时间
    float time_in_long = 0;//水平移动的时间
    float time_in_run = 0;//堆垛机移动的时间
    float time = 0;//堆垛机移动的时间（多设置一个变量，用于后续测试）
    High_In = Yn * h;//计算垂直移动的距离
    Long_In = Xn * (l + d);//计算水平移动的距离
    time_in_high = High_In / v1;//计算垂直移动的时间
    time_in_long = Long_In / v2;//计算水平移动的时间
    time_in_run = max(time_in_high,time_in_long);//堆垛机垂直运动的时间与堆垛机水平移动的时间 两者最长的时间即为堆垛机的移动时间
    time = time_in_run;//赋值给time
    return time_in_run;//返回堆垛机运动的时间
}
//插入，目前没有用到
void insert_G(int G[],int sit,int value){  //插入 ，在某个数组中插入一个元素，输入数组，插入的元素，和插入的位置。目前此函数没有用到
    len++;
    int *a_n = new int[len];
    for(int i = 0;i<sit;i++)
        a_n[i] = G[i];
    a_n[sit] = value;
    for(int i = sit+1;i<len;i++)
        a_n[i] = G[i-1];
    for(int i=0;i<len;i++)
        G[i] = a_n[i];
    delete []a_n;
}
//送检前h-k个编码，回库后h-k个编码，形成1-1对应关系。
void S_H2(int G[]){//输入编码数组
    int j = 0,p=0;
    for(int i=0; i < CODELENGTH; i++){//遍历编码数组
        if(cargo_now[G[i]-1].s1==0 && cargo_now[G[i]-1].s2==1 && G[i]>=R+1 && G[i]<= R + H - _k){//按照编码的顺序，判断编码是否属于 送检编码,且该送检编码属于前H-K
			s[j] = G[i];//将该编码写入到送检数组中
			INum[j][0] = i;
			j++;//送检数组下标自增1
		}
		else if(cargo_now[G[i]-1].s1==1 && cargo_now[G[i]-1].s2==0 && G[i]>= R + S + _k + 1 && G[i] <= R + S + H){//按照编码顺序，判断编码是否属于回库编码，且回库编码属于后H-_k
			h[p] = G[i];//将该编码写入到回库编码
			INum[p][1] = i;
			p++;//回库数组下标自增1
		}
    }	
	for(int i=0;i< H - _k; i++){
		I[i][0] = s[i];
		I[i][1] = h[i];
	}		
}
// todo 重载 S_H()
void S_H(Food f){//该函数与S_H2的功能一致，但输入的是一个种群
    int j = 0,p=0;
    for(int i=0; i < CODELENGTH; i++){
        // todo error: SIGSEGV (Segmentation fault)
        if(cargo_now[f.getSequence(i)-1].s1==0 && cargo_now[f.getSequence(i)-1].s2==1){
            s[j] = f.getSequence(i);
            INum[j][0] = i;
            j++;
        }
        else if(cargo_now[f.getSequence(i)-1].s1==1 && cargo_now[f.getSequence(i)-1].s2==0){
            h[p] = f.getSequence(i);
            INum[p][1] = i;
            p++;
        }
    }
    for(int i=0;i< H - _k; i++){
        I[i][0] = s[i];
        I[i][1] = h[i];
    }
}
//判断S编码与对应的回库编码在G[CODELENGTH]的前后关系，如果 H编码位于对应的送检编码之前，交换两者位置，保证S编码始终位于与其相对应的H编码之前。
// void check(int G[],int s[],int h[]){
//     int temp = 0;
//     int l = 0;//送检编码数组下标
//     for(int i=0;i<CODELENGTH;i++){
//         if(R+1<=G[i] && R+H-_k>=G[i]){//在G[]中，如果该元素属于到送检元素
//             for(;l<H-_k;l++){  //在s中确定该元素下标
//                 if(s[l]==G[i]){	//在G编码数组中找到送检编码
// 					for(int j=0;j<CODELENGTH;j++){   // 在G[CODELENGTH]找到与s[l]对应的h[l]  下标均为l
// 						if(G[j]==h[l]){
// 							if(i>j){        //如果h位于s之前，交换位置。
// 								temp = G[j];
// 								G[j] = G[i];
// 								G[i] = temp;
// 							}
// 							break;//已找到回库编码，跳出循环
// 						}
// 					}
// 					break;//继续检测第二个送检编码
// 				}
// 			}
//         }
//     }
// }
//判断S编码与对应的回库编码在G[CODELENGTH]的前后关系，如果 H编码位于对应的送检编码之前，交换两者位置，保证S编码始终位于与其相对应的H编码之前。
void check(int G[],int s[],int h[]){
	int i=0,temp=0;
	for(int j=0;j< H - _k; j++){
		if(INum[j][0]>INum[j][1]){//需要交换
			temp = G[INum[j][0]];
			G[INum[j][0]] = G[INum[j][1]];
			G[INum[j][1]] = temp;
		}
	}	
}
//读码函数
double read(double TI,double TDI,int p,int second_p,int third_p){
    char type,second_type,third_type;//当前编码的货物类型，下一个编码的货物类型
	int ddj=0;//堆垛机序号
    int ddj_1  = 0,ddj_2 = 0;
	int first_i = 0,second_i = 0;
    double wait_time = 0;//等待时间
    double grab_time = 20;//取货时间
    double walk_time1 = 0;//行走时间1
    double place_time = 20;//放货时间
    double walk_time2 = 0;//行走时间2
    double walk_time3 = 0;//行走时间3
    double walk_time4 = 0;//行走时间4
	bool flag = false;
    bool two_flag = false;
    bool same_flag = false;
	int gi_n = 0,i = 0;
    //临时坐标数据，无实际含义
    double temp_x = 0,temp_y = 0,temp_z = 0;
    //堆垛机第一次要去的坐标
    double first_x = 0,first_y = 0,first_z = 0;
    //如果取两垛资产，堆垛机第二次要去的坐标
    double second_x = 0,second_y = 0,second_z = 0;
    //堆垛机在完成前两次任务后，第三次要去的坐标
    //int third_x = 0,third_y = 0,third_z = 0; 已作为全局变量出现
    //堆垛机在完成任务后，第四次要去的坐标
    double fourth_x = 0,fourth_y = 0,fourth_z = 0;
	//判断当前读取的编码属于哪种编码类型：R、S、H、C
    //第一个编码和第二个编码的左右排货架
    int first_flag = 0,second_flag = 0;
    type = judge_type(p);
    second_type = judge_type(second_p);
    third_p = judge_type(third_p);
    ddj = stacker(p);
    //判断 p 与 second_p ，这两相邻编码是否属于同种类型
    if (type == second_type){
        two_flag = true;
        //属于同种类型
        ddj_last(third_type,third_p);

        if(type == 'R'){
             //表示两相邻的编码为同种编码,堆垛机取两垛货物
            first_x = cargo_now[p-1].x;
            first_y = cargo_now[p-1].y;
            first_z = cargo_now[p-1].z;
            
            second_x = cargo_now[second_p-1].x;
            second_y = cargo_now[second_p-1].y;
            second_z = cargo_now[second_p-1].z;
        }

        else if(type == 'S'){
            //获取当前编码的送检口
            inspect_xyz(p);
            temp_x = inspect_x;
            temp_y = inspect_y;
            temp_z = inspect_z;
            //获取下一个编码的送检口
            inspect_xyz(second_p);
            //判断两个相邻编码的送检口是否相同
            if(temp_x == inspect_x && temp_y == inspect_y && temp_z == inspect_z){
                //相同
                same_flag = true;
                first_x = cargo_now[second_p-1].x;
                first_y = cargo_now[second_p-1].y;
                first_z = cargo_now[second_p-1].z;

                second_x = inspect_x;
                second_y = inspect_y;
                second_z = inspect_z;
            }
            else{
                //送检口不同
                inspect_xyz(p);

                first_x = cargo_now[second_p-1].x;
                first_y = cargo_now[second_p-1].y;
                first_z = cargo_now[second_p-1].z;

                second_x = inspect_x;
                second_y = inspect_y;
                second_z = inspect_z;

                ddj_last(third_type,third_p);

                fourth_x = third_x;
                fourth_y = third_y;
                fourth_z = third_z;

                inspect_xyz(second_p);
                third_x = inspect_x;
                third_y = inspect_y;
                third_z = inspect_z;
            }
        }

        else if(type == 'H'){
            //获取当前编码的回库口
            return_xyz(p);
            temp_x = return_x;
            temp_y = return_y;
            temp_z = return_z;
            //获取下一个编码的回库口
            return_xyz(second_p);

            if(temp_x == return_x && temp_y == return_y && temp_z == return_z){
                //回库口相同
                same_flag = true;
                first_x = cargo_now[p-1].x;
                first_y = cargo_now[p-1].y;
                first_z = cargo_now[p-1].z;

                second_x = cargo_now[second_p-1].x;
                second_y = cargo_now[second_p-1].y;
                second_z = cargo_now[second_p-1].z;
            }
            else{
                //回库口不同
                return_xyz(second_p);
                first_x = return_x;
                first_y = return_y;
                first_z = return_z;

                second_x = cargo_now[p-1].x;
                second_y = cargo_now[p-1].y;
                second_y = cargo_now[p-1].z;

                ddj_last(third_type,third_p);

                fourth_x = third_x;
                fourth_y = third_y;
                fourth_z = third_z;

                third_x = cargo_now[second_p-1].x;
                third_y = cargo_now[second_p-1].y;
                third_z = cargo_now[second_p-1].z;
            }  
        }
        
        else if(type == 'C'){
            //出库
            first_x = cargo_now[second_p-1].x;
            first_y = cargo_now[second_p-1].y;
            first_z = cargo_now[second_p-1].z;

            out_xyz(second_p);
            second_x = out_x;
            second_y = out_y;
            second_z = out_z;
        }
        
        else {
            cout<<"type == second_type error!"<<endl;
        }
    }
    //相邻编码不属于同种类型,只取一垛资产
    else{
        ddj_last(second_type,second_p);
        if(type == 'R'){
            first_x = cargo_now[p-1].x;
            first_y = cargo_now[p-1].y;
            first_z = cargo_now[p-1].z;          
        }
        else if(type == 'S'){
            inspect_xyz(p);
            first_x = cargo_now[p-1].x;
            first_y = cargo_now[p-1].y;
            first_z = cargo_now[p-1].z;
        }
        else if(type == 'H'){
            return_xyz(p);
            first_x = cargo_now[p-1].x;
            first_y = cargo_now[p-1].y;
            first_z = cargo_now[p-1].z;   
        }
        else if(type == 'C'){
            out_xyz(p);
            first_x = out_x;
            first_y = out_y;
            first_z = out_z;

            // third_x = cargo_now[second_p - 1].x;
            // third_y = cargo_now[second_p - 1].y;
            // third_z = cargo_now[second_p - 1].z;
        }
    }

    //本期送检回库口相同
    same_flag = true;

    switch (type){
        case 'R'://该编码为入库编码
            
            if(cargo_now[p-1].flag == 'A'){
                first_flag = 0;
            }
            else if(cargo_now[p-1].flag == 'B'){
                first_flag = 1;
            }
            else{
                cout<<"case R first_flag error!"<<endl;
            }
            if(cargo_now[second_p-1].flag == 'A'){
                second_flag = 0;
            }
            else if(cargo_now[second_p-1].flag == 'B'){
                second_flag = 1;
            }
            else{
                cout<<"case R second_flag error!"<<endl;
            }
            ddj = stacker(p);
            if(a[ai]<=TI)//判断等待时间 数组a[ai]中存放的入库时间是依次从小到大的
                wait_time = 0;
            else
                wait_time = a[ai] - TI;
			ai++;//数组 a下标自增

            enter_xyz(p);
            if(two_flag == true){
                ddj_1 = stacker(p);
                ddj_2 = stacker(second_p);
			    //gi_n = g_number(ddj_1);
                for(int j=0;j<R;j++){
                    if(enter_block[ddj-1][j][first_flag][0]==p){
                        enter_block[ddj-1][j][first_flag][1] = INT32_MAX;
                        break;
                    }
                }
                gi_n = g_number(ddj_2);
                for(int j=0;j<R;j++){
                    if(enter_block[ddj-1][j][second_flag][0]==second_p){
                        enter_block[ddj-1][j][second_flag][1] = INT32_MAX;
                        break;
                    }
                }

                add_ddjCode(ddj);
                init_json();
                runTime = TI;
                sm[ddj-1].taskNumber = 1;
                sm[ddj-1].getPosition_x1 = enter_x;
                sm[ddj-1].getPosition_y1 = enter_y;
                //sm[ddj-1].getPosition_z1 = enter_z;
                sm[ddj-1].getAssertType1_1 = cargo_now[p-1].model;
                sm[ddj-1].getAssert1Id_1 = cargo_now[p-1].num;
                sm[ddj-1].getDirection1_1 = 'A';
                sm[ddj-1].getAssertType2_1 = cargo_now[second_p-1].model;
                sm[ddj-1].getAssert2Id_1 = cargo_now[second_p-1].model;
                sm[ddj-1].getDirection2_1 = 'B';
                //当前位置（入库口）-取2垛货 -> 货位1-放1垛货
                walk_time1 = Walk_time(abs(enter_x - first_x),abs(enter_y - first_y));
                
                sm[ddj-1].putPosition_x1 = first_x + smShiftX;
                sm[ddj-1].putPosition_y1 = first_y + smShiftY;
                sm[ddj-1].putAssertType1_1 = cargo_now[p-1].model;
                sm[ddj-1].putDirection1_1 = cargo_now[p-1].flag;

                //货位1-放1垛货 -> 货位2-放1垛货
                walk_time2 = Walk_time(abs(first_x - second_x),abs(first_y - second_y));

                sm[ddj-1].putPosition_x2 = second_x + smShiftX;
                sm[ddj-1].putPosition_y2 = second_y + smShiftY;
                sm[ddj-1].putAssertType2_2 = cargo_now[second_p-1].model;
                sm[ddj-1].putDirection2_2 = cargo_now[second_p-1].flag;
                creat_json_file();

                //货位2-放1垛货 -> 下一个编码起始位置
                walk_time3 = Walk_time(abs(second_x - third_x),abs(second_y - third_y));
                ddj_last(third_type,third_p);
                init_json();
                runTime = TI + wait_time + walk_time1 + walk_time2 + grab_time + place_time;
                sm[ddj-1].taskNumber = 1;
                sm[ddj-1].getPosition_x1 = third_x + smShiftX;
                sm[ddj-1].getPosition_y1 = third_y + smShiftY;
                sm[ddj-1].getAssertType1_1 = -1;
                creat_json_file();

                TI += wait_time + walk_time1 + walk_time2 + walk_time3 + walk_time4 + grab_time + place_time;
                TDI =  walk_time1 + walk_time2 + walk_time3 + walk_time4 + grab_time + place_time + TD[0];

                enterBlock(TI,ddj,cargo_now[p-1].flag);
                enterBlock(TI,ddj,cargo_now[second_p-1].flag);
            }
            else{
                ddj = stacker(p);//将编码的到达-时间设为最大
			    //gi_n = g_number(ddj);
			    for(int j=0;j<R;j++){
				    if(enter_block[ddj-1][j][first_flag][0]==p){
					    enter_block[ddj-1][j][first_flag][1] = INT32_MAX;
					    break;
				    }
			    }
                add_ddjCode(ddj);

                init_json();
                runTime = TI;
                sm[ddj-1].taskNumber = 1;
                sm[ddj-1].getPosition_x1 = enter_x;
                sm[ddj-1].getPosition_y1 = enter_y;
                //sm[ddj-1].getPosition_z1 = enter_z;
                sm[ddj-1].getAssertType1_1 = cargo_now[p-1].model;
                sm[ddj-1].getAssert1Id_1 = cargo_now[p-1].num;

                //当前位置（入库口）-取1垛货 -> 货位1-放1垛货
                walk_time1 = Walk_time(abs(enter_x - first_x),abs(enter_y - first_y));

                sm[ddj-1].putPosition_x1 = first_x + smShiftX;
                sm[ddj-1].putPosition_y1 = first_y + smShiftY;
                sm[ddj-1].putAssertType1_1 = cargo_now[p-1].model;
                sm[ddj-1].putDirection1_1 = cargo_now[p-1].flag;
                creat_json_file();
                //货位1-放1垛货 -> 下一个编码起始位置
                walk_time2 = Walk_time(abs(first_x - third_x),abs(first_y - third_y));

                init_json();
                runTime = TI + wait_time + walk_time1 +  grab_time + place_time;
                sm[ddj-1].taskNumber = 1;
                sm[ddj-1].getPosition_x1 = third_x + smShiftX;
                sm[ddj-1].getPosition_y1 = third_y + smShiftY;
                sm[ddj-1].getAssertType1_1 = -1;
                creat_json_file();

                TI += wait_time + walk_time1 + walk_time2 + walk_time3 + walk_time4 + grab_time + place_time;
                TDI =  walk_time1 + walk_time2 + walk_time3 + walk_time4 + grab_time + place_time + TD[0];
                enterBlock(TI,ddj,cargo_now[p-1].flag);
            }

            // walk_time1 = Walk_time(cargo_now[p-1].y,cargo_now[p-1].z);
            // if(second_type=='R'||second_type=='H')
            //     walk_time2 = Walk_time(cargo_now[p-1].y,cargo_now[p-1].z);
            // else
            //     walk_time2 = Walk_time(abs(cargo_now[p-1].y-cargo_now[second_p-1].y),abs(cargo_now[p-1].z-cargo_now[second_p-1].z));

            // TI += wait_time + grab_time + walk_time1 + walk_time2 + place_time;
			// TDI = grab_time + walk_time1 + walk_time2 + place_time + TD[0];
			TD[0] = TDI;
			//arr_block(TI,ddj);
            break;
        case 'H':
            ddj = stacker(p);
            //计算送检口送检长度
            //inspection_NUM('H',cargo_now[p-1].model);
            p_model = judge_model(p);
            for(i=0;i< H - _k; i++){//在h[]中找到下标
                if(hi[p_model][i][0] == p){
					flag = true;
					break;
				}
            }
            if(hi[p_model][i][1]<=TI || flag==false)
                wait_time = 0;
            else    
                wait_time = hi[p_model][i][1] - TI;
            // walk_time1 = Walk_time(cargo_now[p-1].y,cargo_now[p-1].z);
            // if(second_type=='R'||second_type=='H')
            //     walk_time2 = Walk_time(cargo_now[p-1].y,cargo_now[p-1].z);
            // else
            //     walk_time2 = Walk_time(abs(cargo_now[p-1].y-cargo_now[second_p-1].y),abs(cargo_now[p-1].z-cargo_now[second_p-1].z));
            // TI += wait_time + grab_time + walk_time1 + walk_time2 + place_time;
			// TDI = grab_time + walk_time1 + walk_time2 + place_time + TD[0];
			
            if(two_flag == true){
                //将编码的到达时间设为最大
                ddj_1 = stacker(p);
                ddj_2 = stacker(second_p);
			    gi_n = g_number(ddj_1);
			    for(int j=0;j<gi_n;j++){
				    if(gp[ddj-1][j][0]==p){
					    gp[ddj-1][j][1] = INT32_MAX;
					    break;
				    }
			    }
                gi_n = g_number(ddj_2);
			    for(int j=0;j<gi_n;j++){
				    if(gp[ddj-1][j][0]==second_p){
					    gp[ddj-1][j][1] = INT32_MAX;
					    break;
				    }
			    }

                add_ddjCode(ddj,'H');
                //堆垛机一次可以取两垛
                if(same_flag == true){
                    //回库口相同，当前位置（回库口）-取货 -> 货位1-放货 -> 货位2-放货 -> 下个编码起始位置
                    return_xyz(p);

                    init_json();
                    runTime = TI;
                    sm[ddj-1].taskNumber = 1;
                    sm[ddj-1].getPosition_x1 = return_x;
                    sm[ddj-1].getPosition_y1 = return_y;
                    //sm[ddj-1].getPosition_z1 = enter_z;
                    sm[ddj-1].getAssertType1_1 = cargo_now[p-1].model;
                    sm[ddj-1].getAssert1Id_1 = cargo_now[p-1].num;
                    sm[ddj-1].getDirection1_1 = 'A';
                    sm[ddj-1].getAssertType2_1 = cargo_now[second_p-1].model;
                    sm[ddj-1].getAssert2Id_1 = cargo_now[second_p-1].model;
                    sm[ddj-1].getDirection2_1 = 'B';

                    //当前位置（回库口）-取2垛货 -> 货位1-放1垛货
                    walk_time1 = Walk_time(abs(return_x - first_x),abs(return_y - first_y));

                    sm[ddj-1].putPosition_x1 = first_x + smShiftX;
                    sm[ddj-1].putPosition_y1 = first_y + smShiftY;
                    sm[ddj-1].putAssertType1_1 = cargo_now[p-1].model;
                    sm[ddj-1].putDirection1_1 = cargo_now[p-1].flag;

                    //货位1-放1垛货 -> 货位2-放1垛货
                    walk_time2 = Walk_time(abs(first_x - second_x),abs(first_y - second_y));

                    sm[ddj-1].putPosition_x2 = second_x + smShiftX;
                    sm[ddj-1].putPosition_y2 = second_y + smShiftY;
                    sm[ddj-1].putAssertType2_2 = cargo_now[second_p-1].model;
                    sm[ddj-1].putDirection2_2 = cargo_now[second_p-1].flag;
                    creat_json_file();

                    //货位2-放1垛货 -> 下个编码起始位置
                    walk_time3 = Walk_time(abs(second_x - third_x),abs(second_y - third_y));

                    init_json();
                    runTime = TI + wait_time + walk_time1 + walk_time2 + grab_time + place_time;
                    sm[ddj-1].taskNumber = 1;
                    sm[ddj-1].getPosition_x1 = third_x + smShiftX;
                    sm[ddj-1].getPosition_y1 = third_y + smShiftY;
                    sm[ddj-1].getAssertType1_1 = -1;
                    creat_json_file();

                    TI += wait_time + walk_time1 + walk_time2 + walk_time3 + walk_time4 + grab_time + place_time;
                    TDI =  walk_time1 + walk_time2 + walk_time3 + walk_time4 + grab_time + place_time + TD[0];
                }
                else{
                    ddj = stacker(p);
			        gi_n = g_number(ddj);
			        for(int j=0;j<gi_n;j++){
				        if(gp[ddj-1][j][0]==p){
					        gp[ddj-1][j][1] = INT32_MAX;
					        break;
				        }
			        }
                    //回库口不同，当前位置（回库口1）-取货 -> 回库口2-取货 -> 货位1-放货 -> 货位2-放货 -> 下个编码起始位置
                    return_xyz(p);
                    //当前位置（回库口1）-取1垛货 -> 回库口2-取1垛货 
                    walk_time1 = Walk_time(abs(return_x - first_x),abs(return_y - first_y));
                    //回库口2-取1垛货 -> 货位1-放1垛货
                    walk_time2 = Walk_time(abs(first_x - second_x),abs(first_y - second_y));
                    //货位1-放1垛货 -> 货位2-放1垛货
                    walk_time3 = Walk_time(abs(second_x - third_x),abs(second_y - third_y));
                    //货位2-放1垛货 -> 下个编码起始位置
                    walk_time4 = Walk_time(abs(third_x - fourth_x),abs(third_y - fourth_y));

                    TI += wait_time + walk_time1 + walk_time2 + walk_time3 + walk_time4 + grab_time + place_time;
                    TDI =  walk_time1 + walk_time2 + walk_time3 + walk_time4 + grab_time + place_time + TD[0];
                }
            }
            else{
                //堆垛机一次只能取一垛
                return_xyz(p);

                init_json();
                runTime = TI;
                sm[ddj-1].taskNumber = 1;
                sm[ddj-1].getPosition_x1 = return_x;
                sm[ddj-1].getPosition_y1 = return_y;
                //sm[ddj-1].getPosition_z1 = enter_z;
                sm[ddj-1].getAssertType1_1 = cargo_now[p-1].model;
                sm[ddj-1].getAssert1Id_1 = cargo_now[p-1].num;

                //当前位置（回库口）取1垛货 -> 货位1-放1垛货 -> 下个编码起始位置
                walk_time1 = Walk_time(abs(return_x - first_x),abs(return_y - first_y)); 

                sm[ddj-1].putPosition_x1 = first_x + smShiftX;
                sm[ddj-1].putPosition_y1 = first_y + smShiftY;
                sm[ddj-1].putAssertType1_1 = cargo_now[p-1].model;
                sm[ddj-1].putDirection1_1 = cargo_now[p-1].flag;
                creat_json_file();

                //货位1-放1垛货 -> 下个编码起始位置
                walk_time2 = Walk_time(abs(first_x - second_x),abs(first_y - second_y));

                init_json();
                runTime = TI + wait_time + walk_time1 +  grab_time + place_time;
                sm[ddj-1].taskNumber = 1;
                sm[ddj-1].getPosition_x1 = third_x + smShiftX;
                sm[ddj-1].getPosition_y1 = third_y + smShiftY;
                sm[ddj-1].getAssertType1_1 = -1;
                creat_json_file();

                TI += wait_time + walk_time1 + walk_time2 + walk_time3 + walk_time4 + grab_time + place_time;
                TDI =  walk_time1 + walk_time2 + walk_time3 + walk_time4 + grab_time + place_time + TD[0];
            }   
            TD[0] = TDI;
			ddj = stacker(p);
			arr_block(TI,ddj);

            //保存出库时间
            // if(outbound_i>H){std::cout<<"outbound_i error"<<endl;}
            // outbound[outbound_i][0] = outbound_i + 1;
            // outbound[outbound_i++][1] = TI + walk_time1;
            break;
        case 'C':
            ddj = stacker(p);
            // walk_time1 = Walk_time(cargo_now[p-1].y,cargo_now[p-1].z);
            // if(second_type=='R'||second_type=='H')
            //     walk_time2 = Walk_time(cargo_now[p-1].y,cargo_now[p-1].z);
            // else
            //     walk_time2 = Walk_time(abs(cargo_now[p-1].y-cargo_now[second_p-1].y),abs(cargo_now[p-1].z-cargo_now[second_p-1].z));
            // TI += grab_time + walk_time1 + place_time + walk_time2;
			// TDI = grab_time + walk_time1 + walk_time2 + place_time + TD[0];
			// TD[0] = TDI;
            out_xyz(p);
            out_y = 1.35;
            if(two_flag == true){
                add_ddjCode(ddj);
                //当前位置（货位1）-取1垛货 -> 货位2-取1垛货 —> 出库口-放2垛货 —> 下个编码起始位置

                init_json();
                runTime = TI;
                sm[ddj-1].taskNumber = 1;
                sm[ddj-1].getPosition_x1 = cargo_now[p-1].x + smShiftX;
                sm[ddj-1].getPosition_y1 = cargo_now[p-1].y + smShiftY;
                //sm[ddj-1].getPosition_z1 = enter_z;
                sm[ddj-1].getAssertType1_1 = cargo_now[p-1].model;
                sm[ddj-1].getAssert1Id_1 = cargo_now[p-1].num;
                sm[ddj-1].getDirection1_1 = cargo_now[p-1].flag;
                sm[ddj-1].getAssertType2_1 = cargo_now[second_p-1].model;
                sm[ddj-1].getAssert2Id_1 = cargo_now[second_p-1].model;
                sm[ddj-1].getDirection2_1 = cargo_now[p-1].flag;;

                //当前位置（货位1）-取1垛货 -> 货位2-取货
                walk_time1 = Walk_time(abs(first_x - cargo_now[p-1].x),abs(first_y - cargo_now[p-1].y));

                sm[ddj-1].getPosition_x2 = cargo_now[second_p-1].x + smShiftX;
                sm[ddj-1].getPosition_y2 = cargo_now[second_p-1].y + smShiftY;
                //sm[ddj-1].getPosition_z1 = enter_z;
                sm[ddj-1].getAssertType1_2 = cargo_now[second_p-1].model;
                sm[ddj-1].getAssert1Id_2 = cargo_now[second_p-1].num;
                sm[ddj-1].getDirection1_2 = cargo_now[second_p-1].flag;;
                sm[ddj-1].getAssertType2_2 = cargo_now[second_p-1].model;
                sm[ddj-1].getAssert2Id_2 = cargo_now[second_p-1].model;
                sm[ddj-1].getDirection2_2 = cargo_now[second_p-1].flag;;

                //货位2-取1垛货 —> 出库口-放2垛货
                walk_time2 = Walk_time(abs(first_x - second_x),abs(first_y - second_y));

                sm[ddj-1].putPosition_x1 = out_x;
                sm[ddj-1].putPosition_y1 = 1.35;
                sm[ddj-1].putAssertType2_1 = cargo_now[p-1].model;
                sm[ddj-1].putDirection2_1 = cargo_now[p-1].flag;

                sm[ddj-1].putPosition_x2 = out_x;
                sm[ddj-1].putPosition_y2 = 1.35;
                sm[ddj-1].putAssertType1_2 = cargo_now[second_p-1].model;
                sm[ddj-1].putDirection1_2 = cargo_now[second_p-1].flag;
                creat_json_file();

                //出库口-放2垛货 —> 下个编码起始位置
                walk_time3 = Walk_time(abs(second_x - third_x),abs(second_y - third_y));

                init_json();
                runTime = TI + wait_time + walk_time1 + walk_time2 + grab_time + place_time;
                sm[ddj-1].taskNumber = 1;
                sm[ddj-1].getPosition_x1 = third_x + smShiftX;
                sm[ddj-1].getPosition_y1 = third_y + smShiftY;
                sm[ddj-1].getAssertType1_1 = -1;
                creat_json_file();

                TI += wait_time + walk_time1 + walk_time2 + walk_time3 + walk_time4 + grab_time + place_time;
                TDI =  walk_time1 + walk_time2 + walk_time3 + walk_time4 + grab_time + place_time + TD[0];
            }
            else{
                init_json();
                runTime = TI;
                sm[ddj-1].taskNumber = 1;
                sm[ddj-1].getPosition_x1 = cargo_now[p-1].x + smShiftX;
                sm[ddj-1].getPosition_y1 = cargo_now[p-1].y + smShiftY;
                //sm[ddj-1].getPosition_z1 = enter_z;
                sm[ddj-1].getAssertType1_1 = cargo_now[p-1].model;
                sm[ddj-1].getAssert1Id_1 = cargo_now[p-1].num;
                sm[ddj-1].getDirection1_1 = cargo_now[p-1].flag;
                sm[ddj-1].getAssertType2_1 = cargo_now[p-1].model;
                sm[ddj-1].getAssert2Id_1 = cargo_now[p-1].model;
                sm[ddj-1].getDirection2_1 = cargo_now[p-1].flag;;

                //当前位置（货位1）-取1垛货 —> 出库口-放1垛货 —> 下个编码起始位置
                walk_time1 = Walk_time(abs(out_x - first_x),abs(out_y - first_y));

                sm[ddj-1].putPosition_x1 = out_x;
                sm[ddj-1].putPosition_y1 = 1.35;
                sm[ddj-1].putAssertType1_1 = cargo_now[p-1].model;
                sm[ddj-1].putDirection1_1 = cargo_now[p-1].flag;
                creat_json_file();

                //货位1-放1垛货 -> 下一个编码起始位置
                walk_time2 = Walk_time(abs(first_x - second_x),abs(first_y - second_y));

                init_json();
                runTime = TI + wait_time + walk_time1 +  grab_time + place_time;
                sm[ddj-1].taskNumber = 1;
                sm[ddj-1].getPosition_x1 = third_x + smShiftX;
                sm[ddj-1].getPosition_y1 = third_y + smShiftY;
                sm[ddj-1].getAssertType1_1 = -1;
                creat_json_file();

                TI += wait_time + walk_time1 + walk_time2 + walk_time3 + walk_time4 + grab_time + place_time;
                TDI =  walk_time1 + walk_time2 + walk_time3 + walk_time4 + grab_time + place_time + TD[0];
            }

			ddj = stacker(p);
			arr_block(TI,ddj);
            break;
        case 'S':
            //inspection_NUM('S',cargo_now[p-1].model);
            //获取检定口位置,以及检定资产的检定时间
            inspect(cargo_now[p-1].model);
            inspect_xyz(p);
            ddj = stacker(p);
            if(two_flag == true){
                add_ddjCode(ddj);
                //堆垛机一次可以取两垛
                if(same_flag == true){

                    init_json();
                    runTime = TI;
                    sm[ddj-1].taskNumber = 1;
                    sm[ddj-1].getPosition_x1 = cargo_now[p-1].x + smShiftX;;
                    sm[ddj-1].getPosition_y1 = cargo_now[p-1].y + smShiftY;
                    //sm[ddj-1].getPosition_z1 = enter_z;
                    sm[ddj-1].getAssertType1_1 = cargo_now[p-1].model;
                    sm[ddj-1].getAssert1Id_1 = cargo_now[p-1].num;
                    sm[ddj-1].getDirection1_1 = 'A';
                    sm[ddj-1].getAssertType2_1 = cargo_now[second_p-1].model;
                    sm[ddj-1].getAssert2Id_1 = cargo_now[second_p-1].model;
                    sm[ddj-1].getDirection2_1 = 'B';

                    //送检口相同，当前位置（货位1）-取1垛货 -> 货位2-取1垛货 -> 送检口-放2垛货 -> 下一个编码起始位置
                    //当前位置（货位1）-取1垛货 -> 货位2-取1垛货
                    walk_time1 = Walk_time(abs(cargo_now[p-1].x - first_x),abs(cargo_now[p-1].y - first_y));

                    sm[ddj-1].getPosition_x2 = first_x + smShiftX;
                    sm[ddj-1].getPosition_y2 = first_y + smShiftY;
                    sm[ddj-1].putAssertType1_2 = cargo_now[second_p-1].model;
                    sm[ddj-1].putDirection1_2 = cargo_now[second_p-1].flag;
                    sm[ddj-1].putAssertType1_2 = cargo_now[second_p-1].model;
                    sm[ddj-1].putDirection1_2 = cargo_now[second_p-1].flag;

                    //货位2-取1垛货 -> 送检口-放2垛货
                    walk_time2 = Walk_time(abs(first_x - second_x),abs(first_y - second_y));

                    sm[ddj-1].putPosition_x1 = inspect_x;
                    sm[ddj-1].putPosition_y1 = inspect_y;
                    sm[ddj-1].putAssertType1_1 = cargo_now[p-1].model;
                    sm[ddj-1].putDirection1_1 = cargo_now[p-1].flag;

                    sm[ddj-1].putPosition_x2 = inspect_x;
                    sm[ddj-1].putPosition_y2 = inspect_y;
                    sm[ddj-1].putAssertType2_2 = cargo_now[second_p-1].model;
                    sm[ddj-1].putDirection2_2 = cargo_now[second_p-1].flag;
                    creat_json_file();

                    //送检口-放2垛货 -> 下一个编码起始位置
                    walk_time3 = Walk_time(abs(second_x - third_x),abs(second_y - third_y));

                    init_json();
                    runTime = TI + wait_time + walk_time1 + walk_time2 + grab_time + place_time;
                    sm[ddj-1].taskNumber = 1;
                    sm[ddj-1].getPosition_x1 = third_x + smShiftX;
                    sm[ddj-1].getPosition_y1 = third_y + smShiftY;
                    sm[ddj-1].getAssertType1_1 = -1;
                    creat_json_file();

                    TI += wait_time + walk_time1 + walk_time2 + walk_time3 + walk_time4 + grab_time + place_time;
                    TDI =  walk_time1 + walk_time2 + walk_time3 + walk_time4 + grab_time + place_time + TD[0];
                }
                else{
                    //送检口不同，当前位置（货位1）-取1垛货 -> 货位2-取1垛货 -> 送检口1-放1垛货 -> 送检口2-放1垛货 -> 下一个编码起始位置
                    //当前位置（货位1）-取1垛货 -> 货位2-取1垛货
                    walk_time1 = Walk_time(abs(return_x - first_x),abs(return_y - first_y));
                    //货位2-取1垛货 -> 送检口1-放1垛货
                    walk_time2 = Walk_time(abs(first_x - second_x),abs(first_y - second_y));
                    //送检口1-放1垛货 -> 送检口2-放1垛货
                    walk_time3 = Walk_time(abs(second_x - third_x),abs(second_y - third_y));
                    //送检口2-放1垛货 -> 下一个编码起始位置
                    walk_time4 = Walk_time(abs(third_x - fourth_x),abs(third_y - fourth_y));

                    TI += wait_time + walk_time1 + walk_time2 + walk_time3 + walk_time4 + grab_time + place_time;
                    TDI =  walk_time1 + walk_time2 + walk_time3 + walk_time4 + grab_time + place_time + TD[0];
                }
            }
            else{
                init_json();
                runTime = TI;
                sm[ddj-1].taskNumber = 1;
                sm[ddj-1].getPosition_x1 = cargo_now[p-1].x + smShiftX;;
                sm[ddj-1].getPosition_y1 = cargo_now[p-1].y + smShiftY;
                //sm[ddj-1].getPosition_z1 = enter_z;
                sm[ddj-1].getAssertType1_1 = cargo_now[p-1].model;
                sm[ddj-1].getAssert1Id_1 = cargo_now[p-1].num;
                sm[ddj-1].getDirection1_1 = 'A';
                sm[ddj-1].getAssertType2_1 = cargo_now[p-1].model;
                sm[ddj-1].getAssert2Id_1 = cargo_now[p-1].model;
                sm[ddj-1].getDirection2_1 = 'B';

                //堆垛机一次只能取一垛
                //当前位置（货位1）取1垛货 -> 送检口-放1垛货 -> 下个编码起始位置
                //当前位置（货位1）取1垛货 -> 送检口-放1垛货
                walk_time1 = Walk_time(abs(inspect_x - first_x),abs(inspect_y - first_y)); 

                sm[ddj-1].putPosition_x1 = inspect_x;
                sm[ddj-1].putPosition_y1 = inspect_y;
                sm[ddj-1].putAssertType1_1 = cargo_now[p-1].model;
                sm[ddj-1].putDirection1_1 = cargo_now[p-1].flag;
                creat_json_file();

                //送检口-放1垛货 -> 下个编码起始位置
                walk_time2 = Walk_time(abs(first_x - third_x),abs(first_y - second_y));

                init_json();
                runTime = TI + wait_time + walk_time1 +  grab_time + place_time;
                sm[ddj-1].taskNumber = 1;
                sm[ddj-1].getPosition_x1 = third_x + smShiftX;
                sm[ddj-1].getPosition_y1 = third_y + smShiftY;
                sm[ddj-1].getAssertType1_1 = -1;
                creat_json_file();

            TI += wait_time + walk_time1 + walk_time2 + walk_time3 + walk_time4 + grab_time + place_time;
            TDI =  walk_time1 + walk_time2 + walk_time3 + walk_time4 + grab_time + place_time + TD[0];
            }  

            // walk_time1 = Walk_time(cargo_now[p-1].y,abs(cargo_now[p-1].z-inspect_z)); //堆垛机从当前位置移动到送检口，此处送检口与资产type相关
			// if(second_type=='R'||second_type=='H')//如果下一个编码属于入库或回库编码
			// 	walk_time2 = Walk_time(cargo_now[p-1].y,cargo_now[p-1].z);//***可修改***堆垛机最后移动到下一个编码的起始位置，也就是0,0位置（此处，后期可根据不同的回库资产的楼层让堆垛机移动到不同的位置）
			// else
			// 	walk_time2 = Walk_time(abs(cargo_now[p-1].y-cargo_now[second_p-1].y),abs(cargo_now[p-1].z-cargo_now[second_p-1].z));//如果属于送检或出库，则移动到该货物的货架位置
			// TI +=  grab_time + walk_time1 + place_time+ walk_time2;//该条编码的堆垛机总工作时间为 等待时间+拿取时间+工作行走时间+放置时间+行走到下一条编码的时间
			// TDI =  grab_time + walk_time1 + place_time+ walk_time2 + TD[0];//堆垛机实际工作时间 = 总工作时间-等待时间
			TD[0] = TDI;//将实际工作时间写入到实际工作数组中，如果后期有需要，则该数组可以保留每一台堆垛机的实际工作时间。此时将每台堆垛机的实际工作时间叠加到TD[0]中
			
            //开始计算 送检编码 所对应的 回库编码 的 回库时间
            if(two_flag == true){
                //当p and second_p 均在数组s[i]中被找到时，以下两个flag的值变为true
                bool flag_i = false,flag_second_i = false;
                for(int i=0;i< H - _k; i++){
                    if(s[i] == p){//找到p
                        flag_i = true;
                        first_i = i;
                    }
                    if(s[i] == second_p){
                        flag_second_i = true;
                        second_i = i;
                    }
                    if(flag_i == true && flag_second_i == true){//根据当前编码，找到在 送检编码数组 中的下标 i，此下标可对应在 回库数组 中的回库编码的位置
                        
                        ddj_1 = stacker(h[first_i]);//判断该回库编码属于哪台堆垛机来服务
                        ddj_2 = stacker(h[second_i]);
                        switch (ddj_1)
                        {
                        case 1://如果是第一台堆垛机服务
                            g1_H2[th1]=h[i];//将该回库编码写入到堆垛机1的回库数组里
                            th1++;//堆垛机1的 回库编码数组 和 回库时间数组 下标自增
                            break;
                        case 2:
                            g2_H2[th2]=h[i];
                            th2++;
                            break;
                        case 3:
                            g3_H2[th3]=h[i];
                            th3++;
                            break;
                        case 4:
                            g4_H2[th4]=h[i];
                            th4++;
                            break;
                        case 5:
                            g5_H2[th5]=h[i];
                            th5++;
                            break;
                        case 6:
                            g6_H2[th6]=h[i];
                            th6++;
                            break;
                        default:
                            cout<<"read code ddj error!"<<endl;
                            break;
                        }
                        switch (ddj_2)
                        {
                        case 1://如果是第一台堆垛机服务
                            g1_H2[th1]=h[i];//将该回库编码写入到堆垛机1的回库数组里
                            th1++;//堆垛机1的 回库编码数组 和 回库时间数组 下标自增
                            break;
                        case 2:
                            g2_H2[th2]=h[i];
                            th2++;
                            break;
                        case 3:
                            g3_H2[th3]=h[i];
                            th3++;
                            break;
                        case 4:
                            g4_H2[th4]=h[i];
                            th4++;
                            break;
                        case 5:
                            g5_H2[th5]=h[i];
                            th5++;
                            break;
                        case 6:
                            g6_H2[th6]=h[i];
                            th6++;
                            break;
                        default:
                            cout<<"read code ddj error!"<<endl;
                            break;
                        }
                        //cout<<"------------"<<h[i]<<"------------"<<endl;
                        //p 回库编码的处理
                        p_model = judge_model(p);
                        if(cargo_now[p-1].model != p_model){
                            cout<<"p_model error!"<<endl;
                        }
                        cargo_now[h[first_i]-1].model = p_model;
                        if(cargo_now[p-1].model==0)
                        {
                            hi[p_model][b_0][1] = TI + t_inspect;//回库时间写入到hi[p_model][b_0][1]中
                            hi[p_model][b_0][0] = h[first_i];//回库编码 写入到hi[p_model][b_0][0]中
                            b_0++;//b_0自增
                        }
                        else if(cargo_now[p-1].model==1)
                        {
                            hi[p_model][b_1][1] = TI + t_inspect;//回库时间写入到hi[p_model][b_1][1]中
                            hi[p_model][b_1][0] = h[first_i];//回库编码 写入到hi[p_model][b_1][0]中
                            b_1++;//b_1自增
                        }
                        else if(cargo_now[p-1].model==2)
                        {
                            hi[p_model][b_2][1] = TI + t_inspect;//回库时间写入到hi[p_model][b_2][1]中
                            hi[p_model][b_2][0] = h[first_i];//回库编码 写入到hi[p_model][b_2][0]中
                            b_2++;//b_2自增
                        }
                        else if(cargo_now[p-1].model==3)
                        {
                            hi[p_model][b_3][1] = TI + t_inspect;//回库时间写入到hi[p_model][b_3][1]中
                            hi[p_model][b_3][0] = h[first_i];//回库编码 写入到hi[p_model][b_3][0]中
                            b_3++;//b_3自增
                        }
                        else if(cargo_now[p-1].model==4)
                        {
                            hi[p_model][b_4][1] = TI + t_inspect;//回库时间写入到hi[p_model][b_4][1]中
                            hi[p_model][b_4][0] = h[first_i];//回库编码 写入到hi[p_model][b_4][0]中
                            b_4++;//b_4自增
                        }
                        else{
                            cout<<"read-S-cargo_now[p-1].model error!"<<endl;
                        }
                        
                        //second_p 回库编码的处理
                        p_model = judge_model(second_p);
                        if(cargo_now[second_p-1].model != p_model){
                            cout<<"second_p_model error!"<<endl;
                        }
                        cargo_now[h[second_i]-1].model = p_model;
                        if(cargo_now[second_p-1].model==0)
                        {
                            hi[p_model][b_0][1] = TI + t_inspect;//回库时间写入到hi[p_model][b_0][1]中
                            hi[p_model][b_0][0] = h[second_i];//回库编码 写入到hi[p_model][b_0][0]中
                            b_0++;//b_0自增
                        }
                        else if(cargo_now[second_p-1].model==1)
                        {
                            hi[p_model][b_1][1] = TI + t_inspect;//回库时间写入到hi[p_model][b_1][1]中
                            hi[p_model][b_1][0] = h[second_i];//回库编码 写入到hi[p_model][b_1][0]中
                            b_1++;//b_1自增
                        }
                        else if(cargo_now[second_p-1].model==2)
                        {
                            hi[p_model][b_2][1] = TI + t_inspect;//回库时间写入到hi[p_model][b_2][1]中
                            hi[p_model][b_2][0] = h[second_i];//回库编码 写入到hi[p_model][b_2][0]中
                            b_2++;//b_2自增
                        }
                        else if(cargo_now[second_p-1].model==3)
                        {
                            hi[p_model][b_3][1] = TI + t_inspect;//回库时间写入到hi[p_model][b_3][1]中
                            hi[p_model][b_3][0] = h[second_i];//回库编码 写入到hi[p_model][b_3][0]中
                            b_3++;//b_3自增
                        }
                        else if(cargo_now[second_p-1].model==4)
                        {
                            hi[p_model][b_4][1] = TI + t_inspect;//回库时间写入到hi[p_model][b_4][1]中
                            hi[p_model][b_4][0] = h[second_i];//回库编码 写入到hi[p_model][b_4][0]中
                            b_4++;//b_4自增
                        }
                        else{
                            cout<<"read-S-cargo_now[second_p-1].model error!"<<endl;
                        }
                        break;
                        // hi[][1] = TI + t_inspect;//回库时间写入到hi[p_model][][1]中
                        // hi[][0] = h[i];//回库编码 写入到hi[p_model][b_n][0]中
                        // ++;//自增
                        // break;
				    }
			    }
            }
            else{
                for( i=0;i< H - _k; i++){
				if(s[i]==p){//根据当前编码，找到在 送检编码数组 中的下标 i，此下标可对应在 回库数组 中的回库编码的位置
					ddj = stacker(h[i]);//判断该回库编码属于哪台堆垛机来服务
					switch (ddj)
					{
					case 1://如果是第一台堆垛机服务
						g1_H2[th1]=h[i];//将该回库编码写入到堆垛机1的回库数组里
						th1++;//堆垛机1的 回库编码数组 和 回库时间数组 下标自增
						break;
					case 2:
						g2_H2[th2]=h[i];
						th2++;
						break;
					case 3:
						g3_H2[th3]=h[i];
						th3++;
						break;
					case 4:
						g4_H2[th4]=h[i];
						th4++;
						break;
					case 5:
						g5_H2[th5]=h[i];
						th5++;
						break;
					case 6:
						g6_H2[th6]=h[i];
						th6++;
						break;
					default:
						cout<<"read code ddj error!"<<endl;
						break;
					}

					p_model = judge_model(p);
                    if(cargo_now[p-1].model != p_model){
                            cout<<"p_model error!"<<endl;
                    }
                    cargo_now[h[first_i]-1].model = p_model;
                    if(cargo_now[p-1].model==0)
                    {
                        hi[p_model][b_0][1] = TI + t_inspect;//回库时间写入到hi[p_model][b_0][1]中
                        hi[p_model][b_0][0] = h[first_i];//回库编码 写入到hi[p_model][b_0][0]中
                        b_0++;//b_0自增
                    }
                    else if(cargo_now[p-1].model==1)
                    {
                        hi[p_model][b_1][1] = TI + t_inspect;//回库时间写入到hi[p_model][b_1][1]中
                        hi[p_model][b_1][0] = h[first_i];//回库编码 写入到hi[p_model][b_1][0]中
                        b_1++;//b_1自增
                    }
                    else if(cargo_now[p-1].model==2)
                    {
                        hi[p_model][b_2][1] = TI + t_inspect;//回库时间写入到hi[p_model][b_2][1]中
                        hi[p_model][b_2][0] = h[first_i];//回库编码 写入到hi[p_model][b_2][0]中
                        b_2++;//b_2自增
                    }
                    else if(cargo_now[p-1].model==3)
                    {
                        hi[p_model][b_3][1] = TI + t_inspect;//回库时间写入到hi[p_model][b_3][1]中
                        hi[p_model][b_3][0] = h[first_i];//回库编码 写入到hi[p_model][b_3][0]中
                        b_3++;//b_3自增
                    }
                    else if(cargo_now[p-1].model==4)
                    {
                        hi[p_model][b_4][1] = TI + t_inspect;//回库时间写入到hi[p_model][b_4][1]中
                        hi[p_model][b_4][0] = h[first_i];//回库编码 写入到hi[p_model][b_4][0]中
                        b_4++;//b_4自增
                    }
                    else{
                        cout<<"read-S-cargo_now[p-1].model error!"<<endl;
                    }
                    break;
					// hi[][1] = TI + t_inspect;//回库时间写入到hi[p_model][][1]中
					// hi[][0] = h[i];//回库编码 写入到hi[p_model][][0]中
					// ++;//自增
					//break;
				}
			}
        }
		ddj = stacker(p);
		arr_block(TI,ddj);
		break;
        default:
            cout<<"read error!"<<endl;
            break;
    }
    return TI;//返回堆垛机读取该编码的时间.
}
// todo 重载 Storing_num()
void Storing_num(Food f){//输入种群
    int p=0;
    char g=0;
    g1_s = 0,g2_s = 0,g3_s = 0,g4_s = 0,g5_s = 0,g6_s = 0;
    g1_h = 0,g2_h = 0,g3_h = 0,g4_h = 0,g5_h = 0,g6_h = 0;
    g1_r = 0,g2_r = 0,g3_r = 0,g4_r = 0,g5_r = 0,g6_r = 0;
    g1_n=0;g2_n=0;g3_n=0;g4_n=0;g5_n=0;g6_n=0;
    for(int i=0; i < CODELENGTH; i++){//遍历所有货位
        p = cargo_now[f.getSequence(i)-1].line-4;//货架信息
        g = judge_type(f.getSequence(i));//货物类别 R、S、H、C
        switch (p)//判断属于哪台堆垛机
        {
            case 1:
            case 2://属于1号堆垛机
                if(g=='S')//送检
                    g1_s++;
                else if(g=='H')//回库
                    g1_h++;
                else if(g=='R')//入库
				    g1_r++;
                g1_n++;//堆垛机1编码数量自增
                break;
            case 3:
            case 4:
                if(g=='S')
                    g2_s++;
                else if(g=='H')
                    g2_h++;
                else if(g=='R')
				    g2_r++;
                g2_n++;
                break;
            case 5:
            case 6:
                if(g=='S')
                    g3_s++;
                else if(g=='H')
                    g3_h++;
                else if(g=='R')
				    g3_r++;
                g3_n++;
                break;
            case 7:
            case 8:
                if(g=='S')
                    g4_s++;
                else if(g=='H')
                    g4_h++;
                else if(g=='R')
				    g4_r++;
                g4_n++;
                break;
            case 9:
            case 10:
                if(g=='S')
                    g5_s++;
                else if(g=='H')
                    g5_h++;
                else if(g=='R')
				    g5_r++;
                g5_n++;
                break;
            case 11:
            case 12:
                if(g=='S')
                    g6_s++;
                else if(g=='H')
                    g6_h++;
                else if(g=='R')
				    g6_r++;
                g6_n++;
                break;
            default:
                cout<<"sort_num error!"<<endl;
                break;
        }
    }
}
// todo 重载 Storing()
void Storing(Food f,int g1[],int g2[],int g3[],int g4[],int g5[],int g6[],int g1_S[],int g2_S[],int g3_S[],int g4_S[],int g5_S[],int g6_S[],int g1_H[],int g2_H[],int g3_H[],int g4_H[],int g5_H[],int g6_H[]){
    j_1=0, j_2=0, j_3=0, j_4=0, j_5=0, j_6=0;
    int g1s=0,g2s=0,g3s=0,g4s=0,g5s=0,g6s=0;
    int g1h=0,g2h=0,g3h=0,g4h=0,g5h=0,g6h=0;
    int g1r=0,g2r=0,g3r=0,g4r=0,g5r=0,g6r=0;
    int p=0;
    char g=0;
    for(int i=0; i < CODELENGTH; i++){//遍历编码数组
        p = cargo_now[f.getSequence(i)-1].line-4;//货架信息
        g = judge_type(f.getSequence(i));//货物类别 R、S、H、C
        switch (p)//判断编码属于哪台堆垛机
        {
            case 1:
            case 2://属于堆垛机1
                if(g=='S'){//属于送检编码
                    g1_S[g1s] = f.getSequence(i);//将该编码写入堆垛机1的送检数组
                    g1s++;//送检数组下标自增1
                }
                else if(g=='H'){//属于回库编码
                    g1_H[g1h] = f.getSequence(i);//该编码写入堆垛机1的回库数组
                    g1h++;//回库数组下标自增1
                }
                else if(g=='R'){//属于入库编码
				    gp[0][g1r][0] = f.getSequence(i);
				    //g1_R[g1r] = f.G[i];//将该编码写入堆垛机1的入库数组
				    g1r++;
			    }   
                g1[j_1] = f.getSequence(i);//该编码写入到堆垛机1的 编码数组中
                j_1++;//堆垛机1的编码数组自增1
                break;
            case 3:
            case 4:
                if(g=='S'){
                    g2_S[g2s] = f.getSequence(i);
                    g2s++;
                }
                else if(g=='H'){
                    g2_H[g2h] = f.getSequence(i);
                    g2h++;
                }
                else if(g=='R'){//属于入库编码
				    gp[1][g2r][0] = f.getSequence(i);
				    //g2_R[g2r] = f.G[i];//将该编码写入堆垛机2的入库数组
				    g2r++;
			    }
                g2[j_2] = f.getSequence(i);
                j_2++;
                break;
            case 5:
            case 6:
                if(g=='S'){
                    g3_S[g3s] = f.getSequence(i);
                    g3s++;
                }
                else if(g=='H'){
                    g3_H[g3h] = f.getSequence(i);
                    g3h++;
                }
                else if(g=='R'){//属于入库编码
				    gp[2][g3r][0] = f.getSequence(i);
				    //g3_R[g3r] = f.G[i];//将该编码写入堆垛机3的入库数组
				    g3r++;
			    }
                g3[j_3] = f.getSequence(i);
                j_3++;
                break;
            case 7:
            case 8:
                if(g=='S'){
                    g4_S[g4s] = f.getSequence(i);
                    g4s++;
                }
                else if(g=='H'){
                    g4_H[g4h] = f.getSequence(i);
                    g4h++;
                }
                else if(g=='R'){//属于入库编码
				    gp[3][g4r][0] = f.getSequence(i);
				    //g4_R[g4r] = f.G[i];//将该编码写入堆垛机4的入库数组
				    g4r++;
			    }
                g4[j_4] = f.getSequence(i);
                j_4++;
                break;
            case 9:
            case 10:
                if(g=='S'){
                    g5_S[g5s] = f.getSequence(i);
                    g5s++;
                }
                else if(g=='H'){
                    g5_H[g5h] = f.getSequence(i);
                    g5h++;
                }
                else if(g=='R'){//属于入库编码
				    gp[4][g5r][0] = f.getSequence(i);
				    //g5_R[g5r] = f.G[i];//将该编码写入堆垛机5的入库数组
				    g5r++;
			    }
                g5[j_5] = f.getSequence(i);
                j_5++;
                break;
            case 11:
            case 12:
                if(g=='S'){
                    g6_S[g6s] = f.getSequence(i);
                    g6s++;
                }
                else if(g=='H'){
                    g6_H[g6h] = f.getSequence(i);
                    g6h++;
                }
                else if(g=='R'){//属于入库编码
				    gp[5][g6r][0] = f.getSequence(i);
				    //g6_R[g6r] = f.G[i];//将该编码写入堆垛机6的入库数组
				    g6r++;
			    }
                g6[j_6] = f.getSequence(i);
                j_6++;
                break;
            default:
                cout<<"sort error!"<<endl;
                break;
        }
    }
}
//入库组 目前没有用到
void R_t(double a[]){
    int cnt = 0;
    double temp = 0;
    FILE *fp=fopen("Test.txt", "r");
    while(cnt<R){
        fscanf(fp, "%lf", &temp);
        a[cnt] = temp; 
        cnt++;
    }
    fclose(fp);
}
//获得适应度值，（最大工期*0.8 + 堆垛机实际工作时间*0.2）/60
int max2(double T[], Food &f){
	int i,j;
    double temp,G_fintess;
	double TT;
    for(i=0;i<5;i++)//按照数组元素，从大到小排序
        for(j=0;j<5-i;j++){
            if(T[j+1]>T[j]){
            temp=T[j+1];
            T[j+1]=T[j];
            T[j]=temp;
            }
        }
    int temp2=0;
    int sit = 0;
    int ddj = 0;
    for(int i=0;i<CODELENGTH;i++){
        for(int j=0;j<CODELENGTH-i;j++){
            if(arr_p[j+1][3]<arr_p[j][3]){//以时间为顺序排列
            temp2=arr_p[j+1][1];
            arr_p[j+1][1]=arr_p[j][1];
            arr_p[j][1]=temp2;

			sit = arr_p[j+1][0];
            arr_p[j+1][0] = arr_p[j][0];
            arr_p[j][0] = sit;

            ddj = arr_p[j+1][2];
            arr_p[j+1][2] = arr_p[j][2];
            arr_p[j][2] = ddj;

			TT = arr_p[j+1][3];
            arr_p[j+1][3] = arr_p[j][3];
            arr_p[j][3] = TT;
            }
           
        }
	}
    ofstream out;
    out.open("output/in_block.txt");
    for(int i=1;i<CODELENGTH+1;i++){
        out<<"arr_p[][]:"<<arr_p[i][0]<<","<<arr_p[i][1]<<","<<arr_p[i][2]<<","<<arr_p[i][3]<<endl;
    }
	punish();
	//T[0] = T[0]/60.0;
	//G_fintess = T[0]*0.95 + TD[0]*0.05 + block_long*block_times*50;//适应度值计算，加权重

    G_fintess = T[0] + enterI * 1000;
    //cout<<enterI<<endl;
//    cout << T[0] << endl;
    f.setTimeSpan(T[0] / 3600.0);
	//G_fintess = G_fintess/60.0;//除以60 将秒转换为分钟
	//T[0] = T[0]/60.0;//堆垛机实际工作时间 分钟
	out.close();
	return G_fintess;
    //return G_fintess;
}
//根据堆垛机号读码
void read_ddj(int gi_H[],int ddj,int gi[]){
	switch (ddj)//判断堆垛机序号
	{
	case 1:
		while(gi_H[h1]!=gi[j_1]){//不断读取，直到读取到g1中第一条H编码为止

			if(j_1 < (g1_n - 2)){//不属于最后一位编码
				T1 = read(T1, TD1, gi[j_1], gi[j_1 + 1],gi[j_1 + 2]);//读取编码
				j_1++;//堆垛机数组编码自增1
			}
			else if(j_1 == (g1_n - 2)){//如果读取到该堆垛机的最后一位编码，则下一条编码与当前编码相同
				T1 = read(T1, TD1, gi[j_1], gi[j_1+1],gi[j_1+1]);
				j_1++;
			}
            else if(j_1 == (g1_n - 1)){
                T1 = read(T1, TD1, gi[j_1], gi[j_1],gi[j_1]);
				j_1++; 
            } 
			if(j_1 > g1_n - 1)//如果该堆垛机的编码全部读取完毕 
				break;//跳出循环 
		} 
		h1++; 
		break; 
 
	case 2: 
		while(gi_H[h2]!=gi[j_2]){ //不断读取，直到读取到g2中第一条H编码为止

			if(j_2 < (g2_n - 2)){
				T2 = read(T2, TD2, gi[j_2], gi[j_2 + 1],gi[j_2 + 2]);
				j_2++;
			}
			else if(j_2 == (g2_n - 2)){
				T2 = read(T2, TD2, gi[j_2], gi[j_2+1],gi[j_2+1]);
				j_2++;
			}	
            else if(j_2 == (g2_n -1)){
                T2 = read(T2, TD2, gi[j_2], gi[j_2],gi[j_2]);
				j_2++;
            }
			if(j_2 > g2_n - 1)
				break;

		}
		h2++;	
		break;

	case 3:
		while(gi_H[h3]!=gi[j_3]){ //不断读取，直到读取到g3中第一条H编码为止
			if(j_3 < (g3_n - 2)){
				T3 = read(T3, TD3, gi[j_3], gi[j_3 + 1],gi[j_3 + 2]);
				j_3++;
			}
			else if(j_3 == (g3_n - 2)){
				T3 = read(T3, TD3, gi[j_3], gi[j_3 + 1], gi[j_3 + 1]);
				j_3++;
			}	
            else if(j_3 == (g3_n - 1)){
				T3 = read(T3, TD3, gi[j_3], gi[j_3], gi[j_3]);
				j_3++;
			}	
			if(j_3 > g3_n - 1)
				break;
		}	
		h3++;
		break;

	case 4:
		while(gi_H[h4]!=gi[j_4]){ //不断读取，直到读取到g4中第一条H编码为止
			if(j_4 < (g4_n - 2)){
				T4 = read(T4, TD4, gi[j_4], gi[j_4 + 1], gi[j_4 + 2]);
				j_4++;
			}
            else if(j_4 == (g4_n - 2)){
				T4 = read(T4, TD4, gi[j_4], gi[j_4 + 1], gi[j_4 + 1]);
				j_4++;
			}
			else if(j_4 == (g4_n - 1)){
				T4 = read(T4, TD4, gi[j_4], gi[j_4],gi[j_4]);
				j_4++;
			}	
			if(j_4 > g4_n - 1)
				break;
		}
		h4++;
		break;

	case 5:
		while(gi_H[h5]!=gi[j_5]){ //不断读取，直到读取到g5中第一条S编码为止
			if(j_5 < (g5_n - 2)){
				T5 = read(T5, TD5, gi[j_5], gi[j_5 + 1], gi[j_5 + 2]);
				j_5++;
			}
			else if(j_5 == (g5_n - 2)){
				T5 = read(T5, TD5, gi[j_5], gi[j_5 + 1], gi[j_5 + 1]);
				j_5++;
			}
            else if(j_5 == (g5_n - 1)){
				T5 = read(T5, TD5, gi[j_5], gi[j_5], gi[j_5]);
				j_5++;
			}	
			if(j_5 > g5_n - 1)
				break;
		}
		h5++;
		break;

	case 6:
		while(gi_H[h6]!=gi[j_6]){ //不断读取，直到读取到g6中第一条S编码为止
			if(j_6 < (g6_n - 2)){
				T6 = read(T6, TD6, gi[j_6], gi[j_6 + 1], gi[j_6 + 2]);
				j_6++;
			}
			else if(j_6 == (g6_n - 2)){
				T6 = read(T6, TD6, gi[j_6], gi[j_6 + 1], gi[j_6 + 1]);
				j_6++;
			}
            else if(j_6 == (g6_n - 1)){
				T6 = read(T6, TD6, gi[j_6], gi[j_6], gi[j_6]);
				j_6++;
			}		
			if(j_6 > g6_n - 1)
				break;
		}	
		h6++;
		break;

	default:
		cout<<"read_ddj error!"<<endl;
		break;
	}
}
//判断是否产生交换
void decide_swap(int g[], int gi[], int gi_H2[], int gi_th[], int gi_H[], int thi, int p, int gi_h, int hj,int gi_n) {//hj表示堆垛机读取的当前回库编码数量
    int u1 = 0, u2 = 0, temp = 0;//u1，u2表示需要交换编码的下标
    int p1 = 0;
    bool flag_u1 = false, flag_u2 = false;
    p_model = judge_model(p);
    if(p_model == 0){
        p1 = hi[p_model][a_0 - 1][0];//时间最短的回库编码
        if(a_0==0)
            p1 = hi[p_model][a_0][0];
    }
    else if(p_model == 1){
        p1 = hi[p_model][a_1 - 1][0];
        if(a_1==0)
            p1 = hi[p_model][a_1][0];
    }
    else if(p_model == 2){
        p1 = hi[p_model][a_2 - 1][0];
        if(a_2==0)
            p1 = hi[p_model][a_2][0];
    }
    else if(p_model == 3){
        p1 = hi[p_model][a_3 - 1][0];
        if(a_3==0)
            p1 = hi[p_model][a_3][0];
    }
    else if(p_model == 4){
        p1 = hi[p_model][a_4 - 1][0];
        if(a_4==0)
            p1 = hi[p_model][a_4][0];
    }
    else{
        cout<<"decide_swap p1 error!"<<endl;
    }
    //p1 = hi[p_model][ - 1][0];//时间最短的回库编码
    int ddj = stacker(p1);//判断最短时间回库编码的堆垛机序号
    int p2 = 0;//要交换的编码
    for (int i = hj - 1; i < thi; i++) {//从读取到当前回库编码数量 开始 到所有已与送检编码匹配的回库编码数量为止
        if (p1 == gi_H2[hj - 1])break;//不需要交换
        else {//需要交换
            p2 = gi_H2[hj - 1];//与第一位的回库编码交换
            for (int j = 0; j < CODELENGTH; j++) {
                if (g[j] == p1) {
                    u1 = j;
                    flag_u1 = true;
                    continue;
                }
                if (g[j] == p2) {
                    u2 = j;
                    flag_u2 = true;
                    continue;
                }
                if (flag_u1 == true && flag_u2 == true)
                    break;
            }
            //在G中交换位置
            //temp = g[u1];
            //g[u1] = g[u2];
            //g[u2] = temp;
            //u1 = 0, u2 = 0;
            flag_u1 = false, flag_u2 = false;
            //在gi_h中交换
            for (int j = 0; j < gi_h; j++) {
                if (gi_H[j] == p1) {
                    u1 = j;
                    continue;
                }
                if (gi_H[j] == p2) {
                    u2 = j;
                    continue;
                }
                if (flag_u1 == true && flag_u2 == true)
                    break;
            }
            temp = gi_H[u1];
            gi_H[u1] = gi_H[u2];
            gi_H[u2] = temp;
            u1 = 0, u2 = 0;
            flag_u1 = false, flag_u2 = false;
            gi_H2[hj - 1] = p1;//替换在gi_H2中的编码
            //在gi中交换
            for (int j = 0; j < gi_n; j++) {
                if (gi[j] == p1) {
                    u1 = j;
                    continue;
                }
                if (gi[j] == p2) {
                    u2 = j;
                    continue;
                }
                if (flag_u1 == true && flag_u2 == true)
                    break;
            }
            temp = gi[u1];
            gi[u1] = gi[u2];
            gi[u2] = temp;
            u1 = 0, u2 = 0;
            break;
        }
    }
}
// todo 重载 decide_swap()
void decide_swap(Food &food, int gi[], int gi_H2[], int gi_th[], int gi_H[], int thi, int p, int gi_h, int hj, int gi_n) {//hj表示堆垛机读取的当前回库编码数量
    int *g = food.getSequenceAddress();
    int u1 = 0, u2 = 0, temp = 0;//u1，u2表示需要交换编码的下标
    int p1 = 0;
    bool flag_u1 = false, flag_u2 = false;
    p_model = judge_model(p);
    if(p_model == 0){
        p1 = hi[p_model][a_0 - 1][0];//时间最短的回库编码
    }
    else if(p_model == 1){
        p1 = hi[p_model][a_1 - 1][0];
    }
    else if(p_model == 2){
        p1 = hi[p_model][a_2 - 1][0];
    }
    else if(p_model == 3){
        p1 = hi[p_model][a_3 - 1][0];
    }
    else if(p_model == 4){
        p1 = hi[p_model][a_4 - 1][0];
    }
    else{
        cout<<"decide_swap p_model error!"<<endl;
    }
    //p1 = hi[p_model][ - 1][0];//时间最短的回库编码
    int ddj = stacker(p1);//判断最短时间回库编码的堆垛机序号
    int p2 = 0;//要交换的编码
    for (int i = hj - 1; i < thi; i++) {//从读取到当前回库编码数量 开始 到所有已与送检编码匹配的回库编码数量为止
        if (p1 == gi_H2[hj - 1])break;//不需要交换
        else {//需要交换
            p2 = gi_H2[hj - 1];//与第一位的回库编码交换
            for (int j = 0; j < CODELENGTH; j++) {
                if (g[j] == p1) {
                    u1 = j;
                    flag_u1 = true;
                    continue;
                }
                if (g[j] == p2) {
                    u2 = j;
                    flag_u2 = true;
                    continue;
                }
                if (flag_u1 == true && flag_u2 == true)
                    break;
            }
            //在G中交换位置
            //temp = g[u1];
            //g[u1] = g[u2];
           // g[u2] = temp;
            //u1 = 0, u2 = 0;
            flag_u1 = false, flag_u2 = false;
            //在gi_h中交换
            for (int j = 0; j < gi_h; j++) {
                if (gi_H[j] == p1) {
                    u1 = j;
                    continue;
                }
                if (gi_H[j] == p2) {
                    u2 = j;
                    continue;
                }
                if (flag_u1 == true && flag_u2 == true)
                    break;
            }
            temp = gi_H[u1];
            gi_H[u1] = gi_H[u2];
            gi_H[u2] = temp;
            u1 = 0, u2 = 0;
            flag_u1 = false, flag_u2 = false;
            gi_H2[hj - 1] = p1;//替换在gi_H2中的编码
            //在gi中交换
            for (int j = 0; j < gi_n; j++) {
                if (gi[j] == p1) {
                    u1 = j;
                    continue;
                }
                if (gi[j] == p2) {
                    u2 = j;
                    continue;
                }
                if (flag_u1 == true && flag_u2 == true)
                    break;
            }
            temp = gi[u1];
            gi[u1] = gi[u2];
            gi[u2] = temp;
            u1 = 0, u2 = 0;
            break;
        }
    }
}
//找到时间最短的回库编码
int min_h(){
	//int Th = th1+th2+th3+th4+th5+th6-m1;//所有已读取送检编码的数量
    int Th = 0;//已读取送检编码的数量
    int i,j,i_model,p=0,sit=0;
    double temp;
    //m1 = a_0 + a_1 + a_2 + a_3 + a_4;
    //Th = b_0 + b_1 + b_2 + b_3 + b_4;
	//冒泡排序
    for(i_model =0;i_model<5;i_model++){
        if(i_model == 0){
            m1 = a_0;
            Th = b_0;
        }
        else if(i_model == 1){
            m1 = a_1;
            Th = b_1;
        }
        else if(i_model == 2){
            m1 = a_2;
            Th = b_2;
        }
        else if(i_model == 3){
            m1 = a_3;
            Th = b_3;
        }
        else if(i_model == 4){
            m1 = a_4;
            Th = b_4 ;
        }
        else{
            cout<<"min_h i_model error!"<<endl;
        }
        //主要是两两对比，将hi[][]数组根据回库时间进行排序，并且在排序时，其对应的回库编码也随着回库时间进行排序，保证hi[m1][0]始终为 本次所有回库编码的最短时间
        for( i=m1;i<Th-1;i++){//开始m1是0，从0开始循环，到所有已读取的送检数量为止。表示遍历 所有已读取送检编码数量 的 回库编码 和 回库时间
            for(j=m1;j<Th-1-i;j++){
                if(hi[i_model][j+1][1]<hi[i_model][j][1]){
                temp=hi[i_model][j+1][1];
                hi[i_model][j+1][1]=hi[i_model][j][1];
                hi[i_model][j][1]=temp;

                sit = hi[i_model][j+1][0];
                hi[i_model][j+1][0] = hi[i_model][j][0];
                hi[i_model][j][0] = sit;
                }
            }
        }
	}
    min_times[0] = hi[0][a_0][1];
    min_times[1] = hi[1][a_1][1];
    min_times[2] = hi[2][a_2][1];
    min_times[3] = hi[3][a_3][1];
    min_times[4] = hi[4][a_4][1];
    //min_times[5] = {hi[0][a_0][1],hi[1][a_1][1],hi[2][a_2][1],hi[3][a_3][1],hi[4][a_4][1]};
    sort(min_times,min_times+5);
    // double min_[5][1][2];//该数组保留每一种资产中回库时间最短的编码及回库时间
    // min_[0][0][0] = hi[0][a_0][0],min_[0][0][1] = hi[0][a_0][1];
    // min_[1][0][0] = hi[1][a_1][0],min_[1][0][1] = hi[1][a_1][1];
    // min_[2][0][0] = hi[2][a_2][0],min_[2][0][1] = hi[2][a_2][1];
    // min_[3][0][0] = hi[3][a_3][0],min_[3][0][1] = hi[3][a_3][1];
    // min_[4][0][0] = hi[4][a_4][0],min_[4][0][1] = hi[4][a_4][1];
    //min_times[0] 为最短回库时间
    if(min_times[0] == hi[0][a_0][1]){
        a_0++;
        if(hi[0][a_0][0]==INT32_MAX){
            a_0--;
        }
        //cout<<hi[0][a_0 - 1][0]<<endl;
        if(a_0==0)
            return hi[0][a_0][0];
        return hi[0][a_0 - 1][0];
    }
    else if(min_times[0] == hi[1][a_1][1]){
        a_1++;
        if(hi[1][a_1][0]==INT32_MAX){
            a_1--;
        }
        if(a_1==0)
            return hi[1][a_1][0];
        return hi[1][a_1 - 1][0];
    }
    else if(min_times[0] == hi[2][a_2][1]){
        a_2++;
        if(hi[2][a_2][0]==INT32_MAX){
            a_2--;
        }
        if(a_2==0)
            return hi[2][a_2][0];
        return hi[2][a_2 - 1][0];
    }
    else if(min_times[0] == hi[3][a_3][1]){
        a_3++;
        if(hi[3][a_3][0]==INT32_MAX){
            a_3--;
        }
        if(a_3==0)
            return hi[3][a_3][0];
        return hi[3][a_3 - 1][0];
    }
    else if(min_times[0] == hi[4][a_4][1]){
        a_4++;
        if(hi[4][a_4][0]==INT32_MAX){
            a_4--;
        }
        if(a_4==0)
            return hi[4][a_4][0];
        return hi[4][a_4 - 1][0];
    }
    else{
        cout<<"min_h error!"<<endl;
        return 0;
    }
    // cout<<"min_h error!"<<endl;
    // return 0;
	//快速排序
	//quickSortHelp(hi, m1, Th-1);
	// m1++;//本次读取的最短回库编码的回库时间已找到，移动到下一位，此后，位于v之前的回库编码不再参与比较
	// if(hi[m1-1][0]==INT32_MAX)
	// 	m1--;
	// return hi[m1-1][0];//返回最短回库时间的回库编码
}
// todo 重载 Fitness()
double Fintess(Food& f,int g1[],int g2[],int g3[],int g4[],int g5[],int g6[],int g1_H[],int g2_H[],int g3_H[],int g4_H[],int g5_H[],int g6_H[],int g1_H2[],int g2_H2[],int g3_H2[],int g4_H2[],int g5_H2[],int g6_H2[],int g1_th[],int g2_th[],int g3_th[],int g4_th[],int g5_th[],int g6_th[]){
    T1=0,T2=0,T3=0,T4=0,T5=0,T6=0;
    TD1=0,TD2=0,TD3=0,TD4=0,TD5=0,TD6=0;
    j_1=0, j_2=0, j_3=0, j_4=0, j_5=0, j_6=0;
    h1=0,h2=0,h3=0,h4=0,h5=0,h6=0;
    th1=0,th2=0,th3=0,th4=0,th5=0,th6=0;
    aa = 0,bb = 0;
    outbound_i = 0;
    inspect_volume_a_now[0] = 0;
    inspect_volume_b_now[0] = 0;
    int ddj=0,p=0;
    a_0 = 0,a_1 = 0,a_2 = 0,a_3 = 0,a_4 = 0; 
    b_0 = 0,b_1 = 0,b_2 = 0,b_3 = 0,b_4 = 0;
    m1 = 0;m2=0;
    TD[0]=0;
    //按照堆垛机顺序，依次读取编码，直到读取到回库编码为止
    read_ddj(g1_H,1,g1);
    read_ddj(g2_H,2,g2);
    read_ddj(g3_H,3,g3);
    read_ddj(g4_H,4,g4);
    read_ddj(g5_H,5,g5);
    read_ddj(g6_H,6,g6);

    //void decide_swap(firefly& f,int gi_H2[],int gi_th[],int gi_H[],int thi,int p,int gi_h,int hi)
    for(int i=0;i< H - _k - 6; i++){
        p = min_h();//最短回库时间的回库编码
        if(p==INT32_MAX)
            break;
        if(p==0){
            cout<<"p error"<<endl;
            //p = min_h();
        }
        ddj = stacker(cargo_now[p-1].line-4);//获取该编码的堆垛机序号
        switch (ddj)//判断 最短回库时间的回库编码的 堆垛机序号
        {
            case 1://如果是1号堆垛机，则先判断是否需要交换回库编码的为止，再读不断读取1号堆垛机的编码，直到读取到回库编码为止
                decide_swap(f.getSequenceAddress(),g1,g1_H2,g1_th,g1_H,th1,p,g1_h,h1,g1_n);//交换回库编码位置
                read_ddj(g1_H,1,g1);//读取编码，直到回库编码
                break;//跳出，继续获得最短回库时间
            case 2:
                decide_swap(f.getSequenceAddress(),g2,g2_H2,g2_th,g2_H,th2,p,g2_h,h2,g2_n);
                read_ddj(g2_H,2,g2);
                break;
            case 3:
                decide_swap(f.getSequenceAddress(),g3,g3_H2,g3_th,g3_H,th3,p,g3_h,h3,g3_n);
                read_ddj(g3_H,3,g3);
                break;
            case 4:
                decide_swap(f.getSequenceAddress(),g4,g4_H2,g4_th,g4_H,th4,p,g4_h,h4,g4_n);
                read_ddj(g4_H,4,g4);
                break;
            case 5:
                decide_swap(f.getSequenceAddress(),g5,g5_H2,g5_th,g5_H,th5,p,g5_h,h5,g5_n);
                read_ddj(g5_H,5,g5);
                break;
            case 6:
                decide_swap(f.getSequenceAddress(),g6,g6_H2,g6_th,g6_H,th6,p,g6_h,h6,g6_n);
                read_ddj(g6_H,6,g6);
                break;
            default:
                cout<<"Fintess decide_swap error!"<<endl;
                break;
        }
    }

//判断6个子序列编码是否全部读取完毕
    if(j_1 + j_2 + j_3 + j_4 + j_5 + j_6 == CODELENGTH){
        T[0] = T1;T[1] = T2;T[2] = T3;T[3] = T4;T[4] = T5;T[5] = T6;
        return max2(T, f);
    }
    if(j_1 < g1_n){
        while(j_1 != g1_n){
            if(j_1 < (g1_n - 2)){//不属于最后一位编码
				T1 = read(T1, TD1, g1[j_1], g1[j_1 + 1],g1[j_1 + 2]);//读取编码
				j_1++;//堆垛机数组编码自增1
			}
			else if(j_1 == (g1_n - 2)){//如果读取到该堆垛机的最后一位编码，则下一条编码与当前编码相同
				T1 = read(T1, TD1, g1[j_1], g1[j_1+1],g1[j_1+1]);
				j_1++;
			}
            else if(j_1 == (g1_n - 1)){
                T1 = read(T1, TD1, g1[j_1], g1[j_1],g1[j_1]);
				j_1++; 
            } 
			if(j_1 > g1_n - 1)//如果该堆垛机的编码全部读取完毕 
				break;//跳出循环 
        }
    }

    if(j_2 < g2_n){
        while(j_2 != g2_n){
            if(j_2 < (g2_n - 2)){
				T2 = read(T2, TD2, g2[j_2], g2[j_2 + 1],g2[j_2 + 2]);
				j_2++;
			}
			else if(j_2 == (g2_n - 2)){
				T2 = read(T2, TD2, g2[j_2], g2[j_2+1],g2[j_2+1]);
				j_2++;
			}	
            else if(j_2 == (g2_n -1)){
                T2 = read(T2, TD2, g2[j_2], g2[j_2],g2[j_2]);
				j_2++;
            }
			if(j_2 > g2_n - 1)
				break;
        }
    }

    if(j_3 < g3_n){
        while(j_3 != g3_n){
            if(j_3 < (g3_n - 2)){
				T3 = read(T3, TD3, g3[j_3], g3[j_3 + 1],g3[j_3 + 2]);
				j_3++;
			}
			else if(j_3 == (g3_n - 2)){
				T3 = read(T3, TD3, g3[j_3], g3[j_3 + 1], g3[j_3 + 1]);
				j_3++;
			}	
            else if(j_3 == (g3_n - 1)){
				T3 = read(T3, TD3, g3[j_3], g3[j_3], g3[j_3]);
				j_3++;
			}	
			if(j_3 > g3_n - 1)
				break;
        }
    }

    if(j_4 < g4_n){
        while(j_4 != g4_n){
            if(j_4 < (g4_n - 2)){
				T4 = read(T4, TD4, g4[j_4], g4[j_4 + 1], g4[j_4 + 2]);
				j_4++;
			}
            else if(j_4 == (g4_n - 2)){
				T4 = read(T4, TD4, g4[j_4], g4[j_4 + 1], g4[j_4 + 1]);
				j_4++;
			}
			else if(j_4 == (g4_n - 1)){
				T4 = read(T4, TD4, g4[j_4], g4[j_4],g4[j_4]);
				j_4++;
			}	
			if(j_4 > g4_n - 1)
				break;
        }
    }

    if(j_5 < g5_n){
        while(j_5 != g5_n){
            if(j_5 < (g5_n - 2)){
				T5 = read(T5, TD5, g5[j_5], g5[j_5 + 1], g5[j_5 + 2]);
				j_5++;
			}
			else if(j_5 == (g5_n - 2)){
				T5 = read(T5, TD5, g5[j_5], g5[j_5 + 1], g5[j_5 + 1]);
				j_5++;
			}
            else if(j_5 == (g5_n - 1)){
				T5 = read(T5, TD5, g5[j_5], g5[j_5], g5[j_5]);
				j_5++;
			}	
			if(j_5 > g5_n - 1)
				break;
        }
    }

    if(j_6 < g6_n){
        while(j_6 != g6_n){
           if(j_6 < (g6_n - 2)){
				T6 = read(T6, TD6, g6[j_6], g6[j_6 + 1], g6[j_6 + 2]);
				j_6++;
			}
			else if(j_6 == (g6_n - 2)){
				T6 = read(T6, TD6, g6[j_6], g6[j_6 + 1], g6[j_6 + 1]);
				j_6++;
			}
            else if(j_6 == (g6_n - 1)){
				T6 = read(T6, TD6, g6[j_6], g6[j_6], g6[j_6]);
				j_6++;
			}		
			if(j_6 > g6_n - 1)
				break;
        }
    }


    T[0] = T1;T[1] = T2;T[2] = T3;T[3] = T4;T[4] = T5;T[5] = T6;
    return max2(T, f);
}
// todo 重载 ensimpleCode()
void enSimpleCode(Food& f) {
    //初始化一些变量
    //fre1 = f.getFre();
    //fre2 = f.getFre();
    int b1 = INT32_MAX;
    ai = 0;
    flag_R = 0;
    t_R = 0;
	//11.3 go
	gp1 = 0,gp2 = 0,gp3 = 0,gp4 = 0,gp5 = 0,gp6 = 0;
	gpi=0;
    enterI = 0;
	for(int i=0;i<NUM_ddj;i++)
		for(int j=0;j<ddj_num;j++)
			gp[i][j][1] = INT32_MAX;
	//11.3 end
    for(int i=0;i<R;i++){
        r_arry[i] = 0;
        a[i] = 0;
    }
    for(int i=0;i<NUM_ddj;i++){
        T[i] = 0;
        TD[i] = 0;
    }
    for(int i=0;i<H;i++){
        I[i][0] = 0;
        I[i][1] = 0;
        INum[i][0] = 0;
        INum[i][1] = 0;
        g1_H2[i] = 0;
        g2_H2[i] = 0;
        g3_H2[i] = 0;
        g4_H2[i] = 0;
        g5_H2[i] = 0;
        g6_H2[i] = 0;
    }
    for(int i=0;i<NUM_model;i++){
        for(int j=0;j<H;j++){
            hi[i][j][0]=INT32_MAX;
            hi[i][j][1]=INT32_MAX;
        }
    }
    for(int i=0;i<NUM_ddj;i++){
        for(int j=0;j<R;j++){
            for(int ii=0;ii<2;ii++){
                enter_block[i][j][ii][0] = INT32_MAX;
                enter_block[i][j][ii][1] = INT32_MAX;
                enter_block[i][j][ii][2] = 0;
            }
        }
    }
    S_H(f);//送检前h-k个编码，回库后h-k个编码，形成1-1对应关系。
    check(f.getSequenceAddress(),s,h);
    get_R(f.getSequenceAddress());//分离出入库编码
    R_Test(r_arry);//计算出入库货物到达堆垛机的时间，从小到大排序
/*
	for(int i=0;i<R;i++){
		cout<<a[i]<<endl;
	}
	cout<<"---------"<<endl;
*/
    //cout<<endl;
    Storing_num(f);//计算出每台堆垛机的任务量、送检数量、回库数量
    int g1_S[g1_s],g2_S[g2_s],g3_S[g3_s],g4_S[g4_s],g5_S[g5_s],g6_S[g6_s];//送检任务分拣到6台堆垛机
    int g1_H[g1_h],g2_H[g2_h],g3_H[g3_h],g4_H[g4_h],g5_H[g5_h],g6_H[g6_h];//回库任务分拣到6台堆垛机
    int g1_th[g1_h],g2_th[g2_h],g3_th[g3_h],g4_th[g4_h],g5_th[g5_h],g6_th[g6_h];//6台堆垛机的回库任务的时间
    int g1[g1_n],g2[g2_n],g3[g3_n],g4[g4_n],g5[g5_n],g6[g6_n];//任务分拣到6台堆垛机

    for(int i=0;i<g1_h;i++){g1_th[i]=INT32_MAX;g1_H2[i]=0;}
    for(int i=0;i<g2_h;i++){g2_th[i]=INT32_MAX;g2_H2[i]=0;}
    for(int i=0;i<g3_h;i++){g3_th[i]=INT32_MAX;g3_H2[i]=0;}
    for(int i=0;i<g4_h;i++){g4_th[i]=INT32_MAX;g4_H2[i]=0;}
    for(int i=0;i<g5_h;i++){g5_th[i]=INT32_MAX;g5_H2[i]=0;}
    for(int i=0;i<g6_h;i++){g6_th[i]=INT32_MAX;g6_H2[i]=0;}

    Storing(f,g1,g2,g3,g4,g5,g6,g1_S,g2_S,g3_S,g4_S,g5_S,g6_S,g1_H,g2_H,g3_H,g4_H,g5_H,g6_H);//将每台堆垛机的工作和送检、回库任务分离成不同的数组。共18个数组
    //f.fitness=Fintess(f,g1,g2,g3,g4,g5,g6,g1_H,g2_H,g3_H,g4_H,g5_H,g6_H );
    f.setFitness(Fintess(f,g1,g2,g3,g4,g5,g6,g1_H,g2_H,g3_H,g4_H,g5_H,g6_H,g1_H2,g2_H2,g3_H2,g4_H2,g5_H2,g6_H2,g1_th,g2_th,g3_th,g4_th,g5_th,g6_th)); //计算适应度值
    // get_inspect();//获取动态检定数量数组
    // get_outbound();//获取出库数组
    // out_block(10);//10s出库一垛
    // get_out_block();//出库堵塞输出到文件
//    f.fluorescein = (1-rou)*f.fluorescein + mgamma / f.fitness;

}
//对种群进行解码
void enCode(Food *f) {
    //按照自己的方法对 初始种群 中的每个个体进行解码，计算出目标函数
    //先写对一条编码的解码，再循环调用
    for(int i=0;i<FoodsNum;i++){
        enSimpleCode(f[i]);
        //cout<<fly[0].G[1999];
    }
    // enSimpleCode(fly[0]);
    // enSimpleCode(fly[1]);
    // enSimpleCode(fly[2]);
}
