#include <bits/stdc++.h>
#include <thread>
#include <mutex>
using namespace std;

std::condition_variable cond;
deque<int> buffer;
const int buffersize = 50;
mutex mu;

void producer(int val)
{
    while (val)
    {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker, []()
                  { return buffer.size() < buffersize; });
        buffer.push_back(val);
        cout << "Produced " << val << endl;
        val--;
        locker.unlock();
        cond.notify_one();
    }
}

void consumer()
{
    while (true)
    {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker, []()
                  { return buffer.size() > 0; });
        int val = buffer.back();
        buffer.pop_back();
        cout << "Consumed " << val << endl;
        locker.unlock();
        cond.notify_one();
    }
}

int main()
{
    thread t1(producer, 100);
    thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}