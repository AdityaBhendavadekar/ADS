#include<stdio.h>

long long int tempSqrt(int n){

    int num =n;
    int start = 0;
    int end = num;
    long long int mid = start+(end - start)/2;
    long long int ans=-1;

    while(start<=end){
        if(mid*mid>num){
            end = mid-1;
        }
        if(mid * mid<num){
            ans = mid;
            start=mid+1;
        }
        if(mid * mid==num){
            return mid;
        }
        mid = start+(end - start)/2;
    }
    return ans;
}

double precisedSqrt(int tmp, int num){
    double ans = tmp;
    int n = num;
    double factor = 1;

    for(int i=0;i<3;i++){
        factor=factor/10;

        for(double j=ans;j*j<n;j+=factor){
            ans=j;
        }
    }
    return ans;
}

int main(){

    int num;
    scanf("%d", &num);

    int tmpSOl = tempSqrt(num);

    double precise = precisedSqrt(tmpSOl, num);

    printf("Square root of %d is %f", num, precise);

    return 0;
}