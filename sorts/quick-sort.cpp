/*
 * Name: 快速排序演示
 * Author: Newnius
 * Date: 2014-9-8
 */

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

const int MAXN=100000;//测试用的数据个数

//自定义的排序方式，下面的为增序
bool cmp(int a, int b){
	return a<b;
}

//快速排序部分，参数形式与标准库的快排一样
//ps：(point start)所需排序的数据首地址
//pe：(point end)  所需排序的数据第一个无效地址
//cmp：自定义的比较函数
int sort(int *ps, int *pe, bool(*cmp)(int, int))
{
	if(pe-ps<=1)return 0;//递归出口

	//当待排序的数据足够小时改用处理小数据更快的插入排序
	/*
	if(pe-ps < 5)
	{
		insertsort(ps, pe, cmp);
	}
	*/

	int i = 1;
	int j = pe-ps-1;

	/*
	 * 加入了随机化的快速排序
	 * 有效防止对已基本有序的数据排序所带来的退化
	 * 可以自己模拟以加快速度，生成随机数也是很耗时间的
	 */
	/*
	int index = rand()%j;
	swap(ps[0], ps[j]);
	*/

	while(true)//这么写主要是考虑交换后还要做一次下面的两个循环
	{
		while(cmp(ps[i],ps[0]) && i<pe-ps-1)
			i++;//从左向右找到第一个比主元大的元素
		
		while(cmp(ps[0],ps[j])&&j>0)
			j--;//从右向左找到第一个比主元小的元素

		/*
		 * 如果主元最终位置左边有更大的元素，并且右边有更小的元素，则交换它们
		 * swap函数包含在标准库函数中，可以自己写成内联函数以加快速度
		 */
		if(i<j)
			swap(ps[i++], ps[j--]);	
		/*
		 * 左边找不到更大元素且右边找不到更小元素，说明
		 * 已满足主元最终位置左边都比主元小，右边亦然，则退出循环
		 */
		else 
			break;
	}

	//交换，使得主元到达最终位置
	swap(ps[0],ps[j]);
	//去掉注释观察每一步排序后的结果
	/*
	for(int k=0; k < pe-ps; k++)
		cout<<ps[k]<<" ";
	cout<<endl;
	cin.get();//按任意键继续
	*/

	sort(ps,ps+j,cmp);   //排主元左边元素
	sort(ps+j+1,pe,cmp); //排主元右边元素
	return 0;
}


int main(){
	//将当前时间作为种子，否则每次随机出的数据相同
	srand((unsigned)time(NULL));
	int aa[MAXN];

	//随机生成MAXN个测试数据
	for(int i=0; i<MAXN; i++)
		aa[i] = rand()%1000000;

	//打印未排序之前的数据
	/*
	for(int i=0;i<MAXN;i++)
			cout<<aa[i]<<" ";
	cout<<endl;
	*/

	//开始排序
	cout<<"sorting"<<endl;
	sort(aa,aa+MAXN,cmp);

	//打印排序后数据
	/*
	for(int i=0;i<MAXN;i++)
		cout<<aa[i]<<" ";
	cout<<endl;
	cout<<"sort finished"<<endl;
	*/

	//用这段代码来判断排序过程是否正确
	cout<<"checking"<<endl;
	int temp = aa[0];
	for(int i=0; i<MAXN; i++)
	{
		if(cmp(aa[i], temp))
			cout<<"wrong"<<endl;
			temp=aa[i];
	}
	cout<<"check finished"<<endl;
	return 0;
}
