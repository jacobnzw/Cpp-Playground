#include <iostream>
#include <vector>
#include <queue>
#include <tuple>


struct Node
{
    size_t _x, _y;
    float _f_value;
    Node* _previous_node;

    Node(size_t x, size_t y, float f_value) 
    : _x(x), _y(y), _f_value(f_value), _previous_node(nullptr) {}

    void set_parent(Node& parent)
    {
        _previous_node = &parent;
    }

    bool operator>(const Node& rhs) const  // for priority_queue
	{
		//return std::tie(_x, _y) < std::tie(rhs._x, rhs._y);
		return _f_value > rhs._f_value;
	}

	bool operator==(const Node& rhs) const
	{
		return std::tie(_x, _y) == std::tie(rhs._x, rhs._y);
	}

    friend std::ostream& operator<<(std::ostream& out, const Node& n)
    {
        out << "(" << n._x  << ", " << n._y  << ", "  << n._f_value  << ")";
        return out;
    }
};

int main()
{
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> opened_list;
    Node parent(0, 0, 100.0);
    
    Node one(10, 20, 1.23);
    one.set_parent(parent);
    opened_list.push(one);

    Node two(20, 5, 16.3);
    two.set_parent(parent);
    opened_list.push(two);

    Node three(15, 15, 0.5);
    three.set_parent(parent);
    opened_list.push(three);

    std::cout << *one._previous_node << "\n";

    parent = opened_list.top();

    std::cout << *one._previous_node << "\n";
    
    opened_list.pop();

    std::cout << *one._previous_node << "\n";
}