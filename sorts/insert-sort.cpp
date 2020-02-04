/**
name：  插入排序演示
author：Newnius
blog:   http://blog.newnius.com
data：  2015-3-25
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

#define MAXN 10


int insert_sort(int *,int);
int insert_sort2(int *,int);
int insert_sort3(int *,int);

int main(){
    int src[MAXN];
    for(int i=0;i<MAXN;i++)src[i]=rand()%10000;//先随机生成MAXN个数字，做测试用
    for(int i=0;i<MAXN;i++)cout<<src[i]<<" ";cout<<endl;//输出原始数据

    //执行插入排序
    insert_sort(src,MAXN);

    /**检查排序结果*/
    for(int i=0;i<MAXN-1;i++){
        if(src[i]>src[i+1]){
                cout<<"wrong"<<endl;
        }
    }
    cout<<"sort finished!"<<endl;
    return 0;
}

/**边检索位置边交换，代码简洁，但多一些赋值操作*/
int insert_sort(int *src, int size){
    for(int i=0;i<size;i++){//从第一个元素开始，每次取出一个加入到有序序列中
        int j=i;
        while(j>0&&src[j]<src[j-1]){//找到新元素在有序序列中的位置
            swap(src[j],src[j-1]);//交换函数。使用该函数会消耗一定的额外内存，建议自己写
            j--;
        }
    }
    return 0;
}


/*检索到位置后再插入，减少了一部分赋值语句*/
int insert_sort2(int *src, int size){
    int j,tmp;
    for(int i=0; i<size; i++){//从第一个元素开始，每次取出一个加入到有序序列中
        j=i;
        while(j>0 && src[i]<src[j-1]){//找到新元素在有序序列中的位置
            src[j]=src[j-1];
            j--;
        }
        src[j]=tmp;
    }
    return 0;
}

//edited by yqy
void insertsort(vector<int> &arr)
{
	for (int i = 1; i < arr.size(); ++i) //n-1次扫描，依次向前插入n-1个元素
	{
		int tmp = arr[i]; //每趟将a[i]插入到前面的排序子序列中
		int j = i - 1;
		while(j >= 0 && tmp < arr[j])
		{
			arr[j + 1] = arr[j];//将前面较大的元素向后移动 
			--j;
		}
		arr[j + 1] = tmp;//temp值到达插入位置
	}
}
//end 



/* 二分查找插入排序
 *  检索使用二分查找，减少了检索次数，但是赋值次数不会减少
 *  没有太大改进，而且代码不简洁。略
 */
int insert_sort3(int *src, int size){

    return 0;
}
