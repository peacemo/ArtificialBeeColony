//输出货位信息到文件

void getCargo_now(string File_name1,string File_name2){
    ofstream out1;
	ofstream out_sit;
	out1.open(File_name1);
	out_sit.open(File_name2);
	for(int i=0;i<n;i++){
		out1<<"{"<<cargo_now[i].x<<","<<cargo_now[i].y<<","<<cargo_now[i].z<<","<<cargo_now[i].s1<<","<<cargo_now[i].s2<<","<<cargo_now[i].num<<","<<"'a'"<<","<<cargo_now[i].model<<","<<cargo_now[i].time<<"}"<<",";
		out_sit<<cargo_now[i].x<<","<<cargo_now[i].y<<","<<cargo_now[i].z<<","<<judge_type(i)<<endl;
		if((i+1)%5==0){
			out1<<endl;	
		}
	}
	out1.close();
	out_sit.close();
}

void getCargo(string file_name1,string file_name2){
    ofstream outf,outd;
    outf.open(file_name1);
    outd.open(file_name2);
    for(int i=0;i<n_total;i++){
        outf<<"{"<<cargo[i].x<<","<<cargo[i].y<<","<<cargo[i].z<<","<<cargo[i].s1<<","<<cargo[i].s2<<","<<cargo[i].num<<","<<"'a'"<<","<<cargo[i].model<<","<<cargo[i].time<<"}"<<",";
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
    out.open("candidate.txt");
    for(int i=0;i<3000;i++){
          out<<"{"<<G_r[i].x<<","<<G_r[i].y<<","<<G_r[i].z<<","<<G_r[i].s1<<","<<G_r[i].s2<<","<<G_r[i].num<<","<<"'a'"<<","<<G_r[i].model<<","<<G_r[i].time<<"}"<<",";
          if((i+1)%5==0){
			out<<endl;	
		}
    }
    out<<endl;
    for(int i=0;i<3000;i++){
          out<<"{"<<G_s[i].x<<","<<G_s[i].y<<","<<G_s[i].z<<","<<G_s[i].s1<<","<<G_s[i].s2<<","<<G_s[i].num<<","<<"'a'"<<","<<G_s[i].model<<","<<G_s[i].time<<"}"<<",";
          if((i+1)%5==0){
			out<<endl;	
		}
    }
    out<<endl;
    for(int i=0;i<3000;i++){
          out<<"{"<<G_h[i].x<<","<<G_h[i].y<<","<<G_h[i].z<<","<<G_h[i].s1<<","<<G_h[i].s2<<","<<G_h[i].num<<","<<"'a'"<<","<<G_h[i].model<<","<<G_h[i].time<<"}"<<",";
          if((i+1)%5==0){
			out<<endl;	
		}
    }
    out<<endl;
    for(int i=0;i<3000;i++){
          out<<"{"<<G_c[i].x<<","<<G_c[i].y<<","<<G_c[i].z<<","<<G_c[i].s1<<","<<G_c[i].s2<<","<<G_c[i].num<<","<<"'a'"<<","<<G_c[i].model<<","<<G_c[i].time<<"}"<<",";
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
            for(int i=0;i<3000 && count<S;i++){
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
            for(int i=0;i<3000 && count<C;i++){
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
    for(int i=0;i<n;i++){
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
    
    for(int i=0;i<8112;i++){
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