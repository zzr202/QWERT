//
// Created by bwats on 2024-09-16.
//

#ifndef QWSAFE_ARRAYS_H
#define QWSAFE_ARRAYS_H
#include "QWARRAYS.h"

namespace QWERT {
    template<typename T>
    class SafePointerArray : PointerArray<T> {

        void check(const size_t index) {
            if(index >= this->size) {
                throw std::out_of_range("Index out of range of array");
            }
            if(index < 0) {
                throw std::out_of_range("Index below out of range of array");
            }
        }

    public:

        explicit SafePointerArray(size_t size) : PointerArray<T>(size)  {}

        void set(const size_t index, T to) override {
            check(index);
            PointerArray<T>::set(index, to);
        }

        T & get(size_t index) override {
            check(index);
            return PointerArray<T>::get(index);
        }

        T * getP(const size_t index) override {
            check(index);
            return PointerArray<T>::getP(index);
        }
    };

    /*idc about duplicated code,
    it was either that or I create
    a new child class with equal
    amount of code
     */
    template<typename T, size_t size>
    class SafeSizedArray : public SizedArray<T, size> {

        void check(const size_t index) {
            if(index >= size) {
                throw std::out_of_range("Index out of range of array");
            }
            if(index < 0) {
                throw std::out_of_range("Index below out of range of array");
            }
        }

    public:

        explicit SafeSizedArray() : SizedArray<T, size>()  {}

        void set(const size_t index, T to) override {
            check(index);
            SizedArray<T,size>::set(index, to);
        }

        T & get(size_t index) override {
            check(index);
            return SizedArray<T,size>::get(index);
        }

        T * getP(const size_t index) override {
            check(index);
            return SizedArray<T,size>::getP(index);
        }
    };
}



#endif //QWSAFE_ARRAYS_H
