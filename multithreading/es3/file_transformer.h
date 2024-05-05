/*

You are required to implement a C/C++ program performing a transformation of an input file,
by doing simple arithmetic operations. The file is a fixed size (4 KB) binary file, containing a
sequence of 8-bit integer numbers. The path of the input file is provided as a command-line
argument. The program must replace each number with the result of the “number MODULO
5” operation, overwriting the content of the input file (hints: use memory mapping)
The required solution must be a parallel implementation (use threads or processes as you
wish), spawning 16 threads or processes.

*/

// ThreadPool Design Pattern

# ifndef FILETRANS
# define FILETRANS

# include <functional>
# include <mutex>
# include <condition_variable>
# include <thread>
# include <list>
# include <atomic>

using namespace std;

class ThreadPool {
    public:
        ThreadPool (unsigned int threadNumber);
        ~ThreadPool ();
        void pushTask (function<void ()> task);


    private:
        mutex m;
        condition_variable cv;
        vector<thread> workers;
        list<function<void()>> queue;
        void executeTask ();
        atomic<bool> done;
        unsigned int threadCount;
};


# endif