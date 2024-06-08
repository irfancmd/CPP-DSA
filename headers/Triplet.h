//
// Created by irfan on 6/3/24.
//

#ifndef CPP_DSA_TRIPLET_H
#define CPP_DSA_TRIPLET_H

#endif //CPP_DSA_TRIPLET_H

template<typename T1, typename T2, typename T3>
class Triplet {
public:
    T1 first;
    T2 second;
    T3 third;

    Triplet(T1 first, T2 second, T3 third): first{first}, second{second}, third{third} {}
};
