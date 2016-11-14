/**
name：  选择排序演示
author：Newnius
blog:   http://blog.newnius.com
data：  2015-3-26
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

#define MAXN 10

int select_sort(int *, int);

int main()
{
	int src[MAXN];
	//先随机生成MAXN个数字，做测试用
	for(int i=0; i<MAXN; i++)
		src[i] = rand()%10000;

	/**输出原始数据*/
	for(int i=0; i<MAXN; i++)
		cout<<src[i]<<" ";
	cout<<endl;

	/**执行选择排序*/
	select_sort(src, MAXN);

	/**检查排序结果*/
	for(int i=0; i<MAXN-1; i++)
	{
		if(src[i] > src[i+1]){
			cout<<"wrong"<<endl;
		}
	}
	cout<<"sort finished!"<<endl;
	return 0;
}

/*
 * 选择排序
 * @param int* src 待排序数组
 * @param int size 待排序数组大小
 * 默认执行升序排序
 */

int select_sort(int *src, int size){
	int min;
	/*找出第i小的元素并将该元素放在第i位上*/
	for(int i=0; i<size; i++)
	{
		min=i;
		//跟它后面的元素比较，选出从第i位开始最小的
		for(int j=i+1; j<size; j++)
		{
			min=src[j] < src[min]?j:min;
		}
		//交换使得第i位上元素为第i小元素
		swap(src[i], src[min]);
	}
	return 0;
}
