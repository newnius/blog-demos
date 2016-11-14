/*
name：归并排序演示
author：Newnius
data：2015-3-20
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<stack>
using namespace std;

#define MAXN 10

int merge_sort(int *,int,int);
int merge_sort2(int * ,int ,int,int *);
int merge_sort3(int *,int,int);
int merge_sort4(int *,int,int);

//for merge_sort3
class point{
public:
	int l;
	int r;
	int cnt;//第几次处理，第一次为分，第二次为合

	point(int l, int r){
		this->l=l;
		this->r=r;
		cnt=1;
	}
};


int main(){
	int src[MAXN];
	for(int i=0; i<MAXN; i++)
		src[i]=rand()%10000;//先随机生成MAXN个数字，做测试用

	for(int i=0; i<MAXN; i++)
		cout<<src[i]<<" ";
	cout<<endl;

	//执行归并排序
	merge_sort3(src,0,MAXN);

	for(int i=0; i<MAXN; i++)
		cout<<src[i]<<" ";
	cout<<endl;

	/*检查排序结果*/
	for(int i=0; i<MAXN-1; i++){
		if(src[i] > src[i+1]){
			cout<<"wrong"<<endl;
		}
	}
	return 0;
}


/*普通的归并排序*/
int merge_sort(int * src, int index_s, int index_e){
	cout<<"processing "<<index_s<<" "<<index_e<<endl;
	system("pause");

	/*治*/
	if(index_e - index_s <= 1){
		return 0;
	}

	int index_l_s = index_s;
	int index_l_e = (index_e + index_s) / 2;
	int index_r_s = (index_e + index_s) / 2;
	int index_r_e = index_e;

	/*分*/
	merge_sort(src, index_l_s, index_l_e);
	merge_sort(src, index_r_s, index_r_e);

	//开辟额外的内存来保存中间结果
	int* tmp = new int[index_e-index_s];
	int cnt = 0;

	int i = index_l_s;
	int j = index_r_s;

	/*合*/
	/*合并左右两个数组*/
	for(; i<index_l_e && j<index_r_e; ){
		if(src[i]<=src[j]){
			tmp[cnt++]=src[i++];
		}else{
			tmp[cnt++]=src[j++];
		}
	}

	/*处理剩余*/
	for(; i<index_l_e; i++){
		tmp[cnt++] = src[i];
	}
	for(; j<index_r_e; j++){
		tmp[cnt++] = src[j];
	}

	/*把排好序的写回原数组的对应位置*/
	for(int i = index_l_s; i < index_r_e; i++){
		src[i] = tmp[i-index_s];
		//cout<<src[i]<<" ";
	}
	//cout<<endl;

	delete []tmp;
	cout<<"finish "<<index_l_s<<" "<<index_r_e<<endl;
	return 0;
}

/* 好一点的归并排序
 * 减少申请额外内存至一次
 */
int merge_sort2(int * src, int index_s, int index_e, int *tmp=NULL){
	//标记，如果是第一次调用，就申请一个额外的数组
	bool i_create_tmp = false;
	if(tmp == NULL){
		i_create_tmp = true;
		tmp = new int[index_e];
	}

	cout<<"processing "<<index_s<<" "<<index_e<<endl;
	system("pause");

	/*治*/
	if(index_e - index_s <= 1){
		return 0;
	}

	int index_l_s = index_s;
	int index_l_e = (index_e + index_s) / 2;
	int index_r_s = (index_e + index_s) / 2;
	int index_r_e = index_e;

	/*分*/
	merge_sort2(src, index_l_s, index_l_e, tmp);
	merge_sort2(src, index_r_s, index_r_e, tmp);


	int i = index_l_s;
	int j = index_r_s;

	/*合*/
	/*合并左右两个数组*/
	for(; i<index_l_e && j<index_r_e; ){
		if(src[i] <= src[j]){
			tmp[index_s++] = src[i++];
		}else{
			tmp[index_s++] = src[j++];
		}
	}

	/*处理剩余*/
	for(; i<index_l_e; i++){
		tmp[index_s++] = src[i];
	}
	for(; j<index_r_e; j++){
		tmp[index_s++] = src[j];
	}

	/*把排好序的写回原数组的对应位置*/
	for(int i=index_l_s; i<index_r_e; i++){
		src[i]=tmp[i];
		//cout<<src[i]<<" ";
	}
	//cout<<endl;

	//如果本次调用申请了内存，别忘了释放
	if(i_create_tmp){
		delete []tmp;
	}
	cout<<"finish "<<index_l_s<<" "<<index_r_e<<endl;
	return 0;
}



/* 再好一点的归并排序
 * 减少申请额外内存至一次
 * 并消去了递归
 */
int merge_sort3(int * src, int index_s, int index_e){
	//申请一个额外的数组
	int *tmp = new int[index_e];
	stack<point*> range;
	int l = index_s;
	int r = index_e;
	int cnt;
	range.push(new point(l,r));
	
	while(!range.empty())
	{
		l = range.top()->l;
		r = range.top()->r;
		cnt = range.top()->cnt;
		cout<<"processing "<<l<<" "<<r<<endl;
		if(cnt==1)
		{/*分*/
			range.top()->cnt++;
			if(r-l>1)
			{
				range.push(new point((r+l)/2,r));
				range.push(new point(l,(r+l)/2));
			}
		}else
		{/*合*/
			delete range.top();
			range.pop();

			int i = l;
			int j = (r+l)/2;
			int index = l;

			/*合*/
			/*合并左右两个数组*/
			for(;i<(r+l)/2 && j<r;)
			{
				if(src[i]<=src[j])
				{
					tmp[index++]=src[i++];
				}else
				{
					tmp[index++]=src[j++];
				}
			}

			/*处理剩余*/
			for(;i<(r+l)/2;i++)
			{
				tmp[index++]=src[i];
			}
			for(;j<r;j++)
			{
				tmp[index++]=src[j];
			}

			/*把排好序的写回原数组的对应位置*/
			for(int i=l;i<r;i++)
			{
				src[i]=tmp[i];
				//cout<<src[i]<<" ";
			}
			//cout<<endl;
			cout<<"finish "<<l<<" "<<r<<endl;
		}
		system("pause");
	}
	//别忘了释放
	delete []tmp;
	return 0;
}


/*
 * 还要好的归并排序
 * 连额外数组都省了，写过一次，但是感觉就是希尔排序
 * 下次写希尔排序的时候再分析吧
 *
 */
int merge_sort4(int * src, int index_s, int index_e)
{
	return 1;
}
