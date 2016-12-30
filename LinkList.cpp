#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<cassert>
using namespace	std;

template<typename T>
struct Node
{
    Node()
    :_next(NULL)
    {}
    ~Node()
    {
    }
public:
    T _data;
    Node* _next;

};

template <typename T>
class LinkList
{
	
public:
    LinkList();
    ~LinkList();
    LinkList(const LinkList<T> & list);
    LinkList<T>& operator =(const LinkList<T> list);
    void PushBack(const T& data);  //Î²²å
    void Display();
    void PushFront(const T& data);//Í·²å
    void PopBack(); //Î²É¾
    void PopFront();//Í·É¾
    void Insert(Node<T> *pos, const T& data);

    void Remove(const T& data);
    void RemoveAll(const T& data);
    void Sort();
    void Erase(Node<T>* pos);
    void Size();
    Node<T>* Find(const T& data);

private:
    Node<T>* _head;
    Node<T>* _tail;
};

template<typename T>
LinkList<T>::LinkList()
:_head(NULL)
, _tail(NULL)
{

}

template<typename T>
LinkList<T>::~LinkList()
{
    Node <T>*cur = _head;
    while (cur)
    {
        Node<T>*del = cur;
        cur=cur->_next;
        delete del;
    }
}

template<typename T>
LinkList<T>::LinkList(const LinkList & list)
    :_head(NULL)
    , _tail(NULL)
{
    Node <T>*cur = list._head;
    while (cur != NULL)
    {
        PushBack(cur->_data);
        cur = cur->_next;
    }

}

template<typename T>
LinkList<T>& LinkList<T>::operator =( LinkList<T> list)
{
    std::swap(_head, list._head);
    std::swap(_tail, list._tail);
    return *this;
}

template<typename T>
void LinkList<T>::PushBack(const T& data)
{
    if (_head == NULL)
    {
        _head = new Node<T>;
        _head->_data = data;
        _tail = _head;
    }
    else
    {
        Node<T> *tmp = new Node<T>;
        tmp->_data = data;
        tmp->_next = NULL;
        _tail->_next = tmp;
        _tail = tmp;
    }
}

template<typename T>
void LinkList<T>::Display()
{
    Node<T>* cur = _head;
    while (cur)
    {
        cout << cur->_data << " ";
        cur = cur->_next;
    }
    cout << endl;
}

template<typename T>
void LinkList<T>::PushFront(const T& data)
{
    Node<T>*tmp = new Node<T>;
    tmp->_data = data;
    Node <T>*cur = _head;
    _head = tmp;
    tmp->_next = cur;
}


template<typename T>
void LinkList<T>::PopBack()
{
    Node <T>*cur = _head;
    Node <T>*del = NULL;
    if (_head == NULL)
    {
        return;
    }
    else if (_head == _tail)
    {
        del = _head;
        delete del;
        _head = _tail = NULL;
    }
    else
    {
        while (cur->_next != _tail)
        {
            cur = cur->_next;
        }
        delete _tail;
        _tail = cur;
        _tail->_next = NULL;

    }
}

template<typename T>
void LinkList<T>::PopFront()
{
    if (_head == NULL)
    {
        return;
    }
    else
    {
        Node<T>* cur = _head;
        Node<T>* del = NULL;
        del = _head;
        _head = _head->_next;
        delete del;
        del = NULL;
    }
}
template<typename T>
Node<T>* LinkList<T>::Find(const T& data)
{
    Node<T>* cur = _head;
    while (cur)
    {
        if (cur->_data == data)
        {
            return cur;
        }
        cur = cur->_next;
    }
    return NULL;
}
template<typename T>
void LinkList<T>::Insert(Node<T>* pos, const T& data)
{
    if (pos == NULL)
    {
        return;
    }
    Node<T>* newnode = new Node<T>;
    newnode->_data = data;
    Node<T>* cur = _head;
    Node<T>* prev = NULL;
    while (cur != NULL)
    {
        if (pos == cur)
        {
            break;
        }
        prev = cur;
        cur = cur->_next;
    }
    if (prev == NULL)
    {
        _head->_next = newnode;
        newnode->_next = cur;
    }
    else
    {
        prev->_next = newnode;
        newnode->_next = cur;
    }
}

template<typename T>
void LinkList<T>::Remove(const T& data)
{
    if (_head == NULL)
    {
        return;
    }
    Node<T> *cur = _head;
    Node<T> *prev = NULL;
    Node<T> *del = NULL;
    while (cur != NULL)
    {
        if (cur->_data == data)
        {
            if (cur == _head)
            {
                del = cur;
                _head = cur->_next;
                delete del;
                del = NULL;
            }
            else
            {
                del = cur;
                prev->_next = cur->_next;
                delete del;
                del = NULL;
            }
            return;
        }
        else
        {
            prev = cur;
            cur = cur->_next;
        }
    }
}

template<typename T>
void LinkList<T>::RemoveAll(const T& data)
{
    if (_head == NULL)
    {
        return;
    }
    Node<T> *cur = _head;
    Node<T> *del = NULL;
    Node<T> *prev = cur;
    while (cur != NULL)
    {
        if (cur->_data == data)
        {
            if (cur == _head)
            {
                del = cur;
                prev = cur->_next;
                _head = cur->_next;
                delete del;
                del = NULL;
            }
            else
            {
                del = cur;
                prev->_next = cur->_next;
                delete del;
                del = NULL;
            }
            cur = prev;
        }
        else
        {
            prev = cur;
            cur = cur->_next;
        }
    }
}

template<typename T>
void LinkList<T>::Sort()
{
    if ((_head == NULL) || (_head->_next == NULL))
    {
        return;
    }
    Node<T>* cur = _head;
    Node<T>* tail = NULL;
    while (cur != tail)
    {
        while (cur->_next != tail)
        {
            if (cur->_data > cur->_next->_data)
            {
                std::swap(cur->_data, cur->_next->_data);
            }
            cur = cur->_next;
        }
        tail = cur;
        cur = _head;
    }
}

template<typename T>
void LinkList<T>::	Erase(Node<T>* pos)
{
    if (_head == NULL)
    {
        return;
    }
    Node<T> *cur = _head;
    Node<T> *del = NULL;
    Node<T> *prev = _head;
    while (cur != NULL)
    {
        if (pos == cur)
        {
            if (pos == _head)
            {
                del = pos;
                _head = cur->_next;
                delete del;

                del = NULL;
            }
            else
            {
                del = pos;
                prev->_next = cur->_next;
                delete del;
                del = NULL;
            }
            return;
        }
        else
        {
            prev = cur;
            cur = cur->_next;
        }


    }
}

template<typename T>
void LinkList<T>::Size()
{
    Node<T>*cur = _head;
    int count = 0;
    while (cur != NULL)
    {
        count++;
        cur = cur->_next;
    }
    cout<<count<<endl;
}

int main()
{
	LinkList<int> l;
	/*l.PushFront(1);
	l.PushFront(2);
	l.PushFront(3);
	l.PushFront(4);*/
	//l.Display();
	l.PushBack(4);
	l.PushBack(3);
	l.PushBack(2);
	l.PushBack(1);
	l.PushBack(1);
	l.Display();
	l.Size();
	//l.Remove(1);
	//l.Display();
	l.RemoveAll(1);
	l.Display();
	system("pause");
	return 0;
}