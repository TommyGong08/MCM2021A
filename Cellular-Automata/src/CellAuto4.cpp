#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstdio>
#include<string.h>
using namespace std;

int main()
{
    int cell_size = 22;int N[10];int T = 100;   //interation 
    int T_iteration = 100;
    double NP[12] = {0};double p_ij[12] = {0};double max_NP,min_NP,max_fp;
    double NP_mean,deita,sum_NP;double fp[12] = {0};
    int veg[100][100] = {0};int veg_temp[100][100] = {0};
    double p[12] ;    int count_cell[12]; 
    //consider Shandong province
    int T_season[15] = {12,16, 20, 24,21,17,14,9,4,0,4,8};//from Juanuary
    int mos_season[15] = { 63,69,75, 79,75,71, 68,64,62, 61,62,62};
    double mos_i[12] = {0,80,75,70,60,55,50,70,65,60}; //不同真菌的极限湿度
    double T_i[12] = {0,22,23,24,24,25,26,26,27,28};    //不同真菌的极限温度
    double mos_env = 100; //environment moisture
    double T_env  = 35; //environment temperature
    //double T_env_mutation[30] = {14,14,14,14,14,14,14,14,14,14,0,0,0,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14};
    double alpha[12],beita[12];
    double kM_i[12] = {0,10,10,10,10,10,10,10,10,10}, kT_i[12]= {0,1000,1000,1000,1000,1000,1000,1000,1000,1000};
    memset(alpha,0,sizeof(alpha));
    memset(beita,0,sizeof(beita));
    int v_ex[12] = {0, 100, 100, 100, 101 , 101, 101,99,99,99};
    for(int t = 1;t <= 9;t++)
    {
        alpha[t] = (kM_i[t] * abs(mos_i[t] - mos_env)) / mos_i[t];
        beita[t] = (kT_i[t] * abs(T_i[t] - T_env)) / T_i[t]; 
        p[t] = v_ex[t] * alpha[t] * beita[t];
        cout << alpha[t]  << "   " << beita[t] <<  "   "<< p[t] << endl;
    }
    memset(veg,0,sizeof(veg));
    cout << "===================init veg==================" << endl;
    int rand_num;
    memset(count_cell,0,sizeof(count_cell));
    for (int i = 0; i < cell_size; i++)
	{
		for (int j = 0; j < cell_size; j++)
		{
            //random num from [1,10] ,80% cells are empty
			rand_num = (rand() % 10) + 1 ;
            if(rand_num <= 8) veg[i][j] = 0;
            else
            {
                rand_num = (rand() % 9) + 1;
                veg[i][j] = rand_num;
                count_cell[rand_num]++;
            }
		}
	}
    cout << "=============================================" << endl;
    cout << "        A    B     C    D    E   F   G   H   I " << endl;
    cout << "T : " << T_iteration -T << " ";
    for(int i = 1 ;i <= 9 ;i++)
    {
        cout << count_cell[i] << " ";
    }
    cout << endl;
    //assumption that T_season equals one season
    while(T--)
    {
        //seasonal changes
       // T_env += 0.022;
        //set iteration cycle
        //T_env =  T_season[(T_iteration - T) % 12 ];
        // mos_env = mos_season[(T_iteration - T)  % 12];
       // T_env = T_env_mutation[T_iteration - T];
    //     for(int t = 1;t <= 9;t++)
    //    {
    //        alpha[t] = (kM_i[t] * abs(mos_i[t] - mos_env)) / mos_i[t];
    //        beita[t] = (kT_i[t] * abs(T_i[t] - T_env)) / T_i[t]; 
    //        p[t] = v_ex[t] * alpha[t] * beita[t];
    //       //  cout <<  " t : " << t << " alpha : " << alpha[t]  << "  beita: " << beita[t] <<  " p: "<< p[t] << endl;
    //    }
        for(int i = 1;i < cell_size - 1; i++)
        {
            for(int j = 1; j < cell_size - 1; j++)
            {
                memset(N,0,sizeof(N));
                memset(NP,0,sizeof(NP));
                memset(fp,0,sizeof(fp));
                if(veg[i][j] == 0)
                {
                    //analyse moore neighborhood
                    N[veg[i-1][j-1]]++; N[veg[i-1][j]]++; N[veg[i-1][j+1]]++;
                    N[veg[i][j-1]]++; N[veg[i][j]]++; N[veg[i][j+1]]++;
                    N[veg[i+1][j-1]]++; N[veg[i+1][j]]++; N[veg[i+1][j+1]]++;
                    if(N[1]+N[2]+ N[3]+ N[4]+ N[5] + N[6]+ N[7] + N[8] + N[9] == 0) 
                    {
                        veg_temp[i][j]=0;
                        break;
                    }
                    for(int t = 1 ; t <= 9;t++)
                    {
                        NP[t] = N[t] * p[t];
                    }
                    NP_mean = (NP[1] + NP[2] + NP[3] + NP[4] + NP[5] + NP[6] + NP[7] + NP[8]+ NP[9]) / 9 ;

                    for(int t = 1 ; t <= 9 ;t++)
                    {
                        sum_NP += (NP[t]-NP_mean) * (NP[t]-NP_mean);
                    }
                    deita = sqrt(sum_NP/ 9);
                    max_fp = -99999;
                    for(int t = 1 ; t <= 9 ; t++)
                    {
                        p_ij[t] = (NP[t] - NP_mean) / deita;
                        fp[t] = 1/(1 + exp(-3 * p_ij[t]));
                        if(fp[t] > max_fp) 
                        {
                            max_fp = fp[t];
                            if(fp[t] > 0.5)    veg_temp[i][j] = t;
                            else veg_temp[i][j] = veg[i][j];
                        }
                    } 
                }
                else if(veg[i][j] != 0)
                {
                    N[veg[i-1][j-1]]++; N[veg[i-1][j]]++; N[veg[i-1][j+1]]++;
                    N[veg[i][j-1]]++; N[veg[i][j]]++; N[veg[i][j+1]]++;
                    N[veg[i+1][j-1]]++; N[veg[i+1][j]]++; N[veg[i+1][j+1]]++;

                    max_NP = -99999;
                    min_NP = 99999;
                    for(int t = 1 ; t <= 9;t++)
                    {
                        NP[t] = N[t] * p[t];
                        if(NP[t] > max_NP) max_NP = NP[t];
                        if(NP[t] < min_NP) min_NP = NP[t];
                    }
                    max_fp = -99999;
                    for(int t = 1 ; t <= 9;t++)
                    {
                        p_ij[t] = (NP[t] - NP[veg[i][j]]) / (max_NP - min_NP);
                        fp[t] = 1/(1 + exp(-3 * p_ij[t]));
                        if(fp[t] > max_fp) 
                        {
                            max_fp = fp[t];
                            veg_temp[i][j] = t;
                        }
                    }
                }
            }
        }
        memset(count_cell, 0 , sizeof(count_cell));
        for(int i = 0;i < cell_size ;i++)
        {
            for(int j = 0 ; j < cell_size ; j++){
                veg[i][j] = veg_temp[i][j];
                count_cell[veg[i][j]]++;
            }
        }
        cout << "T : " << T_iteration - T << "  "; 
        for(int i = 1 ;i <= 9 ;i++){
            cout << count_cell[i] << " ";
        }
        cout << endl;
    }
    return 0;
}