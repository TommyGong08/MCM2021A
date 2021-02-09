//考虑温度与湿度

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstdio>
#include<string.h>
using namespace std;

int main()
{
    int cell_size = 22;
    int N[10] = {0};
    int T = 30;   //迭代次数
    int T_iteration = 30;
    double NP[10] = {0};
    double p_ij[10] = {0};
    double max_NP,min_NP,max_fp;
    double NP_mean,deita,sum_NP;
    double fp[10] = {0};
    int veg[100][100] = {0};
    int veg_temp[100][100] = {0};
    double p[5] ;    
    int count_cell[10]; 

    //考虑长期影响
    //以A为标准100

    double mos_i[10] = {0,100,100,100};
    double T_i[10] = {0,30,30,30};
    double mos_env = 69; //当前环境湿度
    double T_env = 22; //当前环境温度
    double alpha[10],beita[10];
    double kM = 10;
    double kT = 10;
    memset(alpha,0,sizeof(alpha));
    memset(beita,0,sizeof(beita));
    int v_ex[10] = {0, 105,100,95};
    for(int t = 1;t <= 3;t++)
    {
        alpha[t] = (kM * abs(mos_i[t] - mos_env)) / mos_i[t];
        beita[t] = (kT * abs(T_i[t] - T_env)) / T_i[t]; 
        p[t] = v_ex[t] * alpha[t] * beita[t];
        cout << alpha[t]  << "   " << beita[t] <<  "   "<< p[t] << endl;
    }

   cout << "===================init veg==================" << endl;
    int rand_num;//随机整数
    memset(count_cell,0,sizeof(count_cell));
    for (int i = 0; i < cell_size; i++)
	{
		for (int j = 0; j < cell_size; j++)
		{
            //[1,10]随机整数,刚开始80%为空
			rand_num = (rand() % 10) + 1 ;
            if(rand_num <= 8) veg[i][j] = 0;
            else
            {
                rand_num = (rand() % 4) + 1;
                veg[i][j] = rand_num;
                count_cell[rand_num]++;
            }
            cout << veg[i][j] << "  ";
		}
       cout << endl << endl;
	}
    cout << "=============================================" << endl;
    
    cout << "        A    B     C    D" << endl;
    cout << "T : " << T_iteration - T<< " ";
    for(int i = 1 ;i <= 3 ;i++)
    {
        cout << count_cell[i] << " ";
    }
    cout << endl;
    while(T--)
    {
        for(int i = 1;i < cell_size - 1; i++)
        {
            for(int j = 1; j < cell_size - 1; j++)
            {
                memset(N,0,sizeof(N));
                memset(NP,0,sizeof(NP));
                memset(fp,0,sizeof(fp));
                //当元胞为空
                if(veg[i][j] == 0)
                {
                    //分析8邻域
                    N[veg[i-1][j-1]]++; N[veg[i-1][j]]++; N[veg[i-1][j+1]]++;
                    N[veg[i][j-1]]++; N[veg[i][j]]++; N[veg[i][j+1]]++;
                    N[veg[i+1][j-1]]++; N[veg[i+1][j]]++; N[veg[i+1][j+1]]++;
                    if(N[1]+N[2]+ N[3] == 0) 
                    {
                        veg_temp[i][j]=0;
                        break;
                    }
                    for(int t = 1 ; t <= 3;t++)
                    {
                        NP[t] = N[t] * p[t];
                    }
                    NP_mean = (NP[1] + NP[2] + NP[3] ) / 3 ;
                    //总体标准差
                    for(int t = 1 ; t <= 3 ;t++)
                    {
                        sum_NP += (NP[t]-NP_mean) * (NP[t]-NP_mean);
                    }
                    deita = sqrt(sum_NP/ 3);
                    max_fp = -99999;
                    for(int t = 1 ; t <= 3 ; t++)
                    {
                        p_ij[t] = (NP[t] - NP_mean) / deita;
                        fp[t] = 1/(1 + exp(-3 * p_ij[t]));
                        if(fp[t] > max_fp) 
                        {
                            max_fp = fp[t];
                            if(fp[t] > 0.5)    veg_temp[i][j] = t;
                            else veg_temp[i][j] = veg[i][j];
                        }
                        //cout << "case 0 :" <<  "t: " << t << "  fp[t]: " << fp[t] << "  max_fp: " << max_fp <<"  NP[t]: " << NP[t] << "  max_NP: " << max_NP << "  min_NP: " << min_NP << "  N[t]: " << N[t] << " p[t]: " << p[t] <<  endl;
                        //cout << "case0:"  << "t: " << t << "  fp[t]: " << fp[t] << endl;
                    } 
                }
                else if(veg[i][j] != 0)
                {
                    //分析8邻域
                    N[10] = {0};
                    N[veg[i-1][j-1]]++; N[veg[i-1][j]]++; N[veg[i-1][j+1]]++;
                    N[veg[i][j-1]]++; N[veg[i][j]]++; N[veg[i][j+1]]++;
                    N[veg[i+1][j-1]]++; N[veg[i+1][j]]++; N[veg[i+1][j+1]]++;
                    //竞争关系
                    max_NP = -99999;
                    min_NP = 99999;
                    for(int t = 1 ; t <= 3;t++)
                    {
                        NP[t] = N[t] * p[t];
                        if(NP[t] > max_NP) max_NP = NP[t];
                        if(NP[t] < min_NP) min_NP = NP[t];
                    }
                    max_fp = -99999;
                    for(int t = 1 ; t <= 3;t++)
                    {
                        p_ij[t] = (NP[t] - NP[veg[i][j]]) / (max_NP - min_NP);
                        fp[t] = 1/(1 + exp(-3 * p_ij[t]));
                        if(fp[t] > max_fp) 
                        {
                            max_fp = fp[t];
                            veg_temp[i][j] = t;
                        }
                        //cout << "case1:"  << "t: " << t << "  fp[t]: " << fp[t] << "  max_fp: " << max_fp <<"  NP[t]: " << NP[t] << "  max_NP: " << max_NP << "  min_NP: " << min_NP << "  N[t]: " << N[t] << " p[t]: " << p[t] <<  endl;
                       // cout << "case1:"  << "t: " << t << "  fp[t]: " << fp[t] << endl;
                    }
                }
            }
        }
        memset(count_cell, 0 , sizeof(count_cell));
        for(int i = 0;i < cell_size ;i++)
        {
            for(int j = 0 ; j < cell_size ; j++)
            {
                veg[i][j] = veg_temp[i][j];
                count_cell[veg[i][j]]++;
            }
        }
        cout << "T : " << T_iteration -T << "  "; 
        for(int i = 1 ;i <= 3 ;i++)
        {
            cout << count_cell[i] << " ";
        }
        cout << endl;
        /*
        if(T % 10 == 0)
        {
            cout << " T : "  << T << endl;
            for(int i = 0; i < cell_size ;i++)
            {
                for(int j = 0 ;j < cell_size ;j++)
                {
                    cout << veg[i][j] << "  " ;
                }
                cout << endl << endl;
            }
        }
        */
    }
    
    return 0;
}