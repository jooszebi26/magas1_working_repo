#include "std_lib_facilities.h"

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    while (f1 != e1)
    {
        *f2 = *f1;
        ++f1;
        ++f2;
    }
    return f2;
}


int main()
{
    int my_array[10] = {0,1,2,3,4,5,6,7,8,9};
    cout << "Array 1: " << endl;
    for(int i = 0; i < 10; i++){cout << my_array[i] << " ";}
    cout << endl;

    vector<int> my_vector{0,1,2,3,4,5,6,7,8,9};
    cout << "Vector 1: " << endl;
    for(int& i : my_vector){cout << i << " ";}
    cout << endl;

    list<int> my_list{0,1,2,3,4,5,6,7,8,9};
    cout << "List 1: " << endl;
    for(int& i : my_list){cout << i << " ";}
    cout << endl;

    cout << endl;
    cout << "--------------------" << endl;
    cout << endl;
    
    int my_array2[10];

    copy(begin(my_array), end(my_array), begin(my_array2));

    vector<int> my_vector2 = my_vector;

    list<int> my_list2 = my_list;

    for(int& i : my_array){i += 2;}

    for(int& i : my_vector){i += 3;}
    
    for(int& i : my_list){i += 5;}

    cout << "Array 1(+2): " << endl;
    for(int i = 0; i < 10; i++){cout << my_array[i] << " ";}
    cout << endl;
    my_copy(begin(my_array), end(my_array), begin(my_vector2));
    
    cout << "Copied vector 2: " << endl;
    for(int& i : my_vector2){cout << i << " ";}
    cout << endl;

    cout << "List 1: " << endl;
    for(int& i : my_list)
        cout << i;
    cout << endl;

    my_copy(begin(my_list), end(my_list), begin(my_array2));
    cout << "Copied array 2: " << endl;
    for(int i = 0; i < 10; i++)
        cout << my_array2[i];
    cout << endl;

    auto found = find(begin(my_vector), end(my_vector), 3);

    if (found != end(my_vector))
        cout << "3 is found at position:" << distance(begin(my_vector), found) << endl;
    else
        cout << "3 not found in vector." << endl;
    
    auto found2 = find(begin(my_list), end(my_list), 27);

    if (found2 != end(my_list))
        cout << "27 is found at position:" << distance(begin(my_list), found2) << endl;
    else
        cout << "27 not found in list." << endl;

    return 0;
}
