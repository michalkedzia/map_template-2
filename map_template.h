#ifndef __MAP_TEMPLATE_H__
#define __MAP_TEMPLATE_H__
#include <iostream>
using namespace std;

template <class key__T,  class val_T > class map_template
{
private:

    struct node
    {
        node* next;
        key__T key;
        val_T val;

        node() :next(NULL)
        {
        };

        ~node()
        {
        };

    };
    node* head;
public:
    void Add(key__T key,  val_T value)
    {
        node* newnode = new node;
        newnode->next = head;
        head = newnode;
        head->val = value;
        head->key = key;
    };

    void clear()
    {
        while (head)
        {
            node* t = head->next;
            delete head;
            head = t;
        };
    };

    val_T  * Find( key__T key ) const
    {
        node* c = head;
        while (c)
        {
            if (c->key == key)
                return &(c->val);
            c = c->next;
        };
        return NULL;
    };

    void swap(map_template& l)
    {
        node* t = head;
        head = l.head;
        l.head = t;
    };

    map_template()
    {
        head = NULL;
    };

    map_template(const map_template& l)
    {
        node* src, ** dst;
        head = NULL;
        src = l.head;
        dst = &head;
        try
        {
            while (src)
            {
                *dst = new node(*src);
                src = src->next;
                dst = &((*dst)->next);
            }
        }
        catch (...)
        {
            clear();
            throw;
        };
    };

    map_template& operator= (const map_template& l)
    {
        if (&l == this)
            return *this;
        map_template t(l);
        swap(t);
        return *this;
    };

    ~map_template()
    {
        clear();
    };

    friend std::ostream& operator << (std::ostream& o, const map_template& m)
    {
        for (node* i = m.head; i; i = i->next)
            o << i->val << ": " << i->key << '\n';
        return o;
    };

};

#endif /* __MAP_TEMPLATE_H__ */







