# ifndef SYNCHRONIZEDQUEUE
# define SYNCHRONIZEDQUEUE

# include <thread>
# include <list>
# include <mutex>
# include <condition_variable>

// template function --> declaration and definition in the same .h file

using namespace std;

template <typename T>
class SynchronizedQueue {
    public:
        SynchronizedQueue () {};
        void put (T value);
        T get ();
        size_t size ();
    private:
        SynchronizedQueue (const SynchronizedQueue&) = delete;
        SynchronizedQueue &operator=(const SynchronizedQueue &) = delete;
        list<T> queue;
        mutex myMutex;
        condition_variable myCv;
};

// functions definition

template <typename T>
void SynchronizedQueue<T>::put (T value) {
    unique_lock<mutex> lck(myMutex);
    queue.push_back(value);
    myCv.notify_one();
}

template <typename T>
T SynchronizedQueue<T>::get () {
    unique_lock<mutex> lck(myMutex);
    while (queue.empty()) {
        myCv.wait(lck);
    }
    T result = queue.front();
    queue.pop_front();
    return result;
}

template <typename T>
size_t SynchronizedQueue<T>::size () {
    unique_lock<mutex> lck(myMutex);
    return queue.size();
}

# endif
