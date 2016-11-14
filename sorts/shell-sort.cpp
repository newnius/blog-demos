/**
name：  希尔排序演示
author：Newnius
blog:   http://blog.newnius.com
data：  2015-4-12
*/
#include<iostream>
#include<cstdlib>
#include<algorithm>
#define MAXN 10

using namespace std;


void shellSort(int *,int);
void shellSort2(int *,int);
void insertSort(int *,int, int);
int src[MAXN];

int main(){

    for(int i=0;i<MAXN;i++)src[i]=rand()%10000;//先随机生成MAXN个数字，做测试用
    for(int i=0;i<MAXN;i++)cout<<src[i]<<" ";cout<<endl;//输出原始数据

    //执行希尔排序
    shellSort(src,MAXN);
    for(int i=0;i<MAXN;i++)cout<<src[i]<<" ";cout<<endl;
    /**检查排序结果*/
    for(int i=0;i<MAXN-1;i++){
        if(src[i]>src[i+1]){
                cout<<"wrong"<<endl;
        }
    }
    cout<<"sort finished!"<<endl;
    return 0;
}

/**
 * 希尔排序
 */
void shellSort(int *src,int size){
    int step=size/2;
    while(step>=1){
        insertSort(src,size,step);
        step/=2;
    }
}

/**插入排序*/
void insertSort(int *src, int size, int step){
    int j,tmp;
    for(int i=0;i<size;i+=step){//从第一个元素开始，每次取出一个加入到有序序列中

        j=i;
        tmp=src[i];
        while(j>step-1&&tmp<src[j-step]){//找到新元素在有序序列中的位置
            src[j]=src[j-step];
            j-=step;
        }
        src[j]=tmp;
        //for(int k=0;k<size;k++)cout<<src[k]<<" ";cout<<endl;
    }
}



/**
 * 希尔排序
 * 取消了函数调用
 *
 */
void shellSort2(int *src,int size){
    int step=size/2;
    int j,tmp;
    while(step>=1){
        for(int i=0;i<size;i+=step){//从第一个元素开始，每次取出一个加入到有序序列中
            j=i;
            tmp=src[i];
            while(j>0&&tmp<src[j-step]){//找到新元素在有序序列中的位置
                src[j]=src[j-step];
                j-=step;
            }
            src[j]=tmp;
        }
        step/=2;
    }
}

