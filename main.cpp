#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <functional>

#define Max 10000
using namespace std;

/*---��С��������---*/
class Tree {
private:
    int** map;                            //��ͼ
    int num;                              //�ڵ���Ŀ
    vector <pair <string, int> > name;	  //�ڵ����Ͷ�Ӧ�����
    vector <pair<int, int> > ans;         //��С����������
public:
    Tree() :map(NULL), num(0) {}            //Ĭ�Ϲ��캯��
    ~Tree();                              //��������

    void A_InputName();                   //����ڵ�����
    void B_InputMap();                    //�����ͼ
    void C_buildTree();                   //������С������
    void D_print();                       //��ӡ��С������
};
/*---��������---*/
Tree::~Tree() {
    if (map != NULL) {
        for (int i = 0; i < num; i++) {
            delete[] map[i];
        }
        delete[] map;
    }
}

/*---����ڵ�����---*/
void Tree::A_InputName() {
    if (!ans.empty()) {
        cout << "��������С���������Ƿ�������" << endl << endl;
        return;
    }
    if (map != NULL) {
        cout << "�����ɵ�ͼ�� �Ƿ�������" << endl << endl;
        return;
    }
    string temp;
    cout << "�����붥��ĸ���:";
    cin >> num;
    cout << "���������붥�������:" << endl;

    for (int i = 0; i < num; i++) {
        cin >> temp;
        name.push_back(make_pair(temp, i));
    }
    cout << endl;
}
/*---�����ͼ---*/
void Tree::B_InputMap() {
    if (!ans.empty()) {
        cout << "��������С���������Ƿ�������" << endl << endl;
        return;
    }
    if (num == 1) {
        cout << "�Ƿ����и�����" << endl << endl;
        return;
    }

    map = new int* [num];
    for (int i = 0; i < num; i++)
        map[i] = new int[num];

    for (int i = 0; i < num - 1; i++) {
        cout << "��������������������ľ��룬�����ھ���������-1: ";
        map[i][i] = 0;
        for (int k = i + 1; k < num; k++) {
            cout << name[i].first << " ";
            cout << name[k].first << " ";
            cin >> map[i][k];
            if (map[i][k] == -1)
                map[i][k] = Max;
            if (k != num - 1)
                cout << "��������������������ľ��룬�����ھ���������-1: ";
        }
    }
    for (int i = 0; i < num; i++) {
        map[i][i] = 0;
    }
    for (int i = 0; i < num; i++) {
        for (int k = 0; k < i; k++) {
            map[i][k] = map[k][i];
        }
    }
    cout << endl;
}
/*---������С������---*/
void Tree::C_buildTree() {
    if (num == 0 || map == nullptr) {
        cout << "��������ڵ����ƺ͵�ͼ��Ϣ��" << endl;
        return;
    }
    ans.clear();
    vector<bool> visited(num, false); // ���һ�����ڸ��ٷ��ʹ��Ķ��������
    priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> que;

    // ��ӵ�һ���ڵ㵽���ȶ���
    string tempname;
    cout << "��������ʼ���㣺";
    cin >> tempname;
    int startIndex = -1;
    for (int i = 0; i < num; i++) {
        if (tempname == name[i].first) {
            startIndex = i;
            visited[i] = true;
            break;
        }
    }
    if (startIndex == -1) {
        cout << "δ�ҵ���ʼ���㡣" << endl;
        return;
    }

    // ����ʼ������ӱߵ����ȶ���
    for (int i = 0; i < num; i++) {
        if (i != startIndex) {
            que.push({ map[startIndex][i], {startIndex, i} });
        }
    }

    // Prim�㷨����ѭ��
    while (!que.empty()) {
        auto edge = que.top();
        que.pop();

        int to = edge.second.second;
        if (visited[to]) continue; // �����Ѿ����ʵĽڵ�

        visited[to] = true; // ��ǽڵ��ѷ���
        ans.push_back(edge.second); // ��ӵ������

        // ���������ӵ�δ���ʽڵ�ı߼��뵽���ȶ���
        for (int i = 0; i < num; i++) {
            if (!visited[i]) {
                que.push({ map[to][i], {to, i} });
            }
        }
    }

    cout << "����Prim��С��������" << endl << endl;
}

/*---��ӡ��С������---*/
void Tree::D_print() {
    string name1, name2;
    cout << "��С�������Ķ����Լ���Ϊ��" << endl;
    for (int i = 0; i < ans.size(); i++) {

        for (int k = 0; k < name.size(); k++) {
            if (ans[i].first == name[k].second)
                name1 = name[k].first;
            if (ans[i].second == name[k].second)
                name2 = name[k].first;
        }

        cout << name1 << "-(" << map[ans[i].first][ans[i].second]
            << ")-" << name2 << "        ";
    }
    cout << endl << endl;
}

int main() {
    cout << "**                     �������ģ��ϵͳ                     **" << endl;
    cout << "==============================================================" << endl;
    cout << "**                     A---������������                       **" << endl;
    cout << "**                     B---��ӵ����ı�                       **" << endl;
    cout << "**                     C---������С������                     **" << endl;
    cout << "**                     D---��ʾ��С������                     **" << endl;
    cout << "**                     E---�˳�����                          **" << endl;
    cout << "==============================================================" << endl;

    char order;
    Tree tree;

    //Node * p = tree.create();

    cout << "��ѡ�����:";
    cin >> order;

    while (order != 'E') {
        switch (order) {
        case 'A':
            tree.A_InputName();
            break;
        case 'B':
            tree.B_InputMap();
            break;
        case 'C':
            tree.C_buildTree();
            break;
        case 'D':
            tree.D_print();
            break;
        default:
            break;
        }
        cout << "��ѡ�����:";
        cin >> order;
    }
    return 0;
}
