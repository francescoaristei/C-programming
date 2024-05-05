/*

You are asked to complete the following C++ template class named SyncPoint:

# include <list>

template <typename T> class SyncPoint {
    public:
        void addData(T data);
        std::list<T> getData();
        
        //Complete the rest of the class body and implementation
};

such that both methods can be called by one or more threads. addData should put the data item in an ordered
queue. getData shall return the first three data items that have been put in the queue. If the queue contains less
than three data items, the function shall wait until this condition is satisfied.

*/

// PRODUCER-CONSUMER design pattern (Synchronized Queue)

# ifndef SYNCPOINT
# define SYNCPOINT

using namespace std;

# include <mutex>
# include <condition_variable>
# include <list>

template <typename T>
class SyncPoint {
    public:
        void addData (T data);
        list<T> getData();
    private:
        list<T> queue;
        mutex m;
        condition_variable cv;

};

template <typename T>
void SyncPoint<T>::addData (T data) {
    unique_lock<mutex> lck(m);
    queue.push_back(data);
    cv.notify_one();
}

template <typename T>
list<T> SyncPoint<T>::getData () {
    unique_lock<mutex> lck(m);
    while (queue.size() < 3) {
        // NOTE: when the wait is performed the lock is released (unlocked).
        cout << "Size of the queue is too small" << "\n";
        cv.wait(lck);
    }
    list<T> result;
    for (int i = 0; i < 3; i++) {
        result.push_back(queue.front());
        queue.pop_front();
    }
    return result;
}

# endif