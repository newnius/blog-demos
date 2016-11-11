/*
name：冒泡排序演示
author：Newnius
data：2014-9-10
*/

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

//测试用的数据个数。不要设的太大，不然会等死你的^-^
const int MAXN=1000;

//自定义的排序方式，下面的为增序
bool cmp(int a,int b)
{
    return a<b;
}

//冒泡排序部分，参数形式与标准库的快排一样
//ps：(point start)所需排序的数据首地址
//pe：(point end)  所需排序的数据第一个无效地址
//cmp：自定义的比较函数
int sort(int *ps,int *pe,bool(*cmp)(int,int))
{
    bool flag=true;//用以判断某次循环后是否有元素位置发生变化

    while(flag)
    {
        flag=false;//假设没有交换

        //上浮过程
        for(int i=1;i<pe-ps;i++)//注意：i从1开始
        {
            if(cmp(ps[i],ps[i-1]))
            {
                swap(ps[i],ps[i-1]);
                flag=true;//有元素发生交换，说明排序可能没有结束
            }
        }

        //下沉过程
        //防止特殊数据，例： 2 3 4 5 1
        //普通冒泡（单纯上浮）需要4趟，而加上下沉操作，则只有1+1=2次
        /*
        for(int i=pe-ps;i>0;i--)
        {
            if(cmp(ps[i],ps[i-1]))
            {
                swap(ps[i],ps[i-1]);
                flag=true;//有元素发生交换，说明排序可能没有结束
            }
        }
        */

        //去掉注释观察每一步排序后的结果
        /*
        for(int k=0;k<pe-ps;k++)
            cout<<ps[k]<<" ";
        cout<<endl;
        cin.get();
        */

    }
    return 0;
}


int main(){
    //将当前时间作为种子，否则每次随机出的数据相同
    srand((unsigned)time(NULL));
    int aa[MAXN];

    //随机生成MAXN个测试数据
    for(int i=0;i<MAXN;i++)aa[i]=rand()%1000000;

    //打印未排序之前的数据
    //for(int i=0;i<MAXN;i++)cout<<aa[i]<<" ";cout<<endl;

    //开始排序
    cout<<"sorting"<<endl;
    sort(aa,aa+MAXN,cmp);

    //打印排序后数据
    //for(int i=0;i<MAXN;i++)cout<<aa[i]<<" ";cout<<endl;
    cout<<"finished"<<endl;

    //用这段代码来判断排序过程是否正确
    cout<<"checking"<<endl;
    int temp=aa[0];
    for(int i=0;i<MAXN;i++)
    {
        if(cmp(aa[i],temp))cout<<"wrong"<<endl;
        temp=aa[i];
    }
    return 0;
}
