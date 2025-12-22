#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


#include "include/utils/moves/left_to_left.hpp"
#include "include/utils/moves/left_to_right.hpp"
#include "include/utils/moves/right_to_left.hpp"
#include "include/utils/moves/right_to_right.hpp"

#include "include/utils/state_repr.hpp"
int main()
{
    State_tuple s1;
    get<0>(get<0>(s1)) = 0;
    get<1>(get<0>(s1)) = 2;
    get<0>(get<1>(s1)) = 0;
    get<1>(get<1>(s1)) = 4;
    get<2>(s1) = 0;
    cout << "ll: "<< ll(s1).data()<< '\n';
    cout << "lr: "<< lr(s1).data()<< '\n';
    cout << "rl: "<< rl(s1).data()<< '\n';
    cout << "rr: "<< rr(s1).data()<< '\n';

    //Player 2 attacks
    get<2>(s1) = 1;
    cout << "ll: "<< ll(s1).data()<< '\n';
    cout << "lr: "<< lr(s1).data()<< '\n';
    cout << "rl: "<< rl(s1).data()<< '\n';
    cout << "rr: "<< rr(s1).data()<< '\n';
    // State_str s1 = {0};
    // cout << s1.data() << endl;
    return 0;
}