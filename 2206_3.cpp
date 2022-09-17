#include<map>
#include<set>
#include<string>
#include<iostream>

using namespace std;

struct Property
{
    set<string> oper;
    set<string> resType;
    set<string> resName;
    set<string> authorObj;
};

int main()
{
   ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    map<string ,Property> role;

    int n, m, q;
    cin >> n >> m >> q;
    //处理角色的操作、资源种类和清单
    while(n--)
    {
        string name;
        Property pro;

        cin >> name;

        int operCnt;
        cin >> operCnt;
        while(operCnt--)
        {
            string operName;
            cin >> operName;
            pro.oper.insert(operName);
        }

        int resTypeCnt;
        cin >> resTypeCnt;
        while(resTypeCnt--)
        {
            string resTypeName;
            cin >> resTypeName;
            pro.resType.insert(resTypeName);
        }

        int resNameCnt;
        cin >> resNameCnt;
        while(resNameCnt--)
        {
            string resName;
            cin >> resName;
            pro.resName.insert(resName);
        }
    
        role[name] = pro;
    }
    //处理角色和用户/用户组的关联关系
    while(m--)
    {
        string roleName;
        cin >> roleName;

        int objCnt;
        cin >> objCnt;

        while(objCnt--)
        {
            string objType, objName;
            cin >> objType >> objName;

            role[roleName].authorObj.insert(objName);
        }
    }
    
    while(q--)
    {
        bool flag = false;
        string User;
        int userGrpCnt;
        set<string> userId;

        cin >> User;
        userId.insert(User);
        
        cin >> userGrpCnt;
        while(userGrpCnt--)
        {
            string grpName;
            cin >> grpName;
            userId.insert(grpName);
        }

        string dstOper, dstResType, dstResName;
        cin >> dstOper>>dstResType>>dstResName;


        for (map<string, Property>::iterator iter = role.begin(); iter != role.end(); ++iter)
        {
            
            Property pro = (*iter).second;

            if (pro.oper.find(dstOper) != pro.oper.end() || pro.oper.find("*") != pro.oper.end())
            {
                if (pro.resType.find(dstResType) != pro.resType.end() || pro.resType.find("*") != pro.resType.end())
                {
                    if (pro.resName.find(dstResName) != pro.resName.end() || pro.resName.empty())
                    {
                        for (set<string>::iterator idIter = userId.begin(); idIter != userId.end(); ++idIter)
                        {
                            if (pro.authorObj.find((*idIter)) != pro.authorObj.end())
                            {
                                flag = true;
                                break;
                            }
                        }
                    }
                }
            }
        }


        if (flag == true)
        {
            cout << 1 << endl;
        }
        else cout << 0 << endl;
    }

    return 0;
}