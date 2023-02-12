#include<iostream>
#include<math.h>
#include<limits.h>
using namespace std;

//this function helps in calculating mean price of the item
float calculate_mean(float prices[], int size){
    float mean_price=0;

    for(int i=0; i<size; i=i+1){
        mean_price=mean_price+prices[i];
    }
    float return_mean=(mean_price/size);
    return return_mean;
}


//this function helps in calculating variance 
float calculate_variance(float prices[], int size,float mean){
    //var=sqrt(sum((price[i]-mean)^2)/10)
    float sum=0;  

    for(int i=0; i<size; i=i+1){
        sum=sum+((prices[i]-mean)*(prices[i]-mean));
    }
    float var=sqrt((sum/size));

    return var;
}


//this function will return price 
void return_price(float mean, float variance, float min_price, float max_price){
    float coeff_var=(variance/mean)*100;
    //now expected price 
    float range= max_price-min_price;
    float avg_fluc=(max_price+min_price)/2;
    float fluctuated_price=mean*(coeff_var/100);
    float min=range-fluctuated_price;
    float maxi= range+fluctuated_price;
    cout<<"The Least possible Future price can be: "<<min+min_price<<endl;
    cout<<"The Max Possible Future Price can be: "<<maxi+max_price;
    cout<<endl;
}

//this function will return min value
int min_element(float prices[], int size){
    int min_price=INT_MAX;
    for(int i=0; i<size; i=i+1){
        if(prices[i]<min_price){min_price=prices[i];}
    }
    return min_price;
}

//this function will return max value
int max_element(float prices[], int size){
    int min_price=INT_MIN;
    for(int i=0; i<size; i=i+1){
        if(prices[i]>min_price){min_price=prices[i];}
    }
    return min_price;
}

//main function
int main(){
    int size;
    cout<<"How many Years/Months Data You have?";
    cin>>size;

    float prices[size];
    for(int year=0; year<size; year=year+1){
        cout<<"Enter Price for Year/Month "<<year+1<<": ";
        cin>>prices[year];
    }
    float min_price=min_element(prices, size);
    float max_price=max_element(prices, size);
    float mean=calculate_mean(prices,size);
    float variance=calculate_variance(prices,size,mean);
    cout<<endl;
    return_price(mean,variance,min_price,max_price);
    return 0;
}
