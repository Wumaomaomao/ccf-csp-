#include<map>
#include<set>
#include<string.h>
#include<iostream>

using namespace std;

int main()
{
    int n, L, s;
    cin >> n >> L >> s;

    //采用点集的方式存储可能占用大量内存的图
    set<pair<int, int>> greenMap;

    map<pair<int, int>, int> greenMapTreecnt;

    int treasure[51][51];
    int treasureTreecnt = 0;
    memset(treasure, 0, 51 * 51 * sizeof(int));

    while(n--)
    {
        int x, y;
        cin >> x >> y;
        greenMap.insert(make_pair(x, y));
    }

    for (int i = s; i >= 0; -- i)
    {
        for (int j = 0; j <= s; ++ j)
            {
                cin >> treasure[i][j];
                if (treasure[i][j] == 1)
                {
                    ++treasureTreecnt;
                }
            }
    }

    int res = 0;

    //实际上的点的数目相对于图来说是稀疏的，所以可以通过直接遍历点集的方式减少时间浪费
    for (set<pair<int, int>>::iterator iter = greenMap.begin(); iter != greenMap.end(); ++iter)
    {
        int i = (*iter).first;
        int j = (*iter).second;
        if (i <= L - s && j <= L - s)
        {
            bool flag = true;
            for (int k = 0; k <= s; ++ k)
                for(int m = 0; m <= s ; ++ m)
                {
                    if (greenMap.find(make_pair(i+ k,j + m)) != greenMap.end())
                    {
                        ++greenMapTreecnt[make_pair(i, j)];
                    }
                }
            if (greenMapTreecnt[make_pair(i, j)] == treasureTreecnt)
            {
                for (int k = 0; k <= s; ++ k)
                {
                    for(int m = 0; m <= s ; ++ m)
                    {
                        if (treasure[k][m] == 1)
                        {
                            if (greenMap.find(make_pair(i+ k,j + m)) != greenMap.end())
                            ;
                            else 
                            {
                                flag = false;
                                break;
                            }
                        }
                        else
                        {
                            if (greenMap.find(make_pair(i+ k,j + m)) != greenMap.end())
                            {
                                flag = false;
                                break;
                            }
                            else 
                            {
                                ;
                            }
                        }
                    }
                    if (flag == false)
                    break;
                }
                if (flag == true)
                {
                    // cout << i << j << endl;
                    ++res;
                }
            }
        }
    }

    // for (int i = 0; i <= L  - s ; ++ i)
    //     for (int j = 0; j <= L  - s; ++ j)
    //     {
    //         bool flag = true;
    //         for (int k = 0; k <= s; ++ k)
    //             for(int m = 0; m <= s ; ++ m)
    //             {
    //                 if (greenMap.find(make_pair(i+ k,j + m)) != greenMap.end())
    //                 {
    //                     ++greenMapTreecnt[make_pair(i, j)];
    //                 }
    //             }
    //         if (greenMapTreecnt[make_pair(i, j)] == treasureTreecnt)
    //         {
    //             for (int k = 0; k <= s; ++ k)
    //             {
    //                 for(int m = 0; m <= s ; ++ m)
    //                 {
    //                     if (treasure[k][m] == 1)
    //                     {
    //                         if (greenMap.find(make_pair(i+ k,j + m)) != greenMap.end())
    //                         ;
    //                         else 
    //                         {
    //                             flag = false;
    //                             break;
    //                         }
    //                     }
    //                     else
    //                     {
    //                         if (greenMap.find(make_pair(i+ k,j + m)) != greenMap.end())
    //                         {
    //                             flag = false;
    //                             break;
    //                         }
    //                         else 
    //                         {
    //                             ;
    //                         }
    //                     }
    //                 }
    //                 if (flag == false)
    //                 break;
    //             }
    //             if (flag == true)
    //             {
    //                 // cout << i << j << endl;
    //                 ++res;
    //             }
    //         }
            
    //     }
        

    cout << res;

    return 0;
}