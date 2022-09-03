/*设计一个函数，int getpowerdsum(int a, int b)，其中0 < a < 10，1<b<10000，
功能是求出a^b的所有位的数字之和，并返回该和值。比如，2^10=1024，那么getpowerdsum(2, 10)的返回值为1+0+2+4=7。
如下main函数执行后
int main(int argc, char** argv) {
	cout << getpowerdsum(9,10)<< endl;
}
执行结果为：
45
*/
#include<iostream>
using namespace std;

int getpowerdsum(int a, int b);

int main(int argc, char** argv) {
	cout << getpowerdsum(9,10)<< endl;
}

#include<vector>
int getpowerdsum(int a, int b)
{
	vector<int> vector={1};
	int mask=0;//进位转移数
	for(auto i=0 ;i<b;i++){

		for(int j = 0; j < vector.size(); ++j){

			int num=vector[j]*a+mask;

			vector[j]=(num)%10;

			mask=0;

			if(num>=10){

				mask=num/10;

				if(i+1>=vector.size()){

					vector.push_back(0);
					
				}
			}
		}
	}
	int sum=0;

	for(auto &i:vector){

		sum+=i;
		
	}
	return sum;
}