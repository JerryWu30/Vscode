#pragma once
#include <iostream>
#include <string>
using namespace std;

//ְ������

class Worker
{
    public:
        
        //��ʾ��Ϣ
        virtual void show_info() = 0; //���崿����,���㲻ͬ����ְ����ʾ��Ϣ

        //��λְ��
        virtual string getDepName() = 0;

        int m_id;  //���
        string m_Name;  //����
        int m_DepName;  //ְ�����ڲ������Ʊ��

};