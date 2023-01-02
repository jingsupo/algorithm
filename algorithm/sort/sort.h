#include <vector>

class sort
{
public:
    std::vector<int> vec;

    sort(std::vector<int> vec);

    //ð������
    //ʱ�临�Ӷȣ�O(n^2)
    //�ռ临�Ӷȣ�O(1)
    //�ȶ��ԣ��ȶ�
    void bubble();

    //ѡ������
    //ʱ�临�Ӷȣ�O(n^2)
    //�ռ临�Ӷȣ�O(1)
    //�ȶ��ԣ����ȶ�
    void select();

    //��������
    //ʱ�临�Ӷȣ�O(n^2)
    //�ռ临�Ӷȣ�O(1)
    //�ȶ��ԣ��ȶ�
    void insert();

    //ϣ������/��С��������
    //ʱ�临�Ӷȣ�O(nlogn)
    //�ռ临�Ӷȣ�O(1)
    //�ȶ��ԣ����ȶ�
    void shell();
    void shell_insert(std::vector<int>& vec, int start, int gap);

    //��������
    //ʱ�临�Ӷȣ�O(n+m)
    //�ռ临�Ӷȣ�O(m)
    //�ȶ��ԣ��ȶ�
    void count();

    //Ͱ����
    //ʱ�临�Ӷȣ�O(n+m)
    //�ռ临�Ӷȣ�O(n+m)
    //�ȶ��ԣ��ȶ�
    void bucket();

    //������
    //ʱ�临�Ӷȣ�O(nlogn)
    //�ռ临�Ӷȣ�O(1)
    //�ȶ��ԣ����ȶ�
    void heap();
    void build_heap(std::vector<int>& vec, int start, int end);
};
