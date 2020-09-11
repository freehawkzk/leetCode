#include <iostream>
#include <map>
#include <vector>

//����ڵ㶨��
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

};

//�ϲ�K������
ListNode* mergeKLists(std::vector<ListNode*>& lists) 
{
    if (lists.size() == 0)
        return 0;
    if (lists.size() == 1)
        return lists[0];
    //��Ҫ˼·������std::map��key�Ǿ����������һ���ԣ������нڵ�
    //��ӵ�һ��map�У���map�н������ڵ��nextָ������ã����������ʱ��ֱ��
    //����map�ĳ�ʼ�ڵ������ĵ�һ��Ԫ�ؼ��ɡ�
    std::map<int, std::vector<ListNode*> > tempmap;
    for (int i = 0; i < lists.size(); i++)//����K������
    {
        ListNode* pList = lists[i];
        while (pList != 0)//����i���������е�Ԫ�ش���map
        {
            int mapkey = pList->val;
            ListNode* mapvalue = pList;

            pList = pList->next;
            mapvalue->next = 0;
            std::map<int, std::vector<ListNode*> >::iterator itor = tempmap.find(mapkey);
            if (itor == tempmap.end())//��ǰ����ڵ��ֵ��map�в����ڣ���map�����ڵ�
            {
                std::vector<ListNode*> arr;
                arr.push_back(mapvalue);
                tempmap.insert(std::make_pair(mapkey, arr));
            }
            else//��ǰֵ�Ѿ���map�д��ڣ���ֱ�ӽ���ǰ�ڵ�Ĵ����Ӧ��map
            {
                itor->second.push_back(mapvalue);
                //����map�ڵ��е�����ڵ��nextָ��
                itor->second[itor->second.size() - 2]->next = itor->second[itor->second.size() - 1];
                itor->second[itor->second.size() - 1]->next = 0;
            }

        }
    }
    if (tempmap.empty())//����������Ƕ��������ʱ�����ؿ�
    {
        return 0;
    }

    //��map�ĸ����ڵ�������ڵ���������һ���ڵ��nextָ��ָ����һ�ڵ�����ĵ�һ��Ԫ��
    std::map<int, std::vector<ListNode*> >::iterator itorend = tempmap.end();
    itorend--;
    for (std::map<int, std::vector<ListNode*> >::iterator itor = tempmap.begin(); itor != itorend; itor++)
    {
        itor++;
        std::map<int, std::vector<ListNode*> >::iterator itor1 = itor;
        itor--;
        itor->second[itor->second.size() - 1]->next = itor1->second[0];
    }
    //����ͷԪ�ص�����ĵ�һ��Ԫ��
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