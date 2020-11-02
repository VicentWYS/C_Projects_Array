#include "fun.h"
#include <stdio.h>


//数组输入元素
void inputArray(int a[], int n){
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
}


//数组打印元素
void outputArray(int a[], int n){
    for(int i=0; i<n; i++){
        printf("%d\t", a[i]);
    }
    printf("\n");
}


//数组逆序排列
void invertArray(int a[], int n){
    int t;
    for(int i=0; i<n/2; i++){
        //交换两元素的值
        //新增一个变量用于交换两数组元素的值
        t = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = t;
    }
}

//寻找数组中最大值和其下标
void arrayFindMax(){
    int a[10];
    int maxIndex;   //最大值下标

    //输入数组元素
    printf("输入10个数组元素：\n");
    for(int i=0; i<10; i++){
        scanf("%d", &a[i]);
    }

    //逐个查询
    maxIndex = 0;
    for(int i=0; i<10; i++){
        if(a[i] > a[maxIndex]){
            maxIndex = i;
        }
    }

    //输出结果
    printf("最大值：%d, 下标：%d\n", a[maxIndex], maxIndex);
}


//求成绩数组中最高、最低、平均成绩
void arrayFind_Max_Min_Aver(){
    int a[10];
    int maxIndex;   //最大值下标
    int minIndex;   //最小值下标
    int sumScore;   //总成绩

    //输入数组元素
    printf("输入10个数组元素：\n");
    for(int i=0; i<10; i++){
        scanf("%d", &a[i]);
    }

    //逐个查询
    maxIndex = 0;
    minIndex = 0;
    sumScore = 0;

    for(int i=0; i<10; i++){
        if(a[i] > a[maxIndex]){
            maxIndex = i;
        }
        if(a[i] < a[minIndex]){
            minIndex = i;
        }

        sumScore = sumScore + a[i];
    }

    //输出结果
    printf("最大值：%d, 下标：%d\n", a[maxIndex], maxIndex);
    printf("最小值：%d, 下标：%d\n", a[minIndex], minIndex);
    printf("平均值：%.2f\n",(1.0*sumScore)/10);
}

//冒泡排序(从小到大)
void bubbleSort(){
    int a[10];
    int n=10;
    int temp;   //用于交换时

    //输入元素
    printf("输入10个数组元素：\n");
    for(int i=0; i<=9; i++){
        scanf("%d", &a[i]);
    }
    printf("数组元素为：\n");
    for(int i=0; i<=9; i++){
        printf("%d\t", a[i]);
    }

    //排序
    for(int i=1; i<=9; i++){
        for(int j=0; j<=9-i; j++){
            if(a[j] > a[j+1]){
                //交换，使得大的在后
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    //打印数组
    printf("\n排序后数组：\n");
    for(int i=0; i<n; i++){
        printf("%d\t", a[i]);
    }
}


//选择排序(从小到大)
void selectionSort(){
    int a[10];
    int n=10;
    int k;   //用于保存每回合最小值下标
    int t;   //用于交换时

    //输入元素
    printf("输入10个数组元素：\n");
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    printf("数组元素为：\n");
    for(int i=0; i<n; i++){
        printf("%d\t", a[i]);
    }

    //排序
    for(int i=0; i<=n-2; i++){
        k = i;
        for(int j=i+1; j<=n-1; j++){
            if(a[k] > a[j]){
                k=j;
            }//k表示j循环中的最小值下标
        }

        //若k还是为i，说明j循环中没有比 a[i] 更小的数了
        if(k != i){
            //交换
            t = a[i];
            a[i] = a[k];
            a[k] = t;
        }
    }

    //打印数组
    printf("\n排序后数组：\n");
    for(int i=0; i<n; i++){
        printf("%d\t", a[i]);
    }
}


//选择排序(从小到大)(返回数组)
void selectionSort2(int a[], int n){
    int k;   //用于保存每回合最小值下标
    int t;   //用于交换时

    //排序
    for(int i=0; i<=n-2; i++){
        k = i;
        for(int j=i+1; j<=n-1; j++){
            if(a[k] > a[j]){
                k=j;
            }//k表示j循环中的最小值下标
        }

        //若k还是为i，说明j循环中没有比 a[i] 更小的数了
        if(k != i){
            //交换
            t = a[i];
            a[i] = a[k];
            a[k] = t;
        }
    }

}


//顺序查找
int search(int a[], int n, int target){
    int i = 0;
    while(i<n){
        if(a[i] == target){
            break;
        }

        i++;
    }

    if(i<n){
        return i;   //找到目标，返回其下标
    }else{
        return -1;  //没找到，返回-1
    }
}

//顺序查找测试
void testSearch(){
    int a[10];
    int target; //目标值

    printf("输入数组元素:\n");
    inputArray(a, 10);
    printf("数组元素为：\n");
    outputArray(a,10);

    printf("输入要查找的数：\n");
    scanf("%d", &target);

    int result = search(a, 10, target);

    if(result == -1){
        printf("找不到\n");
    }else{
        printf("找到了，下标为：%d\n", result);
    }
}

//折半查找
int binarySearch(int a[], int n, int target){
    int low = 0;
    int mid;
    int high = n-1;

    while(low <= high){
        mid = (low + high)/2;
        if(target = a[mid]){
            //返回下标
            return mid;
        }else if(target > a[mid]){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    //找不到，则返回-1
    return -1;
}


//折半查找测试
void testBinarySearch(){
    int a[10];
    int target; //目标值

    printf("输入数组元素:\n");
    inputArray(a, 10);
    printf("数组元素为：\n");
    outputArray(a,10);

    printf("输入要查找的数：\n");
    scanf("%d", &target);

    selectionSort2(a, 10);
    printf("排序后的数组：\n");
    outputArray(a, 10);

    int result = binarySearch(a, 10, target);

    if(result == -1){
        printf("找不到\n");
    }else{
        printf("找到了，下标为：%d\n", result);
    }
}