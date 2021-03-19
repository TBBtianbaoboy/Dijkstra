class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
         if(n<1||src<0||src>n-1||dst<0||dst>n-1||K<0||K>n-1)//验证数据的有效性
            return -1;
        #define UNPRICE 1000000000
        //为避免内存泄漏，也可以使用定长数组记录数据
        int *flag = new int[n]();//1表示结点被访问，0表示结点未被访问,初始化为0
        int *price = new int[n];//价格列表
        for(int i=0;i<n;i++)//初始化价格无穷表示不可达
            price[i] = UNPRICE;
        int k=src;//起点标志
        flag[k] = 1;//初始化自身已被访问
        price[k] = 0;//初始化到自身价格为0
        for(int i=0;i<K+1;i++)//DJ算法
        {
            for(int j=0;j<n*(n-1)/2;j++)//更新路径
            {
                if(flights[j][0]==k)
                {
                    if(price[flights[j][1]]>price[k]+flights[j][2])
                    price[flights[j][1]] = price[k]+flights[j][2];
                }
            }
            int min = UNPRICE;
            int index;//记录最小值下标
            for(int j=0;j<n;j++)
            {
                if(flag[j]==0 && price[j]<min)
                {
                    min = price[j];
                    index = j;
                }
            }
            flag[index] = 1;//设置该结点为已访问，避免环影响
            k = index;//更新起点标志
        }
        if(price[dst]==UNPRICE)
            return -1;
        #undef UNPRICE
        return price[dst];
    }
};