#include <iostream>
#include <map>
#include <vector>

//链表节点定义
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

};

//合并K个链表
ListNode* mergeKLists(std::vector<ListNode*>& lists) 
{
    if (lists.size() == 0)
        return 0;
    if (lists.size() == 1)
        return lists[0];
    //主要思路是利用std::map的key是经过排序的这一属性，将所有节点
    //添加到一个map中，在map中将各个节点的next指针调整好，最终输出的时候直接
    //返回map的初始节点的数组的第一个元素即可。
    std::map<int, std::vector<ListNode*> > tempmap;
    for (int i = 0; i < lists.size(); i++)//遍历K个链表
    {
        ListNode* pList = lists[i];
        while (pList != 0)//将第i个链表所有的元素存入map
        {
            int mapkey = pList->val;
            ListNode* mapvalue = pList;

            pList = pList->next;
            mapvalue->next = 0;
            std::map<int, std::vector<ListNode*> >::iterator itor = tempmap.find(mapkey);
            if (itor == tempmap.end())//当前链表节点的值在map中不存在，则map新增节点
            {
                std::vector<ListNode*> arr;
                arr.push_back(mapvalue);
                tempmap.insert(std::make_pair(mapkey, arr));
            }
            else//当前值已经在map中存在，则直接将当前节点的存入对应的map
            {
                itor->second.push_back(mapvalue);
                //调整map节点中的链表节点的next指针
                itor->second[itor->second.size() - 2]->next = itor->second[itor->second.size() - 1];
                itor->second[itor->second.size() - 1]->next = 0;
            }

        }
    }
    if (tempmap.empty())//对于输入的是多个空链表时，返回空
    {
        return 0;
    }

    //将map的各个节点中链表节点数组的最后一个节点的next指针指向下一节点数组的第一个元素
    std::map<int, std::vector<ListNode*> >::iterator itorend = tempmap.end();
    itorend--;
    for (std::map<int, std::vector<ListNode*> >::iterator itor = tempmap.begin(); itor != itorend; itor++)
    {
        itor++;
        std::map<int, std::vector<ListNode*> >::iterator itor1 = itor;
        itor--;
        itor->second[itor->second.size() - 1]->next = itor1->second[0];
    }
    //返回头元素的数组的第一个元素
    ListNode* head = 0;

    head = tempmap.begin()->second[0];
    return head;
}
int main()
{
    std::cout << "main" << std::endl;
    ListNode n00(0);
    ListNode n01(1);
    ListNode n02(3);
    ListNode n10(2);
    ListNode n11(4);
    ListNode n20(0);
    ListNode n21(1);
    ListNode n22(2);
    ListNode n23(3);
    n00.next = &n01;
    n01.next = &n02;
    n10.next = &n11;
    n20.next = &n21;
    n21.next = &n22;
    n22.next = &n23;
    std::vector<ListNode*> lists;
    lists.push_back(&n00);
    lists.push_back(&n10);
    lists.push_back(&n20);

    ListNode * pRes = mergeKLists(lists);
    while (pRes!= 0)
    {
        std::cout << pRes->val << " ";
        pRes = pRes->next;
    }
    return 0;
}