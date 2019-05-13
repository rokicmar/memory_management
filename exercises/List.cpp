#include <iostream>
#include <memory>

using namespace std;

class Node
{
public:
    Node(const int v) :
        next(nullptr),
        prev(nullptr),
        value(v)
    {}

    std::shared_ptr<Node> next;
    std::shared_ptr<Node> prev;
    int value;
};

class List
{
public:
    List();
    void add(std::shared_ptr<Node> node);
    std::shared_ptr<Node> get(const int value);

private:
    std::shared_ptr<Node> first;
    std::shared_ptr<Node> last;
};

List::List() :
    first(nullptr),
    last(nullptr)
{}

void List::add(std::shared_ptr<Node> node)
{
    if (!first) {
        first = node;
        last = first;
    }
    else {
        first->prev = node;
        node->next = first;

        first = node;
    }
}

std::shared_ptr<Node> List::get(const int value)
{
    if(!last)
    {
        cout << "List is empty!" << endl;
        return nullptr;
    }
    else
    {
        std::shared_ptr<Node> current = last;
        do
        {
            if(current->value == value)
            {
                cout << "Found value " << current->value << endl;
                return current;
            }
            else
            {
                cout << "Going through " << current->value << endl;
                current = current->prev;
            }
        } while(current);

        cout << "Not found: value " << value << endl;
        return nullptr;
    }
}

int main()
{
    List lista;
    auto node4 = std::make_shared<Node>(4);
    auto node7 = std::make_shared<Node>(7);

    lista.add(node4);
    lista.add(std::make_shared<Node>(2));
    lista.add(node7);
    lista.add(std::make_shared<Node>(9));
    auto node = lista.get(1);
    node = lista.get(4);

    if (node)
        cout << node->value << '\n';

    return 0;
}

