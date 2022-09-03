#include<iostream>
using namespace std;
class Matric {
private:
	int n;
	int *data;
public:
	Matric(int n,int *data){
		this->n = n;
		this->data = data;
	}
	void print() const {
		for(int i=0;i<n*n;i++){
			cout << data[i] << " ";
			if((i+1)%5==0) cout << endl;
		}
	}
//data[i][j] = data[i*n+j]
	void poly(const Matric & rhs) {
		int *array = new int [n];//记录处理后的一行
		for(int i=0 ;i<n;i++){

			for(int q=0;q<n;q++){
				array[i]=0;
			}

			for(int j=0 ;j<n;j++){
				int sum = 0;
				for(int k=0;k<n;k++){
					//sum *= data[i][k]*rhs.data[k][j]
					sum += data[i*n+k]*rhs.data[k*n+j];
				}
				//array[j] = sum
				array[j] = sum;
			}
			//array复制到对象的data
			for(int p=0; p<n ; p++){
				data[i*n+p] = array[p];
			}
		}
	}
};

int main()
{
	int a[5][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
	int b[5][5]={{5,4,3,2,1},{5,4,3,2,1},{5,4,3,2,1},{5,4,3,2,1},{5,4,3,2,1}};
	Matric x(5,(int *)a);

	x.print();
	cout << endl;
	Matric y(5,(int *)b);

	y.print();
	cout << endl;

	x.poly(y);
	x.print();

}