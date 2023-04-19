#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <mutex>
#include <thread>
using namespace std;

std::mutex m1, m2;

void thread1()
{
    m1.lock();
    _sleep(1);
    m2.lock();
    cout << "ONE ACCESSED CS" << endl;
    m1.unlock();
    m2.unlock();
}

void thread2()
{
    m2.lock();
    _sleep(1);
    m1.lock();
    cout << "TWO ACCESSED CS" << endl;
    m2.unlock();
    m1.unlock();
}

int main()
{
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();
}